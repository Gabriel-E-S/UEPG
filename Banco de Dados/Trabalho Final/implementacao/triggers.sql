-- Trigger 1 - Quando a máquina registrar pagamento como "Aprovado",
-- o plano do aluno deve ficar “Ativo/Em dia” automaticamente.

CREATE FUNCTION trg_atualiza_plano_pagamento()
RETURNS TRIGGER AS $$
BEGIN
    IF NEW.status_pagamento = 'Aprovado' THEN
        UPDATE Plano
        SET situacao = 'Ativo'
        WHERE cod_plano = NEW.cod_plano;
    END IF;

    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER tg_pagamento_aprovado
AFTER UPDATE ON Maquina_de_Pagamento
FOR EACH ROW
EXECUTE FUNCTION trg_atualiza_plano_pagamento();


-- Trigger 2 - Se o servidor Gympass retornar status “Invalido”,
-- a catraca ligada a ele deve ser bloqueada automaticamente.

CREATE FUNCTION trg_bloqueia_catraca_gympass()
RETURNS TRIGGER AS $$
BEGIN
    IF NEW.status_validacao = 'Invalido' THEN
        UPDATE Catraca
        SET status = 'Bloqueado'
        WHERE cod_gympass = NEW.cod_gympass;
    END IF;

    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER tg_gympass_invalido
AFTER UPDATE ON Servidor_Gympass
FOR EACH ROW
EXECUTE FUNCTION trg_bloqueia_catraca_gympass();


-- Trigger 3 - Impede que o aluno tenha mais de um plano ativo por vez.

CREATE FUNCTION trg_limite_plano_por_aluno()
RETURNS TRIGGER AS $$
DECLARE
    quantidade INTEGER;
BEGIN
    UPDATE Aluno
    SET ultima_avaliacao = NEW.data
    WHERE cod_a = NEW.cod_a;

    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER tg_ultima_avaliacao
AFTER INSERT ON Avaliacao_Fisica
FOR EACH ROW
EXECUTE FUNCTION trg_atualiza_ultima_avaliacao();


-- Trigger 4 - Impede que uma avaliação física seja cadastrada no futuro.

CREATE FUNCTION trg_proibir_avaliacao_futura()
RETURNS TRIGGER AS $$
BEGIN
    IF NEW.data > CURRENT_DATE THEN
        RAISE EXCEPTION 'Erro: A data da avaliação não pode ser no futuro.';
    END IF;

    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER tg_data_avaliacao_futura
BEFORE INSERT OR UPDATE ON Avaliacao_Fisica
FOR EACH ROW
EXECUTE FUNCTION trg_proibir_avaliacao_futura();


-- Trigger 5 - Libera entrada pela catraca somente se o plano estiver ativo.

CREATE FUNCTION trg_verifica_plano_catraca()
RETURNS TRIGGER AS $$
DECLARE
    status_plano VARCHAR(20);
BEGIN
    SELECT situacao
    INTO status_plano
    FROM Plano
    WHERE cod_plano = NEW.cod_plano;

    IF status_plano <> 'Ativo' THEN
        UPDATE Catraca
        SET status = 'Bloqueado'
        WHERE cod_c = NEW.cod_c;
    END IF;

    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER tg_plano_catraca
AFTER INSERT OR UPDATE ON Aluno
FOR EACH ROW
EXECUTE FUNCTION trg_verifica_plano_catraca();
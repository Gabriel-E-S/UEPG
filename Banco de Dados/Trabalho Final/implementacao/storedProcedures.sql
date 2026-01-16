CREATE PROCEDURE sp_cadastrar_aluno(
    p_cod_a INT,
    p_nome VARCHAR,
    p_cpf CHAR(11),
    p_data_nasc DATE,
    p_digital VARCHAR,
    p_cod_r INT,
    p_cod_c INT,
    p_cod_m INT,
    p_cod_plano INT
)
LANGUAGE plpgsql
AS $$
BEGIN
    INSERT INTO Aluno (
        cod_a,
        nome_aluno,
        cpf_aluno,
        data_nascimento_aluno,
        digital,
        cod_r,
        cod_c,
        cod_m,
        cod_plano
    )
    VALUES (
        p_cod_a,
        p_nome,
        p_cpf,
        p_data_nasc,
        p_digital,
        p_cod_r,
        p_cod_c,
        p_cod_m,
        p_cod_plano
    );
END;
$$;


CREATE PROCEDURE sp_registrar_pagamento(
    p_cod_m INT,
    p_status VARCHAR(20)
)
LANGUAGE plpgsql
AS $$
BEGIN
    UPDATE Maquina_de_Pagamento
    SET status_pagamento = p_status
    WHERE cod_m = p_cod_m;

    -- Trigger cuidará da ativação do plano
END;
$$;


CREATE FUNCTION fn_validar_gympass(p_cod_gympass INT)
RETURNS VARCHAR
LANGUAGE plpgsql
AS $$
DECLARE
    v_status VARCHAR(20);
BEGIN
    SELECT status_validacao
    INTO v_status
    FROM Servidor_Gympass
    WHERE cod_gympass = p_cod_gympass;

    IF v_status = 'Valido' THEN
        RETURN 'Acesso Liberado';
    ELSIF v_status = 'Invalido' THEN
        RETURN 'Acesso Negado';
    ELSE
        RETURN 'Erro na validação. Tente novamente.';
    END IF;
END;
$$;


CREATE PROCEDURE sp_registrar_avaliacao(
    p_data DATE,
    p_cod_a INT,
    p_med_perna DECIMAL,
    p_med_braco DECIMAL,
    p_med_cintura DECIMAL,
    p_gordura DECIMAL,
    p_peso DECIMAL,
    p_altura DECIMAL,
    p_cod_r INT,
    p_cod_p INT
)
LANGUAGE plpgsql
AS $$
BEGIN
    INSERT INTO Avaliação_Física (
        data,
        cod_a,
        med_perna,
        med_braco,
        med_cintura,
        percentual_gordura,
        peso,
        altura,
        cod_r,
        cod_p
    )
    VALUES (
        p_data,
        p_cod_a,
        p_med_perna,
        p_med_braco,
        p_med_cintura,
        p_gordura,
        p_peso,
        p_altura,
        p_cod_r,
        p_cod_p
    );
END;
$$;


CREATE PROCEDURE sp_atualizar_aluno(
    p_cod_a INT,
    p_nome VARCHAR,
    p_cpf CHAR(11),
    p_data_nasc DATE,
    p_digital VARCHAR,
    p_cod_r INT,
    p_cod_c INT,
    p_cod_m INT,
    p_cod_plano INT
)
LANGUAGE plpgsql
AS $$
BEGIN
    UPDATE Aluno
    SET nome_aluno = p_nome,
        cpf_aluno = p_cpf,
        data_nascimento_aluno = p_data_nasc,
        digital = p_digital,
        cod_r = p_cod_r,
        cod_c = p_cod_c,
        cod_m = p_cod_m,
        cod_plano = p_cod_plano
    WHERE cod_a = p_cod_a;
END;
$$;
/* CRIANDO AS RESTRIÇÕES DE INTEGRIDADE */
-- Recepcionista
ALTER TABLE Recepcionista -- Garante que o salário não seja negativo
ADD CONSTRAINT ck_rec_salario CHECK (salario_recepcionista >= 0);
ALTER TABLE Recepcionista -- Garante uma data de nascimento "lógica"
(ninguém nascido antes de 1900)
ADD CONSTRAINT ck_rec_nascimento CHECK
(data_nascimento_recepcionista > '1900-01-01');
-- Professor
ALTER TABLE Professor -- Garante uma data de nascimento "lógica"
(ninguém nascido antes de 1900)

ADD CONSTRAINT ck_prof_nascimento CHECK (data_nascimento_professor
> '1900-01-01');
ALTER TABLE Professor -- Garante que o salário do professor não seja
negativo.
ADD CONSTRAINT ck_prof_salario CHECK (salario_professor >= 0);
ALTER TABLE Professor -- Garante que o CREF tenha um tamanho mínimo
(evita erros de digitação com 1 ou 2 caracteres).
ADD CONSTRAINT ck_prof_cref_len CHECK (LENGTH(cref) >= 4);
ALTER TABLE Professor -- Restrição do teto do salário
ADD CONSTRAINT ck_prof_salario_teto CHECK (salario_professor <
50000);
-- Plano
ALTER TABLE Plano -- O preço do plano não pode ser negativo.
ADD CONSTRAINT ck_plano_preco CHECK (preco_plano >= 0);
ALTER TABLE Plano --A duração do plano (provavelmente em meses ou dias)
deve ser maior que zero.
ADD CONSTRAINT ck_plano_duracao CHECK (duracao > 0);
ALTER TABLE Plano -- Limita a situação do plano a valores específicos
ADD CONSTRAINT ck_plano_situacao CHECK (situacao IN ('Ativo',
'Inativo', 'Suspenso'));
ALTER TABLE Plano -- Não permite dois planos com o mesmo nome
ADD CONSTRAINT uq_plano_nome UNIQUE (nome_plano);
-- Catraca
ALTER TABLE Catraca -- Define os estados possíveis da catraca, evitando
textos aleatórios.
ADD CONSTRAINT ck_catraca_status CHECK (status IN ('Liberado',
'Bloqueado', 'Manutencao'));
-- Servidor Gympass
ALTER TABLE Servidor_Gympass -- Padroniza os status de validação
retornados pelo servidor.

ADD CONSTRAINT ck_gym_status CHECK (status_validacao IN ('Valido',
'Invalido', 'Erro'));
-- Maquina pagamento
ALTER TABLE Maquina_de_Pagamento -- Padroniza os status de pagamento
possíveis.
ADD CONSTRAINT ck_maq_status CHECK (status_pagamento IN
('Aprovado', 'Recusado', 'Pendente'));
-- Aluno
ALTER TABLE Aluno -- Garante que a data de nascimento do aluno seja
válida.
ADD CONSTRAINT ck_aluno_nasc CHECK (data_nascimento_aluno >
'1900-01-01');
ALTER TABLE Aluno -- Se a digital for preenchida, garante que não seja
uma string vazia ('').
ADD CONSTRAINT ck_aluno_digital CHECK (LENGTH(digital) > 0);
-- Avaliacao fisica
ALTER TABLE Avaliacao_Fisica -- O percentual de gordura deve estar
logicamente entre 0 e 100.
ADD CONSTRAINT ck_av_gordura CHECK (percentual_gordura >= 0 AND
percentual_gordura <= 100);
ALTER TABLE Avaliacao_Fisica -- O peso do aluno deve ser positivo.
ADD CONSTRAINT ck_av_peso CHECK (peso > 0);
ALTER TABLE Avaliacao_Fisica -- A altura deve ser positiva e
logicamente aceitável (ex: menor que 3 metros).
ADD CONSTRAINT ck_av_altura CHECK (altura > 0 AND altura < 3.00);
ALTER TABLE Avaliacao_Fisica -- Medida da perna deve ser positiva.
ADD CONSTRAINT ck_av_perna CHECK (med_perna > 0);
ALTER TABLE Avaliacao_Fisica -- Mesma coisa para o braço
ADD CONSTRAINT ck_av_braco CHECK (med_braco > 0);
ALTER TABLE Avaliacao_Fisica -- E cintura também
ADD CONSTRAINT ck_av_cintura CHECK (med_cintura > 0);

ALTER TABLE Avaliacao_Fisica -- A cintura geralmente é menor que a
altura da pessoa. (Evita troca de campos na digitação).
ADD CONSTRAINT ck_av_cintura_vs_braco CHECK (med_cintura >
med_braco);
ALTER TABLE Avaliacao_Fisica -- A data da avaliação física não pode ser
no futuro (ninguém faz avaliação amanhã).
ADD CONSTRAINT ck_av_data_passado CHECK (data <= CURRENT_DATE);
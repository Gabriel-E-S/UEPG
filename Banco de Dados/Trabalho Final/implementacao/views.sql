/* CRIANDO AS VIEWS */

-- View 1 = Mostra os recepcionistas, quantos alunos eles cadastraram, professores relacionados e planos contratados.

CREATE VIEW vw_resumo_recepcionistas AS
SELECT
    recepcionista.nome_recepcionista,
    COUNT(DISTINCT aluno.cod_a) AS qtd_alunos,
    COUNT(DISTINCT professor.cod_p) AS qtd_professores,
    COUNT(DISTINCT plano.cod_plano) AS qtd_planos,
    COUNT(DISTINCT maquinapagamento.cod_m) AS qtd_maquinas
FROM Recepcionista recepcionista
    LEFT JOIN Aluno aluno ON recepcionista.cod_r = aluno.cod_r
    LEFT JOIN Avaliacao_Fisica avaliacao ON aluno.cod_a = avaliacao.cod_a
    LEFT JOIN Professor professor ON avaliacao.cod_p = professor.cod_p
    LEFT JOIN Plano plano ON aluno.cod_plano = plano.cod_plano
    LEFT JOIN Maquina_de_Pagamento maquinapagamento ON plano.cod_plano = maquinapagamento.cod_plano
GROUP BY recepcionista.nome_recepcionista;

--  View 2 - Integra alunos internos e externos com o servidor Gympass, a catraca e o plano correspondente.

CREATE VIEW vw_status_acesso_gympass AS
SELECT 
    aluno.nome_aluno,
    alunoexterno.cod_ae AS aluno_externo,
    gympass.status_validacao,
    catraca.status AS status_catraca,
    plano.nome_plano,
    maquinapagamento.status_pagamento
FROM Servidor_Gympass gympass
    LEFT JOIN Aluno_externo alunoexterno ON gympass.cod_gympass = alunoexterno.cod_gympass
    LEFT JOIN Catraca catraca ON gympass.cod_gympass = catraca.cod_gympass
    LEFT JOIN Aluno aluno ON catraca.cod_c = aluno.cod_c
    LEFT JOIN Plano plano ON aluno.cod_plano = plano.cod_plano
    LEFT JOIN Maquina_de_Pagamento maquinapagamento ON plano.cod_plano = maquinapagamento.cod_plano;
	
-- View 3 - Mostra o histórico de avaliações físicas dos alunos, com seus planos, pagamentos, recepcionistas e professores.

CREATE VIEW vw_historico_avaliacoes AS
SELECT 
    aluno.nome_aluno,
    avaliacao.data AS data_avaliacao,
    avaliacao.peso,
    avaliacao.altura,
    professor.nome_professor,
    recepcionista.nome_recepcionista,
    plano.nome_plano,
    plano.situacao AS situacao_plano,
    maquinapagamento.status_pagamento
FROM Avaliacao_Fisica avaliacao
    JOIN Aluno aluno ON avaliacao.cod_a = aluno.cod_a
    JOIN Professor professor ON avaliacao.cod_p = professor.cod_p
    JOIN Recepcionista recepcionista ON avaliacao.cod_r = recepcionista.cod_r
    JOIN Plano plano ON aluno.cod_plano = plano.cod_plano
    JOIN Maquina_de_Pagamento maquinapagamento ON plano.cod_plano = maquinapagamento.cod_plano;


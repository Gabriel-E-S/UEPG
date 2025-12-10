-- Consulta 1

SELECT
    aluno.nome_aluno,
    plano.nome_plano,
    maquinapagamento.status_pagamento,
    catraca.status AS status_catraca,
    recepcionista.nome_recepcionista,
    servidorgympass.status_validacao AS status_gympass
FROM Aluno aluno
JOIN Plano plano ON aluno.cod_plano = plano.cod_plano
JOIN Maquina_de_Pagamento maquinapagamento ON aluno.cod_m = maquinapagamento.cod_m
JOIN Catraca catraca ON aluno.cod_c = catraca.cod_c
JOIN Recepcionista recepcionista ON aluno.cod_r = recepcionista.cod_r
JOIN Servidor_gympass servidorgymppass ON catraca.cod_gympass = servidorgympass.cod_gympass;

-- Consulta 2

SELECT
    aluno.nome_aluno,
    recepcionista.nome_recepcionista,
    catraca.status AS status_catraca,
    servidorgympass.status_validacao,
    plano.nome_plano
FROM Aluno aluno
JOIN Recepcionista recepcionista ON aluno.cod_r = recepcionista.cod_r
JOIN Catraca catraca ON aluno.cod_c = catraca.cod_c
LEFT JOIN Servidor_Gympass servidorgympass ON catraca.cod_gympass = servidorgympass.cod_gympass
JOIN Plano plano ON aluno.cod_plano = plano.cod_plano;

-- Consulta 3

SELECT
    alunoexterno.cod_ae,
    servidorgympass.status_validacao,
    catraca.status AS status_catraca
FROM Aluno_externo alunoexterno
JOIN Servidor_Gympass servidorgympass ON alunoexterno.cod_gympass = servidorgympass.cod_gympass
JOIN Catraca catraca ON servidorgympass.cod_gympass = catraca.cod_gympass;

-- Consulta 4

SELECT
    aluno.nome_aluno,
    professor.nome_professor,
    MAX(avaliacao.data) AS ultima_avaliacao,
    recepcionista.nome_recepcionista,
    maquinapagamento.status_pagamento
FROM Aluno aluno
JOIN Avaliacao_Fisica avaliacao ON aluno.cod_a = avaliacao.cod_a
JOIN Professor professor ON avaliacao.cod_p= professor.cod_p
JOIN Recepcionista recepcionista ON avaliacao.cod_r = recepcionista.cod_r
JOIN Maquina_de_Pagamento maquinapagamento ON aluno.cod_m = maquinapagamento.cod_m
GROUP BY aluno.nome_aluno, professor.nome_professor, recepcionista.nome_recepcionista, maquinapagamento.status_pagamento;

-- Consulta 5

SELECT
    plano.nome_plano,
    aluno.nome_aluno,
    catraca.status AS status_catraca,
    gympass.status_validacao,
    maquinapagamento.status_pagamento,
    professor.nome_professor
FROM Plano plano
JOIN Aluno aluno ON plano.cod_plano = aluno.cod_plano
JOIN Catraca catraca ON aluno.cod_c = catraca.cod_c
LEFT JOIN Servidor_Gympass gympass ON catraca.cod_gympass = gympass.cod_gympass
JOIN Maquina_de_Pagamento maquinapagamento ON plano.cod_plano = maquinapagamento.cod_plano
LEFT JOIN Avaliacao_Fisica avaliacao ON aluno.cod_a = avaliacao.cod_a
LEFT JOIN Professor professor ON avaliacao.cod_p = professor.cod_p;


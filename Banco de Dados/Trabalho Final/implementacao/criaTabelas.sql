/* CRIANDO AS TABELAS */
-- Tabela de Recepcionista
CREATE TABLE Recepcionista (
cod_r INT PRIMARY KEY,
nome_recepcionista VARCHAR(100) NOT NULL,
cpf_recepcionista CHAR(11) UNIQUE NOT NULL,
salario_recepcionista DECIMAL(10,2),
data_nascimento_recepcionista DATE
);
-- Tabela de Servidor Gympass
CREATE TABLE Servidor_Gympass (
cod_gympass INT PRIMARY KEY,
status_validacao VARCHAR(20) NOT NULL
);
-- Tabela de Catraca
CREATE TABLE Catraca (
cod_c INT PRIMARY KEY,
status VARCHAR(20) NOT NULL,
cod_gympass INT,
FOREIGN KEY (cod_gympass) REFERENCES Servidor_Gympass(cod_gympass)
);
-- Tabela de Plano
CREATE TABLE Plano (
cod_plano INT PRIMARY KEY,
nome_plano VARCHAR(50) NOT NULL,
preco_plano DECIMAL(10,2) NOT NULL,
duracao INT NOT NULL,
situacao VARCHAR(20) NOT NULL
);
-- Tabela de Máquina de Pagamento

CREATE TABLE Maquina_de_Pagamento (
cod_m INT PRIMARY KEY,
status_pagamento VARCHAR(20) NOT NULL,
cod_plano INT NOT NULL,
FOREIGN KEY (cod_plano) REFERENCES Plano(cod_plano)
);
-- Tabela de Aluno
CREATE TABLE Aluno (
cod_a INT PRIMARY KEY,
nome_aluno VARCHAR(100) NOT NULL,
cpf_aluno CHAR(11) UNIQUE NOT NULL,
data_nascimento_aluno DATE NOT NULL,
digital VARCHAR(200),
cod_r INT NOT NULL,
cod_c INT NOT NULL,
cod_m INT NOT NULL,
cod_plano INT NOT NULL,
FOREIGN KEY (cod_r) REFERENCES Recepcionista(cod_r),
FOREIGN KEY (cod_c) REFERENCES Catraca(cod_c),
FOREIGN KEY (cod_m) REFERENCES Maquina_de_Pagamento(cod_m),
FOREIGN KEY (cod_plano) REFERENCES Plano(cod_plano)
);
-- Tabela de Aluno Externo (Gympass)
CREATE TABLE Aluno_externo (
cod_ae INT PRIMARY KEY,
cod_gympass INT NOT NULL,
FOREIGN KEY (cod_gympass) REFERENCES Servidor_Gympass(cod_gympass)
);
-- Tabela de Professor
CREATE TABLE Professor (
cod_p INT PRIMARY KEY,
cref VARCHAR(20) UNIQUE NOT NULL,
data_nascimento_professor DATE NOT NULL,
salario_professor DECIMAL(10,2),
cpf_professor CHAR(11) UNIQUE NOT NULL,
nome_professor VARCHAR(100) NOT NULL
);

-- Tabela de Avaliação Física
CREATE TABLE Avaliacao_Fisica (
data DATE NOT NULL,
cod_a INT NOT NULL,
med_perna DECIMAL(5,2),
med_braco DECIMAL(5,2),
med_cintura DECIMAL(5,2),
percentual_gordura DECIMAL(5,2),
peso DECIMAL(5,2),
altura DECIMAL(5,2),
cod_r INT NOT NULL,
cod_p INT NOT NULL,
PRIMARY KEY (data, cod_a),
FOREIGN KEY (cod_a) REFERENCES Aluno(cod_a),
FOREIGN KEY (cod_r) REFERENCES Recepcionista(cod_r),
FOREIGN KEY (cod_p) REFERENCES Professor(cod_p)
);
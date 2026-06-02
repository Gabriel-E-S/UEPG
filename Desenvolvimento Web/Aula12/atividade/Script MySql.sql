CREATE DATABASE meu_banco;
USE meu_banco;

/*DROP TABLE filmes;*/

CREATE TABLE filmes(
	id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(255) NOT NULL,
    descricao VARCHAR(255) NOT NULL,
    genero char(10) NOT NULL,
    lancamento DATE NOT NULL,
    nota INT NOT NULL
);

SELECT * FROM filmes;

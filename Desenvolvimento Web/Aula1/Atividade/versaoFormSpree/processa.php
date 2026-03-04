<?php

$nome = $_POST['nome'];

$email = $_POST['email'];

$telefone = $_POST['telefone'];

$nascimento = $_POST['nascimento'];

$endereco = $_POST['endereco'];

$cidade = $_POST['cidade'];

$estado = $_POST['estado'];

$cor = $_POST['cor'];

$frontEnd = $_POST['frontEnd'] ?? 'não' ;

$backEnd = $_POST['backEnd'] ?? 'não';

$bancoDeDados = $_POST['bancoDeDados'] ?? 'não' ;

$turno = $_POST['turno'];

$mensagem = $_POST['mensagem'];

echo "<h1: Resultados do formulário:</h1>

      Nome: $nome <br> 
      
      Email: $email <br> 
      
      Telefone: $telefone <br>
      
      Data de nascimento: $nascimento <br>
      
      Endereco: $endereco <br>
      
      Cidade: $cidade <br>
      
      Estado: $estado <br>
      
      Cor preferida: $cor <br>
      
      Area de Interesse:
      <ol>
        <li>FrontEnd - $frontEnd</li>
        <li>BackEnd - $backEnd</li>
        <li>BancoDeDados - $bancoDeDados</li>
      </ol>

      Turno: $turno <br>
      
      Mensagem: $mensagem.
"

?>
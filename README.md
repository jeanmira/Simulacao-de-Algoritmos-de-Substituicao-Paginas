# **Simulação de Algoritmos de Substituição de Páginas**

[![Generic badge](https://img.shields.io/badge/Status-Finalizado-<red>.svg)](https://shields.io/)

### Como executar o programa:
     • No ubuntu ou derivado abra o terminal, para uma melhor experiência expanda ao máximo a tela
     • Execute o comando: make all (observação: somente se fizer alguma alteração visto que o programa já contém um executável)
     • Para executar no terminal digite ./execultavel depois informe a quantidade de quadros e o nome do arquivo .txt que contém as referências (exemplo: ./simulador 4 < vsim-gcc.txt)
     • Caso o usuário queira habilitar ou desabilitar a interface gráfica ou o delay que facilitar a visualização deve abrir o arquivo interface.h e mudar o valor da constante:
          • Para executar a interface os parâmetros devem:
               #define INTERFACE 1
               #define DELAY 1
          • Para não executar a interface os parâmetros devem ser:
               #define INTERFACE 0
               #define DELAY 0
     • Após fornecer essa informação o programa irá executar
     • Caso seja necessário instalar o pacote para rodar a interface gráfica no ubuntu basta rodar o comando $ make sfml ou entrar no site para mais informações https://www.sfml-dev.org/tutorials/2.5/start-linux.php


 


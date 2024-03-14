# Projeto-Pratico

  No dia 13/12/2023, foi realizada a Aula Prática #9 no Laboratório de Sistemas Digitais do CCMN, UFRJ. Nela, foi realizado o seguinte experimento:

  Criar uma função para movimentar um braço robótico, composto por quatro servomotores, através de um controle remoto infravermelho, nos eixos X, Y e Z, além da garra. Além disso, através do sensor ultrassônico HC-SR04, os movimentos do braço deveriam ser limitados, não podendo se aproximar mais do que 3cm do sensor, ou seja, uma barreira “invisível”.

  O experimento foi realizado com sucesso pelo grupo, e as devidas explicações acerca da modelagem, montagem e dos resultados obtidos serão explicitadas ao longo do relatório.


  Para realizar o experimento, o grupo utilizou os seguintes componentes: 1x Placa de ensaio; 1x Sensor ultrassônico HC-SR04; 1x Receptor de infravermelho; 1x Braço robótico; Arduino. 

  Após alimentar as trilhas da placa de ensaio e os componentes, o grupo fez as seguintes conexões: os pinos Echo e Trig, do sensor ultrassônico, foram conectados aos pinos digitais 2 e 3 do Arduino, respectivamente. O pino de saída do receptor infravermelho foi conectado ao pino digital 7 do Arduino. Por último, os cabos de sinal dos servomotores foram conectados da seguinte forma: o sinal do motor 1 (eixo X) foi conectado ao pino digital 6 do Arduino; o sinal do motor 2 (eixo Y) foi conectado ao pino digital 9 do Arduino; o sinal do motor 3 (eixo Z) foi conectado ao pino digital 10 do Arduino; o sinal do motor da garra foi conectado ao pino digital 11 do Arduino.


  Após todas as devidas conexões, fizemos o upload do código para o Arduino, e conferimos os resultados. O código pode ser visualizado no repositório.


  Os resultados obtidos pelo grupo foram satisfatórios, estando todos de acordo com o esperado. O braço robótico se movimentou corretamente de acordo com as teclas pressionadas no controle remoto (designadas conforme pedido no enunciado da prática). Quando algum objeto se encontrava a menos de 3cm do sensor ultrassônico, o braço não respondia aos comandos e, por conseguinte, não se movia, também conforme o esperado.	
Os resultados foram gravados e podem ser visualizados nos vídeos linkados abaixo:

https://drive.google.com/file/d/1yKQCc2xyQDFDCaUgC29GFRUkW5eO5404/view?usp=sharing
https://drive.google.com/file/d/1uSTk77pGjGdxl9DaR4I5thuCZmf43k_K/view?usp=sharing


A conclusão bem-sucedida das tarefas delineadas representa um progresso significativo na aplicação integrada de tecnologias para controle e segurança em um sistema robótico. A implementação da rotina de controle remoto infravermelho proporcionou movimentos precisos nos eixos X, Y e Z do braço robótico, possibilitando operações versáteis e intuitivas.

A criação da barreira "invisível" utilizando o Sensor Ultrassônico HC-SR04 demonstrou eficácia na prevenção de aproximação a menos de 3 centímetros em qualquer direção, atestando a capacidade do sistema em evitar colisões e danos potenciais. A sinergia entre o controle remoto e o sensor ultrassônico não apenas alcançou os objetivos propostos, mas também nos mostrou possibilidades para serem exploradas utilizando o braço robótico.

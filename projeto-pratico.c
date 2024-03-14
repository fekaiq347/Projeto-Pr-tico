#include <Servo.h>
#include <IRremote.hpp>


#define echoPin 2 // Pino 2 do Arduino ligado ao pino Echo do HC-SR04
#define trigPin 3 // Pino 3 do Arduino ligado ao pino Trig do HC-SR04


int distancia;
int duracao;
int atual;
int errado = 0;


Servo servoEixo1;
Servo servoEixo2;
Servo servoEixo3;
Servo servoGarra;


int eixo1Pos = 90; // posicao inicial para o servo do eixo 1
int eixo2Pos = 90; // posicao inicial para o servo do eixo 2
int eixo3Pos = 90; // posicao inicial para o servo do eixo 3
int garraPos = 90; // posicao inicial para o servo da garra
int RECV_PIN = 7; // IR receiver pin


IRrecv irrecv(RECV_PIN);
decode_results results;


void setup() {
    servoEixo1.attach(6); // servo do eixo 1 pin 6
    servoEixo2.attach(9); // servo do eixo 2 pin 9
    servoEixo3.attach(10); // servo do eixo 3 pin 10
    servoGarra.attach(11); // servo da garra pin 11
    Serial.begin(9600);
    servoEixo1.write(eixo1Pos);
    servoEixo2.write(eixo2Pos);
    servoEixo3.write(eixo3Pos);  
    servoGarra.write(garraPos);
    IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK); // inicializa o IR receiver
    pinMode(trigPin, OUTPUT); // Define trigPin como OUTPUT
    pinMode(echoPin, INPUT);  // Define echoPin como INPUT
}


void loop() {
    digitalWrite(trigPin, LOW); // Coloca trigPin em nível BAIXO
    delayMicroseconds(2);       // Por 2 microssegundos
    digitalWrite(trigPin, HIGH); // Coloca trigPin em nível ALTO
    delayMicroseconds(10);       // Por 10 microssegundos
    digitalWrite(trigPin, LOW);
    // Lê echoPin e retorna o tempo de propagação em microssegundos
    duracao = pulseIn(echoPin, HIGH); // Função interna do Arduino
    // distancia = duracao * 0.034 / 2; (ida e volta)
    distancia = duracao * 0.034 / 2;
    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.println(" cm");
    if(distancia > 3){
      if (IrReceiver.decode()) {
        //IrReceiver.printIRResultShort(&Serial); //teste controle
        switch (IrReceiver.decodedIRData.command) {
            case 0x5A: // Botão >>
                eixo1Pos += 10;
                eixo1Pos = constrain(eixo1Pos, 10, 170);
                servoEixo1.write(eixo1Pos);
                atual = 1;
                break;
            case 0x8: // Botão <<
                eixo1Pos -= 10;
                eixo1Pos = constrain(eixo1Pos, 10, 170);
                servoEixo1.write(eixo1Pos);
                atual = 2;
                break;
            case 0x18: // Botão ^
                eixo2Pos += 10;
                eixo2Pos = constrain(eixo2Pos, 10, 170);
                servoEixo2.write(eixo2Pos);
                atual = 3;
                break;
            case 0x52: // Botão v
                eixo2Pos -= 10;
                eixo2Pos = constrain(eixo2Pos, 10, 170);
                servoEixo2.write(eixo2Pos);
                atual = 4;
                break;
            case 0x16: // Botão VOL-
                eixo3Pos += 10;
                eixo3Pos = constrain(eixo3Pos, 10, 170);
                servoEixo3.write(eixo3Pos);
                atual = 5;
                break;
            case 0xD: // Botão VOL+
                eixo3Pos -= 10;
                eixo3Pos = constrain(eixo3Pos, 10, 170);
                servoEixo3.write(eixo3Pos);
                atual = 6;
                break;
            case 0x1C: // Botão >||
                garraPos = (garraPos == 10) ? 120 : 10;
                servoGarra.write(garraPos);
                break;
            case 0x45: // Botão >||
                eixo1Pos += 10;
                eixo2Pos += 10;
                eixo2Pos = constrain(eixo2Pos, 10, 170);
                eixo1Pos = constrain(eixo1Pos, 10, 170);
                servoEixo1.write(eixo1Pos);
                servoEixo2.write(eixo2Pos);
                break;
            case 0x46: // Botão >||
                eixo3Pos += 10;
                eixo2Pos += 10;
                eixo2Pos = constrain(eixo2Pos, 10, 170);
                eixo3Pos = constrain(eixo3Pos, 10, 170);
                servoEixo3.write(eixo3Pos);
                servoEixo2.write(eixo2Pos);
                atual = 6;
                break;
            case 0x47: // Botão >||
                eixo1Pos += 10;
                eixo3Pos += 10;
                eixo3Pos = constrain(eixo3Pos, 10, 170);
                eixo1Pos = constrain(eixo1Pos, 10, 170);
                servoEixo1.write(eixo1Pos);
                servoEixo3.write(eixo3Pos);
                atual = 6;
                break;
            case 0x44: // Botão >||
                eixo1Pos -= 10;
                eixo2Pos -= 10;
                eixo2Pos = constrain(eixo2Pos, 10, 170);
                eixo1Pos = constrain(eixo1Pos, 10, 170);
                servoEixo1.write(eixo1Pos);
                servoEixo2.write(eixo2Pos);
                atual = 6;
                break;
            case 0x40: // Botão >||
                eixo3Pos -= 10;
                eixo2Pos -= 10;
                eixo2Pos = constrain(eixo2Pos, 10, 170);
                eixo3Pos = constrain(eixo3Pos, 10, 170);
                servoEixo3.write(eixo3Pos);
                servoEixo2.write(eixo2Pos);
                atual = 6;
                break;
            case 0x43: // Botão >||
                eixo1Pos -= 10;
                eixo3Pos -= 10;
                eixo3Pos = constrain(eixo3Pos, 10, 170);
                eixo1Pos = constrain(eixo1Pos, 10, 170);
                servoEixo1.write(eixo1Pos);
                servoEixo3.write(eixo3Pos);
                atual = 6;
                break;
        }
        IrReceiver.resume(); // recebe o próximo valor
    }
    }
    delay(100);
}

//Programa : Teste basico encoder Arduino
//Autor : Arduino e Cia

//Carrega a biblioteca do encoder
#include <RotaryEncoder.h>
#include <Arduino.h>
//Pinos de ligacao do encoder
RotaryEncoder encoder(2, 3);

//Variavel para o botao do encoder
int valor = 0;
int newPos = 0;

void setup()
{
  pinMode(10, INPUT);
  Serial.begin(9600);
  Serial.println("Gire o encoder....");
}

void loop()
{
  //Verifica se o botao do encoder foi pressionado
  valor = digitalRead(10);
  if (valor != 1)
  {
    Serial.println("Botao pressionado");
    while (digitalRead(10) == 0)
      delay(10);
  }

  //Le as informacoes do encoder
  static int pos = 0;
  encoder.tick();
  int newPos = encoder.getPosition();
  //Se a posicao foi alterada, mostra o valor
  //no Serial Monitor
  if (pos != newPos)
  {
    Serial.print(newPos);
    Serial.println();
    pos = newPos;
  }
}
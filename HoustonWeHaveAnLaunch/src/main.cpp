

#include <RotaryEncoder.h>
#include <Arduino.h>
//Pinos de ligacao do encoder
#define A 2
#define B 3
#define swt 10

RotaryEncoder encoder(A, B);

//Variavel para o botao do encoder
int valor = 0;
int newPos = 0;

void setup()
{
  pinMode(swt, INPUT);
  Serial.begin(9600);
  Serial.println("Gire o encoder....");
}

void loop()
{
  //Verifica se o botao do encoder foi pressionado
  valor = digitalRead(swt);
  if (valor != 1)
  {
    Serial.println("Botao pressionado");
    while (digitalRead(swt) == 0)
      delay(10);
  }

  //Le as informacoes do encoder
  static int pos = 0;
  encoder.tick();
  int newPos = encoder.getPosition();
  //Se a posicao foi alterada, mostra o valor
  if (pos != newPos)
  {
    if (pos > newPos)
    { //aumenta o volume
      Serial.print(newPos);
      Serial.println(" MAIS");
    }
    if (pos < newPos)
    { //diminui o volume
      Serial.print(newPos);
      Serial.println(" MENOS");
    }
    pos = newPos;
  }
}
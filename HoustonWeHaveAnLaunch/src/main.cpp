

#include <RotaryEncoder.h>
#include <Arduino.h>
//Pinos de ligacao do encoder
#define A 2
#define B 3
#define muteAudio 10
#define muteMic 9
#define setPlaylist 8
#define playMusic 7
#define setAudioOut 6

RotaryEncoder encoder(A, B);

//Variavel de controle
int audioMuted = 0;
int micMuted = 0;
int prev_micMuted = 0;
int lofi = 0;
int prev_lofi = 0;
int musicPlaying = 0;
int prev_musicPlaying = 0;
int audioPhone = 0;
//Variavel para o botao do encoder
int newPos = 0;

void setup()
{
  pinMode(muteAudio, INPUT);
  pinMode(muteMic, INPUT);
  pinMode(setPlaylist, INPUT);
  pinMode(playMusic, INPUT);
  pinMode(setAudioOut, INPUT);

  Serial.begin(9600);
  Serial.println("Gire o encoder....");
}

void loop()
{
  //Verifica se o botao do encoder foi pressionado
  //muta o volume geral
  audioMuted = digitalRead(muteAudio);
  if (audioMuted != 1)
  {
    Serial.println("Botao pressionado");
    while (digitalRead(muteAudio) == 0)
      delay(10);
  }
  //muta o microfone
  micMuted = digitalRead(muteMic);
  if (micMuted == 1 && prev_micMuted == 0)
  {
    Serial.println("Microfone mutado");
    prev_micMuted = 1;
    while (digitalRead(muteMic) == 0)
      delay(10);
  }
  if (micMuted == 0 && prev_micMuted == 1)
  {
    Serial.println("Microfone desmutado");
    prev_micMuted = 0;
    while (digitalRead(muteMic) == 0)
      delay(10);
  }
  // play spotify playlist
  lofi = digitalRead(setPlaylist);
  if (lofi == 1 && prev_lofi == 0)
  {
    Serial.println("Playlist: LOFI");
    prev_lofi = 1;
    while (digitalRead(setPlaylist) == 0)
      delay(10);
  }
  if (lofi == 0 && prev_lofi == 1)
  {
    Serial.println("Playlist: ROCK");
    prev_lofi = 0;
    while (digitalRead(setPlaylist) == 0)
      delay(10);
  }
  // choose spotify playlist
  lofi = digitalRead(setPlaylist);
  if (lofi == 1 && prev_lofi == 0)
  {
    Serial.println("Playlist: LOFI");
    prev_lofi = 1;
    while (digitalRead(setPlaylist) == 0)
      delay(10);
  }
  if (lofi == 0 && prev_lofi == 1)
  {
    Serial.println("Playlist: ROCK");
    prev_lofi = 0;
    while (digitalRead(setPlaylist) == 0)
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
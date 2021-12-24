

#include <RotaryEncoder.h>
#include <Arduino.h>
//Pinos de ligacao do encoder
#define A 6
#define B 4
#define muteAudio 15
#define muteMic 3
#define setPlaylist 9
#define playMusic 10
#define setAudioOut 16

RotaryEncoder encoder(A, B);

//Variavel de controle
int audioMuted = 0;
int micMuted = 0;
int prev_micMuted = 0;
int lofi = 0;
int prev_lofi = 0;
int musicPlaying = 0;
int prev_musicPlaying = 0;
int audioFone = 0;
int prev_audioFone = 0;
//Variavel para o botao do encoder
int newPos = 0;

void setup()
{
  pinMode(muteAudio, INPUT);
  pinMode(muteMic, INPUT);
  pinMode(setPlaylist, INPUT);
  pinMode(playMusic, INPUT);
  pinMode(setAudioOut, INPUT);
  prev_micMuted = digitalRead(muteAudio);
  Serial.begin(9600);
  Serial.println("Gire o encoder....");
}

void loop()
{
  //Verifica se o botao do encoder foi pressionado
  //muta o volume geral------------------
  audioMuted = digitalRead(muteAudio);
  if (audioMuted != 1)
  {
    Serial.println("Muda estado do volume geral");
    while (digitalRead(muteAudio) == 0)
      delay(10);
  }

  //muta o microfone--------------------
  micMuted = digitalRead(muteMic);
  if (micMuted == 0 && prev_micMuted == 1)
  {
    Serial.println("Microfone desmutado");
    prev_micMuted = 0;
    delay(10);
  }

  if (micMuted == 1 && prev_micMuted == 0)
  {
    Serial.println("Microfone mutado");
    prev_micMuted = 1;
    delay(10);
  }

  // play spotify playlist----------------
  musicPlaying = digitalRead(playMusic);
  if (musicPlaying == 1 && prev_musicPlaying == 0)
  {
    Serial.println("Play music");
    prev_musicPlaying = 1;
    delay(10);
  }
  if (musicPlaying == 0 && prev_musicPlaying == 1)
  {
    Serial.println("Stop music");
    prev_musicPlaying = 0;
    delay(10);
  }
  // choose spotify playlist-----------------
  lofi = digitalRead(setPlaylist);
  if (lofi == 1 && prev_lofi == 0)
  {
    Serial.println("Playlist: LOFI");
    prev_lofi = 1;
    delay(10);
  }
  if (lofi == 0 && prev_lofi == 1)
  {
    Serial.println("Playlist: ROCK");
    prev_lofi = 0;
    delay(10);
  }
  // choose audio OUTPUT----------------------
  audioFone = digitalRead(setAudioOut);
  if (audioFone == 1 && prev_audioFone == 0)
  {
    Serial.println("Output:Fone");
    prev_audioFone = 1;
    delay(10);
  }
  if (audioFone == 0 && prev_audioFone == 1)
  {
    Serial.println("Output:Tv");
    prev_audioFone = 0;
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
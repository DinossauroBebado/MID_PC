//code by : DinossauroBebado
// MID controls for Windows PC
//references :
//https://github.com/RalphBacon/184-USB-Volume-Control
//https://github.com/NicoHood/HID
//obs : this code could be refactor to be way shorter by using functions,
// but o wrote like that to be easily readable

#include <RotaryEncoder.h>
#include <HID-Project.h>
#include <Arduino.h>
//Pinos de ligacao do encoder
#define A 6
#define B 4
#define muteAudio 15
#define muteMic 9
#define setPlaylist 3
#define playMusic 10
#define setAudioOut 16
// Comment out next line to prevent slow response when
// not actively debugging via serial port monitor
#define DEBUG

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
#ifdef DEBUG
  Serial.begin(9600);
#endif

  Consumer.begin();
  Keyboard.begin();
}

void loop()
{
  //Verifica se o botao do encoder foi pressionado
  //muta o volume geral------------------
  audioMuted = digitalRead(muteAudio);
  if (audioMuted != 1)
  {
#ifdef DEBUG
    Serial.println("Muda estado do volume geral");
#endif

    Consumer.write(MEDIA_VOLUME_MUTE);
    while (digitalRead(muteAudio) == 0)
      delay(10);
  }

  //MICROFONE--------------------
  micMuted = digitalRead(muteMic);
  if (micMuted == 0 && prev_micMuted == 1)
  { //mute mic--------------------
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_RIGHT_CTRL);
    Keyboard.press('4');
    delay(100);
    Keyboard.releaseAll();

#ifdef DEBUG
    Serial.println("Microfone desmutado");
#endif

    prev_micMuted = 0;

    delay(10);
  }

  if (micMuted == 1 && prev_micMuted == 0)
  { //unmute m--------------------
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_RIGHT_CTRL);
    Keyboard.press('3');
    delay(100);
    Keyboard.releaseAll();

#ifdef DEBUG
    Serial.println("Microfone mutado");
#endif

    prev_micMuted = 1;

    delay(100);
  }

  //spotify playlist----------------
  musicPlaying = digitalRead(playMusic);
  if (musicPlaying == 1 && prev_musicPlaying == 0)
  { // play spotify playlist----------------
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_RIGHT_CTRL);
    Keyboard.press('5');
    delay(100);
    Keyboard.releaseAll();

#ifdef DEBUG
    Serial.println("Play music");
#endif

    prev_musicPlaying = 1;
    delay(100);
  }
  if (musicPlaying == 0 && prev_musicPlaying == 1)
  { //pause spotify playlist----------------
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_RIGHT_CTRL);
    Keyboard.press('6');
    delay(100);
    Keyboard.releaseAll();

#ifdef DEBUG
    Serial.println("Stop music");
#endif

    prev_musicPlaying = 0;

    delay(100);
  }
  // choose spotify playlist-----------------
  lofi = digitalRead(setPlaylist);
  if (lofi == 1 && prev_lofi == 0)
  { // choose lofi playlist-----------------
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_RIGHT_CTRL);
    Keyboard.press('1');
    delay(100);
    Keyboard.releaseAll();

#ifdef DEBUG
    Serial.println("Playlist: LOFI");
#endif

    prev_lofi = 1;

    delay(100);
  }
  if (lofi == 0 && prev_lofi == 1)
  { // choose rock  playlist-----------------
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_RIGHT_CTRL);
    Keyboard.press('2');
    delay(100);
    Keyboard.releaseAll();

#ifdef DEBUG
    Serial.println("Playlist: ROCK");
#endif

    prev_lofi = 0;

    delay(100);
  }

  // choose audio OUTPUT----------------------
  audioFone = digitalRead(setAudioOut);
  if (audioFone == 1 && prev_audioFone == 0)
  { // choose fone output -----------------
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_RIGHT_CTRL);
    Keyboard.press('7');
    delay(100);
    Keyboard.releaseAll();

#ifdef DEBUG
    Serial.println("Output:Fone");
#endif

    prev_audioFone = 1;

    delay(100);
  }
  if (audioFone == 0 && prev_audioFone == 1)
  { // choose fone output -----------------
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_RIGHT_CTRL);
    Keyboard.press('8');
    delay(100);
    Keyboard.releaseAll();

#ifdef DEBUG
    Serial.println("Output:TV");
#endif

    prev_audioFone = 0;

    delay(100);
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
#ifdef DEBUG
      Serial.print(newPos);
      Serial.println(" MAIS");
#endif

      Consumer.write(MEDIA_VOL_DOWN);
    }
    if (pos < newPos)
    { //diminui o volume
#ifdef DEBUG
      Serial.print(newPos);
#endif

      Consumer.write(MEDIA_VOL_UP);
    }
    pos = newPos;
  }
}
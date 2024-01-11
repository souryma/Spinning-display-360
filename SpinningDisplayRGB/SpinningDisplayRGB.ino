#include <TimeLib.h>
//int LED_PINS[] = { 19, 18, 17, 16, 15, 14, 13, 12 };
int LED_PINS[] = { 49, 50, 51, 52, 53, 54, 55, 56 };
int INPUT_PIN = 5;
int DEFAULT_LED = 13;
int CUSTOM_CHAR_LENGTH = 7;
int LED_COUNT = 8;
int k;
int letterThickness = 0;
int letterSpacing = 0;

const unsigned char CUSTOM_CHAR[95][7] = {
  { 00000000, 00000000, 00000000, 00000000, 00000000, 00000000, 00000000 },  //   0x20 32
  { 00000000, 00000000, 0x6f, 00000000, 00000000, 00000000, 00000000 },  // ! 0x21 33
  { 00000000, 0x07, 00000000, 0x07, 00000000, 00000000, 00000000 },  // " 0x22 34
  { 0x14, 0x7f, 0x14, 0x7f, 0x14, 00000000, 00000000 },  // # 0x23 35
  { 00000000, 0x07, 0x04, 0x1e, 00000000, 00000000, 00000000 },  // $ 0x24 36
  { 0x23, 0x13, 0x08, 0x64, 0x62, 00000000, 00000000 },  // % 0x25 37
  { 0x36, 0x49, 0x56, 0x20, 0x50, 00000000, 00000000 },  // & 0x26 38
  { 00000000, 00000000, 0x07, 00000000, 00000000, 00000000, 00000000 },  // ' 0x27 39
  { 00000000, 0x1c, 0x22, 0x41, 00000000, 00000000, 00000000 },  // ( 0x28 40
  { 00000000, 0x41, 0x22, 0x1c, 00000000, 00000000, 00000000 },  // ) 0x29 41
  { 0x14, 0x08, 0x3e, 0x08, 0x14, 00000000, 00000000 },  // * 0x2a 42
  { 0x08, 0x08, 0x3e, 0x08, 0x08, 00000000, 00000000 },  // + 0x2b 43
  { 00000000, 0x50, 0x30, 00000000, 00000000, 00000000, 00000000 },  // , 0x2c 44
  { 0x08, 0x08, 0x08, 0x08, 0x08, 00000000, 00000000 },  // - 0x2d 45
  { 00000000, 0x60, 0x60, 00000000, 00000000, 00000000, 00000000 },  // . 0x2e 46
  { 0x20, 0x10, 0x08, 0x04, 0x02, 00000000, 00000000 },  // / 0x2f 47
  { 0x3e, 0x51, 0x49, 0x45, 0x3e, 00000000, 00000000 },  // 0 0x30 48
  { 00000000, 0x42, 0x7f, 0x40, 00000000, 00000000, 00000000 },  // 1 0x31 49
  { 0x42, 0x61, 0x51, 0x49, 0x46, 00000000, 00000000 },  // 2 0x32 50
  { 0x21, 0x41, 0x45, 0x4b, 0x31, 00000000, 00000000 },  // 3 0x33 51
  { 0x18, 0x14, 0x12, 0x7f, 0x10, 00000000, 00000000 },  // 4 0x34 52
  { 0x27, 0x45, 0x45, 0x45, 0x39, 00000000, 00000000 },  // 5 0x35 53
  { 0x3c, 0x4a, 0x49, 0x49, 0x30, 00000000, 00000000 },  // 6 0x36 54
  { 0x01, 0x71, 0x09, 0x05, 0x03, 00000000, 00000000 },  // 7 0x37 55
  { 0x36, 0x49, 0x49, 0x49, 0x36, 00000000, 00000000 },  // 8 0x38 56
  { 0x06, 0x49, 0x49, 0x29, 0x1e, 00000000, 00000000 },  // 9 0x39 57
  { 00000000, 0x36, 0x36, 00000000, 00000000, 00000000, 00000000 },  // : 0x3a 58
  { 00000000, 0x56, 0x36, 00000000, 00000000, 00000000, 00000000 },  // ; 0x3b 59
  { 0x08, 0x14, 0x22, 0x41, 00000000, 00000000, 00000000 },  // < 0x3c 60
  { 0x14, 0x14, 0x14, 0x14, 0x14, 00000000, 00000000 },  // = 0x3d 61
  { 00000000, 0x41, 0x22, 0x14, 0x08, 00000000, 00000000 },  // > 0x3e 62
  { 0x02, 0x01, 0x51, 0x09, 0x06, 00000000, 00000000 },  // ? 0x3f 63
  { 0x3e, 0x41, 0x5d, 0x49, 0x4e, 00000000, 00000000 },  // @ 0x40 64
  { 0x7e, 0x09, 0x09, 0x09, 0x7e, 00000000, 00000000 },  // A 0x41 65
  { 0x7f, 0x49, 0x49, 0x49, 0x36, 00000000, 00000000 },  // B 0x42 66
  { 0x3e, 0x41, 0x41, 0x41, 0x22, 00000000, 00000000 },  // C 0x43 67
  { 0x7f, 0x41, 0x41, 0x41, 0x3e, 00000000, 00000000 },  // D 0x44 68
  { 0x7f, 0x49, 0x49, 0x49, 0x41, 00000000, 00000000 },  // E 0x45 69
  { 0x7f, 0x09, 0x09, 0x09, 0x01, 00000000, 00000000 },  // F 0x46 70
  { 0x3e, 0x41, 0x49, 0x49, 0x7a, 00000000, 00000000 },  // G 0x47 71
  { 0x7f, 0x08, 0x08, 0x08, 0x7f, 00000000, 00000000 },  // H 0x48 72
  { 00000000, 0x41, 0x7f, 0x41, 00000000, 00000000, 00000000 },  // I 0x49 73
  { 0x20, 0x40, 0x41, 0x3f, 0x01, 00000000, 00000000 },  // J 0x4a 74
  { 0x7f, 0x08, 0x14, 0x22, 0x41, 00000000, 00000000 },  // K 0x4b 75
  { 0x7f, 0x40, 0x40, 0x40, 0x40, 00000000, 00000000 },  // L 0x4c 76
  { 0x7f, 0x02, 0x0c, 0x02, 0x7f, 00000000, 00000000 },  // M 0x4d 77
  { 0x7f, 0x04, 0x08, 0x10, 0x7f, 00000000, 00000000 },  // N 0x4e 78
  { 0x3e, 0x41, 0x41, 0x41, 0x3e, 00000000, 00000000 },  // O 0x4f 79
  { 0x7f, 0x09, 0x09, 0x09, 0x06, 00000000, 00000000 },  // P 0x50 80
  { 0x3e, 0x41, 0x51, 0x21, 0x5e, 00000000, 00000000 },  // Q 0x51 81
  { 0x7f, 0x09, 0x19, 0x29, 0x46, 00000000, 00000000 },  // R 0x52 82
  { 0x46, 0x49, 0x49, 0x49, 0x31, 00000000, 00000000 },  // S 0x53 83
  { 0x01, 0x01, 0x7f, 0x01, 0x01, 00000000, 00000000 },  // T 0x54 84
  { 0x3f, 0x40, 0x40, 0x40, 0x3f, 00000000, 00000000 },  // U 0x55 85
  { 0x0f, 0x30, 0x40, 0x30, 0x0f, 00000000, 00000000 },  // V 0x56 86
  { 0x3f, 0x40, 0x30, 0x40, 0x3f, 00000000, 00000000 },  // W 0x57 87
  { 0x63, 0x14, 0x08, 0x14, 0x63, 00000000, 00000000 },  // X 0x58 88
  { 0x07, 0x08, 0x70, 0x08, 0x07, 00000000, 00000000 },  // Y 0x59 89
  { 0x61, 0x51, 0x49, 0x45, 0x43, 00000000, 00000000 },  // Z 0x5a 90
  { 0x3c, 0x4a, 0x49, 0x29, 0x1e, 00000000, 00000000 },  // [ 0x5b 91
  { 0x02, 0x04, 0x08, 0x10, 0x20, 00000000, 00000000 },  // \ 0x5c 92
  { 00000000, 0x41, 0x7f, 00000000, 00000000, 00000000, 00000000 },  // ] 0x5d 93
  { 0x04, 0x02, 0x01, 0x02, 0x04, 00000000, 00000000 },  // ^ 0x5e 94
  { 0x40, 0x40, 0x40, 0x40, 0x40, 00000000, 00000000 },  // _ 0x5f 95
  { 00000000, 00000000, 0x03, 0x04, 00000000, 00000000, 00000000 },  // ` 0x60 96
  { 0x20, 0x54, 0x54, 0x54, 0x78, 00000000, 00000000 },  // a 0x61 97
  { 0x7f, 0x48, 0x44, 0x44, 0x38, 00000000, 00000000 },  // b 0x62 98
  { 0x38, 0x44, 0x44, 0x44, 0x20, 00000000, 00000000 },  // c 0x63 99
  { 0x38, 0x44, 0x44, 0x48, 0x7f, 00000000, 00000000 },  // d 0x64 100
  { 0x38, 0x54, 0x54, 0x54, 0x18, 00000000, 00000000 },  // e 0x65 101
  { 0x08, 0x7e, 0x09, 0x01, 0x02, 00000000, 00000000 },  // f 0x66 102
  { 0x0c, 0x52, 0x52, 0x52, 0x3e, 00000000, 00000000 },  // g 0x67 103
  { 0x7f, 0x08, 0x04, 0x04, 0x78, 00000000, 00000000 },  // h 0x68 104
  { 00000000, 0x44, 0x7d, 0x40, 00000000, 00000000, 00000000 },  // i 0x69 105
  { 0x20, 0x40, 0x44, 0x3d, 00000000, 00000000, 00000000 },  // j 0x6a 106
  { 00000000, 0x7f, 0x10, 0x28, 0x44, 00000000, 00000000 },  // k 0x6b 107
  { 00000000, 0x41, 0x7f, 0x40, 00000000, 00000000, 00000000 },  // l 0x6c 108
  { 0x7c, 0x04, 0x18, 0x04, 0x78, 00000000, 00000000 },  // m 0x6d 109
  { 0x7c, 0x08, 0x04, 0x04, 0x78, 00000000, 00000000 },  // n 0x6e 110
  { 0x38, 0x44, 0x44, 0x44, 0x38, 00000000, 00000000 },  // o 0x6f 111
  { 0x7c, 0x14, 0x14, 0x14, 0x08, 00000000, 00000000 },  // p 0x70 112
  { 0x08, 0x14, 0x14, 0x18, 0x7c, 00000000, 00000000 },  // q 0x71 113
  { 0x7c, 0x08, 0x04, 0x04, 0x08, 00000000, 00000000 },  // r 0x72 114
  { 0x48, 0x54, 0x54, 0x54, 0x20, 00000000, 00000000 },  // s 0x73 115
  { 0x04, 0x3f, 0x44, 0x40, 0x20, 00000000, 00000000 },  // t 0x74 116
  { 0x3c, 0x40, 0x40, 0x20, 0x7c, 00000000, 00000000 },  // u 0x75 117
  { 0x1c, 0x20, 0x40, 0x20, 0x1c, 00000000, 00000000 },  // v 0x76 118
  { 0x3c, 0x40, 0x30, 0x40, 0x3c, 00000000, 00000000 },  // w 0x77 119
  { 0x44, 0x28, 0x10, 0x28, 0x44, 00000000, 00000000 },  // x 0x78 120
  { 0x0c, 0x50, 0x50, 0x50, 0x3c, 00000000, 00000000 },  // y 0x79 121
  { 0x44, 0x64, 0x54, 0x4c, 0x44, 00000000, 00000000 },  // z 0x7a 122
  { 00000000, 0x08, 0x36, 0x41, 0x41, 00000000, 00000000 },  // { 0x7b 123
  { 00000000, 00000000, 0x7f, 00000000, 00000000, 00000000, 00000000 },  // | 0x7c 124
  { 0x41, 0x41, 0x36, 0x08, 00000000, 00000000, 00000000 },  // } 0x7d 125
  { 0xe, 0x1f, 0x3f, 0x7e, 0x3f, 0x1f, 0xe },    // <3 0x7e 126
};



char Display_String[] = "IEM P8~";
char Display_String2[] = "IEM P8~ ";
char Display_String3[] = "IEM P8~    ";
unsigned long stop = 0;

char colors[] = {'C', 'Y', 'G', 'W', 'O', 'R'};
char current_color = 'R';

#include "FastLED.h"

byte bright = 250;  // luminosité des LEDs

int brightness = 100;

#define NUM_LEDS 144  // nombre de LEDs
#define PIN 4         // port de connexion ws2812b
#define CLOCK_PIN 6
CRGB leds[NUM_LEDS];

void SwitchLed(int ledNb, bool value) {
  if (value) {
    leds[ledNb] = CRGB::Cyan;
  } else {
    leds[ledNb] = CRGB::Black;
  }
}

void SwitchLedColor(int ledNb, bool value, char color) {
  if (value) {
    switch (color) {
    case 'C':leds[ledNb] = CRGB::Cyan;
    break;
    case 'R':leds[ledNb] = CRGB::Red;
    break;
    case 'G':leds[ledNb] = CRGB::Green;
    break;
    case 'W':leds[ledNb] = CRGB::White;
    break;
    case 'Y':leds[ledNb] = CRGB::Yellow;
    break;
    case 'O':leds[ledNb] = CRGB::Orange;
    break;
    }
    
  } else {
    leds[ledNb] = CRGB::Black;
  }
}

void setup() {
  Serial.begin(9600);
  // for (int i = 0; i < LED_COUNT; i++) {
  //   pinMode(LED_PINS[i], OUTPUT);
  // }

  // 72 leds strip
  //FastLED.addLeds<WS2812, PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  // 144 leds strip
  FastLED.addLeds<APA102, PIN, CLOCK_PIN, BGR>(leds, NUM_LEDS);

  FastLED.setBrightness(brightness);
  pinMode(INPUT_PIN, INPUT);

  stop = 0;
}

int state = 1;

bool CompareFloats(float A, float B) {
  return A == B;
}

bool CompareInts(int A, int B) {
  return A == B;
}

bool GreaterThanFloat(float A, float B) {
  return A > B;
}

bool GreaterThanInt(int A, int B) {
  return A > B;
}

int loop_nb = 0;

void loop() {
  if (loop_nb < 1) {
      //switch on all leds
      for (int i = 0; i < 70; i++) {
        SwitchLedColor(i, true, 'G');
        FastLED.setBrightness(brightness);
        FastLED.show();
      }

      // SwitchLedColor(49, false, 'G');
      // SwitchLedColor(50, false, 'G');
      // SwitchLedColor(51, false, 'G');
      // SwitchLedColor(52, false, 'G');
      // SwitchLedColor(53, false, 'G');
      // SwitchLedColor(54, false, 'G');
      // SwitchLedColor(55, false, 'G');
      // SwitchLedColor(56, false, 'G');

      SwitchLedColor(12, false, 'G');
      SwitchLedColor(13, false, 'G');
      SwitchLedColor(14, false, 'G');
      SwitchLedColor(15, false, 'G');
      SwitchLedColor(16, false, 'G');
      SwitchLedColor(17, false, 'G');
      SwitchLedColor(18, false, 'G');
      SwitchLedColor(19, false, 'G');




      loop_nb = 1;
  }
  

  while (digitalRead(INPUT_PIN) != 0) {
    // Le capteur ne detecte rien
  }

  //anim();

  // le capteur a détecté quelque chose

  float temp = millis() - stop;

  //if (millis() - stop < 3000) {
  if (GreaterThanFloat(3000, temp) == true) {
    state = 1;
  } else {
    if (GreaterThanFloat(6000, temp) == true) {
      state = 2;
    } else {
      state = 3;
    }
  }

  if (GreaterThanFloat(temp, 9000) == true) {
    stop = millis();
  }

  for (int a = sizeof(Display_String) - 1; a > -1; a--) {
    if (CompareInts(state, 1) == true) {
      PRINT_STRING(Display_String[a]);
    } else {
      if (CompareInts(state, 2) == true) {
        PRINT_STRING(Display_String2[a]);

      } else {
        PRINT_STRING(Display_String3[a]);
      }
    }
  }
}

char color_char = 'C';

void PRINT_STRING(char data) {

  if (GreaterThanInt(32, data) == true || GreaterThanInt(32, data) == true) {
    data = 32;
  }
  data -= 32;

  int data_int = data;

  // Lettre
  for (int x = CUSTOM_CHAR_LENGTH - 1; x > -1; x--) {
    byte temp_data = CUSTOM_CHAR[data][x];

    if (data_int == 94) {
      color_char = 'R';
    } else {
      color_char = 'C';
    }

    // Barre de lettre
    for (int y = 0; y < LED_COUNT; y++) {
      SwitchLedColor(LED_PINS[y], bitRead(temp_data, y), color_char);
    }
    FastLED.setBrightness(brightness);
    FastLED.show();
    // Epaisseur des lettres
    delayMicroseconds(letterThickness);
  }

  for (k = 0; k < LED_COUNT; k++) {
    //SwitchLed(LED_PINS[k], false);
  }
  //FastLED.setBrightness(0);
  //FastLED.show();

  delayMicroseconds(letterSpacing);
}

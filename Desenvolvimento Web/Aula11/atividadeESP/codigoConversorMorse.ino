#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OBS: O CÓDIGO FOI FEITO PARA O ESP 8266.
// O grupo responsável por esse projeto composto por:

// Gabriel do Espírito Santo
// Maguiane Gloden Lopes
// Nicoli Saldanha Ricardo
// Pablo Francisco Freitas Barauce 
// Pedro Augusto Marques Kloster


const char* ssid = "Coloque o nome da sua rede wifi";
const char* password = "senha da rede";

ESP8266WebServer server(80);

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
#define OLED_RESET -1    
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int ledPin = LED_BUILTIN; 
const int dotDelay = 150; 

const String morseAlphabet[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", 
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." 
};

const String morseNumbers[] = {
  "-----", ".----", "..---", "...--", "....-", 
  ".....", "-....", "--...", "---..", "----."  
};

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println("Falha na tela OLED!");
    for(;;); 
  }
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 10);
  display.println("Conectando Wi-Fi...");
  display.display();

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  mostrarIPnaTela(); 

  server.on("/morse", []() {
    server.sendHeader("Access-Control-Allow-Origin", "*");

    if (server.hasArg("palavra")) {
      String msg = server.arg("palavra");
      
      server.send(200, "text/plain", "Mensagem recebida"); 
      
      msg.toUpperCase();
      Serial.print("Msg: ");
      Serial.println(msg);
      
      playMorseString(msg);

      mostrarIPnaTela();
    } else {
      server.send(400, "text/plain", "Palavra não inserida");
    }
  });

  server.onNotFound([]() {
    if (server.method() == HTTP_OPTIONS) {
      server.sendHeader("Access-Control-Allow-Origin", "*");
      server.sendHeader("Access-Control-Allow-Methods", "GET, OPTIONS");
      server.send(204);
    } else {
      server.send(404, "text/plain", "Rota não encontrada");
    }
  });

  server.begin();
}

void loop() {
  server.handleClient();
}

void mostrarIPnaTela() {
  display.clearDisplay();
  display.setCursor(0, 10);
  display.setTextSize(2); 
  display.println("IP:");
  
  display.setCursor(0, 40);

  display.setTextSize(1); 
  display.println(WiFi.localIP());
  display.display();
}

void playMorseString(String text) {
  for (int i = 0; i < text.length(); i++) {
    char c = text[i];
    String code = "";
    
    if (c >= 'A' && c <= 'Z') {
      code = morseAlphabet[c - 'A'];
    } 
    else if (c >= '0' && c <= '9') {
      code = morseNumbers[c - '0'];
    }
    else if (c == ' ') {
      delay(dotDelay * 4); 
    }
    
    if (code != "") {
      display.clearDisplay(); 
      
      display.setCursor(20, 20);
      display.setTextSize(3); 
      display.print(c);
      
      display.setCursor(50, 25);
      display.setTextSize(2);
      display.print(code);
      
      display.display();
      
      
      playMorseChar(code); 
    }
    
    delay(dotDelay * 3); 
  }
}

void playMorseChar(String morseCode) {
  for (int i = 0; i < morseCode.length(); i++) {
    char symbol = morseCode[i];
    
    digitalWrite(ledPin, LOW); 
    if (symbol == '.') { delay(dotDelay); } 
    else if (symbol == '-') { delay(dotDelay * 3); }
    
    digitalWrite(ledPin, HIGH); 
    delay(dotDelay); 
  }
}
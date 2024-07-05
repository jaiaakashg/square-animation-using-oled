#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <math.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  
  display.clearDisplay();

  display.setTextColor(WHITE);
}

void loop() {
  display.clearDisplay();
  drawRotatingSquare();
  display.display();
  delay(30);
}

void drawRotatingSquare() {
  int centerX = SCREEN_WIDTH / 2;
  int centerY = SCREEN_HEIGHT / 2;
  int squareSize = 20;
  float rotationSpeed = 0.1; // Adjust rotation speed as needed
  
  float angle = millis() * rotationSpeed / 1000.0;
  
  int x1 = centerX + squareSize * cos(angle);
  int y1 = centerY + squareSize * sin(angle);
  int x2 = centerX - squareSize * cos(angle);
  int y2 = centerY + squareSize * sin(angle);
  int x3 = centerX - squareSize * cos(angle);
  int y3 = centerY - squareSize * sin(angle);
  int x4 = centerX + squareSize * cos(angle);
  int y4 = centerY - squareSize * sin(angle);

  display.drawLine(x1, y1, x2, y2, WHITE);
  display.drawLine(x2, y2, x3, y3, WHITE);
  display.drawLine(x3, y3, x4, y4, WHITE);
  display.drawLine(x4, y4, x1, y1, WHITE);
}


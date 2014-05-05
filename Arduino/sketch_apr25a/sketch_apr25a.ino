#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

void setup()  
{
  lcd.begin(16,2);   // initialize the lcd for 16 chars 2 lines, turn on backlight
  lcd.setCursor(0,0); //Start at character 4 on line 0
  lcd.print("CTP Tech Radar");  
  lcd.setCursor(0,1);
  lcd.print("Press Any Key"); 
}

void loop()
{
  showDifferentPointByPort(22, "Jetty", "Master");
  showDifferentPointByPort(23, "Tomcat", "Familiar");
  showDifferentPointByPort(24, "Node.js", "Know");

  showDifferentPointByPort(25, "Spring", "Master");
  showDifferentPointByPort(26, "Angularjs", "Familiar");
  showDifferentPointByPort(27, "Freemarker", "Know");

  showDifferentPointByPort(28, "Jasmine", "Master");
  showDifferentPointByPort(29, "Protractor", "Familiar");
  showDifferentPointByPort(30, "Concordion", "Know");

  showDifferentPointByPort(31, "Java", "Master");
  showDifferentPointByPort(32, "JavaScript", "Familiar");
  showDifferentPointByPort(33, "JSP", "Know");
}

void showDifferentPointByPort(int portNum, char * keyword, char* description) {
    pinMode(portNum, OUTPUT);
  digitalWrite(portNum,LOW);
  pinMode(portNum, INPUT);
  if(digitalRead(portNum)==HIGH)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(keyword);
    lcd.setCursor(0,1);
    lcd.print(description);
  } 
}

// including liquid crystal to enable using the lcd
#include<LiquidCrystal.h>
// setting the lcd pins to the arduino
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//creating characters to show on lcd by lighting some points on lcd
byte smiley[8]{
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b10001,
  0b01110,
  0b00000,
  0b00000
};
byte face[8]{
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b11111,
  0b00000,
  0b00000,
};
byte sad[8]{
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b01110,
  0b10001,
  0b00000,
  0b00000
};

void setup() {
// setting pins 8,9 to lcd and 10,11,12, to the leds
  DDRB=0b00011111;
  // setting 1,2,3 to leds and 4,5,6 to lcd
  DDRD=0b01111110;
  // defining 16*2 lcd
  lcd.begin(16,2);
  // creating characters which previously defined
  lcd.createChar(0,smiley);
  lcd.createChar(1,face);
  lcd.createChar(2,sad);
  
}

void loop(){

  //green for 20 seconds
  for(int g=20; g>0; g--){

    // clearing the lcd
    lcd.clear();
    // setting lcd to write in column 0 and row 0
    lcd.setCursor(0,0);
    // turn on pin 10 and turn off all other pins
    PORTB=0b00000100;
    // print things on screen
    lcd.print("GO ");
    lcd.print(g);
    lcd.print(" ");
    lcd.write(byte(0));

    // setting lcd to write in column 1 and row 0
    lcd.setCursor(0,1);
    // turn on pin 4 and turn off all other pins
    PORTD=0b00001000;
    // print things on screen
    lcd.print("DON'T WALK ");
    lcd.print(g);
    lcd.print(" ");
    lcd.write(byte(2));

    // delay one second
    delay(1000);

  }

  //yellow for 5 seconds
  for(int y=5; y>0; y--){

    lcd.clear();
    lcd.setCursor(0,0);
    PORTB=0b00001000;
    lcd.print("STEADY ");
    lcd.print(y);
    lcd.print(" ");
    lcd.write(byte(1));

    lcd.setCursor(0,1);
    PORTD=0b00000100;
    lcd.print("STEADY ");
    lcd.print(y);
    lcd.print(" ");
    lcd.write(byte(1));
    
    delay(1000);
  
  }
  
  //red for 20 seconds
  for(int r=20; r>0; r--){

    lcd.setCursor(0,0);
    lcd.clear();
    PORTB=0b00010000;
    lcd.print("STOP ");
    lcd.print(r);
    lcd.print(" ");
    lcd.write(byte(2));

    lcd.setCursor(0,1);
    PORTD=0b00000010;
    lcd.print("WALK ");
    lcd.print(r);
    lcd.print(" ");
    lcd.write(byte(0));
  
    delay(1000);
  }
}  

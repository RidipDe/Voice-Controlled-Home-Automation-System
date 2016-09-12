#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13); 
String voice;

int led1 = 2; //Connect LED 1 To Pin #2
int led2 = 3; //Connect LED 2 To Pin #3
int led3 = 4; //Connect LED 3 To Pin #4
int led4 = 5; //Connect LED 4 To Pin #5

void setup() 
{
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("SMART HOME");
  lcd.setCursor(0,1);
  lcd.print("!!! Welcome !!!");
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  }
//-----------------------------------------------------------------------// 
void loop() 
{
  while (Serial.available())
  {  
  delay(10); //Delay added to make thing stable
  char c = Serial.read(); //Conduct a serial read
  if (c == '#') 
  {
    break;
    } //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
  } 
  if (voice.length() > 0) 
  {
	  Serial.println(voice);
	  lcd.clear();
	  lcd.print(voice);
	  if(voice == "*light on") 
	  {
	  digitalWrite(led1, HIGH);
	  delay(1000);
		}
	  else if(voice == "*light off") 
	  {
	  digitalWrite(led1, LOW);
	  delay(1000);
		}
	  else if(voice == "*fan on") 
	  {
	  digitalWrite(led3, HIGH);
	  delay(1000);
		}
	  else if(voice == "*switch off fan")
	  {
	  digitalWrite(led3, LOW);
	  delay(1000);
		}
		
	  else if(voice == "*appliances on") 
	  {
	  digitalWrite(led1, HIGH);
	  digitalWrite(led2, HIGH);
	  digitalWrite(led3, HIGH);
	  digitalWrite(led4, HIGH);
	  //digitalWrite(led5, LOW);
	  delay(1000);
		}
	  else if((voice == "*appliances of")||(voice == "*appliances off"))
	  {
	  digitalWrite(led1, LOW);
	  digitalWrite(led2, LOW);
	  digitalWrite(led3, LOW);
	  digitalWrite(led4, LOW);
	  //digitalWrite(led5, LOW);
	  delay(1000);
		}
	 //-----------------------------------------------------------------------// 
	voice="";
  }
} //Reset the variable after initiating



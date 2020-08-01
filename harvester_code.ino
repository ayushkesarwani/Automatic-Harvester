#include <Keypad.h>
int a=0,x=1;
int b=0,y=1;
int t=0,z=1;
int k,z1=1,c=0;
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {2,3,8,9}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {10,11,12,13}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int n1=7;
int n2=6;
int n3=5;
int n4=4;
int mini=1;
int t1,t2;
int deg;
int temp=0;
void setup()
{
  Serial.begin(9600);
while(z==1)
{
  char key = keypad.getKey();
  if (key != NO_KEY){
    Serial.println(key);

   if(key=='#'){
  Serial.println("\n");
  //Serial.println(a);
  //Serial.println(b);
  break;}
  
    if(key=='B')
    t=1;
    if(key=='C')
    t=2;
    if(t==0)
    {
      storeA(key);
    }
    else if(t==1 && key!='B')
    {
      storeB(key);
    }
    else if(key!='C' && t==2)
    {
      storeC(key);
    }
  }
  
} 
  pinMode(n1,OUTPUT);
  pinMode(n2,OUTPUT);
  pinMode(n3,OUTPUT);
  pinMode(n4,OUTPUT);
  t1=2*(int)(a*1.6);
  t2=2*(int)(b*1.6);
  
  
}

void storeA(char key)
{
  
 int z=(int)key-48;
 a=a*x+z;
  x=10;
  Serial.println(a);
}
void storeB(char key)
{
  int j=(int)key-48;
  b=b*y+j;
  y=10;
  Serial.println(b);
}
void storeC(char key)
{
  int k=(int)key-48;
  c=c*z1+k;
  z1=10;
  Serial.println(c);
}
void loop()
{
  Serial.println(t1);
  Serial.println(t2);
  int i;
  if(temp==0)
  {
  for(i=0;i<t1;i++)
  {
  startcar();
  delay(500);
  }
  stopcar();
  delay(1000);
  rightturn();
  delay(c);
  for(i=0;i<t2;i++)
  {
  startcar();
  delay(500);
  }
  stopcar();
  delay(1000);
  rightturn();
  delay(c);
  for(i=0;i<t1;i++)
  {
  startcar();
  delay(500);
  }
  stopcar();
  delay(1000);
  rightturn();
  delay(c);
  temp=1;
  }
  else
  {
  for(i=0;i<t1;i++)
  {
  startcar();
  delay(500);
  }
  stopcar();
  delay(1000);
  rightturn();
  delay(c);
  
  for(i=0;i<t2;i++)
  {
  startcar();
  delay(500);
  }
  stopcar();
  delay(1000);
  rightturn();
  delay(c);
  }
  t1=t1-mini;
  t2=t2-mini;
  if(t1<=0 && t2<=0)
  {
    endcar();
  }
}
void startcar()
{
  digitalWrite(n1,LOW);
  digitalWrite(n2,HIGH);
  digitalWrite(n3,LOW);
  digitalWrite(n4,HIGH);
}
void stopcar()
{ 
  digitalWrite(n1,LOW);
  digitalWrite(n2,LOW);
  digitalWrite(n3,LOW);
  digitalWrite(n4,LOW);
}
void rightturn()
{
 digitalWrite(n1,HIGH);
  digitalWrite(n2,LOW);
  digitalWrite(n3,LOW);
  digitalWrite(n4,HIGH); 
}
void endcar()
{
  digitalWrite(n1,LOW);
  digitalWrite(n2,LOW);
  digitalWrite(n3,LOW);
  digitalWrite(n4,LOW);
  delay(100000);
}

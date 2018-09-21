#include "U8glib.h"
const int KEY0 = 11;
const int KEY1 = 10;
const int KEY2 = 9;
const int RES0 = 7;
const int RES1 = 6;
const int RES2 = 5;
const int RES3 = 4;                     
int buttonState0 = 0;// variable for reading the pushbutton status
int buttonState1 = 0;// variables will change:
int buttonState2 = 0;

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE|U8G_I2C_OPT_DEV_0); // I2C / TWI
void draw(void)
{
    u8g.setFont(u8g_font_unifont);

    int value0=0;            //定义值为0，也可以在程序一开始定义
    value0=analogRead(A0);  //使模拟信号输入的值为value
    float val0=value0*(5.0/1023.0);   //由于模拟信号输入的值为0到1023的值，即为0到5v的值，这里可以转换一下

    int value1=0;            //定义值为0，也可以在程序一开始定义
    value1=analogRead(A1);  //使模拟信号输入的值为value
    float val1=value1*(5.0/1023.0);   //由于模拟信号输入的值为0到1023的值，即为0到5v的值，这里可以转换一下

    int value2=0;            //定义值为0，也可以在程序一开始定义
    float huoer0=0;
    value2=analogRead(A2);  //使模拟信号输入的值为value
    float val2=value2*(5.0/1023.0);   //由于模拟信号输入的值为0到1023的值，即为0到5v的值，这里可以转换一下
    huoer0=(val2-2.5)/0.066;

    int value3=0;            //定义值为0，也可以在程序一开始定义
    float huoer1=0;
    value3=analogRead(A3);  //使模拟信号输入的值为value
    float val3=value3*(5.0/1023.0);   //由于模拟信号输入的值为0到1023的值，即为0到5v的值，这里可以转换一下
    huoer1=(val3-2.5)/0.066;

    float power = huoer1*val1;
    float effic = power/(huoer0*val0);
    u8g.setPrintPos(0, 13);
    u8g.print("valuin=");
    u8g.print(val0);
   
    u8g.setPrintPos(0, 28);
    u8g.print("valout=");
    u8g.print(val1);
   
    u8g.setPrintPos(0, 43);
    u8g.print("power=");
    u8g.print(power);
   
    u8g.setPrintPos(0, 58);
    u8g.print("effict=");
    u8g.print(effic);
  }

void setup(void) {
    //pinMode(LED_BUILTIN, OUTPUT);
    pinMode(A0,INPUT);
    pinMode(A1,INPUT);
    pinMode(A2,INPUT);
    pinMode(A3,INPUT);
    pinMode(RES0, OUTPUT);// initialize the LED pin as an output:
    pinMode(RES1, OUTPUT);
    pinMode(RES2, OUTPUT);
    pinMode(RES3, OUTPUT);
    pinMode(KEY0, INPUT);// initialize the pushbutton pin as an input:
    pinMode(KEY1, INPUT);
    pinMode(KEY2, INPUT);
    //pinMode(KEY3, INPUT);
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255,255,255);
  }
 
  pinMode(8, OUTPUT);
}
void loop(void) {
 
  u8g.firstPage();// picture loop 
  do
  {
    draw();
    int value0=0;            //定义值为0，也可以在程序一开始定义
    value0=analogRead(A0);  //使模拟信号输入的值为value
    float val0=value0*(5.0/1023.0);   //由于模拟信号输入的值为0到1023的值，即为0到5v的值，这里可以转换一下

    int value1=0;            //定义值为0，也可以在程序一开始定义
    value1=analogRead(A1);  //使模拟信号输入的值为value
    float val1=value1*(5.0/1023.0);   //由于模拟信号输入的值为0到1023的值，即为0到5v的值，这里可以转换一下

    int value2=0;            //定义值为0，也可以在程序一开始定义
    float huoer0=0;
    value2=analogRead(A2);  //使模拟信号输入的值为value
    float val2=value2*(5.0/1023.0);   //由于模拟信号输入的值为0到1023的值，即为0到5v的值，这里可以转换一下
    huoer0=(val2-2.5)/0.066;

    int value3=0;            //定义值为0，也可以在程序一开始定义
    float huoer1=0;
    value3=analogRead(A3);  //使模拟信号输入的值为value
    float val3=value3*(5.0/1023.0);   //由于模拟信号输入的值为0到1023的值，即为0到5v的值，这里可以转换一下
    huoer1=(val3-2.5)/0.066;
   
    buttonState0 = digitalRead(KEY0);// read the state of the pushbutton value:
    buttonState1 = digitalRead(KEY1);
    buttonState2 = digitalRead(KEY2);
 
    if (buttonState2 == LOW) // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
    {
        digitalWrite(RES0,HIGH);
        digitalWrite(RES1,HIGH);
        digitalWrite(RES2,HIGH);
        digitalWrite(RES3,HIGH);
    }
    else if(buttonState1 == LOW)
    {
        digitalWrite(RES0, LOW);
        digitalWrite(RES1,HIGH);
        digitalWrite(RES2, HIGH);
        digitalWrite(RES3,HIGH);
    }
    else if(buttonState0==LOW )
    {
        digitalWrite(RES0,LOW);
        digitalWrite(RES1,LOW);
        digitalWrite(RES2,LOW);
        digitalWrite(RES3,LOW);
    }
  }while(u8g.nextPage());

  // rebuild the picture after some delay
  //delay(50);
}

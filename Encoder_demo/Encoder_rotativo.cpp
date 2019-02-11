#include "Encoder_rotativo.h"
Encoder_rotativo::Encoder_rotativo(byte dt, byte clk, byte sw)
{
  pin_clk=clk;
  pin_dt=dt;
  pin_sw=sw;
  pinMode(pin_clk, INPUT);
  pinMode(pin_dt, INPUT);
  pinMode(pin_sw, INPUT);
}
Encoder_rotativo::Encoder_rotativo(byte dt, byte clk)
{
  pin_clk=clk;
  pin_dt=dt;
  pinMode(pin_clk, INPUT);
  pinMode(pin_dt, INPUT);
}
Encoder_rotativo::~Encoder_rotativo()
{

}
void Encoder_rotativo::init()
{
  
  aLastState = digitalRead(pin_clk);   
}
int Encoder_rotativo::read_data()
{
  int counter = 0; 
  aState = digitalRead(pin_clk); // Reads the "current" state of the outputA
  // If the previous and the current state of the outputA are different, that means a Pulse has occured
  if (aState != aLastState)
  {     
    // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
    if (digitalRead(pin_dt) != aState) 
    { 
      counter --;
    } else 
    {
      counter ++;
    }   
  } 
  aLastState = aState;
  return counter;
}
bool Encoder_rotativo::read_sw()
{
  return !digitalRead(pin_sw);
}

#include <arduino.h>
class Encoder_rotativo
{
private:
  /* data */
  byte pin_clk;
  byte pin_dt;
  byte pin_sw;
  int aState;
  int aLastState; 
  
public:
void init();
bool read_sw();
int read_data();
  Encoder_rotativo(byte dt, byte clk, byte sw);
  Encoder_rotativo(byte dt, byte clk);
  ~Encoder_rotativo();
};
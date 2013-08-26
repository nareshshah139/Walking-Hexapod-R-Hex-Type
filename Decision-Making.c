#include <Rhex.h>
void setup()
{
}
int received_value = 0;
void loop()
{
  switch(received_value)
  {
    case '0':
    {
      Rhex.forward(1);
    }
    case '1':
    {
      Rhex.left(1);
    }
    case '2':
    {
      Rhex.right(1);
    }
    case '3':
    {
      Rhex.backward(1);
    }
  }
}

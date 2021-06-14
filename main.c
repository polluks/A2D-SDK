#include "loader.h"

const int h = 9;

int j;
char x = 9;

void main_da()
{
  struct OpenWindow ow;
  ow.x = 0x12;
  ow.y = 0x23;
  ow.z = 0x34;
  call_mgtk(0x89, &ow);
}

char g = 't';

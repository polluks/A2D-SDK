#include "loader.h"

#include <string.h>


void main_da()
{
  const char title[] = "\x05Title";
  unsigned char a;
  struct Command38 param = {};
  memset(&param, 0, sizeof(param));

  // copied from calculator.s

  param.winfo.window_id = 59;
  param.winfo.options = MGTK_Option_go_away_box;
  param.winfo.title = title;
  param.winfo.hscroll = MGTK_Scroll_option_none;
  param.winfo.vscroll = MGTK_Scroll_option_none;
  param.winfo.mincontwidth = 130;
  param.winfo.mincontheight = 96;
  param.winfo.maxcontwidth = 130;
  param.winfo.maxcontheight = 96;
  param.winfo.grafport.mapinfo.viewloc.xcoord = 210;
  param.winfo.grafport.mapinfo.viewloc.ycoord = 60;
  param.winfo.grafport.mapinfo.mapbits = (void *)(MGTK_screen_mapbits);
  param.winfo.grafport.mapinfo.mapwidth = MGTK_screen_mapwidth;
  param.winfo.grafport.colormask_and = MGTK_colormask_and;
  param.winfo.grafport.colormask_or = MGTK_colormask_or;
  param.winfo.grafport.penwidth = 1;
  param.winfo.grafport.penheight = 1;
  param.winfo.grafport.textback = 0x7f;
  param.winfo.grafport.textfont = (void*)(MGTK_DEFAULT_FONT);

  a = call_mgtk(MGTK_OpenWindow, &param);
}

unsigned char __fastcall__ call_mgtk(unsigned char code, void * params);

#define MGTK_OpenWindow         0x38
#define MGTK_closeWindow        0x39

#define MGTK_Option_dialog_box     1
#define MGTK_Option_go_away_box    2
#define MGTK_Option_grow_box       4

#define MGTK_Scroll_option_none    0

#define MGTK_screen_mapbits   0x2000
#define MGTK_screen_mapwidth    0x80

#define MGTK_colormask_and      0xFF
#define MGTK_colormask_or       0x00
#define MGTK_textbg_black       0x00
#define MGTK_textbg_white       0x7F

#define MGTK_DEFAULT_FONT          0x8800

struct OpenWindow
{
  unsigned char x;
  unsigned char y;
  unsigned char z;
};

struct Point
{
  unsigned int xcoord;
  unsigned int ycoord;
};

struct Rect
{
  struct Point topleft;
  struct Point bottomright;
};

struct MapInfo
{
  struct Point viewloc;
  void * mapbits;
  unsigned char mapwidth;
  unsigned char reserved[1];
  struct Rect maprect;
};

struct Pattern
{
  unsigned char rows[8];
};

struct GrafPort
{
  struct MapInfo mapinfo;
  struct Pattern penpattern;
  unsigned char colormask_and;
  unsigned char colormask_or;
  struct Point penloc;
  unsigned char penwidth;
  unsigned char penheight;
  unsigned char penmode;
  unsigned char textback;
  void * textfont;
};

struct WInfo
{
  unsigned char window_id; //         .byte ; 0
  unsigned char options;   //         .byte ; 1 Option::*
  const char * title; //     .addr ; 2
  unsigned char hscroll; //           .byte ; 4 Scroll::option_*
  unsigned char vscroll; //           .byte ; 5 Scroll::option_*
  unsigned char hthumbmax; //         .byte ; 6
  unsigned char hthumbpos; //         .byte ; 7
  unsigned char vthumbmax; //         .byte ; 8
  unsigned char vthumbpos; //         .byte ; 9
  unsigned char status; //            .byte ; 10
  unsigned char reserved; //          .byte ; 11
  unsigned int mincontwidth; //       .word ; 12 minimum content size (horizontal)
  unsigned int mincontheight; //      .word ; 14 minimum content size (vertical)
  unsigned int maxcontwidth; //       .word ; 16 maximum content size (horizontal)
  unsigned int maxcontheight; //      .word ; 18 maximum content size (vertical)
  struct GrafPort grafport; //        .tag  ; 20
  struct WInfo * nextwinfo; //        .addr ; 54 address of next lower window in stack
};

struct Command38
{
  struct WInfo winfo;
};

struct Command39
{
  unsigned char window_id;
};

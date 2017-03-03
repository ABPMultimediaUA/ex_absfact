#ifndef __STDPIJO_H_
#define __STDPIJO_H_
// Version beta de StdPijo.h en C++
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <sstream>
#include <ncurses.h>

using namespace std;

// Definiciones de Colores
//----------------------------------
#define STDP_C_NEGRO    COLOR_BLACK
#define STDP_C_ROJO     COLOR_RED
#define STDP_C_VERDE    COLOR_GREEN
#define STDP_C_AMARILLO COLOR_YELLOW
#define STDP_C_AZUL     COLOR_BLUE
#define STDP_C_MAGENTA  COLOR_MAGENTA
#define STDP_C_CIAN     COLOR_CYAN
#define STDP_C_BLANCO   COLOR_WHITE

// Definiciones de atributos
//-----------------------------------
#define STDP_A_NORMAL	A_NORMAL
#define STDP_A_INVERSO	A_REVERSE
#define STDP_A_PARPADEO	A_BLINK
#define STDP_A_NEGRITA	A_BOLD

// Definiciones de teclas
//-----------------------------------
#define STDP_T_ESCAPE	       27
#define STDP_T_ENTER           13
#define STDP_T_CURSOR_ARRIBA   KEY_UP
#define STDP_T_CURSOR_ABAJO    KEY_DOWN

class STDP {
public:
   class stdpostream {
   public:
      stdpostream() {};

      template<typename T>
      stdpostream& operator<<(const T& ui) {
         std::stringstream ss;
         ss << ui;
         EscribeStr(ss.str().c_str());
         return *this;
      }
   };

   static stdpostream sout;

    STDP ();
    ~STDP ();
    static void Inicializar ();
    static void Terminar ();

    // Primitivas graficas
    static bool EsAtributo (const int att);
    static bool EsColor (const int col);
    static void PonCursor (int x, int y);
    static void CambiaColor (int ATR, int CT, int CF);
    static void BorraPantalla ();
    static void Refrescar ();
    static void EscribeCh  (chtype c);
    static void EscribeStr (const char *str);
    static void DibujaLineaHorizontal (int minX, int maxX, int Y, chtype ch);
    static void DibujaLineaVertical   (int minY, int maxY, int X, chtype ch);
    static void DibujaMarco    (int minX, int minY, int maxX,
                                int maxY, chtype ch);
    static void DibujaCuadrado (int minX, int minY, int maxX,
    				int maxY, chtype ch);
    static int  CursorX ();
    static int  CursorY ();
    static int  TamX();
    static int  TamY();

    // Primitivas de teclado
    static int  ObtenTecla();

private:
    static int cursorX, cursorY; // Posicion del cursor en pantalla
    static int tamX, tamY;       // Tamanyo de la pantalla
    static int color[8][8];	 // Vector de colores

    static void ValidaCursor();  // Corrige la posicion del cursor
};
#endif

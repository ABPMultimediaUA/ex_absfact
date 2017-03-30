///////////////////////////////////////////////////////////////////////////////
//     This is part of StdPijo, a simplified textmode colored drawing library.
//     StdPijo is a simplified abstraction layer over ncurses.
//
//    Copyright (C) 2017   Francisco J. Gallego-Durán
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
///////////////////////////////////////////////////////////////////////////////
// Codigo de las StdPijo C++ Beta
#include "StdPijo.h"

int STDP::cursorX;
int STDP::cursorY;
int STDP::tamX;
int STDP::tamY;
int STDP::color[8][8];
STDP::stdpostream STDP::sout;

// Constructorcillo...
STDP::STDP ()
{ /* Nada que hacer */ }

// Destructorcete...
STDP::~STDP ()
{ /* Nada que hacer */ }

// Pa inicializar la pantalla...
void
STDP::Inicializar ()
{
   // Preinicializacion de N-Curses
   initscr();              // Inicializar N-curses 
   keypad(stdscr, TRUE);   // Mapeo de teclado
   nodelay(stdscr,TRUE);   // Lectura no bloqueante
   notimeout(stdscr,FALSE);
   timeout (0);	           // Para que no se espere en la lectura...
   nonl();                 // NL no es CR/NL a la salida
   cbreak();               // Disponibilidad inmediata de teclas pulsadas
   noecho();               // Eliminamos el echo al terminal
   curs_set(0);            // Cursor invisible
   leaveok(stdscr,TRUE);   // Cursor siempre en 0,0 tras refresh()
   scrollok(stdscr,FALSE); // No hacer scroll vertical automatico
   if (has_colors())
      start_color();       // Inicializa los colores
   refresh();              // Borramos la pantalla

   // Colocamos el cursor arriba y establecemos los parametros
   move(0,0);
   cursorX = 0; cursorY = 0; 
   getmaxyx (stdscr, tamY, tamX);

   // Inicializamos los pares de colores
   int p = 0;
   int c [8] = { COLOR_BLACK, COLOR_RED, COLOR_GREEN, COLOR_YELLOW,
                 COLOR_BLUE, COLOR_MAGENTA, COLOR_CYAN, COLOR_WHITE };
   for (int i=0; i<8; i++)
   {
      for (int j=0; j<8; j++)
      {
         color[i][j] = p;
         init_pair(p++, c[i], c[j]);
      }
   }
}

// Esto nos servira pa terminar en condisiones...
void
STDP::Terminar() { endwin(); }

// Pa poner el cursor por ahi...
void
STDP::PonCursor (int x, int y)
{
   if (x >= 0 && x < tamX && y >= 0 && y < tamY)
   {
      move (y, x);
      cursorX = x;
      cursorY = y;
   }
}

// Pa poner colorines pijos...
void
STDP::CambiaColor (int Atr, int CT, int CF)
{
   // Establecemos color para borrar atributos y luego el atr q toca
   if (EsColor(CT) && EsColor(CF))  attrset(COLOR_PAIR(color[CT][CF]));
   if            (EsAtributo(Atr))  attron (Atr);
}

// Pa borrarlo to....
void
STDP::BorraPantalla ()
{
/* move(0,0);
   CambiaColor (A_NORMAL, COLOR_WHITE, COLOR_BLACK);
   for (int i=0; i<tamY*tamX; i++)
      addch(' ');
   PonCursor (0,0);
*/
   erase();
}

// Dibujar una linea horizontaaaaaaaaaaaAAaaaAallll xDDD...
void
STDP::DibujaLineaHorizontal (int minX, int maxX, int Y, chtype ch)
{
   // Pintamos...
   PonCursor (minX, Y);
   for (int i=0; i<maxX - minX + 1; i++)
      addch(ch);

   // Y ponemos el cursor al final...
   cursorX = maxX + 1; cursorY = Y;
   ValidaCursor();
}

// Dibujar una linea vertical
void
STDP::DibujaLineaVertical (int minY, int maxY, int X, chtype ch)
{
   // Pintamos...
   for (int i=minY; i<=maxY; i++)
   {
      PonCursor (X, i);
      addch(ch);
   }
}

// Dibujar un cuadradito relleno de colo :-D...
void
STDP::DibujaCuadrado (int minX, int minY, int maxX, int maxY, chtype ch)
{
    for (int i=minY; i<=maxY; i++)
       DibujaLineaHorizontal (minX, maxX, i, ch);
}

void 
STDP::DibujaMarco (int minX, int minY, int maxX, int maxY, chtype ch)
{
    DibujaLineaHorizontal (minX, maxX, minY, ch);
    DibujaLineaHorizontal (minX, maxX, maxY, ch);
    DibujaLineaVertical   (minY+1, maxY-1, minX, ch);
    DibujaLineaVertical   (minY+1, maxY-1, maxX, ch);
}

// Escribir un caracter en pantalla...
void
STDP::EscribeCh (chtype c)
{
   addch (c);
   cursorX++;
   ValidaCursor();
}

// Escribir una cadena......
void
STDP::EscribeStr (const char *str)
{
   addstr (str);
   cursorX+=strlen(str);
   if (cursorX >= tamX) { cursorY += cursorX / tamX; cursorX %= tamX; }
   ValidaCursor();
}

// Corrige la posicion del cursor si este se encuentra
// fuera de los limites de la pantalla
void
STDP::ValidaCursor ()
{
   if (cursorX >= tamX) 
   {
      if (cursorY < tamY-1) { cursorX = 0; cursorY++; }
                       else { cursorX = tamX - 1; cursorY = tamY - 1; }
   }
}

// Comprueba si el entero representa un posible atributo simple...
bool
STDP::EsAtributo (const int att)
{
   switch(att)
   {
      case STDP_A_NORMAL:
      case STDP_A_INVERSO:
      case STDP_A_NEGRITA:
      case STDP_A_PARPADEO:
         return true;
         break;
   }
   return false;
}

// Comprueba su el entero representa un color valido...
bool
STDP::EsColor (const int col)
{
   if (col >= 0 && col < 8) return true;
   return false;
}

// Volcado a video de la pantalla...
void
STDP::Refrescar() { refresh(); }

// Devolver la posicion horizontal del cursor...
int
STDP::CursorX () { return cursorX; }

// Devolver la posicion vertical del cursor...
int
STDP::CursorY () { return cursorY; }

// Devolver tamanyo horizontal de la pantalla
int
STDP::TamX () { return tamX; }

// Devolver tamanyo vertical de la pantalla
int
STDP::TamY () { return tamY; }

// Obtener tecla
int
STDP::ObtenTecla() { return getch(); }

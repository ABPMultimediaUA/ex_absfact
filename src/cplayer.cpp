///////////////////////////////////////////////////////////////////////////////
//     This is part of ex_absfact, an example on how to implement an Abstract
//     Factory pattern. It is a simple textmode game that has two game modes: 
//     Easy and Hard. The Abstract Factory decouples maze creation from the
//     GameObjects required depending on the Game Mode. 
//     This example was used during Videogame Programming lessons at the 
//     Multimedia Degree from the University of Alicante (Spain). You may
//     watch the associated lesson at https://youtu.be/FFM9cQ2bwA0.
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
#include <cplayer.h>
#include <StdPijo.h>
#include <ckeyboardman.h>

CPlayer::CPlayer() {
   m_KeyMan = &CKeyboardMan::p();
}

void CPlayer::update() {
   // Move the player on keypresses
   switch (m_KeyMan->getLastKeyPressed()) {
      case 'a': setNextMovement(-1,  0); break;
      case 'w': setNextMovement( 0, -1); break;
      case 's': setNextMovement( 0,  1); break;
      case 'd': setNextMovement( 1,  0); break;
      default: break;
   }
}

void CPlayer::draw() {
   STDP::CambiaColor(STDP_A_NEGRITA, STDP_C_AMARILLO, STDP_C_NEGRO);  
   STDP::PonCursor(m_x, m_y);
   STDP::sout << "P";
}

CPlayer::~CPlayer() {
}

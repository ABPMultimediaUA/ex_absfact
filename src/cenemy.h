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
#ifndef __CENEMY_H__
#define __CENEMY_H__

#include <cgameobject.h>

class CEnemy : public CGameObject {
public:
   virtual void update()   = 0;
   virtual void draw()     = 0;

   virtual bool isPlayer() const override { return false; };
   virtual bool isMortal() const override { return true;  };
private:

};

#endif
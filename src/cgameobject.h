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
#ifndef __CGAMEOBJECT_H__
#define __CGAMEOBJECT_H__

#include <cstdint>
#include <string>

class CGameObject {
public:
   virtual void setLocation(uint8_t x, uint8_t y);
   virtual void setNextMovement(int8_t dx, int8_t dy);

   virtual void update() = 0;
   virtual void draw()   = 0;
   
   virtual bool isPlayer() const = 0;
   virtual bool isMortal() const = 0;

   uint8_t getX()        const { return m_x;  }
   uint8_t getY()        const { return m_y;  }
   uint8_t getNextX()    const { return m_nx; }
   uint8_t getNextY()    const { return m_ny; }
   bool    wantsToMove() const { return m_wantToMove; }
protected:
   uint8_t  m_x,  m_y;   //< Coordinates
   bool  m_wantToMove;   //< Flag to know whether the entity wants to move
   int8_t  m_nx, m_ny;   //< Desired movement
};

#endif
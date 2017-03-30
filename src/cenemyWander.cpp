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
#include <cenemyWander.h>
#include <StdPijo.h>
#include <cstdlib>
#include <algorithm>

CEnemyWander::CEnemyWander() {
   initMovementVector();
}

void CEnemyWander::initMovementVector() {
   // Initialize directions vector
   m_dirs[0] = { 1, 0, static_cast<uint8_t>(1 + rand() % 10) };
   m_dirs[1] = { 0, 1, static_cast<uint8_t>(1 + rand() % 10) };
   m_dirs[2] = {-1, 0, static_cast<uint8_t>(1 + rand() % 10) };
   m_dirs[3] = { 0,-1, static_cast<uint8_t>(1 + rand() % 10) };
   std::random_shuffle(m_dirs + 0, m_dirs + 4);

   // Start from direction 0
   m_di = 0;
}

void CEnemyWander::update() {
   if (!currentDirectionStepsLeft())
      changeDirection();

   moveOneStepInCurrentDirection();
}

void CEnemyWander::draw() {
   STDP::CambiaColor(STDP_A_NEGRITA, STDP_C_MAGENTA, STDP_C_NEGRO);  
   STDP::PonCursor(m_x, m_y);
   STDP::sout << "W";
}

CEnemyWander::~CEnemyWander() {
}

void CEnemyWander::moveOneStepInCurrentDirection() {
   // Do next movement
   TMoveDir& move = m_dirs[m_di]; 
   setNextMovement(move.dx, move.dy);

   // Count one step more
   ++m_step;   
}

uint8_t CEnemyWander::currentDirectionStepsLeft() {
   return m_dirs[m_di].step - m_step;
}

void CEnemyWander::changeDirection() {
   // Pickup Next direction and reset steps
   ++m_di;
   m_step = 0;

   // If all directions have been picked up
   // Initialize movement Movement Direction again
   if (m_di > 3)
      initMovementVector();
}

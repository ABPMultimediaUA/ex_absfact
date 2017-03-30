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
#include <cgame.h>
#include <ckeyboardman.h>
#include <cscene.h>
#include <StdPijo.h>
#include <unistd.h>
#include <cmazefactEasy.h>

CGame::CGame() {
   STDP::Inicializar();
   STDP::BorraPantalla();

   // Get KeyboardManager Reference and clear Buffer
   m_KeyMan = &CKeyboardMan::p();
   m_KeyMan->clear();

   // Create scene
   m_scene = new CScene();
   CMazeFactEasy f;
   m_scene->initialize(f);
}

void CGame::update() {
   // Update keyboard and scene
   m_KeyMan->update();
   m_scene->update();
}

void CGame::timeWait() {
   static long   t = clock();
   const float fps = 30.0f;

   long toWait = t + CLOCKS_PER_SEC / fps - clock();
   if (toWait > 0)
      usleep(toWait);

   t = clock();
}

void CGame::run() {
   // Run the game until Q is pressed
   do {
      update();
      draw();
      timeWait();
   } while(    m_KeyMan->getLastKeyPressed() != 'q' 
            && m_scene->thereIsAPlayer() );
}

void CGame::draw() {
   // Redraw the screen
   STDP::BorraPantalla(); 
   m_scene->draw();
   STDP::Refrescar();
}

CGame::~CGame() {
   // End the game
   STDP::CambiaColor(STDP_A_NEGRITA, STDP_C_BLANCO, STDP_C_ROJO);
   STDP::PonCursor(2, 6);
   STDP::sout << "GAME  OVER";
   
   // Remove the scene
   delete m_scene;
   
   // Clear screen
   STDP::Refrescar();
   sleep(2);
   STDP::Terminar();
}

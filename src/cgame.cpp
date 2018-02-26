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
#include <crenderer.h>
#include <crendererobj.h>
#include <crendererman.h>
#include <cscene.h>
#include <cmazefactEasy.h>
#include <chrono>
#include <thread>

// Simplify calls to renderer using a lambda expression
const auto& RENDERER = []()->CRenderer& { CRendererMan::p().renderer(); };

CGame::CGame() {
   CRendererMan::p();   // Initialize renderer

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
   using clk = std::chrono::high_resolution_clock;
   using namespace std::chrono_literals;

   constexpr auto fps = 30.0f;
   constexpr auto spf   = 1.0s / fps;
   static auto t = clk::now();

   auto passed = clk::now() - t;
   if (passed < spf)
      std::this_thread::sleep_for(spf - passed);

   t = clk::now();
}

void CGame::run() {
   // Run the game until Q is pressed
   do {
      update();
      draw();
      timeWait();
      if (m_KeyMan->getLastKeyPressed() == 'n') m_scene->changeRenderer();
   } while(    m_KeyMan->getLastKeyPressed() != 'q' 
            && m_scene->thereIsAPlayer() );
}

void CGame::draw() {
   // Redraw the screen
   RENDERER().clearScreen();
   m_scene->draw();
   RENDERER().refresh();
}

CGame::~CGame() {
   // End the game
   CRendererObj* str = RENDERER().createString("GAME OVER");
   str->setPosition(2, 6);
   str->draw();
   
   // Remove the scene
   delete m_scene;
   delete str;
   
   // Clear screen
   RENDERER().refresh();
   std::this_thread::sleep_for(std::chrono::seconds(2));
}

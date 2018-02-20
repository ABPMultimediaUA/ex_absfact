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
#include <cscene.h>
#include <cenemy.h>
#include <cwall.h>
#include <cplayer.h>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <cmazefact.h>

CScene::CScene() {
   // Null Object Matrix
   for(uint8_t i = 0; i < 13; ++i) {
      for(uint8_t j = 0; j < 13; ++j) {
         m_objMatrix[i][j] = nullptr;
      }
   }
}

void CScene::initialize(CMazeFact &f) {
   // Create and add gameobjects
   for(uint8_t i = 2; i < 12; ++i) {
      CWall *wt = f.createWall( i,  1);
      CWall *wd = f.createWall( i, 12);
      CWall *wl = f.createWall( 1,  i);
      CWall *wr = f.createWall(12,  i);
      addGameObject(wt,  i,  1);
      addGameObject(wd,  i, 12);
      addGameObject(wl,  1,  i);
      addGameObject(wr, 12,  i);
   }
   CEnemy *e1 = f.createEnemy(3, 3);
   CEnemy *e2 = f.createEnemy(5, 6);
   CPlayer *p = f.createPlayer(2, 2);
   addGameObject(e1, 3, 3);
   addGameObject(e2, 5, 6);
   addGameObject(p, 2, 2);
   m_thereIsAPlayer = true;
}

void CScene::addGameObject(CGameObject* o, uint8_t x, uint8_t y) {
   // Check for exceptions
   if (x > 12 || y > 12) {
      throw std::out_of_range(
         static_cast<std::string>("Out of scene matrix (")
            + std::to_string(x) + "," 
            + std::to_string(y) + ")");
   } else if (m_objMatrix[x][y] != nullptr) {
      throw std::logic_error(
         static_cast<std::string>("Duplicated object at (") 
            + std::to_string(x) + "," 
            + std::to_string(y) + ")");
   }

   // Add a gameObject to the scene
   m_objMatrix[x][y] = o;
   o->setLocation(x, y);
   m_gameObjects.push_back(o);
}

void CScene::update() {
   // Update gameobjects
   // Beware! Use a normal iteration because 
   // m_gameObjects gets modified when an object is deleted
   size_t s = m_gameObjects.size();
   for (size_t i=0; i < s; i++) {
      CGameObject *g = m_gameObjects[i];
      g->update();
      moveGameObject(g);
      // Check if game object has been removed
      // then go back 1 item (next item its at index i, not i+1)
      if (m_gameObjects.size() != s) {
         s = m_gameObjects.size();
         --i;
      }
   }
}

void CScene::draw() {  
   // Draw all game objects
   for(CGameObject* g : m_gameObjects) {
      g->draw();
   }
}

CScene::~CScene() {  
   // Remove Game Objects
   for(CGameObject* g : m_gameObjects) {
      delete g;
   }
   m_gameObjects.clear();
}

void CScene::removeGameObject(CGameObject *g) {
   // Find and remove it from the gameObject vector
   TObjVec::iterator it;
   it = std::find(m_gameObjects.begin(), m_gameObjects.end(), g);
   if ( it == m_gameObjects.end() )
      throw std::logic_error("Not found while removing object");  
   m_gameObjects.erase(it);

   // Remove it from the Collision Matrix
   uint32_t x = g->getX();
   uint32_t y = g->getY();
   if ( m_objMatrix[x][y] != g )
      throw std::logic_error("Not located in the Object Matrix");
   m_objMatrix[x][y] = nullptr;

   // If it was a player, note it
   if (g->isPlayer())
      m_thereIsAPlayer = false;

   // Then delete it
   delete g;
}

void CScene::moveGameObject(CGameObject *g) {
   // Only if object wants to move
   if (g->wantsToMove()) {
      uint8_t x  = g->getX();
      uint8_t y  = g->getY();
      uint8_t nx = g->getNextX();
      uint8_t ny = g->getNextY();
      
      // Check for collisions
      CGameObject *gdest = m_objMatrix[nx][ny];
      if (gdest == nullptr) {
         // Move because destiny place is empty
         m_objMatrix[x][y]   = nullptr;
         m_objMatrix[nx][ny] = g;
      } else if ( g->isPlayer() && gdest->isMortal() ) {
         // Destiny is taken by a mortal entity and I'm a player: then Die

         removeGameObject(g);
         return;              // Safely return
      } else if ( g->isMortal() && gdest->isPlayer() ) {
         // Destiny is the player and I'm a mortal object: kill player
         removeGameObject(gdest);
         return;              // Safely return         
      } else {
         // Cannot move to a non-empty place
         nx = x; ny = y;
      }
      // Make the movement effective
      g->setLocation(nx, ny);
   }
}


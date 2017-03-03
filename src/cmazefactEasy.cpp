#include <cmazefactEasy.h>
#include <cenemyLR.h>
#include <cwallNormal.h>
#include <cplayer.h>

CMazeFactEasy::CMazeFactEasy() {
}

CEnemy *CMazeFactEasy::createEnemy (uint8_t x, uint8_t y) const{
   CEnemyLR* e = new CEnemyLR();
   e->setLocation(x, y);
   return e;
}

CPlayer *CMazeFactEasy::createPlayer (uint8_t x, uint8_t y) const{
   CPlayer* p = new CPlayer();
   p->setLocation(x, y);
   return p;
}

CWall *CMazeFactEasy::createWall (uint8_t x, uint8_t y) const{
   CWallNormal* w = new CWallNormal();
   w->setLocation(x, y);
   return w;
}
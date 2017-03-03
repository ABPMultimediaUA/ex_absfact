#include <cmazefactHard.h>
#include <cenemyWander.h>
#include <cwallMortal.h>
#include <cplayer.h>

CMazeFactHard::CMazeFactHard() {
}

CEnemy *CMazeFactHard::createEnemy (uint8_t x, uint8_t y) const{
   CEnemyWander* e = new CEnemyWander();
   e->setLocation(x, y);
   return e;
}

CPlayer *CMazeFactHard::createPlayer (uint8_t x, uint8_t y) const{
   CPlayer* p = new CPlayer();
   p->setLocation(x, y);
   return p;
}

CWall *CMazeFactHard::createWall (uint8_t x, uint8_t y) const{
   CWallMortal* w = new CWallMortal();
   w->setLocation(x, y);
   return w;
}
#ifndef __CWALL_H__
#define __CWALL_H__

#include <cgameobject.h>

class CWall : public CGameObject {
public:
   virtual void update()   = 0;
   virtual void draw()     = 0;

   virtual bool isPlayer() const override { return false; }
   virtual bool isMortal() const override { return false; }
private:
};

#endif
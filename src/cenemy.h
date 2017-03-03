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
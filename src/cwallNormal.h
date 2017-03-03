#ifndef __CWALLNORMAL_H__
#define __CWALLNORMAL_H__

#include <cwall.h>

class CWallNormal : public CWall {
public:
   CWallNormal();
   virtual ~CWallNormal();
   virtual void update() override;
   virtual void draw()   override;

   virtual bool isPlayer() const override { return false; };
   virtual bool isMortal() const override { return false; };
private:
};

#endif
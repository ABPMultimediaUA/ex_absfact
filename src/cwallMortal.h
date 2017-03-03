#ifndef __CWALLMORTAL_H__
#define __CWALLMORTAL_H__

#include <cwall.h>

class CWallMortal : public CWall {
public:
   CWallMortal();
   virtual ~CWallMortal();
   virtual void update() override;
   virtual void draw()   override;

   virtual bool isPlayer() const override { return false; };
   virtual bool isMortal() const override { return true; };
private:
};

#endif
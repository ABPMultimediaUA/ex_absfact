#ifndef __CENEMYLR_H__
#define __CENEMYLR_H__

#include <cenemy.h>

class CEnemyLR : public CEnemy {
public:
   CEnemyLR();
   virtual ~CEnemyLR();
   virtual void update() override;
   virtual void draw()   override;

   virtual bool isPlayer() const override { return false; };
   virtual bool isMortal() const override { return true;  };
private:
   int8_t   m_dir;   // Movement Direction
};

#endif
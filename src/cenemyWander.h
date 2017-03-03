#ifndef __CEnemyWander_H__
#define __CEnemyWander_H__

#include <cenemy.h>

class CEnemyWander : public CEnemy {
public:
   struct TMoveDir {
         int8_t dx, dy, step;
   };

   CEnemyWander();
   virtual ~CEnemyWander();
   virtual void update() override;
   virtual void draw()   override;

   virtual bool isPlayer() const override { return false; };
   virtual bool isMortal() const override { return true;  };
private:
   uint8_t   m_di;        // Direction index
   uint8_t   m_step;      // Step number
   TMoveDir  m_dirs[4];   // Direction vector

   void initMovementVector();
};

#endif
#ifndef __CPLAYER_H__
#define __CPLAYER_H__

#include <cgameobject.h>

class CKeyboardMan;

class CPlayer : public CGameObject {
public:
   CPlayer();
   virtual ~CPlayer();

   virtual void update() override;
   virtual void draw()   override;
   
   virtual bool isPlayer() const override { return true;  };
   virtual bool isMortal() const override { return false; };

   void move(int8_t dx, int8_t dy);
private:
   CKeyboardMan* m_KeyMan;

   uint8_t move_one_axis_with_limits(uint8_t p, int8_t d, uint8_t min, uint8_t max);
};

#endif
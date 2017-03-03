#ifndef __CGAMEOBJECT_H__
#define __CGAMEOBJECT_H__

#include <cstdint>
#include <string>

class CGameObject {
public:
   virtual void setLocation(uint8_t x, uint8_t y);
   virtual void setNextMovement(int8_t dx, int8_t dy);

   virtual void update() = 0;
   virtual void draw()   = 0;
   
   virtual bool isPlayer() const = 0;
   virtual bool isMortal() const = 0;

   uint8_t getX()        const { return m_x;  }
   uint8_t getY()        const { return m_y;  }
   uint8_t getNextX()    const { return m_nx; }
   uint8_t getNextY()    const { return m_ny; }
   bool    wantsToMove() const { return m_wantToMove; }
protected:
   uint8_t  m_x,  m_y;   //< Coordinates
   bool  m_wantToMove;   //< Flag to know whether the entity wants to move
   int8_t  m_nx, m_ny;   //< Desired movement
};

#endif
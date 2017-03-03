#ifndef __CMAZEFACT_H__
#define __CMAZEFACT_H__

#include <cstdint>

class CEnemy;
class CPlayer;
class CWall;

class CMazeFact {
public:
   virtual CEnemy  *createEnemy (uint8_t x, uint8_t y) const = 0;
   virtual CWall   *createWall  (uint8_t x, uint8_t y) const = 0;
   virtual CPlayer *createPlayer(uint8_t x, uint8_t y) const = 0;
};

#endif
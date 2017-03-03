#ifndef __CMAZEFACTEASY_H__
#define __CMAZEFACTEASY_H__

#include <cmazefact.h>

class CMazeFactHard : public CMazeFact {
public:   
   CMazeFactHard();
   virtual CEnemy  *createEnemy (uint8_t x, uint8_t y) const override;
   virtual CWall   *createWall  (uint8_t x, uint8_t y) const override;
   virtual CPlayer *createPlayer(uint8_t x, uint8_t y) const override;
protected:
};

#endif
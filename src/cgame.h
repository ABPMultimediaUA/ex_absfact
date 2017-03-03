#ifndef __CGAME_H__
#define __CGAME_H__

#include <vector>

class CGameObject;
class CKeyboardMan;
class CScene;

class CGame {
public:
   CGame();
   ~CGame();

   void  run();
   void  draw();
   void  update();
private:
   CKeyboardMan*  m_KeyMan;
   CScene*        m_scene;

   void  timeWait();
};

#endif
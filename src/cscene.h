#ifndef __CSCENE_H__
#define __CSCENE_H__

#include <vector>
#include <cgameobject.h>

class CMazeFact;

class CScene : public CGameObject {
public:
   typedef std::vector<CGameObject*> TObjVec;

   CScene();
   ~CScene();

   virtual void  draw()    override;
   virtual void  update()  override;

   void initialize(CMazeFact &f);
   void addGameObject   (CGameObject* o, uint8_t x, uint8_t y);
   void removeGameObject(CGameObject* o);
   void moveGameObject  (CGameObject *g);

   bool thereIsAPlayer() const { return m_thereIsAPlayer; }
   bool isPlayer()       const override { return false; }
   bool isMortal()       const override { return false; }
private:
   TObjVec        m_gameObjects;
   CGameObject*   m_objMatrix[13][13];
   bool           m_thereIsAPlayer;
};

#endif
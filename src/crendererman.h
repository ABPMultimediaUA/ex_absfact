#ifndef __CRENDERERMANAGER_H__
#define __CRENDERERMANAGER_H__

#include <vector>
#include <crendererobj.h>

class CRenderer;
class CRendererObjSTDP;
enum class CRendererType { STDP, STDP2, SFML };
using TVecRenderObjs = std::vector<CRendererObj*>;

class CRendererMan {
public:
   ~CRendererMan();

   static CRendererMan& p();
   CRenderer& renderer();
   void changeToRenderer(CRendererType t, TVecRenderObjs& robjs);
   void switchToSFML(TVecRenderObjs& robjs);

   template<class TRenderer, class TRenderTo>
   void switchRenderer(TVecRenderObjs& robjs) {
        delete m_renderer;
        m_renderer = new TRenderer();
        for(auto* o : robjs)
            o->setImplementation( new TRenderTo( *dynamic_cast<CRendererObjSTDP*>(o->getImplementation()) ) );
   }
private:
   CRendererMan();

   CRenderer* m_renderer = nullptr;
};

#endif
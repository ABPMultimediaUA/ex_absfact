#ifndef __CRENDERERMANAGER_H__
#define __CRENDERERMANAGER_H__

#include <vector>

class CRenderer;
class CRendererObj;
enum class CRendererType { STDP, STDP2 };
using TVecRenderObjs = std::vector<CRendererObj*>;

class CRendererMan {
public:
   ~CRendererMan();

   static CRendererMan& p();
   CRenderer& renderer();
   void changeToRenderer(CRendererType t, TVecRenderObjs& robjs);

   template<class TRenderer, class TRendererObj>
   void switchRenderer(TVecRenderObjs& robjs) {
      delete m_renderer;
      m_renderer = new TRenderer();
      //for(auto* o : robjs)
      //   o = dynamic_cast<TRendererObj*>(o);
   }
private:
   CRendererMan();

   CRenderer* m_renderer = nullptr;
};

#endif
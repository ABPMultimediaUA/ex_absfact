#include <crendererman.h>
#include <crendererstdp.h>
#include <crendererobjstdp.h>
#include <crendererstdp2.h>
#include <crendererobjstdp2.h>

CRendererMan::CRendererMan() {
   m_renderer = new CRendererSTDP();
}

CRendererMan::~CRendererMan() {
   delete m_renderer;
}

CRendererMan&
CRendererMan::p() {
   static CRendererMan instance;

   return instance;
}

CRenderer& 
CRendererMan::renderer() { 
   return *m_renderer; 
}

void 
CRendererMan::changeToRenderer(CRendererType t, TVecRenderObjs& robjs) {
   switch (t) {
      case CRendererType::STDP:  switchRenderer<CRendererSTDP,  CRendererObjSTDP> (robjs); break;
      case CRendererType::STDP2: switchRenderer<CRendererSTDP2, CRendererObjSTDP2>(robjs); break;
   }
}
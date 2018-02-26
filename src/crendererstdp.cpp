#include <crendererstdp.h>
#include <istream>
#include <StdPijo.h>
#include <crendererobjstdp.h>

CRendererSTDP::CRendererSTDP() {
   STDP::Inicializar();
   STDP::BorraPantalla();   
}

CRendererSTDP::~CRendererSTDP() {  
   STDP::Refrescar();
   STDP::Terminar();
}

void 
CRendererSTDP::clearScreen() const { 
   STDP::BorraPantalla();
}
void 
CRendererSTDP::refresh() const {
   STDP::Refrescar();   
}

CRendererObj* 
CRendererSTDP::createSprite(const char* filename) const {
   std::ifstream ifile(m_filepath + filename);

   CRendererObjSTDP* robj = new CRendererObjSTDP();
   ifile >> *robj;

   return robj;
}

CRendererObj* 
CRendererSTDP::createString(const char* str) const {
   CRendererObjSTDP* robj = new CRendererObjSTDP();
   robj->setAppearance(str);

   return robj;
}

void
CRendererSTDP::setFilePath(const char* filepath) { 
   m_filepath = filepath;
}

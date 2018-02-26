#include <crendererobj.h>
#include <crendererstdp.h>
#include <crendererobjstdp.h>
#include <istream>

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

   return new CRendererObj(robj);
}

CRendererObj* 
CRendererSTDP::createString(const char* str) const {
   CRendererObjSTDP* robj = new CRendererObjSTDP();
   robj->setAppearance(str);

   return new CRendererObj(robj);
}

void
CRendererSTDP::setFilePath(const char* filepath) { 
   m_filepath = filepath;
}

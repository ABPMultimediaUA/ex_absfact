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

CRendererObjImpl* 
CRendererSTDP::createSpriteImpl(const char* filename) const {
   std::ifstream ifile(m_filepath + filename);

   CRendererObjSTDP* robj = new CRendererObjSTDP(filename);
   ifile >> *robj;

   return robj;
}

CRendererObjImpl* 
CRendererSTDP::createStringImpl(const char* str) const {
   CRendererObjSTDP* robj = new CRendererObjSTDP(str);
   robj->setAppearance(str);

   return robj;
}


CRendererObj* 
CRendererSTDP::createSprite(const char* filename) const {
   return new CRendererObj( createSpriteImpl(filename) );
}

CRendererObj* 
CRendererSTDP::createString(const char* str) const {
   return new CRendererObj( createStringImpl(str) );
}

void
CRendererSTDP::setFilePath(const char* filepath) { 
   m_filepath = filepath;
}

#include <crendererobj.h>
#include <crendererstdp2.h>
#include <crendererobjstdp2.h>
#include <fstream>

CRendererObjImpl* 
CRendererSTDP2::createSpriteImpl(const char* filename) const {
   std::ifstream ifile(m_filepath + filename);

   CRendererObjSTDP2* robj = new CRendererObjSTDP2(filename);
   ifile >> *robj;

   return robj;
}

CRendererObjImpl* 
CRendererSTDP2::createStringImpl(const char* str) const {
   CRendererObjSTDP2* robj = new CRendererObjSTDP2(str);
   robj->setAppearance(str);

   return robj;
}


CRendererObj* 
CRendererSTDP2::createSprite(const char* filename) const {
   return new CRendererObj( createSpriteImpl(filename) );
}

CRendererObj* 
CRendererSTDP2::createString(const char* str) const {
   return new CRendererObj( createStringImpl(str) );
}


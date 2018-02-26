#include <crendererobj.h>
#include <crendererstdp2.h>
#include <crendererobjstdp2.h>
#include <fstream>

CRendererObj*
CRendererSTDP2::createSprite(const char* filename) const {
   std::ifstream ifile(m_filepath + filename);

   CRendererObjSTDP2* robj = new CRendererObjSTDP2(filename);
   ifile >> *robj;

   return new CRendererObj(robj);
}

CRendererObj*
CRendererSTDP2::createString(const char* str) const {
   CRendererObjSTDP2* robj = new CRendererObjSTDP2(str);
   robj->setAppearance(str);

   return new CRendererObj(robj);
}

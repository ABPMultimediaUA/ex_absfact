#ifndef __CRENDEREROBJIMPL_H__
#define __CRENDEREROBJIMPL_H__

#include <cstdint>
#include <string>

class CRendererObjImpl {
public:
   CRendererObjImpl() = delete;
   CRendererObjImpl(std::string objf) : m_objfile(std::move(objf)) {}
   virtual ~CRendererObjImpl() = default;

   virtual void draw() const = 0;
   virtual void setPosition(uint8_t x, uint8_t y) = 0;

   std::string getObjFile() { return m_objfile; }
protected:
   std::string m_objfile = "";
};

#endif
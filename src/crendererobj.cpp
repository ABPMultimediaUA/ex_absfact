#include <crendererobj.h>
#include <crendererobjimpl.h>
#include <stdexcept>

CRendererObj::CRendererObj(CRendererObjImpl* impl) {
    setImplementation(impl);
}

CRendererObj::~CRendererObj() {
    clearImpl();
}

void
CRendererObj::clearImpl() {
    if (m_impl) { 
        delete m_impl;
        m_impl = nullptr;
    }
}

void  
CRendererObj::setImplementation(CRendererObjImpl* impl) {
    if (!impl)
      throw std::logic_error("Null pointer for setImplementation");
    m_impl = impl;
}

void
CRendererObj::draw() { m_impl->draw(); }

void 
CRendererObj::setPosition(uint8_t x, uint8_t y) {
    m_impl->setPosition(x, y);
}

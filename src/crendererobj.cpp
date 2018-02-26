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
    clearImpl();
    m_impl = impl;
}

CRendererObjImpl*
CRendererObj::getImplementation() {
    return m_impl;
}

void
CRendererObj::draw() { m_impl->draw(); }

void 
CRendererObj::setPosition(uint8_t x, uint8_t y) {
    m_impl->setPosition(x, y);
}

uint8_t CRendererObj::getX() const { return m_impl->getX(); }
uint8_t CRendererObj::getY() const { return m_impl->getY(); }

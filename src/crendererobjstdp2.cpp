#include <crendererobjstdp2.h>
#include <StdPijo.h>

void 
CRendererObjSTDP2::draw() const {
   STDP::CambiaColor(m_attrib, m_fgcolor, m_bgcolor);  
   STDP::PonCursor(m_x, m_y);
   STDP::sout << m_appearance << m_appearance;
   STDP::PonCursor(m_x, m_y+1);
   STDP::sout << m_appearance << m_appearance;
};

void 
CRendererObjSTDP2::setPosition(uint8_t x, uint8_t y) {
   m_x = 2*x; m_y = 2*y;  
}

istream& 
operator>>(istream& in, CRendererObjSTDP2& robj) {
   std::string app, att, fg, bg;

   in >> app >> att >> fg >> bg;

   robj.setAppearance(app);
   robj.setAttribute(att);
   robj.setFGColor(fg);
   robj.setBGColor(bg);   
}

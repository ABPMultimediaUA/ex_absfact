#include <crendererobjstdp.h>
#include <unordered_map>

const std::unordered_map < std::string, uint8_t > kColorMap {
      { "negro"   , STDP_C_NEGRO    }
   ,  { "rojo"    , STDP_C_ROJO     }
   ,  { "verde"   , STDP_C_VERDE    }
   ,  { "amarillo", STDP_C_AMARILLO }
   ,  { "azul"    , STDP_C_AZUL     }
   ,  { "magenta" , STDP_C_MAGENTA  } 
   ,  { "cian"    , STDP_C_CIAN     }
   ,  { "blanco"  , STDP_C_BLANCO   }
};

const std::unordered_map < std::string, uint8_t > kAttribMap {
      { "normal"  , STDP_A_NORMAL   }
   ,  { "inverso" , STDP_A_INVERSO  }
   ,  { "parpadeo", STDP_A_PARPADEO }
   ,  { "negrita" , STDP_A_NEGRITA  }
};

CRendererObjSTDP::CRendererObjSTDP(const CRendererObjSTDP& other)
   :  m_appearance(other.m_appearance)
   ,  m_attrib(other.m_attrib), m_fgcolor(other.m_fgcolor)
   ,  m_bgcolor(other.m_bgcolor), m_x(other.m_x), m_y(other.m_y)
{
   // Copy constructor
}

void
CRendererObjSTDP::setAppearance(const std::string& app) {
   m_appearance = app;
}

void
CRendererObjSTDP::setAttribute(const std::string& att) {
   const auto& a = kAttribMap.find(att);
   if (a == kAttribMap.end()) {
      throw std::logic_error(
         static_cast<std::string>("Undefined attribute (" + att + ")")
      );
   }

   m_attrib = a->second;
}

void
CRendererObjSTDP::setFGColor(const std::string& fg) {
   const auto& c = kColorMap.find(fg);
   if (c == kColorMap.end()) {
      throw std::logic_error(
         static_cast<std::string>("Undefined color (" + fg + ")")
      );
   }

   m_fgcolor = c->second;
}

void
CRendererObjSTDP::setBGColor(const std::string& bg) {
   const auto& c = kColorMap.find(bg);
   if (c == kColorMap.end()) {
      throw std::logic_error(
         static_cast<std::string>("Undefined color (" + bg + ")")
      );
   }

   m_bgcolor = c->second;
}

void 
CRendererObjSTDP::draw() const {
   STDP::CambiaColor(m_attrib, m_fgcolor, m_bgcolor);  
   STDP::PonCursor(m_x, m_y);
   STDP::sout << m_appearance;   
};

void 
CRendererObjSTDP::setPosition(uint8_t x, uint8_t y) {
   m_x = x; m_y = y;  
}

istream& 
operator>>(istream& in, CRendererObjSTDP& robj) {
   std::string app, att, fg, bg;

   in >> app >> att >> fg >> bg;

   robj.setAppearance(app);
   robj.setAttribute(att);
   robj.setFGColor(fg);
   robj.setBGColor(bg);   
}

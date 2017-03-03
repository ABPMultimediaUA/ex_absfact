#include <cwallMortal.h>
#include <StdPijo.h>

CWallMortal::CWallMortal() {
}

void CWallMortal::update() {
}

void CWallMortal::draw() {
   STDP::CambiaColor(STDP_A_NEGRITA, STDP_C_ROJO, STDP_C_NEGRO);  
   STDP::PonCursor(m_x, m_y);
   STDP::sout << "*";
}

CWallMortal::~CWallMortal() {
}

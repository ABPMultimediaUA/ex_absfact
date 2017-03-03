#include <cwallNormal.h>
#include <StdPijo.h>

CWallNormal::CWallNormal() {
}

void CWallNormal::update() {
}

void CWallNormal::draw() {
   STDP::CambiaColor(STDP_A_NEGRITA, STDP_C_VERDE, STDP_C_NEGRO);  
   STDP::PonCursor(m_x, m_y);
   STDP::sout << "#";
}

CWallNormal::~CWallNormal() {
}

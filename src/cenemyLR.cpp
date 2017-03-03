#include <cenemyLR.h>
#include <StdPijo.h>

CEnemyLR::CEnemyLR() : m_dir(1) {
}

void CEnemyLR::update() {
   // Check if last movement was successful
   if (m_x != m_nx) {
      // Not successful, change direction
      m_dir = -m_dir;
   }

   // Perform next movement
   setNextMovement(m_dir, 0);
}

void CEnemyLR::draw() {
   STDP::CambiaColor(STDP_A_NEGRITA, STDP_C_ROJO, STDP_C_NEGRO);  
   STDP::PonCursor(m_x, m_y);
   STDP::sout << "E";
}

CEnemyLR::~CEnemyLR() {
}

#include <cenemyWander.h>
#include <StdPijo.h>
#include <cstdlib>
#include <algorithm>

CEnemyWander::CEnemyWander() {
   initMovementVector();
}

void CEnemyWander::initMovementVector() {
   // Initialize directions vector
   m_dirs[0] = { 1, 0, static_cast<int8_t>(1 + rand() % 10) };
   m_dirs[1] = { 0, 1, static_cast<int8_t>(1 + rand() % 10) };
   m_dirs[2] = {-1, 0, static_cast<int8_t>(1 + rand() % 10) };
   m_dirs[3] = { 0,-1, static_cast<int8_t>(1 + rand() % 10) };
   std::random_shuffle(m_dirs + 0, m_dirs + 3);
}

void CEnemyWander::update() {
   // Do next movement
   TMoveDir& move = m_dirs[m_di]; 
   setNextMovement(move.dx, move.dy);

   // Count one step more and check
   ++m_step;
   if (m_step > move.step) {
      // Next direction
      ++m_di;
      if (m_di > 3) {
         initMovementVector();
         m_di   = 0;
         m_step = 0;
      }
   }
}

void CEnemyWander::draw() {
   STDP::CambiaColor(STDP_A_NEGRITA, STDP_C_MAGENTA, STDP_C_NEGRO);  
   STDP::PonCursor(m_x, m_y);
   STDP::sout << "W";
}

CEnemyWander::~CEnemyWander() {
}

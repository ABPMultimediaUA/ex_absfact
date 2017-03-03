#include <cplayer.h>
#include <StdPijo.h>
#include <ckeyboardman.h>

CPlayer::CPlayer() {
   m_KeyMan = &CKeyboardMan::p();
}

void CPlayer::update() {
   // Move the player on keypresses
   switch (m_KeyMan->getLastKeyPressed()) {
      case 'a': setNextMovement(-1,  0); break;
      case 'w': setNextMovement( 0, -1); break;
      case 's': setNextMovement( 0,  1); break;
      case 'd': setNextMovement( 1,  0); break;
      default: break;
   }
}

void CPlayer::draw() {
   STDP::CambiaColor(STDP_A_NEGRITA, STDP_C_AMARILLO, STDP_C_NEGRO);  
   STDP::PonCursor(m_x, m_y);
   STDP::sout << "P";
}

CPlayer::~CPlayer() {
}

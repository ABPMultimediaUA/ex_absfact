#include <ckeyboardman.h>
#include <StdPijo.h>

CKeyboardMan::CKeyboardMan() {}

CKeyboardMan::~CKeyboardMan() {}

CKeyboardMan&
CKeyboardMan::p() {
   static CKeyboardMan instance;
   return instance;
}

void 
CKeyboardMan::update() {
   m_lastKeyPressed = STDP::ObtenTecla();
}

char 
CKeyboardMan::getLastKeyPressed() { 
   return m_lastKeyPressed; 
}

void 
CKeyboardMan::clear() {
   // Gets keys until buffer is clear
   while(STDP::ObtenTecla() > -1);
}

char
CKeyboardMan::wait4Key() { 
   // Clears and waits for a keypress
   clear();  
   do {
      update();
   } while(m_lastKeyPressed == -1);

   return m_lastKeyPressed;
}

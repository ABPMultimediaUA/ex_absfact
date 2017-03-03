#ifndef __CKEYBOARDMAN_H__
#define __CKEYBOARDMAN_H__

class CKeyboardMan {
public:
   ~CKeyboardMan();
   static CKeyboardMan& p();

   void update();
   char getLastKeyPressed();
   char wait4Key();
   void clear();
private:
   CKeyboardMan();
   char m_lastKeyPressed;
};

#endif
#include <cgame.h>
#include <ckeyboardman.h>
#include <cscene.h>
#include <StdPijo.h>
#include <unistd.h>
#include <cmazefactEasy.h>

CGame::CGame() {
   STDP::Inicializar();
   STDP::BorraPantalla();

   // Get KeyboardManager Reference and clear Buffer
   m_KeyMan = &CKeyboardMan::p();
   m_KeyMan->clear();

   // Create scene
   m_scene = new CScene();
   CMazeFactEasy f;
   m_scene->initialize(f);
}

void CGame::update() {
   // Update keyboard and scene
   m_KeyMan->update();
   m_scene->update();
}

void CGame::timeWait() {
   static long   t = clock();
   const float fps = 30.0f;

   long toWait = t + CLOCKS_PER_SEC / fps - clock();
   if (toWait > 0)
      usleep(toWait);

   t = clock();
}

void CGame::run() {
   // Run the game until Q is pressed
   do {
      update();
      draw();
      timeWait();
   } while(    m_KeyMan->getLastKeyPressed() != 'q' 
            && m_scene->thereIsAPlayer() );
}

void CGame::draw() {
   // Redraw the screen
   STDP::BorraPantalla(); 
   m_scene->draw();
   STDP::Refrescar();
}

CGame::~CGame() {
   // End the game
   STDP::CambiaColor(STDP_A_NEGRITA, STDP_C_BLANCO, STDP_C_ROJO);
   STDP::PonCursor(2, 6);
   STDP::sout << "GAME  OVER";
   
   // Remove the scene
   delete m_scene;
   
   // Clear screen
   STDP::Refrescar();
   sleep(2);
   STDP::Terminar();
}

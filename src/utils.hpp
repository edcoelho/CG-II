#ifndef UTILS_HPP_
#define UTILS_HPP_

// Assinaturas das funções callbacks do GLUT.

// É chamada quando o FreeGLUT necessita desenhar algo na tela.
void display ();
// Lida com eventos de teclado envolvendo teclas com representações em ASCII.
void keyboard (unsigned char key, int x, int y);
// Lida com eventos de teclado envolvendo teclas especiais, como Shift, Ctrl, Fn, de F1 até F12, etc.
void special_func_keyboard (int key, int x, int y);
// Lida com eventos envolvendo os botões do mouse.
void mouse (int button, int state, int x, int y);
// Lida com eventos envolvendo o movimento do mouse enquanto um botão é pressionado.
void mouse_motion (int x, int y);
// Lida com eventos envolvendo o movimento passivo do mouse (quando não tem um botão pressionado).
void mouse_passive_motion (int x, int y);
// Lida com eventos de redimensionamento de janelas.
void window_reshape (int x, int y);
// Lida com momentos em que não há nenhum evento sendo processado.
void idle ();

#endif
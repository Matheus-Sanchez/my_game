#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h> //biblioteca de desenho
#include <ctime>


//-------------VARIAVEIS GLOBAIS------------- 
#define Largura_t  640
#define Altura_t  480
//cada pixel do jogo vale 4X4 pixeis da tela 1920x1080
int pos_x, pos_y;
pos_x = Largura_t ;
pos_y = Altura_t ;
enum TECLAS { CIMA, BAIXO, DIREITA, ESQUERDA };
bool teclas[4] = { false, false, false, false };
int fps = 60;
bool fim = false;

void IniciarAllegro()
{
    ALLEGRO_DISPLAY* display = NULL;
    //desenhar formas
    al_init_primitives_addon(); 
    //entrada do teclado
    al_install_keyboard();
    //criação de fila e demais dispositivos
    
    ALLEGRO_EVENT_QUEUE* fila_eventos = NULL;

    fila_eventos = al_create_event_queue();
    //registro de sources
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    //entrada do mouse
    al_install_mouse();
    al_register_event_source(fila_eventos, al_get_mouse_event_source());

    ALLEGRO_EVENT* ev;
    //o comando while só vai ser executado somente se alguma tecla for clicada 
    al_wait_for_event(fila_eventos, &ev);

    //TEMPORIZADOR 
    ALLEGRO_TIMER* timer = NULL;

    timer = al_create_timer(1.0 / fps);

    al_register_event_source(fila_eventos, al_get_timer_event_source(timer));

    al_start_timer(timer);
}

int IniciarDisplay()
{
    if (!al_init())
    {
        al_show_native_message_box(NULL, "AVISO!", "ERRO!", "ERRO AO INICIALIZAR A ALLEGRO!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return-1;
    }
    display = al_create_display(Largura_t, Altura_t);

    if (!display)
    {
        al_show_native_message_box(NULL, "AVISO!", "ERRO!", "ERRO AO CRIAR DISPLAY!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

}

void perso()
{
    al_draw_filled_circle(pos_x, pos_y, 50, al_map_rgb(0, 0, 255));
}

void Movimentar()
{
    //movimentar quando presionar as teclas
    switch (ev.keyboard.keycode)
    {
    case ALLEGRO_KEY_UP:
        teclas[CIMA] = true;
        break;
    case ALLEGRO_KEY_DOWN:
        teclas[BAIXO] = true;
        break;
    case ALLEGRO_KEY_RIGHT:
        teclas[DIREITA] = true;
        break;
    case ALLEGRO_KEY_LEFT:
        teclas[ESQUERDA] = true;
        break;
    }
    //parar o movimento quando soltar a tecla
    if (ev.type == ALLEGRO_EVENT_KEY_UP)
    {
        switch (ev.keyboard.keycode)
        {
        case ALLEGRO_KEY_UP:
            teclas[CIMA] = false;
            break;
        case ALLEGRO_KEY_DOWN:
            teclas[BAIXO] = false;
            break;
        case ALLEGRO_KEY_RIGHT:
            teclas[DIREITA] = false;
            break;
        case ALLEGRO_KEY_LEFT:
            teclas[ESQUERDA] = false;
            break;
        }
    }
    //velocidade do personagem (para evitar movimento diagonal, cada um tem que estar em um else if)
    if (teclas[CIMA])
    {
        pos_y -= teclas[CIMA] * 10;
    }
    else if (teclas[BAIXO])
    {
        pos_y += teclas[BAIXO] * 10;
    }
    else if (teclas[ESQUERDA])
    {
        pos_x -= teclas[ESQUERDA] * 10;
    }
    else if (teclas[DIREITA])
    {
        pos_x += teclas[DIREITA] * 10;
    }
}

void Finalizar()
{
    al_destroy_display(display);
    al_destroy_event_queue(fila_eventos);
    al_destroy_timer(timer);
}
void jogo()
{
    IniciarAllegro();
    IniciarDisplay();
    perso();

    if (ev.type == ALLEGRO_EVENT_TIMER)
    {
        while (!fim)
        {
            //o comando while só vai ser executado somente se alguma tecla for clicada 
            al_wait_for_event(fila_eventos, &ev);

            //para descobrir se o evento foi de alguma tecla sendo clicada
            if (ev.type == ALLEGRO_EVENT_KEY_DOWN)//KEY_UP para quando soltar uma tecla
            {
                //descobrir qual tecla foi presionada
                if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                {
                    fim = true;
                    Finalizar();
                }
                Movimentar();

            }
            else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                fim = true;

            }

            al_flip_display();
        }
    }
}


int main()
{
    


    jogo();




	return 0;
}
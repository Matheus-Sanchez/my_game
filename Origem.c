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
pos_x = Largura_t;
pos_y = Altura_t;
enum TECLAS { CIMA, BAIXO, DIREITA, ESQUERDA };
bool teclas[4] = { false, false, false, false };
int fps = 60;
bool fim = false;
int fase = 0;




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

int IniciarDisplay(display)
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


//tenho que criar separado cada objeto que é interativo
//geladeira
//armario
//fogao
//forno
//pia
//balcao
//batedeira



void mapa()
{
}
void submapa()
{

}
//colocar ingredientes na bacia


//colocar ingredientes no liquidificador


//cortar


//misturar


//assar


//misturar


//abrir a massa


//colocar recheio


//mergulhar


 //fritar


 //ferver no fogão


void minigames()
{
    int passo = 0;
    do
    {
        switch (passo)
            {
                case 1:       //colocar ingredientes na bacia

                    break;
                case 2:       //colocar ingredientes no liquidificador

                    break;
                case 3:       //cortar

                    break;
                case 4:       //misturar

                    break;
                case 5:       //assar

                    break;
                case 6:       //misturar

                    break;
                case 7:       //abrir a massa

                    break;
                case 8:       //colocar recheio

                    break;
                case 9:       //mergulhar

                    break;
                case 10:       //fritar

                    break;
                case 11:       //ferver no fogão

                    break;
            }
    } while (passo < 12);
    
}
//todos vao receber as funçoes respectivas para cada receita
void Bauru()
{
    // 1 bata no liquidificador (oleo, farinha, ovos, leite, sal, fermento)    
    // 2 reserve
    // 3 pique (tomete, cebola)
    // 4 reserve
    // 5 coloque metade da massa em uma forma
    // 6 coloque o que foi picado junto com milho
    // 7 cubra com presunto e queijo
    // 8 despeje o resto da massa
    // 9 asse por 40 mim no forno
    //


}
void Pastel()
{

}
void Rabanada()
{

}
void ArrozDoce()
{

}

void Fases()
{
    do
    {
        switch (fase)
        {
        case 1:
            Bauru();
            break;
        case 2:
            Pastel();
            break;
        case 3:
            Rabanada();
            break;
        case 4:
            ArrozDoce();
            break;
        }
        fase++;
    } while (fase < 5)
    {

    }
}


void perso()
{
    al_draw_filled_circle(pos_x, pos_y, 50, al_map_rgb(0, 0, 255));
}

void Movimentar(ev)
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




void colocar(display, fila_eventos, ev, timer)
{
    //pegar ingredientes com o mouse
    //quando soutar o botao, soltar ingrediente

}

void Finalizar(display, fila_eventos, ev, timer)
{
    al_destroy_display(display);
    al_destroy_event_queue(fila_eventos);
    al_destroy_timer(timer);
}


void jogo(display, fila_eventos, ev, timer)
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
            al_clear_to_color(al_map_rgb(0, 0, 0));
        }
    }
}


int main()
{



    jogo();




    return 0;
}
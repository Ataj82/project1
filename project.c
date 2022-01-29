#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/bitmap.h>
#include<allegro5/keyboard.h>
#include<allegro5/allegro.h>

int n;
int start()
{
    
    al_init();
    
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();
    al_flip_display();
    al_install_keyboard();
    al_install_mouse();
   

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    ALLEGRO_DISPLAY* disp = al_create_display(1280, 960);
    ALLEGRO_FONT* font = al_load_ttf_font("impact.ttf", 100, 0);
    ALLEGRO_FONT* font1 = al_load_ttf_font("impact.ttf", 50, 0);
    ALLEGRO_BITMAP* bitmap1 = al_load_bitmap("1.png");
    ALLEGRO_BITMAP* bitmap2 = al_load_bitmap("2.png");
    ALLEGRO_BITMAP* bitmap3 = al_load_bitmap("3.png");
    ALLEGRO_BITMAP* bitmapstart = al_load_bitmap("start.png");
    ALLEGRO_BITMAP* bitmapnull = al_load_bitmap("null.png");
    

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));
   
 
    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    al_start_timer(timer);
    while (1)
    {
        al_wait_for_event(queue, &event);

        switch (event.type)
        {
        case ALLEGRO_EVENT_TIMER:
            // game logic goes here.
            redraw = true;
            break;

        case ALLEGRO_EVENT_KEY_DOWN:
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;
            break;
        }

        if (done)
            break;

        if (redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(0, 30, 100));
            al_draw_filled_triangle(600, 400, 700, 450, 600, 500, al_map_rgb(255, 255, 255));
            al_draw_text(font, al_map_rgb(255, 255, 255), 500, 0,1000, "START");
            al_draw_text(font1, al_map_rgb(255, 255, 255), 420, 800, 1000, "press any key to start");
            al_flip_display();

            redraw = false;
        }
    }
    
    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    al_destroy_bitmap(bitmap1);
    al_destroy_bitmap(bitmap2);
    al_destroy_bitmap(bitmap3);
    al_destroy_bitmap(bitmapnull);
    al_destroy_bitmap(bitmapstart);
    return 0;
}
int game() {
    int x = 0, y = 0;
    al_init();

    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();
    al_flip_display();
    al_install_keyboard();
    al_install_mouse();


    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    ALLEGRO_DISPLAY* disp = al_create_display(1280, 960);
    ALLEGRO_FONT* font = al_load_ttf_font("impact.ttf", 100, 0);
    ALLEGRO_FONT* font1 = al_load_ttf_font("impact.ttf", 50, 0);
    ALLEGRO_BITMAP* bitmap1 = al_load_bitmap("1.png");
    ALLEGRO_BITMAP* bitmap2 = al_load_bitmap("2.png");
    ALLEGRO_BITMAP* bitmap3 = al_load_bitmap("3.png");
    ALLEGRO_BITMAP* bitmapnull = al_load_bitmap("null.png");
    ALLEGRO_BITMAP* n1 = al_load_bitmap("n1.png");

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_mouse_event_source());

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;
   

    al_start_timer(timer);
    while (1)
    {
        al_wait_for_event(queue, &event);

        switch (event.type)
        {
        case ALLEGRO_EVENT_TIMER:
            // game logic goes here.
            redraw = true;
            break;

        case ALLEGRO_EVENT_KEY_DOWN:
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;
            break;
        }
        int i = 0;
        if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            x = event.mouse.x;
            y = event.mouse.y;
            i++;
        }
        if (done)
            break;

        if (redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(0, 30, 100));
            al_draw_bitmap(bitmap3, 200, 100, 0);
            al_draw_bitmap(bitmap1, 296, 100, 0);
            al_draw_bitmap(bitmap1, 392, 100, 0);
            al_draw_bitmap(bitmap1, 488, 100, 0);
            al_draw_bitmap(bitmap1, 584, 100, 0);
            al_draw_bitmap(bitmap1, 680, 100, 0);
            al_draw_bitmap(bitmap2, 776, 100, 0);
            al_draw_bitmap(bitmap3, 152, 185, 0);
            al_draw_bitmap(bitmap2, 248, 185, 0);
            al_draw_bitmap(bitmap1, 344, 185, 0);
            al_draw_bitmap(bitmap3, 440, 185, 0);
            al_draw_bitmap(bitmap1, 536, 185, 0);
            al_draw_bitmap(bitmap1, 632, 185, 0);
            al_draw_bitmap(bitmap2, 728, 185, 0);
            al_draw_bitmap(bitmap2, 824, 185, 0);
            al_draw_bitmap(bitmap1, 200, 270, 0);
            al_draw_bitmap(bitmap2, 296, 270, 0);
            al_draw_bitmap(bitmap2, 392, 270, 0);
            al_draw_bitmap(bitmap1, 488, 270, 0);
            al_draw_bitmap(bitmap3, 584, 270, 0);
            al_draw_bitmap(bitmap1, 680, 270, 0);
            al_draw_bitmap(bitmap2, 776, 270, 0);
            al_draw_bitmap(bitmap2, 152, 355, 0);
            al_draw_bitmap(bitmap3, 248, 355, 0);
            al_draw_bitmap(bitmap1, 344, 355, 0);
            al_draw_bitmap(bitmap3, 440, 355, 0);
            al_draw_bitmap(bitmap2, 536, 355, 0);
            al_draw_bitmap(bitmap3, 632, 355, 0);
            al_draw_bitmap(bitmap2, 728, 355, 0);
            al_draw_bitmap(bitmap3, 824, 355, 0);
            al_draw_bitmap(bitmap1, 200, 440, 0);
            al_draw_bitmap(bitmap1, 296, 440, 0);
            al_draw_bitmap(bitmap3, 392, 440, 0);
            al_draw_bitmap(bitmap3, 488, 440, 0);
            al_draw_bitmap(bitmap2, 584, 440, 0);
            al_draw_bitmap(bitmap2, 680, 440, 0);
            al_draw_bitmap(bitmap1, 776, 440, 0);
            al_draw_bitmap(bitmap2, 152, 525, 0);
            al_draw_bitmap(bitmap2, 248, 525, 0);
            al_draw_bitmap(bitmap3, 344, 525, 0);
            al_draw_bitmap(bitmap3, 440, 525, 0);
            al_draw_bitmap(bitmap2, 536, 525, 0);
            al_draw_bitmap(bitmap2, 632, 525, 0);
            al_draw_bitmap(bitmap1, 728, 525, 0);
            al_draw_bitmap(bitmap2, 824, 525, 0);
            al_draw_bitmap(bitmap1, 200, 610, 0);
            al_draw_bitmap(bitmap2, 296, 610, 0);
            al_draw_bitmap(bitmap2, 392, 610, 0);
            al_draw_bitmap(bitmap3, 488, 610, 0);
            al_draw_bitmap(bitmap1, 584, 610, 0);
            al_draw_bitmap(bitmap1, 680, 610, 0);
            al_draw_bitmap(bitmap2, 776, 610, 0);
            al_draw_bitmap(bitmap3, 152, 695, 0);
            al_draw_bitmap(bitmap3, 248, 695, 0);
            al_draw_bitmap(bitmap1, 344, 695, 0);
            al_draw_bitmap(bitmap1, 440, 695, 0);
            al_draw_bitmap(bitmap1, 536, 695, 0);
            al_draw_bitmap(bitmap1, 632, 695, 0);
            al_draw_bitmap(bitmap2, 728, 695, 0);
            al_draw_bitmap(bitmap1, 824, 695, 0);
            al_draw_bitmap(n1, x-20, y-20, 0);



            al_flip_display();

            redraw = false;
        }
    }
    
    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_uninstall_mouse();
    al_destroy_event_queue(queue);
    al_destroy_bitmap(bitmap1);
    al_destroy_bitmap(bitmap2);
    al_destroy_bitmap(bitmap3);
    al_destroy_bitmap(bitmapnull);
    al_destroy_bitmap(n1);
    
    return 0;
}
int main(){
    
   printf("The number of players: ");
   scanf("%d", &n);
   start();
   game();
}
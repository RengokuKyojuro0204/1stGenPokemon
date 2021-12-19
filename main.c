#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    struct Pokemon {
        char species[20];
        int hp;
        int atk;
        int def;
        int spd;
        int sp;
    } pokemon;

    //Base per creare un allenatore (utilizzare una struct dentro un'altra struct
    /*struct Trainer {
        char name[50];
        Pokemon team[6]
        }*/

    time_t t;

    int hp = 0;
    int atk = 0;
    int def = 0;
    int spd = 0;
    int sp = 0;

    int max_iv_value = 15;

    srand((unsigned) time(&t));

    int hp_iv = 0;
    int atk_iv = rand() / (RAND_MAX / max_iv_value + 1);
    int def_iv = rand() / (RAND_MAX / max_iv_value + 1);
    int spd_iv = rand() / (RAND_MAX / max_iv_value + 1);
    int sp_iv = rand() / (RAND_MAX / max_iv_value + 1);

    int a[4];

    a[0] = atk_iv & 1;
    a[1] = def_iv & 1;
    a[2] = spd_iv & 1;
    a[3] = sp_iv & 1;

    hp_iv = a[0]*pow(2, 3) + a[1]*pow(2, 2) + a[2]*pow(2, 1) + a[3];

    printf("Gli Iv dei punti salute sono %d\n", hp_iv);
    printf("Gli Iv dell'attacco sono %d\n", atk_iv);
    printf("Gli Iv della difesa %d\n", def_iv);
    printf("Gli Iv della velocita'  sono %d\n", spd_iv);
    printf("Gli Iv degli speciali sono %d\n",sp_iv);

    int level = 5;
    int base_hp = 250;
    int base_atk = 5;
    int base_def = 5;
    int base_spd = 50;
    int base_sp = 105;


    pokemon.hp = floor((((base_hp + hp_iv) * 2) * level) / 100) + level + 10;
    pokemon.atk = floor((((base_atk + atk_iv) * 2) * level) / 100) + 5;
    pokemon.def = floor((((base_def + def_iv) * 2) * level) / 100) + 5;
    pokemon.spd = floor((((base_spd + spd_iv) * 2) * level) / 100) + 5;
    pokemon.sp = floor((((base_sp + sp_iv) * 2) * level) / 100) + 5;

    printf("I punti salute di Chansey sono %d\n", pokemon.hp);
    printf("L'attacco di Chansey e' %d\n", pokemon.atk);
    printf("La difesa di Chansey e' %d\n", pokemon.def);
    printf("La velocita' di Chansey e' %d\n", pokemon.spd);
    printf("Gli speciali di Chansey sono %d\n", pokemon.sp);





    return 0;
}

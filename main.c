#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX_IV_VALUE 15
#define LEVEL 5
#define BASE_HP 250
#define BASE_ATK 5
#define BASE_DEF 5
#define BASE_SPD 50
#define BASE_SP 105

struct Pokemon {
        char species[20];
        int hp;
        int atk;
        int def;
        int spd;
        int sp;
    };

void calcolo_degli_iv_di_chansey(int*iv)
{
    int hp_iv = 0;
    int atk_iv = 0;
    int def_iv = 0;
    int spd_iv = 0;
    int sp_iv = 0;

    time_t t;

    srand((unsigned) time(&t));

    atk_iv = rand() / (RAND_MAX / MAX_IV_VALUE + 1);
    def_iv = rand() / (RAND_MAX / MAX_IV_VALUE + 1);
    spd_iv = rand() / (RAND_MAX / MAX_IV_VALUE + 1);
    sp_iv = rand() / (RAND_MAX / MAX_IV_VALUE + 1);

    hp_iv = (atk_iv&1) *pow(2, 3) + (def_iv&1)*pow(2, 2) + (spd_iv&1)*pow(2, 1) + (sp_iv&1);

    *iv = hp_iv;
    *(iv+1) = atk_iv;
    *(iv+2) = def_iv;
    *(iv+3) = spd_iv;
    *(iv+4) = sp_iv;
}

void stampa_gli_iv_di_chansey(int hp_iv, int atk_iv, int def_iv, int spd_iv, int sp_iv)
{
    printf("Gli Iv dei punti salute sono %d\n", hp_iv);
    printf("Gli Iv dell'attacco sono %d\n", atk_iv);
    printf("Gli Iv della difesa %d\n", def_iv);
    printf("Gli Iv della velocita'  sono %d\n", spd_iv);
    printf("Gli Iv degli speciali sono %d\n",sp_iv);
}

void calcolo_delle_stats_di_chansey( int hp_iv, int atk_iv, int def_iv, int spd_iv, int sp_iv, struct Pokemon* pokemon)
{
    pokemon->hp = floor((((BASE_HP + hp_iv) * 2) * LEVEL) / 100) + LEVEL + 10;
    pokemon->atk = floor((((BASE_ATK + atk_iv) * 2) * LEVEL) / 100) + 5;
    pokemon->def =floor((((BASE_DEF + def_iv) * 2) * LEVEL) / 100) + 5;
    pokemon->spd = floor((((BASE_SPD + spd_iv) * 2) * LEVEL) / 100) + 5;
    pokemon->sp = floor((((BASE_SP + sp_iv) * 2) * LEVEL) / 100) + 5;
}

void stampa_le_statistiche_finali_di_chansey(int hp, int atk, int def, int spd, int sp)
{
    printf("I punti salute di Chansey sono %d\n", hp);
    printf("L'attacco di Chansey e' %d\n", atk);
    printf("La difesa di Chansey e' %d\n", def);
    printf("La velocita' di Chansey e' %d\n", spd);
    printf("Gli speciali di Chansey sono %d\n", sp);

}

int main()
{
    struct Pokemon pokemon;

    int hp_iv = 0;
    int atk_iv = 0;
    int def_iv = 0;
    int spd_iv = 0;
    int sp_iv = 0;

    int iv[5];

    calcolo_degli_iv_di_chansey(&(iv[0]));
    hp_iv = iv[0];
    atk_iv = iv[1];
    def_iv = iv[2];
    spd_iv = iv[3];
    sp_iv = iv[4];

    stampa_gli_iv_di_chansey(hp_iv, atk_iv, def_iv, spd_iv, sp_iv);

    calcolo_delle_stats_di_chansey( hp_iv, atk_iv, def_iv, spd_iv, sp_iv, &(pokemon));

    stampa_le_statistiche_finali_di_chansey( pokemon.hp, pokemon.atk, pokemon.def, pokemon.spd, pokemon.sp);

    return 0;
}

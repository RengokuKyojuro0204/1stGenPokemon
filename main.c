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

void calcolo_delle_stats_di_chansey(int*stats, int hp_iv, int atk_iv, int def_iv, int spd_iv, int sp_iv)
{
    *stats = floor((((BASE_HP + hp_iv) * 2) * LEVEL) / 100) + LEVEL + 10;
    *(stats+1)= floor((((BASE_ATK + atk_iv) * 2) * LEVEL) / 100) + 5;
    *(stats+2)= floor((((BASE_DEF + def_iv) * 2) * LEVEL) / 100) + 5;
    *(stats+3)= floor((((BASE_SPD + spd_iv) * 2) * LEVEL) / 100) + 5;
    *(stats+4)= floor((((BASE_SP + sp_iv) * 2) * LEVEL) / 100) + 5;
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
    struct Pokemon {
        char species[20];
        int hp;
        int atk;
        int def;
        int spd;
        int sp;
    } pokemon;

    int hp_iv = 0;
    int atk_iv = 0;
    int def_iv = 0;
    int spd_iv = 0;
    int sp_iv = 0;

    int hp = 0;
    int atk = 0;
    int def = 0;
    int spd = 0;
    int sp = 0;

    int iv[5];

    calcolo_degli_iv_di_chansey(&(iv[0]));
    hp_iv = iv[0];
    atk_iv = iv[1];
    def_iv = iv[2];
    spd_iv = iv[3];
    sp_iv = iv[4];

    stampa_gli_iv_di_chansey(hp_iv, atk_iv, def_iv, spd_iv, sp_iv);

    int stats[5];

    calcolo_delle_stats_di_chansey(&(stats[0]), hp_iv, atk_iv, def_iv, spd_iv, sp_iv);

    hp = stats[0];
    atk = stats[1];
    def = stats[2];
    spd = stats[3];
    sp = stats[4];

    pokemon.hp = hp;
    pokemon.atk = atk;
    pokemon.def = def;
    pokemon.spd = spd;
    pokemon.sp = sp;

    stampa_le_statistiche_finali_di_chansey( pokemon.hp, pokemon.atk, pokemon.def, pokemon.spd, pokemon.sp);

    return 0;
}

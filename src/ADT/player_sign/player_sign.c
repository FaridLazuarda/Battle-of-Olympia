#include <stdio.h>
#include <stdint.h>
#include "player_sign.h"

void OneTurn(char *str);
void TwoTurn(char *str);
void red();
void yellow();
void green();
void blue();
void magenta();
void cyan();
void reset();
void WelcomeMessage();
void Help();
void Congrats(char *str);

void WelcomeMessage()
{
 blue();
 printf("    e Y8b                         d8                 \n"); 
 printf("   d8b Y8b    Y8b Y888P  ,1Y88b  d88    ,1Y88b 888,8,\n"); 
 printf("  d888b Y8b    Y8b Y8P  '8' 888 d88888 '8' 888 888 8 \n"); 
 printf(" d888888888b    Y8b 8   ,ee 888  888   ,ee 888 888   \n"); 
 printf("d8888888b Y8b    Y8P     88 888  888   '88 888 888   \n"); 
 reset();
 printf("                                                     \n"); 
 cyan();
 printf("Y8b Y8b Y888P                  888      888          \n"); 
 printf(" Y8b Y8b Y8P   e88 88e  888,8, 888  e88 888          \n"); 
 printf("  Y8b Y8b Y   d888 888b 888 8  888 d888 888          \n"); 
 printf("   Y8b Y8b    Y888 888P 888    888 Y888 888          \n"); 
 printf("    Y8P Y      188 881  888    888  188 888          \n");
 reset(); 
 printf("                                                     \n"); 
 blue();
 printf("Y8b Y8b Y888P                                        \n"); 
 printf(" Y8b Y8b Y8P   ,1Y88b   888,8,                         \n"); 
 printf("  Y8b Y8b Y   '8' 888   888 8                          \n"); 
 printf("   Y8b Y8b    ,ee 888   888                            \n"); 
 printf("    Y8P Y     '88 888   888                            \n\n"); 
 reset();
printf("SELAMAT DATANG DI AVATAR WORLD WAR!\n");
printf("Game Avatar World War adalah game turn-based strategy yang mensimulasikan perang dunia ATLA. Game ini\n");
printf("dimainkan dengan cara memasukkan perintah melalui command line interface sebagai berikut:\n\n");
printf("$ ATTACK   : Melakukan serangan ke bangunan lain.\n");
printf("$ MOVE     : Memindahkan pasukan dari suatu bangunan ke bangunan lain.\n");
printf("$ SKILL    : Memakai skill yang dimiliki oleh pemain\n");
printf("$ LEVEL_UP : Menaikkan level dari suatu bangunan.\n");
printf("$ END_TURN : Mengakhiri giliran dari pemain.\n");
printf("$ EXIT     : Keluar dari program.\n");
printf("$ UNDO     : Membatalkan perintah terakhir.\n");
printf("$ SAVE     : Menyimpan status permainan sekarang ke file eksternal.\n\n");
printf("$ HELP     : Memberikan petunjuk cara bermain.");
blue();
printf("Good luck!\n\n");
reset();
}

void Help()
{
  printf("$ ATTACK   : Melakukan serangan ke bangunan lain.\n");
  printf("$ MOVE     : Memindahkan pasukan dari suatu bangunan ke bangunan lain.\n");
  printf("$ SKILL    : Memakai skill yang dimiliki oleh pemain\n");
  printf("$ LEVEL_UP : Menaikkan level dari suatu bangunan.\n");
  printf("$ END_TURN : Mengakhiri giliran dari pemain.\n");
  printf("$ EXIT     : Keluar dari program.\n");
  printf("$ UNDO     : Membatalkan perintah terakhir.\n");
  printf("$ SAVE     : Menyimpan status permainan sekarang ke file eksternal.\n\n");
  printf("$ HELP     : Memberikan petunjuk cara bermain.\n\n");
}
void red () {
  printf("\033[1;31m");
}

void yellow() {
  printf("\033[1;33m");
}

void green() {
  printf("\033[1;32m");
}

void blue() {
  printf("\033[1;34m");
}

void magenta() {
  printf("\033[1;35m");
}

void cyan() {
  printf("\033[1;36m");
}

void reset () {
  printf("\033[0m");
}

void OneTurn(char *str)
{ 
 //scanf("%s",&nama);
 red();
 printf("           d8b                                                                  \n"); 
 printf("           88P                                                                  \n");
 reset();
 yellow();
 printf("          d88                                                                   \n");
 printf("?88,.d88b,888   d888b8b  ?88   d8P  d8888b  88bd88b     d8888b   88bd88b  d8888b\n");
 reset();
 green();
 printf("`?88'  ?88?88  d8P' ?88  d88   88  d8b_,dP  88P'  `    d8P' ?88  88P' ?8bd8b_,dP\n");
 printf("  88b  d8P 88b 88b  ,88b ?8(  d88  88b     d88         88b  d88 d88   88P88b    \n");
 reset();
 blue();
 printf("  888888P'  88b`?88P'`88b`?88P'?8b `?888P'd88'         `?8888P'd88'   88b`?888P'\n");
 printf("  88P'                          )88                                             \n");
 reset();
 magenta();
 printf(" d88                           ,d8P                                             \n");
 printf(" ?8P                        `?888P'                                           \n\n"); 
 reset();
 printf("Sekarang giliranmu, %s (P1)!\n\n", str);
 printf("\033[0m");
}

void TwoTurn(char *str)
{ 
    
 //scanf("%s", &nama);
 magenta();
 printf("           d8b                                                                        \n");
 printf("           88P                                            d8P                         \n");
 reset();
 blue();
 printf("          d88                                          d888888P                       \n");
 printf("?88,.d88b,888   d888b8b  ?88   d8P  d8888b  88bd88b      ?88'   ?88   d8P  d8P d8888b \n");
 reset();
 green();
 printf("`?88'  ?88?88  d8P' ?88  d88   88  d8b_,dP  88P'  `      88P    d88  d8P' d8P'd8P' ?88\n");
 printf("  88b  d8P 88b 88b  ,88b ?8(  d88  88b     d88           88b    ?8b ,88b ,88' 88b  d88\n");
 reset();
 yellow();
 printf("  888888P'  88b`?88P'`88b`?88P'?8b `?888P'd88'           `?8b   `?888P'888P'  `?8888P'\n");
 printf("  88P'                          )88                                                   \n");
 reset();
 red();
 printf(" d88                           ,d8P                                                   \n");
 printf(" ?8P                        `?888P'                                                 \n\n");
 reset();
 printf("Sekarang giliranmu, %s (P2)!\n\n", str);
}

void Congrats(char *str)
{
for (int i=1;i<=18;i++)
{
//  system("cls");
 blue();
 printf("                                                                                                                                                       \n");
 printf("                                                                                                                                                       \n");
 printf("        CCCCCCCCCCCCC                                                                                                   tttt                           \n");
 printf("     CCC::::::::::::C                                                                                                ttt:::t                           \n");
 printf("   CC:::::::::::::::C                                                                                                t:::::t                           \n");
 printf("  C:::::CCCCCCCC::::C                                                                                                t:::::t                           \n");
 printf(" C:::::C       CCCCCC   ooooooooooo   nnnn  nnnnnnnn       ggggggggg   gggggrrrrr   rrrrrrrrr   aaaaaaaaaaaaa  ttttttt:::::ttttttt        ssssssssss   \n");
 printf("C:::::C               oo:::::::::::oo n:::nn::::::::nn    g:::::::::ggg::::gr::::rrr:::::::::r  a::::::::::::a t:::::::::::::::::t      ss::::::::::s  \n");
 printf("C:::::C              o:::::::::::::::on::::::::::::::nn  g:::::::::::::::::gr:::::::::::::::::r aaaaaaaaa:::::at:::::::::::::::::t    ss:::::::::::::s \n");
 printf("C:::::C              o:::::ooooo:::::onn:::::::::::::::ng::::::ggggg::::::ggrr::::::rrrrr::::::r         a::::atttttt:::::::tttttt    s::::::ssss:::::s\n");
 printf("C:::::C              o::::o     o::::o  n:::::nnnn:::::ng:::::g     g:::::g  r:::::r     r:::::r  aaaaaaa:::::a      t:::::t           s:::::s  ssssss \n");
 printf("C:::::C              o::::o     o::::o  n::::n    n::::ng:::::g     g:::::g  r:::::r     rrrrrrraa::::::::::::a      t:::::t             s::::::s      \n");
 printf("C:::::C              o::::o     o::::o  n::::n    n::::ng:::::g     g:::::g  r:::::r           a::::aaaa::::::a      t:::::t                s::::::s   \n");
 printf(" C:::::C       CCCCCCo::::o     o::::o  n::::n    n::::ng::::::g    g:::::g  r:::::r          a::::a    a:::::a      t:::::t    ttttttssssss   s:::::s \n");
 printf("  C:::::CCCCCCCC::::Co:::::ooooo:::::o  n::::n    n::::ng:::::::ggggg:::::g  r:::::r          a::::a    a:::::a      t::::::tttt:::::ts:::::ssss::::::s\n");
 printf("   CC:::::::::::::::Co:::::::::::::::o  n::::n    n::::n g::::::::::::::::g  r:::::r          a:::::aaaa::::::a      tt::::::::::::::ts::::::::::::::s \n");
 printf("     CCC::::::::::::C oo:::::::::::oo   n::::n    n::::n  gg::::::::::::::g  r:::::r           a::::::::::aa:::a       tt:::::::::::tt s:::::::::::ss  \n");
 printf("        CCCCCCCCCCCCC   ooooooooooo     nnnnnn    nnnnnn    gggggggg::::::g  rrrrrrr            aaaaaaaaaa  aaaa         ttttttttttt    sssssssssss    \n");
 printf("                                                                    g:::::g                                                                            \n");
 printf("                                                        gggggg      g:::::g                                                                            \n");
 printf("                                                        g:::::gg   gg:::::g                                                                            \n");
 printf("                                                         g::::::ggg:::::::g                                                                            \n");
 printf("                                                          gg:::::::::::::g                                                                             \n");
 printf("                                                            ggg::::::ggg                                                                               \n");
 printf("                                                               gggggg                                                                                  \n");
 
 reset();
 printf("\n\n Selamat, %s! Kamu berhasil memenangkan permainan ini!\n", str);
//  Sleep(500);
//  system("cls");
 cyan();
 printf("                                                                                                                                                       \n");
 printf("                                                                                                                                                       \n");
 printf("        CCCCCCCCCCCCC                                                                                                   tttt                           \n");
 printf("     CCC::::::::::::C                                                                                                ttt:::t                           \n");
 printf("   CC:::::::::::::::C                                                                                                t:::::t                           \n");
 printf("  C:::::CCCCCCCC::::C                                                                                                t:::::t                           \n");
 printf(" C:::::C       CCCCCC   ooooooooooo   nnnn  nnnnnnnn       ggggggggg   gggggrrrrr   rrrrrrrrr   aaaaaaaaaaaaa  ttttttt:::::ttttttt        ssssssssss   \n");
 printf("C:::::C               oo:::::::::::oo n:::nn::::::::nn    g:::::::::ggg::::gr::::rrr:::::::::r  a::::::::::::a t:::::::::::::::::t      ss::::::::::s  \n");
 printf("C:::::C              o:::::::::::::::on::::::::::::::nn  g:::::::::::::::::gr:::::::::::::::::r aaaaaaaaa:::::at:::::::::::::::::t    ss:::::::::::::s \n");
 printf("C:::::C              o:::::ooooo:::::onn:::::::::::::::ng::::::ggggg::::::ggrr::::::rrrrr::::::r         a::::atttttt:::::::tttttt    s::::::ssss:::::s\n");
 printf("C:::::C              o::::o     o::::o  n:::::nnnn:::::ng:::::g     g:::::g  r:::::r     r:::::r  aaaaaaa:::::a      t:::::t           s:::::s  ssssss \n");
 printf("C:::::C              o::::o     o::::o  n::::n    n::::ng:::::g     g:::::g  r:::::r     rrrrrrraa::::::::::::a      t:::::t             s::::::s      \n");
 printf("C:::::C              o::::o     o::::o  n::::n    n::::ng:::::g     g:::::g  r:::::r           a::::aaaa::::::a      t:::::t                s::::::s   \n");
 printf(" C:::::C       CCCCCCo::::o     o::::o  n::::n    n::::ng::::::g    g:::::g  r:::::r          a::::a    a:::::a      t:::::t    ttttttssssss   s:::::s \n");
 printf("  C:::::CCCCCCCC::::Co:::::ooooo:::::o  n::::n    n::::ng:::::::ggggg:::::g  r:::::r          a::::a    a:::::a      t::::::tttt:::::ts:::::ssss::::::s\n");
 printf("   CC:::::::::::::::Co:::::::::::::::o  n::::n    n::::n g::::::::::::::::g  r:::::r          a:::::aaaa::::::a      tt::::::::::::::ts::::::::::::::s \n");
 printf("     CCC::::::::::::C oo:::::::::::oo   n::::n    n::::n  gg::::::::::::::g  r:::::r           a::::::::::aa:::a       tt:::::::::::tt s:::::::::::ss  \n");
 printf("        CCCCCCCCCCCCC   ooooooooooo     nnnnnn    nnnnnn    gggggggg::::::g  rrrrrrr            aaaaaaaaaa  aaaa         ttttttttttt    sssssssssss    \n");
 printf("                                                                    g:::::g                                                                            \n");
 printf("                                                        gggggg      g:::::g                                                                            \n");
 printf("                                                        g:::::gg   gg:::::g                                                                            \n");
 printf("                                                         g::::::ggg:::::::g                                                                            \n");
 printf("                                                          gg:::::::::::::g                                                                             \n");
 printf("                                                            ggg::::::ggg                                                                               \n");
 printf("                                                               gggggg                                                                                  \n");
 reset();
 printf("\n\n Selamat, %s! Kamu berhasil memenangkan permainan ini!\n", str);
//  Sleep(500);
//  system("cls");
}
reset();
}
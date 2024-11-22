//-------------------------------------------------------------*/         
//                 Projet Space Invader Groupe A2
//
// Groupe : A2
//
// Auteurs :  -Caillet Maxence
//            -Grolier Nicolas
//-------------------------------------------------------------*/


#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

/*-------------------------------------------------------------*/
/* DECLARATIONS DES FCTS DE GESTION DU TERMINAL */
/*-------------------------------------------------------------*/
void color(int cT, int cF);
char nb_getch();
char b_getch();
void startscr();


 /*-------------------------------------------------------------*/
 /* DECLARATION DES FCTS DE GESTION DU JEU */
 /*-------------------------------------------------------------*/

int choix_menu()
{
  
  int choix; 
  char pseudo[100]; //Chaine de caractère stockant le pseudo du joueur
  printw(

                  "          _____                          ____                     __         "   
                  "\n       / ___/____  ____ _________     /  _/___ _   ______ _____/ /__  _____"
                  "\n       |__ |/ __ |/ __ `/ ___/ _ |    / // __ | | / / __ `/ __  / _ |/ ___/"
                  "\n      ___/ / /_/ / /_/ / /__/  __/  _/ // / / / |/ / /_/ / /_/ /  __/ /    "
                  "\n     /____/ .___/|__,_/|___/|___/  /___/_/ /_/|___/|__,_/|__,_/|___/_/     "    
                  "\n         /_/                                                               "
                  "\n                                                                           "  
                  "\n                                                                           "
                  "\n                                                                           "
                  "\n                                                                           "
                  "\n                  Welcome to                           Let's GO !!!                    "
                  "\n                  Space Invader                    ,                       "
                  "\n                                                                           "
                  "\n                                                "
                  "\n                             /  _.-'~~~~'-._   /                           "
                  "\n                      .      .-~ /__/  /__/ ~-.         .                  "
                  "\n                           .-~   (oo)  (oo)    ~-.                         "
                  "\n                          (_____//~~////~~//______)                        "
                  "\n                     _.-~`                         `~-._                   "
                  "\n                    |O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O|     *            "
                  "\n                    |___________________________________|                  "
                  "\n                              |x x x x x x x|                              "
                  "\n                      .  *     |x_x_x_x_x_x|                               ");
  
  getch();               
  clear();
  refresh();

  printw(     "                                                                "
              "\n          .     .  :     .    .. .___---------___.            "
              "\n          .  .   .    .  :.:. _.^ .^ ^.  '.. :-_. .           "
              "\n        .  :       .  .  .:../:            . .^  :.:|.        "
              "\n             .   . :: +. :.:/: .   .    .        . . .:|      "
              "\n         :    .     . _ :::/:                 ^ .  . .:|      "
              "\n       .. . .   . - : :.:./.                       .  .:|     "
              "\n       .      .     . :..|:                    .  .  ^. .:|   "
              "\n         .       . : : ..||        .                . . !:|   "
              "\n       .     . . . ::. ::|(                           . :)|   "
              "\n      .   .     : . : .:.|. ######              .#######::|   "
              "\n       :.. .  :-  : .:  ::|.#######            ########:|     "
              "\n       .  .  .  ..  .  .. :| ########        :######## :/     "
              "\n        .        .+ :: : -.:| ########       ########.:/      "
              "\n         .  .+   . . . . :.:|.  #######     #######..:/       "
              "\n         :: . . . . ::.:..:.|          .   .   ..:  /         "
              "\n       .   .  .. :  -::::   .|.         | |     .   /         "
              "\n          :  .  .  .-:.:.::   .|             ..:    /         "
              "\n         -.   . . . .: .:::.:   .|.           .:   /          "
              "\n.  .   ..  :       : ....::_:.   .|:   ___.   :   /   What's your name warrior ?  "
              "\n         .   .  .   .:. .. .  .: :.:|            |    "
              "\n          +   .   .   : . ::. :.:. .|     .:/.   |    "
              "\n     .   .       .      :  .   .: ::|     ..     |                    \n");                        
  getch();
  clear();
  refresh();
  
  printw("Entrez votre pseudo :");
  scanw("%s",&pseudo);
  printw("\n\n\t\t\t*****************************"
             "\n\t\t\t*                           *"
             "\n\t\t\t*         BIENVENUE         *"
             "\n\t\t\t*                           *"
             "\n\t\t\t*****************************");
  printw("\n\n\n\n\nPresser Entrée pour poursuivre :    ");
  getch();
  clear();
  refresh();
  printw("\n\n\t\t\t1:    Jouer"
             "\n\t\t\t2:    Aide"
             "\n\t\t\t3:    Quitter");
  printw("\n\nVotre choix:");
  scanw("%d", &choix);
  clear();
  refresh();
  
  //Saisie validé 
  while(choix<1 || choix>3) 
   {
     printw("\nVotre choix de poursuite");
     scanw("%d", &choix);
     clear();
     refresh();
   }
   
   return choix; 
}

float game_play(x,y,touche,xvs1,yvs1,xvs2,yvs2,xvs3,yvs3,xvs4,yvs4,xmissile,ymissile,xvitamine,yvitamine,haut,life,point)
{
  life=2; //Fixation du nombre de Vies de départ
  point=0; //Fixation du nombre de Points d'XP
  printw(     "\n |                                                                           |" 
              "\n |                                                                           |"
              "\n |                                                                           |"
              "\n |                                                                           |"
              "\n |                                                                           |"
              "\n |                                                                           |"
              "\n |                                                                           |"
              "\n |                                                                           |"
              "\n |                                                                           |"
              "\n |                                                                           |"
              "\n |                                                                           |"
              "\n |                                                                           |"
              "\n |                                                                           |"
              "\n |                                                                           |"
              "\n |                                                                           |"
              "\n |                                                                           |"
              "\n |                                                                           |"
              "\n |                                                                           |"
              "\n |                                                                           |"
              "\n |___________________________________________________________________________| \n");     
  while(1)
  { 
    touche=nb_getch();
    move(y,x);
    printw("    ");
    
    if (touche=='q'&& x!=3) x-=1; //Non dépassement du bord gauche
    if (touche=='d' && x!=71) x+=1; //Non dépassement du bord droit
    if (touche=='z'&& y!=1) y-=1;  //Non dépassement en hauteur 
    if (touche=='s' && y!=18) y+=1;  //Non dépassement du bas
    curs_set(0); //N'affiche plus les espaces, on est centré sur le vaisseaux
    noecho();    //N'affiche pas les caractères tapés
    move(y,x);
    printw("*/\\*");
    refresh();
    
    /*-----------------------------------------------------------------------*/
    /* Paramètres affichage des points de Vie et du nombre de Points Gagnants 
    *-------------------------------------------------------------------------*/
    mvprintw(23,3,"life=%d",life); //Point de Vies
    mvprintw(23,15,"Points Gagnants=%d",point); //Points d'XP
    
    /*-------------------------------------------------------------*/
    /* Paramètres des vaissaux ennemis
    *-------------------------------------------------------------*/
    
    //Premier vaisseau ennemie vs1
    mvprintw(yvs1,xvs1,"   ");
    if(yvs1<18) //Fixation de la limite pour y=18
    {
      yvs1=yvs1+1;
      refresh();
    } 
    else 
    {
      xvs1=rand() % 3 + 10; //Génère des abscisses aléatoires dans l'intervalle donné
      yvs1=0;
      refresh();
    }
    mvprintw(yvs1,xvs1,"<x>");
    refresh();
    usleep(100000);
    
    //Deuxième vaisseau ennemie vs2
    if(point>=20)
    {
      mvprintw(yvs2,xvs2,"   ");
      if(yvs2<18) 
      {
        yvs2=yvs2+1.5; 
        refresh();
      } 
      else 
      {
        xvs2=rand() % 12 + 25;
        yvs2=0;
        refresh();
      }
      mvprintw(yvs2,xvs2,"<x>");
      refresh();
      usleep(1000);
    }
    
    //Troisème vaisseau ennemie vs3
    if(point>=50)
    {
      mvprintw(yvs3,xvs3,"   ");
      if(yvs3<16) 
      {
        yvs3=yvs3+2; 
        refresh();
      } 
      else 
      {
        xvs3=rand() % 27 + 46;
        yvs3=0;
        refresh();
      }
      mvprintw(yvs3,xvs3,"<x>");
      refresh();
      usleep(100000);
    }
    
    //Quatrième vaisseau ennemie vs4
    if(point>=60)
    {
      mvprintw(yvs4,xvs4,"   ");
      if(yvs4<16) 
      {
        yvs4=yvs4+4; 
        refresh();
      } 
      else 
      {
        xvs4=rand() %  4 + 35;
        yvs4=0;
        refresh();
      }
      mvprintw(yvs4,xvs4,"<x>");
      refresh();
      usleep(100000);
    }
    
    /*-------------------------------------------------------------*/
    /* Paramètres pour le lancer de missiles
    *-------------------------------------------------------------*/
    if (touche=='m') 
    {
      haut=0; //Logique d'état Haut/Bas
      xmissile=x;
      ymissile=y;
      mvprintw(ymissile,xmissile,"*||*");
      refresh();
      while(haut!=1)
      {
        ymissile=ymissile-1;
        curs_set(x);
        mvprintw(ymissile,xmissile," ||");
        refresh();
        usleep(27000);
        if (ymissile<2)
        {
          haut=1;
          refresh(); 
        }
        mvprintw(ymissile,xmissile,"   ");
        refresh(); 
        } 
     }  

     /*---------------------------------------------------------------------------*/
     /* Paramètres pour les collisions entre vaisseau joueur et vaisseaux ennemis
     *----------------------------------------------------------------------------*/
     if((x==xvs1 && y-yvs1==0)||(x==xvs2 && y-yvs2==0)||(x+1==xvs1 && y-yvs1==0)||(x+1==xvs2 && y-yvs2==0)||(x+2==xvs1 && y-yvs1==0)||(x+2==xvs2 && y-yvs2==0)||(x+3==xvs1 && y-yvs1==0)||(x+3==xvs2 && y-yvs2==0))
      {
        life=life-1;
      }
      if((x==xvs3 && y-yvs3==0)||(x==xvs4 && y-yvs4==0)||(x+1==xvs3 && y-yvs3==0)||(x+1==xvs4 && y-yvs4==0)||(x+2==xvs3 && y-yvs3==0)||(x+2==xvs4 && y-yvs4==0)||(x+3==xvs3 && y-yvs3==0)||(x+3==xvs4 && y-yvs4==0))
      {
        life=life-1;
      }
      if((xvs1+1==x && y-yvs1<0)||(xvs1+2==x && y-yvs1<0)||(xvs2+1==x && y-yvs2<0)||(xvs2+2==x && y-yvs2<0))
      {
        life=life-1;
      }
      if((xvs3+1==x && y-yvs3<0)||(xvs3+2==x && y-yvs3<0)||(xvs4+1==x && y-yvs4<0)||(xvs4+2==x && y-yvs4<0))
      {
        life=life-1;
      }
      
     //---------------------------------------------------------------*/
     // Paramètres pour collisions entre missiles et vaisseaux ennemis
     //---------------------------------------------------------------*/
     
     //Collision Misisle/VS1
     if((xmissile+1==xvs1 && ymissile-yvs1<=0)||(xmissile+2==xvs1 && ymissile-yvs1<=0)||(xmissile+3==xvs1 && ymissile-yvs1<=0))
     {
       point=point+10; //Augmentation des Points d'XP
       mvprintw(yvs1,xvs1,"   "); 
       xvs1=rand() % 10 + 3;
       yvs1=-30;
       mvprintw(yvs1,xvs1,"   ");      
     }    
     if((xmissile+1==xvs1+1 && ymissile-yvs1<=0)||(xmissile+1==xvs1+2 && ymissile-yvs1<=0)||(xmissile+1==xvs1+3 && ymissile-yvs1<=0))  
     {
       point=point+10;
       mvprintw(yvs1,xvs1,"   "); 
       xvs1=rand() % 10 + 3;
       yvs1=-30;
       mvprintw(yvs1,xvs1,"   ");      
     } 
  
    //Collision Misisle/VS2
    if((xmissile+1==xvs2 && ymissile-yvs2<=0)||(xmissile+2==xvs2 && ymissile-yvs2<=0)||(xmissile+3==xvs2 && ymissile-yvs2<=0))
    {
      point=point+20;
      mvprintw(yvs2,xvs2,"   "); 
      xvs2=rand()  % 12 + 25;
      yvs2=-15;
      mvprintw(yvs2,xvs2,"   ");      
      
    }    
    if((xmissile+1==xvs2+1 && ymissile-yvs2<=0)||(xmissile+1==xvs2+2 && ymissile-yvs2<=0)||(xmissile+1==xvs2+3 && ymissile-yvs2<=0))  
    {
      point=point+20;
      mvprintw(yvs2,xvs2,"   "); 
      xvs2=rand()  % 12 + 25;
      yvs2=-15;
      mvprintw(yvs2,xvs2,"   ");      
    } 
    //Collision Misisle/VS3
     if((xmissile+1==xvs3 && ymissile-yvs3<=0)||(xmissile+2==xvs3 && ymissile-yvs3<=0)||(xmissile+3==xvs3 && ymissile-yvs3<=0))
    {
      point=point+30;
      mvprintw(yvs3,xvs3,"   "); 
      xvs3=rand() % 27 + 46;
      yvs3=-2;
      mvprintw(yvs3,xvs3,"   ");      
      
    }    
    if((xmissile+1==xvs3+1 && ymissile-yvs3<=0)||(xmissile+1==xvs3+2 && ymissile-yvs3<=0)||(xmissile+1==xvs3+3 && ymissile-yvs3<=0))  
    {
      point=point+30;
      mvprintw(yvs3,xvs3,"   "); 
      xvs3=rand() % 27 + 46;
      yvs3=-2;
      mvprintw(yvs3,xvs3,"   ");      
    } 
   //Collision Misisle/VS4
     if((xmissile+1==xvs4 && ymissile-yvs4<=0)||(xmissile+2==xvs4 && ymissile-yvs4<=0)||(xmissile+3==xvs4 && ymissile-yvs4<=0))
    {
      point=point+30;
      mvprintw(yvs3,xvs3,"   "); 
      xvs4=rand() % 4 + 35;
      yvs4=-5;
      mvprintw(yvs3,xvs3,"   ");      
      
    }    
    if((xmissile+1==xvs4+1 && ymissile-yvs4<=0)||(xmissile+1==xvs4+2 && ymissile-yvs4<=0)||(xmissile+1==xvs4+3 && ymissile-yvs4<=0))  
    {
      point=point+30;
      mvprintw(yvs3,xvs3,"   "); 
      xvs4=rand() % 4 + 35;
      yvs4=-5;
      mvprintw(yvs3,xvs3,"   ");      
    } 
    
    //---------------------------------------------------------------*/
    // Paramètres pour les vitamines
    //---------------------------------------------------------------*/
    
    if((point==20)||(point==40)||(point==80)||(point==100)|| (point==200)||(point==350))
    {
      xvitamine=15;
      yvitamine=15;
      mvprintw(xvitamine,yvitamine,"ooo");
      refresh();
      if((x==xvitamine && y==yvitamine)||(x+1==xvitamine && y==yvitamine)||(x+2==xvitamine && y==yvitamine)||(x==xvitamine+1 && y==yvitamine)||(x==xvitamine+2 && y==yvitamine))
      {
        life=life+1; //Augmentation de la vie 
        xvitamine=0;
        yvitamine=0;
        mvprintw(xvitamine,yvitamine," ");
        refresh();
      }
    }
    
    //---------------------------------------------------------------*/ 
    // Condition de sortie du jeu
    //---------------------------------------------------------------*/
    if((life==35) || (point>=150))
    {
      break;
    }
    
  }
  clear();
  refresh();
  return 0;
}

float aide(choix)
{
  
  printw("\n\tBonjour à toi et bienvenue sur notre jeu Space Invader !");
  printw("\n\nLe but du jeu est très simple, tu controles ton vaisseau et tu dois éviter ou éliminer les vaisseaux énnemies");
  printw("\n\nPour cela Warrior, tu possèdes un laser qui te permet d'éliminer tes énnemies en appuyant sur la touche M de ton clavier");
  printw("\n\nSi tu as aquis plus de 150 points d'XP, le jeu s'arrete et "
         "tu remportes la partie Warrior");
  printw("\n\n De plus, des vitamines sous la forme de +++ apparaitront à l'écran, en restant dessus le plus longtemps, ta vie augmentera considérablement.");
  printw("\n\n Si toutefois tu arrivais à 35 points de vies, tu remportes la partie Warrior");
  printw("\n\n Bien entendu, si tu n'as plus de vie, tu PÉRIRA DANS LE VIDE INTERSIDERALE. ");
  printw("\n\nJe n'ai qu'une dernière phrase à te dire avant que tu prennes ton envole");
  printw("\n\t\t\tVERS L'INFNI ET AU-DELA !!!!!!!!");
  getch();               
  clear();
  refresh();
  return 0;
} 
  
  /*-------------------------------------------------------------*/
  /* FONCTION PRINCIPALE */
  /*-------------------------------------------------------------*/
  int main()
 {
   //Déclaration des variables
   int choix;
   int x=23; //Abscisse du vaisseau joueur
   int y=17; //Ordonnée du vaisseau joueur
   int xvs1=rand() % 10 + 3; //Abscisse du premier vaisseau ennemi vs1
   int yvs1=0; //Ordonnée du  premier vaisseau ennemi vs1
   int xvs2=rand() % 49; //Abscisse du deuxième vaisseau ennemi vs1
   int yvs2=0;
   int xvs3=rand() %  27 + 46; //Abscisse du troisième vaisseau ennemi vs1
   int yvs3=0;
   int xvs4=rand() % 4 + 35; //Abscisse du quatrième vaisseau ennemi vs1
   int yvs4=0;
   int xmissile; //Abscisse du missile
   int ymissile; //Ordonnée du missile
   int haut; //Etat du missile 
   int life; //Variable de Vie du vaisseau joueur 
   char touche='d'; //Initialisation de la variable touche
   int point; //Variable stockant le nombre de Points d'XP du joueur 
   int xvitamine; //Abscisse de la vitamine 
   int yvitamine; //Ordonnée de la vitamine 
   srand(time(NULL)); //Génère des nombres aléatoires 

   
   // Les instructions avant le début du jeu
   initscr();
   choix=choix_menu();
  
   while(choix>1 || choix<=3 )
    {  
      if(choix==1)
      {
        game_play(x,y,touche,xvs1,yvs1,xvs2,yvs2,xvs3,yvs3,xvs4,yvs4,xmissile,ymissile,xvitamine,yvitamine,haut,life,point);
        return 0;
      }
      else if(choix==2)
      {
        aide(choix);
      }
      if(choix==3)
      {
        printw(

                  "          _____                          ____                     __         "   
                  "\n       / ___/____  ____ _________     /  _/___ _   ______ _____/ /__  _____"
                  "\n       |__ |/ __ |/ __ `/ ___/ _ |    / // __ | | / / __ `/ __  / _ |/ ___/"
                  "\n      ___/ / /_/ / /_/ / /__/  __/  _/ // / / / |/ / /_/ / /_/ /  __/ /    "
                  "\n     /____/ .___/|__,_/|___/|___/  /___/_/ /_/|___/|__,_/|__,_/|___/_/     "    
                  "\n         /_/                                                               "
                  "\n                                                                           "  
                  "\n                                                                           "
                  "\n                                                                           "
                  "\n                                                                           "
                  "\n                                             Alright Bye and see you soon !!!                    "
                  "\n       What, are you leaving already?                    ,                       "
                  "\n                                                                           "
                  "\n                                                "
                  "\n                             /  _.-'~~~~'-._   /                           "
                  "\n                      .      .-~ /__/  /__/ ~-.         .                  "
                  "\n                           .-~   (oo)  (oo)    ~-.                         "
                  "\n                          (_____//~~////~~//______)                        "
                  "\n                     _.-~`                         `~-._                   "
                  "\n                    |O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O|     *            "
                  "\n                    |___________________________________|                  "
                  "\n                              |x x x x x x x|                              "
                  "\n                      .  *     |x_x_x_x_x_x|                               ");
  
        getch();              
        clear();
        refresh();
        return 0;
      }
      printw("\nVotre choix de poursuite taper 1 pour jouer ou 3 pour quitter");
      scanw("%d", &choix);
      clear();
      refresh();
      }
   endwin();
   
// Les instructions avant la cloture du programme
   return 0;


} //Fin du MAIN

/*-------------------------------------------------------------*/
/* DEFINITIONS DES FCTS DE GESTION DU TERMINAL */
/*-------------------------------------------------------------*/

/************************************************************/

/*  Choix des couleurs de la police et de la fen�tre CONSOLE
     cT correspond a la couleur du texte
     cF correspond a la couleur de fond
     Codes couleus :
                       0: noir
                       1: bleu fonce
                       2: vert
                       3: bleu-gris
                       4: marron
                       5: pourpre
                       6: kaki
                       7: gris clair
                       8: gris
                       9: bleu
                      10: vert fluo
                      11: turquoise
                      12: rouge
                      13: rose fluo
                      14: jaune fluo
                      15: blanc                    */
/************************************************************/
       void color(int cT,int cF)
       {
          init_pair(1,cT,cF);
         attron(COLOR_PAIR(1));
       }

  /*-----------------------------------------------------------*/
  /* Retourne la touche pressee sans bloquer le deroulement    */
  /*-----------------------------------------------------------*/
    char nb_getch()
    {
      timeout(0);
      return getch();
    }

  /*-----------------------------------------------------------*/
 /* Retourne la touche pressee en bloquant le deroulement     */
  /*-----------------------------------------------------------*/
char b_getch()
{
    timeout(-1);
    return getch();
}

  /*-----------------------------------------------------------*/
 /* Initialise l'ecran */
 /*-----------------------------------------------------------*/
 void startscr()
 {
    initscr();
    start_color();
    cbreak();
    //noecho();
    curs_set(0);
    keypad(stdscr, true);
 } 





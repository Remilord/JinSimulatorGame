#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <unistd.h>
#include <time.h>

int main(void) {
	int i,n;
	int a,b;
	int j,h;
	int r=0;
	int tourjin=0;
	int findugame=0;
	int imb=0;
	int chienaucul=0;
	int tablo[12][12]={{0}};
	int tabx[12];
	int taby[12];
	int x=1;
	int divx=0,divy=0;
	int diff;
	int menu=0;
	int quitte=0;
	InitialiserGraphique();
	CreerFenetre(0,0,600,600);
	while(menu==0) {
		EcrireTexte(50,50,"Choisissez le mode de difficulte",2); 
			EcrireTexte(150,200,"Facile",2);
			EcrireTexte(150,300,"Normal",2);
			EcrireTexte(150,400,"Hard",2);
			EcrireTexte(150,500,"Insane",2);
			if(SourisCliquee()) {
				if((_X>=140)&&(_X<=220)&&(_Y>=190)&&(_Y<=270)) {
					diff=1;
					menu=1;
				}
				if((_X>=140)&&(_X<=220)&&(_Y>=290)&&(_Y<=370)) {
					diff=2;
					menu=1;
				}
				if((_X>=140)&&(_X<=220)&&(_Y>=390)&&(_Y<=470)) {
					diff=3;
					menu=1;
				}
				if((_X>=140)&&(_X<=220)&&(_Y>=490)&&(_Y<=570)) {
					diff=4;
					menu=1;
				}
			}
		
	}
	FermerGraphique();
	InitialiserGraphique();
	CreerFenetre(0,0,600,600);
	ChargerImage("plateauj.png",0,0,0,0,600,600);
	ChoisirEcran(1);
	ChargerImage("plateauj.png",0,0,0,0,600,600);
	ChoisirEcran(0);
	for(n=0;n<=4;n++) {
		for(i=0;i<=3;i++) {
			tablo[n][i]=-1;
		}
	}
	tablo[0][3]=0;
	tablo[0][7]=-1;
	tablo[1][7]=-1;
	tablo[0][10]=-1;
	tablo[0][11]=-1;
	tablo[1][10]=-1;
	tablo[1][11]=-1;
	tablo[4][7]=-1;
	tablo[4][8]=-1;
	tablo[4][9]=-1;
	tablo[5][7]=-1;
	tablo[6][7]=-1;
	tablo[7][7]=-1;
	tablo[6][10]=-1;
	tablo[6][11]=-1;
	tablo[7][10]=-1;
	tablo[7][11]=-1;
	tablo[6][1]=-1;
	tablo[6][2]=-1;
	tablo[6][3]=-1;
	tablo[7][3]=-1;
	tablo[8][3]=-1;
	tablo[9][3]=-1;
	tablo[10][3]=-1;
	for(i=5;i<=8;i++) {
		tablo[9][i]=-1;
		tablo[10][i]=-1;
	}
	tablo[11][11]=-1;
	tablo[10][11]=-1;
	tablo[10][10]=-1;
	tablo[19][11]=-1;
	for(i=0;i<=11;i++) {
		tabx[i]=50*i;
		taby[i]=50*i;
	}
	ChargerImage("Pionu.png",tabx[6],taby[8],0,0,50,50);
	ChargerImage("jinpion.png",tabx[10],taby[4],0,0,50,50);
	a=6;
	b=8;
	j=10;
	h=4;
	while(findugame==0) {
		if((Touche()==XK_Left)&&(tablo[b][a-1]!=-1)&&(tourjin==0)) {
			if(imb==0) {
			CopierZone(1,0,0,0,600,600,0,0);
			ChargerImage("Piong.png",tabx[a-1],taby[b],0,0,50,50);
			a=a-1;
			b=b;
		} else {
			CopierZone(1,0,0,0,600,600,0,0);
			ChargerImage("Piong.png",tabx[a],taby[b],0,0,50,50);
		}
		tourjin=1;
		}
		if((Touche()==XK_Right)&&(tablo[b][a+1]!=-1)&&(tourjin==0)) {
			if(imb==0) {
			CopierZone(1,0,0,0,600,600,0,0);
			ChargerImage("Piond.png",tabx[a+1],taby[b],0,0,50,50);
			a=a+1;
			b=b;
		} else {
			CopierZone(1,0,0,0,600,600,0,0);
			ChargerImage("Piond.png",tabx[a],taby[b],0,0,50,50);
		}
		tourjin=1;
		}
		if((Touche()==XK_Up)&&(tablo[b-1][a]!=-1)&&(tourjin==0)) {
			if(imb==0) {
			CopierZone(1,0,0,0,600,600,0,0);
			ChargerImage("Pionu.png",tabx[a],taby[b-1],0,0,50,50);
			a=a;
			b=b-1;
		} else {
			CopierZone(1,0,0,0,600,600,0,0);
			ChargerImage("Pionu.png",tabx[a],taby[b],0,0,50,50);
		}
		tourjin=1;
		}
		if((Touche()==XK_Down)&(tablo[b+1][a]!=-1)&&(tourjin==0)) {
			if(imb==0) {
			CopierZone(1,0,0,0,600,600,0,0);
			ChargerImage("Pionb.png",tabx[a],taby[b+1],0,0,50,50);
			a=a;
			b=b+1;
		} else {
			CopierZone(1,0,0,0,600,600,0,0);
			ChargerImage("Pionb.png",tabx[a],taby[b],0,0,50,50);
		}
		tourjin=1;
		}
		if(tourjin==1) {
			switch(x) {
				case 0:
				ChargerImage("jinpion.png",tabx[10],taby[4],0,0,50,50);
				j=10;
				h=4;
				x=x+1;
				if((diff==2)||(diff==3)) {
					x=x+1;
				} else if(diff==4) {
					x=rand()%29;
				}
				break;
				case 1:
				ChargerImage("jinpion.png",tabx[10],taby[3],0,0,50,50);
				j=10;
				h=3;
				x=x+1;
				if((diff==2)||(diff==3)) {
					x=x+1;
				} else if(diff==4) {
					x=rand()%29;
				}
				break;
				case 2:
				ChargerImage("jinpion.png",tabx[10],taby[2],0,0,50,50);
				j=10;
				h=2;
				x=x+1;
				if((diff==2)||(diff==3)) {
					x=x+1;
				} else if(diff==4) {
					x=rand()%29;
				}
				break;
				case 3:
				ChargerImage("jinpion.png",tabx[9],taby[2],0,0,50,50);
				j=9;
				h=2;
				x=x+1;
				if((diff==2)||(diff==3)) {
					x=x+1;
				} else if(diff==4) {
					x=rand()%29;
				}
				break;
				case 4:
				ChargerImage("jinpion.png",tabx[8],taby[2],0,0,50,50);
				j=8;
				h=2;
				x=x+1;
				if((diff==2)||(diff==3)) {
					x=x+1;
				} else if(diff==4) {
					x=rand()%29;
				}
				break;
				case 5:
				ChargerImage("jinpion.png",tabx[7],taby[2],0,0,50,50);
				j=7;
				h=2;
				x=x+1;
				if((diff==2)||(diff==3)) {
					x=x+1;
				} else if(diff==4) {
					x=rand()%29;
				}
				break;
				case 6:
				ChargerImage("jinpion.png",tabx[6],taby[2],0,0,50,50);
				j=6;
				h=2;
				x=x+1;
				if((diff==2)||(diff==3)) {
					x=x+1;
				} else if(diff==4) {
					x=rand()%29;
				}
				break;
				case 7:
				ChargerImage("jinpion.png",tabx[5],taby[2],0,0,50,50);
				j=5;
				h=2;
				x=x+1;
				if((diff==2)||(diff==3)) {
					x=x+1;
				} else if(diff==4) {
					x=rand()%29;
				}
				break;
				case 8:
				ChargerImage("jinpion.png",tabx[5],taby[3],0,0,50,50);
				j=5;
				h=3;
				x=x+1;
				if((diff==2)||(diff==3)) {
					x=x+1;
				} else if(diff==4) {
					x=rand()%29;
				}
				break;
				case 9:
				ChargerImage("jinpion.png",tabx[5],taby[4],0,0,50,50);
				j=5;
				h=4;
				x=x+1;
				if((diff==2)||(diff==3)) {
					x=x+1;
				} else if(diff==4) {
					x=rand()%29;
				}
				break;
				case 10:
				ChargerImage("jinpion.png",tabx[5],taby[5],0,0,50,50);
				j=5;
				h=5;
				x=x+1;
				if((diff==2)||(diff==3)) {
					x=x+1;
				} else if(diff==4) {
					x=rand()%29;
				}
				break;
				case 11:
				ChargerImage("jinpion.png",tabx[5],taby[6],0,0,50,50);
				j=5;
				h=6;
				x=x+1;
				if((diff==2)||(diff==3)) {
					x=x+1;
				} else if(diff==4) {
					x=rand()%29;
				}
				break;
				case 12:
				ChargerImage("jinpion.png",tabx[5],taby[7],0,0,50,50);
				j=5;
				h=7;
				x=x+1;
				if((diff==2)||(diff==3)) {
					x=x+1;
				} else if(diff==4) {
					x=rand()%29;
				}
				break;
				case 13:
				ChargerImage("jinpion.png",tabx[5],taby[8],0,0,50,50);
				j=5;
				h=8;
				x=x+1;
				if((diff==2)||(diff==3)) {
					x=x+1;
				} else if(diff==4) {
					x=rand()%29;
				}
				break;
				case 14:
				ChargerImage("jinpion.png",tabx[4],taby[9],0,0,50,50);
				j=4;
				h=9;
				x=x+1;
				if((diff==2)||(diff==3)) {
					x=x+1;
				} else if(diff==4) {
					x=rand()%29;
				}
				break;
				case 15:
				ChargerImage("jinpion.png",tabx[4],taby[10],0,0,50,50);
				j=4;
				h=10;
				x=x+1;
				if((diff==2)||(diff==3)) {
					x=x+1;
				} else if(diff==4) {
					x=rand()%29;
				}
				break;
				case 16:
				ChargerImage("jinpion.png",tabx[4],taby[11],0,0,50,50);
				j=4;
				h=11;
				x=x+1;
				if((diff==2)||(diff==3)) {
					x=x+1;
				} else if(diff==4) {
					x=rand()%29;
				}
				break;
				case 17:
				ChargerImage("jinpion.png",tabx[5],taby[11],0,0,50,50);
				j=5;
				h=11;
				x=x+1;
				if((diff==2)||(diff==3)) {
					x=x+1;
				} else if(diff==4) {
					x=rand()%29;
				}
				break;
				case 18:
				ChargerImage("jinpion.png",tabx[6],taby[11],0,0,50,50);
				j=6;
				h=11;
				x=x+1;
				if((diff==2)||(diff==3)) {
					x=x+1;
				} else if(diff==4) {
					x=rand()%29;
				}
				break;
				case 19:
				ChargerImage("jinpion.png",tabx[7],taby[11],0,0,50,50);
				j=7;
				h=11;
				x=x+1;
				if((diff==2)||(diff==3)) {
					x=x+1;
				} else if(diff==4) {
					x=rand()%29;
				}
				break;
				case 20:
				ChargerImage("jinpion.png",tabx[8],taby[11],0,0,50,50);
				j=8;
				h=11;
				x=x+1;
				if((diff==2)||(diff==3)) {
					x=x+1;
				} else if(diff==4) {
					x=rand()%29;
				}
				break;
				case 21:
				ChargerImage("jinpion.png",tabx[9],taby[11],0,0,50,50);
				j=9;
				h=11;
				x=x+1;
				if((diff==2)||(diff==3)) {
					x=x+1;
				} else if(diff==4) {
					x=rand()%29;
				}
				break;
				case 22:
				ChargerImage("jinpion.png",tabx[9],taby[10],0,0,50,50);
				j=9;
				h=10;
				x=x+1;
				if((diff==2)||(diff==3)) {
					x=x+1;
				} else if(diff==4) {
					x=rand()%29;
				}
				break;
				case 23:
				ChargerImage("jinpion.png",tabx[9],taby[9],0,0,50,50);
				j=9;
				h=9;
				x=x+1;
				if((diff==2)||(diff==3)) {
					x=x+1;
				} else if(diff==4) {
					x=rand()%29;
				}
				break;
				case 24:
				ChargerImage("jinpion.png",tabx[9],taby[8],0,0,50,50);
				j=9;
				h=8;
				x=x+1;
				if((diff==2)||(diff==3)) {
					x=x+1;
				} else if(diff==4) {
					x=rand()%29;
				}
				break;
				case 25:
				ChargerImage("jinpion.png",tabx[9],taby[7],0,0,50,50);
				j=9;
				h=7;
				x=x+1;
				if((diff==2)||(diff==3)) {
					x=x+1;
				} else if(diff==4) {
					x=rand()%29;
				}
				break;
				case 26:
				ChargerImage("jinpion.png",tabx[9],taby[6],0,0,50,50);
				j=9;
				h=6;
				x=x+1;
				if((diff==2)||(diff==3)) {
					x=x+1;
				} else if(diff==4) {
					x=rand()%29;
				}
				break;
				case 27:
				ChargerImage("jinpion.png",tabx[9],taby[5],0,0,50,50);
				j=9;
				h=5;
				x=x+1;
				if((diff==2)||(diff==3)) {
					x=x+1;
				} else if(diff==4) {
					x=rand()%29;
				}
				break;
				case 28:
				ChargerImage("jinpion.png",tabx[10],taby[5],0,0,50,50);
				j=10;
				h=5;
				x=0;
				break;
				case 29:
				ChargerImage("jinpion.png",tabx[a],taby[b],0,0,50,50);
				j=a;
				h=b;
				break;
			}
			tourjin=0;
		}
		if((diff==3)||(diff==4)) {
			r=rand()%3;
			if(r==0) {
				ChargerImage("divpion.png",tabx[5],taby[5],0,0,50,50);
				divx=5;
				divy=5;
			}
			if(r==1) {
				ChargerImage("divpion.png",tabx[10],taby[4],0,0,50,50);
				divx=10;
				divy=4;
			}
			if(r==2) {
				ChargerImage("divpion.png",tabx[10],taby[11],0,0,50,50);
				divx=10;
				divy=11;
			}
		}
		if((diff==1)||(diff==2)) {
		if((tabx[a]==tabx[j])||(tabx[a-1]==tabx[j])||(tabx[a+1]==tabx[j])) {
			if((taby[b]==taby[h])||(taby[b-1]==taby[h])||(taby[b+1]==taby[h])) {
				chienaucul=1;
				x=29;
			}
		}
	}
	if((diff==3)||(diff==4)) {
		if((tabx[a]==tabx[j])||(tabx[a-1]==tabx[j])||(tabx[a+1]==tabx[j])||(tabx[a-2]==tabx[j])||(tabx[a+2]==tabx[j])) {
			if((taby[b]==taby[h])||(taby[b-1]==taby[h])||(taby[b+1]==taby[h])||(taby[b-2]==tabx[h])||(taby[b+2]==tabx[h])) {
				chienaucul=1;
				x=29;
			}
		}
	}
		if((tabx[a]==150)&&(taby[b]==250)&&(chienaucul==1)) {
		chienaucul=0;
		x=10;
}
if((tabx[a]==150)&&(taby[b]==550)&&(chienaucul==1)) {
		chienaucul=0;
		x=16;
}
		if((tabx[a]==150)&&(taby[b]==0)&&(chienaucul==1)) {
			ChargerImage("whaouf.png",tabx[j-1],taby[h+1],0,0,200,100);
			findugame=1;
			sleep(2);
		}
		if((tabx[a]==150)&&(taby[b]==0)&&(chienaucul==0)) {
			findugame=2;
		}
	}
	FermerGraphique();
	InitialiserGraphique();
		CreerFenetre(0,0,600,600);
	while(quitte==0) {
		if(findugame==1) {
			EcrireTexte(50,250,"JIIIIIIIIINNNNNNNN ! Chien de merde",2);
		}
		if (findugame==2) 
		{
			EcrireTexte(50,250,"GG vous avez esquive Jin",2);
		}
		EcrireTexte(50,400,"QUITTER",2);
		if(SourisCliquee()) {
			if ((_X>=50)&&(_X<=250)&&(_Y>=300)&&(_Y<=500)) {
				quitte=1;
			}
		}
		}
	FermerGraphique();
}
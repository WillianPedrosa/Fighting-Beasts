/*
	Jogo 2ªSemestre - Grupo 7
	
	Guilherme Rocha Pedrina
	Josué Eduardo Menezes Jr.
	Willian dos Santos Pedroza 
*/

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<time.h>
#include<windows.h>

#define ESC 27
#define a 97   
#define d 100
#define s 115
#define w 119
#define chao 600
#define borda 5

struct TAnimacao{
    int QtdeSprites;
    void **Mask, **Sprite;
};

struct TPlayer{
	int X1, X2;
	int Y1, Y2;
	//int *Golpes;
	int QdeGolpes;
	int Dano;
	int R,G,B;
	int GravP;
	int VelocX, VelocY;
	int ForcaP;
	int Vida, Stamina;
};

struct TDesenho {
	int X1, X2;
	int Y1, Y2;
};

// Struct dedicada para todas as imagens únicas
struct THud{
	void **Sprite, **Mask;
};

struct TImagens{
	void  **SpriteMask;
};

//Structs do galo
TAnimacao IdleG;
TAnimacao IdleGMirror;
TAnimacao AndandoG;
TAnimacao AndandoGMirror;
TAnimacao PuloG;
TAnimacao PuloGMirror;
TAnimacao SocoG;
TAnimacao SocoGMirror;
TAnimacao ChuteG;
TAnimacao ChuteGMirror;
TAnimacao AntiAerioG;
TAnimacao AntiAerioGMirror;
TAnimacao DanoG;
TAnimacao DanoGMirror;
TAnimacao KnockBackG;
TAnimacao KnockBackGMirror;
TAnimacao DerrotaG;
TAnimacao DerrotaGMirror;
TAnimacao GanchoG;
TAnimacao GanchoGMirror;
TAnimacao LevantaG;
TAnimacao LevantaGMirror;

//Structs do suricato
TAnimacao IdleS;
TAnimacao IdleSMirror;
TAnimacao AndandoS;
TAnimacao AndandoSMirror;
TAnimacao PuloS;
TAnimacao PuloSMirror;
TAnimacao SocoS;
TAnimacao SocoSMirror;
TAnimacao ChuteS;
TAnimacao ChuteSMirror;
TAnimacao AntiAerioS;
TAnimacao AntiAerioSMirror;
TAnimacao DanoS;
TAnimacao DanoSMirror;
TAnimacao KnockBackS;
TAnimacao KnockBackSMirror;
TAnimacao DerrotaS;
TAnimacao DerrotaSMirror;
TAnimacao GanchoS;
TAnimacao GanchoSMirror;
TAnimacao LevantaS;
TAnimacao LevantaSMirror;

// Vetores de animações únicas
void *AgacharG;
void *AgacharGMask;
void *AgacharGMirror;
void *AgacharGMirrorMask;
void *DefesaG;
void *DefesaGMask;
void *DefesaGMirror;
void *DefesaGMirrorMask;

void *AgacharS;
void *AgacharSMask;
void *AgacharSMirror;
void *AgacharSMirrorMask;
void *DefesaS;
void *DefesaSMask;
void *DefesaSMirror;
void *DefesaSMirrorMask;

// ELEMENTOS DA HUD / BOTÕES!!! ==============
THud Hud;
THud BarraVida;
THud BarraStamina;
THud Vitoria;
THud Icones;

TImagens Round1;
TImagens Round2;
TImagens Round3;
TImagens Round4;
TImagens Round5;
TImagens Tempo;
TImagens VitoriaJog1;
TImagens VitoriaJog2;
TImagens Rematch;
TImagens VoltarMenu;

TImagens btnJogar;
TImagens btnComandos;
TImagens btnSair;

// Outras Telas
TImagens Pausado;
TImagens Cenario;
TImagens MenuPrin;
TImagens TutorialComandos;

int LarTela, AltTela;
int BtnLar, BtnAlt;
int QdeImg = 4;

void TelaInicial();
void Jogar();



int main (){
	LarTela = 1000;
	AltTela = 700;
	
	int imgTamanhoX = 300;
	int imgTamanhoY = 300;
	int tam,i,xt,xt1;
	int pg = 1, pg2 = 2;
	
	//Carregando as HUDs
	int QtdeElementosHud = 2;
	int HudX = 400, HudY = 120;
	int BarraX = 293, BarraY = 32;
	int BarraStamY = 13;
	int VitRoundX = 12, VitRoundY = 24;
	int IconeX = 95, IconeY = 100;
	
	//Outras Imagens
	int RoundX = 200, RoundY = 110;
	int JogGanhouX = 220, JogGanhouY = 130;
	int BotMenuX = 152, BotMenuY = 87;
	
	// HUD
	Hud.Mask = (void **)malloc(sizeof(void*) * QtdeElementosHud);
	Hud.Sprite = (void **)malloc(sizeof(void*) * QtdeElementosHud);
	BarraVida.Mask = (void **)malloc(sizeof(void*) * QtdeElementosHud);
	BarraVida.Sprite = (void **)malloc(sizeof(void*) * QtdeElementosHud);
	BarraStamina.Mask = (void **)malloc(sizeof(void*) * QtdeElementosHud);
	BarraStamina.Sprite = (void **)malloc(sizeof(void*) * QtdeElementosHud);
	Vitoria.Mask = (void **)malloc(sizeof(void*) * QtdeElementosHud);
	Vitoria.Sprite = (void **)malloc(sizeof(void*) * QtdeElementosHud);
	Icones.Mask = (void **)malloc(sizeof(void*) * QtdeElementosHud);
	Icones.Sprite = (void **)malloc(sizeof(void*) * QtdeElementosHud);
	
	// Botões
	btnJogar.SpriteMask = (void **)malloc(sizeof(void*) * 2);
	btnComandos.SpriteMask = (void **)malloc(sizeof(void*) * 2);
	btnSair.SpriteMask = (void **)malloc(sizeof(void*) * 2);
	
	// Indicações In Game
	Round1.SpriteMask = (void **)malloc(sizeof(void*) * 2);
	Round2.SpriteMask = (void **)malloc(sizeof(void*) * 2);
	Round3.SpriteMask = (void **)malloc(sizeof(void*) * 2);
	Round4.SpriteMask = (void **)malloc(sizeof(void*) * 2);
	Round5.SpriteMask = (void **)malloc(sizeof(void*) * 2);
	Tempo.SpriteMask = (void **)malloc(sizeof(void*) * 2);
	VitoriaJog1.SpriteMask = (void **)malloc(sizeof(void*) * 2);
	VitoriaJog2.SpriteMask = (void **)malloc(sizeof(void*) * 2);
	Rematch.SpriteMask = (void **)malloc(sizeof(void*) * 2);
	VoltarMenu.SpriteMask = (void **)malloc(sizeof(void*) * 2);
	Pausado.SpriteMask = (void **)malloc(sizeof(void*) * 2);
	
	// Cenário, Menu e comandos
	Cenario.SpriteMask = (void**)malloc(sizeof(void*) * 1);
	MenuPrin.SpriteMask = (void**)malloc(sizeof(void*) * 1);
	TutorialComandos.SpriteMask = (void**)malloc(sizeof(void*) * 1);
	
	// Animações
	// Galo
	IdleG.QtdeSprites = 4;
	IdleGMirror.QtdeSprites = 4;
	AndandoG.QtdeSprites = 5;
	AndandoGMirror.QtdeSprites = 5;
	PuloG.QtdeSprites = 5;
	PuloGMirror.QtdeSprites = 5;
	SocoG.QtdeSprites = 5; 
	SocoGMirror.QtdeSprites = 5;
	ChuteG.QtdeSprites = 5;
	ChuteGMirror.QtdeSprites = 5;
	AntiAerioG.QtdeSprites = 6;
	AntiAerioGMirror.QtdeSprites = 6;
	DanoG.QtdeSprites = 5;
	DanoGMirror.QtdeSprites = 5;
	KnockBackG.QtdeSprites = 0;
	KnockBackGMirror.QtdeSprites = 0;
	DerrotaG.QtdeSprites = 5;
	DerrotaGMirror.QtdeSprites = 5;
	GanchoG.QtdeSprites = 5;
	GanchoGMirror.QtdeSprites = 5;
	LevantaG.QtdeSprites = 4;
	LevantaGMirror.QtdeSprites = 4;
	
	// Suricato
	IdleS.QtdeSprites = 4;
	IdleSMirror.QtdeSprites = 4;
	AndandoS.QtdeSprites = 5;
	AndandoSMirror.QtdeSprites = 5;
	PuloS.QtdeSprites = 5;
	PuloSMirror.QtdeSprites = 5;
	SocoS.QtdeSprites = 5; 
	SocoSMirror.QtdeSprites = 5;
	ChuteS.QtdeSprites = 5;
	ChuteSMirror.QtdeSprites = 5;
	AntiAerioS.QtdeSprites = 5;
	AntiAerioSMirror.QtdeSprites = 5;
	DanoS.QtdeSprites = 5;
	DanoSMirror.QtdeSprites = 5;
	KnockBackS.QtdeSprites = 0;
	KnockBackSMirror.QtdeSprites = 0;
	DerrotaS.QtdeSprites = 5;
	DerrotaSMirror.QtdeSprites = 5;
	GanchoS.QtdeSprites = 5;
	GanchoSMirror.QtdeSprites = 5;
	LevantaS.QtdeSprites = 4;
	LevantaSMirror.QtdeSprites = 4;
	
	// Galo
	IdleG.Mask = (void **)malloc(sizeof(void*) * IdleG.QtdeSprites);
	IdleG.Sprite = (void **)malloc(sizeof(void*) * IdleG.QtdeSprites);
	IdleGMirror.Mask = (void **)malloc(sizeof(void*) * IdleGMirror.QtdeSprites);
	IdleGMirror.Sprite = (void **)malloc(sizeof(void*) * IdleGMirror.QtdeSprites);
	
	AndandoG.Mask = (void **)malloc(sizeof(void*) * AndandoG.QtdeSprites);
	AndandoG.Sprite = (void **)malloc(sizeof(void*) * AndandoG.QtdeSprites);
	AndandoGMirror.Mask = (void **)malloc(sizeof(void*) * AndandoGMirror.QtdeSprites);
	AndandoGMirror.Sprite = (void **)malloc(sizeof(void*) * AndandoGMirror.QtdeSprites);
	
	PuloG.Mask = (void **)malloc(sizeof(void*) * PuloG.QtdeSprites);
	PuloG.Sprite = (void **)malloc(sizeof(void*) * PuloG.QtdeSprites);
	PuloGMirror.Mask = (void **)malloc(sizeof(void*) * PuloGMirror.QtdeSprites);
	PuloGMirror.Sprite = (void **)malloc(sizeof(void*) * PuloGMirror.QtdeSprites);
	
	SocoG.Mask = (void **)malloc(sizeof(void*) * SocoG.QtdeSprites);
	SocoG.Sprite = (void **)malloc(sizeof(void*) * SocoG.QtdeSprites);
	SocoGMirror.Mask = (void **)malloc(sizeof(void*) * SocoGMirror.QtdeSprites);
	SocoGMirror.Sprite = (void **)malloc(sizeof(void*) * SocoGMirror.QtdeSprites);
	
	ChuteG.Mask = (void **)malloc(sizeof(void*) * ChuteG.QtdeSprites);
	ChuteG.Sprite = (void **)malloc(sizeof(void*) * ChuteG.QtdeSprites);
	ChuteGMirror.Mask = (void **)malloc(sizeof(void*) * ChuteGMirror.QtdeSprites);
	ChuteGMirror.Sprite = (void **)malloc(sizeof(void*) * ChuteGMirror.QtdeSprites);
	
	DanoG.Mask = (void **)malloc(sizeof(void*) * DanoG.QtdeSprites);
	DanoG.Sprite = (void **)malloc(sizeof(void*) * DanoG.QtdeSprites);
	DanoGMirror.Mask = (void **)malloc(sizeof(void*) * DanoGMirror.QtdeSprites);
	DanoGMirror.Sprite = (void **)malloc(sizeof(void*) * DanoGMirror.QtdeSprites);
	
	GanchoG.Mask = (void **)malloc(sizeof(void*) * GanchoG.QtdeSprites);
	GanchoG.Sprite = (void **)malloc(sizeof(void*) * GanchoG.QtdeSprites);
	GanchoGMirror.Mask = (void **)malloc(sizeof(void*) * GanchoGMirror.QtdeSprites);
	GanchoGMirror.Sprite = (void **)malloc(sizeof(void*) * GanchoGMirror.QtdeSprites);
	
	LevantaG.Mask = (void **)malloc(sizeof(void*) * LevantaG.QtdeSprites);
	LevantaG.Sprite = (void **)malloc(sizeof(void*) * LevantaG.QtdeSprites);
	LevantaGMirror.Mask = (void **)malloc(sizeof(void*) * LevantaGMirror.QtdeSprites);
	LevantaGMirror.Sprite = (void **)malloc(sizeof(void*) * LevantaGMirror.QtdeSprites);
	
	
	// Suricato
	IdleS.Mask = (void **)malloc(sizeof(void*) * IdleS.QtdeSprites);
	IdleS.Sprite = (void **)malloc(sizeof(void*) * IdleS.QtdeSprites);
	IdleSMirror.Mask = (void **)malloc(sizeof(void*) * IdleSMirror.QtdeSprites);
	IdleSMirror.Sprite = (void **)malloc(sizeof(void*) * IdleSMirror.QtdeSprites);
	
	AndandoS.Mask = (void **)malloc(sizeof(void*) * AndandoS.QtdeSprites);
	AndandoS.Sprite = (void **)malloc(sizeof(void*) * AndandoS.QtdeSprites);
	AndandoSMirror.Mask = (void **)malloc(sizeof(void*) * AndandoSMirror.QtdeSprites);
	AndandoSMirror.Sprite = (void **)malloc(sizeof(void*) * AndandoSMirror.QtdeSprites);
	
	PuloS.Mask = (void **)malloc(sizeof(void*) * PuloS.QtdeSprites);
	PuloS.Sprite = (void **)malloc(sizeof(void*) * PuloS.QtdeSprites);
	PuloSMirror.Mask = (void **)malloc(sizeof(void*) * PuloSMirror.QtdeSprites);
	PuloSMirror.Sprite = (void **)malloc(sizeof(void*) * PuloSMirror.QtdeSprites);
	
	SocoS.Mask = (void **)malloc(sizeof(void*) * SocoS.QtdeSprites);
	SocoS.Sprite = (void **)malloc(sizeof(void*) * SocoS.QtdeSprites);
	SocoSMirror.Mask = (void **)malloc(sizeof(void*) * SocoSMirror.QtdeSprites);
	SocoSMirror.Sprite = (void **)malloc(sizeof(void*) * SocoSMirror.QtdeSprites);
	
	ChuteS.Mask = (void **)malloc(sizeof(void*) * ChuteS.QtdeSprites);
	ChuteS.Sprite = (void **)malloc(sizeof(void*) * ChuteS.QtdeSprites);
	ChuteSMirror.Mask = (void **)malloc(sizeof(void*) * ChuteSMirror.QtdeSprites);
	ChuteSMirror.Sprite = (void **)malloc(sizeof(void*) * ChuteSMirror.QtdeSprites);
	
	DanoS.Mask = (void **)malloc(sizeof(void*) * DanoS.QtdeSprites);
	DanoS.Sprite = (void **)malloc(sizeof(void*) * DanoS.QtdeSprites);
	DanoSMirror.Mask = (void **)malloc(sizeof(void*) * DanoSMirror.QtdeSprites);
	DanoSMirror.Sprite = (void **)malloc(sizeof(void*) * DanoSMirror.QtdeSprites);
	
	GanchoS.Mask = (void **)malloc(sizeof(void*) * GanchoS.QtdeSprites);
	GanchoS.Sprite = (void **)malloc(sizeof(void*) * GanchoS.QtdeSprites);
	GanchoSMirror.Mask = (void **)malloc(sizeof(void*) * GanchoSMirror.QtdeSprites);
	GanchoSMirror.Sprite = (void **)malloc(sizeof(void*) * GanchoSMirror.QtdeSprites);
	
	LevantaS.Mask = (void **)malloc(sizeof(void*) * LevantaS.QtdeSprites);
	LevantaS.Sprite = (void **)malloc(sizeof(void*) * LevantaS.QtdeSprites);
	LevantaSMirror.Mask = (void **)malloc(sizeof(void*) * LevantaSMirror.QtdeSprites);
	LevantaSMirror.Sprite = (void **)malloc(sizeof(void*) * LevantaSMirror.QtdeSprites);
		
	/*
	QtdeElementos = 2;
	Hud = (void **) malloc(sizeof(void*) * QtdeElementos);
	HudMask = (void **) malloc(sizeof(void*) * QtdeElementos);
	*/
	
	//============= Tela caraga imagem ============ 
	initwindow(1000,700,"Chamando imagens",150,10);
	
	// Trocando as telas para esconder as imagens sendo carregadas
	readimagefile(".\\img\\Carregando.bmp", 0, 0, 1000, 700);
	
	setactivepage(pg2);
	

	//Alocando memoria
	
	// Animações ================================
	// Galo
	tam = imagesize(0,0, imgTamanhoX,imgTamanhoY);
	for(i = 0; i < IdleG.QtdeSprites; i++){
		IdleG.Sprite[i] = malloc(tam);
		IdleG.Mask[i] = malloc(tam);
		IdleGMirror.Sprite[i] = malloc(tam);
		IdleGMirror.Mask[i] = malloc(tam);
	}
	
	
	for(i = 0; i < AndandoG.QtdeSprites; i++){
		AndandoG.Sprite[i] = malloc(tam);
		AndandoG.Mask[i] = malloc(tam);
		AndandoGMirror.Sprite[i] = malloc(tam);
		AndandoGMirror.Mask[i] = malloc(tam);
	}
	
	for(i = 0; i < PuloG.QtdeSprites; i++){
		PuloG.Sprite[i] = malloc(tam);
		PuloG.Mask[i] = malloc(tam);
		PuloGMirror.Sprite[i] = malloc(tam);
		PuloGMirror.Mask[i] = malloc(tam);
	}
	
	for(i = 0; i < SocoG.QtdeSprites; i++){
		SocoG.Sprite[i] = malloc(tam);
		SocoG.Mask[i] = malloc(tam);
		SocoGMirror.Sprite[i] = malloc(tam);
		SocoGMirror.Mask[i] = malloc(tam);
	}
	
	for(i = 0; i < ChuteG.QtdeSprites; i++){
		ChuteG.Sprite[i] = malloc(tam);
		ChuteG.Mask[i] = malloc(tam);
		ChuteGMirror.Sprite[i] = malloc(tam);
		ChuteGMirror.Mask[i] = malloc(tam);
	}
	
	for(i = 0; i < DanoG.QtdeSprites; i++){
		DanoG.Sprite[i] = malloc(tam);
		DanoG.Mask[i] = malloc(tam);
		DanoGMirror.Sprite[i] = malloc(tam);
		DanoGMirror.Mask[i] = malloc(tam);
	}
	
	for(i = 0; i < GanchoG.QtdeSprites; i++){
		GanchoG.Sprite[i] = malloc(tam);
		GanchoG.Mask[i] = malloc(tam);
		GanchoGMirror.Sprite[i] = malloc(tam);
		GanchoGMirror.Mask[i] = malloc(tam);
	}
	
	for(i = 0; i < LevantaG.QtdeSprites; i++){
		LevantaG.Sprite[i] = malloc(tam);
		LevantaG.Mask[i] = malloc(tam);
		LevantaGMirror.Sprite[i] = malloc(tam);
		LevantaGMirror.Mask[i] = malloc(tam);
	}

	AgacharG = malloc(tam);
	AgacharGMask = malloc(tam);
	AgacharGMirror = malloc(tam);
	AgacharGMirrorMask = malloc(tam);
		
	DefesaG = malloc(tam);
	DefesaGMask = malloc(tam);
	DefesaGMirror = malloc(tam);
	DefesaGMirrorMask = malloc(tam);
	
	
	// Suricato
	for(i = 0; i < IdleS.QtdeSprites; i++){
		IdleS.Sprite[i] = malloc(tam);
		IdleS.Mask[i] = malloc(tam);
		IdleSMirror.Sprite[i] = malloc(tam);
		IdleSMirror.Mask[i] = malloc(tam);
	}
	
	
	for(i = 0; i < AndandoS.QtdeSprites; i++){
		AndandoS.Sprite[i] = malloc(tam);
		AndandoS.Mask[i] = malloc(tam);
		AndandoSMirror.Sprite[i] = malloc(tam);
		AndandoSMirror.Mask[i] = malloc(tam);
	}
	
	for(i = 0; i < PuloS.QtdeSprites; i++){
		PuloS.Sprite[i] = malloc(tam);
		PuloS.Mask[i] = malloc(tam);
		PuloSMirror.Sprite[i] = malloc(tam);
		PuloSMirror.Mask[i] = malloc(tam);
	}
	
	for(i = 0; i < SocoS.QtdeSprites; i++){
		SocoS.Sprite[i] = malloc(tam);
		SocoS.Mask[i] = malloc(tam);
		SocoSMirror.Sprite[i] = malloc(tam);
		SocoSMirror.Mask[i] = malloc(tam);
	}
	
	for(i = 0; i < ChuteS.QtdeSprites; i++){
		ChuteS.Sprite[i] = malloc(tam);
		ChuteS.Mask[i] = malloc(tam);
		ChuteSMirror.Sprite[i] = malloc(tam);
		ChuteSMirror.Mask[i] = malloc(tam);
	}
	
	for(i = 0; i < DanoS.QtdeSprites; i++){
		DanoS.Sprite[i] = malloc(tam);
		DanoS.Mask[i] = malloc(tam);
		DanoSMirror.Sprite[i] = malloc(tam);
		DanoSMirror.Mask[i] = malloc(tam);
	}
	
	for(i = 0; i < GanchoS.QtdeSprites; i++){
		GanchoS.Sprite[i] = malloc(tam);
		GanchoS.Mask[i] = malloc(tam);
		GanchoSMirror.Sprite[i] = malloc(tam);
		GanchoSMirror.Mask[i] = malloc(tam);
	}

	for(i = 0; i < LevantaS.QtdeSprites; i++){
		LevantaS.Sprite[i] = malloc(tam);
		LevantaS.Mask[i] = malloc(tam);
		LevantaSMirror.Sprite[i] = malloc(tam);
		LevantaSMirror.Mask[i] = malloc(tam);
	}

	AgacharS = malloc(tam);
	AgacharSMask = malloc(tam);
	AgacharSMirror = malloc(tam);
	AgacharSMirrorMask = malloc(tam);
		
	DefesaS = malloc(tam);
	DefesaSMask = malloc(tam);
	DefesaSMirror = malloc(tam);
	DefesaSMirrorMask = malloc(tam);
	
	// ================================
		
	// Hud
	for(i = 0; i < 2; i++){
		Hud.Mask[i] = malloc(imagesize(0, 0, HudX, HudY));
		Hud.Sprite[i] = malloc(imagesize(0, 0, HudX, HudY));
		BarraVida.Mask[i] = malloc(imagesize(0, 0, BarraX, BarraY));
		BarraVida.Sprite[i] = malloc(imagesize(0, 0, BarraX, BarraY));
		BarraStamina.Mask[i] = malloc(imagesize(0, 0, BarraX, BarraStamY));
		BarraStamina.Sprite[i] = malloc(imagesize(0, 0, BarraX, BarraStamY));
		Vitoria.Mask[i] = malloc(imagesize(0, 0, VitRoundX, VitRoundY));
		Vitoria.Sprite[i] = malloc(imagesize(0, 0, VitRoundX, VitRoundY));
	}

	// Icones
	tam = imagesize(0, 0, IconeX, IconeY);
	for(i = 0; i < 2; i++){
		Icones.Mask[i] = malloc(tam);
		Icones.Sprite[i] = malloc(tam);
	}

	//Imagens
	//Balões de Rounds
	tam = imagesize(0, 0, 200, 110);
	for(i = 0; i < 2; i++){
		Round1.SpriteMask[i] = malloc(tam);
		Round2.SpriteMask[i] = malloc(tam);
		Round3.SpriteMask[i] = malloc(tam);
		Round4.SpriteMask[i] = malloc(tam);
		Round5.SpriteMask[i] = malloc(tam);
	}
	
	//Indicador de Vitoria - Botões de fim de jogo
	tam = imagesize(0, 0, 220, 130);
	for(i = 0; i < 2; i++){
		VitoriaJog1.SpriteMask[i] = malloc(tam);
		VitoriaJog2.SpriteMask[i] = malloc(tam);
		Rematch.SpriteMask[i] = malloc(tam);
		VoltarMenu.SpriteMask[i] = malloc(tam);
	}
	
	// Botões do Menu Inicial
	tam = imagesize(0, 0, BotMenuX, BotMenuY);
	for(i = 0; i < 2; i++){
		btnJogar.SpriteMask[i] = malloc(tam);
		btnComandos.SpriteMask[i] = malloc(tam);
		btnSair.SpriteMask[i] = malloc(tam);
	}

	// Tempo
	tam = imagesize(0, 0, 112, 65);
	for(i = 0; i < 2; i++){
		Tempo.SpriteMask[i] = malloc(tam);
	}

	// Tela de Pausado - Cenário
	tam = imagesize(0, 0, LarTela, AltTela);
	for(i = 0; i < 2; i++){
		Pausado.SpriteMask[i] = malloc(tam);
	}
	Cenario.SpriteMask[0] = malloc(tam);
	MenuPrin.SpriteMask[0] = malloc(tam);
	TutorialComandos.SpriteMask[0] = malloc(tam);
	
	// ============== FIM DOS MALLOCS ===============

	//Carregar Imagem
	

	//============= Elementos da HUD ===============
	readimagefile(".\\img\\Huds\\Hud.bmp", 0, 0, 399, 353);
	
	// Huds
	
	for(i = 0; i < 2; i++){
		getimage(0, HudY*i, HudX-1, HudY*(i+1)-1, Hud.Sprite[i]);    // Hud
		getimage(0, HudY*2+(BarraY*i), BarraX-1, HudY*2+BarraY*(i+1)-1, BarraVida.Sprite[i]);    // Barra de Vida
		getimage(0, HudY*2+BarraY*2+(BarraStamY*i), BarraX-1, HudY*2+BarraY*2+BarraStamY*(i+1)-1, BarraStamina.Sprite[i]);    // Barra de Stamina
		getimage(0+VitRoundX*i, HudY*2+BarraY*2+BarraStamY*2,
		         VitRoundX*(i+1)-1, HudY*2+BarraY*2+BarraStamY*2+VitRoundY-1, Vitoria.Sprite[i]);    // Indicador de vitória de round
	}

	readimagefile(".\\img\\Huds\\HudNegativo.bmp", 0, 0, 399, 353);
	
	for(i = 0; i < 2; i++){
		getimage(0, HudY*i, HudX-1, HudY*(i+1)-1, Hud.Mask[i]);    // Hud
		getimage(0+VitRoundX*i, HudY*2+BarraY+BarraStamY,
		         VitRoundX*(i+1)-1, HudY*2+BarraY+BarraStamY+VitRoundY-1, Vitoria.Mask[i]);    // Indicador de vitória de round
	}
	getimage(0, HudY*2, BarraX-1, HudY*2+BarraY-1, BarraVida.Mask[0]);    // Barra de Vida
	getimage(0, HudY*2+BarraY, BarraX-1, HudY*2+BarraY+BarraStamY*-1, BarraStamina.Mask[0]);    // Barra de Stamina
	// Como a imagem só possue uma barra que serve para ambas as situações, esses dois ficam fora do loop

	// Icones		
	readimagefile(".\\img\\Huds\\Icons.bmp",0,0,190,100);
	for(i=0; i<2; i++){
		getimage(0+IconeX*i, 0, IconeX*(i+1)-1, IconeY-1, Icones.Sprite[i]);
	}

	readimagefile(".\\img\\Huds\\IconsNegativo.bmp",0,0,190,100);
	for(i=0; i<2; i++){
		getimage(0+IconeX*i, 0, IconeX*(i+1)-1, IconeY-1, Icones.Mask[i]);
	}
	// ======= FIM HUD ========
	
	// ================== OUTRAS IMAGENS ====================
	// Usando FOR para percorrer a imagem inteira, e IF/ELSE para mudar de imagem dos sprites para a mascara
	for(i=0; i<2; i++){
		if (i < 1){
			readimagefile(".\\img\\BotoesTelas.bmp", 0, 0, 572, 549);
		}
		else {
			readimagefile(".\\img\\BotoesTelasMask.bmp", 0, 0, 572, 549);
		}
		getimage(0, RoundY*0, RoundX-1, RoundY*1-1, Round1.SpriteMask[i]);
		getimage(0, RoundY*1, RoundX-1, RoundY*2-1, Round2.SpriteMask[i]);
		getimage(0, RoundY*2, RoundX-1, RoundY*3-1, Round3.SpriteMask[i]);
		getimage(0, RoundY*3, RoundX-1, RoundY*4-1, Round4.SpriteMask[i]);
		getimage(0, RoundY*4, RoundX-1, RoundY*5-1, Round5.SpriteMask[i]);
		getimage(RoundX, JogGanhouY*0, RoundX+JogGanhouX-1, JogGanhouY*1-1, VitoriaJog1.SpriteMask[i]);
		getimage(RoundX, JogGanhouY*1, RoundX+JogGanhouX-1, JogGanhouY*2-1, VitoriaJog2.SpriteMask[i]);
		getimage(RoundX, JogGanhouY*2, RoundX+JogGanhouX-1, JogGanhouY*3-1, Rematch.SpriteMask[i]);
		getimage(RoundX, JogGanhouY*3, RoundX+JogGanhouX-1, JogGanhouY*4-1, VoltarMenu.SpriteMask[i]);
		getimage(RoundX+JogGanhouX, BotMenuY*0, RoundX+JogGanhouX+BotMenuX-1, BotMenuY*1-1, btnJogar.SpriteMask[i]);
		getimage(RoundX+JogGanhouX, BotMenuY*1, RoundX+JogGanhouX+BotMenuX-1, BotMenuY*2-1, btnComandos.SpriteMask[i]);
		getimage(RoundX+JogGanhouX, BotMenuY*2, RoundX+JogGanhouX+BotMenuX-1, BotMenuY*3-1, btnSair.SpriteMask[i]);
		getimage(RoundX+JogGanhouX, BotMenuY*3, RoundX+JogGanhouX+111, BotMenuY*3+64, Tempo.SpriteMask[i]);
	}
	
	// Pausado
	for(i=0; i<2; i++){
		if(i < 1){
			readimagefile(".\\img\\Pausado.bmp", 0, 0, LarTela, AltTela);
		}
		else{
			readimagefile(".\\img\\PausadoMask.bmp", 0, 0, LarTela, AltTela);
		}
		getimage(0, 0, LarTela-1, AltTela-1, Pausado.SpriteMask[i]);
	}
	
	// Cenário, Menu e Comandos
	readimagefile(".\\img\\TemploDeGongji.bmp", 0, 0, LarTela, AltTela);
	getimage(0, 0, LarTela, AltTela, Cenario.SpriteMask[0]);
	readimagefile(".\\img\\TelaPrincipal.bmp", 0, 0, LarTela, AltTela);
	getimage(0, 0, LarTela, AltTela, MenuPrin.SpriteMask[0]);
	readimagefile(".\\img\\Comandos.bmp", 0, 0, LarTela, AltTela);
	getimage(0, 0, LarTela, AltTela, TutorialComandos.SpriteMask[0]);
	
	// ============ FIm das Imagens ===================
	
	
//============= Animações ===============
	
	//============ Personagem Parado ===============
	readimagefile(".\\img\\Galo\\Idle.bmp",0,0,900,600);
	for(i=0;i<IdleG.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,IdleG.Sprite[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,IdleG.Sprite[i]);
		}
	}
	
	// Agachar
	getimage(imgTamanhoX, imgTamanhoY, 300+imgTamanhoX, imgTamanhoY+imgTamanhoY, AgacharG);
	
	// Defesa
	getimage(300 + imgTamanhoX, imgTamanhoY, 600+imgTamanhoX, imgTamanhoY+imgTamanhoY, DefesaG);
	
	
	readimagefile(".\\img\\Galo\\IdleMacara.bmp",0,0,900,600);
	for(i=0;i<IdleG.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,IdleG.Mask[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,IdleG.Mask[i]);
		}
	}
	
	// Agachar Mask
	getimage(imgTamanhoX, imgTamanhoY, 300+imgTamanhoX, imgTamanhoY+imgTamanhoY, AgacharGMask);
	
	// Defesa Mask
	getimage(300 + imgTamanhoX, imgTamanhoY, 600+imgTamanhoX, imgTamanhoY+imgTamanhoY, DefesaGMask);
	
//============ Fim personagem Parado ============
	
//============ Personagem Parado Invertido ===============
	readimagefile(".\\img\\Galo\\IdleINVERTIDO.bmp",0,0,900,600);
	for(i=0;i<IdleGMirror.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,IdleGMirror.Sprite[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,IdleGMirror.Sprite[i]);
		}
	}
	
	// Agachar Invertido
	getimage(imgTamanhoX, imgTamanhoY, 300+imgTamanhoX, imgTamanhoY+imgTamanhoY, AgacharGMirror);
	
	// Defesa Invertida
	getimage(300 + imgTamanhoX, imgTamanhoY, 600+imgTamanhoX, imgTamanhoY+imgTamanhoY, DefesaGMirror);
	
	readimagefile(".\\img\\Galo\\IdleInvertidoMascara.bmp",0,0,900,600);
	for(i=0;i<IdleGMirror.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,IdleGMirror.Mask[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,IdleGMirror.Mask[i]);
		}
	}
	
	// Agachar Invertido Mask
	getimage(imgTamanhoX, imgTamanhoY, 300+imgTamanhoX, imgTamanhoY+imgTamanhoY, AgacharGMirrorMask);
	
	// Defesa Invertida Mask
	getimage(300 + imgTamanhoX, imgTamanhoY, 600+imgTamanhoX, imgTamanhoY+imgTamanhoY, DefesaGMirrorMask);
	
//============ Fim personagem Parado Invertido ============
	
	
//============ Personagem Andando ===============
	readimagefile(".\\img\\Galo\\Andando.bmp",0,0,900,600);
	for(i=0;i<AndandoG.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,AndandoG.Sprite[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,AndandoG.Sprite[i]);
		}
	}
	
	readimagefile(".\\img\\Galo\\AndandoMascara.bmp",0,0,900,600);
	for(i=0;i<AndandoG.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,AndandoG.Mask[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,AndandoG.Mask[i]);
		}
	}
	
//============ Fim personagem Andando ============
	
//============ Personagem Andando Invertido ===============
	readimagefile(".\\img\\Galo\\AndandoInvertido.bmp",0,0,900,600);
	for(i=0;i<AndandoGMirror.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,AndandoGMirror.Sprite[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,AndandoGMirror.Sprite[i]);
		}
	}
	
	readimagefile(".\\img\\Galo\\AndandoInvertidoMascara.bmp",0,0,900,600);
	for(i=0;i<AndandoGMirror.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,AndandoGMirror.Mask[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,AndandoGMirror.Mask[i]);
		}
	}
	
//============ Fim personagem Andando Invertido ============
	
	
	
//============ Personagem Pulando ===============
	readimagefile(".\\img\\Galo\\Pulo.bmp",0,0,900,600);
	for(i=0;i<PuloG.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,PuloG.Sprite[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,PuloG.Sprite[i]);
		}
	}
	
	readimagefile(".\\img\\Galo\\PuloMascara.bmp",0,0,900,600);
	for(i=0;i<PuloG.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,PuloG.Mask[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,PuloG.Mask[i]);
		}
	}
	
//============ Fim personagem Pulando ============
	
//============ Personagem Pulando Invertido ===============
	readimagefile(".\\img\\Galo\\PuloInvertido.bmp",0,0,900,600);
	for(i=0;i<PuloGMirror.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,PuloGMirror.Sprite[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,PuloGMirror.Sprite[i]);
		}
	}
	
	readimagefile(".\\img\\Galo\\PuloInvertidoMascara.bmp",0,0,900,600);
	for(i=0;i<PuloGMirror.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,PuloGMirror.Mask[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,PuloGMirror.Mask[i]);
		}
	}
	
//============ Fim personagem Pulando Invertido ============
	
	
//============ Personagem Socando ===============
	readimagefile(".\\img\\Galo\\Porrada.bmp",0,0,900,600);
	for(i=0;i<SocoG.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,SocoG.Sprite[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,SocoG.Sprite[i]);
		}
	}
	
	readimagefile(".\\img\\Galo\\PorradaMascara.bmp",0,0,900,600);
	for(i=0;i<SocoG.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,SocoG.Mask[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,SocoG.Mask[i]);
		}
	}
	
//============ Fim personagem Socando ============

//============ Personagem Socando Invertido ===============
	readimagefile(".\\img\\Galo\\PorradaInvertido.bmp",0,0,900,600);
	for(i=0;i<SocoGMirror.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,SocoGMirror.Sprite[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,SocoGMirror.Sprite[i]);
		}
	}
	
	readimagefile(".\\img\\Galo\\PorradaInvertidoMascara.bmp",0,0,900,600);
	for(i=0;i<SocoGMirror.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,SocoGMirror.Mask[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,SocoGMirror.Mask[i]);
		}
	}
	
//============ Fim personagem Socando Invertido ============


//============ Personagem Chutando ===============
	readimagefile(".\\img\\Galo\\Chute.bmp",0,0,900,600);
	for(i=0;i<ChuteG.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,ChuteG.Sprite[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,ChuteG.Sprite[i]);
		}
	}
	
	readimagefile(".\\img\\Galo\\ChuteMascara.bmp",0,0,900,600);
	for(i=0;i<ChuteG.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,ChuteG.Mask[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,ChuteG.Mask[i]);
		}
	}
	
//============ Fim personagem Chutando ============

//============ CHUTE INVERTIDO =================
		readimagefile(".\\img\\Galo\\ChuteInvertido.bmp",0,0,900,600);
	for(i=0;i<ChuteGMirror.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,ChuteGMirror.Sprite[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,ChuteGMirror.Sprite[i]);
		}
	}
	
	readimagefile(".\\img\\Galo\\ChuteInvertidoMascara.bmp",0,0,900,600);
	for(i=0;i<ChuteGMirror.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,ChuteGMirror.Mask[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,ChuteGMirror.Mask[i]);
		}
	}	
	
// ========== Fim chute invertido ===========

//============ Personagem Levando Dano ===============
	readimagefile(".\\img\\Galo\\Levadano.bmp",0,0,900,600);
	for(i=0;i<DanoG.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,DanoG.Sprite[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,DanoG.Sprite[i]);
		}
	}
	
	readimagefile(".\\img\\Galo\\LevadanoMascara.bmp",0,0,900,600);
	for(i=0;i<DanoG.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,DanoG.Mask[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,DanoG.Mask[i]);
		}
	}
	
//============ Fim personagem Levando Dano ============

//============ Personagem Levando Dano Invertido ===============
	readimagefile(".\\img\\Galo\\LevadanoInvertido.bmp",0,0,900,600);
	for(i=0;i<DanoGMirror.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,DanoGMirror.Sprite[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,DanoGMirror.Sprite[i]);
		}
	}
	
	readimagefile(".\\img\\Galo\\LevadanoInvertidoMascara.bmp",0,0,900,600);
	for(i=0;i<DanoGMirror.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,DanoGMirror.Mask[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,DanoGMirror.Mask[i]);
		}
	}
	
	
//============ Fim personagem Levando Dano Invertido ============

// Gancho
// ==============================================================
	readimagefile(".\\img\\Galo\\Gancho.bmp",0,0,900,600);
	for(i=0;i<GanchoG.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,GanchoG.Sprite[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,GanchoG.Sprite[i]);
		}
	}
	
	readimagefile(".\\img\\Galo\\GanchoMascara.bmp",0,0,900,600);
	for(i=0;i<GanchoG.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,GanchoG.Mask[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,GanchoG.Mask[i]);
		}
	}	
	// fim Gancho
	// =================================================================
	
	// Gancho invertido
	// =================================================================
	readimagefile(".\\img\\Galo\\GanchoInvertido.bmp",0,0,900,600);
	for(i=0;i<GanchoGMirror.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,GanchoGMirror.Sprite[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,GanchoGMirror.Sprite[i]);
		}
	}
	
	readimagefile(".\\img\\Galo\\GanchoInvertidoMascara.bmp",0,0,900,600);
	for(i=0;i<GanchoGMirror.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,GanchoGMirror.Mask[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,GanchoGMirror.Mask[i]);
		}
	}
	//Fim Gancho Invertido
	
	// =========== GALO LEVANTANDO ===========
	readimagefile(".\\img\\Galo\\Levanta.bmp",0,0,900,600);
	for(i=0;i<LevantaG.QtdeSprites-1;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,LevantaG.Sprite[i]);
	}
	getimage(0,imgTamanhoY,imgTamanhoX,imgTamanhoY*2,LevantaG.Sprite[3]);
	
	readimagefile(".\\img\\Galo\\LevantaMascara.bmp",0,0,900,600);
	for(i=0;i<LevantaG.QtdeSprites-1;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,LevantaG.Mask[i]);
	}
	getimage(0,imgTamanhoY,imgTamanhoX,imgTamanhoY*2,LevantaG.Mask[3]);
	
	// INVERTIDO
	
		readimagefile(".\\img\\Galo\\LevantaInvertido.bmp",0,0,900,600);
	for(i=0;i<LevantaG.QtdeSprites-1;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,LevantaGMirror.Sprite[i]);
	}
	getimage(0,imgTamanhoY,imgTamanhoX,imgTamanhoY*2,LevantaGMirror.Sprite[3]);
	
	readimagefile(".\\img\\Galo\\LevantaInvertidoMascara.bmp",0,0,900,600);
	for(i=0;i<LevantaG.QtdeSprites-1;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,LevantaGMirror.Mask[i]);
	}
	getimage(0,imgTamanhoY,imgTamanhoX,imgTamanhoY*2,LevantaGMirror.Mask[3]);
	
	// ===== Fim do Levanta Galo ======
	
// =================================================================
	

// SURICATO
//============ Personagem Parado ===============
	readimagefile(".\\img\\Suricato\\Idle.bmp",0,0,900,600);
	for(i=0;i<IdleS.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,IdleS.Sprite[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,IdleS.Sprite[i]);
		}
	}
	
	// Agachar
	getimage(imgTamanhoX, imgTamanhoY, 300+imgTamanhoX, imgTamanhoY+imgTamanhoY, AgacharS);
	
	// Defesa
	getimage(300 + imgTamanhoX, imgTamanhoY, 600+imgTamanhoX, imgTamanhoY+imgTamanhoY, DefesaS);
	
	
	readimagefile(".\\img\\Suricato\\IdleMascara.bmp",0,0,900,600);
	for(i=0;i<IdleS.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,IdleS.Mask[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,IdleS.Mask[i]);
		}
	}
	
	// Agachar Mask
	getimage(imgTamanhoX, imgTamanhoY, 300+imgTamanhoX, imgTamanhoY+imgTamanhoY, AgacharSMask);
	
	// Defesa Mask
	getimage(300 + imgTamanhoX, imgTamanhoY, 600+imgTamanhoX, imgTamanhoY+imgTamanhoY, DefesaSMask);
	
//============ Fim personagem Parado ============
	
//============ Personagem Parado Invertido ===============
	readimagefile(".\\img\\Suricato\\IdleINVERTIDO.bmp",0,0,900,600);
	for(i=0;i<IdleSMirror.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,IdleSMirror.Sprite[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,IdleSMirror.Sprite[i]);
		}
	}
	
	// Agachar Invertido
	getimage(imgTamanhoX, imgTamanhoY, 300+imgTamanhoX, imgTamanhoY+imgTamanhoY, AgacharSMirror);
	
	// Defesa Invertida
	getimage(300 + imgTamanhoX, imgTamanhoY, 600+imgTamanhoX, imgTamanhoY+imgTamanhoY, DefesaSMirror);
	
	readimagefile(".\\img\\Suricato\\IdleInvertidoMascara.bmp",0,0,900,600);
	for(i=0;i<IdleSMirror.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,IdleSMirror.Mask[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,IdleSMirror.Mask[i]);
		}
	}
	
	// Agachar Invertido Mask
	getimage(imgTamanhoX, imgTamanhoY, 300+imgTamanhoX, imgTamanhoY+imgTamanhoY, AgacharSMirrorMask);
	
	// Defesa Invertida Mask
	getimage(300 + imgTamanhoX, imgTamanhoY, 600+imgTamanhoX, imgTamanhoY+imgTamanhoY, DefesaSMirrorMask);
	
//============ Fim personagem Parado Invertido ============
	
	
//============ Personagem Andando ===============
	readimagefile(".\\img\\Suricato\\Andando.bmp",0,0,900,600);
	for(i=0;i<AndandoS.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,AndandoS.Sprite[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,AndandoS.Sprite[i]);
		}
	}
	
	readimagefile(".\\img\\Suricato\\AndandoMascara.bmp",0,0,900,600);
	for(i=0;i<AndandoS.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,AndandoS.Mask[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,AndandoS.Mask[i]);
		}
	}
	
//============ Fim personagem Andando ============
	
//============ Personagem Andando Invertido ===============
	readimagefile(".\\img\\Suricato\\AndandoInvertido.bmp",0,0,900,600);
	for(i=0;i<AndandoSMirror.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,AndandoSMirror.Sprite[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,AndandoSMirror.Sprite[i]);
		}
	}
	
	readimagefile(".\\img\\Suricato\\AndandoInvertidoMascara.bmp",0,0,900,600);
	for(i=0;i<AndandoSMirror.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,AndandoSMirror.Mask[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,AndandoSMirror.Mask[i]);
		}
	}
	
//============ Fim personagem Andando Invertido ============
	
	
	
//============ Personagem Pulando ===============
	readimagefile(".\\img\\Suricato\\Pulo.bmp",0,0,900,600);
	for(i=0;i<PuloS.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,PuloS.Sprite[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,PuloS.Sprite[i]);
		}
	}
	
	readimagefile(".\\img\\Suricato\\PuloMascara.bmp",0,0,900,600);
	for(i=0;i<PuloS.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,PuloS.Mask[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,PuloS.Mask[i]);
		}
	}
	
//============ Fim personagem Pulando ============
	
//============ Personagem Pulando Invertido ===============
	readimagefile(".\\img\\Suricato\\PuloInvertido.bmp",0,0,900,600);
	for(i=0;i<PuloSMirror.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,PuloSMirror.Sprite[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,PuloSMirror.Sprite[i]);
		}
	}
	
	readimagefile(".\\img\\Suricato\\PuloInvertidoMascara.bmp",0,0,900,600);
	for(i=0;i<PuloSMirror.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,PuloSMirror.Mask[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,PuloSMirror.Mask[i]);
		}
	}
	
//============ Fim personagem Pulando Invertido ============
	
	
//============ Personagem Socando ===============
	readimagefile(".\\img\\Suricato\\Porrada.bmp",0,0,900,600);
	for(i=0;i<SocoS.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,SocoS.Sprite[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,SocoS.Sprite[i]);
		}
	}
	
	readimagefile(".\\img\\Suricato\\PorradaMascara.bmp",0,0,900,600);
	for(i=0;i<SocoS.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,SocoS.Mask[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,SocoS.Mask[i]);
		}
	}
	
//============ Fim personagem Socando ============

//============ Personagem Socando Invertido ===============
	readimagefile(".\\img\\Suricato\\PorradaInvertida.bmp",0,0,900,600);
	for(i=0;i<SocoSMirror.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,SocoSMirror.Sprite[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,SocoSMirror.Sprite[i]);
		}
	}
	
	readimagefile(".\\img\\Suricato\\PorradaInvertidaMascara.bmp",0,0,900,600);
	for(i=0;i<SocoSMirror.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,SocoSMirror.Mask[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,SocoSMirror.Mask[i]);
		}
	}
	
//============ Fim personagem Socando Invertido ============


//============ Personagem Chutando ===============
	readimagefile(".\\img\\Suricato\\Chute.bmp",0,0,900,600);
	for(i=0;i<ChuteS.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,ChuteS.Sprite[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,ChuteS.Sprite[i]);
		}
	}
	
	readimagefile(".\\img\\Suricato\\ChuteMascara.bmp",0,0,900,600);
	for(i=0;i<ChuteS.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,ChuteS.Mask[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,ChuteS.Mask[i]);
		}
	}
	
//============ Fim personagem Chutando ============

//============ Personagem Chutando Invertido ===============
	readimagefile(".\\img\\Suricato\\ChuteInvertido.bmp",0,0,900,600);
	for(i=0;i<ChuteSMirror.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,ChuteSMirror.Sprite[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,ChuteSMirror.Sprite[i]);
		}
	}
	
	readimagefile(".\\img\\Suricato\\ChuteInvertidoMascara.bmp",0,0,900,600);
	for(i=0;i<ChuteSMirror.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,ChuteSMirror.Mask[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,ChuteSMirror.Mask[i]);
		}
	}
	
//============ Fim personagem Chutando Invertido ============

//============ Personagem Levando Dano ===============
	readimagefile(".\\img\\Suricato\\Levadano.bmp",0,0,900,600);
	for(i=0;i<DanoS.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,DanoS.Sprite[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,DanoS.Sprite[i]);
		}
	}
	
	readimagefile(".\\img\\Suricato\\LevadanoMascara.bmp",0,0,900,600);
	for(i=0;i<DanoS.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,DanoS.Mask[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,DanoS.Mask[i]);
		}
	}
	
//============ Fim personagem Levando Dano ============

//============ Personagem Levando Dano Invertido ===============
	readimagefile(".\\img\\Suricato\\LevadanoInvertido.bmp",0,0,900,600);
	for(i=0;i<DanoSMirror.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,DanoSMirror.Sprite[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,DanoSMirror.Sprite[i]);
		}
	}
	
	readimagefile(".\\img\\Suricato\\LevadanoInvertidoMascara.bmp",0,0,900,600);
	for(i=0;i<DanoSMirror.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,DanoSMirror.Mask[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,DanoSMirror.Mask[i]);
		}
	}
	
//============ Fim personagem Levando Dano Invertido ============

	// Gancho
	// ==============================================================
	readimagefile(".\\img\\Suricato\\Gancho.bmp",0,0,900,600);
	for(i=0;i<GanchoS.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,GanchoS.Sprite[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,GanchoS.Sprite[i]);
		}
	}
	
	readimagefile(".\\img\\Suricato\\GanchoMascara.bmp",0,0,900,600);
	for(i=0;i<GanchoS.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,GanchoS.Mask[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,GanchoS.Mask[i]);
		}
	}	
	// fim Gancho
	// =================================================================
	
	// Gancho invertido
	// =================================================================
	readimagefile(".\\img\\Suricato\\GanchoInvertido.bmp",0,0,900,600);
	for(i=0;i<GanchoSMirror.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,GanchoSMirror.Sprite[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,GanchoSMirror.Sprite[i]);
		}
	}
	
	readimagefile(".\\img\\Suricato\\GanchoInvertidoMascara.bmp",0,0,900,600);
	for(i=0;i<GanchoSMirror.QtdeSprites;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,GanchoSMirror.Mask[i]);
		if (i > 2){
			getimage(900-imgTamanhoX*i,imgTamanhoY,600-imgTamanhoX*i,imgTamanhoY+imgTamanhoY,GanchoSMirror.Mask[i]);
		}
	}
	//Fim Gancho Invertido
	// =================================================================
	
	// =========== SURICATO LEVANTANDO ===========
	readimagefile(".\\img\\Suricato\\Levanta.bmp",0,0,900,600);
	for(i=0;i<LevantaS.QtdeSprites-1;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,LevantaS.Sprite[i]);
	}
	getimage(0,imgTamanhoY,imgTamanhoX,imgTamanhoY*2,LevantaS.Sprite[3]);
	
	readimagefile(".\\img\\Suricato\\LevantaMascara.bmp",0,0,900,600);
	for(i=0;i<LevantaS.QtdeSprites-1;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,LevantaS.Mask[i]);
	}
	getimage(0,imgTamanhoY,imgTamanhoX,imgTamanhoY*2,LevantaS.Mask[3]);
	
	// INVERTIDO
	
		readimagefile(".\\img\\Suricato\\LevantaInvertido.bmp",0,0,900,600);
	for(i=0;i<LevantaS.QtdeSprites-1;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,LevantaSMirror.Sprite[i]);
	}
	getimage(0,imgTamanhoY,imgTamanhoX,imgTamanhoY*2,LevantaSMirror.Sprite[3]);
	
	readimagefile(".\\img\\Suricato\\LevantaInvertidoMascara.bmp",0,0,900,600);
	for(i=0;i<LevantaS.QtdeSprites-1;i++){
		getimage(0+imgTamanhoX*i,0,300+imgTamanhoX*i,imgTamanhoY,LevantaSMirror.Mask[i]);
	}
	getimage(0,imgTamanhoY,imgTamanhoX,imgTamanhoY*2,LevantaSMirror.Mask[3]);

// ============ FIM DO CARREGAR =============

	setvisualpage(pg);
	//Fecha Tela de Carga
	//sleep(10000);
	closegraph();
	
	//================ Tela Jogo ==================
	
	initwindow(LarTela,AltTela,"Fighting Beasts V.0.3",150,0);
	
	// Créditos Iniciais
	readimagefile(".\\img\\Creditos.bmp",0,0,1000,700);
	delay(2000);
	
	// Vai para execução tela inicial
	TelaInicial();
	// Finaliza a tela grafica
	closegraph();
	
	// COLOCAR TODAS OS PONTEIROS AQUI!!!!
	// Free Huds, Menu, Botões, etc.
	free(Hud.Mask); free(Hud.Sprite); free(BarraVida.Mask); free(BarraVida.Sprite);
	free(BarraStamina.Mask); free(BarraStamina.Sprite); free(Vitoria.Mask); free(Vitoria.Sprite);
	free(Icones.Mask); free(Icones.Sprite); free(btnJogar.SpriteMask); free(btnComandos.SpriteMask);
	free(btnSair.SpriteMask); free(Round1.SpriteMask); free(Round2.SpriteMask); free(Round3.SpriteMask);
	free(Round4.SpriteMask); free(Round5.SpriteMask); free(VitoriaJog1.SpriteMask); free(VitoriaJog2.SpriteMask);
	free(Rematch.SpriteMask); free(VoltarMenu.SpriteMask); free(Pausado.SpriteMask); free(Cenario.SpriteMask);
	free(MenuPrin.SpriteMask); free(TutorialComandos.SpriteMask); free(Tempo.SpriteMask);
	
	// Free Animações
	//Galo
	free(IdleG.Mask); free(IdleG.Sprite); free(IdleGMirror.Mask); free(IdleGMirror.Sprite);
	free(AndandoG.Mask); free(AndandoG.Sprite); free(AndandoGMirror.Mask); free(AndandoGMirror.Sprite);
	free(PuloG.Mask); free(PuloG.Sprite); free(PuloGMirror.Mask); free(PuloGMirror.Sprite);
	free(SocoG.Mask); free(SocoG.Sprite); free(SocoGMirror.Mask); free(SocoGMirror.Sprite);
	free(ChuteG.Mask); free(ChuteG.Sprite); free(ChuteGMirror.Mask); free(ChuteGMirror.Sprite);
	free(DanoG.Mask); free(DanoG.Sprite); free(DanoGMirror.Mask); free(DanoGMirror.Sprite);
	free(GanchoG.Mask); free(GanchoG.Sprite); free(GanchoGMirror.Sprite); free(GanchoGMirror.Mask);
	free(LevantaG.Mask); free(LevantaG.Sprite); free(LevantaGMirror.Mask); free(LevantaGMirror.Sprite);
	
	//Suricato
	free(IdleS.Mask); free(IdleS.Sprite); free(IdleSMirror.Mask); free(IdleSMirror.Sprite);
	free(AndandoS.Mask); free(AndandoS.Sprite); free(AndandoSMirror.Mask); free(AndandoSMirror.Sprite);
	free(PuloS.Mask); free(PuloS.Sprite); free(PuloSMirror.Mask); free(PuloSMirror.Sprite);
	free(SocoS.Mask); free(SocoS.Sprite); free(SocoSMirror.Mask); free(SocoSMirror.Sprite);
	free(ChuteS.Mask); free(ChuteS.Sprite); free(ChuteSMirror.Mask); free(ChuteSMirror.Sprite);
	free(DanoS.Mask); free(DanoS.Sprite); free(DanoSMirror.Mask); free(DanoSMirror.Sprite);
	free(GanchoS.Mask); free(GanchoS.Sprite); free(GanchoSMirror.Sprite); free(GanchoSMirror.Mask);
	free(LevantaS.Mask); free(LevantaS.Sprite); free(LevantaSMirror.Mask); free(LevantaSMirror.Sprite);
	
	return 0;
}

void TelaInicial(){
	bool Fim = false;
	int pg = 1;
	POINT P;
	HWND Janela;

	//Carregando a música do menu
	
	// Variáveis de ativação
	bool btnJogarSel = false;
	bool btnComandosSel = false;
	bool btnSairSel = false;
	bool ComandosSel = false;
	int BotMenuX = 152, BotMenuY = 87;
	
	cleardevice();

	// Desenhando a tela Inicial
	Janela = GetForegroundWindow();
	while(!Fim){
		if (pg == 1) pg = 2; else pg = 1;
		setactivepage(pg);
		
		// Desenhando a tela Inicial
		putimage(0,0, MenuPrin.SpriteMask[0], COPY_PUT);
		
		// Desenhando os botões ativados
		if(ComandosSel)
			putimage(0,0, TutorialComandos.SpriteMask[0], COPY_PUT);
		
		if (btnJogarSel ){
			putimage(424,349,btnJogar.SpriteMask[1],AND_PUT);
			putimage(424,349,btnJogar.SpriteMask[0],OR_PUT);
		}
		
		if (btnComandosSel){
			putimage(424,438,btnComandos.SpriteMask[1],AND_PUT);
			putimage(424,438,btnComandos.SpriteMask[0],OR_PUT);
		}
		
		if (btnSairSel){
			putimage(424,527,btnSair.SpriteMask[1],AND_PUT);
			putimage(424,527,btnSair.SpriteMask[0],OR_PUT);
		}

		setvisualpage(pg);
		
		// Input do Mouse
		if(GetCursorPos(&P))
			if(ScreenToClient(Janela,&P)){
				
				// Condições que leem a posição do mouse, e mostram os botõees acesos
				btnJogarSel = false;
				if(424 <= P.x && P.x <= 424+BotMenuX-1 && 349 <= P.y && P.y <= 349+BotMenuY-1 && !ComandosSel){
					btnJogarSel = true;
				}
				btnComandosSel = false;
				if(424 <= P.x && P.x <= 424+BotMenuX-1 && 438 <= P.y && P.y <= 438+BotMenuY-1 && !ComandosSel){
					btnComandosSel = true;
				}
				
					btnSairSel = false;
				if(424 <= P.x && P.x <= 424+BotMenuX-1 && 527 <= P.y && P.y <= 527+BotMenuY-1 && !ComandosSel){
					btnSairSel = true;
				}
				
				// Condições para acionar os botões
				if(GetKeyState(VK_LBUTTON)&0x80){
					if(424 <= P.x && P.x <= 424+BotMenuX-1 && 349 <= P.y && P.y <= 349+BotMenuY-1 && !ComandosSel){
						Jogar();
					}
					
					ComandosSel = false;
					if(424 <= P.x && P.x <= 424+BotMenuX-1 && 438 <= P.y && P.y <= 438+BotMenuY-1 && !ComandosSel){
						if(!ComandosSel)
							ComandosSel = true;
					}
						
					if(424 <= P.x && P.x <= 424+BotMenuX-1 && 527 <= P.y && P.y <= 527+BotMenuY-1 && !ComandosSel){
						Fim = true;
					}
				}
			}
	
	}
		
}


void Jogar(){
	char Tecla;
	POINT P;
	HWND Janela;
	Janela = GetForegroundWindow();
	
	//Intensidade do som do jogo
	waveOutSetVolume(0,0x88888888);
	
	int pg, i;
	int direcaoP1, direcaoP2;
	int X1, X2, Y1, Y2, SX1, SX2, SY1, SY2;
	int X1P, X2P, Y1P, Y2P, SX1P, SX2P, SY1P, SY2P;
	int X1DP1, X2DP1, Y1DP1, Y2DP1, SX1DP1, SX2DP1, SY1DP1, SY2DP1;
	int X1DP2, X2DP2, Y1DP2, Y2DP2, SX1DP2, SX2DP2, SY1DP2, SY2DP2;
	int VitoriasP1 = 0, VitoriasP2 = 0, RoundAtual = 0;
	int presA, presD, presS, presW, presJ, presK, presL;
	int presSL, presSR, presSU, presSD, pres1, pres2, pres3;
	int runAnimaDP1 = 0, runAnimaAP1 = 0, runAnimaDPP1 = 0, runAnimaEPP1 = 0;
	int runAnimaDP2 = 0, runAnimaAP2 = 0, runAnimaDPP2 = 0, runAnimaEPP2 = 0;
	int MovimentacaoP1 = 0, MovimentacaoP2 = 0;
	int caindoP1 = 0, caindoP2 = 0;
	int SocoVP1 = 0, SocoVP2 = 0, DelaySP1 = 0, DelaySP2 = 0, GanchoVP1 = 0, GanchoVP2 = 0;
	int ChuteVP1 = 0, ChuteVP2 = 0, DelayCP1 = 0, DelayCP2 = 0, DelayGanchoP1 = 0, DelayGanchoP2 = 0; 
	int RegenStamP1 = 0, RegenStamP2 = 0;
	int ContadorP1 = 0, ContadorP2 = 0; 
	int InvenciP1 = 0, InvenciP2 = 0;
	int TempInvenciP1 = 0, TempInvenciP2 = 0;
	int DelayGP1 = 0, DelayGP2 = 0;
	int CooldownP1 = 0, CooldownP2 = 0;
	int TempCooldownP1 = 0, TempCooldownP2 = 0;
	int LevaDanoP1 = 0, LevaDanoP2 = 0; 
	int varGancho = 0, varGanchoP2 = 0, varSocoP1 = 0, varSocoP2 = 0;
	int varChuteP1 = 0, varChuteP2 = 0;
	
	// Estes são os "get ticks" genéricos para calcular o tempo em que os personagens ficam
	// travados antes dos rounds começar
	int gtRound1 = 1, gtRound2 = 100;
	
	// Preparando as variáveis para o último round
	int gtFimDeRound1 = 1, gtFimDeRound2 = 100;
	int BotFimDeJogoX = 220, BotFimDeJogoY = 130;
	
	float imgP1 = 0, img2P1 = 0, img3P1 = 0, img4P1 = 0, img5P1 = 0, img6P1 = 0;
	float imgP2 = 0, img2P2 = 0, img3P2 = 0, img4P2 = 0, img5P2 = 0, img6P2 = 0;
	
	unsigned long long gt1, gt2;
	
	// Acionando os estados do jogo
	bool FimDeRound = false;
	bool FimDeJogo = false;
	bool PausarJog = false;
	bool NovoRound = true;
	bool DecisaoFinal = false;
	bool EmpurraoP1 = false;
	bool EmpurraoP2 = false;
	
	TPlayer Player1, Player2;
	TDesenho DgolpesP1S, DgolpesP1C, DgolpesP2S, DgolpesP2C, Dvida, Dstamina, Ddano;
	
	direcaoP1 = 0;
	direcaoP2 = 1;
	
	pg = 1;
	gt1 = GetTickCount();
	
	presA = 0;
	presD = 0;
	presS = 0;
	presW = 0;
	presJ = 0;
	presK = 0;
	presL = 0;
	
	presSL = 0;
	presSR = 0;
	presSU = 0; 
	presSD = 0;
	pres1 = 0;
	pres2 = 0;
	pres3 = 0;
	
	
	//definindo os valores do player 1
	Player1.X1 = 100;
	Player1.X2 = 230;
	Player1.Y1 = 300;
	Player1.Y2 = 600;
	Player1.Dano = 10;
	Player1.QdeGolpes = 1;
	Player1.GravP = 10;
	Player1.R = 255;
	Player1.G = 0;
	Player1.B = 0;
	Player1.VelocX = 7;
	Player1.VelocY = 7;
	Player1.ForcaP = 100;
	Player1.Vida = 293;
	Player1.Stamina = 100;
				
	//definindo os valores do player 2
	Player2.X1 = 780;
	Player2.X2 = 900;
	Player2.Y1 = 300;
	Player2.Y2 = 600;
	Player2.Dano = 10;
	Player2.QdeGolpes = 1;
	Player2.GravP = 10;
	Player2.R = 0;
	Player2.G = 0;
	Player2.B = 255;
	Player2.VelocX = 7;
	Player2.VelocY = 7;
	Player2.ForcaP = 100;
	Player2.Vida = 293;
	Player2.Stamina = 100;
	
	while (!FimDeJogo){
		if(NovoRound){
		
			// Registra qual é o round atual
			RoundAtual++;
			
			//definindo os valores do player 1
			Player1.X1 = 100;
			Player1.X2 = 230;
			Player1.Y1 = 300;
			Player1.Y2 = 600;
			Player1.Vida = 293;
			Player1.Stamina = 100;
							
			//definindo os valores do player 2
			Player2.X1 = 780;
			Player2.X2 = 900;
			Player2.Y1 = 300;
			Player2.Y2 = 600;
			Player2.Vida = 293;
			Player2.Stamina = 100;
			
			// PLAYER 1
			X1 = 136;
			X2 = X1 + Player1.Vida;
			Y1 = 60;
			Y2 = 92;
			SX1 = 136;
			SX2 = SX1 + Player1.Vida;
			SY1 = 96;
			SY2 = 109;
			
			// PLAYER 2
			X1P = 571;
			X2P = X1P + Player2.Vida;
			Y1P = 60;
			Y2P = 92;
			SX1P = 571;
			SX2P = SX1P + Player2.Vida;
			SY1P = 96;
			SY2P = 109;
			
			// Barras de Dano
			// PLAYER 1
			X1DP1 = 136;
			X2DP1 = 136;//429;
			Y1DP1 = 60;
			Y2DP1 = 92;
			SX1DP1 = 136;
			SX2DP1 = 136;
			SY1DP1 = 96;
			SY2DP1 = 109;
				
			// PLAYER 2
			X1DP2 = 864;
			X2DP2 = 864;
			Y1DP2 = 60;
			Y2DP2 = 92;
			SX1DP2 = 864;//571;
			SX2DP2 = 864;
			SY1DP2 = 96;
			SY2DP2 = 109;
			
			// Limitando mais a movimentação antes do round
			presA = 0;
			presD = 0;
			presS = 0;
			presW = 0;
			presJ = 0;
			presK = 0;
			presL = 0;
				
			presSL = 0;
			presSR = 0;
			presSU = 0; 
			presSD = 0;
			pres1 = 0;
			pres2 = 0;
			pres3 = 0;
			
			direcaoP1 = 0;
			direcaoP2 = 1;
			
			// Altera a direção dos hitbox
			DgolpesP1S.X1 = Player1.X1 + 140;
			DgolpesP1S.X2 = Player1.X2 + 35;
			DgolpesP1S.Y1 = Player1.Y1 + 95;
			DgolpesP1S.Y2 = Player1.Y2 - 185;
					
			DgolpesP1C.X1 = Player1.X1 + 140;
			DgolpesP1C.X2 = Player1.X2 + 35;
			DgolpesP1C.Y1 = Player1.Y1 + 110;
			DgolpesP1C.Y2 = Player1.Y2 - 140;
						
			//	Player2

			DgolpesP2S.X1 = Player2.X1 - 35;
			DgolpesP2S.X2 = Player2.X2 - 130;
			DgolpesP2S.Y1 = Player2.Y1 + 90;
			DgolpesP2S.Y2 = Player2.Y2 - 185;
				
			DgolpesP2C.X1 = Player2.X1 - 35;
			DgolpesP2C.X2 = Player2.X2 - 130;
			DgolpesP2C.Y1 = Player2.Y1 + 120;
			DgolpesP2C.Y2 = Player2.Y2 - 145;

			// Resetando o cronometro para aprecer a imagem do próximo round
			gtRound1 = 1;	
			NovoRound = false;
			
		}
		
		gt2 = GetTickCount();
// ======================================    DESENHO    ==========================================
		if(gt2-gt1 > 1000/70){
		if (pg == 1) pg = 2; else pg = 1;
		gt1 = gt2;
		setactivepage(pg);
		cleardevice();
		// Fundo
		putimage(0, 0, Cenario.SpriteMask[0], COPY_PUT);
		
	// Limite de Tempo
		putimage(444,52, Tempo.SpriteMask[1], AND_PUT);
		putimage(444,52, Tempo.SpriteMask[0], OR_PUT);
		
	//Desenhando a barra de vida
		
		// PLAYER 1 (Esquerda)
	
		putimage(35, 25, Hud.Mask[0], AND_PUT);
		putimage(35, 25, Hud.Sprite[0], OR_PUT);
		putimage(36, 32, Icones.Mask[0], AND_PUT);
		putimage(36, 32, Icones.Sprite[0], OR_PUT);

		//barra de vida verde
		setfillstyle(1,RGB(0,255,0));
		bar(X1, Y1, X2, Y2);
		putimage(136,60, BarraVida.Sprite[0], COPY_PUT);
		
		//barra de dano preta
		setfillstyle(1,RGB(15,15,15));
		bar(X1DP1,Y1DP1,X2DP1,Y2DP1);

		// Barra de Stamina Azul
		setfillstyle(1,RGB(0,0,255));
		bar(SX1, SY1, SX2, SY2);
		putimage(136,96,BarraStamina.Sprite[0], OR_PUT);
		
		//barra de dano preta
		setfillstyle(1,RGB(15,15,15));
		bar(SX1DP1,SY1DP1,SX2DP1,SY2DP1);
		
		// Indicador de Vitoria abaixo da Vida
		if(VitoriasP1 == 1){
			putimage(383, 119, Vitoria.Mask[0], AND_PUT);
			putimage(383, 119, Vitoria.Sprite[0], OR_PUT);
		}
		
		if(VitoriasP1 == 2){
			putimage(383, 119, Vitoria.Mask[0], AND_PUT);
			putimage(383, 119, Vitoria.Sprite[0], OR_PUT);
			putimage(401, 119, Vitoria.Mask[0], AND_PUT);
			putimage(401, 119, Vitoria.Sprite[0], OR_PUT);
			
		}
		
		if(VitoriasP1 == 3){
			putimage(383, 119, Vitoria.Mask[0], AND_PUT);
			putimage(383, 119, Vitoria.Sprite[0], OR_PUT);
			putimage(401, 119, Vitoria.Mask[0], AND_PUT);
			putimage(401, 119, Vitoria.Sprite[0], OR_PUT);
			putimage(418, 119, Vitoria.Mask[0], AND_PUT);
			putimage(418, 119, Vitoria.Sprite[0], OR_PUT);
		}

		
		// PLAYER 2 (Direta)
		
		putimage(565, 25, Hud.Mask[1], AND_PUT);
		putimage(565, 25, Hud.Sprite[1], OR_PUT);
		putimage(869, 32, Icones.Mask[1], AND_PUT);
		putimage(869, 32, Icones.Sprite[1], OR_PUT);
		
		//barra de vida verde
		setfillstyle(1,RGB(0,255,0));
		bar(X1P, Y1P, X2P, Y2P);
		putimage(571,60, BarraVida.Sprite[1], COPY_PUT);
		
		//barra de dano preta
		setfillstyle(1,RGB(15,15,15));
		bar(X1DP2,Y1DP2,X2DP2,Y2DP2);

		// Barra de Stamina Azul
		setfillstyle(1,RGB(0,0,255));
		bar(SX1P, SY1P, SX2P, SY2P);
		putimage(571,96, BarraStamina.Sprite[1], OR_PUT);
		
		//barra de dano preta
		setfillstyle(1,RGB(15,15,15));
		bar(SX1DP2,SY1DP2,SX2DP2,SY2DP2);
		
		// Indicador de Vitoria abaixo da Vida
		if(VitoriasP2 == 1){
			putimage(606, 119, Vitoria.Mask[1], AND_PUT);
			putimage(606, 119, Vitoria.Sprite[1], OR_PUT);
		}
		
		if(VitoriasP2 == 2){
			putimage(606, 119, Vitoria.Mask[1], AND_PUT);
			putimage(606, 119, Vitoria.Sprite[1], OR_PUT);
			putimage(588, 119, Vitoria.Mask[1], AND_PUT);
			putimage(588, 119, Vitoria.Sprite[1], OR_PUT);
			
		}
		
		if(VitoriasP2 == 3){
			putimage(606, 119, Vitoria.Mask[1], AND_PUT);
			putimage(606, 119, Vitoria.Sprite[1], OR_PUT);
			putimage(588, 119, Vitoria.Mask[1], AND_PUT);
			putimage(588, 119, Vitoria.Sprite[1], OR_PUT);
			putimage(571, 119, Vitoria.Mask[1], AND_PUT);
			putimage(571, 119, Vitoria.Sprite[1], OR_PUT);
		}
		
	/*/desenhando o player 1
	setfillstyle(1,RGB(Player1.R,Player1.G,Player1.B));
	bar(Player1.X1,Player1.Y1,Player1.X2,Player1.Y2);
	
	//desenhando o soco
	//if(presJ == 1)
	bar(DgolpesP1S.X1,DgolpesP1S.Y1,DgolpesP1S.X2,DgolpesP1S.Y2);
	
	//desenhando o chute
	//if(presK == 1)
	setfillstyle(1,RGB(200,155,155));
	bar(DgolpesP1C.X1,DgolpesP1C.Y1,DgolpesP1C.X2,DgolpesP1C.Y2);
	
	//desenhando o player 2
	setfillstyle(1,RGB(Player2.R,Player2.G,Player2.B));
	bar(Player2.X1,Player2.Y1,Player2.X2,Player2.Y2);
	
	//desenhando o soco
	//if(presJ == 1)
	bar(DgolpesP2S.X1,DgolpesP2S.Y1,DgolpesP2S.X2,DgolpesP2S.Y2);
	
	//desenhando o chute
	//if(presK == 1)
	setfillstyle(1,RGB(155,155,255));
	bar(DgolpesP2C.X1,DgolpesP2C.Y1,DgolpesP2C.X2,DgolpesP2C.Y2);
	*/
		
	// ANIMAÇÕES
// Galo
// Idle
	if(direcaoP1 == 0 && (presD == 0 && presA == 0 && presS == 0 && presW == 0 && presJ == 0 && presK == 0 && presL == 0 && LevaDanoP1 == 0 
	&& varGancho == 0 && varSocoP1 == 0 && varChuteP1 == 0) && runAnimaDPP1 != 1 && runAnimaEPP1 != 1
	 || presA == 1 && presD == 1 && runAnimaDPP1 == 0 && runAnimaEPP1 == 0 && presS == 0){

    	putimage(Player1.X1 - 85,Player1.Y1 + 15,IdleG.Mask[(int(imgP1))], AND_PUT);
		putimage(Player1.X1 - 85,Player1.Y1 + 15,IdleG.Sprite[(int(imgP1))], OR_PUT);
	
		imgP1 = imgP1 + 0.1;
		if(imgP1 >= IdleG.QtdeSprites - 1){
			imgP1 = 0;
			
		}	
	}
	
	if(direcaoP1 == 1 && (presD == 0 && presA == 0 && presS == 0 && presW == 0 && presJ == 0 && presK == 0 && presL == 0 && LevaDanoP1 == 0
	&& varGancho == 0 && varSocoP1 == 0 && varChuteP1 == 0)&& runAnimaDPP1 != 1 && runAnimaEPP1 != 1){

    	putimage(Player1.X1 - 85,Player1.Y1 + 15,IdleGMirror.Mask[(int(imgP1))], AND_PUT);
		putimage(Player1.X1 - 85,Player1.Y1 + 15,IdleGMirror.Sprite[(int(imgP1))], OR_PUT);
			
		imgP1 = imgP1 + 0.1;
		if(imgP1 >= IdleGMirror.QtdeSprites - 1){
			imgP1 = 0;
			
		}	
	}
	
	
// Andando
	if(runAnimaDP1 == 1 && (presD == 1 && presA != 1 && presS != 1) && runAnimaDPP1 != 1 && runAnimaEPP1 != 1 
	&& varGancho == 0 && varSocoP1 == 0){
		
    	putimage(Player1.X1 - 70,Player1.Y1 + 15,AndandoG.Mask[(int(img2P1))], AND_PUT);
		putimage(Player1.X1 - 70,Player1.Y1 + 15,AndandoG.Sprite[(int(img2P1))], OR_PUT);
			
			img2P1 = img2P1 + 0.2;
			if(img2P1 >= AndandoG.QtdeSprites - 1){
				img2P1 = 0;
			}	
	}
	
	if(runAnimaAP1 == 1 && (presA == 1 && presD != 1 && presS != 1) && runAnimaDPP1 != 1 && runAnimaEPP1 != 1
	&& varGancho == 0 && varSocoP1 == 0){
		
    	putimage(Player1.X1 - 100,Player1.Y1 + 15,AndandoGMirror.Mask[(int(img2P1))], AND_PUT);
		putimage(Player1.X1 - 100,Player1.Y1 + 15,AndandoGMirror.Sprite[(int(img2P1))], OR_PUT);
			
			img2P1 = img2P1 + 0.2;
			if(img2P1 >= AndandoGMirror.QtdeSprites - 1){
				img2P1 = 0;
			}	
	}
	
	
// Agachar
	if ((presS == 1 && direcaoP1 == 0) && presW != 1 && runAnimaDPP1 != 1 && runAnimaEPP1 != 1 && varSocoP1 == 0 && varGancho == 0){
		putimage(Player1.X1 - 85,Player1.Y1 - 93,AgacharGMask,AND_PUT);
		putimage(Player1.X1 - 85,Player1.Y1 - 93,AgacharG,OR_PUT);
	}
	
	if ((presS == 1 && direcaoP1 == 1) && presW != 1 && runAnimaDPP1 != 1 && runAnimaEPP1 != 1 && varSocoP1 == 0 && varGancho == 0){
		putimage(Player1.X1 - 85,Player1.Y1 - 93,AgacharGMirrorMask,AND_PUT);
		putimage(Player1.X1 - 85,Player1.Y1 - 93,AgacharGMirror,OR_PUT);
	}
	
	
// Pulo
	if ((presW == 1 && direcaoP1 == 0) && presS != 1 || runAnimaDPP1 == 1){
		putimage(Player1.X1 - 85,Player1.Y1 + 15,PuloG.Mask[(int(img3P1))], AND_PUT);
		putimage(Player1.X1 - 85,Player1.Y1 + 15,PuloG.Sprite[(int(img3P1))], OR_PUT);
			
			img3P1 = img3P1 + 0.1;
			if(img3P1 >= PuloG.QtdeSprites - 1){
				img3P1 = 0;
			}	
	}
	
	if ((presW == 1 && direcaoP1 == 1) && presS != 1 || runAnimaEPP1 == 1){
		putimage(Player1.X1 - 85,Player1.Y1 + 15,PuloGMirror.Mask[(int(img3P1))], AND_PUT);
		putimage(Player1.X1 - 85,Player1.Y1 + 15,PuloGMirror.Sprite[(int(img3P1))], OR_PUT);
			
			img3P1 = img3P1 + 0.1;
			if(img3P1 >= PuloGMirror.QtdeSprites - 1){
				img3P1 = 0;
			}	
	}
	
	
// Defesa	
	if (presL == 1 && direcaoP1 == 0 && runAnimaDPP1 != 1 && runAnimaEPP1 != 1){
		putimage(Player1.X1 - 45,Player1.Y1 + 15,DefesaGMask,AND_PUT);
		putimage(Player1.X1 - 45,Player1.Y1 + 15,DefesaG,OR_PUT);
	}
	
	if (presL == 1 && direcaoP1 == 1 && runAnimaDPP1 != 1 && runAnimaEPP1 != 1){
		putimage(Player1.X1 - 125,Player1.Y1 + 15,DefesaGMirrorMask,AND_PUT);
		putimage(Player1.X1 - 125,Player1.Y1 + 15,DefesaGMirror,OR_PUT);
	}

// Soco 
	if ((presJ == 1 && direcaoP1 == 0) && presK != 1 && presS != 1 && runAnimaDPP1 != 1 && runAnimaEPP1 != 1 && varGancho == 0 && varChuteP1 == 0
	|| (varSocoP1 == 1 && direcaoP1 == 0) ){
		putimage(Player1.X1 - 85,Player1.Y1 + 15,SocoG.Mask[(int(img4P1))], AND_PUT);
		putimage(Player1.X1 - 85,Player1.Y1 + 15,SocoG.Sprite[(int(img4P1))], OR_PUT);
			
			img4P1 = img4P1 + 0.2;
			if(img4P1 >= SocoG.QtdeSprites - 1){
				img4P1 = 0;
			}	
	}
	
	if ((presJ == 1 && direcaoP1 == 1) && presK != 1 && presS != 1 && runAnimaDPP1 != 1 && runAnimaEPP1 != 1  && varGancho == 0 && varChuteP1 == 0 
	|| (varSocoP1 == 1 && direcaoP1 == 1)){
		putimage(Player1.X1 - 85,Player1.Y1 + 15,SocoGMirror.Mask[(int(img4P1))], AND_PUT);
		putimage(Player1.X1 - 85,Player1.Y1 + 15,SocoGMirror.Sprite[(int(img4P1))], OR_PUT);
			
			img4P1 = img4P1 + 0.2;
			if(img4P1 >= SocoGMirror.QtdeSprites - 1){
				img4P1 = 0;
			}	
	}


// Chute 
	if ((presK == 1 && direcaoP1 == 0) && presJ != 1 && presS != 1 && runAnimaDPP1 != 1 && runAnimaEPP1 != 1  && varSocoP1 == 0
	|| varChuteP1 == 1 && direcaoP1 == 0){
		putimage(Player1.X1 - 85,Player1.Y1 + 15,ChuteG.Mask[(int(img4P1))], AND_PUT);
		putimage(Player1.X1 - 85,Player1.Y1 + 15,ChuteG.Sprite[(int(img4P1))], OR_PUT);
			
			img4P1 = img4P1 + 0.2;
			if(img4P1 >= ChuteG.QtdeSprites - 1){
				img4P1 = 0;
			}	
	}
	
	if ((presK == 1 && direcaoP1 == 1) && presJ != 1 && presS != 1 && runAnimaDPP1 != 1 && runAnimaEPP1 != 1 && varSocoP1 == 0
	|| (varChuteP1 == 1 && direcaoP1 == 1)){
		putimage(Player1.X1 -85,Player1.Y1 + 15,ChuteGMirror.Mask[(int(img4P1))], AND_PUT);
		putimage(Player1.X1 -85,Player1.Y1 + 15,ChuteGMirror.Sprite[(int(img4P1))], OR_PUT);
			
			img4P1 = img4P1 + 0.2;
			if(img4P1 >= ChuteGMirror.QtdeSprites - 1){
				img4P1 = 0;
			}	
	}
	
	// Dano 
	if ((LevaDanoP1 == 1 && direcaoP1 == 0) && runAnimaDPP1 != 1 && runAnimaEPP1 != 1){
		putimage(Player1.X1 - 85,Player1.Y1 + 15,DanoG.Mask[(int(img6P1))], AND_PUT);
		putimage(Player1.X1 - 85,Player1.Y1 + 15,DanoG.Sprite[(int(img6P1))], OR_PUT);
			
			img6P1 = img6P1 + 0.2;
			if(img6P1 >= DanoG.QtdeSprites - 1){
				img6P1 = 0;
				LevaDanoP1 = 0;
			}	
	}
	
	if ((LevaDanoP1 == 1 && direcaoP1 == 1) && runAnimaDPP1 != 1 && runAnimaEPP1 != 1){
		putimage(Player1.X1 -85,Player1.Y1 + 15,DanoGMirror.Mask[(int(img6P1))], AND_PUT);
		putimage(Player1.X1 -85,Player1.Y1 + 15,DanoGMirror.Sprite[(int(img6P1))], OR_PUT);
			
			img6P1 = img6P1 + 0.2;
			if(img6P1 >= DanoGMirror.QtdeSprites - 1){
				img6P1 = 0;
				LevaDanoP1 = 0;
			}	
	}
	
	// Gancho
	if((presS ==1 && presJ == 1 && direcaoP1 == 0) && presW != 1 && varSocoP1 == 0 || (varGancho == 1 && direcaoP1 == 0)){
		
		putimage(Player1.X1 -85, Player1.Y1- 93,GanchoG.Mask[(int(img5P1))], AND_PUT);
		putimage(Player1.X1 -85,Player1.Y1 - 93,GanchoG.Sprite[(int(img5P1))], OR_PUT);
			
			img5P1 = img5P1 + 0.2;
			if(img5P1 >= GanchoG.QtdeSprites - 1){
				img5P1 = 0;
			}
	}
	
	if((presS == 1 && presJ == 1 && direcaoP1 == 1) && presW != 1 && varSocoP1 == 0 || (varGancho == 1 && direcaoP1 == 1)){
		
		putimage(Player1.X1 -85,Player1.Y1- 93,GanchoGMirror.Mask[(int(img5P1))], AND_PUT);
		putimage(Player1.X1 -85,Player1.Y1- 93,GanchoGMirror.Sprite[(int(img5P1))], OR_PUT);
			
			img5P1 = img5P1 + 0.2;
			if(img5P1 >= GanchoGMirror.QtdeSprites - 1){
				img5P1 = 0;
			}
	}
	
	
//	======================================
	
	
// Suricato
// Idle
	if(direcaoP2 == 1 && (presSR == 0 && presSL == 0 && presSD == 0 && presSU == 0 && pres1 == 0 && pres2 == 0 && pres3 == 0 && LevaDanoP2 == 0)
	 && runAnimaDPP2 != 1 && runAnimaEPP2 != 1 || presSL == 1 && presSR == 1 && presSD == 0 && runAnimaDPP2 == 0 && runAnimaEPP2 == 0){

    	putimage(Player2.X1-95,Player2.Y1,IdleSMirror.Mask[(int(imgP2))], AND_PUT);
		putimage(Player2.X1-95,Player2.Y1,IdleSMirror.Sprite[(int(imgP2))], OR_PUT);
			
		imgP2 = imgP2 + 0.1;
		if(imgP2 >= IdleSMirror.QtdeSprites - 1){
			imgP2 = 0;
			
		}	
	}

	if(direcaoP2 == 0 && (presSR == 0 && presSL == 0 && presSD == 0 && presSU == 0 && pres1 == 0 && pres2 == 0 && pres3 == 0 && LevaDanoP2 == 0)
	&& runAnimaDPP2 != 1 && runAnimaEPP2 != 1){

    	putimage(Player2.X1-85,Player2.Y1,IdleS.Mask[(int(imgP2))], AND_PUT);
		putimage(Player2.X1-85,Player2.Y1,IdleS.Sprite[(int(imgP2))], OR_PUT);
	
		imgP2 = imgP2 + 0.1;
		if(imgP2 >= IdleS.QtdeSprites - 1){
			imgP2 = 0;
			
		}	
	}
	
	
// Andando

	if(runAnimaAP2 == 1 && (presSL == 1 && presSR != 1 && presSD == 0) && runAnimaDPP2 != 1 && runAnimaEPP2 != 1){
		
    	putimage(Player2.X1-85,Player2.Y1,AndandoSMirror.Mask[(int(img2P2))], AND_PUT);
		putimage(Player2.X1-85,Player2.Y1,AndandoSMirror.Sprite[(int(img2P2))], OR_PUT);
			
			img2P2 = img2P2 + 0.18;
			if(img2P2 >= AndandoSMirror.QtdeSprites - 1){
				img2P2 = 0;
			}	
	}

	if(runAnimaDP2 == 1 && (presSR == 1 && presSL != 1 && presSD == 0) && runAnimaDPP2 != 1 && runAnimaEPP2 != 1){
		
    	putimage(Player2.X1-85,Player2.Y1,AndandoS.Mask[(int(img2P2))], AND_PUT);
		putimage(Player2.X1-85,Player2.Y1,AndandoS.Sprite[(int(img2P2))], OR_PUT);
			
			img2P2 = img2P2 + 0.18;
			if(img2P2 >= AndandoS.QtdeSprites - 1){
				img2P2 = 0;
			}	
	}
	
	
// Agachar
	if ((presSD == 1 && direcaoP2 == 0) && presSU != 1 && runAnimaDPP2 != 1 && runAnimaEPP2 != 1 && varGanchoP2 == 0){
		putimage(Player2.X1-85,Player2.Y1 - 130,AgacharSMask,AND_PUT);
		putimage(Player2.X1-85,Player2.Y1 - 130,AgacharS,OR_PUT);
	}
	
	if ((presSD == 1 && direcaoP2 == 1) && presSU != 1 && runAnimaDPP2 != 1 && runAnimaEPP2 != 1 && varGanchoP2 == 0){
		putimage(Player2.X1-85,Player2.Y1 - 130,AgacharSMirrorMask,AND_PUT);
		putimage(Player2.X1-85,Player2.Y1 - 130,AgacharSMirror,OR_PUT);
	}
	
	
// Pulo
	if ((presSU == 1 && direcaoP2 == 0) && presSD != 1 || runAnimaDPP2 == 1){
		putimage(Player2.X1-95,Player2.Y1,PuloS.Mask[(int(img3P2))], AND_PUT);
		putimage(Player2.X1-95,Player2.Y1,PuloS.Sprite[(int(img3P2))], OR_PUT);
			
			img3P2 = img3P2 + 0.1;
			if(img3P2 >= PuloS.QtdeSprites - 1){
				img3P2 = 0;
			}	
	}
	
	if ((presSU == 1 && direcaoP2 == 1) && presSD != 1 || runAnimaEPP2 == 1){
		putimage(Player2.X1-85,Player2.Y1,PuloSMirror.Mask[(int(img3P2))], AND_PUT);
		putimage(Player2.X1-85,Player2.Y1,PuloSMirror.Sprite[(int(img3P2))], OR_PUT);
			
			img3P2 = img3P2 + 0.1;
			if(img3P2 >= PuloSMirror.QtdeSprites - 1){
				img3P2 = 0;
			}	
	}
	
	
// Defesa	
	if (pres3 == 1 && direcaoP2 == 0 && runAnimaDPP2 != 1 && runAnimaEPP2 != 1){
		putimage(Player2.X1-65,Player2.Y1,DefesaSMask,AND_PUT);
		putimage(Player2.X1-65,Player2.Y1,DefesaS,OR_PUT);
	}
	
	if (pres3 == 1 && direcaoP2 == 1 && runAnimaDPP2 != 1 && runAnimaEPP2 != 1){
		putimage(Player2.X1-115,Player2.Y1,DefesaSMirrorMask,AND_PUT);
		putimage(Player2.X1-115,Player2.Y1,DefesaSMirror,OR_PUT);
	}

// Soco 
	if (pres1 == 1 && (direcaoP2 == 0 && pres2 != 1 && presSD == 0) && runAnimaDPP2 != 1 && runAnimaEPP2 != 1){
		putimage(Player2.X1-85,Player2.Y1,SocoS.Mask[(int(img4P2))], AND_PUT);
		putimage(Player2.X1-85,Player2.Y1,SocoS.Sprite[(int(img4P2))], OR_PUT);
			
			img4P2 = img4P2 + 0.2;
			if(img4P2 >= SocoS.QtdeSprites - 1){
				img4P2 = 0;
			}	
	}
	
	if (pres1 == 1 && (direcaoP2 == 1 && pres2 != 1 && presSD == 0) && runAnimaDPP2 != 1 && runAnimaEPP2 != 1){
		putimage(Player2.X1-85,Player2.Y1,SocoSMirror.Mask[(int(img4P2))], AND_PUT);
		putimage(Player2.X1-85,Player2.Y1,SocoSMirror.Sprite[(int(img4P2))], OR_PUT);
			
			img4P2 = img4P2 + 0.2;
			if(img4P2 >= SocoSMirror.QtdeSprites - 1){
				img4P2 = 0;
			}	
	}


// Chute 
	if ((pres2 == 1 && direcaoP2 == 0) && pres1 != 1 && presSD == 0 && runAnimaDPP2 != 1 && runAnimaEPP2 != 1){
		putimage(Player2.X1-65,Player2.Y1,ChuteS.Mask[(int(img4P2))], AND_PUT);
		putimage(Player2.X1-65,Player2.Y1,ChuteS.Sprite[(int(img4P2))], OR_PUT);
			
			img4P2 = img4P2 + 0.2;
			if(img4P2 >= ChuteS.QtdeSprites - 1){
				img4P2 = 0;
			}	
	}
	
	if ((pres2 == 1 && direcaoP2 == 1) && pres1 != 1 && presSD == 0 && runAnimaDPP2 != 1 && runAnimaEPP2 != 1){
		putimage(Player2.X1-115,Player2.Y1,ChuteSMirror.Mask[(int(img4P2))], AND_PUT);
		putimage(Player2.X1-115,Player2.Y1,ChuteSMirror.Sprite[(int(img4P2))], OR_PUT);
			
			img4P2 = img4P2 + 0.2;
			if(img4P2 >= ChuteSMirror.QtdeSprites - 1){
				img4P2 = 0;
			}	
	}
	
// Dano 
	if ((LevaDanoP2 == 1 && direcaoP2 == 0) && runAnimaDPP2 != 1 && runAnimaEPP2 != 1){
		putimage(Player2.X1 - 85,Player2.Y1,DanoS.Mask[(int(img6P2))], AND_PUT);
		putimage(Player2.X1 - 85,Player2.Y1,DanoS.Sprite[(int(img6P2))], OR_PUT);
			
			img6P2 = img6P2 + 0.2;
			if(img6P2 >= DanoS.QtdeSprites - 1){
				img6P2 = 0;
				LevaDanoP2 = 0;
			}	
	}
	
		if ((LevaDanoP2 == 1 && direcaoP2 == 1) && runAnimaDPP2 != 1 && runAnimaEPP2 != 1){
		putimage(Player2.X1 - 85,Player2.Y1,DanoSMirror.Mask[(int(img6P2))], AND_PUT);
		putimage(Player2.X1 - 85,Player2.Y1,DanoSMirror.Sprite[(int(img6P2))], OR_PUT);
			
			img6P2 = img6P2 + 0.2;
			if(img6P2 >= DanoSMirror.QtdeSprites - 1){
				img6P2 = 0;
				LevaDanoP2 = 0;
			}	
	}
	
	// Gancho
	if((presSD ==1 && pres1 == 1 && direcaoP2 == 0) && presSU != 1 && varSocoP2 == 0 || (varGanchoP2 == 1 && direcaoP2 == 0)){
		
		putimage(Player2.X1 -85, 300,GanchoS.Mask[(int(img5P2))], AND_PUT);
		putimage(Player2.X1 -85, 300,GanchoS.Sprite[(int(img5P2))], OR_PUT);
			
			img5P2 = img5P2 + 0.2;
			if(img5P2 >= GanchoS.QtdeSprites - 1){
				img5P2 = 0;
			}
	}
	
	if((presSD == 1 && pres1 == 1 && direcaoP2 == 1) && presSU != 1 && varSocoP2 == 0 || (varGanchoP2 == 1 && direcaoP2 == 1)){
		
		putimage(Player2.X1 -85,300,GanchoSMirror.Mask[(int(img5P2))], AND_PUT);
		putimage(Player2.X1 -85,300,GanchoSMirror.Sprite[(int(img5P2))], OR_PUT);
			
			img5P2 = img5P2 + 0.2;
			if(img5P2 >= GanchoSMirror.QtdeSprites - 1){
				img5P2 = 0;
			}
	}
	

// Indicando se o jogo foi Pausado -----------------------------------------------
	if(PausarJog){
		putimage(0, 0, Pausado.SpriteMask[1], AND_PUT);
		putimage(0, 0, Pausado.SpriteMask[0], OR_PUT);
	
	}
	
	// Indicando o final do round -----------------------------------------------
	if(FimDeRound){
		// Se o jogador 2 Ganhar
		if(X2DP1 >= X2){
			putimage(390, 300, VitoriaJog2.SpriteMask[1], AND_PUT);
			putimage(390, 300, VitoriaJog2.SpriteMask[0], OR_PUT);
		}
		
		// Se o jogador 1 Ganhar
		if(X1DP2 <= X1P){
			putimage(390, 300, VitoriaJog1.SpriteMask[1], AND_PUT);
			putimage(390, 300, VitoriaJog1.SpriteMask[0], OR_PUT);
		}
			
		if(VitoriasP1 == 3 || VitoriasP2 == 3){
			putimage(250,500, Rematch.SpriteMask[1], AND_PUT);
			putimage(250,500, Rematch.SpriteMask[0], OR_PUT);
			putimage(535,500, VoltarMenu.SpriteMask[1], AND_PUT);
			putimage(535,500, VoltarMenu.SpriteMask[0], OR_PUT);
		}
	}
	
	// As condições que representa o estado da vida está relacionada nas barras pretras
	// que sobrepõem a barra verde da vida de cada jogador, criando a ilusão que a barra diminui
	
	// Enquanto o gtRound1 for menor que o valor estático do gtRound2,
	// aparecerá na tela um indicador do round atual
	if(gtRound1 < gtRound2){
		if(RoundAtual == 1){
			putimage(400,310, Round1.SpriteMask[1], AND_PUT);
			putimage(400,310, Round1.SpriteMask[0], OR_PUT);
		}
		
		if(RoundAtual == 2){
			putimage(400,310, Round2.SpriteMask[1], AND_PUT);
			putimage(400,310, Round2.SpriteMask[0], OR_PUT);
		}
		
		if(RoundAtual == 3){
			putimage(400,311, Round3.SpriteMask[1], AND_PUT);
			putimage(400,311, Round3.SpriteMask[0], OR_PUT);
		}
		
		if(RoundAtual == 4){
			putimage(400,311, Round4.SpriteMask[1], AND_PUT);
			putimage(400,311, Round4.SpriteMask[0], OR_PUT);
		}
		
		if(RoundAtual == 5){
			putimage(400,311, Round5.SpriteMask[1], AND_PUT);
			putimage(400,311, Round5.SpriteMask[0], OR_PUT);
		}
	}
	
		//Fim da Parte Visual
		setvisualpage(pg);
		//=================================================================
		
	//Calculos
	//=================================================================
			
// Calculos dos estados do jogo ======================================

	// Verifica se a vida de um dos jogadores foi zerada, e encerra o round
	if(!FimDeRound){
		// As condições que representa o estado da vida está relacionada nas barras pretras
		// que sobrepõem a barra verde da vida de cada jogador, criando a ilusão que a barra diminui
		if(X1DP2 <= X1P || X2DP1 >= X2){
			FimDeRound = true;
			// Vitoria do P1
			if(X1DP2 <= X1P){
					VitoriasP1 ++;
			}
			// Vitoria do P2
			if(X2DP1 >= X2){
					VitoriasP2 ++;
			}	
		}
	}
	
	// Preparando os comandos do mouse
	// Caso algum dos jogadores ganhe 3 rounds, quando aparecer o balão de vitória
	// o jogador tera a opção de escolher entre começar uma nova partida ou sair do jogo.
	if(VitoriasP1 == 3 || VitoriasP2 == 3)
		DecisaoFinal = true;
	
	// Controlando o tempo de espera para começar um round
	// Quando a variavel dinâmica somar até alcançar o valor estático,
	// Várias áreas do código serão liberadas para o jogador conseguir executar ações
	if(gtRound1 < gtRound2 && !DecisaoFinal){
		gtRound1 ++;
	}
	
	// Controlando o tempo de espera para terminar um round
	if(FimDeRound){
		gtFimDeRound1++;
		if(gtFimDeRound1 == gtFimDeRound2 && !DecisaoFinal){
			gtFimDeRound1 = 0;
			FimDeRound = false;
			if(!DecisaoFinal)
				NovoRound = true;
		}
	}
	
	// Fim dos Calculos de estados ======================
		
		// CONDIÇÃO DE PAUSA!!!
	if(!PausarJog){
			//Calculo de Andar
		//============================================
		//Galo
		// Calculo D
		if (presD == 1 && varSocoP1 == 0 && varGancho == 0 && presS == 0){
			direcaoP1 = 0;
				DgolpesP1S.X1 = Player1.X1 + 140;
				DgolpesP1S.X2 = Player1.X2 + 35;
				DgolpesP1S.Y1 = Player1.Y1 + 95;
				DgolpesP1S.Y2 = Player1.Y2 - 185;
					
				DgolpesP1C.X1 = Player1.X1 + 140;
				DgolpesP1C.X2 = Player1.X2 + 35;
				DgolpesP1C.Y1 = Player1.Y1 + 110;
				DgolpesP1C.Y2 = Player1.Y2 - 140;
				
			if(presS == 0 && Player1.X2 <= LarTela-borda){
			
				MovimentacaoP1 = 1;
				runAnimaDP1 = 1;
				
				if ((DgolpesP1S.X2 >= Player2.X1 && DgolpesP1S.X1 <= Player2.X1) && Player1.Y1 >= Player2.Y1){
					MovimentacaoP1 = 0;
				}
				
				if (MovimentacaoP1 == 1){
					Player1.X1 += Player1.VelocX;
					Player1.X2 += Player1.VelocX;
					DgolpesP1S.X1 += Player1.VelocX;
					DgolpesP1S.X2 += Player1.VelocX;
					DgolpesP1C.X1 += Player1.VelocX;
					DgolpesP1C.X2 += Player1.VelocX;
					
					
				}
			}
			else{
				
				MovimentacaoP1 = 0;
				runAnimaDP1 = 0;
				
			}
		}
		
		//Tecla A
		if (presA == 1 && varGancho == 0 && varSocoP1 == 0 && presS == 0){
			direcaoP1 = 1;
				DgolpesP1S.X1 = Player1.X1 - 35;
				DgolpesP1S.X2 = Player1.X2 - 140;
				DgolpesP1S.Y1 = Player1.Y1 + 95;
				DgolpesP1S.Y2 = Player1.Y2 - 185;
							
				DgolpesP1C.X1 = Player1.X1 - 35;
				DgolpesP1C.X2 = Player1.X2 - 140;
				DgolpesP1C.Y1 = Player1.Y1 + 110;
				DgolpesP1C.Y2 = Player1.Y2 - 140;
			
			if(presS == 0 && Player1.X1 >= borda){ 
			
			 	MovimentacaoP1 = 1;
			 	runAnimaAP1 = 1;
			 	
			 	if ((DgolpesP1S.X1 <= Player2.X2 && DgolpesP1S.X2 >= Player2.X2) && Player1.Y1 >= Player2.Y1){
					MovimentacaoP1 = 0;
				}
			 	
			 	
			 	if (MovimentacaoP1 == 1){
					Player1.X1 -= Player1.VelocX;
					Player1.X2 -= Player1.VelocX;
					DgolpesP1S.X1 -= Player1.VelocX;
					DgolpesP1S.X2 -= Player1.VelocX;
					DgolpesP1C.X1 -= Player1.VelocX;
					DgolpesP1C.X2 -= Player1.VelocX;
				}
				
			}
			else {
				MovimentacaoP1 = 0;
				runAnimaAP1 = 0;
			}
		}
		
		//Suricato
		
		// Tecla Seta Direita
	
		//direção da hitbox direita
		if (presSR == 1  && varGanchoP2 == 0 && varSocoP2 == 0 && presSD == 0){
			direcaoP2 = 0;
				DgolpesP2S.X1 = Player2.X1 + 130;
				DgolpesP2S.X2 = Player2.X2 + 35;
				DgolpesP2S.Y1 = Player2.Y1 + 90;
				DgolpesP2S.Y2 = Player2.Y2 - 185;
							
				DgolpesP2C.X1 = Player2.X1 + 130;
				DgolpesP2C.X2 = Player2.X2 + 35;
				DgolpesP2C.Y1 = Player2.Y1 + 120;
				DgolpesP2C.Y2 = Player2.Y2 - 145;
				
			if(presSD == 0 && Player2.X2 <= LarTela-borda){
			
				MovimentacaoP2 = 1;
				runAnimaDP2 = 1;
				
				if ((DgolpesP2S.X2 >= Player1.X1 && DgolpesP2S.X1 <= Player1.X1) && Player2.Y1 >= Player1.Y1){
					MovimentacaoP2 = 0;
				}
				
				if (MovimentacaoP2 == 1){
					Player2.X1 += Player2.VelocX;
					Player2.X2 += Player2.VelocX;
					DgolpesP2S.X1 += Player2.VelocX;
					DgolpesP2S.X2 += Player2.VelocX;
					DgolpesP2C.X1 += Player2.VelocX;
					DgolpesP2C.X2 += Player2.VelocX;
				}
			}
			else{
				
				MovimentacaoP2 = 0;
				
			}
		}
	
	
	//	======================================
		
	
	// Tecla Seta Esquerda
		
		//direção da hitbox esquerda
		if (presSL == 1 && varGanchoP2 == 0 && varSocoP2 == 0 && presSD == 0){
			direcaoP2 = 1;
				DgolpesP2S.X1 = Player2.X1 - 35;
				DgolpesP2S.X2 = Player2.X2 - 130;
				DgolpesP2S.Y1 = Player2.Y1 + 90;
				DgolpesP2S.Y2 = Player2.Y2 - 185;
					
				DgolpesP2C.X1 = Player2.X1 - 35;
				DgolpesP2C.X2 = Player2.X2 - 130;
				DgolpesP2C.Y1 = Player2.Y1 + 120;
				DgolpesP2C.Y2 = Player2.Y2 - 145;
			
			if(presSD == 0 && Player2.X1 >= borda){ 
			
			 	MovimentacaoP2 = 1;
			 	runAnimaAP2 = 1;
			 	if ((DgolpesP2S.X1 <= Player1.X2 && DgolpesP2S.X2 >= Player1.X2) && Player2.Y1 >= Player1.Y1){
					MovimentacaoP2 = 0;
				}
			 	
			 	
			 	if (MovimentacaoP2 == 1){
					Player2.X1 -= Player2.VelocX;
					Player2.X2 -= Player2.VelocX;
					DgolpesP2S.X1 -= Player2.VelocX;
					DgolpesP2S.X2 -= Player2.VelocX;
					DgolpesP2C.X1 -= Player2.VelocX;
					DgolpesP2C.X2 -= Player2.VelocX;
				}
				
			}
			else {
				MovimentacaoP2 = 0;
				
			}
		}
	
	//	======================================
	
	//Calculo de Pular
	//============================================
	//Galo
	
	// Tecla W
		if(presW == 1 || (Player1.Y2 < 595 && caindoP1 != 1)){
			
			if(runAnimaDPP1 == 0 && direcaoP1 == 0){
				runAnimaDPP1 = 1;
				runAnimaEPP1 = 0;
			}
			
			if(runAnimaEPP1 == 0 && direcaoP1 == 1){
				runAnimaEPP1 = 1;
				runAnimaDPP1 = 0;
			}
			
			Player1.Y1 -= Player1.VelocY;
			Player1.Y2 -= Player1.VelocY;
			//VARIAVEL PARA SUBIR A HITBOX DO SOCO
			DgolpesP1S.Y1 -= Player1.VelocY;
			DgolpesP1S.Y2 -= Player1.VelocY;
			//VARIAVEL PARA SUBIR A HITBOX DO CHUTE
			DgolpesP1C.Y1 -= Player1.VelocY;
			DgolpesP1C.Y2 -= Player1.VelocY;
			
			if(presS == 1)
				presS = 0;
				
			// limite do Pulo
			if (Player1.Y1 <= 140) {
				caindoP1 = 1;
				
			}
		}
		
		if(caindoP1 == 1){
			
		if(runAnimaDPP1 == 0 && direcaoP1 == 0){
				runAnimaDPP1 = 0;
				runAnimaEPP1 = 1;
			}
			
			if(runAnimaEPP1 == 0 && direcaoP1 == 1){
				runAnimaEPP1 = 1;
				runAnimaDPP1 = 0;
			}
			
			Player1.Y1 += Player1.VelocY;
			Player1.Y2 += Player1.VelocY;
			//VARIAVEL PARA DESCER A HITBOX DO SOCO
			DgolpesP1S.Y1 += Player1.VelocY;
			DgolpesP1S.Y2 += Player1.VelocY;
			//VARIAVEL PARA DESCER A HITBOX DO CHUTE
			DgolpesP1C.Y1 += Player1.VelocY;
			DgolpesP1C.Y2 += Player1.VelocY;
			
			if(presS == 1)
				presS = 0;
			
			// Limite do caindo
			if(Player1.Y2 > 595){
				caindoP1 = 0;
				runAnimaDPP1 = 0;
				runAnimaEPP1 = 0;
				img3P1 = 0;
			}
		}
		
		
	//Suricato
	
	// Seta para Cima
		if(presSU == 1 || (Player2.Y2 < 595 && caindoP2 != 1)){
			
			if(runAnimaDPP2 == 0 && direcaoP2 == 0){
				runAnimaDPP2 = 1;
				runAnimaEPP2 = 0;
			}
			
			if(runAnimaEPP2 == 0 && direcaoP2 == 1){
				runAnimaEPP2 = 1;
				runAnimaDPP2 = 0;
			}
			
			Player2.Y1 -= Player2.VelocY;
			Player2.Y2 -= Player2.VelocY;
			//VARIAVEL PARA SUBIR A HITBOX DO SOCO
			DgolpesP2S.Y1 -= Player2.VelocY;
			DgolpesP2S.Y2 -= Player2.VelocY;
			//VARIAVEL PARA SUBIR A HITBOX DO CHUTE
			DgolpesP2C.Y1 -= Player2.VelocY;
			DgolpesP2C.Y2 -= Player2.VelocY;
			
			if(presSD == 1)
				presSD = 0;
				
			// limite do Pulo
			if (Player2.Y1 <= 140) {
				caindoP2 = 1;
				
			}
		}
		
		if(caindoP2 == 1){
			
			if(runAnimaDPP2 == 0 && direcaoP2 == 0){
				runAnimaDPP2 = 1;
				runAnimaEPP2 = 0;
			}
			
			if(runAnimaEPP2 == 0 && direcaoP2 == 1){
				runAnimaEPP2 = 1;
				runAnimaDPP2 = 0;
			}
			
			Player2.Y1 += Player2.VelocY;
			Player2.Y2 += Player2.VelocY;
			//VARIAVEL PARA DESCER A HITBOX DO SOCO
			DgolpesP2S.Y1 += Player2.VelocY;
			DgolpesP2S.Y2 += Player2.VelocY;
			//VARIAVEL PARA DESCER A HITBOX DO CHUTE
			DgolpesP2C.Y1 += Player2.VelocY;
			DgolpesP2C.Y2 += Player2.VelocY;
			
			if(presSD == 1)
				presSD = 0;
			
			// Limite do caindo
			if(Player2.Y2 > 595){
				caindoP2 = 0;
				runAnimaDPP2 = 0;
				runAnimaEPP2 = 0;
				img3P2 = 0;
			}
		}
		
	//	======================================
	
	
	//Calculo de Agachar
	//============================================
	//Galo
	// Tecla S
	if(presS == 1 && presW !=1 && varSocoP1 == 0){
		Player1.Y1 = 408;
		
	}
	else if (presS == 0 && Player1.Y1 == 408 && varGancho == 0){
		Player1.Y1 = 300;
	}
	
	
	//Suricato
	// Seta para Baixo
	if(presSD == 1 && presSU !=1 && varSocoP2 == 0){
		Player2.Y1 = 430;
	}
	else if (presSD == 0 && Player2.Y1 == 430 && varGanchoP2 == 0){
		Player2.Y1 = 300;
	}
	
	
	//	======================================
	
	
	//Calculo do Soco
	//============================================
	//Galo	
	// Tecla J
	if(direcaoP1 == 0){
		// Soco para Direita
		if(presJ == 1 && presS == 0 &&  varGancho == 0 && varChuteP1 == 0|| (DgolpesP1S.X1 > Player1.X1 + 140 && SocoVP1 != 1)){
			
			varSocoP1 = 1;	
			DgolpesP1S.X1 += Player1.VelocX;
			DgolpesP1S.X2 += Player1.VelocX;
				
			presJ = 1;
				
			if(DgolpesP1S.X2 >= Player1.X2 + 90){
				SocoVP1 = 1;
				DelaySP1++;
				ContadorP1++;
				CooldownP1++;
			}
		}
			
		if(SocoVP1 == 1){
				
			presJ = 0;
			
			DgolpesP1S.X1 -= Player1.VelocX;
			DgolpesP1S.X2 -= Player1.VelocX;
				
			if(DgolpesP1S.X1 < Player1.X1 + 147){
				SocoVP1 = 0;
				varSocoP1 = 0;
				img4P1 = 0;
			}
				
		}
	}
		
		
	if(direcaoP1 == 1){
		// Soco para Esquerda
		if(presJ == 1 && presS == 0 && varGancho == 0 && varChuteP1 == 0 || (DgolpesP1S.X2 < Player1.X1 - 10 && SocoVP1 != 1)){
			
			varSocoP1 = 1;	
			DgolpesP1S.X1 -= Player1.VelocX;
			DgolpesP1S.X2 -= Player1.VelocX;
				
			presJ = 1;
				
			if(DgolpesP1S.X1 <= Player1.X1 - 90){
				SocoVP1 = 1;
				DelaySP1++;
				ContadorP1++;
				CooldownP1++;
			}
		}
			
		if(SocoVP1 == 1){
			presJ = 0;
			DgolpesP1S.X1 += Player1.VelocX;
			DgolpesP1S.X2 += Player1.VelocX;
				
			if(DgolpesP1S.X2 > Player1.X2 - 147){
				SocoVP1 = 0;
				varSocoP1 = 0;
				img4P1 = 0;
			}
				
		}
	}
	
	// Delay do Soco
	if (DelaySP1 >= 4){
		DelaySP1++;
		presA = 0;
		presD = 0;
		if (DelaySP1 >= 75){
			DelaySP1 = 0;
		}
	}
	
	
	// Cooldown de cada Soco
	if(CooldownP1 > 0 && CooldownP1 < 4){
		TempCooldownP1++;
			
		if(TempCooldownP1 >= 55){
			TempCooldownP1 = 0;
			CooldownP1 = 0;
			DelaySP1 = 0;
		}
	}
	
	
	
	//Suricato	
	// Tecla 1
	if(direcaoP2 == 0){
		// Soco para Direita
		if(pres1 == 1 && presSD == 0 && varGanchoP2 == 0 && varChuteP2 == 0 || (DgolpesP2S.X1 > Player2.X1 + 130 && SocoVP2 != 1)){
			
			varSocoP2 = 1;
			DgolpesP2S.X1 += Player2.VelocX;
			DgolpesP2S.X2 += Player2.VelocX;
				
			pres1 = 1;
			
			if(DgolpesP2S.X2 >= Player2.X2 + 65){
				SocoVP2 = 1;
				DelaySP2++;
				ContadorP2++;
				
			}
		}
			
		if(SocoVP2 == 1){
				
			pres1 = 0;
			DgolpesP2S.X1 -= Player2.VelocX;
			DgolpesP2S.X2 -= Player2.VelocX;
				
			if(DgolpesP2S.X1 < Player2.X1 + 137){
				SocoVP2 = 0;
				varSocoP2 = 0;
			}
				
		}
	}
		
		
	if(direcaoP2 == 1){
		// Soco para Esquerda
		if(pres1 == 1 && presSD == 0 && varGanchoP2 == 0 && varChuteP2 == 0 || (DgolpesP2S.X2 < Player2.X1 - 10 && SocoVP2 != 1)){
			
			varSocoP2 = 1;
			DgolpesP2S.X1 -= Player2.VelocX;
			DgolpesP2S.X2 -= Player2.VelocX;
				
			pres1 = 1;
				
			if(DgolpesP2S.X1 <= Player2.X1 - 60){
				SocoVP2 = 1;
				DelaySP2++;
				ContadorP2++;
			}
		}
			
		if(SocoVP2 == 1){
			pres1 = 0;
			DgolpesP2S.X1 += Player2.VelocX;
			DgolpesP2S.X2 += Player2.VelocX;
				
			if(DgolpesP2S.X2 > Player2.X2 - 137){
				SocoVP2 = 0;
				varSocoP2 = 0;
			}
				
		}
	}
		
	// Delay do Soco
	
	if (DelaySP2 >= 4){
		DelaySP2++;
		presSL = 0;
		presSR = 0;
		if (DelaySP2 >= 75){
			DelaySP2 = 0;
		}
	}
	
	
	
	//	======================================
	
	
	//Calculo do Chute
	//============================================
	//Galo	
	
	// Tecla K
	if (direcaoP1 == 0){
		if(presK == 1 && presJ == 0 && varChuteP1 == 0 && varSocoP1 == 0 && presS == 0|| (DgolpesP1C.X1 > Player1.X1 + 140 && ChuteVP1 != 1)){
			
			varChuteP1 = 1;
			DgolpesP1C.X1 += Player1.VelocX;
			DgolpesP1C.X2 += Player1.VelocX;
			
			presK = 1;
			
			if (DgolpesP1C.X2 >= Player1.X2 + 90){
				ChuteVP1 = 1;
				DelayCP1++;
				ContadorP2++;
			}
		}
		
		if (ChuteVP1 == 1){
			presK = 0;
			DgolpesP1C.X1 -= Player1.VelocX;
			DgolpesP1C.X2 -= Player1.VelocX;
			
			if (DgolpesP1C.X1 < Player1.X1 + 147){
				ChuteVP1 = 0;
				varChuteP1 = 0;
			}
		}
	}
	
	
	if (direcaoP1 == 1){
		if(presK == 1 && presJ == 0 && varChuteP1 == 0 && varSocoP1 == 0 && presS == 0 || (DgolpesP1C.X2 < Player1.X1 - 10 && ChuteVP1 != 1)){
			
			varChuteP1 = 1;
			DgolpesP1C.X1 -= Player1.VelocX;
			DgolpesP1C.X2 -= Player1.VelocX;
			
			presK = 1;
			
			if (DgolpesP1C.X1 <= Player1.X1 - 90){
				ChuteVP1 = 1;
				DelayCP1++;
				ContadorP2++;
			}
		}
		
		if (ChuteVP1 == 1){
			presK = 0;
			DgolpesP1C.X1 += Player1.VelocX;
			DgolpesP1C.X2 += Player1.VelocX;
			
			if (DgolpesP1C.X2 > Player1.X2 - 147){
				ChuteVP1 = 0;
				varChuteP1 = 0;
			}
		}
	}
	
	// Delay do Chute
	
	if (DelayCP1 >= 2){
		DelayCP1++;
		presD = 0;
		presA = 0;
		if (DelayCP1 >= 75){
			DelayCP1 = 0;
		}
	}
	
	
	
	
	//Suricato	
	
	// Tecla 2
	if (direcaoP2 == 0){
		if(pres2 == 1 && pres1 == 0 && varChuteP2 == 0 && varSocoP2 == 0 && presSD == 0 || (DgolpesP2C.X1 > Player2.X1 + 130 && ChuteVP2 != 1)){
			
			varChuteP2 = 1;
			DgolpesP2C.X1 += Player2.VelocX;
			DgolpesP2C.X2 += Player2.VelocX;
			
			pres2 = 1;
			
			if (DgolpesP2C.X2 >= Player2.X2 + 75){
				ChuteVP2 = 1;
				DelayCP2++;
				ContadorP2++;
			}
		}
		
		if (ChuteVP2 == 1){
			pres2 = 0;
			DgolpesP2C.X1 -= Player2.VelocX;
			DgolpesP2C.X2 -= Player2.VelocX;
			
			if (DgolpesP2C.X1 < Player2.X1 + 137){
				ChuteVP2 = 0;
				varChuteP2 = 0;
			}
		}
	}
	
	
	if (direcaoP2 == 1){
		if(pres2 == 1 && pres1 == 0 && varChuteP2 == 0 && varSocoP2 == 0 && presSD == 0 || (DgolpesP2C.X2 < Player2.X1 - 10 && ChuteVP2 != 1)){
			
			varChuteP2 = 1;
			DgolpesP2C.X1 -= Player2.VelocX;
			DgolpesP2C.X2 -= Player2.VelocX;
			
			pres2 = 1;
			
			if (DgolpesP2C.X1 <= Player2.X1 - 75){
				ChuteVP2 = 1;
				DelayCP2++;
				ContadorP2++;
			}
		}
		
		if (ChuteVP2 == 1){
			pres2 = 0;
			DgolpesP2C.X1 += Player2.VelocX;
			DgolpesP2C.X2 += Player2.VelocX;
			
			if (DgolpesP2C.X2 > Player2.X2 - 137){
				ChuteVP2 = 0;
				varChuteP2 = 0;
			}
		}
	}
	
	// Delay do Chute
	
	if (DelayCP2 >= 2){
		DelayCP2++;
		presSL = 0;
		presSR = 0;
		if (DelayCP2 >= 75){
			DelayCP2 = 0;
		}
	}
	
	//Calculo Anti Aerio
	//========================================================
	//Galo
	if (presJ == 1 && presS == 1 && GanchoVP1 != 1 && varSocoP1 == 0|| (DgolpesP1S.Y2 < Player1.Y2 - 190 && GanchoVP1 != 1)){
		varGancho = 1;
		DgolpesP1S.Y1 -= Player1.VelocY;
		DgolpesP1S.Y2 -= Player1.VelocY;
		
		if (DgolpesP1S.Y1 <= Player1.Y1 - 110){
			GanchoVP1 = 1;
			DelayGanchoP1++;
		}
		

	}
	
	if (GanchoVP1 == 1 ){
		varGancho = 1;
		DgolpesP1S.Y1 += Player1.VelocY;
		DgolpesP1S.Y2 += Player1.VelocY;
		
		if(DgolpesP1S.Y2 > Player1.Y2 - 190){
			GanchoVP1 = 0;
			varGancho = 0;
			img5P1 = 0;
		}
			
	}
	
	if (DelayGanchoP1 >= 1){
		DelayGanchoP1++;
		if (DelayGanchoP1 >= 85){
			DelayGanchoP1 = 0;
		}
	}
	
	//Suricato
	if (pres1 == 1 && presSD == 1 && GanchoVP2 != 1 && varSocoP2 == 0|| (DgolpesP2S.Y2 < Player2.Y2 - 190 && GanchoVP2 != 1)){
		varGanchoP2 = 1;
		DgolpesP2S.Y1 -= Player2.VelocY;
		DgolpesP2S.Y2 -= Player2.VelocY;
		
		if (DgolpesP2S.Y1 <= Player2.Y1 - 110){
			GanchoVP2 = 1;
			DelayGanchoP2++;
		}
		

	}
	
	
	if (GanchoVP2 == 1 ){
		varGanchoP2 = 1;
		DgolpesP2S.Y1 += Player2.VelocY;
		DgolpesP2S.Y2 += Player2.VelocY;
		
		if(DgolpesP2S.Y2 > Player2.Y2 - 190){
			GanchoVP2 = 0;
			varGanchoP2 = 0;
			img5P2 = 0;
		}
			
	}
	
	if (DelayGanchoP2 >= 1){
		DelayGanchoP2++;
		if (DelayGanchoP2 >= 85){
			DelayGanchoP2 = 0;
		}
	}
	
	//	======================================
	
	
	//Calculo dos Danos
	//============================================
	//Galo	
	
	// Soco
	if(DgolpesP1S.X2 > Player2.X1 && DgolpesP1S.X1 < Player2.X2
	&& DgolpesP1S.Y1 < Player2.Y2 && DgolpesP1S.Y2 > Player2.Y1 && presJ == 1 && presS == 0){
		if(InvenciP2 != 1){
			if (pres3 == 1){
				sndPlaySound(".\\sons\\Bloqueio.wav", SND_ASYNC);
				SX1DP2 -= 15;
				SocoVP1 = 1;
				DelaySP1++;
				if(SX1DP2 <= 571)
					SX1DP2 = 571;
			}
			// Se a stamina acabar
			else if (SX1DP2 <= 571){
				sndPlaySound(".\\sons\\SocoNoSuricato.wav", SND_ASYNC);
				X1DP2 -= Player1.Dano + 5;
				SocoVP1 = 1;
				DelaySP1++;
				ContadorP1++;
				LevaDanoP2 = 1;
				if(X1DP2 <= 571){
					X1DP2 = 571;
				}
			}
			else{
				sndPlaySound(".\\sons\\SocoNoSuricato.wav", SND_ASYNC);
				X1DP2 -= Player1.Dano + 5;
				SocoVP1 = 1;
				DelaySP1++;
				ContadorP1++;
				LevaDanoP2 = 1;
				if(X1DP2 <= 571){
					X1DP2 = 571;
				}
			}
			if (ContadorP1 == 4){
				EmpurraoP2 = true;
				LevaDanoP2 = 0;
				InvenciP2 = 1;
			}
			
		}
	}
	
	
	// Chute
	if(DgolpesP1C.X2 > Player2.X1 && DgolpesP1C.X1 < Player2.X2
	&& DgolpesP1C.Y1 < Player2.Y2 && DgolpesP1C.Y2 > Player2.Y1 && presK == 1){
		if(InvenciP2 != 1){
			if (pres3 == 1){
				sndPlaySound(".\\sons\\Bloqueio.wav", SND_ASYNC);
				SX1DP2 -= 20;
				ChuteVP1 = 1;
				DelayCP1++;
				if(SX1DP2 <= 571)
					SX1DP2 = 571;
			}
			// Se a stamina acabar
			else if (SX1DP2 <= 571){
				sndPlaySound(".\\sons\\ChuteNoSuricato.wav", SND_ASYNC);
				X1DP2 -= Player1.Dano + 10;
				ChuteVP1 = 1;
				DelayCP1++;
				ContadorP1++;
				LevaDanoP2 = 1;
				if(X1DP2 <= 571){
					X1DP2 = 571;
				}
			}
			else{
				sndPlaySound(".\\sons\\ChuteNoSuricato.wav", SND_ASYNC);
		    	X1DP2 -= Player1.Dano + 10;
				ChuteVP1 = 1;
				DelayCP1++;
				ContadorP1++;
				LevaDanoP2 = 1;
				if(X1DP2 <= 571){
					X1DP2 = 571;
				}
			}
			if (ContadorP1 == 2){
				EmpurraoP2 = true;
				LevaDanoP2 = 0;
				InvenciP2 = 1;
			}
		}
	}
	
	// Gancho
	if(DgolpesP1S.X2 > Player2.X1 && DgolpesP1S.X1 < Player2.X2
	&& DgolpesP1S.Y1 < Player2.Y2 && DgolpesP1S.Y2 > Player2.Y1 && presJ == 1 && presS == 1){
		if(InvenciP2 != 1){
			
			sndPlaySound(".\\sons\\SocoNoSuricato.wav", SND_ASYNC);
			X1DP2 -= Player1.Dano + 20;
			DelayGanchoP1++;
			LevaDanoP2 = 1;
			ContadorP1 += 4;
			if(X1DP2 <= 571){
				X1DP2 = 571;
			}
			if (ContadorP1 == 4){
				EmpurraoP2 = true;
				LevaDanoP2 = 0;
				InvenciP2 = 1;
			}	
		}
	}
	
	
	
	//Suricato	
	
	// Soco
	if(DgolpesP2S.X2 > Player1.X1 && DgolpesP2S.X1 < Player1.X2
	&& DgolpesP2S.Y1 < Player1.Y2 && DgolpesP2S.Y2 > Player1.Y1 && pres1 == 1 && presSD == 0){
		if(InvenciP1 != 1){
			if (presL == 1){
				sndPlaySound(".\\sons\\Bloqueio.wav", SND_ASYNC);
				SX2DP1 += 10;
				SocoVP2 = 1;
				DelaySP2++;
				if(SX2DP1 >= 429)
					SX2DP1 = 429;
			}
			// Se a stamina acabar
			else if (SX2DP1 >= 429){
				sndPlaySound(".\\sons\\SocoNoGalo.wav", SND_ASYNC);
				X2DP1 += Player2.Dano;
				SocoVP2 = 1;
				DelaySP2++;
				ContadorP2++;
				LevaDanoP1 = 1;
				if(X2DP1 >= 429){
					X2DP1 = 429;
				}
			}
			else{
				sndPlaySound(".\\sons\\SocoNoGalo.wav", SND_ASYNC);
		    	X2DP1 += Player2.Dano;
				SocoVP2 = 1;
				DelaySP2++;
				ContadorP2++;
				LevaDanoP1 = 1;
				if(X2DP1 >= 429){
					X2DP1 = 429;
				}
			}
			if (ContadorP2 == 4){
				EmpurraoP1 = true;
				LevaDanoP1 = 0;
				InvenciP1 = 1;
			}
		}
	}
	
	
	// Chute
	if(DgolpesP2C.X2 > Player1.X1 && DgolpesP2C.X1 < Player1.X2
	&& DgolpesP2C.Y1 < Player1.Y2 && DgolpesP2C.Y2 > Player1.Y1 && pres2 == 1){
		if(InvenciP1 != 1){
			if (presL == 1){
				sndPlaySound(".\\sons\\Bloqueio.wav", SND_ASYNC);
				SX2DP1 += 10;
				ChuteVP2 = 1;
				DelayCP2++;
				if(SX2DP1 >= 429)
					SX2DP1 = 429;
			}
			// Se a stamina acabar
			else if (SX2DP1 >= 429){
				sndPlaySound(".\\sons\\ChuteNoGalo.wav", SND_ASYNC);
				X2DP1 += Player2.Dano;
				ChuteVP2 = 1;
				DelayCP2++;
				ContadorP2++;
				LevaDanoP1 = 1;
				if(X2DP1 >= 429){
					X2DP1 = 429;
				}
			}
			else{
				sndPlaySound(".\\sons\\ChuteNoGalo.wav", SND_ASYNC);
		    	X2DP1 += Player2.Dano;
				ChuteVP2 = 1;
				DelayCP2++;
				ContadorP2++;
				LevaDanoP1 = 1;
				if(X2DP1 >= 429){
					X2DP1 = 429;
				}
			}
			if (ContadorP2 == 2){
				EmpurraoP1 = true;
				LevaDanoP1 = 0;
				InvenciP1 = 1;
			}
		}
	}
	
	// Gancho
	if(DgolpesP2S.X2 > Player1.X1 && DgolpesP2S.X1 < Player1.X2
	&& DgolpesP2S.Y1 < Player1.Y2 && DgolpesP2S.Y2 > Player1.Y1 && pres1 == 1 && presSD == 1){
		if(InvenciP1 != 1){
			
			sndPlaySound(".\\sons\\SocoNoGalo.wav", SND_ASYNC);
			X2DP1 += Player2.Dano + 20;
			DelayGanchoP2++;
			LevaDanoP1 = 1;
			ContadorP2 += 4;
			if(X2DP1 >= 429){
				X2DP1 = 429;
			}
			if (ContadorP2 == 4){
				EmpurraoP1 = true;
				LevaDanoP1 = 0;
				InvenciP1 = 1;
			}	
		}
	}
	
	
	//	======================================
	
	
	//Calculo da Regeneração da Stamina
	//============================================
	//Galo	
	if(SX2DP1 >= 429)
		RegenStamP1 = 1;
		if(RegenStamP1 == 1){
			SX2DP1 -= 1;
			presL = 0;
			
			if(SX2DP1 <= 136){
				RegenStamP1 = 0;
			}
		}
	
	
	//Suricato
	if(SX1DP2 <= 571)
		RegenStamP2 = 1;
		if(RegenStamP2 == 1){
			SX1DP2 += 1;
			pres3 = 0;
			
			if(SX1DP2 >= 864){
				RegenStamP2 = 0;
			}
		}
		

	//Calculo da Invencibilidade
	//============================================
	//Galo	
	
	if (InvenciP1 == 1){
		TempInvenciP1++;
			
		if(TempInvenciP1 >= 100){
			InvenciP1 = 0;
			TempInvenciP1 = 0;	
			ContadorP2 = 0;
		}
	}
	
	
	//Suricato	
	
	if (InvenciP2 == 1){
		TempInvenciP2++;
			
		if(TempInvenciP2 >= 100){
			InvenciP2 = 0;
			TempInvenciP2 = 0;	
			ContadorP1 = 0;
		}
	}
	
	
	//	======================================
	
	
	//Calculo do Knock Back
	//============================================
	//Galo	
	
	// Knock back para direita 
		if (direcaoP2	== 0){
			if(ContadorP2 >= 4){
				ContadorP2 = 0;
			} 
			
			if (EmpurraoP1 == true){ 

				Player1.X1 += 16;
				Player1.X2 += 16;
				Player1.Y1 -= 1;
				Player1.Y2 -= 1;
					
				DgolpesP1S.X1 += 16;
				DgolpesP1S.X2 += 16;
				DgolpesP1S.Y1 -= 1;
				DgolpesP1S.Y2 -= 1;
				
				DgolpesP1C.X1 += 16;
				DgolpesP1C.X2 += 16;
				DgolpesP1C.Y1 -= 1;
				DgolpesP1C.Y2 -= 1;
				
				if(Player1.X2 >= LarTela-borda){
					
					Player1.X1 -= 16;
					Player1.X2 -= 16;
				
					
					DgolpesP1S.X1 -= 16;
					DgolpesP1S.X2 -= 16;
					
				
					DgolpesP1C.X1 -= 16;
					DgolpesP1C.X2 -= 16;
				
				}
					
				if (Player1.Y1 <= 250 ){
					caindoP1 = 1;
					EmpurraoP1 = false;
				}
			}
			else if (caindoP1 == 1){
				if(caindoP1 == 0){
					EmpurraoP1 = false;
				} 
			}
			
			
		}
	 	
		//============================ fim da parte direita ==============================
		
		//=============================== para esquerda ==================================
		if (direcaoP2	== 1){
			if(ContadorP2 >= 4){
				ContadorP2 = 0;
			} 
			
			if (EmpurraoP1 == true){
				Player1.X1 -= 16;
				Player1.X2 -= 16;
				Player1.Y1 -= 1;
				Player1.Y2 -= 1;
					
				DgolpesP1S.X1 -= 16;
				DgolpesP1S.X2 -= 16;
				DgolpesP1S.Y1 -= 1;
				DgolpesP1S.Y2 -= 1;
				
				DgolpesP1C.X1 -= 16;
				DgolpesP1C.X2 -= 16;
				DgolpesP1C.Y1 -= 1;
				DgolpesP1C.Y2 -= 1;
					
				if(Player1.X1 <= borda){
					
					Player1.X1 += 16;
					Player1.X2 += 16;
				
					DgolpesP1S.X1 += 16;
					DgolpesP1S.X2 += 16;
										
					DgolpesP1C.X1 += 16;
					DgolpesP1C.X2 += 16;
				}
				
				if (Player1.Y1 <= 250){
					caindoP1 = 1;
					EmpurraoP1 = false;
				}
			}
			else if (caindoP1 == 1){
				if(caindoP1 == 0){
					EmpurraoP1 = false;
				} 
			}
			
			
		}
	 	
		//========================= Fim da esquerda ==========================
		
		
	//Suricato	
	
	// Knock back para direita 
		if (direcaoP1 == 0){
			if(ContadorP1 >= 4){
				ContadorP1 = 0;
			} 
			
				if (EmpurraoP2 == true){ 
					Player2.X1 += 16;
					Player2.X2 += 16;
					Player2.Y1 -= 1;
					Player2.Y2 -= 1;
					
					DgolpesP2S.X1 += 16;
					DgolpesP2S.X2 += 16;
					DgolpesP2S.Y1 -= 1;
					DgolpesP2S.Y2 -= 1;
					
					DgolpesP2C.X1 += 16;
					DgolpesP2C.X2 += 16;
					DgolpesP2C.Y1 -= 1;
					DgolpesP2C.Y2 -= 1;
					
					if(Player2.X2 >= LarTela-borda){
					
						Player2.X1 -= 16;
						Player2.X2 -= 16;
						
						DgolpesP2S.X1 -= 16;
						DgolpesP2S.X2 -= 16;
					
						DgolpesP2C.X1 -= 16;
						DgolpesP2C.X2 -= 16;
					}
					
					if (Player2.Y1 <= 250 ){
						caindoP2 = 1;
						EmpurraoP2 = false;
					}
				}
				else if(caindoP2 == 1){
					if(caindoP2 == 0){
						EmpurraoP2 = false;
					} 
				}
				
				
		}
	 	
		//============================ fim da parte direita ==============================
		
		//=============================== para esquerda ==================================
		if (direcaoP1	== 1){
			
			if(ContadorP1 >= 4){
				ContadorP1 = 0;
			} 
			
				if (EmpurraoP2 == true){
					Player2.X1 -= 16;
					Player2.X2 -= 16;
					Player2.Y1 -= 1;
					Player2.Y2 -= 1;
					
					DgolpesP2S.X1 -= 16;
					DgolpesP2S.X2 -= 16;
					DgolpesP2S.Y1 -= 1;
					DgolpesP2S.Y2 -= 1;
					
					DgolpesP2C.X1 -= 16;
					DgolpesP2C.X2 -= 16;
					DgolpesP2C.Y1 -= 1;
					DgolpesP2C.Y2 -= 1;
					
					if(Player2.X1 <= borda){
						
						Player2.X1 += 16;
						Player2.X2 += 16;
					
						DgolpesP2S.X1 += 16;
						DgolpesP2S.X2 += 16;
					
						DgolpesP2C.X1 += 16;
						DgolpesP2C.X2 += 16;
					}
					
					if (Player2.Y1 <= 250){
						caindoP2 = 1;
						EmpurraoP2 = false;
					}
				}
				else if (caindoP2 == 1){
					if(caindoP2 == 0){
						EmpurraoP2 = false;
					} 
				}
				
				
		}
	 	
		//========================= Fim da esquerda ==========================
		
	//Calculo do Delay Geral
	//============================================
	//Galo	
	if(DelayCP1 >= 2 || DelaySP1 >= 4 ){
		DelayGP1 = 1;
	}
	else{
		DelayGP1 = 0;
	}
	
	//Suricato
	if(DelayCP2 >= 2 || DelaySP2 >= 4 ){
		DelayGP2 = 1;
	}
	else{
		DelayGP2 = 0;
	}
	
		
	//Fim dos calculos
	//=================================================================
		
		
//Teclas
	// Limitando o uso da teclas durante o intervalo entre rounds
	if(!FimDeRound && gtRound1 == gtRound2){
		if(DelayGP1 != 1 ){
			if( LevaDanoP1 != 1){
		
				presA = 0;
				if(GetKeyState('A')&0x80){
					if((presJ != 1 && presK != 1) && (DelaySP1 < 4 && DelayCP1 < 2 && DelayGanchoP1 < 1)){
						presA = 1;
						runAnimaAP1 = 1;
					
					}
					
				}
				
				//Andar pra Direita
				presD = 0;
				if(GetKeyState('D')&0x80){
					if((presJ != 1 && presK != 1) && (DelaySP1 < 4 && DelayCP1 < 2 && DelayGanchoP1 < 1)){
						presD = 1;
						runAnimaDP1 = 1;
					}	
				}
				
				//abaixar	
				presS = 0;		
				//presSUP = 0;
				if(GetKeyState('S')&0x80) {
	
					if (presW == 0 && caindoP1 == 0)
						presS = 1;
				}
				
				presW = 0;
				if(GetKeyState('W')&0x80) {
					if (caindoP1 !=1 && presS != 1){
						presW = 1;
						presS = 0;
					}
				}
	
				presJ = 0;
				if(GetKeyState('J')&0x80){
					
					if (SocoVP1 !=1 && DelaySP1 < 5 && DelayGanchoP1 < 2){
						presJ = 1;
					}
		
				}
	
				presK = 0;
				if(GetKeyState('K')&0x80){
			
					if (ChuteVP1 != 1 && DelayCP1 < 3){
						presK = 1;	
					
					}
				}
			}
				presL = 0;
				if(GetKeyState('L')&0x80){
					if (RegenStamP1  != 1)
						presL = 1;
							
					if (presL == 1){
						presS = 0;
						presJ = 0;
						presK = 0;
						presW = 0;
						presA = 0;
						presD = 0;
						//presSUP = 0;
					}	
				}
			}
//		Jogador 2
//		=========================================================
		if(DelayGP2 != 1 ){
			if( LevaDanoP2 != 1){
		
				//Andar pra esquerda
				presSL = 0;
				if(GetKeyState(VK_LEFT)&0x80){
					if((pres1 != 1 && pres2 != 1) && (DelaySP2 < 4 && DelayCP2 < 2 && DelayGanchoP2 < 1)){
						runAnimaDP2 = 1;
						presSL = 1;
					}
				}
				
				//Andar pra Direita
				presSR = 0;
				if(GetKeyState(VK_RIGHT)&0x80){
					if((pres1 != 1 && pres2 != 1) && (DelaySP2 < 4 && DelayCP2 < 2 && DelayGanchoP2 < 1)){
						presSR = 1;
						runAnimaAP2 = 1;
					}
				}
				
				//abaixar
				presSD = 0;		
				//presSD1 = 0;
				if(GetKeyState(VK_DOWN)&0x80) {

					if (presSU == 0 && caindoP2 == 0)
						presSD = 1;
				}
		
				//pular
				presSU = 0;
				if(GetKeyState(VK_UP)&0x80) {
					if (caindoP2 !=1 && presSD != 1){
						presSU = 1;
						presSD = 0;
					}
				}
				
				// BOTÃO DO SOCO
				pres1 = 0;
				if(GetKeyState(VK_NUMPAD1)&0x80){
					
					if (SocoVP2 !=1 && DelaySP2 < 5 && DelayGanchoP2 < 2){
						pres1 = 1;
						
					}
		
				}
				
				// BOTÃO DO CHUTE
				pres2 = 0;
				if(GetKeyState(VK_NUMPAD2)&0x80){
			
					if (ChuteVP2 != 1 && DelayCP2 < 3){
						pres2 = 1;	
					
					}
				}
			}
			// Botão de Defesa
			pres3 = 0;
				if(GetKeyState(VK_NUMPAD3)&0x80){
					if (RegenStamP2 != 1)
						pres3 = 1;
							
					if (pres3 == 1){
						presSL = 0;
						presSR = 0;
						presSU = 0;
						presSD = 0;
						pres1 = 0;
						pres2 = 0;
//						presSD1 = 0;
					}	
				}
			}			
		}
	}	
		
	} // Chave final da condição PausarJog
		
	if(kbhit()){
		Tecla = getch();
		if (Tecla == ESC && !FimDeRound){ //Sem pausar o jogo no estado de Novo Round
			if(!PausarJog)
				PausarJog = true;
				else
				PausarJog = false;
			}

		
	
	}
	
	// Leitor do Mouse
	if(GetCursorPos(&P)){
		if(ScreenToClient(Janela,&P)){
			// Condições para acionar os botões
			if(GetKeyState(VK_LBUTTON)&0x80){
				if(250 <= P.x && P.x <= 250+BotFimDeJogoX-1 && 500 <= P.y && P.y <= 500+BotFimDeJogoY-1 && DecisaoFinal){
					DecisaoFinal = false;
					FimDeRound = false;
					NovoRound = true;
					gtFimDeRound1 = 1;
					gtRound1 = 1;
					VitoriasP1 = 0;
					VitoriasP2 = 0;
					RoundAtual = 0;
				}
				
				if(535 <= P.x && P.x <= 535+BotFimDeJogoX-1 && 500 <= P.y && P.y <= 500+BotFimDeJogoY-1 && DecisaoFinal){
					FimDeJogo = true;
				}
			}
		}
	}
	}
}

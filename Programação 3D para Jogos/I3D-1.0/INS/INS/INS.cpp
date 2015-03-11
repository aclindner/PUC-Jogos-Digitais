/*********************************************************************************/
/*Projeto             :Insane Engine
/*Descricao           :
/*Data de Criação     :
/*
/*Copyright (c) 2013 William Wolff. Todos os direitos reservados
/**********************************************************************************/


#include "stdafx.h"

#include "I3D_DefGlobal.h"
#include "I3D_Camera.h"
#include "I3D_Tempo.h"


CI3DTempo    Tempo      ;
CI3DCamera   Camera     ;

typedef struct func
{
	char*  Funcao;
	int    tecla ;
}KBD_FUNC;

std::vector<KBD_FUNC> ListaFuncoes;

/************************************************************/
/*Nome da Função      : Inicializa()
/*
/*Objetivo            : Inicializa OpenGL
/************************************************************/
void Inicializa()
{
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );//Fundo Preto
 
   /*****************************/
   /*Seta a Velocidade da Camera*/
   /*****************************/
	Camera.I3D_Velocidade = 25.0f;

	ListaFuncoes.resize(3);
}

/************************************************************/
/*Nome do Método      : Renderiza()
/*
/*Objetivo            : Realiza o desenho propriamente dito da
/*                      imagem na tela.
/************************************************************/
void Renderiza()
{
	float X,Y,Z;
	int tam = 256;

   /*******************************************************************/
   /*Regula as Matrizes internas da OpenGl para orientacao dos objetos*/
   /*******************************************************************/
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearDepth( 1.0f                 );
	glClear     ( GL_COLOR_BUFFER_BIT  | 
	 	          GL_DEPTH_BUFFER_BIT  );

	glEnable    (GL_DEPTH_TEST    );
	glFrontFace (GL_CCW           );
	glEnable    (GL_CULL_FACE     );
	glEnable    (GL_TEXTURE_2D    );

	/**********************/
	/*trava tempo inicial */
	/**********************/
	Tempo.Tick(0);

   /************************/
   /*Atualiza a Camera     */
   /************************/
	Camera.PosicionaCamera();
	
	X= Camera.I3D_CameraPos.x;
	Y= Camera.I3D_CameraPos.y;
	Z= Camera.I3D_CameraPos.z;
	
   /******************************************/
   /*Renderiza objeto                        */
   /******************************************/
    glPolygonMode(GL_FRONT, GL_LINE);
	glPushMatrix();
	glColor3f( 0.7f,0.7f,0.7f);
	glBegin(GL_QUADS);
	for ( int X = 0; X < tam; X++ )
		   for (int Z = 0; Z < tam; Z++ )
		   {
			   glVertex3i (X    ,0,Z     );
			   glVertex3i (X    ,0,Z + 1 );
			   glVertex3i (X + 1,0,Z + 1 );
			   glVertex3i (X + 1,0,Z     );
		   }
	glEnd();
	glPopMatrix();

   /******************************************/
   /*Finaliza Processo de Renderização       */
   /******************************************/
	glDisable    (GL_DEPTH_TEST    );
	glDisable    (GL_CULL_FACE     );

	glutSwapBuffers();
}

/************************************************************/
/*Nome da Função      : Inicializa()
/*
/*Objetivo            : Inicializa OpenGL
/************************************************************/
void ProcessaComandos()
{
   /******************************/
   /*Mapeia Mouse caso habilitado*/
   /******************************/
   Camera.MapeiaMouse();
   
   /****************************************/
   /*Processa as teclas pressionadas       */
   /****************************************/
	if ( GetAsyncKeyState( 0x57 ) & 0xFF00 ) 
	{
       // (W)
	}
    if ( GetAsyncKeyState( 0x53 ) & 0xFF00 ) 
	{
	   // (S)
	}
    if ( GetAsyncKeyState( 0x41 ) & 0xFF00 ) 
	{
	   // (A)
	}
    if ( GetAsyncKeyState( 0x44 ) & 0xFF00 ) 
	{
	   // (D)
	}
	if ( GetAsyncKeyState( 0x1B ) & 0xFF00 ) 
	{
       exit(0); // (ESC)
	}
}

/************************************************************/
/*Nome do Método      : FuncaoConstante(void)
/*
/*Objetivo            : Esta Funcao e executada a cada frame
/*                      e está sendo utilizada para  o  pro-
/*                      cessamento do movimento de camera.
/*                      Obs:.Utilizamos GetAsyncKeyState aqui
/*                           devido a uma melhor  performance
/*                           que a funcao padrao de   teclado
/*                           disponibilizada  pela biblioteca
/*                           glut.
/************************************************************/
void FuncaoConstante(void)
{
   ProcessaComandos();
   
   glutPostRedisplay  ();
}

/************************************************************/
/*Nome do Método      : Dimensiona(int w, int h)
/*
/*Objetivo            : Regula a Perspectiva de Renderizacao
/************************************************************/
void Dimensiona(int w, int h)
{
	Camera.AtTela=w;
	Camera.LgTela=h;
	Camera.CalculaPerspectiva(CAMPO_VISAO_PROXIMO,CAMPO_VISAO_DISTANTE);

}

int _tmain(int argc, char ** argv)
{
   /***********************************/
   /*Inicializa biblioteca glut       */
   /***********************************/
	glutInit(&argc,argv);

   /*******************************************************/
   /*Cria e Regula uma janela para renderizacao           */
   /*******************************************************/
	glutInitDisplayMode   (GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
	glutInitWindowSize    (800, 600);
	glutInitWindowSize    (1024, 768);
	glutInitWindowPosition(0   , 0  );
	glutCreateWindow      (argv[0] );
	/*****************************/
   /*Renderiza em Fullscreen    */
   /*****************************/
    glutFullScreen();
   /*****************************/
   /*Esconde o ponteiro do mouse*/
   /*****************************/
	ShowCursor(false);
   /*************************/
   /*Inicializa OpenGL      */
   /*************************/
	Inicializa();
   /*******************************/
   /*Carrega um Cenario            */
   /********************************/
	/*
   	Futuramente será incluido aqui rodinas para carregamento do cenario
	*/

   /**********************************/
   /*Seta as funções callback da glut*/
   /**********************************/
	glutDisplayFunc (Renderiza      );
	glutReshapeFunc (Dimensiona     );
	glutIdleFunc    (FuncaoConstante);
   /***********************************************/
   /*Transfere para a glut o controle sobre o loop*/
   /***********************************************/
	glutMainLoop();
	
	return 0;
}


/*********************************************************************************/
/*Projeto             :Insane Engine
/*Descricao           :
/*Data de Criação     :
/*
/*Copyright (c) 2013 William Wolff. Todos os direitos reservados
/**********************************************************************************/
#include "stdafx.h"
#include "I3D_Camera.h"


/************************************************************/
/*Nome do Método      : CI3DCamera()
/*
/*Objetivo            : Construtor Padrão da classe de Camera
/************************************************************/
CI3DCamera::CI3DCamera()
{
   I3D_CameraPos =CI3DVetor(100.00f,300.00f,100.00f);
   I3D_CameraView=CI3DVetor(0.00f,0.00f,0.00f);
   I3D_CameraUp  =CI3DVetor(0.00f,1.00f,0.00f);
   I3D_Velocidade       =25.0f;
   I3D_Intervalo        =0.0f;
   i3dFramesPorSegundo  =0;	
   i3dUltimoTempo		=0;	
   i3dTempoFrame        =0;
   LgTela               =800;
   AtTela               =600;
}

/************************************************************/
/*Nome do Método      : SetaCamera 
/*
/*Objetivo            : Seta a Posição em que a camera se 
/*                      encontra.
/************************************************************/
void CI3DCamera::SetaCamera(float i3dPosicaoX , 
							float i3dPosicaoY , 
							float i3dPosicaoZ ,
                            float i3dViewX    , 
							float i3dViewY    , 
							float i3dViewZ    ,
                            float i3dUpX      , 
							float i3dUpY      , 
							float i3dUpZ      )
{

   I3D_CameraPos =CI3DVetor( i3dPosicaoX, i3dPosicaoY , i3dPosicaoZ);
   I3D_CameraView=CI3DVetor( i3dViewX   , i3dViewY    , i3dViewZ   );
   I3D_CameraUp  =CI3DVetor( i3dUpX     , i3dUpY      , i3dUpZ     );

}

/************************************************************/
/*Nome do Método      : PegaDirecao 
/*
/*Objetivo            : Pega a direção onde a camera está 
/*                      apontando.
/************************************************************/
void CI3DCamera::PegaDirecao(float &i3dPosicaoX, 
						  float &i3dPosicaoY, 
						  float &i3dPosicaoZ)
{
	CI3DVetor Direcao;

	Direcao=I3D_CameraView - I3D_CameraPos;

	i3dPosicaoX = Direcao.x;
	i3dPosicaoY = Direcao.y;
	i3dPosicaoZ = Direcao.z;

}

/************************************************************/
/*Nome do Método      : PegaDirecao 
/*
/*Objetivo            : Pega a direção onde a camera está 
/*                      apontando.
/************************************************************/
CI3DVetor CI3DCamera::PegaDirecao()
{
	CI3DVetor Direcao;

	Direcao=I3D_CameraView - I3D_CameraPos;

	return Direcao;
}
/************************************************************/
/*Nome do Método      : MoverCamera
/*
/*Objetivo            : Move a camera para a direção desejada
/************************************************************/
void CI3DCamera::MoverCamera(float i3dDirecao)
{
   
   CI3DVetor  i3dDir;

   i3dDir=PegaDirecao();
   i3dDir.Normalizar ();
   
   AtualizaCamera(i3dDir.x, i3dDir.y,i3dDir.z,i3dDirecao);
}

/************************************************************/
/*Nome do Método      : AtualizaCamera
/*
/*Objetivo            : Atualiza a camera
/************************************************************/
void CI3DCamera::AtualizaCamera(float xDir, float yDir, float zDir, float dir)
{
   dir = dir * I3D_Intervalo;

   I3D_CameraPos.x += xDir * dir;
   I3D_CameraPos.y += yDir * dir;
   I3D_CameraPos.z += zDir * dir;

   I3D_CameraView.x += xDir * dir;
   I3D_CameraView.y += yDir * dir;
   I3D_CameraView.z += zDir * dir;
}


/************************************************************/
/*Nome do Método      : Rodar
/*
/*Objetivo            : Roda a camera na direção desejada
/************************************************************/
void CI3DCamera::Rodar(float i3dAnguloDirecao, 
					float i3dPosicaoX     , 
					float i3dPosicaoY     , 
					float i3dPosicaoZ     )
{
	

   CI3DVetor i3dDirVisao ;
   CI3DQuat qRotacao, qVisao, qNovaVisao;

   qRotacao.Rotaciona(i3dAnguloDirecao, i3dPosicaoX, i3dPosicaoY, i3dPosicaoZ);

   i3dDirVisao     = PegaDirecao();

   qVisao.x = i3dDirVisao.x ;
   qVisao.y = i3dDirVisao.y ;
   qVisao.z = i3dDirVisao.z ;
   qVisao.w = 0;

   qNovaVisao = ((qRotacao * qVisao) * qRotacao.Conjugar());

   I3D_CameraView.x = I3D_CameraPos.x + qNovaVisao.x;
   I3D_CameraView.y = I3D_CameraPos.y + qNovaVisao.y;
   I3D_CameraView.z = I3D_CameraPos.z + qNovaVisao.z;

   
}

void CI3DCamera::MapeiaMouse()
{
	 
	POINT mousePos;

	int i3dScreenX = LgTela >> 1;				
	int i3dScreenY = AtTela >> 1;				
	
	float i3dAnguloY = 0.0f;				
	float i3dAnguloZ = 0.0f;					
	
	CI3DVetor i3dVetTemp,i3dEixo;	
	
	static float i3dRotacaoX = 0.0f;

	
	GetCursorPos(&mousePos);						
	
	// se estiver ainda no meio e pq nao se moveu... portanto nao atualizamos a tela
	if( (mousePos.x == i3dScreenX) && (mousePos.y == i3dScreenY) ) return;

	// seta a pos no meio da tela
	SetCursorPos(i3dScreenX, i3dScreenY);							

    i3dAnguloY = (float)( (i3dScreenX - mousePos.x) ) / 10.0f;		
	i3dAnguloZ = (float)( (i3dScreenY - mousePos.y) ) / 10.0f;		

	i3dRotacaoX -= i3dAnguloZ;  

	if(i3dRotacaoX > 1.0f)
	{

		i3dRotacaoX = 1.0f;

	}
	
	if(i3dRotacaoX < -1.0f)
	{

		i3dRotacaoX = -1.0f;
	
	}
	
		
	i3dVetTemp     = PegaDirecao();
    i3dEixo        = i3dVetTemp.ProdutoVetorial(I3D_CameraUp);
	i3dEixo.Normalizar();

		
	Rodar(i3dAnguloZ,
		  i3dEixo.x ,
		  i3dEixo.y ,
		  i3dEixo.z);

	Rodar(i3dAnguloY, 0, 1, 0);

}

/************************************************************/
/*Nome do Método      : CameraStrafe
/*
/*Objetivo            : Realiza o strafing da camera
/*
/************************************************************/
void CI3DCamera::CameraStrafe(float i3dDirecao)
{	

   CalculaStrafe();
   AtualizaCamera(I3D_CameraStrafe.x, 
	              I3D_CameraStrafe.y, 
				  I3D_CameraStrafe.z, 
				  i3dDirecao);
}

/************************************************************/
/*Nome do Método      : CameraStrafe
/*
/*Objetivo            : Realiza o strafing da camera
/*
/************************************************************/
void CI3DCamera::CalculaStrafe()
{	

   CI3DVetor Direcao;

   Direcao=PegaDirecao();
   Direcao.Normalizar ();

   I3D_CameraStrafe=Direcao.ProdutoVetorial(I3D_CameraUp);

}
/************************************************************/
/*Nome do Método      : PosicionaCamera
/*
/*Objetivo            : Posiciona a camera levando-se em con-
/*                      ideração todas as suas coordenadas
/*
/************************************************************/
void CI3DCamera::PosicionaCamera()
{
	gluLookAt(I3D_CameraPos .x , I3D_CameraPos .y,I3D_CameraPos .z ,	
			  I3D_CameraView.x , I3D_CameraView.y,I3D_CameraView.z ,	
	          I3D_CameraUp  .x , I3D_CameraUp  .y,I3D_CameraUp  .z );

}


/************************************************************/
/*Nome do Método      : CalculaFrameRate
/*
/*Objetivo            : Calcula nosso FPS , neste caso estamos
/*                      utilizando para calcular a velocidade 
/*                      em algumas situações... 
/*
/************************************************************/
void CI3DCamera::CalculaTempo()
{
   static float i3dTempoFrame = 0.0f;

   float i3dTempoAtual = timeGetTime() * 0.001f;

   I3D_Intervalo = i3dTempoAtual - i3dTempoFrame;
   i3dTempoFrame = i3dTempoAtual;	
}

/************************************************************/
/*Nome do Método      : ResetaCamera
/*
/*Objetivo            : Inicializa as variaveis responsaveis
/*                      pelos valores de tempo utilizados para 
/*                      o calculo da velocidade. 
/*
/************************************************************/
void CI3DCamera::ResetaCamera()
{
   I3D_CameraPos        =CI3DVetor(100.00f,300.00f,100.00f);
   I3D_CameraView       =CI3DVetor(0.00f,0.00f,0.00f);
   I3D_CameraUp         =CI3DVetor(0.00f,1.00f,0.00f);
   I3D_Velocidade       =0.5f;
   I3D_Intervalo        =0.0f;
   i3dFramesPorSegundo  =0;	
   i3dUltimoTempo		=0;	
   i3dTempoFrame        =0;
}

void CI3DCamera::CalculaPerspectiva(float i3dProx,float i3dDist)
{
	GLfloat Aspecto;
	float   CampoVisao = 90.0f;
	
	/**************************/
	/*Previne divisao por zero*/
	/**************************/
	if(LgTela == 0)
		LgTela = 1;
	/************************************************************/
	/*Regula o campo de desenho da tela para o tamanho requerido*/
	/************************************************************/
    glViewport(0, 0, AtTela, LgTela);
    /*******************************/
	/*Obtem o divisor de aspecto   */
	/*******************************/
	Aspecto = (GLfloat)AtTela/(GLfloat)LgTela;
	/********************************/
	/*Limpa o sistema de coordenadas*/
	/********************************/
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	{
		/***********************************/
		/*Calcula a Projecao de perspectiva*/
		/***********************************/
		double  esquerda;
		double  direita;
		double  embaixo;
		double  topo;
		
		direita  = i3dProx * tan( CampoVisao/2.0 * PI/180.0f );
		
		topo     = direita / Aspecto;

		embaixo  = -topo   ;
		esquerda = -direita;
		
		glFrustum(esquerda, direita, embaixo, topo,i3dProx,i3dDist);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
/*********************************************************************************/
/*Projeto             :Insane Engine
/*Descricao           :
/*Data de Criação     :
/*
/*Copyright (c) 2013 William Wolff. Todos os direitos reservados
/**********************************************************************************/
#ifndef _I3D_CAMERA_H
#define _I3D_CAMERA_H

#include "I3D_Vetor.h"
#include "I3D_Quaternion.h"

/************************************************************/
/*Nome da Classe      : CI3DCamera
/*
/*Objetivo            : Responsável pelos eventos de Câmera
/*                      Tem a responsabilidade de armazenar
/*                      e manipular a câmera utilizada para
/*                      a visualização da cena.
/************************************************************/
class CI3DCamera
{

public:
	
     
	float     I3D_Velocidade     ;// Velocidade da camera
	float     I3D_Intervalo      ;// Intervalo dos Frames
	
	CI3DVetor    I3D_CameraPos         ;// Posicao da camera					
	CI3DVetor    I3D_CameraView        ;// Visão da Câmera						
 	CI3DVetor    I3D_CameraUp          ;// Direcao Superior		
	CI3DVetor    I3D_CameraStrafe      ;// Strafe						

	float     i3dFramesPorSegundo    ;	
    float     i3dUltimoTempo		 ;	
	float     i3dTempoFrame          ;

	int       AtTela,
		      LgTela;
 
public:

	  CI3DCamera                 (                           );                                

      void SetaCamera            (float i3dPosicaoX          , 
						          float i3dPosicaoY          , 
						          float i3dPosicaoZ          ,
                                  float i3dViewX             , 
					         	  float i3dViewY             , 
						          float i3dViewZ             ,
                                  float i3dUpX               , 
						          float i3dUpY               , 
						          float i3dUpZ               );
      void PegaDirecao           (float &i3dPosicaoX         , 
                                  float &i3dPosicaoY         , 
                                  float &i3dPosicaoZ         );
	  
	  CI3DVetor PegaDirecao      (                           ); 
      
	  void MoverCamera           (float i3dDirecao           );               
	  
	  void AtualizaCamera        (float xDir                 , 
		                          float yDir                 , 
								  float zDir                 , 
								  float dir                  );
	  void Rodar                 (float i3dAnguloDirecao     , 
		                          float i3dPosicaoX          , 
                                  float i3dPosicaoY          , 
						          float i3dPosicaoZ          );

	  void MapeiaMouse           (                           );
	  void CalculaStrafe         (                           );
	  void CameraStrafe          (float        i3dDirecao    );
	  void PosicionaCamera       (                           );
	  void CalculaTempo          (                           );
	  void ResetaCamera          (                           );
	  void CalculaPerspectiva    (float i3dProx,float i3dDist);

};

#endif
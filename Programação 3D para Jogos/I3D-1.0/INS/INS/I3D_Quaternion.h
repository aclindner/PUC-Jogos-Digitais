/*********************************************************************************/
/*Projeto             :Insane Engine
/*Descricao           :
/*Data de Criação     :
/*
/*Copyright (c) 2013 William Wolff. Todos os direitos reservados
/**********************************************************************************/

#ifndef _I3D_QUATERNION_H
#define _I3D_QUATERNION_H

#define PEGA_RADIANOS(grau) (float)((grau * PI) / 180.0f)   

#include<math.h>                                            


class CI3DQuat 
{
   public:
      
	  CI3DQuat(              ); 
	  CI3DQuat(float xEixo, 
		       float yEixo, 
			   float zEixo, 
			   float wEixo   ); 
	   
      void operator=(const CI3DQuat &q);
      

      CI3DQuat operator*(const CI3DQuat &q);
      

      CI3DQuat Conjugar();
       

	   void Rotaciona(float grau, float xEixo, float yEixo, float zEixo);
       
	   void CriaMatriz(float *pMatriz);
       
	   float x, y, z, w;                      
};

#endif
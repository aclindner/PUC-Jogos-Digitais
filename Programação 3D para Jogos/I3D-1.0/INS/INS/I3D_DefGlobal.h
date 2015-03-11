/*********************************************************************************/
/*Projeto             :Insane Engine
/*Descricao           :
/*Data de Cria��o     :
/*
/*Copyright (c) 2013 William Wolff. Todos os direitos reservados
/**********************************************************************************/
#ifndef _I3D_DEF_H
#define _I3D_DEF_H

#define EPSILON         0.001f   //Valor de tolerancia
#define FUZZY           0.00001f //Valor de Tolerancia
#define PI              3.1415926535897932    //PI
#define TWOPI           6.283185308
#define PiOver180		1.74532925199433E-002f
#define PiUnder180		5.72957795130823E+001f
#define SMALL_NUMBER	0.00001
#define LARGE_NUMBER	1E20
/*
typedef enum CLASSIFICACAO
{
       FRENTE      = 1 ,
       ATRAS       = 2 ,
       COPLANAR    = 3 ,
       CRUZANDO    = 4 
};
*/

#define SQR(x) ((x) * (x))
#define MAX(a,b) ((a < b) ? (b) : (a))
#define M_PI (3.14159265358979323846f)
#define DEG2RAD(a) (((a) * M_PI) / 180.0f)
#define MIN( a, b ) ((a < b)?(a):(b))

#define CAMPO_VISAO_PROXIMO     (0.1f)
#define CAMPO_VISAO_DISTANTE    (15000.0f)
 
#endif
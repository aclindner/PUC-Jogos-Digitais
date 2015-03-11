/*********************************************************************************/
/*Projeto             :Insane Engine
/*Descricao           :
/*Data de Criação     :
/*
/*Copyright (c) 2013 William Wolff. Todos os direitos reservados
/**********************************************************************************/


#pragma once

/*****************************************/
/* define windows 7 como plataforma alvo */
/*****************************************/
#define WINVER 0x0601
#define _WIN32_WINNT 0x0601

/**************************************************/
/*Desabilita warning esquisito de linkagem da Glut*/
/**************************************************/
#define GLUT_DISABLE_ATEXIT_HACK

#include "targetver.h"

/******************************************/
/* INCLUDES DA PLATAFORMA WINDOWS         */
/******************************************/
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <math.h>
#include <float.h>
#include <Mmsystem.h>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#include <assert.h>
#include <TCHAR.h>
#include <objbase.h>
#include <iostream>
using namespace std;


#include "glut.h"
#include <gl/GL.h>

#pragma comment(lib, "opengl32.lib"           )
#pragma comment(lib, "glut32.lib"             )

#include "I3D_DefGlobal.h"

// TODO: reference additional headers your program requires here

/*********************************************************************************/
/*Projeto             :Insane Engine
/*Descricao           :
/*Data de Criação     :
/*
/*Copyright (c) 2013 William Wolff. Todos os direitos reservados
/**********************************************************************************/

#ifndef _I3D_TEMPO_H_
#define _I3D_TEMPO_H_

//-----------------------------------------------------------------------------
// Definições, Macros & Constantes
//-----------------------------------------------------------------------------
const unsigned long MAX_SAMPLE_COUNT = 50; // Maximum frame time sample count

class CI3DTempo
{
public:
	         CI3DTempo();
	virtual ~CI3DTempo();

	void	        Tick( float fLockFPS = 0.0f );
    unsigned long   GetFrameRate( LPTSTR lpszString = NULL ) const;
    float           GetTimeElapsed() const;

private:
    bool            m_PerfHardware;             // Tem Contador de Performance?
	float           m_TimeScale;                // Qtd Escala de Tempo
	float           m_TimeElapsed;              // Tempo percorrido desde o ultimo Frame
    __int64         m_CurrentTime;              // Contador Atual
    __int64         m_LastTime;                 // Contador Frame Passado
	__int64         m_PerfFreq;                 // Frequencia de Performance

    float           m_FrameTime[MAX_SAMPLE_COUNT];
    ULONG           m_SampleCount;

    unsigned long   m_FrameRate;                // Armazena framerate atual
	unsigned long   m_FPSFrameCount;            // Frames por Segundo
	float           m_FPSTimeElapsed;           // quanto tempo passou entre os frames
	
};

#endif // _CI3DTempo_H_
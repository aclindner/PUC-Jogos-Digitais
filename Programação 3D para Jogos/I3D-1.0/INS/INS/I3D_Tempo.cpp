/*********************************************************************************/
/*Projeto             :Insane Engine
/*Descricao           :
/*Data de Criação     :
/*
/*Copyright (c) 2013 William Wolff. Todos os direitos reservados
/**********************************************************************************/

#include "stdafx.h"
#include "I3D_Tempo.h"

CI3DTempo::CI3DTempo()
{
	// Caso o Hardware suporte Frequency Performance Counters
	if (QueryPerformanceFrequency((LARGE_INTEGER *)&m_PerfFreq)) 
    { 
		m_PerfHardware		= TRUE;
		QueryPerformanceCounter((LARGE_INTEGER *) &m_LastTime); 
		m_TimeScale			= 1.0f / m_PerfFreq;
	} 
    else 
    { 
		// caso contrario usa timeGetTime mesmo... 
		m_PerfHardware		= FALSE;
		m_LastTime			= timeGetTime(); 
		m_TimeScale			= 0.001f;
	
    } 

	m_SampleCount       = 0;
	m_FrameRate			= 0;
	m_FPSFrameCount		= 0;
	m_FPSTimeElapsed	= 0.0f;
}

//-----------------------------------------------------------------------------
// Name : CI3DTempo () (Destructor)
// Desc : CI3DTempo Class Destructor
//-----------------------------------------------------------------------------
CI3DTempo::~CI3DTempo()
{
}

//-----------------------------------------------------------------------------
// Desc : Sinaliza que o tempo andou...
// Nota : Pode-se definir um numero fixo de frames por segundo para travar os frame rates
//-----------------------------------------------------------------------------
void CI3DTempo::Tick( float fLockFPS )
{
    float fTimeElapsed; 

    // performance hardware disponivel?
	if ( m_PerfHardware ) 
    {
		QueryPerformanceCounter((LARGE_INTEGER *)&m_CurrentTime);
	} 
    else 
    {
        // timeGetTime caso contrario...
		m_CurrentTime = timeGetTime();

	} 

	// Calculate tempo percorrido em segundos
	fTimeElapsed = (m_CurrentTime - m_LastTime) * m_TimeScale;

    // Suaviza as mudanças de frames para evitar jittering
    //if ( fLockFPS == 0.0f && m_TimeElapsed > 0 ) fLockFPS = (1.0f / m_TimeElapsed) + 20.0f;
    
    // travamos frame rate ?
    if ( fLockFPS > 0.0f )
    {
        while ( fTimeElapsed < (1.0f / fLockFPS))
        {
	        if ( m_PerfHardware ) 
            {
		        QueryPerformanceCounter((LARGE_INTEGER*)&m_CurrentTime);
	        } 
            else 
            {
		        m_CurrentTime = timeGetTime();

	        } 

	        fTimeElapsed = (m_CurrentTime - m_LastTime) * m_TimeScale;
        } 
    }

	m_LastTime = m_CurrentTime;

    // Filtra valores muito fora do que a media normal de processamento
    if ( fabsf(fTimeElapsed - m_TimeElapsed) < 1.0f  )
    {
        // FIFO Buffer de Frames
        memmove( &m_FrameTime[1], m_FrameTime, (MAX_SAMPLE_COUNT - 1) * sizeof(float) );
        m_FrameTime[ 0 ] = fTimeElapsed;
        if ( m_SampleCount < MAX_SAMPLE_COUNT ) m_SampleCount++;
    }
    

	// Calcula Frame Rate
	m_FPSFrameCount++;
	m_FPSTimeElapsed += fTimeElapsed;
	if ( m_FPSTimeElapsed > 1.0f) 
    {
		m_FrameRate			= m_FPSFrameCount;
		m_FPSFrameCount		= 0;
		m_FPSTimeElapsed	= 0.0f;
	}

    // atualiza a nova media de tempo percorrido
    m_TimeElapsed = 0.0f;
    if ( m_SampleCount > 0 )
    {
        for ( ULONG i = 0; i < m_SampleCount; i++ ) m_TimeElapsed += m_FrameTime[ i ];
        m_TimeElapsed /= m_SampleCount;
    }
}

//-----------------------------------------------------------------------------
// Desc : Retorna o frame rate, sampled over the last second or so.
//-----------------------------------------------------------------------------
unsigned long CI3DTempo::GetFrameRate( LPTSTR lpszString ) const
{
    // preenche string com o buffer ?
    if ( lpszString )
    {
        //copia o FPS para string de saida
    }

    return m_FrameRate;
}

//-----------------------------------------------------------------------------
// Desc : Retorna o tempo percorrido desde o ultimo frame(em segundos)
//-----------------------------------------------------------------------------
float CI3DTempo::GetTimeElapsed() const
{
    return m_TimeElapsed;
}

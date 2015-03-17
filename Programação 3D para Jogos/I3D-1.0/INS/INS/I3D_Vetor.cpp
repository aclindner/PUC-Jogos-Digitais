/*********************************************************************************/
/*Projeto             :Insane Engine
/*Descricao           :
/*Data de Criação     :
/*
/*Copyright (c) 2013 William Wolff. Todos os direitos reservados
/**********************************************************************************/
#include "stdafx.h"
#include "I3D_Vetor.h"



/*************************************************************/
/*                                                           */
/*************************************************************/
CI3DVetor::CI3DVetor( )
{
    // Reset required variables.
    x = 0.0f; y = 0.0f; z = 0.0f;
}

/*************************************************************/
/*                                                           */
/*************************************************************/
CI3DVetor::CI3DVetor( const CI3DVetor & vetor )
{
    x = vetor.x; y = vetor.y; z = vetor.z;
}

/*************************************************************/
/*                                                           */
/*************************************************************/
CI3DVetor::CI3DVetor( float _x, float _y, float _z)
{
    x = _x; y = _y; z = _z;
}


/*************************************************************/
/*                                                           */
/*************************************************************/
CI3DVetor::operator float * ()
{
    return (float*)&x;
}

/*************************************************************/
/*                                                           */
/*************************************************************/
CI3DVetor::operator const float * () const
{
    return (const float*)&x;
}

/*************************************************************/
/*                                                           */
/*************************************************************/
CI3DVetor CI3DVetor::operator+  () const
{
    return *this;
}

/*************************************************************/
/*                                                           */
/*************************************************************/
CI3DVetor CI3DVetor::operator-  () const
{
    return CI3DVetor( -x, -y, -z );
}

/*************************************************************/
/*                                                           */
/*************************************************************/
CI3DVetor& CI3DVetor::operator+= ( const CI3DVetor& vetor )
{
    x += vetor.x; y += vetor.y; z += vetor.z;
    return *this;
}

/*************************************************************/
/*                                                           */
/*************************************************************/
CI3DVetor& CI3DVetor::operator-= ( const CI3DVetor& vetor )
{
    x -= vetor.x; y -= vetor.y; z -= vetor.z;
    return *this;
}

/*************************************************************/
/*                                                           */
/*************************************************************/
CI3DVetor& CI3DVetor::operator*= ( const float& Valor  )
{
    x *= Valor; y *= Valor; z *= Valor;
    return *this;
}

/*************************************************************/
/*                                                           */
/*************************************************************/
CI3DVetor& CI3DVetor::operator/= ( const float& Valor  )
{
    float fValor = 1.0f / Valor;
    x *= fValor; y *= fValor; z *= fValor;
    return *this;
}

/*************************************************************/
/*                                                           */
/*************************************************************/
CI3DVetor CI3DVetor::operator+  ( const CI3DVetor& vetor ) const
{
    return CI3DVetor( x + vetor.x, y + vetor.y, z + vetor.z );
}

/*************************************************************/
/*                                                           */
/*************************************************************/
CI3DVetor CI3DVetor::operator-  ( const CI3DVetor& vetor ) const
{
    return CI3DVetor( x - vetor.x, y - vetor.y, z - vetor.z );
}

/*************************************************************/
/*                                                           */
/*************************************************************/
CI3DVetor CI3DVetor::operator*  ( const float& Valor  ) const
{
    return CI3DVetor( x * Valor, y * Valor, z * Valor );
}


/*************************************************************/
/*                                                           */
/*************************************************************/
CI3DVetor CI3DVetor::operator*  ( const CI3DVetor& vetor  ) const
{
    return CI3DVetor( x * vetor.x, y * vetor.y, z * vetor.z );
}

/*************************************************************/
/*                                                           */
/*************************************************************/
CI3DVetor CI3DVetor::operator/  ( const float& Valor  ) const
{
    float fValor = 1.0f / Valor;
    return CI3DVetor( x * fValor, y * fValor, z * fValor );
}

/*************************************************************/
/*                                                           */
/*************************************************************/
CI3DVetor& CI3DVetor::operator=  ( const CI3DVetor& vetor )
{
    x = vetor.x; y = vetor.y; z = vetor.z;
    return *this;
}

/*************************************************************/
/*                                                           */
/*************************************************************/
bool CI3DVetor::operator== ( const CI3DVetor& vetor ) const
{
    return (x == vetor.x) && (y == vetor.y) && (z == vetor.z);
}

/*************************************************************/
/*                                                           */
/*************************************************************/
bool CI3DVetor::operator!= ( const CI3DVetor& vetor ) const
{
    return (x != vetor.x) || (y != vetor.y) || (z != vetor.z);
}
    
/*************************************************************/
/*                                                           */
/*************************************************************/
CI3DVetor operator * (float Valor, const CI3DVetor& vetor )
{
    return CI3DVetor( vetor.x * Valor, vetor.y * Valor, vetor.z * Valor );
}

/*************************************************************/
/*                                                           */
/*************************************************************/
bool CI3DVetor::Vazio() const
{
    return (x == 0.0f) && (y == 0.0f) && (z == 0.0f);
}

/*************************************************************/
/*                                                           */
/*************************************************************/
CI3DVetor CI3DVetor::ProdutoVetorial( const CI3DVetor& V1 ) const
{
    return CI3DVetor( y * V1.z - z * V1.y , 
		              z * V1.x - x * V1.z , 
					  x * V1.y - y * V1.x );
}

/*************************************************************/
/*                                                           */
/*************************************************************/
float CI3DVetor::ProdutoEscalar( const CI3DVetor& vetor ) const
{
    return x * vetor.x + y * vetor.y + z * vetor.z;
}

/*************************************************************/
/*                                                           */
/*************************************************************/
float CI3DVetor::Magnitude() const
{
    return sqrtf(x * x + y * y + z * z);
}

/*************************************************************/
/*                                                           */
/*************************************************************/
float CI3DVetor::MeiaMagnitude() const
{
    return x * x + y * y + z * z;
}


/*************************************************************/
/*                                                           */
/*************************************************************/
bool CI3DVetor::Compara( const CI3DVetor& vetorComparacao,  const float& tolerancia) const
{
    if ( fabsf(x - vetorComparacao.x) >= tolerancia ) return false;
    if ( fabsf(y - vetorComparacao.y) >= tolerancia ) return false;
    if ( fabsf(z - vetorComparacao.z) >= tolerancia ) return false;
    return true;
}

/*************************************************************/
/*                                                           */
/*************************************************************/
CI3DVetor& CI3DVetor::Normalizar()
{
    float   denom;

    denom = sqrtf(x * x + y * y + z * z);
    if (fabsf(denom) < 1e-5f) return *this;

    denom = 1.0f / denom;

    x *= denom;
    y *= denom;
    z *= denom;

    return *this;
}

/************************************************************/
/*Nome do Método    : AnguloEntre
/*
/*Objetivo          : Retorna o angulo entre este vetor e 
/*                    outro vetor passado.
/*
/************************************************************/
double CI3DVetor::AnguloEntre(const CI3DVetor& kbcVetor) const
{

	float  kbcProdEsc = ProdutoEscalar(kbcVetor);				

	float  kbcMags    = Magnitude() * kbcVetor.Magnitude();

	double kbcAngulo  = acos( kbcProdEsc / kbcMags );

	// Para ter certeza que não e angulo indefinido
	if(_isnan(kbcAngulo))
		return 0;

	// retorna em radianos
	return( kbcAngulo );

}

/************************************************************/
/*Nome do Método    : Distancia
/*
/*Objetivo          : Retorna a Distancia entre este vetor e
/*                    um vetor passado
/*
/************************************************************/
float CI3DVetor::Distancia(const CI3DVetor& vetor) const
{
	return sqrt((vetor.x - x) * (vetor.x - x) +
		        (vetor.y - y) * (vetor.y - y) +
		        (vetor.z - z) * (vetor.z - z));

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float CI3DVetor::DistanciaLinha( const CI3DVetor& vecStart, const CI3DVetor& vecEnd ) const
{
    CI3DVetor c, v;
    float     d, t;

    // Determina t 
    // (o tamanho do vetor do inicio até ‘this’)
    c = *this  - vecStart;
    v = vecEnd - vecStart;   
    d = v.Magnitude();
    
    v.Normalizar();
    
    t = v.ProdutoEscalar( c );
   
    // Checa se ‘t’ esta dentro do segmento de linha
    if (t < 0.01f)     return 99999.0f;
    if (t > d - 0.01f) return 99999.0f;
  
    v.x = vecStart.x + (v.x * t);
    v.y = vecStart.y + (v.y * t);
    v.z = vecStart.z + (v.z * t);
  
    // Returna a distancia
    return ((*this) - v).Magnitude();
}



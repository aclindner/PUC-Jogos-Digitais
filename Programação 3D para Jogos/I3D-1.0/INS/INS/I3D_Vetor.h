/*********************************************************************************/
/*Projeto             :Insane Engine
/*Descricao           :
/*Data de Criação     :
/*
/*Copyright (c) 2013 William Wolff. Todos os direitos reservados
/**********************************************************************************/
#ifndef _I3D_VETOR_H_
#define _I3D_VETOR_H_

//-----------------------------------------------------------------------------
// Name : CI3DVetor2 (Class)
// Desc : 2D Vector class. Storage for vector values and wraps up vector math.
//-----------------------------------------------------------------------------
class CI3DVetor2
{
public:

    CI3DVetor2( ) { }
    CI3DVetor2( const CI3DVetor2 & vec ) {x = vec.x; y = vec.y; }
    CI3DVetor2( float _x, float _y ) { x = _x; y = _y; }
    
    union {
        struct {
            float    x;              
            float    y;              
        };
        float v[2];
    }; 
};

/************************************************************/
/*Nome da Classe      : CI3DVetor
/*Objetivo            : 
/************************************************************/
class CI3DVetor
{
public:

    CI3DVetor( );
    CI3DVetor( const CI3DVetor & vetor );
    CI3DVetor( float _x, float _y, float _z );
    
    union {
        struct {
            float    x;              
            float    y;             
            float    z;              
        }; 
        float v[3];
    }; 
	

	bool                Vazio          (                                 ) const;
    CI3DVetor           ProdutoVetorial( const CI3DVetor& V1             ) const;
    float               ProdutoEscalar ( const CI3DVetor& vetor          ) const;
    float               Magnitude      (                                 ) const;
    float               MeiaMagnitude  (                                 ) const;
    bool                Compara        (const CI3DVetor& vetorComparacao,  
		                                const float& tolerancia          ) const;
    CI3DVetor&          Normalizar     (                                 )      ;
	float               Distancia      (const CI3DVetor& vetor           ) const;
	double              AnguloEntre    (const CI3DVetor& kbcVetor        ) const;
    float               DistanciaLinha (const CI3DVetor& vecStart, const CI3DVetor& vecEnd ) const;


    
	CI3DVetor  operator+  ( const CI3DVetor& vetor ) const;
    CI3DVetor  operator-  ( const CI3DVetor& vetor ) const;
    CI3DVetor  operator*  ( const CI3DVetor& vetor ) const;
    CI3DVetor  operator*  ( const float& Valor  ) const;
    CI3DVetor  operator/  ( const float& Valor  ) const;

    CI3DVetor& operator+= ( const CI3DVetor& vetor );
    CI3DVetor& operator-= ( const CI3DVetor& vetor );
    CI3DVetor& operator/= ( const float& Valor  );
    CI3DVetor& operator*= ( const float& Valor  );

    CI3DVetor  operator+  () const;
    CI3DVetor  operator-  () const;
    CI3DVetor& operator=  ( const CI3DVetor& vetor );
    bool       operator== ( const CI3DVetor& vetor ) const;
    bool       operator!= ( const CI3DVetor& vetor ) const;

    operator float * ();
    operator const float * () const;

    
    friend CI3DVetor operator * (float Valor, const CI3DVetor& vetor );
};

#endif
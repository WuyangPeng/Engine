// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/08 15:11)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_THRICE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_THRICE_H

#include "Mathematics/MathematicsDll.h"

#include "EquationImpl.h"

namespace Mathematics
{
	class MATHEMATICS_HIDDEN_DECLARE EquationThrice :public EquationImpl
    {
    public:
        using ClassType = EquationThrice;
        using ParentType = EquationImpl;
        
    public:
        EquationThrice(double constant,double once,double secondary,double thrice,double epsilon = Mathd::sm_ZeroTolerance);
        virtual ~EquationThrice();
        
		CLASS_INVARIANT_VIRTUAL_DECLARE;
        
        virtual double Substitution(double value) const;
		virtual const Imaginary Substitution(const Imaginary& value) const;

	private:
		virtual double SubstitutionTangent(double solution) const;
		virtual const Imaginary SubstitutionTangent(const Imaginary& solution) const;

		virtual void Solving();
		virtual bool Predigest();

		static double CalculateDiscriminant(double pThird,double qHalf);
		
		double CalculatePThird() const;
		double CalculateQHalf() const;

		void CalculateResult(double pThird,double qHalf,double discriminant);
		void CalculateResultDiscriminantIsPlus(double qHalf,double discriminant);
		void CalculateResultDiscriminantIsZero(double qHalf);
		void CalculateResultDiscriminantIsNegative(double pThird,double qHalf);

	private:
		double m_Constant;	
		double m_Once;
		double m_Secondary;
		double m_Thrice;		
	};		
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_THRICE_H
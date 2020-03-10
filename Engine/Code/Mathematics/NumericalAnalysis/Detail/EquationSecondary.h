// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/08 15:11)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_SECONDARY_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_SECONDARY_H

#include "Mathematics/MathematicsDll.h"

#include "EquationImpl.h"

namespace Mathematics
{
	class MATHEMATICS_HIDDEN_DECLARE EquationSecondary : public EquationImpl
    {
    public:
        using ClassType = EquationSecondary;
        using ParentType = EquationImpl;
        
    public:
		EquationSecondary(double constant, double once,double secondary, double epsilon = Mathd::sm_ZeroTolerance);
        virtual ~EquationSecondary();
        
		CLASS_INVARIANT_VIRTUAL_DECLARE;
        
		virtual double Substitution(double value) const;
		virtual const Imaginary Substitution(const Imaginary& value) const;

	private:
		virtual double SubstitutionTangent(double solution) const;
		virtual const Imaginary SubstitutionTangent(const Imaginary& solution) const;

		virtual void Solving();
		virtual bool Predigest();
		
		double CalculateDiscriminant() const;
		double CalculateLhs() const;

		void CalculateResult(double lhs,double discriminant);
		void CalculateResultDiscriminantIsPlus(double lhs,double discriminant);
		void CalculateResultDiscriminantIsZero(double lhs);
		void CalculateResultDiscriminantIsNegative(double lhs,double discriminant);

	private:
		double m_Constant;	
		double m_Once;
		double m_Secondary;
	};	
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_SECONDARY_H
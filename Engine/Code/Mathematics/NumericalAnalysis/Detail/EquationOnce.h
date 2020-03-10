// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/08 15:08)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_ONCE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_ONCE_H

#include "Mathematics/MathematicsDll.h"

#include "EquationImpl.h"

namespace Mathematics
{
	class MATHEMATICS_HIDDEN_DECLARE EquationOnce : public EquationImpl
	{
    public:
        using ClassType = EquationOnce;
        using ParentType = EquationImpl;
        
	public:
		EquationOnce(double constant, double once, double epsilon = Mathd::sm_ZeroTolerance);
		virtual ~EquationOnce();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual double Substitution(double value) const;
		virtual const Imaginary Substitution(const Imaginary& value) const;

	private:
		virtual double SubstitutionTangent(double solution) const;
		virtual const Imaginary SubstitutionTangent(const Imaginary& solution) const;

		virtual void Solving();
		virtual bool Predigest();

	private:
		double m_Constant;	
		double m_Once;			
	};	
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_ONCE_H
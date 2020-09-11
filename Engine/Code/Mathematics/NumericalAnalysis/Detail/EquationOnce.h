// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 12:43)

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
		EquationOnce(double constant, double once, double epsilon = DoubleMath::GetZeroTolerance());
	 

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		  double Substitution(double value) const noexcept override;
		  const Imaginary Substitution(const Imaginary& value) const override;

	private:
		  double SubstitutionTangent(double solution) const noexcept override;
		  const Imaginary SubstitutionTangent(const Imaginary& solution) const override;

		  void Solving() override;
		  bool Predigest() noexcept override;

	private:
		double m_Constant;
		double m_Once;
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_ONCE_H
// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 12:43)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_QUARTIC_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_QUARTIC_H

#include "Mathematics/MathematicsDll.h"

#include "EquationImpl.h"

namespace Mathematics
{
	class MATHEMATICS_HIDDEN_DECLARE EquationQuartic :public EquationImpl
	{
	public:
		using ClassType = EquationQuartic;
		using ParentType = EquationImpl;

	public:
		EquationQuartic(double constant, double once, double secondary, double thrice, double quartic, double epsilon = DoubleMath::GetZeroTolerance())  ;
	 

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		  double Substitution(double value) const noexcept override;
		  const Imaginary Substitution(const Imaginary& value) const override;

	private:
		  double SubstitutionTangent(double solution) const noexcept override;
		  const Imaginary SubstitutionTangent(const Imaginary& solution) const override;

		  void Solving() override;
		  bool Predigest() override;

		double CalculateP()  const noexcept;
		double CalculateQ()   const noexcept;
		double CalculateR()   const noexcept;
		void CalculateThriceEquation(double p, double q, double r);

		void CalculateResult(double solution, double p, double q, double r);
		void CalculateSecondaryEquation(double thriceSolution, double constant, double once);

	private:
		double m_Constant;
		double m_Once;
		double m_Secondary;
		double m_Thrice;
		double m_Quartic;
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_QUARTIC_H
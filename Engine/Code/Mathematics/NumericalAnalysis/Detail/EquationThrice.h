// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 12:45)

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
		EquationThrice(double constant, double once, double secondary, double thrice, double epsilon = Mathd::GetZeroTolerance())  ;
	 

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		  double Substitution(double value) const noexcept override;
		  const Imaginary Substitution(const Imaginary& value) const override;

	private:
		  double SubstitutionTangent(double solution) const noexcept override;
		  const Imaginary SubstitutionTangent(const Imaginary& solution) const override;

		  void Solving() override;
		  bool Predigest() override;

		static constexpr double CalculateDiscriminant(double pThird, double qHalf) noexcept
{
	return qHalf * qHalf + pThird * pThird * pThird;
}

		double CalculatePThird() const noexcept;
		double CalculateQHalf() const noexcept;

		void CalculateResult(double pThird, double qHalf, double discriminant);
		void CalculateResultDiscriminantIsPlus(double qHalf, double discriminant);
		void CalculateResultDiscriminantIsZero(double qHalf);
		void CalculateResultDiscriminantIsNegative(double pThird, double qHalf);

	private:
		double m_Constant;
		double m_Once;
		double m_Secondary;
		double m_Thrice;
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_THRICE_H
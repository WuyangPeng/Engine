// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 12:44)

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
		EquationSecondary(double constant, double once, double secondary, double epsilon = Mathd::sm_ZeroTolerance);
		virtual ~EquationSecondary();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual double Substitution(double value) const override;
		virtual const Imaginary Substitution(const Imaginary& value) const override;

	private:
		virtual double SubstitutionTangent(double solution) const override;
		virtual const Imaginary SubstitutionTangent(const Imaginary& solution) const override;

		virtual void Solving() override;
		virtual bool Predigest() override;

		double CalculateDiscriminant() const;
		double CalculateLhs() const;

		void CalculateResult(double lhs, double discriminant);
		void CalculateResultDiscriminantIsPlus(double lhs, double discriminant);
		void CalculateResultDiscriminantIsZero(double lhs);
		void CalculateResultDiscriminantIsNegative(double lhs, double discriminant);

	private:
		double m_Constant;
		double m_Once;
		double m_Secondary;
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_SECONDARY_H
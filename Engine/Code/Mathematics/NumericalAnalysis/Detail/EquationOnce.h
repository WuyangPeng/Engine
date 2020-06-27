// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/20 12:43)

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

		virtual double Substitution(double value) const override;
		virtual const Imaginary Substitution(const Imaginary& value) const override;

	private:
		virtual double SubstitutionTangent(double solution) const override;
		virtual const Imaginary SubstitutionTangent(const Imaginary& solution) const override;

		virtual void Solving() override;
		virtual bool Predigest() override;

	private:
		double m_Constant;
		double m_Once;
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_ONCE_H
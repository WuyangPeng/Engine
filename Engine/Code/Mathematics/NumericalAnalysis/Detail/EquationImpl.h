// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 12:43)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_IMPL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "EquationResult.h"
#include "Mathematics/Base/MathDetail.h"

namespace Mathematics
{
	class MATHEMATICS_HIDDEN_DECLARE EquationImpl
	{
	public:
		using ClassType = EquationImpl;
		using RealConstIterator = EquationResult::RealConstIterator;
		using ImaginaryConstIterator = EquationResult::ImaginaryConstIterator;
		using Imaginary = EquationResult::Imaginary;
		using ImaginaryVector = EquationResult::ImaginaryVector;
		using RealVector = EquationResult::RealVector;

	public:
		explicit EquationImpl(double epsilon = Mathd::sm_ZeroTolerance);
		virtual ~EquationImpl();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		double GetEpsilon() const;

		bool IsRealResult() const;
		int GetRealResultCount() const;
		int GetImaginaryResultCount() const;

		const RealConstIterator GetRealBegin() const;
		const RealConstIterator GetRealEnd() const;
		const ImaginaryConstIterator GetImaginaryBegin() const;
		const ImaginaryConstIterator GetImaginaryEnd() const;

		virtual double Substitution(double value) const = 0;
		virtual const Imaginary Substitution(const Imaginary& value) const = 0;

	protected:
		void SetRealResult(double result);
		void SetImaginaryResult(const Imaginary& result);
		void AddResult(const EquationImpl& equation, double offset = 0.0);
		void Calculate();
		void SortResult();

	private:
		double NewtonMethod(double solution) const;
		const Imaginary NewtonMethod(const Imaginary& solution) const;
		const RealVector NewRealResult() const;
		const ImaginaryVector NewImaginaryResult() const;

		void CleanSolution();
		void Validate();
		void AddRealResult(const EquationImpl& equation, double offset = 0.0);
		void AddImaginaryResult(const EquationImpl& equation, double offset = 0.0);
		void DisplaceRealResult(const RealVector& result);
		void DisplaceImaginaryResult(const ImaginaryVector& result);

		virtual double SubstitutionTangent(double solution) const = 0;
		virtual const Imaginary SubstitutionTangent(const Imaginary& solution) const = 0;

		virtual void Solving() = 0;
		virtual bool Predigest() = 0;

	private:
		static constexpr auto sm_MaxTime = 10;

	private:
		EquationResult m_Result;
		double m_Epsilon;
	};
}

#endif // MATH_TOOL_EQUATION_IMPL_H
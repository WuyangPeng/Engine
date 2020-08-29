// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 12:44)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_RESULT_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_RESULT_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/EquationResultConstIterator.h"

#include <vector>
#include <complex>

namespace Mathematics
{
	class MATHEMATICS_HIDDEN_DECLARE EquationResult
	{
	public:
		using ClassType = EquationResult;
		using Imaginary = std::complex<double>;
		using ImaginaryVector = std::vector<Imaginary>;
		using RealVector = std::vector<double>;
		using ImaginaryResultConstIter = ImaginaryVector::const_iterator;
		using RealResultConstIter = RealVector::const_iterator;
		using RealConstIterator = EquationResultConstIterator<RealResultConstIter>;
		using ImaginaryConstIterator = EquationResultConstIterator<ImaginaryResultConstIter>;

	public:
		EquationResult() noexcept;

		CLASS_INVARIANT_DECLARE;

		bool IsRealResult() const noexcept;
		int GetRealResultCount() const;
		int GetImaginaryResultCount() const;

		void AddRealResult(double solution, double epsilon = Mathd::GetZeroTolerance());
		void AddImaginaryResult(const Imaginary& solution, double epsilon = Mathd::GetZeroTolerance());
		void CleanSolution() noexcept;

		const RealConstIterator GetRealBegin() const noexcept;
		const RealConstIterator GetRealEnd() const noexcept;
		const ImaginaryConstIterator GetImaginaryBegin() const noexcept;
		const ImaginaryConstIterator GetImaginaryEnd() const noexcept;

		void SortResult();

	private:
		bool FindSolution(double solution, double epsilon) const noexcept;
		bool FindSolution(const Imaginary& solution, double epsilon) const;

		class ImaginaryLess
		{
		public:
			using ClassType = ImaginaryLess;

		public:
			bool operator()(const Imaginary& lhs, const Imaginary& rhs) const;

			CLASS_INVARIANT_DECLARE;
		};

	private:
		RealVector m_RealResult;
		ImaginaryVector m_ImaginaryResult;
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_RESULT_H
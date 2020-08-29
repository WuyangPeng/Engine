// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 12:55)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_SYMMETRIC_CONJUGATE_GRADIENT_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_SYMMETRIC_CONJUGATE_GRADIENT_H

#include "Mathematics/MathematicsDll.h"

#include "LinearSystemConstIteratorDetail.h"
#include "Mathematics/Base/MathDetail.h"

#include <boost/noncopyable.hpp>
#include <vector>

namespace Mathematics
{
	template <typename Real, template <typename> class Matrix>
	class SolveSymmetricConjugateGradient : private boost::noncopyable
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = SolveSymmetricConjugateGradient<Real, Matrix>;
		using MatrixType = Matrix<Real>;
		using OutputConstIterator = LinearSystemConstIterator<Real>;

	public:
		explicit SolveSymmetricConjugateGradient(const MatrixType& matrix, const Real* inputVector, Real zeroTolerance = Math<Real>::GetZeroTolerance());

		CLASS_INVARIANT_DECLARE;

		const OutputConstIterator GetBegin() const;
		const OutputConstIterator GetEnd() const;

	private:
		using RealVector = std::vector<Real>;

	private:
		void CalculateNormal(const Real* inputVector);
		void FirstIteration();
		void RemainingIterations();

		Real Dot(const Real* lhs, const Real* rhs) const;

		void Multiply();
		void UpdateOutput();
		void UpdateFirstAmend();
		void UpdateSecondAmend();

	private:
		Real m_ZeroTolerance;
		const MatrixType& m_Matrix;
		int m_Size;
		RealVector m_InputFirstAmend;
		RealVector m_InputSecondAmend;
		RealVector m_Product;
		Real m_Normal;
		RealVector m_Output;
		Real m_FirstDot;
		Real m_SecondDot;
		Real m_Alpha;
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_SYMMETRIC_CONJUGATE_GRADIENT_H

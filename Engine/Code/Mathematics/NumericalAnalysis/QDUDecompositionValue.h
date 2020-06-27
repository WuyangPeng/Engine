// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 12:53)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_QDU_DECOMPOSITION_VALUE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_QDU_DECOMPOSITION_VALUE_H

#include "Mathematics/Algebra/Matrix3.h"

namespace Mathematics
{
	template <typename Real>
	class QDUDecompositionValue
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = QDUDecompositionValue<Real>;
		using Matrix3 = Matrix3<Real>;

	public:
		explicit QDUDecompositionValue(const Matrix3& matrix);

		CLASS_INVARIANT_DECLARE;

	public:
		const Matrix3 GeOrthogonalMatrix() const;
		const Matrix3 GetDiagonalMatrix() const;
		const Matrix3 GetUpperTriangularMatrix() const;

	private:
		void Calculate(const Matrix3& matrix);

	private:
		Matrix3 m_Orthogonal;
		Matrix3 m_Diagonal;
		Matrix3 m_UpperTriangular;
	};

	using QDUDecompositionValuef = QDUDecompositionValue<float>;
	using QDUDecompositionValued = QDUDecompositionValue<double>;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_QDU_DECOMPOSITION_VALUE_H

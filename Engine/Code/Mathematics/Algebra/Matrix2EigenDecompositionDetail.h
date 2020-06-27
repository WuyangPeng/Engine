// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 13:09)

#ifndef MATHEMATICS_ALGEBRA_MATRIX2_EIGEN_DECOMPOSITION_DETAIL_H
#define MATHEMATICS_ALGEBRA_MATRIX2_EIGEN_DECOMPOSITION_DETAIL_H

#include "Matrix2EigenDecomposition.h"
#include "Matrix2.h"
#include "AlgebraTraits.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/Math.h"

template <typename Real>
Mathematics::Matrix2EigenDecomposition<Real>
	::Matrix2EigenDecomposition(const Matrix2& rotation, const Matrix2& diagonal, const Real epsilon)
	: m_Rotation{ rotation }, m_Diagonal{ diagonal }, m_Epsilon{ epsilon }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Matrix2EigenDecomposition<Real>
	::IsValid() const noexcept
{
	if (Math::FAbs(m_Rotation(0, 0) - m_Rotation(1, 1)) <= m_Epsilon &&
		Math::FAbs(m_Rotation(0, 1) + m_Rotation(1, 0)) <= m_Epsilon &&
		Math::FAbs(m_Rotation(0, 0) * m_Rotation(1, 1) - m_Rotation(0, 1) * m_Rotation(1, 0) - AlgebraTraits::UnitValue) <= m_Epsilon &&
		Math::FAbs(m_Diagonal(0, 1) - Math::sm_Zero) <= m_Epsilon &&
		Math::FAbs(m_Diagonal(1, 0) - Math::sm_Zero) <= m_Epsilon)
	{
		return true;
	}
	else
	{
		return false;
	}

}
#endif	// OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::Matrix2EigenDecomposition<Real>::Matrix2 Mathematics::Matrix2EigenDecomposition<Real>
	::GetRotation() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Rotation;
}

template <typename Real>
typename const Mathematics::Matrix2EigenDecomposition<Real>::Matrix2 Mathematics::Matrix2EigenDecomposition<Real>
	::GetDiagonal() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Diagonal;
}

#endif // MATHEMATICS_ALGEBRA_MATRIX2_EIGEN_DECOMPOSITION_DETAIL_H

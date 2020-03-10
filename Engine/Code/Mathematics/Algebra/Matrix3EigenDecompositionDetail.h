// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/05 16:14)

#ifndef MATHEMATICS_ALGEBRA_MATRIX3_EIGEN_DECOMPOSITION_DETAIL_H
#define MATHEMATICS_ALGEBRA_MATRIX3_EIGEN_DECOMPOSITION_DETAIL_H

#include "Matrix3EigenDecomposition.h"
#include "Matrix3.h"
#include "AlgebraTraits.h"
#include "Mathematics/Base/Math.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics:: Matrix3EigenDecomposition <Real>	
	:: Matrix3EigenDecomposition (const Matrix3& rotation,const Matrix3& diagonal,const Real epsilon)
	: m_Rotation{ rotation }, m_Diagonal{ diagonal }, m_Epsilon{ epsilon }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics:: Matrix3EigenDecomposition <Real>
	::IsValid() const noexcept
{
     if(Math::FAbs(m_Diagonal(0,1) - AlgebraTraits::NullValue) <= m_Epsilon &&
        Math::FAbs(m_Diagonal(0,2) - AlgebraTraits::NullValue) <= m_Epsilon &&
        Math::FAbs(m_Diagonal(1,0) - AlgebraTraits::NullValue) <= m_Epsilon &&
        Math::FAbs(m_Diagonal(1,2) - AlgebraTraits::NullValue) <= m_Epsilon &&
        Math::FAbs(m_Diagonal(2,0) - AlgebraTraits::NullValue) <= m_Epsilon &&
        Math::FAbs(m_Diagonal(2,1) - AlgebraTraits::NullValue) <= m_Epsilon)
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
typename const Mathematics::Matrix3EigenDecomposition<Real>::Matrix3 Mathematics::Matrix3EigenDecomposition<Real>
	::GetRotation() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Rotation;
}

template <typename Real>
typename const Mathematics::Matrix3EigenDecomposition<Real>::Matrix3 Mathematics::Matrix3EigenDecomposition<Real>
	::GetDiagonal() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Diagonal;
} 

#endif // MATHEMATICS_ALGEBRA_MATRIX3_EIGEN_DECOMPOSITION_DETAIL_H

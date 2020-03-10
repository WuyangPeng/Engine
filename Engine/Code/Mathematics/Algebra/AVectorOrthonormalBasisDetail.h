// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/04 18:18)

#ifndef MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMA_BASIS_DETAIL_H
#define MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMA_BASIS_DETAIL_H

#include "AVectorOrthonormalBasis.h"

#include "AVectorDetail.h"
#include "CoreTools/DataTypes/TupleDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::AVectorOrthonormalBasis <Real>
	::AVectorOrthonormalBasis(const AVector& nonzeroVector,bool isUnit,const Real epsilon)
	: m_IsUnit{ isUnit }, m_UVector{}, m_VVector{},
	  m_WVector{ nonzeroVector }, m_Epsilon{ epsilon }
{
	MATHEMATICS_ASSERTION_1(!nonzeroVector.IsZero(m_Epsilon),"输入必须是非零向量！");

	Generate();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics:: AVectorOrthonormalBasis <Real>
	::Generate()
{
    if(!m_IsUnit)
	{
 		m_WVector.Normalize(m_Epsilon);
	}

	if (Math::FAbs(m_WVector[1] <= Math::FAbs(m_WVector[0])))
	{
		GenerateOnXOrZIsMax();
	}
	else
	{
		GenerateOnYOrZIsMax();
	}
}

template <typename Real>
void Mathematics:: AVectorOrthonormalBasis <Real>
	::GenerateOnXOrZIsMax()
{
	// unitVector.x或unitVector.z是大小最大的组成部分，交换他们
	auto invLength = Math::InvSqrt(m_WVector[0] * m_WVector[0] + m_WVector[2] * m_WVector[2]);

	m_UVector = AVector{ -m_WVector[2] * invLength,Real{},m_WVector[0] * invLength };

	m_VVector = AVector{ m_WVector[1] * m_UVector[2],m_WVector[2] * m_UVector[0] - m_WVector[0] * m_UVector[2],-m_WVector[1] * m_UVector[0] };
} 

template <typename Real>
void Mathematics:: AVectorOrthonormalBasis <Real>
	::GenerateOnYOrZIsMax()
{
	// unitVector.y或unitVector.z是大小最大的组成部分，交换他们
	auto invLength = Math::InvSqrt(m_WVector[1] * m_WVector[1] + m_WVector[2] * m_WVector[2]);

	m_UVector = AVector{ Real{},m_WVector[2] * invLength,-m_WVector[1] * invLength };

	m_VVector = AVector{ m_WVector[1] * m_UVector[2] - m_WVector[2] * m_UVector[1],
						 -m_WVector[0] * m_UVector[2], m_WVector[0] * m_UVector[1] };
}
 
#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics:: AVectorOrthonormalBasis <Real>
	::IsValid() const noexcept
{
	if (Math::FAbs(Dot(m_UVector, m_VVector)) <= m_Epsilon &&
		Math::FAbs(Dot(m_UVector, m_WVector)) <= m_Epsilon &&
		Math::FAbs(Dot(m_VVector, m_WVector)) <= m_Epsilon &&
		m_UVector.IsNormalize(m_Epsilon) && m_VVector.IsNormalize(m_Epsilon) && m_WVector.IsNormalize(m_Epsilon))
	{
		return true;
	}		
	else
	{
		return false;
	}		
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
const typename Mathematics::AVectorOrthonormalBasis<Real>::AVector Mathematics:: AVectorOrthonormalBasis <Real>
	::GetUVector() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_UVector;	
}

template <typename Real>
const typename Mathematics:: AVectorOrthonormalBasis<Real>::AVector Mathematics:: AVectorOrthonormalBasis <Real>
	::GetVVector() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_VVector;	
}

template <typename Real>
const typename Mathematics:: AVectorOrthonormalBasis <Real>::AVector Mathematics:: AVectorOrthonormalBasis <Real>
	::GetWVector() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_WVector;	
}

#endif // MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMA_BASIS_DETAIL_H
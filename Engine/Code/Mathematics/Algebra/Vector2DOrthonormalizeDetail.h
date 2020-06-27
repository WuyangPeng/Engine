// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/19 15:47)

#ifndef MATHEMATICS_ALGEBRA_VECTOR_2D_ORTHONORMALIZE_DETAIL_H
#define MATHEMATICS_ALGEBRA_VECTOR_2D_ORTHONORMALIZE_DETAIL_H

#include "Vector2DOrthonormalize.h"
#include "Vector2D.h"
#include "Vector2DTools.h"
#include "CoreTools/DataTypes/TupleDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Vector2DOrthonormalize <Real>
	::Vector2DOrthonormalize(const Vector2D& lhs, const Vector2D& rhs, const Real epsilon)
	: m_UVector{ lhs }, m_VVector{ rhs }, m_Epsilon{ epsilon }
{
	Generate();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::Vector2DOrthonormalize <Real>
	::Generate()
{
	// �����������v0��v1����Gram-Schmidt������������ʸ��u0��u1���£�
	//
	//   u0 = v0 / |v0|
	//   u1 = (v1 - (u0 * v1)u0) / |v1 - (u0 * v1)u0|
	//
	// ����|A|��ʾ����A�ĳ��Ⱥ�A * B��ʾ����A��B�ĵ��

	// ���� u0.
	m_UVector.Normalize(m_Epsilon);

	// ���� u1.
	auto dot = Vector2DTools::DotProduct(m_UVector, m_VVector);

	MATHEMATICS_ASSERTION_1(m_Epsilon < Math::FAbs(dot), "�������������������޹صģ�");

	m_VVector -= m_UVector * dot;
	m_VVector.Normalize(m_Epsilon);
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Vector2DOrthonormalize<Real>
	::IsValid() const noexcept
{
	if (Math::FAbs(Vector2DTools::DotProduct(m_UVector, m_VVector)) <= m_Epsilon &&
		m_UVector.IsNormalize(m_Epsilon) && m_VVector.IsNormalize(m_Epsilon))
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
const typename Mathematics::Vector2DOrthonormalize<Real>::Vector2D Mathematics::Vector2DOrthonormalize<Real>
	::GetUVector() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_UVector;
}

template <typename Real>
const typename Mathematics::Vector2DOrthonormalize<Real>::Vector2D Mathematics::Vector2DOrthonormalize<Real>
	::GetVVector() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_VVector;
}

#endif // MATHEMATICS_ALGEBRA_VECTOR_2D_ORTHONORMALIZE_DETAIL_H
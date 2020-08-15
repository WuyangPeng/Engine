// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/19 15:52)

#ifndef MATHEMATICS_ALGEBRA_VECTOR_3D_ORTHONORMALIZE_DETAIL_H
#define MATHEMATICS_ALGEBRA_VECTOR_3D_ORTHONORMALIZE_DETAIL_H

#include "Vector3DOrthonormalize.h"
#include "Vector3D.h"
#include "Vector3DTools.h"
#include "CoreTools/DataTypes/TupleDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
template <typename Real>
Mathematics::Vector3DOrthonormalize <Real>
	::Vector3DOrthonormalize(const Vector3D& lhs, const Vector3D& mhs, const Vector3D& rhs, const Real epsilon)
	: m_UVector{ lhs }, m_VVector{ mhs }, m_WVector{ rhs }, m_Epsilon{ epsilon }
{
	Generate();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Vector3DOrthonormalize <Real>
	::Vector3DOrthonormalize(const std::vector<Vector3D> vectors, const Real epsilon)
	: m_UVector{ vectors[0] }, m_VVector{ vectors[1] }, m_WVector{ vectors[2] }, m_Epsilon{ epsilon }
{
	Generate();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::Vector3DOrthonormalize <Real>
	::Generate()
{
	// �����������v0��v1��v2����Gram-Schmidt������������ʸ��u0��u1��u2���£�
	//   u0 = v0 / |v0|
	//   u1 = (v1 - (u0 * v1)u0) / |v1 - (u0 * v1)u0|
	//   u2 = (v2 - (u0 * v2)u0 - (u1 * v2)u1) / 
	//        |v2 - (u0 * v2)u0 - (u1 * v2)u1|
	//
	// ����|A|��ʾ����A�ĳ��Ⱥ�A * B��ʾ����A��B�ĵ��

	// ���� u0
	m_UVector.Normalize(m_Epsilon);

	// ���� u1 
	auto dotUV = Vector3DTools::DotProduct(m_UVector, m_VVector);

	MATHEMATICS_ASSERTION_1(m_Epsilon < Math::FAbs(dotUV), "�������������������޹صģ�");

	m_VVector -= dotUV * m_UVector;
	m_VVector.Normalize(m_Epsilon);

	// ���� u2
	auto dotVW = Vector3DTools::DotProduct(m_VVector, m_WVector);
	auto dotUW = Vector3DTools::DotProduct(m_UVector, m_WVector);

	m_WVector -= dotUW * m_UVector + dotVW * m_VVector;
	m_WVector.Normalize(m_Epsilon);
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Vector3DOrthonormalize<Real>
	::IsValid() const noexcept
{
	try{
	if (Math::FAbs(Vector3DTools::DotProduct(m_UVector, m_VVector)) <= m_Epsilon &&
		Math::FAbs(Vector3DTools::DotProduct(m_UVector, m_WVector)) <= m_Epsilon &&
		Math::FAbs(Vector3DTools::DotProduct(m_VVector, m_WVector)) <= m_Epsilon &&
		m_UVector.IsNormalize(m_Epsilon) && m_VVector.IsNormalize(m_Epsilon) &&
		m_WVector.IsNormalize(m_Epsilon))
	{
		return true;
	}
	else
	{
		return false;
	}
	}
	catch(...)
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
const typename Mathematics::Vector3DOrthonormalize<Real>::Vector3D Mathematics::Vector3DOrthonormalize<Real>
	::GetUVector() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_UVector;
}

template <typename Real>
const typename Mathematics::Vector3DOrthonormalize<Real>::Vector3D Mathematics::Vector3DOrthonormalize<Real>
	::GetVVector() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_VVector;
}

template <typename Real>
const typename Mathematics::Vector3DOrthonormalize<Real>::Vector3D Mathematics::Vector3DOrthonormalize<Real>
	::GetWVector() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_WVector;
}
#include STSTEM_WARNING_POP
#endif // MATHEMATICS_ALGEBRA_VECTOR_3D_ORTHONORMALIZE_DETAIL_H
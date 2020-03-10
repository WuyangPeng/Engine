// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/08 09:26)

#ifndef MATHEMATICS_OBJECTS3D_BOX3_DETAIL_H
#define MATHEMATICS_OBJECTS3D_BOX3_DETAIL_H

#include "Box3.h"
#include "Mathematics/Algebra/Vector3DTools.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Box3<Real>
	::Box3()
	:m_Center{}, m_Epsilon{}, m_Axis{}, m_Extent{}
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}


template <typename Real>
Mathematics::Box3<Real>
	::Box3( const Vector3D& center, const Vector3D& firstAxis, const Vector3D& secondAxis, const Vector3D& thirdAxis,
			const Real firstExtent, const Real secondExtent, const Real thirdExtent, const Real epsilon )
	:m_Center{ center }, m_Epsilon{ epsilon }
{
	m_Axis[0] = firstAxis;
	m_Axis[1] = secondAxis;
	m_Axis[2] = thirdAxis;
	m_Extent[0] = firstExtent;
	m_Extent[1] = secondExtent;
	m_Extent[2] = thirdExtent;

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Box3<Real>
	::IsValid() const noexcept
{
	if (m_Axis[0].IsNormalize(m_Epsilon) && m_Axis[1].IsNormalize(m_Epsilon) &&
		m_Axis[2].IsNormalize(m_Epsilon) && -m_Epsilon <= m_Extent[0] &&
		-m_Epsilon <= m_Extent[1] && -m_Epsilon <= m_Extent[2] &&
		Real{} <= m_Epsilon)
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
const std::vector<typename Mathematics::Box3<Real>::Vector3D> Mathematics::Box3<Real>
	::ComputeVertices() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	Vector3D extAxis0 = m_Axis[0] * m_Extent[0];
	Vector3D extAxis1 = m_Axis[1] * m_Extent[1];
	Vector3D extAxis2 = m_Axis[2] * m_Extent[2];

	std::vector<Vector3D> vertex{ m_Center - extAxis0 - extAxis1 - extAxis2 ,m_Center + extAxis0 - extAxis1 - extAxis2 ,
								  m_Center + extAxis0 + extAxis1 - extAxis2 ,m_Center - extAxis0 + extAxis1 - extAxis2 ,
								  m_Center - extAxis0 - extAxis1 + extAxis2 ,m_Center + extAxis0 - extAxis1 + extAxis2 ,
								  m_Center + extAxis0 + extAxis1 + extAxis2 ,m_Center - extAxis0 + extAxis1 + extAxis2 }; 

	MATHEMATICS_ASSERTION_1(vertex.size() == 8,"���صĶ�����Ŀ����ȷ��");

	return vertex;
}

template <typename Real>
typename const Mathematics::Box3<Real>::Vector3D Mathematics::Box3<Real>
	::GetCenter() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Center;
}


template <typename Real>
typename const Mathematics::Box3<Real>::Vector3D Mathematics::Box3<Real>
	::GetFirstAxis() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Axis[0];
}

template <typename Real>
typename const Mathematics::Box3<Real>::Vector3D Mathematics::Box3<Real>
	::GetSecondAxis() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Axis[1];
}

template <typename Real>
typename const Mathematics::Box3<Real>::Vector3D Mathematics::Box3<Real>
	::GetThirdAxis() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Axis[2];
}

template <typename Real>
typename const Mathematics::Box3<Real>::Vector3D Mathematics::Box3<Real>
	::GetAxis(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < 3,"��������");

	return m_Axis[index];
}


template <typename Real>
Real Mathematics::Box3<Real>
	::GetExtent(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < 3,"��������");

	return m_Extent[index];
}

template <typename Real>
Real Mathematics::Box3<Real>
	::GetFirstExtent() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Extent[0];
}

template <typename Real>
Real Mathematics::Box3<Real>
	::GetSecondExtent() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Extent[1];
}

template <typename Real>
Real Mathematics::Box3<Real>
	::GetThirdExtent() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Extent[2];
}

template <typename Real>
Real Mathematics::Box3<Real>
	::GetEpsilon() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Epsilon;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::Box3<Real>
	::GetMove(Real t, const Vector3D& velocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return ClassType{ m_Center * t + velocity, m_Axis[0], m_Axis[1], m_Axis[2], m_Extent[0], m_Extent[1], m_Extent[2], m_Epsilon };
}


template <typename Real>
bool Mathematics
	::Approximate(const Box3<Real>& lhs, const Box3<Real>& rhs, const Real epsilon)
{
	return Vector3DTools<Real>::Approximate(lhs.GetCenter(),rhs.GetCenter(),epsilon) &&
		   Vector3DTools<Real>::Approximate(lhs.GetFirstAxis(),rhs.GetFirstAxis(),epsilon) &&
		   Vector3DTools<Real>::Approximate(lhs.GetSecondAxis(), rhs.GetSecondAxis(), epsilon) &&
		   Vector3DTools<Real>::Approximate(lhs.GetThirdAxis(), rhs.GetThirdAxis(), epsilon) &&
		   Math<Real>::Approximate(lhs.GetFirstExtent(), rhs.GetFirstExtent(), epsilon) &&
		   Math<Real>::Approximate(lhs.GetSecondExtent(), rhs.GetSecondExtent(), epsilon) &&
		   Math<Real>::Approximate(lhs.GetThirdExtent(), rhs.GetThirdExtent(), epsilon);
}


template <typename Real>
void Mathematics::Box3<Real>
	::Set(const Vector3D& center, const Vector3D& firstAxis, const Vector3D& secondAxis, const Vector3D& thirdAxis, const Real firstExtent, const Real secondExtent, const Real thirdExtent)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Center = center;

	m_Axis[0] = firstAxis;
	m_Axis[1] = secondAxis;
	m_Axis[2] = thirdAxis;
	m_Extent[0] = firstExtent;
	m_Extent[1] = secondExtent;
	m_Extent[2] = thirdExtent;
}

template <typename Real>
std::ostream& Mathematics
	::operator<<(std::ostream& outFile, const Box3<Real>& box)
{
	outFile << "center=" << box.GetCenter() << ",axis0=" << box.GetFirstAxis()
		    << ",axis1=" << box.GetSecondAxis() << ",axis2=" << box.GetThirdAxis() 
		    << "extent0=" << box.GetFirstExtent()
			<< "extent1=" << box.GetSecondExtent()
			<< "extent2=" << box.GetThirdExtent();

	return outFile;
}

#endif // MATHEMATICS_OBJECTS3D_BOX3_DETAIL_H


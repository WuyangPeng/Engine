// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.2 (2019/07/10 10:31)

#ifndef MATHEMATICS_QUERY_QUERY3_RATIONAL_DETAIL_H
#define MATHEMATICS_QUERY_QUERY3_INTEGER_DETAIL_H

#include "Query3Rational.h"
#include "QueryDotToolsDetail.h"
#include "Mathematics/Rational/IntegerDetail.h"
#include "Mathematics/Rational/SignRationalDetail.h"
#include "Mathematics/Rational/RationalVector3Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <boost/numeric/conversion/cast.hpp>

template <typename Real>
Mathematics::Query3Rational<Real>
	::Query3Rational(const std::vector<Vector3D>& vertices)
	:ParentType{ vertices }, m_RationalVertices{}
{
	Convert();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::Query3Rational<Real>
	::Convert()
{
	auto  numVertices = GetNumVertices();

	for (auto index = 0; index < numVertices; ++index)
	{
		const auto vertice = GetVertice(index);

		QueryRational firstRational{ vertice[0] };
		QueryRational secondRational{ vertice[1] };
		QueryRational thirdRational{ vertice[2] };

		m_RationalVertices.emplace_back(firstRational, secondRational, thirdRational);
	}		
}

template <typename Real>
Mathematics::Query3Rational<Real>
	::~Query3Rational()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Query3Rational<Real>
	::IsValid() const noexcept
{
    if(ParentType::IsValid())
        return true;
    else
        return false;    
}
#endif // OPEN_CLASS_INVARIANT


template <typename Real>
Mathematics::QueryType Mathematics::Query3Rational<Real>
	::GetType() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    
	return QueryType::Rational;
}

template <typename Real>
Mathematics::PlaneQueryType Mathematics::Query3Rational<Real>
	::ToPlane(int index, int v0, int v1, int v2) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_RationalVertices.size()), "Ë÷Òý´íÎó£¡");

	return ToPlane(m_RationalVertices[index], v0, v1,v2);
}


template <typename Real>
Mathematics::PlaneQueryType Mathematics::Query3Rational<Real>
	::ToPlane(const Vector3D& testVector, int v0, int v1, int v2) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1; 

	QueryRational firstRational{ testVector[0] };
	QueryRational secondRational{ testVector[1] };
	QueryRational thirdRational{ testVector[2] };

	QueryRationalVector queryRationalVector{ firstRational, secondRational, thirdRational };

	return ToPlane(queryRationalVector, v0, v1, v2);
}

template <typename Real>
Mathematics::PlaneQueryType Mathematics::Query3Rational<Real>
	::ToPlane(const QueryRationalVector& rationalTest, int v0, int v1, int v2) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= v0 && v0 < GetNumVertices(), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= v1 && v1 < GetNumVertices(), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= v2 && v2 < GetNumVertices(), "Ë÷Òý´íÎó£¡");

	auto x0 = rationalTest.GetX() - m_RationalVertices[v0].GetX();
	auto y0 = rationalTest.GetY() - m_RationalVertices[v0].GetY();
	auto z0 = rationalTest.GetZ() - m_RationalVertices[v0].GetZ();
	auto x1 = m_RationalVertices[v1].GetX() - m_RationalVertices[v0].GetX();
	auto y1 = m_RationalVertices[v1].GetY() - m_RationalVertices[v0].GetY();
	auto z1 = m_RationalVertices[v1].GetZ() - m_RationalVertices[v0].GetZ();
	auto x2 = m_RationalVertices[v2].GetX() - m_RationalVertices[v0].GetX();
	auto y2 = m_RationalVertices[v2].GetY() - m_RationalVertices[v0].GetY();
	auto z2 = m_RationalVertices[v2].GetZ() - m_RationalVertices[v0].GetZ();

	auto det = QueryDotTools<QueryRational>::Det3(x0, y0, z0, x1, y1, z1, x2, y2, z2);

	if (QueryRational{} < det)
		return PlaneQueryType::PositiveSide;
	else if (det < QueryRational{})
		return PlaneQueryType::NegativeSide;
	else
		return PlaneQueryType::OnPlane; 
}


template <typename Real>
Mathematics::TetrahedronQueryType Mathematics::Query3Rational<Real>
	::ToTetrahedron(int index, int v0, int v1, int v2, int v3) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_RationalVertices.size()), "Ë÷Òý´íÎó£¡");

	return ToTetrahedron(m_RationalVertices[index], v0, v1, v2, v3);
}


template <typename Real>
Mathematics::TetrahedronQueryType Mathematics::Query3Rational<Real>
	::ToTetrahedron(const Vector3D& testVector, int v0, int v1, int v2, int v3) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1; 

	QueryRational firstRational{ testVector[0] };
	QueryRational secondRational{ testVector[1] };
	QueryRational thirdRational{ testVector[2] };

	QueryRationalVector queryRationalVector{ firstRational, secondRational, thirdRational };

	return ToTetrahedron(queryRationalVector, v0, v1, v2, v3);
}

template <typename Real>
Mathematics::TetrahedronQueryType Mathematics::Query3Rational<Real>
	::ToTetrahedron(const QueryRationalVector& rationalTest, int v0, int v1, int v2, int v3) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= v0 && v0 < GetNumVertices(), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= v1 && v1 < GetNumVertices(), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= v2 && v2 < GetNumVertices(), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= v3 && v3 < GetNumVertices(), "Ë÷Òý´íÎó£¡");
	 
	auto sign0 = ToPlane(rationalTest, v1, v2, v3);
	if (sign0 == PlaneQueryType::PositiveSide)
	{
		return TetrahedronQueryType::Outside;
	}

	auto sign1 = ToPlane(rationalTest, v0, v2, v3);
	if (sign1 == PlaneQueryType::NegativeSide)
	{
		return TetrahedronQueryType::Outside;
	}

	auto sign2 = ToPlane(rationalTest, v0, v1, v3);
	if (sign2 == PlaneQueryType::PositiveSide)
	{
		return TetrahedronQueryType::Outside;
	}

	auto sign3 = ToPlane(rationalTest, v0, v1, v2);
	if (sign3 == PlaneQueryType::NegativeSide)
	{
		return TetrahedronQueryType::Outside;
	}

	if (sign0 == PlaneQueryType::OnPlane ||	sign1 == PlaneQueryType::OnPlane ||
		sign2 == PlaneQueryType::OnPlane ||	sign3 == PlaneQueryType::OnPlane)
	{
		return  TetrahedronQueryType::OnTetrahedron;
	}
	else
	{
		return  TetrahedronQueryType::Inside;
	}
}

template <typename Real>
Mathematics::CircumsphereQueryType Mathematics::Query3Rational<Real>
	::ToCircumsphere(int index, int v0, int v1, int v2, int v3) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_RationalVertices.size()), "Ë÷Òý´íÎó£¡");

	return ToCircumsphere(m_RationalVertices[index], v0, v1, v2, v3);
}


template <typename Real>
Mathematics::CircumsphereQueryType Mathematics::Query3Rational<Real>
	::ToCircumsphere(const Vector3D& testVector, int v0, int v1, int v2, int v3) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1; 

	QueryRational firstRational{ testVector[0] };
	QueryRational secondRational{ testVector[1] };
	QueryRational thirdRational{ testVector[2] };

	QueryRationalVector queryRationalVector{ firstRational, secondRational, thirdRational };

	return ToCircumsphere(queryRationalVector, v0, v1, v2, v3);
}


template <typename Real>
Mathematics::CircumsphereQueryType Mathematics::Query3Rational<Real>
	::ToCircumsphere(const QueryRationalVector& rationalTest, int v0, int v1, int v2, int v3) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= v0 && v0 < GetNumVertices(), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= v1 && v1 < GetNumVertices(), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= v2 && v2 < GetNumVertices(), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= v3 && v3 < GetNumVertices(), "Ë÷Òý´íÎó£¡");

	const auto& vector0 = m_RationalVertices[v0];
	const auto& vector1 = m_RationalVertices[v1];
	const auto& vector2 = m_RationalVertices[v2];
	const auto& vector3 = m_RationalVertices[v3];

	QueryRational s0x{ vector0.GetX() + rationalTest.GetX() };
	QueryRational d0x{ vector0.GetX() - rationalTest.GetX() };
	QueryRational s0y{ vector0.GetY() + rationalTest.GetY() };
	QueryRational d0y{ vector0.GetY() - rationalTest.GetY() };
	QueryRational s0z{ vector0.GetZ() + rationalTest.GetZ() };
	QueryRational d0z{ vector0.GetZ() - rationalTest.GetZ() };
	QueryRational s1x{ vector1.GetX() + rationalTest.GetX() };
	QueryRational d1x{ vector1.GetX() - rationalTest.GetX() };
	QueryRational s1y{ vector1.GetY() + rationalTest.GetY() };
	QueryRational d1y{ vector1.GetY() - rationalTest.GetY() };
	QueryRational s1z{ vector1.GetZ() + rationalTest.GetZ() };
	QueryRational d1z{ vector1.GetZ() - rationalTest.GetZ() };
	QueryRational s2x{ vector2.GetX() + rationalTest.GetX() };
	QueryRational d2x{ vector2.GetX() - rationalTest.GetX() };
	QueryRational s2y{ vector2.GetY() + rationalTest.GetY() };
	QueryRational d2y{ vector2.GetY() - rationalTest.GetY() };
	QueryRational s2z{ vector2.GetZ() + rationalTest.GetZ() };
	QueryRational d2z{ vector2.GetZ() - rationalTest.GetZ() };
	QueryRational s3x{ vector3.GetX() + rationalTest.GetX() };
	QueryRational d3x{ vector3.GetX() - rationalTest.GetX() };
	QueryRational s3y{ vector3.GetY() + rationalTest.GetY() };
	QueryRational d3y{ vector3.GetY() - rationalTest.GetY() };
	QueryRational s3z{ vector3.GetZ() + rationalTest.GetZ() };
	QueryRational d3z{ vector3.GetZ() - rationalTest.GetZ() };
	auto w0 = s0x * d0x + s0y * d0y + s0z * d0z;
	auto w1 = s1x * d1x + s1y * d1y + s1z * d1z;
	auto w2 = s2x * d2x + s2y * d2y + s2z * d2z;
	auto w3 = s3x * d3x + s3y * d3y + s3z * d3z;

	auto det = QueryDotTools<QueryRational>::Det4(d0x, d0y, d0z, w0, d1x, d1y, d1z, w1, d2x, d2y, d2z,  w2, d3x, d3y, d3z, w3);
    
	if (QueryRational{} < det)
		return CircumsphereQueryType::Outside;
	else if (det < QueryRational{})
		return CircumsphereQueryType::Inside;
	else
		return CircumsphereQueryType::OnCircumsphere;
}


#endif // MATHEMATICS_QUERY_QUERY3_RATIONAL_DETAIL_H

// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.5 (2020/03/23 10:01)

#ifndef MATHEMATICS_QUERY_QUERY3_DETAIL_H
#define MATHEMATICS_QUERY_QUERY3_DETAIL_H

#include "Query3.h"
#include "QuerySortTools.h"
#include "QueryDotToolsDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

template <typename Real>
Mathematics::Query3<Real>
	::Query3(const std::vector<Vector3D>& vertices)
	:ParentType{}, m_Vertices{ vertices }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Query3<Real>
	::~Query3()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Query3<Real>
	::IsValid() const noexcept
{
	if (!m_Vertices.empty())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::QueryType Mathematics::Query3<Real>
	::GetType() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return QueryType::Real;
}

template <typename Real>
int Mathematics::Query3<Real>
	::GetNumVertices() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return boost::numeric_cast<int>(m_Vertices.size());
}

template <typename Real>
typename const Mathematics::Query3<Real>::Vector3D Mathematics::Query3<Real>
	::GetVertice(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_Vertices.size()), "Ë÷Òý´íÎó£¡");

	return m_Vertices[index];
}

template <typename Real>
Mathematics::PlaneQueryType Mathematics::Query3<Real>
	::ToPlane(int index, int v0, int v1, int v2) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_Vertices.size()), "Ë÷Òý´íÎó£¡");

	return ToPlane(m_Vertices[index], v0, v1, v2);
}

template <typename Real>
Mathematics::PlaneQueryType Mathematics::Query3<Real>
	::ToPlane(const Vector3D& testVector, int v0, int v1, int v2) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= v0 && v0 < boost::numeric_cast<int>(m_Vertices.size()), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= v1 && v1 < boost::numeric_cast<int>(m_Vertices.size()), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= v2 && v2 < boost::numeric_cast<int>(m_Vertices.size()), "Ë÷Òý´íÎó£¡");

	QuerySortTools querySortTools{ v0, v1,v2 };

	const auto& vector0 = m_Vertices[querySortTools.GetValue(0)];
	const auto& vector1 = m_Vertices[querySortTools.GetValue(1)];
	const auto& vector2 = m_Vertices[querySortTools.GetValue(2)];

	auto x0 = testVector[0] - vector0[0];
	auto y0 = testVector[1] - vector0[1];
	auto z0 = testVector[2] - vector0[2];
	auto x1 = vector1[0] - vector0[0];
	auto y1 = vector1[1] - vector0[1];
	auto z1 = vector1[2] - vector0[2];
	auto x2 = vector2[0] - vector0[0];
	auto y2 = vector2[1] - vector0[1];
	auto z2 = vector2[2] - vector0[2];

	auto det = QueryDotTools<Real>::Det3(x0, y0, z0, x1, y1, z1, x2, y2, z2);

	auto positive = querySortTools.GetSymbol();
	if (positive == NumericalValueSymbol::Negative)
	{
		det = -det;
	}

	if (Math<Real>::FAbs(det) <= Math<Real>::GetZeroTolerance())
		return PlaneQueryType::OnPlane;
	else if (Math<Real>::GetValue(0) < det)
		return PlaneQueryType::PositiveSide;
	else
		return PlaneQueryType::NegativeSide;
}

template <typename Real>
Mathematics::TetrahedronQueryType Mathematics::Query3<Real>
	::ToTetrahedron(int index, int v0, int v1, int v2, int v3) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_Vertices.size()), "Ë÷Òý´íÎó£¡");

	return ToTetrahedron(m_Vertices[index], v0, v1, v2, v3);
}

template <typename Real>
Mathematics::TetrahedronQueryType Mathematics::Query3<Real>
	::ToTetrahedron(const Vector3D& testVector, int v0, int v1, int v2, int v3) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= v0 && v0 < boost::numeric_cast<int>(m_Vertices.size()), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= v1 && v1 < boost::numeric_cast<int>(m_Vertices.size()), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= v2 && v2 < boost::numeric_cast<int>(m_Vertices.size()), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= v3 && v3 < boost::numeric_cast<int>(m_Vertices.size()), "Ë÷Òý´íÎó£¡");

	auto sign0 = ToPlane(testVector, v1, v2, v3);
	if (sign0 == PlaneQueryType::PositiveSide)
	{
		return TetrahedronQueryType::Outside;
	}

	auto sign1 = ToPlane(testVector, v0, v2, v3);
	if (sign1 == PlaneQueryType::NegativeSide)
	{
		return TetrahedronQueryType::Outside;
	}

	auto sign2 = ToPlane(testVector, v0, v1, v3);
	if (sign2 == PlaneQueryType::PositiveSide)
	{
		return TetrahedronQueryType::Outside;
	}

	auto sign3 = ToPlane(testVector, v0, v1, v2);
	if (sign3 == PlaneQueryType::NegativeSide)
	{
		return TetrahedronQueryType::Outside;
	}

	if (sign0 == PlaneQueryType::OnPlane || sign1 == PlaneQueryType::OnPlane ||
		sign2 == PlaneQueryType::OnPlane || sign3 == PlaneQueryType::OnPlane)
	{
		return  TetrahedronQueryType::OnTetrahedron;
	}
	else
	{
		return  TetrahedronQueryType::Inside;
	}
}

template <typename Real>
Mathematics::CircumsphereQueryType Mathematics::Query3<Real>
	::ToCircumsphere(int index, int v0, int v1, int v2, int v3) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_Vertices.size()), "Ë÷Òý´íÎó£¡");

	return ToCircumsphere(m_Vertices[index], v0, v1, v2, v3);
}

template <typename Real>
Mathematics::CircumsphereQueryType Mathematics::Query3<Real>
	::ToCircumsphere(const Vector3D& testVector, int v0, int v1, int v2, int v3) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= v0 && v0 < boost::numeric_cast<int>(m_Vertices.size()), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= v1 && v1 < boost::numeric_cast<int>(m_Vertices.size()), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= v2 && v2 < boost::numeric_cast<int>(m_Vertices.size()), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= v3 && v3 < boost::numeric_cast<int>(m_Vertices.size()), "Ë÷Òý´íÎó£¡");

	QuerySortTools querySortTools{ v0, v1, v2, v3 };

	const auto& vec0 = m_Vertices[querySortTools.GetValue(0)];
	const auto& vec1 = m_Vertices[querySortTools.GetValue(1)];
	const auto& vec2 = m_Vertices[querySortTools.GetValue(2)];
	const auto& vec3 = m_Vertices[querySortTools.GetValue(3)];

	auto s0x = vec0[0] + testVector[0];
	auto d0x = vec0[0] - testVector[0];
	auto s0y = vec0[1] + testVector[1];
	auto d0y = vec0[1] - testVector[1];
	auto s0z = vec0[2] + testVector[2];
	auto d0z = vec0[2] - testVector[2];
	auto s1x = vec1[0] + testVector[0];
	auto d1x = vec1[0] - testVector[0];
	auto s1y = vec1[1] + testVector[1];
	auto d1y = vec1[1] - testVector[1];
	auto s1z = vec1[2] + testVector[2];
	auto d1z = vec1[2] - testVector[2];
	auto s2x = vec2[0] + testVector[0];
	auto d2x = vec2[0] - testVector[0];
	auto s2y = vec2[1] + testVector[1];
	auto d2y = vec2[1] - testVector[1];
	auto s2z = vec2[2] + testVector[2];
	auto d2z = vec2[2] - testVector[2];
	auto s3x = vec3[0] + testVector[0];
	auto d3x = vec3[0] - testVector[0];
	auto s3y = vec3[1] + testVector[1];
	auto d3y = vec3[1] - testVector[1];
	auto s3z = vec3[2] + testVector[2];
	auto d3z = vec3[2] - testVector[2];
	auto w0 = s0x * d0x + s0y * d0y + s0z * d0z;
	auto w1 = s1x * d1x + s1y * d1y + s1z * d1z;
	auto w2 = s2x * d2x + s2y * d2y + s2z * d2z;
	auto w3 = s3x * d3x + s3y * d3y + s3z * d3z;

	auto det = QueryDotTools<Real>::Det4(d0x, d0y, d0z, w0, d1x, d1y, d1z, w1, d2x, d2y, d2z, w2, d3x, d3y, d3z, w3);
	auto positive = querySortTools.GetSymbol();
	if (positive == NumericalValueSymbol::Negative)
	{
		det = -det;
	}

	if (Math<Real>::FAbs(det) <= Math<Real>::GetZeroTolerance())
		return CircumsphereQueryType::OnCircumsphere;
	else if (det < Math<Real>::GetValue(0))
		return CircumsphereQueryType::Inside;
	else
		return CircumsphereQueryType::Outside;
}

#endif // MATHEMATICS_QUERY_QUERY3_DETAIL_H

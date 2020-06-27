// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.5 (2020/03/23 10:03)

#ifndef MATHEMATICS_QUERY_QUERY3_INTEGER_DETAIL_H
#define MATHEMATICS_QUERY_QUERY3_INTEGER_DETAIL_H

#include "Query3Integer.h"
#include "QueryDotToolsDetail.h"
#include "Mathematics/Rational/IntegerDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Query3Integer<Real>
	::Query3Integer(const std::vector<Vector3D>& vertices)
	:ParentType{ vertices }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Query3Integer<Real>
	::~Query3Integer()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Query3Integer<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::QueryType Mathematics::Query3Integer<Real>
	::GetType() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return QueryType::Interger;
}
template <typename Real>
Mathematics::PlaneQueryType Mathematics::Query3Integer<Real>
	::ToPlane(int index, int v0, int v1, int v2) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return ParentType::ToPlane(index, v0, v1, v2);
}

template <typename Real>
Mathematics::PlaneQueryType Mathematics::Query3Integer<Real>
	::ToPlane(const Vector3D& testVector, int v0, int v1, int v2) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= v0 && v0 < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= v1 && v1 < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= v2 && v2 < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");

	const auto vector0 = this->GetVertice(v0);
	const auto vector1 = this->GetVertice(v1);
	const auto vector2 = this->GetVertice(v2);

	Integer<4> x0{ testVector[0] - vector0[0] };
	Integer<4> y0{ testVector[1] - vector0[1] };
	Integer<4> z0{ testVector[2] - vector0[2] };
	Integer<4> x1{ vector1[0] - vector0[0] };
	Integer<4> y1{ vector1[1] - vector0[1] };
	Integer<4> z1{ vector1[2] - vector0[2] };
	Integer<4> x2{ vector2[0] - vector0[0] };
	Integer<4> y2{ vector2[1] - vector0[1] };
	Integer<4> z2{ vector2[2] - vector0[2] };

	auto det = QueryDotTools<Integer<4> >::Det3(x0, y0, z0, x1, y1, z1, x2, y2, z2);

	if (Integer<4>{} < det)
		return PlaneQueryType::PositiveSide;
	else if (det < Integer<4>{})
		return PlaneQueryType::NegativeSide;
	else
		return PlaneQueryType::OnPlane;
}

template <typename Real>
Mathematics::CircumsphereQueryType Mathematics::Query3Integer<Real>
	::ToCircumsphere(int index, int v0, int v1, int v2, int v3) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return ParentType::ToCircumsphere(index, v0, v1, v2, v3);
}

template <typename Real>
Mathematics::CircumsphereQueryType Mathematics::Query3Integer<Real>
	::ToCircumsphere(const Vector3D& testVector, int v0, int v1, int v2, int v3) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= v0 && v0 < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= v1 && v1 < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= v2 && v2 < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");

	const auto vector0 = this->GetVertice(v0);
	const auto vector1 = this->GetVertice(v1);
	const auto vector2 = this->GetVertice(v2);
	const auto vector3 = this->GetVertice(v3);

	Integer<6> s0x{ vector0[0] + testVector[0] };
	Integer<6> d0x{ vector0[0] - testVector[0] };
	Integer<6> s0y{ vector0[1] + testVector[1] };
	Integer<6> d0y{ vector0[1] - testVector[1] };
	Integer<6> s0z{ vector0[2] + testVector[2] };
	Integer<6> d0z{ vector0[2] - testVector[2] };
	Integer<6> s1x{ vector1[0] + testVector[0] };
	Integer<6> d1x{ vector1[0] - testVector[0] };
	Integer<6> s1y{ vector1[1] + testVector[1] };
	Integer<6> d1y{ vector1[1] - testVector[1] };
	Integer<6> s1z{ vector1[2] + testVector[2] };
	Integer<6> d1z{ vector1[2] - testVector[2] };
	Integer<6> s2x{ vector2[0] + testVector[0] };
	Integer<6> d2x{ vector2[0] - testVector[0] };
	Integer<6> s2y{ vector2[1] + testVector[1] };
	Integer<6> d2y{ vector2[1] - testVector[1] };
	Integer<6> s2z{ vector2[2] + testVector[2] };
	Integer<6> d2z{ vector2[2] - testVector[2] };
	Integer<6> s3x{ vector3[0] + testVector[0] };
	Integer<6> d3x{ vector3[0] - testVector[0] };
	Integer<6> s3y{ vector3[1] + testVector[1] };
	Integer<6> d3y{ vector3[1] - testVector[1] };
	Integer<6> s3z{ vector3[2] + testVector[2] };
	Integer<6> d3z{ vector3[2] - testVector[2] };
	auto w0 = s0x * d0x + s0y * d0y + s0z * d0z;
	auto w1 = s1x * d1x + s1y * d1y + s1z * d1z;
	auto w2 = s2x * d2x + s2y * d2y + s2z * d2z;
	auto w3 = s3x * d3x + s3y * d3y + s3z * d3z;

	auto det = QueryDotTools<Integer<6> >::Det4(d0x, d0y, d0z, w0, d1x, d1y, d1z, w1, d2x, d2y, d2z, w2, d3x, d3y, d3z, w3);

	if (Integer<6>{} < det)
		return CircumsphereQueryType::Outside;
	else if (det < Integer<6>{})
		return CircumsphereQueryType::Inside;
	else
		return CircumsphereQueryType::OnCircumsphere;
}

#endif // MATHEMATICS_QUERY_QUERY3_INTEGER_DETAIL_H

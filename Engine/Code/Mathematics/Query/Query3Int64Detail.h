// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.5 (2020/03/23 10:02)

#ifndef MATHEMATICS_QUERY_QUERY3_INT64_DETAIL_H
#define MATHEMATICS_QUERY_QUERY3_INT64_DETAIL_H

#include "Query3Int64.h"
#include "QueryDotToolsDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

template <typename Real>
Mathematics::Query3Int64<Real>
	::Query3Int64(const std::vector<Vector3D>& vertices)
	:ParentType{ vertices }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Query3Int64<Real>
	::~Query3Int64()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Query3Int64<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::QueryType Mathematics::Query3Int64<Real>
	::GetType() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return QueryType::Int64;
}

template <typename Real>
Mathematics::PlaneQueryType Mathematics::Query3Int64<Real>
	::ToPlane(int index, int v0, int v1, int v2) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return ParentType::ToPlane(index, v0, v1, v2);
}

template <typename Real>
Mathematics::PlaneQueryType Mathematics::Query3Int64<Real>
	::ToPlane(const Vector3D& testVector, int v0, int v1, int v2) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= v0 && v0 < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= v1 && v1 < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= v2 && v2 < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");

	const auto vector0 = this->GetVertice(v0);
	const auto vector1 = this->GetVertice(v1);
	const auto vector2 = this->GetVertice(v2);

	int64_t x0{ boost::numeric_cast<int64_t>(testVector[0]) - boost::numeric_cast<int64_t>(vector0[0]) };
	int64_t y0{ boost::numeric_cast<int64_t>(testVector[1]) - boost::numeric_cast<int64_t>(vector0[1]) };
	int64_t z0{ boost::numeric_cast<int64_t>(testVector[2]) - boost::numeric_cast<int64_t>(vector0[2]) };
	int64_t x1{ boost::numeric_cast<int64_t>(vector1[0]) - boost::numeric_cast<int64_t>(vector0[0]) };
	int64_t y1{ boost::numeric_cast<int64_t>(vector1[1]) - boost::numeric_cast<int64_t>(vector0[1]) };
	int64_t z1{ boost::numeric_cast<int64_t>(vector1[2]) - boost::numeric_cast<int64_t>(vector0[2]) };
	int64_t x2{ boost::numeric_cast<int64_t>(vector2[0]) - boost::numeric_cast<int64_t>(vector0[0]) };
	int64_t y2{ boost::numeric_cast<int64_t>(vector2[1]) - boost::numeric_cast<int64_t>(vector0[1]) };
	int64_t z2{ boost::numeric_cast<int64_t>(vector2[2]) - boost::numeric_cast<int64_t>(vector0[2]) };

	auto det = QueryDotTools<int64_t>::Det3(x0, y0, z0, x1, y1, z1, x2, y2, z2);

	if (0 < det)
		return PlaneQueryType::PositiveSide;
	else if (det < 0)
		return PlaneQueryType::NegativeSide;
	else
		return PlaneQueryType::OnPlane;
}

template <typename Real>
Mathematics::CircumsphereQueryType Mathematics::Query3Int64<Real>
	::ToCircumsphere(int index, int v0, int v1, int v2, int v3) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return ParentType::ToCircumsphere(index, v0, v1, v2, v3);
}

template <typename Real>
Mathematics::CircumsphereQueryType Mathematics::Query3Int64<Real>
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

	auto s0x = boost::numeric_cast<int64_t>(vector0[0] + testVector[0]);
	auto d0x = boost::numeric_cast<int64_t>(vector0[0] - testVector[0]);
	auto s0y = boost::numeric_cast<int64_t>(vector0[1] + testVector[1]);
	auto d0y = boost::numeric_cast<int64_t>(vector0[1] - testVector[1]);
	auto s0z = boost::numeric_cast<int64_t>(vector0[2] + testVector[2]);
	auto d0z = boost::numeric_cast<int64_t>(vector0[2] - testVector[2]);
	auto s1x = boost::numeric_cast<int64_t>(vector1[0] + testVector[0]);
	auto d1x = boost::numeric_cast<int64_t>(vector1[0] - testVector[0]);
	auto s1y = boost::numeric_cast<int64_t>(vector1[1] + testVector[1]);
	auto d1y = boost::numeric_cast<int64_t>(vector1[1] - testVector[1]);
	auto s1z = boost::numeric_cast<int64_t>(vector1[2] + testVector[2]);
	auto d1z = boost::numeric_cast<int64_t>(vector1[2] - testVector[2]);
	auto s2x = boost::numeric_cast<int64_t>(vector2[0] + testVector[0]);
	auto d2x = boost::numeric_cast<int64_t>(vector2[0] - testVector[0]);
	auto s2y = boost::numeric_cast<int64_t>(vector2[1] + testVector[1]);
	auto d2y = boost::numeric_cast<int64_t>(vector2[1] - testVector[1]);
	auto s2z = boost::numeric_cast<int64_t>(vector2[2] + testVector[2]);
	auto d2z = boost::numeric_cast<int64_t>(vector2[2] - testVector[2]);
	auto s3x = boost::numeric_cast<int64_t>(vector3[0] + testVector[0]);
	auto d3x = boost::numeric_cast<int64_t>(vector3[0] - testVector[0]);
	auto s3y = boost::numeric_cast<int64_t>(vector3[1] + testVector[1]);
	auto d3y = boost::numeric_cast<int64_t>(vector3[1] - testVector[1]);
	auto s3z = boost::numeric_cast<int64_t>(vector3[2] + testVector[2]);
	auto d3z = boost::numeric_cast<int64_t>(vector3[2] - testVector[2]);
	auto w0 = s0x * d0x + s0y * d0y + s0z * d0z;
	auto w1 = s1x * d1x + s1y * d1y + s1z * d1z;
	auto w2 = s2x * d2x + s2y * d2y + s2z * d2z;
	auto w3 = s3x * d3x + s3y * d3y + s3z * d3z;

	auto det = QueryDotTools<int64_t>::Det4(d0x, d0y, d0z, w0, d1x, d1y, d1z, w1, d2x, d2y, d2z, w2, d3x, d3y, d3z, w3);

	if (0 < det)
		return CircumsphereQueryType::Outside;
	else if (det < 0)
		return CircumsphereQueryType::Inside;
	else
		return CircumsphereQueryType::OnCircumsphere;
}

#endif // MATHEMATICS_QUERY_QUERY3_INT64_DETAIL_H

// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 10:09)

#ifndef MATHEMATICS_QUERY_QUERY2_INT64_DETAIL_H
#define MATHEMATICS_QUERY_QUERY2_INT64_DETAIL_H
 
#include "Query2Int64.h"
#include "QueryDotToolsDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <boost/numeric/conversion/cast.hpp>

template <typename Real>
Mathematics::Query2Int64<Real>
	::Query2Int64(const std::vector<Vector2D>& vertices)
	:ParentType{ vertices }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Query2Int64<Real>
	::~Query2Int64()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Query2Int64<Real>
	::IsValid() const noexcept
{
    if(ParentType::IsValid())
        return true;
    else
        return false;    
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::QueryType Mathematics::Query2Int64<Real>
	::GetType() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
    
	return QueryType::Int64;
}

template <typename Real>
Mathematics::LineQueryType Mathematics::Query2Int64<Real>
	::ToLine(int index, int lhsVerticesIndex, int rhsVerticesIndex) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	
	return ParentType::ToLine(index, lhsVerticesIndex, rhsVerticesIndex);
}

template <typename Real>
Mathematics::LineQueryType Mathematics::Query2Int64<Real>
	::ToLine(const Vector2D& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= lhsVerticesIndex && lhsVerticesIndex < GetNumVertices(), "À˜“˝¥ÌŒÛ£°");
	MATHEMATICS_ASSERTION_0(0 <= rhsVerticesIndex && rhsVerticesIndex < GetNumVertices(), "À˜“˝¥ÌŒÛ£°");

	const auto vector0 = GetVertice(lhsVerticesIndex);
	const auto vector1 = GetVertice(rhsVerticesIndex);
    
	int64_t x0{ boost::numeric_cast<int64_t>(testVector[0]) - boost::numeric_cast<int64_t>(vector0[0]) };
	int64_t y0{ boost::numeric_cast<int64_t>(testVector[1]) - boost::numeric_cast<int64_t>(vector0[1]) };
	int64_t x1{ boost::numeric_cast<int64_t>(vector1[0]) - boost::numeric_cast<int64_t>(vector0[0]) };
	int64_t y1{ boost::numeric_cast<int64_t>(vector1[1]) - boost::numeric_cast<int64_t>(vector0[1]) };
    
	auto det = QueryDotTools<int64_t>::Det2(x0, y0, x1, y1);

	if (0 < det)
		return LineQueryType::Right;
	else if (det < 0)
		return LineQueryType::Left;
	else
		return LineQueryType::OnLine;
}

template <typename Real>
Mathematics::CircumcircleQueryType Mathematics::Query2Int64<Real>
	::ToCircumcircle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	
	return ParentType::ToCircumcircle(index, lhsVerticesIndex, mhsVerticesIndex, rhsVerticesIndex);
}

template <typename Real>
Mathematics::CircumcircleQueryType Mathematics::Query2Int64<Real>
	::ToCircumcircle(const Vector2D& testVector, int lhsVerticesIndex,int mhsVerticesIndex, int rhsVerticesIndex) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= lhsVerticesIndex && lhsVerticesIndex < GetNumVertices(), "À˜“˝¥ÌŒÛ£°");
	MATHEMATICS_ASSERTION_0(0 <= mhsVerticesIndex && mhsVerticesIndex < GetNumVertices(), "À˜“˝¥ÌŒÛ£°");
	MATHEMATICS_ASSERTION_0(0 <= rhsVerticesIndex && rhsVerticesIndex < GetNumVertices(), "À˜“˝¥ÌŒÛ£°");

	const Vector2D lhsVector{ GetVertice(lhsVerticesIndex) };
	const Vector2D mhsVector{ GetVertice(mhsVerticesIndex) };
	const Vector2D rhsVector{ GetVertice(rhsVerticesIndex) };

	auto lhsPlusTestX = boost::numeric_cast<int64_t>(lhsVector[0] + testVector[0]);
	auto lhsMinusTestX = boost::numeric_cast<int64_t>(lhsVector[0] - testVector[0]);
	auto lhsPlusTestY = boost::numeric_cast<int64_t>(lhsVector[1] + testVector[1]);
	auto lhsMinusTestY = boost::numeric_cast<int64_t>(lhsVector[1] - testVector[1]);
	auto mhsPlusTestX = boost::numeric_cast<int64_t>(mhsVector[0] + testVector[0]);
	auto mhsMinusTestX = boost::numeric_cast<int64_t>(mhsVector[0] - testVector[0]);
	auto mhsPlusTestY = boost::numeric_cast<int64_t>(mhsVector[1] + testVector[1]);
	auto mhsMinusTestY = boost::numeric_cast<int64_t>(mhsVector[1] - testVector[1]);
	auto rhsPlusTestX = boost::numeric_cast<int64_t>(rhsVector[0] + testVector[0]);
	auto rhsMinusTestX = boost::numeric_cast<int64_t>(rhsVector[0] - testVector[0]);
	auto rhsPlusTestY = boost::numeric_cast<int64_t>(rhsVector[1] + testVector[1]);
	auto rhsMinusTestY = boost::numeric_cast<int64_t>(rhsVector[1] - testVector[1]);
	auto z0 = lhsPlusTestX * lhsMinusTestX + lhsPlusTestY * lhsMinusTestY;
	auto z1 = mhsPlusTestX * mhsMinusTestX + mhsPlusTestY * mhsMinusTestY;
	auto z2 = rhsPlusTestX * rhsMinusTestX + rhsPlusTestY * rhsMinusTestY;
    
	auto det = QueryDotTools<int64_t>::Det3(lhsMinusTestX, lhsMinusTestY, z0,mhsMinusTestX, mhsMinusTestY, z1,rhsMinusTestX, rhsMinusTestY, z2);
    
	if (0 < det)
		return CircumcircleQueryType::Inside;
	else if (det < 0)
		return CircumcircleQueryType::Outside;
	else
		return CircumcircleQueryType::OnCircumcircle;	
}

#endif // MATHEMATICS_QUERY_QUERY2_INT64_DETAIL_H
 
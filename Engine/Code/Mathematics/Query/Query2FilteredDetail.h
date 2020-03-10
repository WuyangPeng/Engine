// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 10:07)

#ifndef MATHEMATICS_QUERY_QUERY2_FILTERED_DETAIL_H
#define MATHEMATICS_QUERY_QUERY2_FILTERED_DETAIL_H

#include "Query2Filtered.h"
#include "Query2RationalDetail.h"
#include "QueryDotToolsDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h" 

template <typename Real>
Mathematics::Query2Filtered<Real>
	::Query2Filtered(const std::vector<Vector2D>& vertices, Real uncertainty)
	:ParentType{ vertices }, m_RationalQuery{ vertices }, m_Uncertainty{ uncertainty }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Query2Filtered<Real>
	::~Query2Filtered()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Query2Filtered<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && Real {} <= m_Uncertainty && m_Uncertainty <= static_cast<Real>(1))
        return true;
    else
        return false;    
}
#endif // OPEN_CLASS_INVARIANT


template <typename Real>
Mathematics::QueryType Mathematics::Query2Filtered<Real>
	::GetType() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    
	return QueryType::Filtered;
}

template <typename Real>
Mathematics::LineQueryType Mathematics::Query2Filtered<Real>
	::ToLine(int index, int lhsVerticesIndex, int rhsVerticesIndex) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	
	return ParentType::ToLine(index, lhsVerticesIndex, rhsVerticesIndex);
}

template <typename Real>
Mathematics::LineQueryType Mathematics::Query2Filtered<Real>
	::ToLine(const Vector2D& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= lhsVerticesIndex && lhsVerticesIndex < GetNumVertices(), "À˜“˝¥ÌŒÛ£°");
	MATHEMATICS_ASSERTION_0(0 <= rhsVerticesIndex && rhsVerticesIndex < GetNumVertices(), "À˜“˝¥ÌŒÛ£°");

	const auto vector0 = GetVertice(lhsVerticesIndex);
	const auto vector1 = GetVertice(rhsVerticesIndex);

	auto x0 = testVector[0] - vector0[0];
	auto y0 = testVector[1] - vector0[1];
	auto x1 = vector1[0] - vector0[0];
	auto y1 = vector1[1] - vector0[1];

	auto len0 = Math<Real>::Sqrt(x0 * x0 + y0 * y0);
	auto len1 = Math<Real>::Sqrt(x1 * x1 + y1 * y1);
	auto scaledUncertainty = m_Uncertainty * len0 * len1;

	auto det = QueryDotTools<Real>::Det2(x0, y0, x1, y1);

	if (scaledUncertainty <= Math<Real>::FAbs(det))
	{
		if (0 < det)
			return LineQueryType::Right;
		else if (det < 0)
			return LineQueryType::Left;
		else
			return LineQueryType::OnLine;
	}

	return m_RationalQuery.ToLine(testVector, lhsVerticesIndex, rhsVerticesIndex); 	
}

template <typename Real>
Mathematics::CircumcircleQueryType Mathematics::Query2Filtered<Real>
	::ToCircumcircle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	
	return ParentType::ToCircumcircle(index, lhsVerticesIndex, mhsVerticesIndex, rhsVerticesIndex);
}

template <typename Real>
Mathematics::CircumcircleQueryType Mathematics::Query2Filtered<Real>
	::ToCircumcircle(const Vector2D& testVector, int lhsVerticesIndex,int mhsVerticesIndex, int rhsVerticesIndex) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= lhsVerticesIndex && lhsVerticesIndex < GetNumVertices(), "À˜“˝¥ÌŒÛ£°");
	MATHEMATICS_ASSERTION_0(0 <= mhsVerticesIndex && mhsVerticesIndex < GetNumVertices(), "À˜“˝¥ÌŒÛ£°");
	MATHEMATICS_ASSERTION_0(0 <= rhsVerticesIndex && rhsVerticesIndex < GetNumVertices(), "À˜“˝¥ÌŒÛ£°");

	const Vector2D lhsVector{ GetVertice(lhsVerticesIndex) };
	const Vector2D mhsVector{ GetVertice(mhsVerticesIndex) };
	const Vector2D rhsVector{ GetVertice(rhsVerticesIndex) };

	auto lhsPlusTestX = lhsVector[0] + testVector[0];
	auto lhsMinusTestX = lhsVector[0] - testVector[0];
	auto lhsPlusTestY = lhsVector[1] + testVector[1];
	auto lhsMinusTestY = lhsVector[1] - testVector[1];
	auto mhsPlusTestX = mhsVector[0] + testVector[0];
	auto mhsMinusTestX = mhsVector[0] - testVector[0];
	auto mhsPlusTestY = mhsVector[1] + testVector[1];
	auto mhsMinusTestY = mhsVector[1] - testVector[1];
	auto rhsPlusTestX = rhsVector[0] + testVector[0];
	auto rhsMinusTestX = rhsVector[0] - testVector[0];
	auto rhsPlusTestY = rhsVector[1] + testVector[1];
	auto rhsMinusTestY = rhsVector[1] - testVector[1];
	auto z0 = lhsPlusTestX * lhsMinusTestX + lhsPlusTestY * lhsMinusTestY;
	auto z1 = mhsPlusTestX * mhsMinusTestX + mhsPlusTestY * mhsMinusTestY;
	auto z2 = rhsPlusTestX * rhsMinusTestX + rhsPlusTestY * rhsMinusTestY;

	auto len0 = Math<Real>::Sqrt(lhsMinusTestX * lhsMinusTestX + lhsMinusTestY * lhsMinusTestY + z0 * z0);
	auto len1 = Math<Real>::Sqrt(mhsMinusTestX * mhsMinusTestX + mhsMinusTestY * mhsMinusTestY + z1 * z1);
	auto len2 = Math<Real>::Sqrt(rhsMinusTestX * rhsMinusTestX + rhsMinusTestY * rhsMinusTestY + z2 * z2);
	auto scaledUncertainty = m_Uncertainty * len0 * len1 * len2;
    
	auto det = QueryDotTools<Real>::Det3(lhsMinusTestX, lhsMinusTestY, z0, mhsMinusTestX, mhsMinusTestY, z1, rhsMinusTestX, rhsMinusTestY, z2);
	if (scaledUncertainty <= Math<Real>::FAbs(det))
	{
		if (0 < det)
			return CircumcircleQueryType::Inside;
		else if (det < 0)
			return CircumcircleQueryType::Outside;
		else
			return CircumcircleQueryType::OnCircumcircle;
	}

	return m_RationalQuery.ToCircumcircle(testVector, lhsVerticesIndex, mhsVerticesIndex, rhsVerticesIndex);
}


#endif // MATHEMATICS_QUERY_QUERY2_FILTERED_DETAIL_H
 
// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.5 (2020/03/23 09:59)

#ifndef MATHEMATICS_QUERY_QUERY2_INTEGER_DETAIL_H
#define MATHEMATICS_QUERY_QUERY2_INTEGER_DETAIL_H

#include "Query2Integer.h"
#include "QueryDotToolsDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Rational/IntegerDetail.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

template <typename Real>
Mathematics::Query2Integer<Real>
	::Query2Integer(const std::vector<Vector2D>& vertices)
	:ParentType{ vertices }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Query2Integer<Real>
	::~Query2Integer()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Query2Integer<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::QueryType Mathematics::Query2Integer<Real>
	::GetType() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return QueryType::Interger;
}

template <typename Real>
Mathematics::LineQueryType Mathematics::Query2Integer<Real>
	::ToLine(const Vector2D& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= lhsVerticesIndex && lhsVerticesIndex < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= rhsVerticesIndex && rhsVerticesIndex < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");

	const auto vector0 = this->GetVertice(lhsVerticesIndex);
	const auto vector1 = this->GetVertice(rhsVerticesIndex);

	Integer<2> x0{ boost::numeric_cast<int>(testVector[0]) - boost::numeric_cast<int>(vector0[0]) };
	Integer<2> y0{ boost::numeric_cast<int>(testVector[1]) - boost::numeric_cast<int>(vector0[1]) };
	Integer<2> x1{ boost::numeric_cast<int>(vector1[0]) - boost::numeric_cast<int>(vector0[0]) };
	Integer<2> y1{ boost::numeric_cast<int>(vector1[1]) - boost::numeric_cast<int>(vector0[1]) };

	auto det = QueryDotTools<Integer<2> >::Det2(x0, y0, x1, y1);

	if (Integer<2>{ 0 } < det)
		return LineQueryType::Right;
	else if (det < Integer<2>{ 0 })
		return LineQueryType::Left;
	else
		return LineQueryType::OnLine;
}

template <typename Real>
Mathematics::LineQueryType Mathematics::Query2Integer<Real>
	::ToLine(int index, int lhsVerticesIndex, int rhsVerticesIndex) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return ParentType::ToLine(index, lhsVerticesIndex, rhsVerticesIndex);
}

template <typename Real>
Mathematics::CircumcircleQueryType Mathematics::Query2Integer<Real>
	::ToCircumcircle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return ParentType::ToCircumcircle(index, lhsVerticesIndex, mhsVerticesIndex, rhsVerticesIndex);
}

template <typename Real>
Mathematics::CircumcircleQueryType	Mathematics::Query2Integer<Real>
	::ToCircumcircle(const Vector2D& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= lhsVerticesIndex && lhsVerticesIndex < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= mhsVerticesIndex && mhsVerticesIndex < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= rhsVerticesIndex && rhsVerticesIndex < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");

	const Vector2D lhsVector{ this->GetVertice(lhsVerticesIndex) };
	const Vector2D mhsVector{ this->GetVertice(mhsVerticesIndex) };
	const Vector2D rhsVector{ this->GetVertice(rhsVerticesIndex) };

	Integer<4> lhsPlusTestX{ lhsVector[0] + testVector[0] };
	Integer<4> lhsMinusTestX{ lhsVector[0] - testVector[0] };
	Integer<4> lhsPlusTestY{ lhsVector[1] + testVector[1] };
	Integer<4> lhsMinusTestY{ lhsVector[1] - testVector[1] };
	Integer<4> mhsPlusTestX{ mhsVector[0] + testVector[0] };
	Integer<4> mhsMinusTestX{ mhsVector[0] - testVector[0] };
	Integer<4> mhsPlusTestY{ mhsVector[1] + testVector[1] };
	Integer<4> mhsMinusTestY{ mhsVector[1] - testVector[1] };
	Integer<4> rhsPlusTestX{ rhsVector[0] + testVector[0] };
	Integer<4> rhsMinusTestX{ rhsVector[0] - testVector[0] };
	Integer<4> rhsPlusTestY{ rhsVector[1] + testVector[1] };
	Integer<4> rhsMinusTestY{ rhsVector[1] - testVector[1] };
	auto z0 = lhsPlusTestX * lhsMinusTestX + lhsPlusTestY * lhsMinusTestY;
	auto z1 = mhsPlusTestX * mhsMinusTestX + mhsPlusTestY * mhsMinusTestY;
	auto z2 = rhsPlusTestX * rhsMinusTestX + rhsPlusTestY * rhsMinusTestY;

	auto det = QueryDotTools<Integer<4>>::Det3(lhsMinusTestX, lhsMinusTestY, z0, mhsMinusTestX, mhsMinusTestY, z1, rhsMinusTestX, rhsMinusTestY, z2);

	if (Integer<4>{ 0 } < det)
		return CircumcircleQueryType::Inside;
	else if (det < Integer<4>{ 0 })
		return CircumcircleQueryType::Outside;
	else
		return CircumcircleQueryType::OnCircumcircle;
}

#endif // MATHEMATICS_QUERY_QUERY2_INTEGER_DETAIL_H

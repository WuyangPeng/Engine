// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.2 (2019/07/10 10:17)

#ifndef MATHEMATICS_QUERY_QUERY2_RATIONAL_DETAIL_H
#define MATHEMATICS_QUERY_QUERY2_RATIONAL_DETAIL_H 

#include "Query2Rational.h"
#include "QueryDotToolsDetail.h"
#include "Mathematics/Rational/SignRationalDetail.h"
#include "Mathematics/Rational/RationalVector2Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <boost/numeric/conversion/cast.hpp>

template <typename Real>
Mathematics::Query2Rational<Real>
	::Query2Rational(const std::vector<Vector2D>& vertices)
	:ParentType{ vertices }, m_RationalVertices{}
{
	Convert();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::Query2Rational<Real>
	::Convert()
{
	auto  numVertices = GetNumVertices();

	for (auto index = 0; index < numVertices; ++index)
	{
		const auto vertice = GetVertice(index);

		QueryRational firstRational{ vertice[0] };
		QueryRational secondRational{ vertice[1] }; 

		m_RationalVertices.emplace_back(firstRational, secondRational);
	}		
}

template <typename Real>
Mathematics::Query2Rational<Real>
	::~Query2Rational()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Query2Rational<Real>
	::IsValid() const noexcept
{
    if(ParentType::IsValid())
        return true;
    else
        return false;    
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::QueryType Mathematics::Query2Rational<Real>
	::GetType() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    
	return QueryType::Rational;
}

template <typename Real>
Mathematics::LineQueryType Mathematics::Query2Rational<Real>
	::ToLine(int index, int lhsVerticesIndex, int rhsVerticesIndex) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_RationalVertices.size()), "Ë÷Òý´íÎó£¡");

	return ToLine(m_RationalVertices[index], lhsVerticesIndex, rhsVerticesIndex);
}

template <typename Real>
Mathematics::LineQueryType Mathematics::Query2Rational<Real>
	::ToLine(const Vector2D& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1; 

	QueryRational firstRational{ testVector[0] };
	QueryRational secondRational{ testVector[1] };

	QueryRationalVector queryRationalVector{ firstRational, secondRational };

	return ToLine(queryRationalVector, lhsVerticesIndex, rhsVerticesIndex);
}


template <typename Real>
Mathematics::LineQueryType Mathematics::Query2Rational<Real>
	::ToLine(const QueryRationalVector& rationalTest, int lhsVerticesIndex, int rhsVerticesIndex) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= lhsVerticesIndex && lhsVerticesIndex < GetNumVertices(), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= rhsVerticesIndex && rhsVerticesIndex < GetNumVertices(), "Ë÷Òý´íÎó£¡");

	auto x0 = rationalTest.GetX() - m_RationalVertices[lhsVerticesIndex].GetX();
	auto y0 = rationalTest.GetY() - m_RationalVertices[lhsVerticesIndex].GetY();
	auto x1 = m_RationalVertices[rhsVerticesIndex].GetX() - m_RationalVertices[lhsVerticesIndex].GetX();
	auto y1 = m_RationalVertices[rhsVerticesIndex].GetY() - m_RationalVertices[lhsVerticesIndex].GetY();

	auto det = QueryDotTools<QueryRational>::Det2(x0, y0, x1, y1);

	if (QueryRational{ 0 } < det)
		return LineQueryType::Right;
	else if (det < QueryRational{ 0 })
		return LineQueryType::Left;
	else
		return LineQueryType::OnLine;
}

template <typename Real>
Mathematics::TriangleQueryType Mathematics::Query2Rational<Real>
	::ToTriangle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_RationalVertices.size()), "Ë÷Òý´íÎó£¡");

	return ToTriangle(m_RationalVertices[index], lhsVerticesIndex, mhsVerticesIndex, rhsVerticesIndex);
}

template <typename Real>
Mathematics::TriangleQueryType Mathematics::Query2Rational<Real>
	::ToTriangle(const Vector2D& testVector, int lhsVerticesIndex,int mhsVerticesIndex, int rhsVerticesIndex) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1; 

	QueryRational firstRational{ testVector[0] };
	QueryRational secondRational{ testVector[1] };

	QueryRationalVector queryRationalVector{ firstRational, secondRational };

	return ToTriangle(queryRationalVector, lhsVerticesIndex, mhsVerticesIndex, rhsVerticesIndex);
}


template <typename Real>
Mathematics::TriangleQueryType Mathematics::Query2Rational<Real>
	::ToTriangle(const QueryRationalVector& rationalTest, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= lhsVerticesIndex && lhsVerticesIndex < GetNumVertices(), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= mhsVerticesIndex && mhsVerticesIndex < GetNumVertices(), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= rhsVerticesIndex && rhsVerticesIndex < GetNumVertices(), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_3(ToLine(lhsVerticesIndex, mhsVerticesIndex, rhsVerticesIndex) != LineQueryType::Right, "Èý½ÇÐÎ¶¥µã²»ÊÇÄæÊ±ÕëË³Ðò£¡");

	auto sign0 = ToLine(rationalTest, mhsVerticesIndex, rhsVerticesIndex);
	if (sign0 == LineQueryType::Right)
	{
		return TriangleQueryType::Outside;
	}

	auto sign1 = ToLine(rationalTest, lhsVerticesIndex, rhsVerticesIndex);
	if (sign1 == LineQueryType::Left)
	{
		return TriangleQueryType::Outside;
	}

	auto sign2 = ToLine(rationalTest, lhsVerticesIndex, mhsVerticesIndex);
	if (sign2 == LineQueryType::Right)
	{
		return TriangleQueryType::Outside;
	}

	if (sign0 == LineQueryType::OnLine || sign1 == LineQueryType::OnLine || sign2 == LineQueryType::OnLine)
	{
		return  TriangleQueryType::OnTriangle;
	}
	else
	{
		return  TriangleQueryType::Inside;
	}
}


template <typename Real>
Mathematics::CircumcircleQueryType Mathematics::Query2Rational<Real>
	::ToCircumcircle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_RationalVertices.size()), "Ë÷Òý´íÎó£¡");

	return ToCircumcircle(m_RationalVertices[index], lhsVerticesIndex, mhsVerticesIndex, rhsVerticesIndex);
}


template <typename Real>
Mathematics::CircumcircleQueryType Mathematics::Query2Rational<Real>
	::ToCircumcircle(const Vector2D& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1; 

	QueryRational firstRational{ testVector[0] };
	QueryRational secondRational{ testVector[1] };

	QueryRationalVector queryRationalVector{ firstRational, secondRational };

	return ToCircumcircle(queryRationalVector, lhsVerticesIndex, mhsVerticesIndex, rhsVerticesIndex);

}

template <typename Real>
Mathematics::CircumcircleQueryType Mathematics::Query2Rational<Real>
	::ToCircumcircle(const QueryRationalVector& rationalTest, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= lhsVerticesIndex && lhsVerticesIndex < GetNumVertices(), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= mhsVerticesIndex && mhsVerticesIndex < GetNumVertices(), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= rhsVerticesIndex && rhsVerticesIndex < GetNumVertices(), "Ë÷Òý´íÎó£¡");

	const auto& lhsVector = m_RationalVertices[lhsVerticesIndex];
	const auto& mhsVector = m_RationalVertices[mhsVerticesIndex];
	const auto& rhsVector = m_RationalVertices[rhsVerticesIndex];

	auto lhsPlusTestX = lhsVector.GetX() + rationalTest.GetX();
	auto lhsMinusTestX = lhsVector.GetX() - rationalTest.GetX();
	auto lhsPlusTestY = lhsVector.GetY() + rationalTest.GetY();
	auto lhsMinusTestY = lhsVector.GetY() - rationalTest.GetY();
	auto mhsPlusTestX = mhsVector.GetX() + rationalTest.GetX();
	auto mhsMinusTestX = mhsVector.GetX() - rationalTest.GetX();
	auto mhsPlusTestY = mhsVector.GetY() + rationalTest.GetY();
	auto mhsMinusTestY = mhsVector.GetY() - rationalTest.GetY();
	auto rhsPlusTestX = rhsVector.GetX() + rationalTest.GetX();
	auto rhsMinusTestX = rhsVector.GetX() - rationalTest.GetX();
	auto rhsPlusTestY = rhsVector.GetY() + rationalTest.GetY();
	auto rhsMinusTestY = rhsVector.GetY() - rationalTest.GetY();
	auto z0 = lhsPlusTestX * lhsMinusTestX + lhsPlusTestY * lhsMinusTestY;
	auto z1 = mhsPlusTestX * mhsMinusTestX + mhsPlusTestY * mhsMinusTestY;
	auto z2 = rhsPlusTestX * rhsMinusTestX + rhsPlusTestY * rhsMinusTestY;
    
	auto det = QueryDotTools<QueryRational>::Det3(lhsMinusTestX, lhsMinusTestY, z0,mhsMinusTestX, mhsMinusTestY, z1, rhsMinusTestX, rhsMinusTestY, z2);
    
	if (QueryRational{ 0 } < det)
		return CircumcircleQueryType::Inside;
	else if (det < QueryRational{ 0 })
		return CircumcircleQueryType::Outside;
	else
		return CircumcircleQueryType::OnCircumcircle;	
}

#endif // MATHEMATICS_QUERY_QUERY2_RATIONAL_DETAIL_H

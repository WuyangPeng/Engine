// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.2 (2019/07/10 10:03)

#ifndef MATHEMATICS_QUERY_QUERY2_DETAIL_H
#define MATHEMATICS_QUERY_QUERY2_DETAIL_H

#include "Query2.h"
#include "QuerySortTools.h"
#include "QueryDotToolsDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <boost/numeric/conversion/cast.hpp>

template <typename Real>
Mathematics::Query2<Real>
	::Query2 (const std::vector<Vector2D>& vertices)
	:ParentType{}, m_Vertices{ vertices }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Query2<Real>
	::~Query2 ()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Query2<Real>
	::IsValid() const noexcept
{
    if(!m_Vertices.empty())
        return true;
    else
        return false;    
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::QueryType Mathematics::Query2<Real>
	::GetType () const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    
    return QueryType::Real;    
}

template <typename Real>
int Mathematics::Query2<Real>
	::GetNumVertices () const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    
    return boost::numeric_cast<int>(m_Vertices.size());
}

template <typename Real>
typename const Mathematics::Query2<Real>::Vector2D Mathematics::Query2<Real>
	::GetVertice (int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(0 <= index && index < static_cast<int>(m_Vertices.size()), "Ë÷Òý´íÎó£¡");
    
    return m_Vertices[index];
}

template <typename Real>
Mathematics::LineQueryType Mathematics::Query2<Real>
	::ToLine(int index, int lhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_Vertices.size()), "Ë÷Òý´íÎó£¡");
    
	return ToLine(m_Vertices[index], lhsVerticesIndex, rhsVerticesIndex);
}

template <typename Real>
Mathematics::LineQueryType Mathematics::Query2<Real>
	::ToLine(const Vector2D& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= lhsVerticesIndex && lhsVerticesIndex < boost::numeric_cast<int>(m_Vertices.size()), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= rhsVerticesIndex && rhsVerticesIndex < boost::numeric_cast<int>(m_Vertices.size()), "Ë÷Òý´íÎó£¡");
	    
	QuerySortTools querySortTools{ lhsVerticesIndex, rhsVerticesIndex };
    
	const auto& vector0 = m_Vertices[querySortTools.GetValue(0)];
	const auto& vector1 = m_Vertices[querySortTools.GetValue(1)];
    
	auto x0 = testVector[0] - vector0[0];
	auto y0 = testVector[1] - vector0[1];
	auto x1 = vector1[0] - vector0[0];
	auto y1 = vector1[1] - vector0[1];
    
	auto det = QueryDotTools<Real>::Det2(x0, y0, x1, y1);

	auto positive = querySortTools.GetSymbol();
    if (positive == NumericalValueSymbol::Negative)
    {
        det = -det;
    }
    
    if(Math<Real>::FAbs(det) <= Math<Real>::sm_ZeroTolerance)
        return LineQueryType::OnLine;
	else if (Real{} < det)
        return LineQueryType::Right;
    else
        return LineQueryType::Left; 
}

template <typename Real>
Mathematics::TriangleQueryType Mathematics::Query2<Real>
	::ToTriangle(int index, int lhsVerticesIndex,int mhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_Vertices.size()), "Ë÷Òý´íÎó£¡");
    
	return ToTriangle(m_Vertices[index], lhsVerticesIndex, mhsVerticesIndex, rhsVerticesIndex);
}

template <typename Real>
Mathematics::TriangleQueryType Mathematics::Query2<Real>
	::ToTriangle (const Vector2D& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_3(ToLine(lhsVerticesIndex,mhsVerticesIndex,rhsVerticesIndex) != LineQueryType::Right,"Èý½ÇÐÎ¶¥µã²»ÊÇÄæÊ±ÕëË³Ðò£¡");

	auto sign0 = ToLine(testVector, mhsVerticesIndex, rhsVerticesIndex);
    if (sign0 == LineQueryType::Right)
    {
        return TriangleQueryType::Outside;
    }
    
	auto sign1 = ToLine(testVector, lhsVerticesIndex, rhsVerticesIndex);
    if (sign1 == LineQueryType::Left)
    {
        return TriangleQueryType::Outside;
    }
    
	auto sign2 = ToLine(testVector, lhsVerticesIndex, mhsVerticesIndex);
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
Mathematics::CircumcircleQueryType Mathematics::Query2<Real>
	::ToCircumcircle (int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_Vertices.size()), "Ë÷Òý´íÎó£¡");
    
	return ToCircumcircle(m_Vertices[index], lhsVerticesIndex, mhsVerticesIndex, rhsVerticesIndex);
}

template <typename Real>
Mathematics::CircumcircleQueryType Mathematics::Query2<Real>
	::ToCircumcircle(const Vector2D& testVector, int lhsVerticesIndex,int mhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= lhsVerticesIndex && lhsVerticesIndex < boost::numeric_cast<int>(m_Vertices.size()), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= mhsVerticesIndex && mhsVerticesIndex < boost::numeric_cast<int>(m_Vertices.size()), "Ë÷Òý´íÎó£¡");
	MATHEMATICS_ASSERTION_0(0 <= rhsVerticesIndex && rhsVerticesIndex < boost::numeric_cast<int>(m_Vertices.size()), "Ë÷Òý´íÎó£¡");
	    
	QuerySortTools querySortTools{ lhsVerticesIndex, mhsVerticesIndex, rhsVerticesIndex };
    
	const auto& lhsVector = m_Vertices[querySortTools.GetValue(0)];
	const auto& mhsVector = m_Vertices[querySortTools.GetValue(1)];
	const auto& rhsVector = m_Vertices[querySortTools.GetValue(2)];
    
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
    
	auto det = QueryDotTools<Real>::Det3(lhsMinusTestX, lhsMinusTestY, z0, mhsMinusTestX, mhsMinusTestY, z1, rhsMinusTestX, rhsMinusTestY, z2);
    
	auto positive = querySortTools.GetSymbol();
    if (positive == NumericalValueSymbol::Negative)
    {
        det = -det;
    }
    
    if(Math<Real>::FAbs(det) <= Math<Real>::sm_ZeroTolerance)
        return CircumcircleQueryType::OnCircumcircle;
	else if (det < Real{})
        return CircumcircleQueryType::Outside;
    else
        return CircumcircleQueryType::Inside;
}

#endif // MATHEMATICS_QUERY_QUERY2_DETAIL_H

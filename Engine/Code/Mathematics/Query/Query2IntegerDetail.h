/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
/// ÁªÏµ×÷Õß£º94458936@qq.com
///
/// ±ê×¼£ºstd:c++20
/// °æ±¾£º1.0.0.4 (2024/01/11 23:32)

#ifndef MATHEMATICS_QUERY_QUERY2_INTEGER_DETAIL_H
#define MATHEMATICS_QUERY_QUERY2_INTEGER_DETAIL_H

#include "Query2Integer.h"
#include "QueryDotToolsDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Rational/IntegerDetail.h"

template <typename Real>
Mathematics::Query2Integer<Real>::Query2Integer(const VerticesType& vertices)
    : ParentType{ vertices }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Query2Integer<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::QueryType Mathematics::Query2Integer<Real>::GetType() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return QueryType::Integer;
}

template <typename Real>
Mathematics::LineQueryType Mathematics::Query2Integer<Real>::ToLine(const Vector2& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(0 <= lhsVerticesIndex && lhsVerticesIndex < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");
    MATHEMATICS_ASSERTION_0(0 <= rhsVerticesIndex && rhsVerticesIndex < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");

    const auto vector0 = this->GetVertex(lhsVerticesIndex);
    const auto vector1 = this->GetVertex(rhsVerticesIndex);

    const Integer<2> x0{ boost::numeric_cast<int>(testVector.GetX()) - boost::numeric_cast<int>(vector0.GetX()) };
    const Integer<2> y0{ boost::numeric_cast<int>(testVector.GetY()) - boost::numeric_cast<int>(vector0.GetY()) };
    const Integer<2> x1{ boost::numeric_cast<int>(vector1.GetX()) - boost::numeric_cast<int>(vector0.GetX()) };
    const Integer<2> y1{ boost::numeric_cast<int>(vector1.GetY()) - boost::numeric_cast<int>(vector0.GetY()) };

    if (const auto det = QueryDotTools<Integer<2>>::Det2(x0, y0, x1, y1);
        Integer<2>{ 0 } < det)
        return LineQueryType::Right;
    else if (det < Integer<2>{ 0 })
        return LineQueryType::Left;
    else
        return LineQueryType::OnLine;
}

template <typename Real>
Mathematics::LineQueryType Mathematics::Query2Integer<Real>::ToLine(int index, int lhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ParentType::ToLine(index, lhsVerticesIndex, rhsVerticesIndex);
}

template <typename Real>
Mathematics::CircumcircleQueryType Mathematics::Query2Integer<Real>::ToCircumcircle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ParentType::ToCircumcircle(index, lhsVerticesIndex, mhsVerticesIndex, rhsVerticesIndex);
}

template <typename Real>
Mathematics::CircumcircleQueryType Mathematics::Query2Integer<Real>::ToCircumcircle(const Vector2& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(0 <= lhsVerticesIndex && lhsVerticesIndex < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");
    MATHEMATICS_ASSERTION_0(0 <= mhsVerticesIndex && mhsVerticesIndex < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");
    MATHEMATICS_ASSERTION_0(0 <= rhsVerticesIndex && rhsVerticesIndex < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");

    const Vector2 lhsVector{ this->GetVertex(lhsVerticesIndex) };
    const Vector2 mhsVector{ this->GetVertex(mhsVerticesIndex) };
    const Vector2 rhsVector{ this->GetVertex(rhsVerticesIndex) };

    const Integer<4> lhsPlusTestX{ lhsVector.GetX() + testVector.GetX() };
    const Integer<4> lhsMinusTestX{ lhsVector.GetX() - testVector.GetX() };
    const Integer<4> lhsPlusTestY{ lhsVector.GetY() + testVector.GetY() };
    const Integer<4> lhsMinusTestY{ lhsVector.GetY() - testVector.GetY() };
    const Integer<4> mhsPlusTestX{ mhsVector.GetX() + testVector.GetX() };
    const Integer<4> mhsMinusTestX{ mhsVector.GetX() - testVector.GetX() };
    const Integer<4> mhsPlusTestY{ mhsVector.GetY() + testVector.GetY() };
    const Integer<4> mhsMinusTestY{ mhsVector.GetY() - testVector.GetY() };
    const Integer<4> rhsPlusTestX{ rhsVector.GetX() + testVector.GetX() };
    const Integer<4> rhsMinusTestX{ rhsVector.GetX() - testVector.GetX() };
    const Integer<4> rhsPlusTestY{ rhsVector.GetY() + testVector.GetY() };
    const Integer<4> rhsMinusTestY{ rhsVector.GetY() - testVector.GetY() };
    const auto z0 = lhsPlusTestX * lhsMinusTestX + lhsPlusTestY * lhsMinusTestY;
    const auto z1 = mhsPlusTestX * mhsMinusTestX + mhsPlusTestY * mhsMinusTestY;
    const auto z2 = rhsPlusTestX * rhsMinusTestX + rhsPlusTestY * rhsMinusTestY;

    if (const auto det = QueryDotTools<Integer<4>>::Det3(lhsMinusTestX, lhsMinusTestY, z0, mhsMinusTestX, mhsMinusTestY, z1, rhsMinusTestX, rhsMinusTestY, z2);
        Integer<4>{ 0 } < det)
        return CircumcircleQueryType::Inside;
    else if (det < Integer<4>{ 0 })
        return CircumcircleQueryType::Outside;
    else
        return CircumcircleQueryType::OnCircumcircle;
}

#endif  // MATHEMATICS_QUERY_QUERY2_INTEGER_DETAIL_H

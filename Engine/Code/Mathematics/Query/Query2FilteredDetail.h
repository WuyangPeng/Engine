/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
/// ÁªÏµ×÷Õß£º94458936@qq.com
///
/// ±ê×¼£ºstd:c++20
/// °æ±¾£º1.0.0.4 (2024/01/11 23:32)

#ifndef MATHEMATICS_QUERY_QUERY2_FILTERED_DETAIL_H
#define MATHEMATICS_QUERY_QUERY2_FILTERED_DETAIL_H

#include "Query2Filtered.h"
#include "Query2RationalDetail.h"
#include "QueryDotToolsDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Rational/RationalVectorDetail.h"

template <typename Real>
Mathematics::Query2Filtered<Real>::Query2Filtered(const VerticesType& vertices, Real uncertainty)
    : ParentType{ vertices }, rationalQuery{ vertices }, uncertainty{ uncertainty }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Query2Filtered<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && MathType::GetValue(0) <= uncertainty && uncertainty <= MathType::GetValue(1))
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::QueryType Mathematics::Query2Filtered<Real>::GetType() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return QueryType::Filtered;
}

template <typename Real>
Mathematics::LineQueryType Mathematics::Query2Filtered<Real>::ToLine(int index, int lhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ParentType::ToLine(index, lhsVerticesIndex, rhsVerticesIndex);
}

template <typename Real>
Mathematics::LineQueryType Mathematics::Query2Filtered<Real>::ToLine(const Vector2& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(0 <= lhsVerticesIndex && lhsVerticesIndex < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");
    MATHEMATICS_ASSERTION_0(0 <= rhsVerticesIndex && rhsVerticesIndex < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");

    const auto vector0 = this->GetVertex(lhsVerticesIndex);
    const auto vector1 = this->GetVertex(rhsVerticesIndex);

    const auto x0 = testVector.GetX() - vector0.GetX();
    const auto y0 = testVector.GetY() - vector0.GetY();
    const auto x1 = vector1.GetX() - vector0.GetX();
    const auto y1 = vector1.GetY() - vector0.GetY();

    const auto len0 = MathType::Sqrt(x0 * x0 + y0 * y0);
    const auto len1 = MathType::Sqrt(x1 * x1 + y1 * y1);
    const auto scaledUncertainty = uncertainty * len0 * len1;

    const auto det = QueryDotTools<Real>::Det2(x0, y0, x1, y1);

    if (scaledUncertainty <= MathType::FAbs(det))
    {
        if (0 < det)
            return LineQueryType::Right;
        else if (det < 0)
            return LineQueryType::Left;
        else
            return LineQueryType::OnLine;
    }

    return rationalQuery.ToLine(testVector, lhsVerticesIndex, rhsVerticesIndex);
}

template <typename Real>
Mathematics::CircumcircleQueryType Mathematics::Query2Filtered<Real>::ToCircumcircle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ParentType::ToCircumcircle(index, lhsVerticesIndex, mhsVerticesIndex, rhsVerticesIndex);
}

template <typename Real>
Mathematics::CircumcircleQueryType Mathematics::Query2Filtered<Real>::ToCircumcircle(const Vector2& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(0 <= lhsVerticesIndex && lhsVerticesIndex < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");
    MATHEMATICS_ASSERTION_0(0 <= mhsVerticesIndex && mhsVerticesIndex < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");
    MATHEMATICS_ASSERTION_0(0 <= rhsVerticesIndex && rhsVerticesIndex < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");

    const Vector2 lhsVector{ this->GetVertex(lhsVerticesIndex) };
    const Vector2 mhsVector{ this->GetVertex(mhsVerticesIndex) };
    const Vector2 rhsVector{ this->GetVertex(rhsVerticesIndex) };

    const auto lhsPlusTestX = lhsVector.GetX() + testVector.GetX();
    const auto lhsMinusTestX = lhsVector.GetX() - testVector.GetX();
    const auto lhsPlusTestY = lhsVector.GetY() + testVector.GetY();
    const auto lhsMinusTestY = lhsVector.GetY() - testVector.GetY();
    const auto mhsPlusTestX = mhsVector.GetX() + testVector.GetX();
    const auto mhsMinusTestX = mhsVector.GetX() - testVector.GetX();
    const auto mhsPlusTestY = mhsVector.GetY() + testVector.GetY();
    const auto mhsMinusTestY = mhsVector.GetY() - testVector.GetY();
    const auto rhsPlusTestX = rhsVector.GetX() + testVector.GetX();
    const auto rhsMinusTestX = rhsVector.GetX() - testVector.GetX();
    const auto rhsPlusTestY = rhsVector.GetY() + testVector.GetY();
    const auto rhsMinusTestY = rhsVector.GetY() - testVector.GetY();
    const auto z0 = lhsPlusTestX * lhsMinusTestX + lhsPlusTestY * lhsMinusTestY;
    const auto z1 = mhsPlusTestX * mhsMinusTestX + mhsPlusTestY * mhsMinusTestY;
    const auto z2 = rhsPlusTestX * rhsMinusTestX + rhsPlusTestY * rhsMinusTestY;

    const auto len0 = MathType::Sqrt(lhsMinusTestX * lhsMinusTestX + lhsMinusTestY * lhsMinusTestY + z0 * z0);
    const auto len1 = MathType::Sqrt(mhsMinusTestX * mhsMinusTestX + mhsMinusTestY * mhsMinusTestY + z1 * z1);
    const auto len2 = MathType::Sqrt(rhsMinusTestX * rhsMinusTestX + rhsMinusTestY * rhsMinusTestY + z2 * z2);
    const auto scaledUncertainty = uncertainty * len0 * len1 * len2;

    const auto det = QueryDotTools<Real>::Det3(lhsMinusTestX, lhsMinusTestY, z0, mhsMinusTestX, mhsMinusTestY, z1, rhsMinusTestX, rhsMinusTestY, z2);
    if (scaledUncertainty <= MathType::FAbs(det))
    {
        if (0 < det)
            return CircumcircleQueryType::Inside;
        else if (det < 0)
            return CircumcircleQueryType::Outside;
        else
            return CircumcircleQueryType::OnCircumcircle;
    }

    return rationalQuery.ToCircumcircle(testVector, lhsVerticesIndex, mhsVerticesIndex, rhsVerticesIndex);
}

#endif  // MATHEMATICS_QUERY_QUERY2_FILTERED_DETAIL_H

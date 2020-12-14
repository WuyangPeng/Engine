///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
///	ÁªÏµ×÷Õß£º94458936@qq.com
///
///	±ê×¼£ºstd:c++17
///	ÒýÇæ°æ±¾£º0.5.2.5 (2020/11/30 14:37)

#ifndef MATHEMATICS_QUERY_QUERY2_FILTERED_DETAIL_H
#define MATHEMATICS_QUERY_QUERY2_FILTERED_DETAIL_H

#include "Query2Filtered.h"
#include "Query2RationalDetail.h"
#include "QueryDotToolsDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Rational/RationalVectorDetail.h"

template <typename Real>
Mathematics::Query2Filtered<Real>::Query2Filtered(const VerticesType& vertices, Real uncertainty)
    : ParentType{ vertices }, m_RationalQuery{ vertices }, m_Uncertainty{ uncertainty }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Query2Filtered<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && Math::GetValue(0) <= m_Uncertainty && m_Uncertainty <= Math::GetValue(1))
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
Mathematics::LineQueryType Mathematics::Query2Filtered<Real>::ToLine(const Vector2D& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(0 <= lhsVerticesIndex && lhsVerticesIndex < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");
    MATHEMATICS_ASSERTION_0(0 <= rhsVerticesIndex && rhsVerticesIndex < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");

    const auto vector0 = this->GetVertice(lhsVerticesIndex);
    const auto vector1 = this->GetVertice(rhsVerticesIndex);

    auto x0 = testVector.GetX() - vector0.GetX();
    auto y0 = testVector.GetY() - vector0.GetY();
    auto x1 = vector1.GetX() - vector0.GetX();
    auto y1 = vector1.GetY() - vector0.GetY();

    auto len0 = Math::Sqrt(x0 * x0 + y0 * y0);
    auto len1 = Math::Sqrt(x1 * x1 + y1 * y1);
    auto scaledUncertainty = m_Uncertainty * len0 * len1;

    auto det = QueryDotTools<Real>::Det2(x0, y0, x1, y1);

    if (scaledUncertainty <= Math::FAbs(det))
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
Mathematics::CircumcircleQueryType Mathematics::Query2Filtered<Real>::ToCircumcircle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ParentType::ToCircumcircle(index, lhsVerticesIndex, mhsVerticesIndex, rhsVerticesIndex);
}

template <typename Real>
Mathematics::CircumcircleQueryType Mathematics::Query2Filtered<Real>::ToCircumcircle(const Vector2D& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(0 <= lhsVerticesIndex && lhsVerticesIndex < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");
    MATHEMATICS_ASSERTION_0(0 <= mhsVerticesIndex && mhsVerticesIndex < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");
    MATHEMATICS_ASSERTION_0(0 <= rhsVerticesIndex && rhsVerticesIndex < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");

    const Vector2D lhsVector{ this->GetVertice(lhsVerticesIndex) };
    const Vector2D mhsVector{ this->GetVertice(mhsVerticesIndex) };
    const Vector2D rhsVector{ this->GetVertice(rhsVerticesIndex) };

    auto lhsPlusTestX = lhsVector.GetX() + testVector.GetX();
    auto lhsMinusTestX = lhsVector.GetX() - testVector.GetX();
    auto lhsPlusTestY = lhsVector.GetY() + testVector.GetY();
    auto lhsMinusTestY = lhsVector.GetY() - testVector.GetY();
    auto mhsPlusTestX = mhsVector.GetX() + testVector.GetX();
    auto mhsMinusTestX = mhsVector.GetX() - testVector.GetX();
    auto mhsPlusTestY = mhsVector.GetY() + testVector.GetY();
    auto mhsMinusTestY = mhsVector.GetY() - testVector.GetY();
    auto rhsPlusTestX = rhsVector.GetX() + testVector.GetX();
    auto rhsMinusTestX = rhsVector.GetX() - testVector.GetX();
    auto rhsPlusTestY = rhsVector.GetY() + testVector.GetY();
    auto rhsMinusTestY = rhsVector.GetY() - testVector.GetY();
    auto z0 = lhsPlusTestX * lhsMinusTestX + lhsPlusTestY * lhsMinusTestY;
    auto z1 = mhsPlusTestX * mhsMinusTestX + mhsPlusTestY * mhsMinusTestY;
    auto z2 = rhsPlusTestX * rhsMinusTestX + rhsPlusTestY * rhsMinusTestY;

    auto len0 = Math::Sqrt(lhsMinusTestX * lhsMinusTestX + lhsMinusTestY * lhsMinusTestY + z0 * z0);
    auto len1 = Math::Sqrt(mhsMinusTestX * mhsMinusTestX + mhsMinusTestY * mhsMinusTestY + z1 * z1);
    auto len2 = Math::Sqrt(rhsMinusTestX * rhsMinusTestX + rhsMinusTestY * rhsMinusTestY + z2 * z2);
    auto scaledUncertainty = m_Uncertainty * len0 * len1 * len2;

    auto det = QueryDotTools<Real>::Det3(lhsMinusTestX, lhsMinusTestY, z0, mhsMinusTestX, mhsMinusTestY, z1, rhsMinusTestX, rhsMinusTestY, z2);
    if (scaledUncertainty <= Math::FAbs(det))
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

#endif  // MATHEMATICS_QUERY_QUERY2_FILTERED_DETAIL_H

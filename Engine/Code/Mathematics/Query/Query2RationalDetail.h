///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/11/30 15:21)

#ifndef MATHEMATICS_QUERY_QUERY2_RATIONAL_DETAIL_H
#define MATHEMATICS_QUERY_QUERY2_RATIONAL_DETAIL_H

#include "Query2Rational.h"
#include "QueryDotToolsDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Rational/RationalVector2Detail.h"
#include "Mathematics/Rational/SignRationalDetail.h"

template <typename Real>
Mathematics::Query2Rational<Real>::Query2Rational(const VerticesType& vertices)
    : ParentType{ vertices }, m_RationalVertices{}
{
    Convert();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::Query2Rational<Real>::Convert()
{
    const auto numVertices = this->GetNumVertices();

    for (auto index = 0; index < numVertices; ++index)
    {
        const auto vertice = this->GetVertice(index);

        QueryRational rational0{ vertice.GetX() };
        QueryRational rational1{ vertice.GetY() };

        m_RationalVertices.emplace_back(rational0, rational1);
    }
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Query2Rational<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::QueryType Mathematics::Query2Rational<Real>::GetType() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return QueryType::Rational;
}

template <typename Real>
Mathematics::LineQueryType Mathematics::Query2Rational<Real>::ToLine(int index, int lhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ToLine(m_RationalVertices.at(index), lhsVerticesIndex, rhsVerticesIndex);
}

template <typename Real>
Mathematics::LineQueryType Mathematics::Query2Rational<Real>::ToLine(const Vector2D& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const QueryRational rational0{ testVector.GetX() };
    const QueryRational rational1{ testVector.GetY() };

    const QueryRationalVector queryRationalVector{ rational0, rational1 };

    return ToLine(queryRationalVector, lhsVerticesIndex, rhsVerticesIndex);
}

template <typename Real>
Mathematics::LineQueryType Mathematics::Query2Rational<Real>::ToLine(const QueryRationalVector& rationalTest, int lhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto x0 = rationalTest.GetX() - m_RationalVertices.at(lhsVerticesIndex).GetX();
    auto y0 = rationalTest.GetY() - m_RationalVertices.at(lhsVerticesIndex).GetY();
    auto x1 = m_RationalVertices.at(rhsVerticesIndex).GetX() - m_RationalVertices.at(lhsVerticesIndex).GetX();
    auto y1 = m_RationalVertices.at(rhsVerticesIndex).GetY() - m_RationalVertices.at(lhsVerticesIndex).GetY();

    auto det = QueryDotTools<QueryRational>::Det2(x0, y0, x1, y1);

    if (QueryRational{ 0 } < det)
        return LineQueryType::Right;
    else if (det < QueryRational{ 0 })
        return LineQueryType::Left;
    else
        return LineQueryType::OnLine;
}

template <typename Real>
Mathematics::TriangleQueryType Mathematics::Query2Rational<Real>::ToTriangle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ToTriangle(m_RationalVertices.at(index), lhsVerticesIndex, mhsVerticesIndex, rhsVerticesIndex);
}

template <typename Real>
Mathematics::TriangleQueryType Mathematics::Query2Rational<Real>::ToTriangle(const Vector2D& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const QueryRational rational0{ testVector.GetX() };
    const QueryRational rational1{ testVector.GetY() };

    const QueryRationalVector queryRationalVector{ rational0, rational1 };

    return ToTriangle(queryRationalVector, lhsVerticesIndex, mhsVerticesIndex, rhsVerticesIndex);
}

template <typename Real>
Mathematics::TriangleQueryType Mathematics::Query2Rational<Real>::ToTriangle(const QueryRationalVector& rationalTest, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(0 <= lhsVerticesIndex && lhsVerticesIndex < this->GetNumVertices(), "索引错误！");
    MATHEMATICS_ASSERTION_0(0 <= mhsVerticesIndex && mhsVerticesIndex < this->GetNumVertices(), "索引错误！");
    MATHEMATICS_ASSERTION_0(0 <= rhsVerticesIndex && rhsVerticesIndex < this->GetNumVertices(), "索引错误！");
    MATHEMATICS_ASSERTION_3(ToLine(lhsVerticesIndex, mhsVerticesIndex, rhsVerticesIndex) != LineQueryType::Right, "三角形顶点不是逆时针顺序！");

    const auto sign0 = ToLine(rationalTest, mhsVerticesIndex, rhsVerticesIndex);
    if (sign0 == LineQueryType::Right)
    {
        return TriangleQueryType::Outside;
    }

    const auto sign1 = ToLine(rationalTest, lhsVerticesIndex, rhsVerticesIndex);
    if (sign1 == LineQueryType::Left)
    {
        return TriangleQueryType::Outside;
    }

    const auto sign2 = ToLine(rationalTest, lhsVerticesIndex, mhsVerticesIndex);
    if (sign2 == LineQueryType::Right)
    {
        return TriangleQueryType::Outside;
    }

    if (sign0 == LineQueryType::OnLine || sign1 == LineQueryType::OnLine || sign2 == LineQueryType::OnLine)
    {
        return TriangleQueryType::OnTriangle;
    }
    else
    {
        return TriangleQueryType::Inside;
    }
}

template <typename Real>
Mathematics::CircumcircleQueryType Mathematics::Query2Rational<Real>::ToCircumcircle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ToCircumcircle(m_RationalVertices.at(index), lhsVerticesIndex, mhsVerticesIndex, rhsVerticesIndex);
}

template <typename Real>
Mathematics::CircumcircleQueryType Mathematics::Query2Rational<Real>::ToCircumcircle(const Vector2D& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const QueryRational rational0{ testVector.GetX() };
    const QueryRational rational1{ testVector.GetY() };

    const QueryRationalVector queryRationalVector{ rational0, rational1 };

    return ToCircumcircle(queryRationalVector, lhsVerticesIndex, mhsVerticesIndex, rhsVerticesIndex);
}

template <typename Real>
Mathematics::CircumcircleQueryType Mathematics::Query2Rational<Real>::ToCircumcircle(const QueryRationalVector& rationalTest, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto& lhsVector = m_RationalVertices.at(lhsVerticesIndex);
    const auto& mhsVector = m_RationalVertices.at(mhsVerticesIndex);
    const auto& rhsVector = m_RationalVertices.at(rhsVerticesIndex);

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

    auto det = QueryDotTools<QueryRational>::Det3(lhsMinusTestX, lhsMinusTestY, z0, mhsMinusTestX, mhsMinusTestY, z1, rhsMinusTestX, rhsMinusTestY, z2);

    if (QueryRational{ 0 } < det)
        return CircumcircleQueryType::Inside;
    else if (det < QueryRational{ 0 })
        return CircumcircleQueryType::Outside;
    else
        return CircumcircleQueryType::OnCircumcircle;
}

#endif  // MATHEMATICS_QUERY_QUERY2_RATIONAL_DETAIL_H

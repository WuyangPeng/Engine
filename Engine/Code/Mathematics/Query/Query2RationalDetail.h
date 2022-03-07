///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/17 16:46)

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
    : ParentType{ vertices }, rationalVertices{}
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

        rationalVertices.emplace_back(rational0, rational1);
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

    return ToLine(rationalVertices.at(index), lhsVerticesIndex, rhsVerticesIndex);
}

template <typename Real>
Mathematics::LineQueryType Mathematics::Query2Rational<Real>::ToLine(const Vector2& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const
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

    const auto x0 = rationalTest.GetX() - rationalVertices.at(lhsVerticesIndex).GetX();
    const auto y0 = rationalTest.GetY() - rationalVertices.at(lhsVerticesIndex).GetY();
    const auto x1 = rationalVertices.at(rhsVerticesIndex).GetX() - rationalVertices.at(lhsVerticesIndex).GetX();
    const auto y1 = rationalVertices.at(rhsVerticesIndex).GetY() - rationalVertices.at(lhsVerticesIndex).GetY();

    const auto det = QueryDotTools<QueryRational>::Det2(x0, y0, x1, y1);

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

    return ToTriangle(rationalVertices.at(index), lhsVerticesIndex, mhsVerticesIndex, rhsVerticesIndex);
}

template <typename Real>
Mathematics::TriangleQueryType Mathematics::Query2Rational<Real>::ToTriangle(const Vector2& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const
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

    return ToCircumcircle(rationalVertices.at(index), lhsVerticesIndex, mhsVerticesIndex, rhsVerticesIndex);
}

template <typename Real>
Mathematics::CircumcircleQueryType Mathematics::Query2Rational<Real>::ToCircumcircle(const Vector2& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const
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

    const auto& lhsVector = rationalVertices.at(lhsVerticesIndex);
    const auto& mhsVector = rationalVertices.at(mhsVerticesIndex);
    const auto& rhsVector = rationalVertices.at(rhsVerticesIndex);

    const auto lhsPlusTestX = lhsVector.GetX() + rationalTest.GetX();
    const auto lhsMinusTestX = lhsVector.GetX() - rationalTest.GetX();
    const auto lhsPlusTestY = lhsVector.GetY() + rationalTest.GetY();
    const auto lhsMinusTestY = lhsVector.GetY() - rationalTest.GetY();
    const auto mhsPlusTestX = mhsVector.GetX() + rationalTest.GetX();
    const auto mhsMinusTestX = mhsVector.GetX() - rationalTest.GetX();
    const auto mhsPlusTestY = mhsVector.GetY() + rationalTest.GetY();
    const auto mhsMinusTestY = mhsVector.GetY() - rationalTest.GetY();
    const auto rhsPlusTestX = rhsVector.GetX() + rationalTest.GetX();
    const auto rhsMinusTestX = rhsVector.GetX() - rationalTest.GetX();
    const auto rhsPlusTestY = rhsVector.GetY() + rationalTest.GetY();
    const auto rhsMinusTestY = rhsVector.GetY() - rationalTest.GetY();
    const auto z0 = lhsPlusTestX * lhsMinusTestX + lhsPlusTestY * lhsMinusTestY;
    const auto z1 = mhsPlusTestX * mhsMinusTestX + mhsPlusTestY * mhsMinusTestY;
    const auto z2 = rhsPlusTestX * rhsMinusTestX + rhsPlusTestY * rhsMinusTestY;

    const auto det = QueryDotTools<QueryRational>::Det3(lhsMinusTestX, lhsMinusTestY, z0, mhsMinusTestX, mhsMinusTestY, z1, rhsMinusTestX, rhsMinusTestY, z2);

    if (QueryRational{ 0 } < det)
        return CircumcircleQueryType::Inside;
    else if (det < QueryRational{ 0 })
        return CircumcircleQueryType::Outside;
    else
        return CircumcircleQueryType::OnCircumcircle;
}

#endif  // MATHEMATICS_QUERY_QUERY2_RATIONAL_DETAIL_H

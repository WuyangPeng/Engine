/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 23:31)

#ifndef MATHEMATICS_QUERY_QUERY2_DETAIL_H
#define MATHEMATICS_QUERY_QUERY2_DETAIL_H

#include "Query2.h"
#include "QueryDotToolsDetail.h"
#include "QuerySortTools.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Query2<Real>::Query2(VerticesType vertices) noexcept
    : ParentType{}, vertices{ std::move(vertices) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Query2<Real>::IsValid() const noexcept
{
    if (!vertices.empty())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::QueryType Mathematics::Query2<Real>::GetType() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return QueryType::Real;
}

template <typename Real>
int Mathematics::Query2<Real>::GetNumVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(vertices.size());
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::Query2<Real>::GetVertex(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return vertices.at(index);
}

template <typename Real>
Mathematics::LineQueryType Mathematics::Query2<Real>::ToLine(int index, int lhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ToLine(GetVertex(index), lhsVerticesIndex, rhsVerticesIndex);
}

template <typename Real>
Mathematics::LineQueryType Mathematics::Query2<Real>::ToLine(const Vector2& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const QuerySortTools querySortTools{ lhsVerticesIndex, rhsVerticesIndex };

    const auto& vector0 = vertices.at(querySortTools.GetValue(0));
    const auto& vector1 = vertices.at(querySortTools.GetValue(1));

    const auto x0 = testVector.GetX() - vector0.GetX();
    const auto y0 = testVector.GetY() - vector0.GetY();
    const auto x1 = vector1.GetX() - vector0.GetX();
    const auto y1 = vector1.GetY() - vector0.GetY();

    auto det = QueryDotTools<Real>::Det2(x0, y0, x1, y1);

    if (const auto positive = querySortTools.GetSymbol();
        positive == NumericalValueSymbol::Negative)
    {
        det = -det;
    }

    if (Math::FAbs(det) <= Math::GetZeroTolerance())
        return LineQueryType::OnLine;
    else if (Math::GetValue(0) < det)
        return LineQueryType::Right;
    else
        return LineQueryType::Left;
}

template <typename Real>
Mathematics::TriangleQueryType Mathematics::Query2<Real>::ToTriangle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ToTriangle(GetVertex(index), lhsVerticesIndex, mhsVerticesIndex, rhsVerticesIndex);
}

template <typename Real>
Mathematics::TriangleQueryType Mathematics::Query2<Real>::ToTriangle(const Vector2& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_3(ToLine(lhsVerticesIndex, mhsVerticesIndex, rhsVerticesIndex) != LineQueryType::Right, "三角形顶点不是逆时针顺序！");

    const auto sign0 = ToLine(testVector, mhsVerticesIndex, rhsVerticesIndex);
    if (sign0 == LineQueryType::Right)
    {
        return TriangleQueryType::Outside;
    }

    const auto sign1 = ToLine(testVector, lhsVerticesIndex, rhsVerticesIndex);
    if (sign1 == LineQueryType::Left)
    {
        return TriangleQueryType::Outside;
    }

    const auto sign2 = ToLine(testVector, lhsVerticesIndex, mhsVerticesIndex);
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
Mathematics::CircumcircleQueryType Mathematics::Query2<Real>::ToCircumcircle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ToCircumcircle(GetVertex(index), lhsVerticesIndex, mhsVerticesIndex, rhsVerticesIndex);
}

template <typename Real>
Mathematics::CircumcircleQueryType Mathematics::Query2<Real>::ToCircumcircle(const Vector2& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const QuerySortTools querySortTools{ lhsVerticesIndex, mhsVerticesIndex, rhsVerticesIndex };

    const auto& lhsVector = vertices.at(querySortTools.GetValue(0));
    const auto& mhsVector = vertices.at(querySortTools.GetValue(1));
    const auto& rhsVector = vertices.at(querySortTools.GetValue(2));

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

    auto det = QueryDotTools<Real>::Det3(lhsMinusTestX, lhsMinusTestY, z0, mhsMinusTestX, mhsMinusTestY, z1, rhsMinusTestX, rhsMinusTestY, z2);

    if (const auto positive = querySortTools.GetSymbol();
        positive == NumericalValueSymbol::Negative)
    {
        det = -det;
    }

    if (Math::FAbs(det) <= Math::GetZeroTolerance())
        return CircumcircleQueryType::OnCircumcircle;
    else if (det < Math::GetValue(0))
        return CircumcircleQueryType::Outside;
    else
        return CircumcircleQueryType::Inside;
}

#endif  // MATHEMATICS_QUERY_QUERY2_DETAIL_H

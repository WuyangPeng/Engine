///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/11/30 14:58)

#ifndef MATHEMATICS_QUERY_QUERY2_INT64_DETAIL_H
#define MATHEMATICS_QUERY_QUERY2_INT64_DETAIL_H

#include "Query2Int64.h"
#include "QueryDotToolsDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Query2Int64<Real>::Query2Int64(const VerticesType& vertices)
    : ParentType{ vertices }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Query2Int64<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::QueryType Mathematics::Query2Int64<Real>::GetType() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return QueryType::Int64;
}

template <typename Real>
Mathematics::LineQueryType Mathematics::Query2Int64<Real>::ToLine(int index, int lhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ParentType::ToLine(index, lhsVerticesIndex, rhsVerticesIndex);
}

template <typename Real>
Mathematics::LineQueryType Mathematics::Query2Int64<Real>::ToLine(const Vector2D& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(0 <= lhsVerticesIndex && lhsVerticesIndex < this->GetNumVertices(), "��������");
    MATHEMATICS_ASSERTION_0(0 <= rhsVerticesIndex && rhsVerticesIndex < this->GetNumVertices(), "��������");

    const auto vector0 = this->GetVertice(lhsVerticesIndex);
    const auto vector1 = this->GetVertice(rhsVerticesIndex);

    const auto x0 = boost::numeric_cast<int64_t>(testVector.GetX()) - boost::numeric_cast<int64_t>(vector0.GetX());
    const auto y0 = boost::numeric_cast<int64_t>(testVector.GetY()) - boost::numeric_cast<int64_t>(vector0.GetY());
    const auto x1 = boost::numeric_cast<int64_t>(vector1.GetX()) - boost::numeric_cast<int64_t>(vector0.GetX());
    const auto y1 = boost::numeric_cast<int64_t>(vector1.GetY()) - boost::numeric_cast<int64_t>(vector0.GetY());

    auto det = QueryDotTools<int64_t>::Det2(x0, y0, x1, y1);

    if (0 < det)
        return LineQueryType::Right;
    else if (det < 0)
        return LineQueryType::Left;
    else
        return LineQueryType::OnLine;
}

template <typename Real>
Mathematics::CircumcircleQueryType Mathematics::Query2Int64<Real>::ToCircumcircle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ParentType::ToCircumcircle(index, lhsVerticesIndex, mhsVerticesIndex, rhsVerticesIndex);
}

template <typename Real>
Mathematics::CircumcircleQueryType Mathematics::Query2Int64<Real>::ToCircumcircle(const Vector2D& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(0 <= lhsVerticesIndex && lhsVerticesIndex < this->GetNumVertices(), "��������");
    MATHEMATICS_ASSERTION_0(0 <= mhsVerticesIndex && mhsVerticesIndex < this->GetNumVertices(), "��������");
    MATHEMATICS_ASSERTION_0(0 <= rhsVerticesIndex && rhsVerticesIndex < this->GetNumVertices(), "��������");

    const Vector2D lhsVector{ this->GetVertice(lhsVerticesIndex) };
    const Vector2D mhsVector{ this->GetVertice(mhsVerticesIndex) };
    const Vector2D rhsVector{ this->GetVertice(rhsVerticesIndex) };

    auto lhsPlusTestX = boost::numeric_cast<int64_t>(lhsVector.GetX() + testVector.GetX());
    auto lhsMinusTestX = boost::numeric_cast<int64_t>(lhsVector.GetX() - testVector.GetX());
    auto lhsPlusTestY = boost::numeric_cast<int64_t>(lhsVector.GetY() + testVector.GetY());
    auto lhsMinusTestY = boost::numeric_cast<int64_t>(lhsVector.GetY() - testVector.GetY());
    auto mhsPlusTestX = boost::numeric_cast<int64_t>(mhsVector.GetX() + testVector.GetX());
    auto mhsMinusTestX = boost::numeric_cast<int64_t>(mhsVector.GetX() - testVector.GetX());
    auto mhsPlusTestY = boost::numeric_cast<int64_t>(mhsVector.GetY() + testVector.GetY());
    auto mhsMinusTestY = boost::numeric_cast<int64_t>(mhsVector.GetY() - testVector.GetY());
    auto rhsPlusTestX = boost::numeric_cast<int64_t>(rhsVector.GetX() + testVector.GetX());
    auto rhsMinusTestX = boost::numeric_cast<int64_t>(rhsVector.GetX() - testVector.GetX());
    auto rhsPlusTestY = boost::numeric_cast<int64_t>(rhsVector.GetY() + testVector.GetY());
    auto rhsMinusTestY = boost::numeric_cast<int64_t>(rhsVector.GetY() - testVector.GetY());
    auto z0 = lhsPlusTestX * lhsMinusTestX + lhsPlusTestY * lhsMinusTestY;
    auto z1 = mhsPlusTestX * mhsMinusTestX + mhsPlusTestY * mhsMinusTestY;
    auto z2 = rhsPlusTestX * rhsMinusTestX + rhsPlusTestY * rhsMinusTestY;

    auto det = QueryDotTools<int64_t>::Det3(lhsMinusTestX, lhsMinusTestY, z0, mhsMinusTestX, mhsMinusTestY, z1, rhsMinusTestX, rhsMinusTestY, z2);

    if (0 < det)
        return CircumcircleQueryType::Inside;
    else if (det < 0)
        return CircumcircleQueryType::Outside;
    else
        return CircumcircleQueryType::OnCircumcircle;
}

#endif  // MATHEMATICS_QUERY_QUERY2_INT64_DETAIL_H

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 14:26)

#ifndef MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_LINE3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_LINE3_TRIANGLE3_DETAIL_H

#include "StaticTestIntersectorLine3Triangle3.h"
#include "Detail/IntersectorLine3Triangle3DataDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"
#include "Mathematics/Intersection/IntersectorDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"

template <typename Real>
Mathematics::StaticTestIntersectorLine3Triangle3<Real>::StaticTestIntersectorLine3Triangle3(const Line3Type& line, const Triangle3Type& triangle, const Real epsilon)
    : ParentType{ epsilon }, line{ line }, triangle{ triangle }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorLine3Triangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line3<Real> Mathematics::StaticTestIntersectorLine3Triangle3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return line;
}

template <typename Real>
Mathematics::Triangle3<Real> Mathematics::StaticTestIntersectorLine3Triangle3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return triangle;
}

template <typename Real>
void Mathematics::StaticTestIntersectorLine3Triangle3<Real>::Test()
{
    const IntersectorLine3Triangle3Data<Real> data{ line, triangle };

    auto directionDotNormal = data.GetDirectionDotNormal();
    auto epsilon = this->GetEpsilon();
    auto sign = NumericalValueSymbol::Zero;

    if (epsilon < directionDotNormal)
    {
        sign = NumericalValueSymbol::Positive;
    }
    else if (directionDotNormal < epsilon)
    {
        sign = NumericalValueSymbol::Negative;
        directionDotNormal = -directionDotNormal;
    }
    else
    {
        // �ߺ���������ƽ�е�,��֮Ϊ��û�н�������
        // ��ʹ�����ཻ��
        return;
    }

    using namespace System;

    auto directionDotOriginCrossEdge2 = sign * Vector3ToolsType::DotProduct(line.GetDirection(), data.GetOriginCrossEdge2());
    if (MathType::GetValue(0) <= directionDotOriginCrossEdge2)
    {
        auto directionDotEdge1CrossOrigin = sign * Vector3ToolsType::DotProduct(line.GetDirection(), data.GetEdge1CrossOrigin());

        if (MathType::GetValue(0) <= directionDotEdge1CrossOrigin)
        {
            if (directionDotNormal <= directionDotOriginCrossEdge2 + directionDotEdge1CrossOrigin)
            {
                this->SetIntersectionType(IntersectionType::Point);
            }
            // else: 1 < b1 + b2, ���ཻ
        }
        // else: b2 < 0, ���ཻ
    }
    // else: b1 < 0, ���ཻ
}

#endif  // MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_LINE3_TRIANGLE3_DETAIL_H
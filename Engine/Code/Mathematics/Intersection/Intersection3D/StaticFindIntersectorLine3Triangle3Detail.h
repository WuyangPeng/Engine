///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 13:50)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_TRIANGLE3_DETAIL_H

#include "StaticFindIntersectorLine3Triangle3.h"
#include "Detail/IntersectorLine3Triangle3DataDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"
#include "Mathematics/Intersection/IntersectorDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine3Triangle3<Real>::StaticFindIntersectorLine3Triangle3(const Line3& line, const Triangle3& triangle, const Real epsilon)
    : ParentType{ epsilon }, line{ line }, triangle{ triangle }, lineParameter{}, triangleBary0{}, triangleBary1{}, triangleBary2{ MathType::GetValue(1) }, point{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorLine3Triangle3<Real>::IsValid() const noexcept
{
    try
    {
        if (ParentType::IsValid() && MathType::Approximate(triangleBary0 + triangleBary1 + triangleBary2, MathType::GetValue(1)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line3<Real> Mathematics::StaticFindIntersectorLine3Triangle3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return line;
}

template <typename Real>
Mathematics::Triangle3<Real> Mathematics::StaticFindIntersectorLine3Triangle3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine3Triangle3<Real>::Find()
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

    auto directionDotOriginCrossEdge2 = System::EnumCastUnderlying(sign) * Vector3ToolsType::DotProduct(line.GetDirection(), data.GetOriginCrossEdge2());
    if (MathType::GetValue(0) <= directionDotOriginCrossEdge2)
    {
        auto directionDotEdge1CrossOrigin = System::EnumCastUnderlying(sign) * Vector3ToolsType::DotProduct(line.GetDirection(), data.GetEdge1CrossOrigin());

        if (MathType::GetValue(0) <= directionDotEdge1CrossOrigin)
        {
            if (directionDotOriginCrossEdge2 + directionDotEdge1CrossOrigin <= directionDotNormal)
            {
                // �ߺ��������ཻ
                auto originDotNormal = -System::EnumCastUnderlying(sign) * data.GetOriginDotNormal();

                lineParameter = originDotNormal / directionDotNormal;
                triangleBary1 = directionDotOriginCrossEdge2 / directionDotNormal;
                triangleBary2 = directionDotEdge1CrossOrigin / directionDotNormal;
                triangleBary0 = MathType::GetValue(1) - triangleBary1 - triangleBary2;

                point = line.GetOrigin() + lineParameter * line.GetDirection();

                this->SetIntersectionType(IntersectionType::Point);
            }
            // else: 1 < b1 + b2, ���ཻ
        }
        // else: b2 < 0, ���ཻ
    }
    // else: b1 < 0, ���ཻ
}

template <typename Real>
Real Mathematics::StaticFindIntersectorLine3Triangle3<Real>::GetLineParameter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return lineParameter;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorLine3Triangle3<Real>::GetTriangleBary0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangleBary0;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorLine3Triangle3<Real>::GetTriangleBary1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangleBary1;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorLine3Triangle3<Real>::GetTriangleBary2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangleBary2;
}

template <typename Real>
typename Mathematics::StaticFindIntersectorLine3Triangle3<Real>::Vector3 Mathematics::StaticFindIntersectorLine3Triangle3<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return point;
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_TRIANGLE3_DETAIL_H

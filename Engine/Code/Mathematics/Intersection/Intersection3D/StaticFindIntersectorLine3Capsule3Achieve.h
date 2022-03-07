///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.3 (2022/03/01 18:48)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_CAPSULE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_CAPSULE3_ACHIEVE_H

#include "StaticFindIntersectorLine3Capsule3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Distance/Distance3D/DistanceLine3Segment3Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine3Capsule3<Real>::StaticFindIntersectorLine3Capsule3(const Line3& line, const Capsule3& capsule, const Real epsilon)
    : ParentType{ epsilon }, line{ line }, capsule{ capsule }, quantity{}, point0{}, point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorLine3Capsule3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line3<Real> Mathematics::StaticFindIntersectorLine3Capsule3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return line;
}

template <typename Real>
Mathematics::Capsule3<Real> Mathematics::StaticFindIntersectorLine3Capsule3<Real>::GetCapsule() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return capsule;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine3Capsule3<Real>::Find()
{
    const auto findShared = Find(line.GetOrigin(), line.GetDirection(), capsule);
    quantity = findShared.quantity;
    if (0 < quantity)
    {
        point0 = line.GetOrigin() + findShared.parameter0 * line.GetDirection();
    }

    if (1 < quantity)
    {
        point1 = line.GetOrigin() + findShared.parameter1 * line.GetDirection();
    }

    if (quantity == 2)
    {
        this->SetIntersectionType(IntersectionType::Segment);
    }
    else if (quantity == 1)
    {
        this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine3Capsule3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::StaticFindIntersectorLine3Capsule3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < quantity)
    {
        if (index == 0)
            return point0;
        else if (index == 1)
            return point1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("����Խ��\n"s));
}

template <typename Real>
typename Mathematics::StaticFindIntersectorLine3Capsule3<Real>::FindShared Mathematics::StaticFindIntersectorLine3Capsule3<Real>::Find(const Vector3& origin, const Vector3& direction, const Capsule3& capsule)
{
    FindShared findShared{};

    /// Ϊ���Ҵ�������ϵ�� �ڸ�ϵͳ�У����Ҷ�����CΪԭ�㣬�����᷽��WΪz�ᡣ
    /// U��V�����������᷽�� ���P = x * U + y * V + z * W����������ұڵ�Բ����Ϊx^2 + y^2 = r^2������r�ǽ��Ұ뾶��
    /// ��ɽ��Ҽ�ȥ������ζ˸ǵ�����Բ�����zֵ|z| <= e������e�ǽ��Ҷεķ�Χ��
    /// ����z > = e���ϰ�������Ϊx^2+y^2+(z-e)^2 = r^2������z <= -e���°�������Ϊx^2+y^2+(z+e)^2 = r^2��
    const auto segmentDirection = capsule.GetSegment().GetDirection();
    const auto Vector3OrthonormalBasis = Vector3Tools::GenerateComplementBasis(segmentDirection);
    const auto uVector = Vector3OrthonormalBasis.GetUVector();
    const auto vVector = Vector3OrthonormalBasis.GetVVector();
    auto radiusSqr = capsule.GetRadius() * capsule.GetRadius();
    auto extent = capsule.GetSegment().GetExtent();

    // �������ߵ�ԭ��ת��Ϊ�������ꡣ
    auto diff = origin - capsule.GetSegment().GetCenterPoint();
    const Vector3 point{ Vector3Tools::DotProduct(uVector, diff), Vector3Tools::DotProduct(vVector, diff), Vector3Tools::DotProduct(segmentDirection, diff) };

    // ��ȡ�ߵĵ�λ���ȷ����ڽ��������е�zֵ��
    auto directionDot = Vector3Tools::DotProduct(segmentDirection, direction);
    if (Math::GetValue(1) - Math::GetZeroTolerance() <= Math::FAbs(directionDot))
    {
        // ����ƽ���ڽ������ߡ� ȷ�������Ƿ��뽺�Ұ����ཻ��
        auto radialSqrDist = radiusSqr - point.GetX() * point.GetX() - point.GetY() * point.GetY();
        if (radialSqrDist < Math::GetValue(0))
        {
            // ���ڽ���Բ������ⲿ�����ཻ����
            return findShared;
        }

        // �������ñ�ཻ
        auto zOffset = Math::Sqrt(radialSqrDist) + extent;
        if (Math::GetValue(0) < directionDot)
        {
            findShared.parameter0 = -point.GetZ() - zOffset;
            findShared.parameter1 = -point.GetZ() + zOffset;
        }
        else
        {
            findShared.parameter0 = point.GetZ() - zOffset;
            findShared.parameter1 = point.GetZ() + zOffset;
        }

        findShared.quantity = 2;
        return findShared;
    }

    // �������ߵ�λ���ȷ���ת��Ϊ�������ꡣ
    const Vector3 dot{ Vector3Tools::DotProduct(uVector, direction), Vector3Tools::DotProduct(vVector, direction), directionDot };

    /// ������ P + t * D������Բ��x^2 + y^2 = r^2�Ľ��㡣 ���Ϊ������η���ʽ�ĸ���
    /// ���P = (px,py,pz)�� D = (dx,dy,dz)������η���Ϊ
    /// (dx^2 + dy^2) * t^2 + 2 * (px * dx + py * dy) * t + (px^2 + py^2 - r^2) = 0
    auto a0 = point.GetX() * point.GetX() + point.GetY() * point.GetY() - radiusSqr;
    auto a1 = point.GetX() * dot.GetX() + point.GetY() * dot.GetY();
    auto a2 = dot.GetX() * dot.GetX() + dot.GetY() * dot.GetY();
    auto discr = a1 * a1 - a0 * a2;
    if (discr < Math::GetValue(0))
    {
        // �߲�������Բ���ཻ��
        return findShared;
    }

    int quantity = 0;
    if (Math::GetZeroTolerance() < discr)
    {
        // ���������ط�������Բ���ཻ��
        auto root = Math::Sqrt(discr);
        auto inv = (Math::GetValue(1)) / a2;
        auto tValue = (-a1 - root) * inv;
        auto zValue = point.GetZ() + tValue * dot.GetZ();
        if (Math::FAbs(zValue) <= extent)
        {
            findShared.parameter0 = tValue;
            ++quantity;
        }

        tValue = (-a1 + root) * inv;
        zValue = point.GetZ() + tValue * dot.GetZ();
        if (Math::FAbs(zValue) <= extent)
        {
            if (quantity == 0)
            {
                findShared.parameter0 = tValue;
            }
            else
            {
                findShared.parameter1 = tValue;
            }
            ++quantity;
        }

        if (quantity == 2)
        {
            // ���������ط��뽺�ұ��ཻ��
            findShared.quantity = 2;
            return findShared;
        }
    }
    else
    {
        // ��������Բ�����С�
        auto tValue = -a1 / a2;
        auto zValue = point.GetZ() + tValue * dot.GetZ();
        if (Math::FAbs(zValue) <= extent)
        {
            findShared.parameter0 = tValue;

            findShared.quantity = 1;
            return findShared;
        }
    }

    /// �������°���Ľ��㡣 ���η�����t^2 + 2 * (px * dx + py * dy + (pz + e) * dz) * t + (px^2 + py^2 + (pz + e)^2 - r^2) = 0
    /// ʹ�õ�ǰa1 = px * dx + py * dy��a0 = px^2 + py^2 - r^2����ʵ�� ǰ��ϵ��Ϊa2 = 1�������������ڹ����С�
    auto zPlusExtent = point.GetZ() + extent;
    a1 += zPlusExtent * dot.GetZ();
    a0 += zPlusExtent * zPlusExtent;
    discr = a1 * a1 - a0;
    if (Math::GetZeroTolerance() < discr)
    {
        auto root = Math::Sqrt(discr);
        auto tValue = -a1 - root;
        auto zValue = point.GetZ() + tValue * dot.GetZ();
        if (zValue <= -extent)
        {
            if (quantity == 0)
            {
                findShared.parameter0 = tValue;
            }
            else
            {
                findShared.parameter1 = tValue;
            }
            ++quantity;
            if (quantity == 2)
            {
                if (findShared.parameter1 < findShared.parameter0)
                {
                    std::swap(findShared.parameter0, findShared.parameter1);
                }

                findShared.quantity = 2;
                return findShared;
            }
        }

        tValue = -a1 + root;
        zValue = point.GetZ() + tValue * dot.GetZ();
        if (zValue <= -extent)
        {
            if (quantity == 0)
            {
                findShared.parameter0 = tValue;
            }
            else
            {
                findShared.parameter1 = tValue;
            }
            ++quantity;
            if (quantity == 2)
            {
                if (findShared.parameter1 < findShared.parameter0)
                {
                    std::swap(findShared.parameter0, findShared.parameter1);
                }

                findShared.quantity = 2;
                return findShared;
            }
        }
    }
    else if (Math::FAbs(discr) <= Math::GetZeroTolerance())
    {
        auto tValue = -a1;
        auto zValue = point.GetZ() + tValue * dot.GetZ();
        if (zValue <= -extent)
        {
            if (quantity == 0)
            {
                findShared.parameter0 = tValue;
            }
            else
            {
                findShared.parameter1 = tValue;
            }
            ++quantity;
            if (quantity == 2)
            {
                if (findShared.parameter1 < findShared.parameter0)
                {
                    std::swap(findShared.parameter0, findShared.parameter1);
                }

                findShared.quantity = 2;
                return findShared;
            }
        }
    }

    /// �������ϰ���Ľ��㡣 ���η�����t^2 + 2 * (px * dx + py * dy + (pz - e) * dz) * t + (px^2 + py^2 + (pz - e)^2 - r^2) = 0
    /// ʹ�õ�ǰa1 = px * dx  + py * dy + (pz + e) * dz��a0 = px^2 + py^2 + (pz + e)^2 - r^2����ʵ��
    /// ǰ��ϵ��Ϊa2 = 1�������������ڹ����С�
    a1 -= (Math::GetValue(2)) * extent * dot.GetZ();
    a0 -= (Math::GetValue(4)) * extent * point.GetZ();
    discr = a1 * a1 - a0;
    if (Math::GetZeroTolerance() < discr)
    {
        auto root = Math::Sqrt(discr);
        auto tValue = -a1 - root;
        auto zValue = point.GetZ() + tValue * dot.GetZ();
        if (extent <= zValue)
        {
            if (quantity == 0)
            {
                findShared.parameter0 = tValue;
            }
            else
            {
                findShared.parameter1 = tValue;
            }
            ++quantity;
            if (quantity == 2)
            {
                if (findShared.parameter1 < findShared.parameter0)
                {
                    std::swap(findShared.parameter0, findShared.parameter1);
                }

                findShared.quantity = 2;
                return findShared;
            }
        }

        tValue = -a1 + root;
        zValue = point.GetZ() + tValue * dot.GetZ();
        if (extent <= zValue)
        {
            if (quantity == 0)
            {
                findShared.parameter0 = tValue;
            }
            else
            {
                findShared.parameter1 = tValue;
            }
            ++quantity;
            if (quantity == 2)
            {
                if (findShared.parameter1 < findShared.parameter0)
                {
                    std::swap(findShared.parameter0, findShared.parameter1);
                }

                findShared.quantity = 2;
                return findShared;
            }
        }
    }
    else if (Math::FAbs(discr) <= Math::GetZeroTolerance())
    {
        auto tValue = -a1;
        auto zValue = point.GetZ() + tValue * dot.GetZ();
        if (extent <= zValue)
        {
            if (quantity == 0)
            {
                findShared.parameter0 = tValue;
            }
            else
            {
                findShared.parameter1 = tValue;
            }
            ++quantity;
            if (quantity == 2)
            {
                if (findShared.parameter1 < findShared.parameter0)
                {
                    std::swap(findShared.parameter0, findShared.parameter1);
                }

                findShared.quantity = 2;
                return findShared;
            }
        }
    }

    findShared.quantity = quantity;

    return findShared;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_CAPSULE3_ACHIEVE_H
// Copyright (c) 2010-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.2.5 (2020/03/24 17:07)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_CAPSULE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_CAPSULE3_ACHIEVE_H

#include "StaticFindIntersectorLine3Capsule3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Distance/Distance3D/DistanceLine3Segment3Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine3Capsule3<Real>::StaticFindIntersectorLine3Capsule3(const Line3& line, const Capsule3& capsule, const Real epsilon)
    : ParentType{ epsilon }, m_Line{ line }, m_Capsule{ capsule }, m_Quantity{}, m_Point0{}, m_Point1{}
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
const Mathematics::Line3<Real> Mathematics::StaticFindIntersectorLine3Capsule3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Line;
}

template <typename Real>
const Mathematics::Capsule3<Real> Mathematics::StaticFindIntersectorLine3Capsule3<Real>::GetCapsule() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Capsule;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine3Capsule3<Real>::Find()
{
    const auto findShared = Find(m_Line.GetOrigin(), m_Line.GetDirection(), m_Capsule);
    m_Quantity = findShared.m_Quantity;
    if (0 < m_Quantity)
    {
        m_Point0 = m_Line.GetOrigin() + findShared.m_Parameter0 * m_Line.GetDirection();
    }

    if (1 < m_Quantity)
    {
        m_Point1 = m_Line.GetOrigin() + findShared.m_Parameter1 * m_Line.GetDirection();
    }

    if (m_Quantity == 2)
    {
        this->SetIntersectionType(IntersectionType::Segment);
    }
    else if (m_Quantity == 1)
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

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorLine3Capsule3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < m_Quantity)
    {
        if (index == 0)
            return m_Point0;
        else if (index == 1)
            return m_Point1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("����Խ��\n"s));
}

template <typename Real>
typename Mathematics::StaticFindIntersectorLine3Capsule3<Real>::FindShared Mathematics::StaticFindIntersectorLine3Capsule3<Real>::Find(const Vector3D& origin, const Vector3D& direction, const Capsule3& capsule)
{
    FindShared findShared{};

    /// Ϊ���Ҵ�������ϵ�� �ڸ�ϵͳ�У����Ҷ�����CΪԭ�㣬�����᷽��WΪz�ᡣ
    /// U��V�����������᷽�� ���P = x * U + y * V + z * W����������ұڵ�Բ����Ϊx^2 + y^2 = r^2������r�ǽ��Ұ뾶��
    /// ��ɽ��Ҽ�ȥ������ζ˸ǵ�����Բ�����zֵ|z| <= e������e�ǽ��Ҷεķ�Χ��
    /// ����z > = e���ϰ�������Ϊx^2+y^2+(z-e)^2 = r^2������z <= -e���°�������Ϊx^2+y^2+(z+e)^2 = r^2��
    const auto segmentDirection = capsule.GetSegment().GetDirection();
    const auto vector3DOrthonormalBasis = Vector3DTools::GenerateComplementBasis(segmentDirection);
    const auto uVector = vector3DOrthonormalBasis.GetUVector();
    const auto vVector = vector3DOrthonormalBasis.GetVVector();
    auto radiusSqr = capsule.GetRadius() * capsule.GetRadius();
    auto extent = capsule.GetSegment().GetExtent();

    // �������ߵ�ԭ��ת��Ϊ�������ꡣ
    auto diff = origin - capsule.GetSegment().GetCenterPoint();
    const Vector3D point{ Vector3DTools::DotProduct(uVector, diff), Vector3DTools::DotProduct(vVector, diff), Vector3DTools::DotProduct(segmentDirection, diff) };

    // ��ȡ�ߵĵ�λ���ȷ����ڽ��������е�zֵ��
    auto directionDot = Vector3DTools::DotProduct(segmentDirection, direction);
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
            findShared.m_Parameter0 = -point.GetZ() - zOffset;
            findShared.m_Parameter1 = -point.GetZ() + zOffset;
        }
        else
        {
            findShared.m_Parameter0 = point.GetZ() - zOffset;
            findShared.m_Parameter1 = point.GetZ() + zOffset;
        }

        findShared.m_Quantity = 2;
        return findShared;
    }

    // �������ߵ�λ���ȷ���ת��Ϊ�������ꡣ
    const Vector3D dot{ Vector3DTools::DotProduct(uVector, direction), Vector3DTools::DotProduct(vVector, direction), directionDot };

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
            findShared.m_Parameter0 = tValue;
            ++quantity;
        }

        tValue = (-a1 + root) * inv;
        zValue = point.GetZ() + tValue * dot.GetZ();
        if (Math::FAbs(zValue) <= extent)
        {
            if (quantity == 0)
            {
                findShared.m_Parameter0 = tValue;
            }
            else
            {
                findShared.m_Parameter1 = tValue;
            }
            ++quantity;
        }

        if (quantity == 2)
        {
            // ���������ط��뽺�ұ��ཻ��
            findShared.m_Quantity = 2;
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
            findShared.m_Parameter0 = tValue;

            findShared.m_Quantity = 1;
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
                findShared.m_Parameter0 = tValue;
            }
            else
            {
                findShared.m_Parameter1 = tValue;
            }
            ++quantity;
            if (quantity == 2)
            {
                if (findShared.m_Parameter1 < findShared.m_Parameter0)
                {
                    std::swap(findShared.m_Parameter0, findShared.m_Parameter1);
                }

                findShared.m_Quantity = 2;
                return findShared;
            }
        }

        tValue = -a1 + root;
        zValue = point.GetZ() + tValue * dot.GetZ();
        if (zValue <= -extent)
        {
            if (quantity == 0)
            {
                findShared.m_Parameter0 = tValue;
            }
            else
            {
                findShared.m_Parameter1 = tValue;
            }
            ++quantity;
            if (quantity == 2)
            {
                if (findShared.m_Parameter1 < findShared.m_Parameter0)
                {
                    std::swap(findShared.m_Parameter0, findShared.m_Parameter1);
                }

                findShared.m_Quantity = 2;
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
                findShared.m_Parameter0 = tValue;
            }
            else
            {
                findShared.m_Parameter1 = tValue;
            }
            ++quantity;
            if (quantity == 2)
            {
                if (findShared.m_Parameter1 < findShared.m_Parameter0)
                {
                    std::swap(findShared.m_Parameter0, findShared.m_Parameter1);
                }

                findShared.m_Quantity = 2;
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
                findShared.m_Parameter0 = tValue;
            }
            else
            {
                findShared.m_Parameter1 = tValue;
            }
            ++quantity;
            if (quantity == 2)
            {
                if (findShared.m_Parameter1 < findShared.m_Parameter0)
                {
                    std::swap(findShared.m_Parameter0, findShared.m_Parameter1);
                }

                findShared.m_Quantity = 2;
                return findShared;
            }
        }

        tValue = -a1 + root;
        zValue = point.GetZ() + tValue * dot.GetZ();
        if (extent <= zValue)
        {
            if (quantity == 0)
            {
                findShared.m_Parameter0 = tValue;
            }
            else
            {
                findShared.m_Parameter1 = tValue;
            }
            ++quantity;
            if (quantity == 2)
            {
                if (findShared.m_Parameter1 < findShared.m_Parameter0)
                {
                    std::swap(findShared.m_Parameter0, findShared.m_Parameter1);
                }

                findShared.m_Quantity = 2;
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
                findShared.m_Parameter0 = tValue;
            }
            else
            {
                findShared.m_Parameter1 = tValue;
            }
            ++quantity;
            if (quantity == 2)
            {
                if (findShared.m_Parameter1 < findShared.m_Parameter0)
                {
                    std::swap(findShared.m_Parameter0, findShared.m_Parameter1);
                }

                findShared.m_Quantity = 2;
                return findShared;
            }
        }
    }

    findShared.m_Quantity = quantity;
    return findShared;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_CAPSULE3_ACHIEVE_H
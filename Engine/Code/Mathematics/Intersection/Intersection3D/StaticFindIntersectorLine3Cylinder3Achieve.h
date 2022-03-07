///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.3 (2022/03/01 19:01)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CYLINDER3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CYLINDER3_ACHIEVE_H

#include "StaticFindIntersectorLine3Cylinder3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine3Cylinder3<Real>::StaticFindIntersectorLine3Cylinder3(const Line3& line, const Cylinder3& cylinder, const Real epsilon)
    : ParentType{ epsilon }, line{ line }, cylinder{ cylinder }, quantity{}, point0{}, point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorLine3Cylinder3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line3<Real> Mathematics::StaticFindIntersectorLine3Cylinder3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return line;
}

template <typename Real>
Mathematics::Cylinder3<Real> Mathematics::StaticFindIntersectorLine3Cylinder3<Real>::GetCylinder() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return cylinder;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine3Cylinder3<Real>::Find()
{
    const auto findShared = Find(line.GetOrigin(), line.GetDirection(), cylinder);
    quantity = findShared.quantity;

    if (quantity == 2)
    {
        point0 = line.GetOrigin() + findShared.parameter0 * line.GetDirection();
        point1 = line.GetOrigin() + findShared.parameter1 * line.GetDirection();
        this->SetIntersectionType(IntersectionType::Segment);
    }
    else if (quantity == 1)
    {
        point0 = line.GetOrigin() + findShared.parameter0 * line.GetDirection();
        this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine3Cylinder3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::StaticFindIntersectorLine3Cylinder3<Real>::GetPoint(int index) const
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
typename Mathematics::StaticFindIntersectorLine3Cylinder3<Real>::FindShared Mathematics::StaticFindIntersectorLine3Cylinder3<Real>::Find(const Vector3& origin, const Vector3& dir, const Cylinder3& cylinder)
{
    FindShared findShared{};

    /// ΪԲ����������ϵ�� �ڸ�ϵͳ�У�ԲͲ�߶�����CΪԭ�㣬ԲͲ�᷽��WΪz�ᡣ U��V�����������᷽��
    /// ���P = x * U + y * V + z * W����Բ����Ϊx^2 + y^2 = r^2������rΪԲ����뾶��
    /// �˸�Ϊ |z| = h/2������h��Բ����߶ȡ�
    const auto wVector = cylinder.GetAxis().GetDirection();
    const auto generateComplementBasis = Vector3Tools::GenerateComplementBasis(wVector);
    const auto uVector = generateComplementBasis.GetUVector();
    const auto vVector = generateComplementBasis.GetVVector();

    auto halfHeight = Math::GetRational(1, 2) * cylinder.GetHeight();
    auto radiusSqr = cylinder.GetRadius() * cylinder.GetRadius();

    // ��������ԭ��ת��ΪԲ������
    auto diff = origin - cylinder.GetAxis().GetOrigin();
    const Vector3 point{ Vector3Tools::DotProduct(uVector, diff), Vector3Tools::DotProduct(vVector, diff), Vector3Tools::DotProduct(wVector, diff) };

    // ��ȡ�����ߵĵ�λ���ȷ����zֵ����Բ�������ʾ����
    auto dirZ = Vector3Tools::DotProduct(wVector, dir);

    if (Math::GetValue(1) - Math::GetZeroTolerance() <= Math::FAbs(dirZ))
    {
        // ����ƽ����Բ���ᡣ ȷ�������Ƿ���ԲͲ�����ཻ��
        auto radialSqrDist = radiusSqr - point.GetX() * point.GetX() - point.GetY() * point.GetY();
        if (radialSqrDist < Math::GetValue(0))
        {
            // ����Բ�������棬û���ཻ��
            return findShared;
        }

        // ����ԲͲ�����ཻ��
        if (Math::GetValue(0) < dirZ)
        {
            findShared.parameter0 = -point.GetZ() - halfHeight;
            findShared.parameter1 = -point.GetZ() + halfHeight;
        }
        else
        {
            findShared.parameter0 = point.GetZ() - halfHeight;
            findShared.parameter1 = point.GetZ() + halfHeight;
        }

        findShared.quantity = 2;
        return findShared;
    }

    // �������ߵ�λ���ȷ���ת��ΪԲ������
    const Vector3 direction{ Vector3Tools::DotProduct(uVector, dir), Vector3Tools::DotProduct(vVector, dir), dirZ };

    if (Math::FAbs(direction.GetZ()) <= Math::GetZeroTolerance())
    {
        // ���ߴ�ֱ��Բ���ᡣ
        if (halfHeight < Math::FAbs(point.GetZ()))
        {
            // ����ԲͲ���̵�ƽ��֮�⡣
            return findShared;
        }

        // ������P + t * D������Բ��x^2 + y^2 = r^2�Ľ��㡣
        // ���Ϊ������η���ʽ�ĸ��� ��� P = (px,py,pz) ��D = (dx,dy,dz)��
        // ����η���Ϊ (dx^2 + dy^2) * t^2 + 2 * (px * dx + py * dy) * t + (px^2 + py^2 - r^2) = 0
        auto a0 = point.GetX() * point.GetX() + point.GetY() * point.GetY() - radiusSqr;
        auto a1 = point.GetX() * direction.GetX() + point.GetY() * direction.GetY();
        auto a2 = direction.GetX() * direction.GetX() + direction.GetY() * direction.GetY();
        auto discr = a1 * a1 - a0 * a2;
        if (discr < Math::GetValue(0))
        {
            // �߲���Բ���ཻ��
            return findShared;
        }
        else if (Math::GetZeroTolerance() < discr)
        {
            // ��������λ����Բ���ཻ��
            auto root = Math::Sqrt(discr);
            auto inv = Math::GetValue(1) / a2;
            findShared.parameter0 = (-a1 - root) * inv;
            findShared.parameter1 = (-a1 + root) * inv;
            findShared.quantity = 2;
            return findShared;
        }
        else
        {
            // ����Բ�����С�
            findShared.parameter0 = -a1 / a2;
            findShared.quantity = 1;
            return findShared;
        }
    }

    // ���Ȳ���ƽ���ཻ�㡣
    int quantity = 0;

    auto t0 = (-halfHeight - point.GetZ()) / direction.GetZ();
    auto x = point.GetX() + t0 * direction.GetX();
    auto y = point.GetY() + t0 * direction.GetY();
    if (x * x + y * y <= radiusSqr)
    {
        // ����ԲͲ�����ڲ���ƽ�潻�㡣
        findShared.parameter0 = t0;
        ++quantity;
    }

    auto t1 = (+halfHeight - point.GetZ()) / direction.GetZ();
    x = point.GetX() + t1 * direction.GetX();
    y = point.GetY() + t1 * direction.GetY();
    if (x * x + y * y <= radiusSqr)
    {
        // �ײ�ԲͲ�����ڲ���ƽ�潻�㡣
        if (quantity == 0)
        {
            findShared.parameter0 = t1;
        }
        else
        {
            findShared.parameter1 = t1;
        }
        ++quantity;
    }

    if (quantity == 2)
    {
        // ���붥���͵ײ�ԲͲ�����ཻ��
        if (findShared.parameter1 < findShared.parameter0)
        {
            std::swap(findShared.parameter0, findShared.parameter1);
        }
        findShared.quantity = quantity;
        return findShared;
    }

    /// ���quantity == 1������߱����ڶ���֮���ĳ������Բ�����ཻ��
    /// �����´����м�⵽����������ô����������Բ����֮����ཻ��
    auto a0 = point.GetX() * point.GetX() + point.GetY() * point.GetY() - radiusSqr;
    auto a1 = point.GetX() * direction.GetX() + point.GetY() * direction.GetY();
    auto a2 = direction.GetX() * direction.GetX() + direction.GetY() * direction.GetY();
    auto discr = a1 * a1 - a0 * a2;
    if (discr < Math::GetValue(0))
    {
        // �߲���ԲͲ���ཻ��
        MATHEMATICS_ASSERTION_0(quantity == 0, "����״��\n");
        return findShared;
    }
    else if (Math::GetZeroTolerance() < discr)
    {
        auto root = Math::Sqrt(discr);
        auto tValue = (-a1 - root) / a2;
        if (t0 <= t1)
        {
            if (t0 <= tValue && tValue <= t1)
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
        }
        else
        {
            if (t1 <= tValue && tValue <= t0)
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
        }

        if (quantity == 2)
        {
            // ����ԲͲ����֮һ�ཻ������ԲͲ���ཻ��
            if (findShared.parameter1 < findShared.parameter0)
            {
                std::swap(findShared.parameter0, findShared.parameter1);
            }
            findShared.quantity = quantity;
            return findShared;
        }

        tValue = (-a1 + root) / a2;
        if (t0 <= t1)
        {
            if (t0 <= tValue && tValue <= t1)
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
        }
        else
        {
            if (t1 <= tValue && tValue <= t0)
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
        }
    }
    else
    {
        auto tValue = -a1 / a2;
        if (t0 <= t1)
        {
            if (t0 <= tValue && tValue <= t1)
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
        }
        else
        {
            if (t1 <= tValue && tValue <= t0)
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
        }
    }

    if (quantity == 2)
    {
        if (findShared.parameter1 < findShared.parameter0)
        {
            std::swap(findShared.parameter0, findShared.parameter1);
        }
    }

    findShared.quantity = quantity;

    return findShared;
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CYLINDER3_ACHIEVE_H

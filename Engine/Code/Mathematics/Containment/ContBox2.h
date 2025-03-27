///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/09 09:41)

#ifndef MATHEMATICS_CONTAINMENT_CONT_BOX2_H
#define MATHEMATICS_CONTAINMENT_CONT_BOX2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Box2.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class ContBox2 final
    {
    public:
        using ClassType = ContBox2<Real>;
        using Vector2Type = Vector2<Real>;
        using Points = std::vector<Vector2Type>;
        using Box2Type = Box2<Real>;
        using MathType = Math<Real>;

    public:
        ContBox2() noexcept;

        CLASS_INVARIANT_DECLARE;

    public:
        // ��������С��������Χ�С�
        NODISCARD static Box2Type ContAlignedBox(const Points& points);

        // �����Ķ���߽�򡣰�Χ�������ǵ��ƽ��ֵ��
        // ��Χ�е�����Э������������������
        static Box2Type ContOrientedBox(const Points& points);

        // ���������
        // ��X = C + y0 * U0 + y1 * U1������C�ǰ�Χ�е����ĺ�U0��U1�Ǻ��ӵ������ᡣ
        // ���|y_i| <= E_i ,���������i�ڿ��У�����E_i�ǰ�Χ�еķ�Χ��
        NODISCARD static bool InBox(const Vector2Type& point, const Box2Type& box);

        // ��������������������Χ�еĶ����Χ�С�
        // �������ܱ�֤�ǰ��������Χ�е���С�����Χ�С�
        NODISCARD static Box2Type MergeBoxes(const Box2Type& lhs, const Box2Type& rhs);
    };

    using ContBox2D = ContBox2<double>;
    using ContBox2F = ContBox2<float>;
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_BOX2_H

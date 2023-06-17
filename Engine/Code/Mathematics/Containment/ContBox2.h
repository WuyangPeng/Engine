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
        using Vector2 = Vector2<Real>;
        using Points = std::vector<Vector2>;
        using Box2 = Box2<Real>;
        using Math = Math<Real>;

    public:
        ContBox2() noexcept;

        CLASS_INVARIANT_DECLARE;

    public:
        // ��������С��������Χ�С�
        NODISCARD static Box2 ContAlignedBox(const Points& points);

        // �����Ķ���߽�򡣰�Χ�������ǵ��ƽ��ֵ��
        // ��Χ�е�����Э������������������
        static Box2 ContOrientedBox(const Points& points);

        // ���������
        // ��X = C + y0 * U0 + y1 * U1������C�ǰ�Χ�е����ĺ�U0��U1�Ǻ��ӵ������ᡣ
        // ���|y_i| <= E_i ,���������i�ڿ��У�����E_i�ǰ�Χ�еķ�Χ��
        NODISCARD static bool InBox(const Vector2& point, const Box2& box);

        // ��������������������Χ�еĶ����Χ�С�
        // �������ܱ�֤�ǰ��������Χ�е���С�����Χ�С�
        NODISCARD static Box2 MergeBoxes(const Box2& lhs, const Box2& rhs);
    };

    using ContBox2D = ContBox2<double>;
    using ContBox2F = ContBox2<float>;
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_BOX2_H

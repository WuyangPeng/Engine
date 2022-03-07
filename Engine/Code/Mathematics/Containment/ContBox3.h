// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.2 (2019/07/17 16:15)

#ifndef MATHEMATICS_CONTAINMENT_CONT_BOX3_H
#define MATHEMATICS_CONTAINMENT_CONT_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Box3.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class ContBox3
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = ContBox3<Real>;
        using Vector3 = Vector3<Real>;
        using Points = std::vector<Vector3>;
        using Box3 = Box3<Real>;
        using Math = Math<Real>;

    public:
        ContBox3() noexcept;

        CLASS_INVARIANT_DECLARE;

        // ��������С��������Χ�С�
        static const Box3 ContAlignedBox(const Points& points);

        // �����Ķ���߽�򡣰�Χ�������ǵ��ƽ��ֵ��
        // ��Χ�е�����Э������������������
        static const Box3 ContOrientedBox(const Points& points);

        // ���������
        // ��X = C + y0 * U0 + y1 * U1 + y2 * U2������C�ǰ�Χ�е����ĺ�U0,U1��U2�Ǻ��ӵ������ᡣ
        // ���|y_i| <= E_i ,���������i�ڿ��У�����E_i�ǰ�Χ�еķ�Χ��
        static bool InBox(const Vector3& point, const Box3& box);

        // ��������������������Χ�еĶ����Χ�С�
        // �������ܱ�֤�ǰ��������Χ�е���С�����Χ�С�
        static const Box3 MergeBoxes(const Box3& lhs, const Box3& rhs);
    };

    using ContBox3d = ContBox3<double>;
    using ContBox3f = ContBox3<float>;
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_BOX3_H

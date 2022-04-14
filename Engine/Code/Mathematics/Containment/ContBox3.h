///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.4 (2022/03/10 11:19)

#ifndef MATHEMATICS_CONTAINMENT_CONT_BOX3_H
#define MATHEMATICS_CONTAINMENT_CONT_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Box3.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class ContBox3 final
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
        NODISCARD static Box3 ContAlignedBox(const Points& points);

        // �����Ķ���߽�򡣰�Χ�������ǵ��ƽ��ֵ��
        // ��Χ�е�����Э������������������
        NODISCARD static Box3 ContOrientedBox(const Points& points);

        // ���������
        // ��X = C + y0 * U0 + y1 * U1 + y2 * U2������C�ǰ�Χ�е����ĺ�U0,U1��U2�Ǻ��ӵ������ᡣ
        // ���|y_i| <= E_i ,���������i�ڿ��У�����E_i�ǰ�Χ�еķ�Χ��
        NODISCARD static bool InBox(const Vector3& point, const Box3& box);

        // ��������������������Χ�еĶ����Χ�С�
        // �������ܱ�֤�ǰ��������Χ�е���С�����Χ�С�
        NODISCARD static Box3 MergeBoxes(const Box3& lhs, const Box3& rhs);
    };

    using ContBox3D = ContBox3<double>;
    using ContBox3F = ContBox3<float>;
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_BOX3_H

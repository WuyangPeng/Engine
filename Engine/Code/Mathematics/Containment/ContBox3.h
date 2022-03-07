// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.2 (2019/07/17 16:15)

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

        // 计算点的最小的轴对齐包围盒。
        static const Box3 ContAlignedBox(const Points& points);

        // 计算点的定向边界框。包围盒中心是点的平均值。
        // 包围盒的轴是协方差矩阵的特征向量。
        static const Box3 ContOrientedBox(const Points& points);

        // 试验包含。
        // 设X = C + y0 * U0 + y1 * U1 + y2 * U2，其中C是包围盒的中心和U0,U1和U2是盒子的正交轴。
        // 如果|y_i| <= E_i ,则对于所有i在框中，这里E_i是包围盒的范围。
        static bool InBox(const Vector3& point, const Box3& box);

        // 构造包含另外两个定向包围盒的定向包围盒。
        // 其结果不能保证是包含输入包围盒的最小体积包围盒。
        static const Box3 MergeBoxes(const Box3& lhs, const Box3& rhs);
    };

    using ContBox3d = ContBox3<double>;
    using ContBox3f = ContBox3<float>;
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_BOX3_H

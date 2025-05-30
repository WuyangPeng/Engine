///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:42)

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
        using Vector3Type = Vector3<Real>;
        using Points = std::vector<Vector3Type>;
        using Box3Type = Box3<Real>;
        using MathType = Math<Real>;

    public:
        ContBox3() noexcept;

        CLASS_INVARIANT_DECLARE;

        // 计算点的最小的轴对齐包围盒。
        NODISCARD static Box3Type ContAlignedBox(const Points& points);

        // 计算点的定向边界框。包围盒中心是点的平均值。
        // 包围盒的轴是协方差矩阵的特征向量。
        NODISCARD static Box3Type ContOrientedBox(const Points& points);

        // 试验包含。
        // 设X = C + y0 * U0 + y1 * U1 + y2 * U2，其中C是包围盒的中心和U0,U1和U2是盒子的正交轴。
        // 如果|y_i| <= E_i ,则对于所有i在框中，这里E_i是包围盒的范围。
        NODISCARD static bool InBox(const Vector3Type& point, const Box3Type& box);

        // 构造包含另外两个定向包围盒的定向包围盒。
        // 其结果不能保证是包含输入包围盒的最小体积包围盒。
        NODISCARD static Box3Type MergeBoxes(const Box3Type& lhs, const Box3Type& rhs);
    };

    using ContBox3D = ContBox3<double>;
    using ContBox3F = ContBox3<float>;
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_BOX3_H

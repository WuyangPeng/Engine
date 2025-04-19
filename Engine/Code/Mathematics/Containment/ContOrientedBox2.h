/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/07 14:41)

#ifndef MATHEMATICS_CONTAINMENT_CONT_ORIENTED_BOX2_H
#define MATHEMATICS_CONTAINMENT_CONT_ORIENTED_BOX2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector/Vector2.h"
#include "Mathematics/Primitives/OrientedBox.h"

namespace Mathematics
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class ContOrientedBox2
    {
    public:
        using ClassType = ContOrientedBox2<Real>;

        using Vector2 = Algebra::Vector2<Real>;
        using Vector2Container = std::vector<Vector2>;
        using OrientedBox2 = Algebra::OrientedBox2<Real>;
        using MathType = Math<Real>;

    public:
        ContOrientedBox2() noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 计算点的定向边界框。
        /// 方框中心是这些点的平均值。
        /// 框轴是协方差矩阵的特征向量。
        NODISCARD static bool GetContainer(const Vector2Container& points, OrientedBox2& box);

        /// 安全壳试验。
        /// 设X = C + y0*U0 + y1*U1，其中C是长方体中心，U0和U1是长方体的正交轴。
        /// 当|y_i| <= E_i表示所有i时，X在框中，其中E_i是框的范围。
        NODISCARD static bool InContainer(const Vector2& point, const OrientedBox2& box);

        /// 构造一个包含另外两个定向长方体的定向长方体。
        /// 不能保证结果是包含输入框的最小面积框。
        NODISCARD static bool MergeContainers(const OrientedBox2& box0,
                                              const OrientedBox2& box1,
                                              OrientedBox2& merge);
    };
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_ORIENTED_BOX2_H

///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/05 10:38)

// 轴对齐包围盒4D类的声明
#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_4D_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_4D_H

#include "Mathematics/MathematicsDll.h"

#include "Vector4D.h"

namespace Mathematics
{
    template <typename T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AxesAlignBoundingBox4D final
    {
    public:
        static_assert(std::is_arithmetic_v<T>, "T must be arithmetic.");

        using ClassType = AxesAlignBoundingBox4D<T>;
        using Vector4D = Vector4D<T>;

    public:
        explicit AxesAlignBoundingBox4D(const Vector4D& minPoint, const Vector4D& maxPoint);

        template <typename RhsType>
        AxesAlignBoundingBox4D(const AxesAlignBoundingBox4D<RhsType>& aabb);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector4D GetMinPoint() const noexcept;
        [[nodiscard]] const Vector4D GetMaxPoint() const noexcept;

    private:
        void Recalculate();

    private:
        Vector4D m_MinPoint;
        Vector4D m_MaxPoint;
    };

    using FloatAxesAlignBoundingBox4D = AxesAlignBoundingBox4D<float>;
    using DoubleAxesAlignBoundingBox4D = AxesAlignBoundingBox4D<double>;
}

#endif  // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_4D_H
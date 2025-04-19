///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 14:42)

#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX4_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX4_H

#include "Mathematics/MathematicsDll.h"

#include "Vector4.h"

namespace Mathematics
{
    template <typename T>
    requires std::is_arithmetic_v<T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AxesAlignBoundingBox4 final
    {
    public:
        using ClassType = AxesAlignBoundingBox4<T>;

        using Vector4Type = Vector4<T>;

    public:
        AxesAlignBoundingBox4(const Vector4Type& minPoint, const Vector4Type& maxPoint) noexcept;

        template <typename RhsType>
        explicit AxesAlignBoundingBox4(const AxesAlignBoundingBox4<RhsType>& aabb);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsBoxValid() const noexcept;

        NODISCARD Vector4Type GetMinPoint() const noexcept;
        NODISCARD Vector4Type GetMaxPoint() const noexcept;

    private:
        Vector4Type minPoint;
        Vector4Type maxPoint;
    };

    using AxesAlignBoundingBox4F = AxesAlignBoundingBox4<float>;
    using AxesAlignBoundingBox4D = AxesAlignBoundingBox4<double>;
}

#endif  // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX4_H
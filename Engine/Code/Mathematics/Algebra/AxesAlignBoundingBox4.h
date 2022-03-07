///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/02 22:39)

#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX4_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX4_H

#include "Mathematics/MathematicsDll.h"

#include "Vector4.h"

namespace Mathematics
{
    template <typename T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AxesAlignBoundingBox4 final
    {
    public:
        static_assert(std::is_arithmetic_v<T>, "T must be arithmetic.");

        using ClassType = AxesAlignBoundingBox4<T>;
        using Vector4 = Vector4<T>;

    public:
        AxesAlignBoundingBox4(const Vector4& minPoint, const Vector4& maxPoint) noexcept;

        template <typename RhsType>
        AxesAlignBoundingBox4(const AxesAlignBoundingBox4<RhsType>& aabb);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsBoxValid() const noexcept;

        NODISCARD Vector4 GetMinPoint() const noexcept;
        NODISCARD Vector4 GetMaxPoint() const noexcept;

    private:
        Vector4 minPoint;
        Vector4 maxPoint;
    };

    using AxesAlignBoundingBox4F = AxesAlignBoundingBox4<float>;
    using AxesAlignBoundingBox4D = AxesAlignBoundingBox4<double>;
}

#endif  // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX4_H
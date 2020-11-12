///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/12 16:03)

// 4D向量工具类的声明
// 当向量存储的值为浮点数时，比较两向量相等，
// 请使用函数Approximate，而不是==。
// == 仅用于STL
#ifndef MATHEMATICS_ALGEBRA_VECTOR_4D_TOOLS_H
#define MATHEMATICS_ALGEBRA_VECTOR_4D_TOOLS_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox4D.h"
#include "Mathematics/Base/MathDetail.h"

#include <iosfwd>
#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector4DTools final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Vector4DTools;
        using Math = Math<Real>;
        using Vector4D = Vector4D<Real>;
        using AxesAlignBoundingBox4D = AxesAlignBoundingBox4D<Real>;
        using ContainerType = std::vector<Vector4D>;

    public:
        [[nodiscard]] static bool Approximate(const Vector4D& lhs, const Vector4D& rhs, const Real epsilon = Math::GetZeroTolerance()) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        [[nodiscard]] static Real VectorMagnitude(const Vector4D& vector) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        [[nodiscard]] static Real VectorMagnitudeSquared(const Vector4D& vector) noexcept;
        [[nodiscard]] static Real Distance(const Vector4D& lhs, const Vector4D& rhs) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        [[nodiscard]] static Real DistanceSquared(const Vector4D& lhs, const Vector4D& rhs) noexcept;
        [[nodiscard]] static Real DotProduct(const Vector4D& lhs, const Vector4D& rhs) noexcept;

        [[nodiscard]] static const Vector4D ParallelVectorLhsToRhs(const Vector4D& lhs, const Vector4D& rhs, const Real epsilon = Math::GetZeroTolerance());
        [[nodiscard]] static const Vector4D ApeakVectorLhsToRhs(const Vector4D& lhs, const Vector4D& rhs, const Real epsilon = Math::GetZeroTolerance());
        [[nodiscard]] static Real GetVectorIncludedAngle(const Vector4D& lhs, const Vector4D& rhs) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // 计算点的轴对齐包围盒。
        [[nodiscard]] static const AxesAlignBoundingBox4D ComputeExtremes(const ContainerType& vectors);
    };

    // STL
    template <typename Real>
    [[nodiscard]] bool operator==(const Vector4D<Real>& lhs, const Vector4D<Real>& rhs);

    template <typename Real>
    [[nodiscard]] bool operator<(const Vector4D<Real>& lhs, const Vector4D<Real>& rhs);

    // 调试输出。
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Vector4D<Real>& vector);

    using FloatVector4DTools = Vector4DTools<float>;
    using DoubleVector4DTools = Vector4DTools<double>;
};

#endif  // MATHEMATICS_ALGEBRA_VECTOR_4D_TOOLS_H

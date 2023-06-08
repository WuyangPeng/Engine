///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/01 10:49)

#ifndef MATHEMATICS_ALGEBRA_VECTOR4_TOOLS_H
#define MATHEMATICS_ALGEBRA_VECTOR4_TOOLS_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox4.h"
#include "Mathematics/Base/MathDetail.h"

#include <iosfwd>
#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector4Tools final
    {
    public:
        using ClassType = Vector4Tools;

        using Math = Math<Real>;
        using Vector3 = Vector3<Real>;
        using Vector4 = Vector4<Real>;
        using AxesAlignBoundingBox4D = AxesAlignBoundingBox4<Real>;
        using ContainerType = std::vector<Vector4>;

    public:
        NODISCARD static bool Approximate(const Vector4& lhs, const Vector4& rhs, Real epsilon = Math::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        NODISCARD static Real GetRobustLength(const Vector4& vector);
        NODISCARD static Real GetLength(const Vector4& vector) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        NODISCARD static Real GetLengthSquared(const Vector4& vector) noexcept;
        NODISCARD static Real Distance(const Vector4& lhs, const Vector4& rhs) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        NODISCARD static Real DistanceSquared(const Vector4& lhs, const Vector4& rhs) noexcept;
        NODISCARD static Real DotProduct(const Vector4& lhs, const Vector4& rhs) noexcept;

        NODISCARD static Vector4 ParallelVectorLhsToRhs(const Vector4& lhs, const Vector4& rhs, Real epsilon = Math::GetZeroTolerance());
        NODISCARD static Vector4 ApeakVectorLhsToRhs(const Vector4& lhs, const Vector4& rhs, Real epsilon = Math::GetZeroTolerance());
        NODISCARD static Real GetVectorIncludedAngle(const Vector4& lhs, const Vector4& rhs) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // 计算点的轴对齐包围盒。
        NODISCARD static AxesAlignBoundingBox4D ComputeExtremes(const ContainerType& vectors);

        NODISCARD static Vector3 ProjectHomogeneous(const Vector4& vector) noexcept;
        NODISCARD static Vector3 Project(const Vector4& vector, int reject);

        NODISCARD static Vector4 HyperCross(const Vector4& v0, const Vector4& v1, const Vector4& v2);
        NODISCARD static Vector4 UnitHyperCross(const Vector4& v0, const Vector4& v1, const Vector4& v2, bool robust = false, const Real epsilon = Math::GetZeroTolerance());
        NODISCARD static Real DotHyperCross(const Vector4& v0, const Vector4& v1, const Vector4& v2, const Vector4& v3);

        NODISCARD static Real ComputeOrthogonalComplement(const ContainerType& container, bool robust = false, Real epsilon = Math::GetZeroTolerance());
        NODISCARD static Real Orthonormalize(const ContainerType& container, bool robust = false, Real epsilon = Math::GetZeroTolerance());
    };

    using Vector4ToolsF = Vector4Tools<float>;
    using Vector4ToolsD = Vector4Tools<double>;
};

#endif  // MATHEMATICS_ALGEBRA_VECTOR4_TOOLS_H

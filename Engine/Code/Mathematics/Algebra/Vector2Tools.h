///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 15:15)

#ifndef MATHEMATICS_ALGEBRA_VECTOR2_TOOLS_H
#define MATHEMATICS_ALGEBRA_VECTOR2_TOOLS_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "AxesAlignBoundingBox2.h"
#include "Vector2OrthonormalBasis.h"
#include "Vector2Orthonormalize.h"
#include "Mathematics/Base/MathDetail.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector2Tools final
    {
    public:
        using ClassType = Vector2Tools<Real>;

        using Vector2 = Vector2<Real>;
        using Vector3 = Vector3<Real>;
        using Math = Math<Real>;
        using Vector2Orthonormalize = Vector2Orthonormalize<Real>;
        using Vector2OrthonormalBasis = Vector2OrthonormalBasis<Real>;
        using AxesAlignBoundingBox2 = AxesAlignBoundingBox2<Real>;
        using ContainerType = std::vector<Vector2>;

    public:
        NODISCARD static bool Approximate(const Vector2& lhs, const Vector2& rhs, Real epsilon = Math::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        NODISCARD static Real GetRobustLength(const Vector2& vector);
        NODISCARD static Real GetLength(const Vector2& vector) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        NODISCARD static Real GetLengthSquared(const Vector2& vector) noexcept;
        NODISCARD static Real Distance(const Vector2& lhs, const Vector2& rhs) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        NODISCARD static Real DistanceSquared(const Vector2& lhs, const Vector2& rhs) noexcept;
        NODISCARD static Real DotProduct(const Vector2& lhs, const Vector2& rhs) noexcept;

        // 即DotPerp
        NODISCARD static Real PseudoCrossProduct(const Vector2& lhs, const Vector2& rhs) noexcept;

        NODISCARD static Vector2 ParallelVectorLhsToRhs(const Vector2& lhs, const Vector2& rhs, Real epsilon = Math::GetZeroTolerance());
        NODISCARD static Vector2 ApeakVectorLhsToRhs(const Vector2& lhs, const Vector2& rhs, Real epsilon = Math::GetZeroTolerance());
        NODISCARD static Real GetVectorIncludedAngle(const Vector2& lhs, const Vector2& rhs) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // 垂直线相关
        // 返回 (y,-x).
        NODISCARD static Vector2 GetPerp(const Vector2& vector) noexcept;

        // 返回 (y,-x) / sqrt(x * x + y * y).
        NODISCARD static Vector2 GetUnitPerp(const Vector2& vector, Real epsilon = Math::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // 返回 DotPerp((lhs.x,lhs.y),(rhs.x,rhs.y)) = lhs.x * rhs.y - lhs.y * rhs.x.
        NODISCARD static Real DotPerp(const Vector2& lhs, const Vector2& rhs) noexcept;

        // 计算点的轴对齐包围盒。
        NODISCARD static AxesAlignBoundingBox2 ComputeExtremes(const ContainerType& vectors);

        // Gram-Schmidt正交化。
        // 以线性无关的向量U和V，来计算一个正交组（单位长度，相互垂直）。
        NODISCARD static Vector2Orthonormalize Orthonormalize(const Vector2& lhs, const Vector2& rhs, Real epsilon = Math::GetZeroTolerance());

        // 输入值nonzeroVector（V）必须是一个非零向量。
        // 返回值是一个标准正交基{U，V}。
        // 返回的V为通过此函数正则化的nonzeroVector。
        // 如果你已知V是单位长度，使用U = GetPerp(V)。
        NODISCARD static Vector2OrthonormalBasis GenerateOrthonormalBasis(const Vector2& nonzeroVector, Real epsilon = Math::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        NODISCARD static Vector3 LiftHomogeneous(const Vector2& vector, Real last) noexcept;
        NODISCARD static Vector3 Lift(const Vector2& vector, int inject, Real value);
    };

    using Vector2ToolsF = Vector2Tools<float>;
    using Vector2ToolsD = Vector2Tools<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR2_TOOLS_H

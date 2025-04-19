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

        using Vector2Type = Vector2<Real>;
        using Vector3Type = Vector3<Real>;
        using MathType = Math<Real>;
        using Vector2OrthonormalizeType = Vector2Orthonormalize<Real>;
        using Vector2OrthonormalBasisType = Vector2OrthonormalBasis<Real>;
        using AxesAlignBoundingBox2Type = AxesAlignBoundingBox2<Real>;
        using ContainerType = std::vector<Vector2Type>;

    public:
        NODISCARD static bool Approximate(const Vector2Type& lhs, const Vector2Type& rhs, Real epsilon = MathType::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        NODISCARD static Real GetRobustLength(const Vector2Type& vector);
        NODISCARD static Real GetLength(const Vector2Type& vector) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        NODISCARD static Real GetLengthSquared(const Vector2Type& vector) noexcept;
        NODISCARD static Real Distance(const Vector2Type& lhs, const Vector2Type& rhs) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        NODISCARD static Real DistanceSquared(const Vector2Type& lhs, const Vector2Type& rhs) noexcept;
        NODISCARD static Real DotProduct(const Vector2Type& lhs, const Vector2Type& rhs) noexcept;

        // 即DotPerp
        NODISCARD static Real PseudoCrossProduct(const Vector2Type& lhs, const Vector2Type& rhs) noexcept;

        NODISCARD static Vector2Type ParallelVectorLhsToRhs(const Vector2Type& lhs, const Vector2Type& rhs, Real epsilon = MathType::GetZeroTolerance());
        NODISCARD static Vector2Type ApeakVectorLhsToRhs(const Vector2Type& lhs, const Vector2Type& rhs, Real epsilon = MathType::GetZeroTolerance());
        NODISCARD static Real GetVectorIncludedAngle(const Vector2Type& lhs, const Vector2Type& rhs) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // 垂直线相关
        // 返回 (y,-x).
        NODISCARD static Vector2Type GetPerp(const Vector2Type& vector) noexcept;

        // 返回 (y,-x) / sqrt(x * x + y * y).
        NODISCARD static Vector2Type GetUnitPerp(const Vector2Type& vector, Real epsilon = MathType::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // 返回 DotPerp((lhs.x,lhs.y),(rhs.x,rhs.y)) = lhs.x * rhs.y - lhs.y * rhs.x.
        NODISCARD static Real DotPerp(const Vector2Type& lhs, const Vector2Type& rhs) noexcept;

        // 计算点的轴对齐包围盒。
        NODISCARD static AxesAlignBoundingBox2Type ComputeExtremes(const ContainerType& vectors);

        // Gram-Schmidt正交化。
        // 以线性无关的向量U和V，来计算一个正交组（单位长度，相互垂直）。
        NODISCARD static Vector2OrthonormalizeType Orthonormalize(const Vector2Type& lhs, const Vector2Type& rhs, Real epsilon = MathType::GetZeroTolerance());

        // 输入值nonzeroVector（V）必须是一个非零向量。
        // 返回值是一个标准正交基{U，V}。
        // 返回的V为通过此函数正则化的nonzeroVector。
        // 如果你已知V是单位长度，使用U = GetPerp(V)。
        NODISCARD static Vector2OrthonormalBasisType GenerateOrthonormalBasis(const Vector2Type& nonzeroVector, Real epsilon = MathType::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        NODISCARD static Vector3Type LiftHomogeneous(const Vector2Type& vector, Real last) noexcept;
        NODISCARD static Vector3Type Lift(const Vector2Type& vector, int inject, Real value);
    };

    using Vector2ToolsF = Vector2Tools<float>;
    using Vector2ToolsD = Vector2Tools<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR2_TOOLS_H

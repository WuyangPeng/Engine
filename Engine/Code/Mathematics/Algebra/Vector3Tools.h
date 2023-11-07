///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 15:17)

#ifndef MATHEMATICS_ALGEBRA_VECTOR3_TOOLS_H
#define MATHEMATICS_ALGEBRA_VECTOR3_TOOLS_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "AxesAlignBoundingBox3.h"
#include "Vector3OrthonormalBasis.h"
#include "Vector3Orthonormalize.h"
#include "Mathematics/Base/MathDetail.h"

#include <iosfwd>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector3Tools final
    {
    public:
        using ClassType = Vector3Tools<Real>;

        using Vector2 = Vector2<Real>;
        using Vector3 = Vector3<Real>;
        using Vector4 = Vector4<Real>;
        using Function = Real (*)(Real);
        using Math = Math<Real>;
        using AxesAlignBoundingBox3D = AxesAlignBoundingBox3<Real>;
        using Vector3Orthonormalize = Vector3Orthonormalize<Real>;
        using Vector3OrthonormalBasis = Vector3OrthonormalBasis<Real>;
        using ContainerType = std::vector<Vector3>;

    public:
        NODISCARD static bool Approximate(const Vector3& lhs, const Vector3& rhs, Real epsilon = Math::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        NODISCARD static Real GetRobustLength(const Vector3& vector);
        NODISCARD static Real GetLength(const Vector3& vector) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        NODISCARD static Real GetLengthSquared(const Vector3& vector) noexcept;
        NODISCARD static Real DotProduct(const Vector3& lhs, const Vector3& rhs) noexcept;

        // 叉积使用的是右手的规则计算。
        // 请注意，某些图形API使用左手的规则。
        // 如果你计算叉积使用这些函数，并将结果发送给一个期望用左手的API，
        // 您将需要更改的矢量符号（替换每个组件值c为-c）。
        NODISCARD static Vector3 CrossProduct(const Vector3& lhs, const Vector3& rhs) noexcept;
        NODISCARD static Vector3 CrossProductWithReduceMultiplication(const Vector3& lhs, const Vector3& rhs) noexcept;
        NODISCARD static Vector3 UnitCrossProduct(const Vector3& lhs, const Vector3& rhs, Real epsilon = Math::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        NODISCARD static Real Distance(const Vector3& lhs, const Vector3& rhs) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        NODISCARD static Real DistanceSquared(const Vector3& lhs, const Vector3& rhs) noexcept;
        NODISCARD static Vector3 ParallelVectorLhsToRhs(const Vector3& lhs, const Vector3& rhs, Real epsilon = Math::GetZeroTolerance());
        NODISCARD static Vector3 ApeakVectorLhsToRhs(const Vector3& lhs, const Vector3& rhs, Real epsilon = Math::GetZeroTolerance());
        NODISCARD static Vector3 ReflectionVector(const Vector3& ray, const Vector3& normal);
        NODISCARD static Vector3 RefractionVector(const Vector3& ray, const Vector3& normal, Real consistencyRatio);
        NODISCARD static Vector3 FeatheringOutZAxes(const Vector3& vector, Function function);
        NODISCARD static Vector3 TwistZAxes(const Vector3& vector, Function function);
        NODISCARD static Vector3 BendYAxes(const Vector3& vector, Real curvatureRadius, Real bendCenter, Real bendAreaMin, Real bendAreaMax) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        NODISCARD static Real ScalarTripleProduct(const Vector3& vector0, const Vector3& vector1, const Vector3& vector2) noexcept;
        NODISCARD static Real GetVectorIncludedAngle(const Vector3& lhs, const Vector3& rhs) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // 计算点的轴对齐包围盒。
        NODISCARD static AxesAlignBoundingBox3D ComputeExtremes(const ContainerType& vectors);

        // Gram-Schmidt正交化.
        // 以线性无关的向量U、V和W，来计算一个正交组（单位长度，相互垂直）。
        NODISCARD static Vector3Orthonormalize Orthonormalize(const Vector3& uVector,
                                                              const Vector3& vVector,
                                                              const Vector3& wVector,
                                                              const Real epsilon = Math::GetZeroTolerance());
        NODISCARD static Vector3Orthonormalize Orthonormalize(const ContainerType& vectors, Real epsilon = Math::GetZeroTolerance());

        // 输入值nonzeroVector（W）必须是一个非零向量。
        // 返回值是一个标准正交基{U，V, W}。
        // 返回的W为通过此函数正则化的nonzeroVector。
        // 如果你已知W是单位长度，使用GenerateComplementBasis来计算U和V。
        NODISCARD static Vector3OrthonormalBasis GenerateOrthonormalBasis(const Vector3& nonzeroVector, Real epsilon = Math::GetZeroTolerance());

        // 输入值nonzeroVector（W）必须是一个单位向量。
        // 返回值中的向量{U,V}是单位长度且互相垂直，
        // 且{U,V,W}是一个标准正交基。
        NODISCARD static Vector3OrthonormalBasis GenerateComplementBasis(const Vector3& unitVector, Real epsilon = Math::GetZeroTolerance());

        NODISCARD static Vector4 LiftHomogeneous(const Vector3& vector, Real last) noexcept;
        NODISCARD static Vector4 Lift(const Vector3& vector, int inject, Real value);
        NODISCARD static Vector2 ProjectHomogeneous(const Vector3& vector) noexcept;
        NODISCARD static Vector2 Project(const Vector3& vector, int reject);
    };

    using Vector3ToolsF = Vector3Tools<float>;
    using Vector3ToolsD = Vector3Tools<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR3_TOOLS_H

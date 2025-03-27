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

        using Vector2Type = Vector2<Real>;
        using Vector3Type = Vector3<Real>;
        using Vector4Type = Vector4<Real>;
        using Function = Real (*)(Real);
        using MathType = Math<Real>;
        using AxesAlignBoundingBox3D = AxesAlignBoundingBox3<Real>;
        using Vector3OrthonormalizeType = Vector3Orthonormalize<Real>;
        using Vector3OrthonormalBasisType = Vector3OrthonormalBasis<Real>;
        using ContainerType = std::vector<Vector3Type>;
        using ArrayType = std::array<Vector3Type, 3>;

    public:
        NODISCARD static bool Approximate(const Vector3Type& lhs, const Vector3Type& rhs, Real epsilon = MathType::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        NODISCARD static Real GetRobustLength(const Vector3Type& vector);
        NODISCARD static Real GetLength(const Vector3Type& vector) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        NODISCARD static Real GetLengthSquared(const Vector3Type& vector) noexcept;
        NODISCARD static Real DotProduct(const Vector3Type& lhs, const Vector3Type& rhs) noexcept;

        // 叉积使用的是右手的规则计算。
        // 请注意，某些图形API使用左手的规则。
        // 如果你计算叉积使用这些函数，并将结果发送给一个期望用左手的API，
        // 您将需要更改的矢量符号（替换每个组件值c为-c）。
        NODISCARD static Vector3Type CrossProduct(const Vector3Type& lhs, const Vector3Type& rhs) noexcept;
        NODISCARD static Vector3Type CrossProductWithReduceMultiplication(const Vector3Type& lhs, const Vector3Type& rhs) noexcept;
        NODISCARD static Vector3Type UnitCrossProduct(const Vector3Type& lhs, const Vector3Type& rhs, Real epsilon = MathType::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        NODISCARD static Real Distance(const Vector3Type& lhs, const Vector3Type& rhs) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        NODISCARD static Real DistanceSquared(const Vector3Type& lhs, const Vector3Type& rhs) noexcept;
        NODISCARD static Vector3Type ParallelVectorLhsToRhs(const Vector3Type& lhs, const Vector3Type& rhs, Real epsilon = MathType::GetZeroTolerance());
        NODISCARD static Vector3Type ApeakVectorLhsToRhs(const Vector3Type& lhs, const Vector3Type& rhs, Real epsilon = MathType::GetZeroTolerance());
        NODISCARD static Vector3Type ReflectionVector(const Vector3Type& ray, const Vector3Type& normal);
        NODISCARD static Vector3Type RefractionVector(const Vector3Type& ray, const Vector3Type& normal, Real consistencyRatio);
        NODISCARD static Vector3Type FeatheringOutZAxes(const Vector3Type& vector, Function function);
        NODISCARD static Vector3Type TwistZAxes(const Vector3Type& vector, Function function);
        NODISCARD static Vector3Type BendYAxes(const Vector3Type& vector, Real curvatureRadius, Real bendCenter, Real bendAreaMin, Real bendAreaMax) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        NODISCARD static Real ScalarTripleProduct(const Vector3Type& vector0, const Vector3Type& vector1, const Vector3Type& vector2) noexcept;
        NODISCARD static Real GetVectorIncludedAngle(const Vector3Type& lhs, const Vector3Type& rhs) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // 计算点的轴对齐包围盒。
        NODISCARD static AxesAlignBoundingBox3D ComputeExtremes(const ContainerType& vectors);

        // Gram-Schmidt正交化.
        // 以线性无关的向量U、V和W，来计算一个正交组（单位长度，相互垂直）。
        NODISCARD static Vector3OrthonormalizeType Orthonormalize(const Vector3Type& uVector,
                                                              const Vector3Type& vVector,
                                                              const Vector3Type& wVector,
                                                              const Real epsilon = MathType::GetZeroTolerance());
        NODISCARD static Vector3OrthonormalizeType Orthonormalize(const ContainerType& vectors, Real epsilon = MathType::GetZeroTolerance());

        // 输入值nonzeroVector（W）必须是一个非零向量。
        // 返回值是一个标准正交基{U，V, W}。
        // 返回的W为通过此函数正则化的nonzeroVector。
        // 如果你已知W是单位长度，使用GenerateComplementBasis来计算U和V。
        NODISCARD static Vector3OrthonormalBasisType GenerateOrthonormalBasis(const Vector3Type& nonzeroVector, Real epsilon = MathType::GetZeroTolerance());

        // 输入值nonzeroVector（W）必须是一个单位向量。
        // 返回值中的向量{U,V}是单位长度且互相垂直，
        // 且{U,V,W}是一个标准正交基。
        NODISCARD static Vector3OrthonormalBasisType GenerateComplementBasis(const Vector3Type& unitVector, Real epsilon = MathType::GetZeroTolerance());

        NODISCARD static Vector4Type LiftHomogeneous(const Vector3Type& vector, Real last) noexcept;
        NODISCARD static Vector4Type Lift(const Vector3Type& vector, int inject, Real value);
        NODISCARD static Vector2Type ProjectHomogeneous(const Vector3Type& vector) noexcept;
        NODISCARD static Vector2Type Project(const Vector3Type& vector, int reject);

        NODISCARD static Vector3OrthonormalizeType ComputeOrthogonalComplement(int numInputs, const ArrayType& vector);
    };

    using Vector3ToolsF = Vector3Tools<float>;
    using Vector3ToolsD = Vector3Tools<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR3_TOOLS_H

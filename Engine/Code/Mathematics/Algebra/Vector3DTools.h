///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/12 21:01)

// 3D向量工具类的声明
// 当向量存储的值为浮点数时，比较两向量相等，
// 请使用函数Approximate，而不是==。
// == 仅用于STL
#ifndef MATHEMATICS_ALGEBRA_VECTOR_3D_TOOLS_H
#define MATHEMATICS_ALGEBRA_VECTOR_3D_TOOLS_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "AxesAlignBoundingBox3D.h"
#include "Vector3DOrthonormalBasis.h"
#include "Vector3DOrthonormalize.h"
#include "Mathematics/Base/MathDetail.h"

#include <iosfwd>
#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector3DTools final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Vector3DTools<Real>;
        using Vector3D = Vector3D<Real>;
        using Function = Real (*)(Real);
        using Math = Math<Real>;
        using AxesAlignBoundingBox3D = AxesAlignBoundingBox3D<Real>;
        using Vector3DOrthonormalize = Vector3DOrthonormalize<Real>;
        using Vector3DOrthonormalBasis = Vector3DOrthonormalBasis<Real>;
        using ContainerType = std::vector<Vector3D>;

    public:
        [[nodiscard]] static bool Approximate(const Vector3D& lhs, const Vector3D& rhs, const Real epsilon = Math::GetZeroTolerance()) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        [[nodiscard]] static Real VectorMagnitude(const Vector3D& vector) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        [[nodiscard]] static Real VectorMagnitudeSquared(const Vector3D& vector) noexcept;
        [[nodiscard]] static Real DotProduct(const Vector3D& lhs, const Vector3D& rhs) noexcept;

        // 叉积使用的是右手的规则计算。
        // 请注意，某些图形API使用左手的规则。
        // 如果你计算叉积使用这些函数，并将结果发送给一个期望用左手的API，
        // 您将需要更改的矢量符号（替换每个组件值c为-c）。
        [[nodiscard]] static const Vector3D CrossProduct(const Vector3D& lhs, const Vector3D& rhs) noexcept;
        [[nodiscard]] static const Vector3D CrossProductWithReduceMultiplication(const Vector3D& lhs, const Vector3D& rhs) noexcept;
        [[nodiscard]] static const Vector3D UnitCrossProduct(const Vector3D& lhs, const Vector3D& rhs, const Real epsilon = Math::GetZeroTolerance()) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        [[nodiscard]] static Real Distance(const Vector3D& lhs, const Vector3D& rhs) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        [[nodiscard]] static Real DistanceSquared(const Vector3D& lhs, const Vector3D& rhs) noexcept;
        [[nodiscard]] static const Vector3D ParallelVectorLhsToRhs(const Vector3D& lhs, const Vector3D& rhs, const Real epsilon = Math::GetZeroTolerance());
        [[nodiscard]] static const Vector3D ApeakVectorLhsToRhs(const Vector3D& lhs, const Vector3D& rhs, const Real epsilon = Math::GetZeroTolerance());
        [[nodiscard]] static const Vector3D ReflectionVector(const Vector3D& ray, const Vector3D& normal);
        [[nodiscard]] static const Vector3D RefractionVector(const Vector3D& ray, const Vector3D& normal, Real consistencyRatio);
        [[nodiscard]] static const Vector3D FeatheringOutZAxes(const Vector3D& vector, Function function);
        [[nodiscard]] static const Vector3D TwistZAxes(const Vector3D& vector, Function function);
        [[nodiscard]] static const Vector3D BendYAxes(const Vector3D& vector, Real curvatureRadius, Real bendCenter, Real bendAreaMin, Real bendAreaMax) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        [[nodiscard]] static Real ScalarTripleProduct(const Vector3D& lhs, const Vector3D& mhs, const Vector3D& rhs) noexcept;
        [[nodiscard]] static Real GetVectorIncludedAngle(const Vector3D& lhs, const Vector3D& rhs) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // 计算点的轴对齐包围盒。
        [[nodiscard]] static const AxesAlignBoundingBox3D ComputeExtremes(const ContainerType& vectors);

        // Gram-Schmidt正交化.
        // 以线性无关的向量U、V和W，来计算一个正交组（单位长度，相互垂直）。
        [[nodiscard]] static const Vector3DOrthonormalize Orthonormalize(const Vector3D& lhs, const Vector3D& mhs, const Vector3D& rhs,
                                                                         const Real epsilon = Math::GetZeroTolerance());
        [[nodiscard]] static const Vector3DOrthonormalize Orthonormalize(const ContainerType& vectors, const Real epsilon = Math::GetZeroTolerance());

        // 输入值nonzeroVector（W）必须是一个非零向量。
        // 返回值是一个标准正交基{U，V, W}。
        // 返回的W为通过此函数正则化的nonzeroVector。
        // 如果你已知W是单位长度，使用GenerateComplementBasis来计算U和V。
        [[nodiscard]] static const Vector3DOrthonormalBasis GenerateOrthonormalBasis(const Vector3D& nonzeroVector, const Real epsilon = Math::GetZeroTolerance());

        // 输入值nonzeroVector（W）必须是一个单位向量。
        // 返回值中的向量{U,V}是单位长度且互相垂直，
        // 且{U,V,W}是一个标准正交基。
        [[nodiscard]] static const Vector3DOrthonormalBasis GenerateComplementBasis(const Vector3D& unitVector, const Real epsilon = Math::GetZeroTolerance());
    };

    // STL
    template <typename Real>
    [[nodiscard]] bool operator==(const Vector3D<Real>& lhs, const Vector3D<Real>& rhs);

    template <typename Real>
    [[nodiscard]] bool operator<(const Vector3D<Real>& lhs, const Vector3D<Real>& rhs);

    // 调试输出。
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Vector3D<Real>& vector);

    using FloatVector3DTools = Vector3DTools<float>;
    using DoubleVector3DTools = Vector3DTools<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_3D_TOOLS_H

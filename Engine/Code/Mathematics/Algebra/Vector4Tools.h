///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 15:17)

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

        using MathType = Math<Real>;
        using Vector3Type = Vector3<Real>;
        using Vector4Type = Vector4<Real>;
        using AxesAlignBoundingBox4D = AxesAlignBoundingBox4<Real>;
        using ContainerType = std::vector<Vector4Type>;

    public:
        NODISCARD static bool Approximate(const Vector4Type& lhs, const Vector4Type& rhs, Real epsilon = MathType::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        NODISCARD static Real GetRobustLength(const Vector4Type& vector);
        NODISCARD static Real GetLength(const Vector4Type& vector) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        NODISCARD static Real GetLengthSquared(const Vector4Type& vector) noexcept;
        NODISCARD static Real Distance(const Vector4Type& lhs, const Vector4Type& rhs) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        NODISCARD static Real DistanceSquared(const Vector4Type& lhs, const Vector4Type& rhs) noexcept;
        NODISCARD static Real DotProduct(const Vector4Type& lhs, const Vector4Type& rhs) noexcept;

        NODISCARD static Vector4Type ParallelVectorLhsToRhs(const Vector4Type& lhs, const Vector4Type& rhs, Real epsilon = MathType::GetZeroTolerance());
        NODISCARD static Vector4Type ApeakVectorLhsToRhs(const Vector4Type& lhs, const Vector4Type& rhs, Real epsilon = MathType::GetZeroTolerance());
        NODISCARD static Real GetVectorIncludedAngle(const Vector4Type& lhs, const Vector4Type& rhs) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // 计算点的轴对齐包围盒。
        NODISCARD static AxesAlignBoundingBox4D ComputeExtremes(const ContainerType& vectors);

        NODISCARD static Vector3Type ProjectHomogeneous(const Vector4Type& vector) noexcept;
        NODISCARD static Vector3Type Project(const Vector4Type& vector, int reject);

        NODISCARD static Vector4Type HyperCross(const Vector4Type& v0, const Vector4Type& v1, const Vector4Type& v2);
        NODISCARD static Vector4Type UnitHyperCross(const Vector4Type& v0, const Vector4Type& v1, const Vector4Type& v2, bool robust = false, const Real epsilon = MathType::GetZeroTolerance());
        NODISCARD static Real DotHyperCross(const Vector4Type& v0, const Vector4Type& v1, const Vector4Type& v2, const Vector4Type& v3);

        NODISCARD static Real ComputeOrthogonalComplement(const ContainerType& container, bool robust = false, Real epsilon = MathType::GetZeroTolerance());
        NODISCARD static Real Orthonormalize(const ContainerType& container, bool robust = false, Real epsilon = MathType::GetZeroTolerance());

        NODISCARD static Vector4Type CrossProduct(const Vector4Type& lhs, const Vector4Type& rhs) noexcept;
        NODISCARD static Vector4Type UnitCrossProduct(const Vector4Type& lhs, const Vector4Type& rhs, Real epsilon = MathType::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);
    };

    using Vector4ToolsF = Vector4Tools<float>;
    using Vector4ToolsD = Vector4Tools<double>;
};

#endif  // MATHEMATICS_ALGEBRA_VECTOR4_TOOLS_H

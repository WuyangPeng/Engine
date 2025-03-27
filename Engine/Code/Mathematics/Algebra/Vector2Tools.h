///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 15:15)

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

        // ��DotPerp
        NODISCARD static Real PseudoCrossProduct(const Vector2Type& lhs, const Vector2Type& rhs) noexcept;

        NODISCARD static Vector2Type ParallelVectorLhsToRhs(const Vector2Type& lhs, const Vector2Type& rhs, Real epsilon = MathType::GetZeroTolerance());
        NODISCARD static Vector2Type ApeakVectorLhsToRhs(const Vector2Type& lhs, const Vector2Type& rhs, Real epsilon = MathType::GetZeroTolerance());
        NODISCARD static Real GetVectorIncludedAngle(const Vector2Type& lhs, const Vector2Type& rhs) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // ��ֱ�����
        // ���� (y,-x).
        NODISCARD static Vector2Type GetPerp(const Vector2Type& vector) noexcept;

        // ���� (y,-x) / sqrt(x * x + y * y).
        NODISCARD static Vector2Type GetUnitPerp(const Vector2Type& vector, Real epsilon = MathType::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // ���� DotPerp((lhs.x,lhs.y),(rhs.x,rhs.y)) = lhs.x * rhs.y - lhs.y * rhs.x.
        NODISCARD static Real DotPerp(const Vector2Type& lhs, const Vector2Type& rhs) noexcept;

        // ������������Χ�С�
        NODISCARD static AxesAlignBoundingBox2Type ComputeExtremes(const ContainerType& vectors);

        // Gram-Schmidt��������
        // �������޹ص�����U��V��������һ�������飨��λ���ȣ��໥��ֱ����
        NODISCARD static Vector2OrthonormalizeType Orthonormalize(const Vector2Type& lhs, const Vector2Type& rhs, Real epsilon = MathType::GetZeroTolerance());

        // ����ֵnonzeroVector��V��������һ������������
        // ����ֵ��һ����׼������{U��V}��
        // ���ص�VΪͨ���˺������򻯵�nonzeroVector��
        // �������֪V�ǵ�λ���ȣ�ʹ��U = GetPerp(V)��
        NODISCARD static Vector2OrthonormalBasisType GenerateOrthonormalBasis(const Vector2Type& nonzeroVector, Real epsilon = MathType::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        NODISCARD static Vector3Type LiftHomogeneous(const Vector2Type& vector, Real last) noexcept;
        NODISCARD static Vector3Type Lift(const Vector2Type& vector, int inject, Real value);
    };

    using Vector2ToolsF = Vector2Tools<float>;
    using Vector2ToolsD = Vector2Tools<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR2_TOOLS_H

///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/03 14:28)

#ifndef MATHEMATICS_ALGEBRA_VECTOR2_TOOLS_H
#define MATHEMATICS_ALGEBRA_VECTOR2_TOOLS_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "AxesAlignBoundingBox2.h"
#include "Vector2OrthonormalBasis.h"
#include "Vector2Orthonormalize.h"
#include "Mathematics/Base/MathDetail.h"

#include <iosfwd>
#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector2Tools final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Vector2Tools<Real>;
        using Vector2 = Vector2<Real>;
        using Vector3 = Vector3<Real>;
        using Math = Math<Real>;
        using Vector2Orthonormalize = Vector2Orthonormalize<Real>;
        using Vector2OrthonormalBasis = Vector2OrthonormalBasis<Real>;
        using AxesAlignBoundingBox2 = AxesAlignBoundingBox2<Real>;
        using ContainerType = std::vector<Vector2>;

    public:
        NODISCARD static bool Approximate(const Vector2& lhs, const Vector2& rhs, const Real epsilon = Math::GetZeroTolerance()) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        NODISCARD static Real GetRobustLength(const Vector2& vector);
        NODISCARD static Real GetLength(const Vector2& vector) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        NODISCARD static Real GetLengthSquared(const Vector2& vector) noexcept;
        NODISCARD static Real Distance(const Vector2& lhs, const Vector2& rhs) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        NODISCARD static Real DistanceSquared(const Vector2& lhs, const Vector2& rhs) noexcept;
        NODISCARD static Real DotProduct(const Vector2& lhs, const Vector2& rhs) noexcept;

        // ��DotPerp
        NODISCARD static Real PseudoCrossProduct(const Vector2& lhs, const Vector2& rhs) noexcept;

        NODISCARD static Vector2 ParallelVectorLhsToRhs(const Vector2& lhs, const Vector2& rhs, const Real epsilon = Math::GetZeroTolerance());
        NODISCARD static Vector2 ApeakVectorLhsToRhs(const Vector2& lhs, const Vector2& rhs, const Real epsilon = Math::GetZeroTolerance());
        NODISCARD static Real GetVectorIncludedAngle(const Vector2& lhs, const Vector2& rhs) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // ��ֱ�����
        // ���� (y,-x).
        NODISCARD static Vector2 GetPerp(const Vector2& vector) noexcept;

        // ���� (y,-x) / sqrt(x * x + y * y).
        NODISCARD static Vector2 GetUnitPerp(const Vector2& vector, const Real epsilon = Math::GetZeroTolerance()) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // ���� DotPerp((lhs.x,lhs.y),(rhs.x,rhs.y)) = lhs.x * rhs.y - lhs.y * rhs.x.
        NODISCARD static Real DotPerp(const Vector2& lhs, const Vector2& rhs) noexcept;

        // ������������Χ�С�
        NODISCARD static AxesAlignBoundingBox2 ComputeExtremes(const ContainerType& vectors);

        // Gram-Schmidt��������
        // �������޹ص�����U��V��������һ�������飨��λ���ȣ��໥��ֱ����
        NODISCARD static Vector2Orthonormalize Orthonormalize(const Vector2& lhs, const Vector2& rhs, const Real epsilon = Math::GetZeroTolerance());

        // ����ֵnonzeroVector��V��������һ������������
        // ����ֵ��һ����׼������{U��V}��
        // ���ص�VΪͨ���˺������򻯵�nonzeroVector��
        // �������֪V�ǵ�λ���ȣ�ʹ��U = GetPerp(V)��
        NODISCARD static Vector2OrthonormalBasis GenerateOrthonormalBasis(const Vector2& nonzeroVector, const Real epsilon = Math::GetZeroTolerance()) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        NODISCARD static Vector3 LiftHomogeneous(const Vector2& vector, Real last) noexcept;
        NODISCARD static Vector3 Lift(const Vector2& vector, int inject, Real value);
    };

    using Vector2ToolsF = Vector2Tools<float>;
    using Vector2ToolsD = Vector2Tools<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR2_TOOLS_H

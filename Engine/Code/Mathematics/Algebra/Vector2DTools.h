///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/12 15:01)

// 2D���������������
// �������洢��ֵΪ������ʱ���Ƚ���������ȣ�
// ��ʹ�ú���Approximate��������==��
// == ������STL
#ifndef MATHEMATICS_ALGEBRA_VECTOR_2D_TOOLS_H
#define MATHEMATICS_ALGEBRA_VECTOR_2D_TOOLS_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "AxesAlignBoundingBox2D.h"
#include "Vector2DOrthonormalBasis.h"
#include "Vector2DOrthonormalize.h"
#include "Mathematics/Base/MathDetail.h"

#include <iosfwd>
#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector2DTools final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Vector2DTools<Real>;
        using Vector2D = Vector2D<Real>;
        using Math = Math<Real>;
        using Vector2DOrthonormalize = Vector2DOrthonormalize<Real>;
        using Vector2DOrthonormalBasis = Vector2DOrthonormalBasis<Real>;
        using AxesAlignBoundingBox2D = AxesAlignBoundingBox2D<Real>;
        using ContainerType = std::vector<Vector2D>;

    public:
        [[nodiscard]] static bool Approximate(const Vector2D& lhs, const Vector2D& rhs, const Real epsilon = Math::GetZeroTolerance()) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        [[nodiscard]] static Real VectorMagnitude(const Vector2D& vector) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        [[nodiscard]] static Real VectorMagnitudeSquared(const Vector2D& vector) noexcept;
        [[nodiscard]] static Real Distance(const Vector2D& lhs, const Vector2D& rhs) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        [[nodiscard]] static Real DistanceSquared(const Vector2D& lhs, const Vector2D& rhs) noexcept;
        [[nodiscard]] static Real DotProduct(const Vector2D& lhs, const Vector2D& rhs) noexcept;

        // ��DotPerp
        [[nodiscard]] static Real PseudoCrossProduct(const Vector2D& lhs, const Vector2D& rhs) noexcept;

        [[nodiscard]] static const Vector2D ParallelVectorLhsToRhs(const Vector2D& lhs, const Vector2D& rhs, const Real epsilon = Math::GetZeroTolerance());
        [[nodiscard]] static const Vector2D ApeakVectorLhsToRhs(const Vector2D& lhs, const Vector2D& rhs, const Real epsilon = Math::GetZeroTolerance());
        [[nodiscard]] static Real GetVectorIncludedAngle(const Vector2D& lhs, const Vector2D& rhs) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // ��ֱ�����
        // ���� (y,-x).
        [[nodiscard]] static const Vector2D GetPerp(const Vector2D& vector) noexcept;

        // ���� (y,-x) / sqrt(x * x + y * y).
        [[nodiscard]] static const Vector2D GetUnitPerp(const Vector2D& vector, const Real epsilon = Math::GetZeroTolerance()) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // ���� DotPerp((lhs.x,lhs.y),(rhs.x,rhs.y)) =
        // lhs.x * rhs.y - lhs.y * rhs.x.
        [[nodiscard]] static Real DotPerp(const Vector2D& lhs, const Vector2D& rhs) noexcept;

        // ������������Χ�С�
        [[nodiscard]] static const AxesAlignBoundingBox2D ComputeExtremes(const ContainerType& vectors);

        // Gram-Schmidt������.
        // �������޹ص�����U��V��������һ�������飨��λ���ȣ��໥��ֱ����
        [[nodiscard]] static const Vector2DOrthonormalize Orthonormalize(const Vector2D& lhs, const Vector2D& rhs, const Real epsilon = Math::GetZeroTolerance());

        // ����ֵnonzeroVector��V��������һ������������
        // ����ֵ��һ����׼������{U��V}��
        // ���ص�VΪͨ���˺������򻯵�nonzeroVector��
        // �������֪V�ǵ�λ���ȣ�ʹ��U = GetPerp(V)��
        [[nodiscard]] static const Vector2DOrthonormalBasis GenerateOrthonormalBasis(const Vector2D& nonzeroVector, const Real epsilon = Math::GetZeroTolerance()) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
    };

    // STL
    template <typename Real>
    [[nodiscard]] bool operator==(const Vector2D<Real>& lhs, const Vector2D<Real>& rhs);

    template <typename Real>
    [[nodiscard]] bool operator<(const Vector2D<Real>& lhs, const Vector2D<Real>& rhs) noexcept;

    // ���������
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Vector2D<Real>& vector);

    using FloatVector2DTools = Vector2DTools<float>;
    using DoubleVector2DTools = Vector2DTools<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_2D_TOOLS_H

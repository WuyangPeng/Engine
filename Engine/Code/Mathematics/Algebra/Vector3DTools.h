///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/12 21:01)

// 3D���������������
// �������洢��ֵΪ������ʱ���Ƚ���������ȣ�
// ��ʹ�ú���Approximate��������==��
// == ������STL
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

        // ���ʹ�õ������ֵĹ�����㡣
        // ��ע�⣬ĳЩͼ��APIʹ�����ֵĹ���
        // ����������ʹ����Щ����������������͸�һ�����������ֵ�API��
        // ������Ҫ���ĵ�ʸ�����ţ��滻ÿ�����ֵcΪ-c����
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

        // ������������Χ�С�
        [[nodiscard]] static const AxesAlignBoundingBox3D ComputeExtremes(const ContainerType& vectors);

        // Gram-Schmidt������.
        // �������޹ص�����U��V��W��������һ�������飨��λ���ȣ��໥��ֱ����
        [[nodiscard]] static const Vector3DOrthonormalize Orthonormalize(const Vector3D& lhs, const Vector3D& mhs, const Vector3D& rhs,
                                                                         const Real epsilon = Math::GetZeroTolerance());
        [[nodiscard]] static const Vector3DOrthonormalize Orthonormalize(const ContainerType& vectors, const Real epsilon = Math::GetZeroTolerance());

        // ����ֵnonzeroVector��W��������һ������������
        // ����ֵ��һ����׼������{U��V, W}��
        // ���ص�WΪͨ���˺������򻯵�nonzeroVector��
        // �������֪W�ǵ�λ���ȣ�ʹ��GenerateComplementBasis������U��V��
        [[nodiscard]] static const Vector3DOrthonormalBasis GenerateOrthonormalBasis(const Vector3D& nonzeroVector, const Real epsilon = Math::GetZeroTolerance());

        // ����ֵnonzeroVector��W��������һ����λ������
        // ����ֵ�е�����{U,V}�ǵ�λ�����һ��ഹֱ��
        // ��{U,V,W}��һ����׼��������
        [[nodiscard]] static const Vector3DOrthonormalBasis GenerateComplementBasis(const Vector3D& unitVector, const Real epsilon = Math::GetZeroTolerance());
    };

    // STL
    template <typename Real>
    [[nodiscard]] bool operator==(const Vector3D<Real>& lhs, const Vector3D<Real>& rhs);

    template <typename Real>
    [[nodiscard]] bool operator<(const Vector3D<Real>& lhs, const Vector3D<Real>& rhs);

    // ���������
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Vector3D<Real>& vector);

    using FloatVector3DTools = Vector3DTools<float>;
    using DoubleVector3DTools = Vector3DTools<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_3D_TOOLS_H

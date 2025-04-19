///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 15:17)

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

        // ���ʹ�õ������ֵĹ�����㡣
        // ��ע�⣬ĳЩͼ��APIʹ�����ֵĹ���
        // ����������ʹ����Щ����������������͸�һ�����������ֵ�API��
        // ������Ҫ���ĵ�ʸ�����ţ��滻ÿ�����ֵcΪ-c����
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

        // ������������Χ�С�
        NODISCARD static AxesAlignBoundingBox3D ComputeExtremes(const ContainerType& vectors);

        // Gram-Schmidt������.
        // �������޹ص�����U��V��W��������һ�������飨��λ���ȣ��໥��ֱ����
        NODISCARD static Vector3OrthonormalizeType Orthonormalize(const Vector3Type& uVector,
                                                              const Vector3Type& vVector,
                                                              const Vector3Type& wVector,
                                                              const Real epsilon = MathType::GetZeroTolerance());
        NODISCARD static Vector3OrthonormalizeType Orthonormalize(const ContainerType& vectors, Real epsilon = MathType::GetZeroTolerance());

        // ����ֵnonzeroVector��W��������һ������������
        // ����ֵ��һ����׼������{U��V, W}��
        // ���ص�WΪͨ���˺������򻯵�nonzeroVector��
        // �������֪W�ǵ�λ���ȣ�ʹ��GenerateComplementBasis������U��V��
        NODISCARD static Vector3OrthonormalBasisType GenerateOrthonormalBasis(const Vector3Type& nonzeroVector, Real epsilon = MathType::GetZeroTolerance());

        // ����ֵnonzeroVector��W��������һ����λ������
        // ����ֵ�е�����{U,V}�ǵ�λ�����һ��ഹֱ��
        // ��{U,V,W}��һ����׼��������
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

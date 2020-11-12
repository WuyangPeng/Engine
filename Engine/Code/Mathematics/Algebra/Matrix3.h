///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/06 14:38)

#ifndef MATHEMATICS_ALGEBRA_MATRIX3_H
#define MATHEMATICS_ALGEBRA_MATRIX3_H

#include "Mathematics/MathematicsDll.h"

/// (x,y,z)����ϵͳ���ٶ�Ϊ��������ϵ�����������ת�������ʽΪ
///   RX =    1       0       0
///           0     cos(t) -sin(t)
///           0     sin(t)  cos(t)
/// ����t > 0��ʾ��yzƽ���ڵ���ʱ����ת
///   RY =  cos(t)    0     sin(t)
///           0       1       0
///        -sin(t)    0     cos(t)
/// ����t > 0��ʾ��zxƽ���ڵ���ʱ����ת
///   RZ =  cos(t) -sin(t)    0
///         sin(t)  cos(t)    0
///           0       0       1
/// ����t > 0��ʾ��xyƽ���ڵ���ʱ����ת

#include "AlgebraFwd.h"
#include "Euler.h"
#include "Matrix3EigenDecomposition.h"
#include "Matrix3Extract.h"
#include "Vector3D.h"
#include "Flags/ExtractEulerResultType.h"
#include "Flags/MatrixFlags.h"
#include "System/Helper/PragmaWarning/Operators.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Matrix3 final : private boost::additive<Matrix3<Real>, boost::multiplicative<Matrix3<Real>, Real>>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Matrix3<Real>;
        using Vector3D = Vector3D<Real>;
        using Math = Math<Real>;
        using Euler = Euler<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Matrix3Extract = Matrix3Extract<Real>;
        using Matrix3EigenDecomposition = Matrix3EigenDecomposition<Real>;

        enum class VectorIndex
        {
            X = 0,
            Y,
            Z,
            Size
        };

        static constexpr auto sm_X = System::EnumCastUnderlying(VectorIndex::X);
        static constexpr auto sm_Y = System::EnumCastUnderlying(VectorIndex::Y);
        static constexpr auto sm_Z = System::EnumCastUnderlying(VectorIndex::Z);
        static constexpr auto sm_VectorSize = System::EnumCastUnderlying(VectorIndex::Size);
        static constexpr auto sm_MatrixSize = sm_VectorSize * Vector3D::sm_PointSize;
        using ArrayType = std::array<Real, sm_MatrixSize>;
        using ContainerType = std::vector<Real>;
        using Vector3DContainerType = std::vector<Vector3D>;

    public:
        // �����־ΪMatrixFlagsZero�����������
        // ���򴴽���λ����
        constexpr explicit Matrix3(MatrixInitType flag = MatrixInitType::Zero) noexcept
            : m_X{ Create(flag, VectorIndex::X) }, m_Y{ Create(flag, VectorIndex::Y) }, m_Z{ Create(flag, VectorIndex::Z) }
        {
        }

        // �����������r����c
        constexpr Matrix3(Real member00, Real member01, Real member02,
                          Real member10, Real member11, Real member12,
                          Real member20, Real member21, Real member22) noexcept
            : m_X{ member00, member01, member02 }, m_Y{ member10, member11, member12 }, m_Z{ member20, member21, member22 }
        {
        }

        /// �������������������֡�
        /// ���������ǻ���MatrixTypeFlags������Ľ���
        /// MatrixTypeFlagsRow:
        /// entry[0..8]={ m00,m01,m02,m10,m11,m12,m20,m21,m22 }  [row major]
        /// MatrixTypeFlagsColumn:
        /// entry[0..8]={ m00,m10,m20,m01,m11,m21,m02,m12,m22 }  [column major]
        Matrix3(const ContainerType& entry, MatrixMajorFlags majorFlag);

        // ������������ʸ���ľ���MatrixMajorFlags����Ϊ
        // MatrixTypeFlagsRow�������Ǿ������
        // MatrixTypeFlagsColumn�������Ǿ������
        Matrix3(const Vector3D& vector0, const Vector3D& vector1, const Vector3D& vector2, MatrixMajorFlags majorFlag);
        Matrix3(const Vector3DContainerType& vectors, MatrixMajorFlags majorFlag);

        // ����һ���ԽǾ���,
        // member01 = member10 = member02 = member20 = member12 = member21 = 0
        constexpr Matrix3(Real member00, Real member11, Real member22) noexcept
            : m_X{ member00, Math::GetValue(0), Math::GetValue(0) },
              m_Y{ Math::GetValue(0), member11, Math::GetValue(0) },
              m_Z{ Math::GetValue(0), Math::GetValue(0), member22 }
        {
        }

        // ����һ����ת���󣨽Ƕ�Ϊ��->��ʱ�뷽��
        // angle����Ϊ���ȣ����ǽǶȡ�
        Matrix3(const Vector3D& axis, Real angle) noexcept;
        Matrix3(MatrixRotationAxis axis, Real angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // ����һ�������� U * V^T
        Matrix3(const Vector3D& vector0, const Vector3D& vector1) noexcept;

        CLASS_INVARIANT_DECLARE;

        // �������־���
        void MakeZero() noexcept;
        void MakeIdentity() noexcept;
        void MakeDiagonal(Real member00, Real member11, Real member22) noexcept;
        void MakeRotation(const Vector3D& axis, Real angle) noexcept;
        void MakeRotation(MatrixRotationAxis axis, Real angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        void MakeTensorProduct(const Vector3D& vector0, const Vector3D& vector1) noexcept;

        [[nodiscard]] const Vector3D& operator[](int row) const;
        [[nodiscard]] Vector3D& operator[](int row);
        [[nodiscard]] const Real& operator()(int row, int column) const;
        [[nodiscard]] Real& operator()(int row, int column);

        template <int Row, int Column>
        [[nodiscard]] Real GetValue() const noexcept;

        template <int Row, int Column>
        void SetValue(Real value) noexcept;

        [[nodiscard]] const Matrix3 operator-() const noexcept;
        Matrix3& operator+=(const Matrix3& rhs) noexcept;
        Matrix3& operator-=(const Matrix3& rhs) noexcept;
        Matrix3& operator*=(Real scalar) noexcept;
        Matrix3& operator/=(Real scalar) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // lhs^T * M * rhs
        [[nodiscard]] Real QuadraticForm(const Vector3D& lhs, const Vector3D& rhs) const noexcept;

        // M^T
        [[nodiscard]] const Matrix3 Transpose() const noexcept;

        // M * rhs
        [[nodiscard]] Matrix3& operator*=(const Matrix3& rhs) noexcept;

        // ��������
        [[nodiscard]] const Matrix3 TimesDiagonal(const Vector3D& diagonal) const noexcept;  // M * D
        [[nodiscard]] const Matrix3 DiagonalTimes(const Vector3D& diagonal) const noexcept;  // D * M
        [[nodiscard]] const Matrix3 Inverse(const Real epsilon = Math::GetZeroTolerance()) const;
        [[nodiscard]] const Matrix3 Adjoint() const noexcept;
        [[nodiscard]] Real Determinant() const noexcept;

        // ���������һ����ת�������溯������Ч��
        // Orthonormalize����ʹ��Gram-Schmidt������ʩ�ӵ�������ת����
        // �Ƕȱ���Ϊ���ȣ������Ƕ�����
        [[nodiscard]] Real ExtractAngle() const noexcept;
        [[nodiscard]] const Vector3D ExtractAxis() const;
        [[nodiscard]] const Matrix3Extract ExtractAngleAxis() const;
        void Orthonormalize();

        // ��������ǶԳƾ���
        // ϵ��M = Real * D * Real^T ������Real = [u0|u1|u2] ��
        // һ����Ϊu0��u1��u2����ת������
        // D = diag(d0,d1,d2)��һ���ԽǾ�������Խ�����Ϊd0��d1��d2��
        // ��������u[i]��Ӧ����������d[i]������ֵ����Ϊd0 <= d1 <= d2��
        // ����ֵ�ĵ�һ����Ϊrotation���ڶ�����Ϊdiagonal��
        [[nodiscard]] const Matrix3EigenDecomposition EigenDecomposition(const Real epsilon = Math::GetZeroTolerance()) const;

        // ��ŷ���Ǵ�����ת����
        void MakeEulerXYZ(Real xAngle, Real yAngle, Real zAngle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        void MakeEulerXZY(Real xAngle, Real zAngle, Real yAngle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        void MakeEulerYXZ(Real yAngle, Real xAngle, Real zAngle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        void MakeEulerYZX(Real yAngle, Real zAngle, Real xAngle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        void MakeEulerZXY(Real zAngle, Real xAngle, Real yAngle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        void MakeEulerZYX(Real zAngle, Real yAngle, Real xAngle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        void MakeEulerXYX(Real x0Angle, Real yAngle, Real x1Angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        void MakeEulerXZX(Real x0Angle, Real zAngle, Real x1Angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        void MakeEulerYXY(Real y0Angle, Real xAngle, Real y1Angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        void MakeEulerYZY(Real y0Angle, Real zAngle, Real y1Angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        void MakeEulerZXZ(Real z0Angle, Real xAngle, Real z1Angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        void MakeEulerZYZ(Real z0Angle, Real yAngle, Real z1Angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        void MakeEuler(const Euler& euler) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        /// ����ֵ˳��ΪxAngle��yAngle��zAngle
        /// ����ָ���ķ�Χ�ڣ�
        /// xAngle��[-pi,pi]��yAngle��[-pi/2,pi/2]��zAngle��[-pi,pi]
        /// �������������Ψһ������zAngle = 0��
        /// һ������£�һ���׽��������
        /// ExtractEulerResultType::Sum��zAngle + xAngle= c
        /// ExtractEulerResultType::Difference��zAngle - xAngle= c
        /// ��һЩ�Ƕ�c��
        [[nodiscard]] const Euler ExtractEulerXYZ() const noexcept;

        /// ����ֵ˳��ΪxAngle��zAngle��yAngle
        /// ����ָ���ķ�Χ�ڣ�
        /// xAngle��[-pi,pi]��zAngle��[-pi/2,pi/2]��yAngle��[-pi,pi]
        /// �������������Ψһ������yAngle = 0��
        /// һ������£�һ���׽��������
        /// ExtractEulerResultType::Sum��yAngle + xAngle = c
        /// ExtractEulerResultType::Difference��yAngle - xAngle = c
        /// ��һЩ�Ƕ�c��
        [[nodiscard]] const Euler ExtractEulerXZY() const noexcept;

        /// ����ֵ˳��ΪyAngle��xAngle��zAngle
        /// ����ָ���ķ�Χ�ڣ�
        /// yAngle��[-pi,pi]��xAngle��[-pi/2,pi/2]��zAngle��[-pi,pi]
        /// �������������Ψһ������zAngle = 0��
        /// һ������£�һ���׽��������
        /// ExtractEulerResultType::Sum��zAngle + yAngle = c
        /// ExtractEulerResultType::Difference��zAngle - yAngle = c
        /// ��һЩ�Ƕ�c��
        [[nodiscard]] const Euler ExtractEulerYXZ() const noexcept;

        /// ����ֵ˳��ΪyAngle��zAngle��xAngle
        /// ����ָ���ķ�Χ�ڣ�
        /// yAngle��[-pi,pi]��zAngle��[-pi/2,pi/2]��xAngle��[-pi,pi]
        /// �������������Ψһ������xAngle = 0��
        /// һ������£�һ���׽��������
        /// ExtractEulerResultType::Sum��xAngle + yAngle = c
        /// ExtractEulerResultType::Difference��xAngle - yAngle = c
        /// ��һЩ�Ƕ�c��
        [[nodiscard]] const Euler ExtractEulerYZX() const noexcept;

        /// ����ֵ˳��ΪzAngle��xAngle��yAngle
        /// ����ָ���ķ�Χ�ڣ�
        /// zAngle��[-pi,pi]��xAngle��[-pi/2,pi/2]��yAngle��[-pi,pi]
        /// �������������Ψһ������yAngle = 0��
        /// һ������£�һ���׽��������
        /// ExtractEulerResultType::Sum��yAngle + zAngle = c
        /// ExtractEulerResultType::Difference��yAngle - zAngle = c
        /// ��һЩ�Ƕ�c��
        [[nodiscard]] const Euler ExtractEulerZXY() const noexcept;

        /// ����ֵ˳��ΪzAngle��yAngle��xAngle
        /// ����ָ���ķ�Χ�ڣ�
        /// zAngle��[-pi,pi]��yAngle��[-pi/2,pi/2]��xAngle��[-pi,pi]
        /// �������������Ψһ������xAngle = 0��
        /// һ������£�һ���׽��������
        /// ExtractEulerResultType::Sum��xAngle + zAngle = c
        /// ExtractEulerResultType::Difference��xAngle - zAngle = c
        /// ��һЩ�Ƕ�c��
        [[nodiscard]] const Euler ExtractEulerZYX() const noexcept;

        /// ����ֵ˳��Ϊx0Angle��yAngle��x1Angle
        /// ����ָ���ķ�Χ�ڣ�
        /// x0Angle��[-pi,pi]��yAngle��[0,pi]��x1Angle��[-pi,pi]
        /// �������������Ψһ������x1Angle = 0��
        /// һ������£�һ���׽��������
        /// ExtractEulerResultType::Sum��x1Angle + x0Angle = c
        /// ExtractEulerResultType::Difference�� x1Angle - x0Angle = c
        /// ��һЩ�Ƕ�c��
        [[nodiscard]] const Euler ExtractEulerXYX() const noexcept;

        /// ����ֵ˳��Ϊx0Angle��zAngle��x1Angle
        /// ����ָ���ķ�Χ�ڣ�
        /// x0Angle��[-pi,pi]��zAngle��[0,pi]��x1Angle��[-pi,pi]
        /// �������������Ψһ������x1Angle = 0��
        /// һ������£�һ���׽��������
        /// ExtractEulerResultType::Sum��x1Angle + x0Angle = c
        /// ExtractEulerResultType::Difference�� x1Angle - x0Angle = c
        /// ��һЩ�Ƕ�c��
        [[nodiscard]] const Euler ExtractEulerXZX() const noexcept;

        /// ����ֵ˳��Ϊy0Angle��xAngle��y1Angle
        /// ����ָ���ķ�Χ�ڣ�
        /// y0Angle��[-pi,pi]��xAngle��[0,pi]��y1Angle��[-pi,pi]
        /// �������������Ψһ������y1Angle = 0��
        /// һ������£�һ���׽��������
        /// ExtractEulerResultType::Sum��y1Angle + y0Angle = c
        /// ExtractEulerResultType::Difference�� y1Angle - y0Angle = c
        /// ��һЩ�Ƕ�c��
        [[nodiscard]] const Euler ExtractEulerYXY() const noexcept;

        /// ����ֵ˳��Ϊy0Angle��zAngle��y1Angle
        /// ����ָ���ķ�Χ�ڣ�
        /// y0Angle��[-pi,pi]��zAngle��[0,pi]��y1Angle��[-pi,pi]
        /// �������������Ψһ������y1Angle = 0��
        /// һ������£�һ���׽��������
        /// ExtractEulerResultType::Sum��y1Angle + y0Angle = c
        /// ExtractEulerResultType::Difference�� y1Angle - y0Angle = c
        /// ��һЩ�Ƕ�c��
        [[nodiscard]] const Euler ExtractEulerYZY() const noexcept;

        /// ����ֵ˳��Ϊz0Angle��xAngle��z1Angle
        /// ����ָ���ķ�Χ�ڣ�
        /// x0Angle��[-pi,pi]��xAngle��[0,pi]��x1Angle��[-pi,pi]
        /// �������������Ψһ������z1Angle = 0��
        /// һ������£�һ���׽��������
        /// ExtractEulerResultType::Sum��z1Angle + z0Angle = c
        /// ExtractEulerResultType::Difference�� z1Angle - z0Angle = c
        /// ��һЩ�Ƕ�c��
        [[nodiscard]] const Euler ExtractEulerZXZ() const noexcept;

        /// ����ֵ˳��Ϊz0Angle��yAngle��z1Angle
        /// ����ָ���ķ�Χ�ڣ�
        /// x0Angle��[-pi,pi]��yAngle��[0,pi]��x1Angle��[-pi,pi]
        /// �������������Ψһ������z1Angle = 0��
        /// һ������£�һ���׽��������
        /// ExtractEulerResultType::Sum��z1Angle + z0Angle = c
        /// ExtractEulerResultType::Difference�� z1Angle - z0Angle = c
        /// ��һЩ�Ƕ�c��
        [[nodiscard]] const Euler ExtractEulerZYZ() const noexcept;

        /// SLERP���������Բ�ֵ������ʹ����Ԫ����
        /// ���� Real(t) = R0*(Transpose(R0)*R1)^t
        /// ���Q��һ����ת����ʹ�õ�λ������U�ͽ�A��
        /// ��Q^ t��һ����ת����ʹ�õ�λ������U����ת�Ƕ�t*A��
        void Slerp(Real t, const Matrix3& rot0, const Matrix3& rot1);

        [[nodiscard]] const ArrayType GetCoordinate() const noexcept;
        void Set(const ArrayType& coordinate);

        // �������
        [[nodiscard]] static constexpr Matrix3 GetZero()
        {
            return Matrix3{ MatrixInitType::Zero };
        }

        [[nodiscard]] static constexpr Matrix3 GetIdentity()
        {
            return Matrix3{ MatrixInitType::Identity };
        }

    private:
        [[nodiscard]] static constexpr Vector3D Create(MatrixInitType flag, VectorIndex vectorIndex)
        {
            if (flag == MatrixInitType::Zero)
            {
                return Vector3D{};
            }
            else if (vectorIndex == VectorIndex::X)
            {
                return Vector3D::GetUnitX();
            }
            else if (vectorIndex == VectorIndex::Y)
            {
                return Vector3D::GetUnitY();
            }
            else
            {
                return Vector3D::GetUnitZ();
            }
        }

        template <int Row>
        [[nodiscard]] const Vector3D& GetVector() const noexcept;

        template <int Row>
        [[nodiscard]] Vector3D& GetVector() noexcept;

        template <int Column>
        [[nodiscard]] typename Vector3D::GetCoordinateFunction GetVectorGetFunction() const noexcept;

        template <int Column>
        [[nodiscard]] typename Vector3D::SetCoordinateFunction GetVectorSetFunction() const noexcept;

    private:
        // �洢Ϊ������
        Vector3D m_X;
        Vector3D m_Y;
        Vector3D m_Z;
    };

    // vec^T * M
    template <typename Real>
    [[nodiscard]] const Vector3D<Real> operator*(const Vector3D<Real>& vector, const Matrix3<Real>& matrix) noexcept;

    // M * vec
    template <typename Real>
    [[nodiscard]] const Vector3D<Real> operator*(const Matrix3<Real>& matrix, const Vector3D<Real>& vector) noexcept;

    // M * mat
    template <typename Real>
    [[nodiscard]] const Matrix3<Real> operator*(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs) noexcept;

    // lhs^T * rhs
    template <typename Real>
    [[nodiscard]] const Matrix3<Real> TransposeTimes(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs) noexcept;

    // lhs * rhs^T
    template <typename Real>
    [[nodiscard]] const Matrix3<Real> TimesTranspose(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs) noexcept;

    // lhs^T * rhs^T
    template <typename Real>
    [[nodiscard]] const Matrix3<Real> TransposeTimesTranspose(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs) noexcept;

    template <typename Real>
    [[nodiscard]] bool Approximate(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs, const Real epsilon = Math<Real>::GetZeroTolerance());

    // ���������
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Matrix3<Real>& matrix);

    using FloatMatrix3 = Matrix3<float>;
    using DoubleMatrix3 = Matrix3<double>;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX3_H

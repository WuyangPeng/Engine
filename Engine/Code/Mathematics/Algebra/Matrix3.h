///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 14:45)

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
#include "AxisAngle.h"
#include "Euler.h"
#include "Matrix3EigenDecomposition.h"
#include "Vector3.h"
#include "Flags/MatrixFlags.h"
#include "System/Helper/PragmaWarning/Operators.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Matrix3 final : private boost::additive<Matrix3<Real>, boost::multiplicative<Matrix3<Real>, Real>>
    {
    public:
        using ClassType = Matrix3<Real>;

        using Vector3 = Vector3<Real>;
        using VectorIndex = typename Vector3::PointIndex;
        static constexpr auto xIndex = Vector3::xIndex;
        static constexpr auto yIndex = Vector3::yIndex;
        static constexpr auto zIndex = Vector3::zIndex;
        static constexpr auto vectorSize = Vector3::pointSize;
        static constexpr auto matrixSize = vectorSize * Vector3::pointSize;

        using Math = Math<Real>;
        using Euler = Euler<Real>;
        using Matrix2 = Matrix2<Real>;
        using Matrix4 = Matrix4<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Matrix3Extract = AxisAngle<Real>;
        using Matrix3EigenDecomposition = Matrix3EigenDecomposition<Real>;
        using ArrayType = std::array<Real, matrixSize>;
        using ContainerType = std::vector<Real>;
        using Vector3ContainerType = std::vector<Vector3>;

    public:
        // �����־ΪMatrixFlagsZero�����������
        // ���򴴽���λ����
        constexpr explicit Matrix3(MatrixInitType flag = MatrixInitType::Zero) noexcept
            : x{ Create(flag, VectorIndex::X) }, y{ Create(flag, VectorIndex::Y) }, z{ Create(flag, VectorIndex::Z) }
        {
        }

        // �����������r����c
        constexpr Matrix3(Real member00,
                          Real member01,
                          Real member02,
                          Real member10,
                          Real member11,
                          Real member12,
                          Real member20,
                          Real member21,
                          Real member22) noexcept
            : x{ member00, member01, member02 }, y{ member10, member11, member12 }, z{ member20, member21, member22 }
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
        Matrix3(const Vector3& vector0, const Vector3& vector1, const Vector3& vector2, MatrixMajorFlags majorFlag);
        Matrix3(const Vector3ContainerType& vectors, MatrixMajorFlags majorFlag);

        // ����һ���ԽǾ���,
        // member01 = member10 = member02 = member20 = member12 = member21 = 0
        constexpr Matrix3(Real member00, Real member11, Real member22) noexcept
            : x{ member00, Math::GetValue(0), Math::GetValue(0) },
              y{ Math::GetValue(0), member11, Math::GetValue(0) },
              z{ Math::GetValue(0), Math::GetValue(0), member22 }
        {
        }

        // ����һ����ת���󣨽Ƕ�Ϊ��->��ʱ�뷽��
        // angle����Ϊ���ȣ����ǽǶȡ�
        Matrix3(const Vector3& axis, Real angle) noexcept;
        Matrix3(MatrixRotationAxis axis, Real angle) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // ����һ�������� U * V^T
        Matrix3(const Vector3& vector0, const Vector3& vector1) noexcept;

        CLASS_INVARIANT_DECLARE;

        // �������־���
        void MakeZero() noexcept;
        void MakeIdentity() noexcept;
        void MakeDiagonal(Real member00, Real member11, Real member22) noexcept;
        void MakeRotation(const Vector3& axis, Real angle) noexcept;
        void MakeRotation(MatrixRotationAxis axis, Real angle) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        void MakeTensorProduct(const Vector3& vector0, const Vector3& vector1) noexcept;

        NODISCARD const Vector3& operator[](int row) const;
        NODISCARD Vector3& operator[](int row);
        NODISCARD const Real& operator()(int row, int column) const;
        NODISCARD Real& operator()(int row, int column);

        template <int Row, int Column>
        NODISCARD Real GetValue() const noexcept;

        template <int Row, int Column>
        void SetValue(Real value) noexcept;

        NODISCARD Matrix3 operator-() const noexcept;
        Matrix3& operator+=(const Matrix3& rhs) noexcept;
        Matrix3& operator-=(const Matrix3& rhs) noexcept;
        Matrix3& operator*=(Real scalar) noexcept;
        Matrix3& operator/=(Real scalar) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // lhs^T * M * rhs
        NODISCARD Real QuadraticForm(const Vector3& lhs, const Vector3& rhs) const noexcept;

        // M^T
        NODISCARD Matrix3 Transpose() const noexcept;

        // M * rhs
        Matrix3& operator*=(const Matrix3& rhs) noexcept;

        // ��������
        NODISCARD Matrix3 TimesDiagonal(const Vector3& diagonal) const noexcept;  // M * D
        NODISCARD Matrix3 DiagonalTimes(const Vector3& diagonal) const noexcept;  // D * M
        NODISCARD Matrix3 Inverse(const Real epsilon = Math::GetZeroTolerance()) const;
        NODISCARD Matrix3 Adjoint() const noexcept;
        NODISCARD Real Determinant() const noexcept;

        NODISCARD Matrix3 GaussianEliminationInverse(Real epsilon = Math::GetZeroTolerance()) const;
        NODISCARD Real GaussianEliminationDeterminant(Real epsilon = Math::GetZeroTolerance()) const;

        // ���������һ����ת�������溯������Ч��
        // Orthonormalize����ʹ��Gram-Schmidt������ʩ�ӵ�������ת����
        // �Ƕȱ���Ϊ���ȣ������Ƕ�����
        NODISCARD Real ExtractAngle() const noexcept;
        NODISCARD Vector3 ExtractAxis() const noexcept(gAssert < 3 || gMathematicsAssert < 3);
        NODISCARD Matrix3Extract ExtractAngleAxis() const noexcept(gAssert < 3 || gMathematicsAssert < 3);
        void Orthonormalize();

        // ��������ǶԳƾ���
        // ϵ��M = Real * D * Real^T ������Real = [u0|u1|u2] ��
        // һ����Ϊu0��u1��u2����ת������
        // D = diag(d0,d1,d2)��һ���ԽǾ�������Խ�����Ϊd0��d1��d2��
        // ��������u[i]��Ӧ����������d[i]������ֵ����Ϊd0 <= d1 <= d2��
        // ����ֵ�ĵ�һ����Ϊrotation���ڶ�����Ϊdiagonal��
        NODISCARD Matrix3EigenDecomposition EigenDecomposition(Real epsilon = Math::GetZeroTolerance()) const;

        // ��ŷ���Ǵ�����ת����
        void MakeEulerXYZ(Real xAngle, Real yAngle, Real zAngle) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        void MakeEulerXZY(Real xAngle, Real zAngle, Real yAngle) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        void MakeEulerYXZ(Real yAngle, Real xAngle, Real zAngle) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        void MakeEulerYZX(Real yAngle, Real zAngle, Real xAngle) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        void MakeEulerZXY(Real zAngle, Real xAngle, Real yAngle) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        void MakeEulerZYX(Real zAngle, Real yAngle, Real xAngle) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        void MakeEulerXYX(Real x0Angle, Real yAngle, Real x1Angle) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        void MakeEulerXZX(Real x0Angle, Real zAngle, Real x1Angle) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        void MakeEulerYXY(Real y0Angle, Real xAngle, Real y1Angle) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        void MakeEulerYZY(Real y0Angle, Real zAngle, Real y1Angle) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        void MakeEulerZXZ(Real z0Angle, Real xAngle, Real z1Angle) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        void MakeEulerZYZ(Real z0Angle, Real yAngle, Real z1Angle) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        void MakeEuler(const Euler& euler) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        NODISCARD Euler ExtractEuler(ExtractEulerResultOrder euler) const noexcept;

        /// ����ֵ˳��ΪxAngle��yAngle��zAngle
        /// ����ָ���ķ�Χ�ڣ�
        /// xAngle��[-pi,pi]��yAngle��[-pi/2,pi/2]��zAngle��[-pi,pi]
        /// �������������Ψһ������zAngle = 0��
        /// һ������£�һ���׽��������
        /// ExtractEulerResultType::Sum��zAngle + xAngle= c
        /// ExtractEulerResultType::Difference��zAngle - xAngle= c
        /// ��һЩ�Ƕ�c��
        NODISCARD Euler ExtractEulerXYZ() const noexcept;

        /// ����ֵ˳��ΪxAngle��zAngle��yAngle
        /// ����ָ���ķ�Χ�ڣ�
        /// xAngle��[-pi,pi]��zAngle��[-pi/2,pi/2]��yAngle��[-pi,pi]
        /// �������������Ψһ������yAngle = 0��
        /// һ������£�һ���׽��������
        /// ExtractEulerResultType::Sum��yAngle + xAngle = c
        /// ExtractEulerResultType::Difference��yAngle - xAngle = c
        /// ��һЩ�Ƕ�c��
        NODISCARD Euler ExtractEulerXZY() const noexcept;

        /// ����ֵ˳��ΪyAngle��xAngle��zAngle
        /// ����ָ���ķ�Χ�ڣ�
        /// yAngle��[-pi,pi]��xAngle��[-pi/2,pi/2]��zAngle��[-pi,pi]
        /// �������������Ψһ������zAngle = 0��
        /// һ������£�һ���׽��������
        /// ExtractEulerResultType::Sum��zAngle + yAngle = c
        /// ExtractEulerResultType::Difference��zAngle - yAngle = c
        /// ��һЩ�Ƕ�c��
        NODISCARD Euler ExtractEulerYXZ() const noexcept;

        /// ����ֵ˳��ΪyAngle��zAngle��xAngle
        /// ����ָ���ķ�Χ�ڣ�
        /// yAngle��[-pi,pi]��zAngle��[-pi/2,pi/2]��xAngle��[-pi,pi]
        /// �������������Ψһ������xAngle = 0��
        /// һ������£�һ���׽��������
        /// ExtractEulerResultType::Sum��xAngle + yAngle = c
        /// ExtractEulerResultType::Difference��xAngle - yAngle = c
        /// ��һЩ�Ƕ�c��
        NODISCARD Euler ExtractEulerYZX() const noexcept;

        /// ����ֵ˳��ΪzAngle��xAngle��yAngle
        /// ����ָ���ķ�Χ�ڣ�
        /// zAngle��[-pi,pi]��xAngle��[-pi/2,pi/2]��yAngle��[-pi,pi]
        /// �������������Ψһ������yAngle = 0��
        /// һ������£�һ���׽��������
        /// ExtractEulerResultType::Sum��yAngle + zAngle = c
        /// ExtractEulerResultType::Difference��yAngle - zAngle = c
        /// ��һЩ�Ƕ�c��
        NODISCARD Euler ExtractEulerZXY() const noexcept;

        /// ����ֵ˳��ΪzAngle��yAngle��xAngle
        /// ����ָ���ķ�Χ�ڣ�
        /// zAngle��[-pi,pi]��yAngle��[-pi/2,pi/2]��xAngle��[-pi,pi]
        /// �������������Ψһ������xAngle = 0��
        /// һ������£�һ���׽��������
        /// ExtractEulerResultType::Sum��xAngle + zAngle = c
        /// ExtractEulerResultType::Difference��xAngle - zAngle = c
        /// ��һЩ�Ƕ�c��
        NODISCARD Euler ExtractEulerZYX() const noexcept;

        /// ����ֵ˳��Ϊx0Angle��yAngle��x1Angle
        /// ����ָ���ķ�Χ�ڣ�
        /// x0Angle��[-pi,pi]��yAngle��[0,pi]��x1Angle��[-pi,pi]
        /// �������������Ψһ������x1Angle = 0��
        /// һ������£�һ���׽��������
        /// ExtractEulerResultType::Sum��x1Angle + x0Angle = c
        /// ExtractEulerResultType::Difference�� x1Angle - x0Angle = c
        /// ��һЩ�Ƕ�c��
        NODISCARD Euler ExtractEulerXYX() const noexcept;

        /// ����ֵ˳��Ϊx0Angle��zAngle��x1Angle
        /// ����ָ���ķ�Χ�ڣ�
        /// x0Angle��[-pi,pi]��zAngle��[0,pi]��x1Angle��[-pi,pi]
        /// �������������Ψһ������x1Angle = 0��
        /// һ������£�һ���׽��������
        /// ExtractEulerResultType::Sum��x1Angle + x0Angle = c
        /// ExtractEulerResultType::Difference�� x1Angle - x0Angle = c
        /// ��һЩ�Ƕ�c��
        NODISCARD Euler ExtractEulerXZX() const noexcept;

        /// ����ֵ˳��Ϊy0Angle��xAngle��y1Angle
        /// ����ָ���ķ�Χ�ڣ�
        /// y0Angle��[-pi,pi]��xAngle��[0,pi]��y1Angle��[-pi,pi]
        /// �������������Ψһ������y1Angle = 0��
        /// һ������£�һ���׽��������
        /// ExtractEulerResultType::Sum��y1Angle + y0Angle = c
        /// ExtractEulerResultType::Difference�� y1Angle - y0Angle = c
        /// ��һЩ�Ƕ�c��
        NODISCARD Euler ExtractEulerYXY() const noexcept;

        /// ����ֵ˳��Ϊy0Angle��zAngle��y1Angle
        /// ����ָ���ķ�Χ�ڣ�
        /// y0Angle��[-pi,pi]��zAngle��[0,pi]��y1Angle��[-pi,pi]
        /// �������������Ψһ������y1Angle = 0��
        /// һ������£�һ���׽��������
        /// ExtractEulerResultType::Sum��y1Angle + y0Angle = c
        /// ExtractEulerResultType::Difference�� y1Angle - y0Angle = c
        /// ��һЩ�Ƕ�c��
        NODISCARD Euler ExtractEulerYZY() const noexcept;

        /// ����ֵ˳��Ϊz0Angle��xAngle��z1Angle
        /// ����ָ���ķ�Χ�ڣ�
        /// x0Angle��[-pi,pi]��xAngle��[0,pi]��x1Angle��[-pi,pi]
        /// �������������Ψһ������z1Angle = 0��
        /// һ������£�һ���׽��������
        /// ExtractEulerResultType::Sum��z1Angle + z0Angle = c
        /// ExtractEulerResultType::Difference�� z1Angle - z0Angle = c
        /// ��һЩ�Ƕ�c��
        NODISCARD Euler ExtractEulerZXZ() const noexcept;

        /// ����ֵ˳��Ϊz0Angle��yAngle��z1Angle
        /// ����ָ���ķ�Χ�ڣ�
        /// x0Angle��[-pi,pi]��yAngle��[0,pi]��x1Angle��[-pi,pi]
        /// �������������Ψһ������z1Angle = 0��
        /// һ������£�һ���׽��������
        /// ExtractEulerResultType::Sum��z1Angle + z0Angle = c
        /// ExtractEulerResultType::Difference�� z1Angle - z0Angle = c
        /// ��һЩ�Ƕ�c��
        NODISCARD Euler ExtractEulerZYZ() const noexcept;

        /// SLERP���������Բ�ֵ������ʹ����Ԫ����
        /// ���� Real(t) = R0*(Transpose(R0)*R1)^t
        /// ���Q��һ����ת����ʹ�õ�λ������U�ͽ�A��
        /// ��Q^ t��һ����ת����ʹ�õ�λ������U����ת�Ƕ�t*A��
        void Slerp(Real t, const Matrix3& rot0, const Matrix3& rot1) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        NODISCARD ArrayType GetCoordinate() const noexcept;
        void Set(const ArrayType& coordinate);

        NODISCARD ContainerType GetContainer() const;

        // �������
        NODISCARD static constexpr Matrix3 GetZero()
        {
            return Matrix3{ MatrixInitType::Zero };
        }

        NODISCARD static constexpr Matrix3 GetIdentity()
        {
            return Matrix3{ MatrixInitType::Identity };
        }

        NODISCARD Matrix4 Lift() const;
        NODISCARD Matrix2 Project() const;

        NODISCARD Real Trace() const noexcept;

    private:
        NODISCARD static constexpr Vector3 Create(MatrixInitType flag, VectorIndex vectorIndex)
        {
            if (flag == MatrixInitType::Zero)
            {
                return Vector3{};
            }
            else if (vectorIndex == VectorIndex::X)
            {
                return Vector3::GetUnitX();
            }
            else if (vectorIndex == VectorIndex::Y)
            {
                return Vector3::GetUnitY();
            }
            else
            {
                return Vector3::GetUnitZ();
            }
        }

        template <int Row>
        NODISCARD const Vector3& GetVector() const noexcept;

        template <int Row>
        NODISCARD Vector3& GetVector() noexcept;

        template <int Column>
        NODISCARD typename Vector3::GetCoordinateFunction GetVectorGetFunction() const noexcept;

        template <int Column>
        NODISCARD typename Vector3::SetCoordinateFunction GetVectorSetFunction() const noexcept;

    private:
        // �洢Ϊ������
        Vector3 x;
        Vector3 y;
        Vector3 z;
    };

    // vec^T * M
    template <typename Real>
    NODISCARD Vector3<Real> operator*(const Vector3<Real>& vector, const Matrix3<Real>& matrix) noexcept;

    // M * vec
    template <typename Real>
    NODISCARD Vector3<Real> operator*(const Matrix3<Real>& matrix, const Vector3<Real>& vector) noexcept;

    // M * mat
    template <typename Real>
    NODISCARD Matrix3<Real> operator*(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs) noexcept;

    // lhs^T * rhs
    template <typename Real>
    NODISCARD Matrix3<Real> TransposeTimes(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs) noexcept;

    // lhs * rhs^T
    template <typename Real>
    NODISCARD Matrix3<Real> TimesTranspose(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs) noexcept;

    // lhs^T * rhs^T
    template <typename Real>
    NODISCARD Matrix3<Real> TransposeTimesTranspose(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs) noexcept;

    template <typename Real>
    NODISCARD bool Approximate(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs, Real epsilon = Math<Real>::GetZeroTolerance());

    // ���������
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Matrix3<Real>& matrix);

    using Matrix3F = Matrix3<float>;
    using Matrix3D = Matrix3<double>;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX3_H

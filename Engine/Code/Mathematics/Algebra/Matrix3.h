// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.2.5 (2020/03/19 10:12)

#ifndef MATHEMATICS_ALGEBRA_MATRIX3_H
#define MATHEMATICS_ALGEBRA_MATRIX3_H

#include "Mathematics/MathematicsDll.h"

// (x,y,z)����ϵͳ���ٶ�Ϊ��������ϵ�����������ת�������ʽΪ
//   RX =    1       0       0
//           0     cos(t) -sin(t)
//           0     sin(t)  cos(t)
// ����t > 0��ʾ��yzƽ���ڵ���ʱ����ת
//   RY =  cos(t)    0     sin(t)
//           0       1       0
//        -sin(t)    0     cos(t)
// ����t > 0��ʾ��zxƽ���ڵ���ʱ����ת
//   RZ =  cos(t) -sin(t)    0
//         sin(t)  cos(t)    0
//           0       0       1
// ����t > 0��ʾ��xyƽ���ڵ���ʱ����ת

#include "AlgebraFwd.h"
#include "Euler.h"
#include "Matrix3EigenDecompositionDetail.h"
#include "Matrix3Extract.h"
#include "Flags/ExtractEulerResultType.h"
#include "Flags/MatrixFlags.h"
#include "CoreTools/DataTypes/TableDetail.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Matrix3 : private boost::additive<Matrix3<Real>, boost::multiplicative<Matrix3<Real>, Real>>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Matrix3<Real>;
        using Table3 = CoreTools::Table<3, 3, Real>;
        using Vector3D = Vector3D<Real>;
        using Math = Math<Real>;
        using Euler = Euler<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using AlgebraTraits = AlgebraTraits<Real>;
        using Matrix3Extract = Matrix3Extract<Real>;
        using Matrix3EigenDecomposition = Matrix3EigenDecomposition<Real>;

        static constexpr auto sm_MatrixSize = 9;
        using ArrayType = std::array<Real, sm_MatrixSize>;

    public:
        // �����־ΪMatrixFlagsZero�����������
        // ���򴴽���λ����
        explicit Matrix3(MatrixInitType flag = MatrixInitType::Zero);

        // �����������r����c
        Matrix3(Real member00, Real member01, Real member02,
                Real member10, Real member11, Real member12,
                Real member20, Real member21, Real member22) noexcept;

        // �������������������֡�
        // ���������ǻ���MatrixTypeFlags������Ľ���
        // MatrixTypeFlagsRow:
        // entry[0..8]={m00,m01,m02,m10,m11,m12,m20,m21,m22}  [row major]
        // MatrixTypeFlagsColumn:
        // entry[0..8]={m00,m10,m20,m01,m11,m21,m02,m12,m22}  [column major]
        Matrix3(const std::vector<Real>& entry, MatrixMajorFlags majorFlag);

        // ������������ʸ���ľ���MatrixMajorFlags����Ϊ
        // MatrixTypeFlagsRow�������Ǿ������
        // MatrixTypeFlagsColumn�������Ǿ������
        Matrix3(const Vector3D& firstVector, const Vector3D& secondVector,
                const Vector3D& thirdVector, MatrixMajorFlags majorFlag);
        Matrix3(const std::vector<Vector3D>& vectors, MatrixMajorFlags majorFlag);

        // ����һ���ԽǾ���,
        // member01 = member10 = member02 = member20 = member12 = member21 = 0
        Matrix3(Real member00, Real member11, Real member22);

        // ����һ����ת���󣨽Ƕ�Ϊ�� ->��ʱ�뷽��
        // angle����Ϊ���ȣ����ǽǶȡ�
        Matrix3(const Vector3D& axis, Real angle);
        Matrix3(MatrixRotationAxis axis, Real angle);

        // ����һ�������� U * V^T
        Matrix3(const Vector3D& firstVector, const Vector3D& secondVector);

        CLASS_INVARIANT_DECLARE;

        // �������־���
        void MakeZero();
        void MakeIdentity();
        void MakeDiagonal(Real member00, Real member11, Real member22);
        void MakeRotation(const Vector3D& axis, Real angle);
        void MakeRotation(MatrixRotationAxis axis, Real angle);
        void MakeTensorProduct(const Vector3D& firstVector, const Vector3D& secondVector);

        const Real* operator[](int row) const;
        Real* operator[](int row);
        const Real& operator()(int row, int column) const;
        Real& operator()(int row, int column);

        const Matrix3 operator-() const;
        Matrix3& operator+=(const Matrix3& rhs);
        Matrix3& operator-=(const Matrix3& rhs);
        Matrix3& operator*=(Real scalar);
        Matrix3& operator/=(Real scalar);

        // lhs^T * M * rhs
        Real QuadraticForm(const Vector3D& lhs, const Vector3D& rhs) const;

        // M^T
        const Matrix3 Transpose() const;

        // M * rhs
        Matrix3& operator*=(const Matrix3& rhs);

        // ��������
        const Matrix3 TimesDiagonal(const Vector3D& diagonal) const;  // M * D
        const Matrix3 DiagonalTimes(const Vector3D& diagonal) const;  // D * M
        const Matrix3 Inverse(const Real epsilon = Math::GetZeroTolerance()) const;
        const Matrix3 Adjoint() const;
        Real Determinant() const;

        // ���������һ����ת�������溯������Ч��
        // Orthonormalize����ʹ��Gram-Schmidt������ʩ�ӵ�������ת����
        // �Ƕȱ���Ϊ���ȣ������Ƕ�����
        Real ExtractAngle() const;
        const Vector3D ExtractAxis() const;
        const Matrix3Extract ExtractAngleAxis() const;
        void Orthonormalize();

        // ��������ǶԳƾ���
        // ϵ��M = Real * D * Real^T ������Real = [u0|u1|u2] ��
        // һ����Ϊu0��u1��u2����ת������
        // D = diag(d0,d1,d2)��һ���ԽǾ�������Խ�����Ϊd0��d1��d2��
        // ��������u[i]��Ӧ����������d[i]������ֵ����Ϊd0 <= d1 <= d2��
        // ����ֵ�ĵ�һ����Ϊrotation���ڶ�����Ϊdiagonal��
        const Matrix3EigenDecomposition EigenDecomposition(const Real epsilon = Math::GetZeroTolerance()) const;

        // ��ŷ���Ǵ�����ת����
        void MakeEulerXYZ(Real xAngle, Real yAngle, Real zAngle);
        void MakeEulerXZY(Real xAngle, Real zAngle, Real yAngle);
        void MakeEulerYXZ(Real yAngle, Real xAngle, Real zAngle);
        void MakeEulerYZX(Real yAngle, Real zAngle, Real xAngle);
        void MakeEulerZXY(Real zAngle, Real xAngle, Real yAngle);
        void MakeEulerZYX(Real zAngle, Real yAngle, Real xAngle);
        void MakeEulerXYX(Real x0Angle, Real yAngle, Real x1Angle);
        void MakeEulerXZX(Real x0Angle, Real zAngle, Real x1Angle);
        void MakeEulerYXY(Real y0Angle, Real xAngle, Real y1Angle);
        void MakeEulerYZY(Real y0Angle, Real zAngle, Real y1Angle);
        void MakeEulerZXZ(Real z0Angle, Real xAngle, Real z1Angle);
        void MakeEulerZYZ(Real z0Angle, Real yAngle, Real z1Angle);

        void MakeEuler(const Euler& euler);

        // ����ֵ˳��ΪxAngle��yAngle��zAngle
        // ����ָ���ķ�Χ�ڣ�
        // xAngle��[-pi,pi]��yAngle��[-pi/2,pi/2]��zAngle��[-pi,pi]
        // �������������Ψһ������zAngle = 0��
        // һ������£�һ���׽��������
        // ExtractEulerResultType::Sum��zAngle + xAngle= c
        // ExtractEulerResultType::Difference��zAngle - xAngle= c
        // ��һЩ�Ƕ�c��
        const Euler ExtractEulerXYZ() const;

        // ����ֵ˳��ΪxAngle��zAngle��yAngle
        // ����ָ���ķ�Χ�ڣ�
        // xAngle��[-pi,pi]��zAngle��[-pi/2,pi/2]��yAngle��[-pi,pi]
        // �������������Ψһ������yAngle = 0��
        // һ������£�һ���׽��������
        // ExtractEulerResultType::Sum��yAngle + xAngle = c
        // ExtractEulerResultType::Difference��yAngle - xAngle = c
        // ��һЩ�Ƕ�c��
        const Euler ExtractEulerXZY() const;

        // ����ֵ˳��ΪyAngle��xAngle��zAngle
        // ����ָ���ķ�Χ�ڣ�
        // yAngle��[-pi,pi]��xAngle��[-pi/2,pi/2]��zAngle��[-pi,pi]
        // �������������Ψһ������zAngle = 0��
        // һ������£�һ���׽��������
        // ExtractEulerResultType::Sum��zAngle + yAngle = c
        // ExtractEulerResultType::Difference��zAngle - yAngle = c
        // ��һЩ�Ƕ�c��
        const Euler ExtractEulerYXZ() const;

        // ����ֵ˳��ΪyAngle��zAngle��xAngle
        // ����ָ���ķ�Χ�ڣ�
        // yAngle��[-pi,pi]��zAngle��[-pi/2,pi/2]��xAngle��[-pi,pi]
        // �������������Ψһ������xAngle = 0��
        // һ������£�һ���׽��������
        // ExtractEulerResultType::Sum��xAngle + yAngle = c
        // ExtractEulerResultType::Difference��xAngle - yAngle = c
        // ��һЩ�Ƕ�c��
        const Euler ExtractEulerYZX() const;

        // ����ֵ˳��ΪzAngle��xAngle��yAngle
        // ����ָ���ķ�Χ�ڣ�
        // zAngle��[-pi,pi]��xAngle��[-pi/2,pi/2]��yAngle��[-pi,pi]
        // �������������Ψһ������yAngle = 0��
        // һ������£�һ���׽��������
        // ExtractEulerResultType::Sum��yAngle + zAngle = c
        // ExtractEulerResultType::Difference��yAngle - zAngle = c
        // ��һЩ�Ƕ�c��
        const Euler ExtractEulerZXY() const;

        // ����ֵ˳��ΪzAngle��yAngle��xAngle
        // ����ָ���ķ�Χ�ڣ�
        // zAngle��[-pi,pi]��yAngle��[-pi/2,pi/2]��xAngle��[-pi,pi]
        // �������������Ψһ������xAngle = 0��
        // һ������£�һ���׽��������
        // ExtractEulerResultType::Sum��xAngle + zAngle = c
        // ExtractEulerResultType::Difference��xAngle - zAngle = c
        // ��һЩ�Ƕ�c��
        const Euler ExtractEulerZYX() const noexcept;

        // ����ֵ˳��Ϊx0Angle��yAngle��x1Angle
        // ����ָ���ķ�Χ�ڣ�
        // x0Angle��[-pi,pi]��yAngle��[0,pi]��x1Angle��[-pi,pi]
        // �������������Ψһ������x1Angle = 0��
        // һ������£�һ���׽��������
        // ExtractEulerResultType::Sum��x1Angle + x0Angle = c
        // ExtractEulerResultType::Difference�� x1Angle - x0Angle = c
        // ��һЩ�Ƕ�c��
        const Euler ExtractEulerXYX() const;

        // ����ֵ˳��Ϊx0Angle��zAngle��x1Angle
        // ����ָ���ķ�Χ�ڣ�
        // x0Angle��[-pi,pi]��zAngle��[0,pi]��x1Angle��[-pi,pi]
        // �������������Ψһ������x1Angle = 0��
        // һ������£�һ���׽��������
        // ExtractEulerResultType::Sum��x1Angle + x0Angle = c
        // ExtractEulerResultType::Difference�� x1Angle - x0Angle = c
        // ��һЩ�Ƕ�c��
        const Euler ExtractEulerXZX() const;

        // ����ֵ˳��Ϊy0Angle��xAngle��y1Angle
        // ����ָ���ķ�Χ�ڣ�
        // y0Angle��[-pi,pi]��xAngle��[0,pi]��y1Angle��[-pi,pi]
        // �������������Ψһ������y1Angle = 0��
        // һ������£�һ���׽��������
        // ExtractEulerResultType::Sum��y1Angle + y0Angle = c
        // ExtractEulerResultType::Difference�� y1Angle - y0Angle = c
        // ��һЩ�Ƕ�c��
        const Euler ExtractEulerYXY() const;

        // ����ֵ˳��Ϊy0Angle��zAngle��y1Angle
        // ����ָ���ķ�Χ�ڣ�
        // y0Angle��[-pi,pi]��zAngle��[0,pi]��y1Angle��[-pi,pi]
        // �������������Ψһ������y1Angle = 0��
        // һ������£�һ���׽��������
        // ExtractEulerResultType::Sum��y1Angle + y0Angle = c
        // ExtractEulerResultType::Difference�� y1Angle - y0Angle = c
        // ��һЩ�Ƕ�c��
        const Euler ExtractEulerYZY() const;

        // ����ֵ˳��Ϊz0Angle��xAngle��z1Angle
        // ����ָ���ķ�Χ�ڣ�
        // x0Angle��[-pi,pi]��xAngle��[0,pi]��x1Angle��[-pi,pi]
        // �������������Ψһ������z1Angle = 0��
        // һ������£�һ���׽��������
        // ExtractEulerResultType::Sum��z1Angle + z0Angle = c
        // ExtractEulerResultType::Difference�� z1Angle - z0Angle = c
        // ��һЩ�Ƕ�c��
        const Euler ExtractEulerZXZ() const;

        // ����ֵ˳��Ϊz0Angle��yAngle��z1Angle
        // ����ָ���ķ�Χ�ڣ�
        // x0Angle��[-pi,pi]��yAngle��[0,pi]��x1Angle��[-pi,pi]
        // �������������Ψһ������z1Angle = 0��
        // һ������£�һ���׽��������
        // ExtractEulerResultType::Sum��z1Angle + z0Angle = c
        // ExtractEulerResultType::Difference�� z1Angle - z0Angle = c
        // ��һЩ�Ƕ�c��
        const Euler ExtractEulerZYZ() const;

        // SLERP���������Բ�ֵ������ʹ����Ԫ����
        // ���� Real(t) = R0*(Transpose(R0)*R1)^t
        // ���Q��һ����ת����ʹ�õ�λ������U�ͽ�A��
        // ��Q^ t��һ����ת����ʹ�õ�λ������U����ת�Ƕ�t*A��
        void Slerp(Real t, const Matrix3& firstRot, const Matrix3& secondRot);

        [[nodiscard]] const ArrayType GetCoordinate() const noexcept;
        void Set(const ArrayType& coordinate) noexcept;

        // �������
        static const Matrix3 sm_Zero;
        static const Matrix3 sm_Identity;

    private:
        // Table�洢Ϊ������
        Table3 m_Entry;
    };

    // vec^T * M
    template <typename Real>
    const Vector3D<Real> operator*(const Vector3D<Real>& vector, const Matrix3<Real>& matrix);

    // M * vec
    template <typename Real>
    const Vector3D<Real> operator*(const Matrix3<Real>& matrix, const Vector3D<Real>& vector);

    // M * mat
    template <typename Real>
    const Matrix3<Real> operator*(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs);

    // lhs^T * rhs
    template <typename Real>
    const Matrix3<Real> TransposeTimes(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs);

    // lhs * rhs^T
    template <typename Real>
    const Matrix3<Real> TimesTranspose(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs);

    // lhs^T * rhs^T
    template <typename Real>
    const Matrix3<Real> TransposeTimesTranspose(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs);

    template <typename Real>
    bool Approximate(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs, const Real epsilon);

    template <typename Real>
    bool Approximate(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs);

    // ���������
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Matrix3<Real>& matrix);

    using Matrix3f = Matrix3<float>;
    using Matrix3d = Matrix3<double>;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX3_H

/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/29 15:45)

#ifndef MATHEMATICS_ALGEBRA_TRANSFORM_H
#define MATHEMATICS_ALGEBRA_TRANSFORM_H

#include "Mathematics/MathematicsDll.h"

#include "Detail/AffineMatrix.h"
#include "Detail/TransformMatrix.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Matrix.h"

/// ��Ԥ�����������ж���MATHEMATICS_USE_MATRIX_VECTORʱ����ת����
/// ת��Ϊ Y = M * X + T������M��3x3�ľ���T��3x1��ƽ��������
/// �ڴ��������£�M = R��һ����ת���󣬻���M = S * R������R��һ����ת�����S��һ���ԽǾ�����Խ�Ԫ�����������š�
/// Ϊ��֧������ͨ�÷���任�Ľ�ģ�������M��������������3x3�ľ���
/// ����X���ڡ�����������ת��ΪY�����桱����ת��YΪX������һ�������X = (Y - T) * M^{-1}��
/// ���������M = S * R���淽����X = S^{-1} * R^t * (Y - T)������S^{-1}�ǶԽǾ��󣬶Խ�Ԫ����S�ĵ�������R^t��R��ת�á�
/// ֧��SIMD�����������;��������ĳ˷������ഢ��һ����ξ���H = {{M,T},{0,1}}��
/// ��ת����{Y,1} = H * {X,1}����ת���� {X,1} = H^{-1} * {Y,1}��
///
/// ��Ԥ������������û�ж���MATHEMATICS_USE_MATRIX_VECTORʱ����ת����
/// ת��Ϊ Y = T + X * M������M��3x3�ľ���T��1x3��ƽ��������
/// �ڴ��������£�M = R��һ����ת���󣬻���M = R * S������R��һ����ת�����S��һ���ԽǾ�����Խ�Ԫ�����������š�
/// Ϊ��֧������ͨ�÷���任�Ľ�ģ�������M��������������3x3�ľ���
/// ����X���ڡ�����������ת��ΪY�����桱����ת��YΪX������һ�������X = M^{-1} * (Y - T)��
/// ���������M = R * S���淽����X = (Y - T) * R^t * S^{-1}������S^{-1}�ǶԽǾ��󣬶Խ�Ԫ����S�ĵ�������R^t��R��ת�á�
/// ֧��SIMD�����������;��������ĳ˷������ഢ��һ����ξ���H = {{M,0},{T,1}}��
/// ��ת����{Y,1} = {X,1} * H ����ת���� {X,1} = {Y,1} * H^{-1}��

/// ���ڳ˷�Լ��������M = R * S��MATHEMATICS_USE_MATRIX_VECTOR�������M = S * R��!MATHEMATICS_USE_MATRIX_VECTOR������Ϊ��RS���󡱡�
/// ����δ�ṩ��Ա����������任���棺��Transform GetInverse() const����
/// ���Ҫ��Ӵ����ע��RS�������ͨ������RS����
/// Ҳ����˵��R*S �� S^{-1}*R^t �����������Ǳ��ֽ�Ϊ S^{-1} * R^t = R' * S'��
/// ����Ҫʹ��S^{-1}*R^t��Ϊ���������þ���

namespace Mathematics
{
    template <typename Real>
    requires std::is_floating_point_v<Real>
    class Transform
    {
    public:
        using ClassType = Transform<Real>;

        using BufferTarget = CoreTools::BufferTarget;
        using BufferSource = CoreTools::BufferSource;

        using Math = Math<Real>;
        using Matrix = Matrix<Real>;
        using APoint = APoint<Real>;
        using AVector = AVector<Real>;
        using Vector3 = Vector3<Real>;
        using Vector4 = Vector4<Real>;
        using Matrix3 = Matrix3<Real>;
        using AQuaternion = AQuaternion<Real>;
        using Euler = Euler<Real>;
        using AxisAngle = AxisAngle<Real>;

    public:
        // Ĭ�Ϲ��캯��������λת����
        Transform() noexcept;
        explicit Transform(Real scale) noexcept;
        Transform(Real s0, Real s1, Real s2) noexcept;

        CLASS_INVARIANT_DECLARE;

        // ����ת��Ϊ��λ����
        void MakeIdentity() noexcept;

        // ����ת��������ֵΪ1��
        void MakeUnitScale();

        // ת���ṹ����ʾ��
        NODISCARD bool IsIdentity() const noexcept;  // I
        NODISCARD bool IsRotationOrScaleMatrix() const noexcept;  // R * S���Ѷ���MATHEMATICS_USE_MATRIX_VECTOR����S * R��δ����MATHEMATICS_USE_MATRIX_VECTOR��
        NODISCARD bool IsUniformScale() const noexcept;  // R * S��S = c * I

        /// ��Ա����
        /// (1) Set* ��������IsIdentity��ʾΪfalse��
        /// (2) SetRotate ��������IsRotationOrScaleMatrix��ʾΪtrue��
        ///     ��������ʾ��false��GetRotate���ܻ����һ�����ԡ�
        /// (3) SetMatrix��������IsRotationOrScaleMatrix��IsUniformScale��ʾΪfalse��
        /// (4) SetScale��������IsUniformScale��ʾΪfalse��
        ///     SetUniformScale��������IsUniformScale��ʾΪtrue��
        ///     ��������ʾ��false, GetUniformScale���ܻ����һ�����ԡ�
        /// (5) ����Set*��������inverseNeedsUpdateΪtrue��
        ///     ��GetInverseMatrix�����ã���������������뱻���¼��㣬������inverseNeedsUpdateΪfalse��

        // {{R,0},{0,1}}
        void SetRotate(const Matrix& rotate) noexcept;

        // {{M,0},{0,1}}
        void SetMatrix(const Matrix& matrix) noexcept;

        void SetTranslate(const APoint& translate) noexcept;
        void SetTranslate(Real x0, Real x1, Real x2) noexcept;
        void SetTranslate(const Vector3& translate) noexcept;
        void SetTranslate(const Vector4& translate) noexcept;
        void SetScale(const APoint& scale);
        void SetScale(Real s0, Real s1, Real s2);
        void SetScale(const Vector3& scale);
        void SetScale(const Vector4& scale);
        void SetUniformScale(Real scale);

        // {{R,0},{0,1}}
        NODISCARD Matrix GetRotate() const;

        // {{M,0},{0,1}}
        NODISCARD Matrix GetMatrix() const noexcept;

        // (x,y,z)
        NODISCARD APoint GetTranslate() const noexcept;
        NODISCARD Vector4 GetTranslationW0() const noexcept;
        NODISCARD Vector4 GetTranslationW1() const noexcept;

        // (s0,s1,s2)
        NODISCARD APoint GetScale() const;
        NODISCARD Vector4 GetScaleW1() const noexcept;

        NODISCARD Real GetUniformScale() const;

        // ��������/��ȡ��ת�ı��ñ�ʾ��

        // ��3x3����������/��ȡ��
        void SetRotation(const Matrix3& rotate);
        NODISCARD Matrix3 GetRotationMatrix3() const;

        // ��Ԫ���ǵ�λ���ȡ�
        void SetRotation(const AQuaternion& quaternion) noexcept;
        NODISCARD AQuaternion GetRotationQuaternion() const;

        void SetRotation(const AxisAngle& axisAngle);
        NODISCARD AxisAngle GetRotationAxisAngle() const;

        // Euler�Ƕ��Ի���Ϊ��λ��GetEulerAngles����Ҫ��orderֵ����Ϊ�������˳��
        void SetRotation(const Euler& eulerAngles);
        NODISCARD Euler GetRotationEuler(ExtractEulerResultOrder order) const;

        /// ����M = R * S��M = S * R�����ؾ���ֵ��S�����ֵ��
        /// ����һ���M��������MATHEMATICS_USE_MATRIX_VECTORʱ���������о���ֵ�ͣ�
        /// ���ߵ�δ����MATHEMATICS_USE_MATRIX_VECTORʱ�����о���ֵ�ͣ����Ǳ任����ģ�ĺ��������
        NODISCARD Real GetNorm() const;

        // ����-��˷�, M * p��
        NODISCARD APoint operator*(const APoint& point) const noexcept;

        // ����-�����˷�, M * v��
        NODISCARD AVector operator*(const AVector& vector) const noexcept;

        // ����-����˷���
        Transform& operator*=(const Transform& transform);

        // ��ȡ��ξ���
        NODISCARD Matrix GetHomogeneousMatrix() const noexcept;

        /// ��ȡ��ξ�����棬����Ҫʱ���¼��㡣
        /// ����MATHEMATICS_USE_MATRIX_VECTOR
        /// H = {{M,T},{0,1}}, ���� H^{-1} = {{M^{-1},-M^{-1}*T},{0,1}}��
        /// δ����MATHEMATICS_USE_MATRIX_VECTOR
        /// H = {{M,0},{T,1}}, ���� H^{-1} = {{M^{-1},0},{-M^{-1}*T,1}}
        NODISCARD Matrix GetInverseMatrix(Real epsilon = Math::GetZeroTolerance()) const;

        /// ��ȡTransform���档��ִ�в�����ȷ�����õ�ת���ǿ���ġ�
        /// Transform�档������ܣ�ͨ������ȷ���䡣
        /// ���磬��������IsRotationOrScaleMatrix���� 'true'����������IsRotationOrScaleMatrixҲ����'true'��
        /// ������������ת����scaleҲ��Ӧ�����á�
        NODISCARD Transform GetInverseTransform(Real epsilon = Math::GetZeroTolerance()) const;

        // ��֧��
        NODISCARD int GetStreamingSize() const noexcept;
        void ReadAggregate(BufferSource& source);
        void WriteAggregate(BufferTarget& target) const;

        static constexpr Transform GetIdentityTransform() noexcept
        {
            return Transform{};
        }

    private:
        using TransformMatrix = TransformMatrix<Real>;
        using AffineMatrix = AffineMatrix<Real>;

    private:
        AffineMatrix affineMatrix;
        // ������4x4��ξ���H = {{M,T},{0,1}}�����������ΪH^{-1} = {M^{-1},-M^{-1}*T},{0,1}}�� �����ֻ����Ҫʱ���㡣
        TransformMatrix transformMatrix;

        mutable Matrix inverseMatrix;
        mutable bool inverseNeedsUpdate;
    };

    template <typename Real>
    NODISCARD Transform<Real> operator*(const Transform<Real>& lhs, const Transform<Real>& rhs);

    template <typename Real>
    NODISCARD bool Approximate(const Transform<Real>& lhs, const Transform<Real>& rhs, Real epsilon = Math<Real>::GetZeroTolerance());

    // ���������
    template <typename Real>
    std::ostream& operator<<(std::ostream& out, const Transform<Real>& transform);

    using TransformF = Transform<float>;
    using TransformD = Transform<double>;
}

#endif  // MATHEMATICS_ALGEBRA_TRANSFORM_H

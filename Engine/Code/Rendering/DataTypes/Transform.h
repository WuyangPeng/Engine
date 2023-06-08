///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/03/29 16:36)

#ifndef RENDERING_DATA_TYPES_TRANSFORM_H
#define RENDERING_DATA_TYPES_TRANSFORM_H

#include "Rendering/RenderingDll.h"

#include "TransformMatrix.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Matrix.h"

namespace Rendering
{
    template <typename Real>
    class Transform
    {
    public:
        using ClassType = Transform<Real>;

        using Math = Mathematics::Math<Real>;
        using Matrix = Mathematics::Matrix<Real>;
        using APoint = Mathematics::APoint<Real>;
        using AVector = Mathematics::AVector<Real>;

    public:
        // Transform�� Y = M * X + T������M��3x3�����T��һ��ƽ��������
        // �ڴ��������£�M = R��һ����ת���󣬻���M = R * S������R��һ����ת�����S��һ���ԽǾ�����Խ�Ԫ�����������š�
        // Ϊ��֧������ͨ�÷���任�Ľ�ģ�������M��������������3x3�ľ���
        // ����X���ڡ�����������ת��ΪY�����桱����ת��YΪX������һ�������X = M^{-1} * (Y - T)��
        // ���������M = R * S���淽����X = S^{-1} * R^t * (Y - T)������S^{-1}�ǶԽǾ��󣬶Խ�Ԫ����S�ĵ�������R^t��R��ת�á�
        // ֧��SIMD�����������;��������ĳ˷������ഢ��һ����ξ���H = {{M,T},{0,1}}��
        // ��ת����{Y,1} = H * {X,1}����ת���� {X,1} = H^{-1} * {Y,1}��

        // Ĭ�Ϲ��캯��������λת����
        Transform() noexcept;

        CLASS_INVARIANT_DECLARE;

        // ����ת��Ϊ��λ����
        void MakeIdentity() noexcept;

        // ����ת��������ֵΪ1��
        void MakeUnitScale() noexcept(gAssert < 2 || gRenderingAssert < 2);

        // ת���ṹ����ʾ��
        NODISCARD bool IsIdentity() const noexcept;  // I
        NODISCARD bool IsRotationOrScaleMatrix() const noexcept;  // R * S
        NODISCARD bool IsUniformScale() const noexcept;  // R * S��S = c * I

        // ��Ա����
        // (1) Set* ��������IsIdentity��ʾΪfalse��
        // (2) SetRotate ��������IsRotationOrScaleMatrix��ʾΪtrue��
        //     ��������ʾ��false��GetRotate���ܻ����һ�����ԡ�
        // (3) SetMatrix��������IsRotationOrScaleMatrix��IsUniformScale��ʾΪfalse��
        // (4) SetScale��������IsUniformScale��ʾΪfalse��
        //     SetUniformScale��������IsUniformScale��ʾΪtrue��
        //     ��������ʾ��false, GetUniformScale���ܻ����һ�����ԡ�
        // (5) ����Set*��������m_InverseNeedsUpdateΪtrue��
        //     ��GetInverseMatrix�����ã���������������뱻���¼��㣬������m_InverseNeedsUpdateΪfalse��
        void SetRotate(const Matrix& rotate) noexcept;
        void SetMatrix(const Matrix& matrix) noexcept;
        void SetTranslate(const APoint& aTranslate) noexcept;
        void SetScale(const APoint& aScale) noexcept(gAssert < 2 || gRenderingAssert < 2);
        void SetUniformScale(Real aScale) noexcept(gAssert < 2 || gRenderingAssert < 2);
        NODISCARD Matrix GetRotate() const noexcept(gAssert < 2 || gRenderingAssert < 2);
        NODISCARD Matrix GetMatrix() const noexcept;
        NODISCARD APoint GetTranslate() const noexcept;
        NODISCARD APoint GetScale() const noexcept(gAssert < 2 || gRenderingAssert < 2);
        NODISCARD Real GetUniformScale() const noexcept(gAssert < 2 || gRenderingAssert < 2);

        // ����M = R * S��S�ľ���ֵ�����ֵ�����ء�
        // ������ͨM����������row����ֵ�ͣ���������ģ��ת���ĺ��������
        NODISCARD Real GetNorm() const;

        // ����-��˷�, M * p��
        NODISCARD APoint operator*(const APoint& point) const noexcept;

        // ����-�����˷�, M * v��
        NODISCARD AVector operator*(const AVector& vector) const noexcept;

        // ����-����˷���
        Transform& operator*=(const Transform& transform);

        // ��ȡ��ξ���
        NODISCARD Matrix GetHomogeneousMatrix() const noexcept;

        // ��ȡ��ξ�����棬����Ҫʱ���¼��㡣
        // H = {{M,T},{0,1}}, ���� H^{-1} = {{M^{-1},-M^{-1}*T},{0,1}}��
        NODISCARD Matrix GetInverseMatrix(float epsilon = Math::GetZeroTolerance()) const;

        // ��ȡTransform���档��ִ�в�����ȷ�����õ�ת���ǿ���ġ�
        NODISCARD Transform GetInverseTransform(float epsilon = Math::GetZeroTolerance()) const;

        // ��֧��
        NODISCARD int GetStreamingSize() const noexcept;

        void ReadAggregate(CoreTools::BufferSource& source);
        void WriteAggregate(CoreTools::BufferTarget& target) const;

    private:
        // ������4x4��ξ���H = {{M,T},{0,1}}�����������ΪH^{-1} = {M^{-1},-M^{-1}*T},{0,1}}�� �����ֻ����Ҫʱ���㡣
        TransformMatrix<Real> transformMatrix;

        Matrix rotationOrGeneralMatrix;  // M (��ͨ) or R (��ת)
        APoint translate;  // T
        APoint scale;  // S

        mutable Matrix inverseMatrix;
        mutable bool inverseNeedsUpdate;
    };

    template <typename Real>
    NODISCARD Transform<Real> operator*(const Transform<Real>& lhs, const Transform<Real>& rhs);

    template <typename Real>
    NODISCARD bool Approximate(const Transform<Real>& lhs, const Transform<Real>& rhs, const Real epsilon = Mathematics::Math<Real>::GetZeroTolerance());

    // ���������
    template <typename Real>
    std::ostream& operator<<(std::ostream& out, const Transform<Real>& transform);

    using TransformF = Transform<float>;
    using TransformD = Transform<double>;
}

#endif  // RENDERING_DATA_TYPES_TRANSFORM_H

//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.0.1 (2020/09/06 10:46)

#ifndef RENDERING_DATA_TYPES_TRANSFORM_H
#define RENDERING_DATA_TYPES_TRANSFORM_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Matrix.h"

namespace Rendering
{
    template <typename Real>
    class TransformImpl;

    template class RENDERING_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<TransformImpl<float>>;
    template class RENDERING_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<TransformImpl<double>>;

    template <typename Real>
    class RENDERING_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<TransformImpl<Real>>;
}

namespace Rendering
{
    template <typename Real>
    class RENDERING_TEMPLATE_DEFAULT_DECLARE Transform
    {
    public:
        using ClassType = Transform<Real>;
        using ImplType = TransformImpl<Real>;
        using ClassShareType = CoreTools::DelayCopyUnsharedClasses;

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
        Transform();

        CLASS_INVARIANT_DECLARE;

        // ����ת��Ϊ��λ����
        void MakeIdentity();

        // ����ת��������ֵΪ1��
        void MakeUnitScale();

        // ת���ṹ����ʾ��
        [[nodiscard]] bool IsIdentity() const noexcept;  // I
        [[nodiscard]] bool IsRotationOrScaleMatrix() const noexcept;  // R * S
        [[nodiscard]] bool IsUniformScale() const noexcept;  // R * S��S = c * I

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
        void SetRotate(const Matrix& rotate);
        void SetMatrix(const Matrix& matrix);
        void SetTranslate(const APoint& translate);
        void SetScale(const APoint& scale);
        void SetUniformScale(Real scale);
        [[nodiscard]] const Matrix GetRotate() const noexcept(g_Assert < 2 || g_RenderingAssert < 2);
        [[nodiscard]] const Matrix GetMatrix() const noexcept;
        [[nodiscard]] const APoint GetTranslate() const noexcept;
        [[nodiscard]] const APoint GetScale() const noexcept(g_Assert < 2 || g_RenderingAssert < 2);
        [[nodiscard]] Real GetUniformScale() const noexcept(g_Assert < 2 || g_RenderingAssert < 2);

        // ����M = R * S��S�ľ���ֵ�����ֵ�����ء�
        // ������ͨM����������row����ֵ�ͣ���������ģ��ת���ĺ��������
        [[nodiscard]] Real GetNorm() const noexcept;

        // ����-��˷�, M * p��
        [[nodiscard]] APoint operator*(const APoint& point) const noexcept;

        // ����-�����˷�, M * v��
        [[nodiscard]] AVector operator*(const AVector& vector) const noexcept;

        // ����-����˷���
        Transform& operator*=(const Transform& transform);

        // ��ȡ��ξ���
        [[nodiscard]] const Matrix GetHomogeneousMatrix() const noexcept;

        // ��ȡ��ξ�����棬����Ҫʱ���¼��㡣
        // H = {{M,T},{0,1}}, ���� H^{-1} = {{M^{-1},-M^{-1}*T},{0,1}}��
        [[nodiscard]] const Matrix GetInverseMatrix(float epsilon = Math::GetZeroTolerance()) const;

        // ��ȡTransform���档��ִ�в�����ȷ�����õ�ת���ǿ���ġ�
        [[nodiscard]] const Transform GetInverseTransform(float epsilon = Math::GetZeroTolerance()) const;

        // ��֧��
        [[nodiscard]] int GetStreamingSize() const noexcept;

        void ReadAggregate(CoreTools::BufferSource& source);
        void WriteAggregate(CoreTools::BufferTarget& target) const;

    private:
        void Copy();

    private:
        IMPL_TYPE_DECLARE(Transform);
    };

    template <typename Real>
    const Transform<Real> operator*(const Transform<Real>& lhs, const Transform<Real>& rhs);

    template <typename Real>
    bool Approximate(const Transform<Real>& lhs, const Transform<Real>& rhs, const Real epsilon = Mathematics::Math<Real>::GetZeroTolerance());

    // ���������
    template <typename Real>
    std::ostream& operator<<(std::ostream& out, const Transform<Real>& transform);

    using FloatTransform = Transform<float>;
    using DoubleTransform = Transform<double>;
}

#endif  // RENDERING_DATA_TYPES_TRANSFORM_H

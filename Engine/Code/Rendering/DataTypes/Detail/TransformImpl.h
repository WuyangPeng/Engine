// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/17 14:00)

#ifndef RENDERING_DATA_TYPES_TRANSFORM_IMPL_H
#define RENDERING_DATA_TYPES_TRANSFORM_IMPL_H

#include "Rendering/RenderingDll.h"

#include "TransformMatrix.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE TransformImpl
    {
    public:
        using ClassType = TransformImpl;
        using Matrix = Mathematics::Matrix<float>;
        using APoint = Mathematics::APoint<float>;
		using AVector = Mathematics::AVector<float>;
		using Math = Mathematics::Math<float>;

    public:
        // Transform �� Y = M * X + T������M��3x3�����T��һ��ƽ��������
        // �ڴ��������£� M = R��һ����ת���󣬻�M = R * S��
        // ����R��һ����ת�����S��һ���ԽǾ��󣬶Խ�Ԫ�����������š�
        // ֧�ֽ�ģ�����,����һ��ķ���任,M��������������3x3�ľ���
        // ����X���ڡ�����������ת��ΪY�����桱����ת��YΪX��
        // ����һ�������X = M^{-1} * (Y - T)��
        // ���������M = R * S���淽����X = S^{-1} * R^t * (Y - T)��
        // ����S^{-1}�ǶԽǾ��󣬶Խ�Ԫ����S�ĵ�������R^t ��R��ת�á�
        // ֧��SIMD�����������;��������ĳ˷�,
        // һ����ξ���H = {{M,T},{0,1}}����������ࡣ
        // ��ת����{Y,1} = H * {X,1}����ת���� {X,1} = H^{-1} * {Y,1}��
 
        // Ĭ�Ϲ��캯��������λת����
        TransformImpl ();
        
		CLASS_INVARIANT_DECLARE;
        
        // ����ת��Ϊ��λ����
        void MakeIdentity ();

         // ����ת��������ֵΪ1
        void MakeUnitScale ();

        // ת���ṹ����ʾ
        bool IsIdentity () const; // I
        bool IsRotationOrScaleMatrix () const; // R * S
        bool IsUniformScale () const; // R * S, S = c * I

        // ��Ա����
        // (1) Set* ��������Is Identity��ʾΪfalse��
        // (2) SetRotate �������� IsRotationOrScaleMatrix��ʾΪtrue��
        //     ��������ʾ��false,  GetRotate�� debug ģʽ����һ�����ԡ�
        // (3) SetMatrix��������IsRotationOrScaleMatrix��IsUniformScale
        //     ��ʾΪfalse��
        // (4) SetScale��������IsUniformScale��ʾΪfalse��
        //     SetUniformScale��������IsUniformScale��ʾΪtrue��
        //     ��������ʾ��false,  GetUniformScale�� debug ģʽ����һ�����ԡ�
        // (5) ���� Set* ��������m_InverseNeedsUpdateΪtrue��
        //     �� GetInverseMatrix�����ã���������������뱻���¼��㣬
        //     ������m_InverseNeedsUpdateΪ false��
        
        void SetRotate (const Matrix& rotate);
        void SetMatrix (const Matrix& matrix);
        void SetTranslate (const APoint& translate);
        void SetScale (const APoint& scale);
        void SetUniformScale (float scale);
        const Matrix GetRotate () const;
        const Matrix GetMatrix () const;
        const APoint GetTranslate () const;
        const APoint GetScale () const;
        float GetUniformScale () const;

        // ����M = R * S,S�ľ���ֵ�����ֵ�����ء�
        // ������ͨM������row����ֵ�ͱ����أ�
        // ����һ�����������ģת���ĵĳ̶ȡ�
        float GetNorm () const;

        // ����-��˷�, M * p��
        APoint operator* (const APoint& point) const;

        // ����-�����˷�, M * v��
        AVector operator* (const AVector& vector) const;

        // ����-����˷���
        TransformImpl& operator*= (const TransformImpl& transform);

        // ��ȡ��ξ���
        const Matrix GetHomogeneousMatrix () const;

        // ��ȡ��ξ�����棬����Ҫʱ���¼��㡣
        // H = {{M,T},{0,1}}, ���� H^{-1} = {{M^{-1},-M^{-1}*T},{0,1}}��
		const Matrix GetInverseMatrix (float epsilon = Math::sm_ZeroTolerance) const;

        // ��ȡTransform���档
        // ��ִ�в�����ȷ�����õ�ת���ǿ���ġ�
		const TransformImpl GetInverseTransform (float epsilon = Math::sm_ZeroTolerance) const;

        // ��λת��
        static const TransformImpl sm_Identity;

        // ��֧��
        int GetStreamingSize () const;
        
    private:
        // ������4x4��ξ���H = {{M,T},{0,1}}��
        // ���������ΪH^{-1} = {M^{-1},-M^{-1}*T},{0,1}}��
        // �����ֻ����Ҫʱ���㡣
        TransformMatrix m_TransformMatrix;

        Matrix m_RotationOrGeneralMatrix; // M (��ͨ) or R (��ת)
        APoint m_Translate; // T
        APoint m_Scale; // S
        
        mutable Matrix m_InverseMatrix;
        mutable bool m_InverseNeedsUpdate;
    };
    
    const TransformImpl operator* (const TransformImpl& lhs,const TransformImpl& rhs);
}

#endif // RENDERING_DATA_TYPES_TRANSFORM_IMPL_H

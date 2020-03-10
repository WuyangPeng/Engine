// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/18 11:19)

#ifndef RENDERING_DATA_TYPES_TRANSFORM_H
#define RENDERING_DATA_TYPES_TRANSFORM_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/Matrix.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"

RENDERING_EXPORT_SHARED_PTR(TransformImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Transform
    {
    public:
        DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(Transform);
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
        Transform (); 
        
		CLASS_INVARIANT_DECLARE;

        void MakeIdentity ();
        void MakeUnitScale ();

        bool IsIdentity () const; 
        bool IsRotationOrScaleMatrix () const; 
        bool IsUniformScale () const; 

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

        float GetNorm () const;

        APoint operator* (const APoint& point) const;
        AVector operator* (const AVector& vector) const;
        Transform& operator*= (const Transform& transform);

        const Matrix GetHomogeneousMatrix () const;
        const Matrix GetInverseMatrix (float epsilon = Math::sm_ZeroTolerance) const;
        const Transform GetInverseTransform (float epsilon = Math::sm_ZeroTolerance) const;

        static const Transform sm_Identity;

        int GetStreamingSize () const;

    private:
		;
		IMPL_TYPE_DECLARE(Transform);
    };
    
    RENDERING_DEFAULT_DECLARE const Transform operator* (const Transform& lhs,const Transform& rhs);

    RENDERING_DEFAULT_DECLARE bool Approximate(const Transform& lhs, const Transform& rhs,const float epsilon = Mathematics::Math<float>::sm_Epsilon);

	// ���������
	RENDERING_DEFAULT_DECLARE std::ostream& operator<< (std::ostream& outFile, const Transform& transform);
}

#endif // RENDERING_DATA_TYPES_TRANSFORM_H

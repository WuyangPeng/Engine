// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/18 11:19)

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
		// Transform 是 Y = M * X + T，这里M是3x3矩阵和T是一个平移向量。
		// 在大多数情况下， M = R，一个旋转矩阵，或M = R * S，
		// 这里R是一个旋转矩阵和S是一个对角矩阵，对角元素是正的缩放。
		// 支持建模软件包,允许一般的仿射变换,M可以是任意可逆的3x3的矩阵。
		// 向量X是在“正”方向下转换为Y，“逆”方向转换Y为X，
		// 即在一般情况下X = M^{-1} * (Y - T)。
		// 在特殊情况M = R * S，逆方向是X = S^{-1} * R^t * (Y - T)，
		// 这里S^{-1}是对角矩阵，对角元素是S的倒数，和R^t 是R的转置。
		// 支持SIMD矩阵与向量和矩阵与矩阵的乘法,
		// 一个齐次矩阵H = {{M,T},{0,1}}保存在这个类。
		// 正转换是{Y,1} = H * {X,1}和逆转换是 {X,1} = H^{-1} * {Y,1}。

		// 默认构造函数产生单位转换。
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

	// 调试输出。
	RENDERING_DEFAULT_DECLARE std::ostream& operator<< (std::ostream& outFile, const Transform& transform);
}

#endif // RENDERING_DATA_TYPES_TRANSFORM_H

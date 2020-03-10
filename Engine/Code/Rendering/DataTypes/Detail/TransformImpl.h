// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/17 14:00)

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
        TransformImpl ();
        
		CLASS_INVARIANT_DECLARE;
        
        // 设置转换为单位矩阵
        void MakeIdentity ();

         // 设置转换的缩放值为1
        void MakeUnitScale ();

        // 转换结构的提示
        bool IsIdentity () const; // I
        bool IsRotationOrScaleMatrix () const; // R * S
        bool IsUniformScale () const; // R * S, S = c * I

        // 成员访问
        // (1) Set* 函数设置Is Identity提示为false。
        // (2) SetRotate 函数设置 IsRotationOrScaleMatrix提示为true。
        //     如果这个提示是false,  GetRotate在 debug 模式产生一个断言。
        // (3) SetMatrix函数设置IsRotationOrScaleMatrix和IsUniformScale
        //     提示为false。
        // (4) SetScale函数设置IsUniformScale提示为false。
        //     SetUniformScale函数设置IsUniformScale提示为true。
        //     如果这个提示是false,  GetUniformScale在 debug 模式产生一个断言。
        // (5) 所有 Set* 函数设置m_InverseNeedsUpdate为true。
        //     当 GetInverseMatrix被调用，这种情况逆矩阵必须被重新计算，
        //     并设置m_InverseNeedsUpdate为 false。
        
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

        // 对于M = R * S,S的绝对值的最大值被返回。
        // 对于普通M，最大的row绝对值和被返回，
        // 这是一个合理的最大规模转换的的程度。
        float GetNorm () const;

        // 矩阵-点乘法, M * p。
        APoint operator* (const APoint& point) const;

        // 矩阵-向量乘法, M * v。
        AVector operator* (const AVector& vector) const;

        // 矩阵-矩阵乘法。
        TransformImpl& operator*= (const TransformImpl& transform);

        // 获取齐次矩阵。
        const Matrix GetHomogeneousMatrix () const;

        // 获取齐次矩阵的逆，当需要时重新计算。
        // H = {{M,T},{0,1}}, 这里 H^{-1} = {{M^{-1},-M^{-1}*T},{0,1}}。
		const Matrix GetInverseMatrix (float epsilon = Math::sm_ZeroTolerance) const;

        // 获取Transform的逆。
        // 不执行测试来确保调用的转换是可逆的。
		const TransformImpl GetInverseTransform (float epsilon = Math::sm_ZeroTolerance) const;

        // 单位转换
        static const TransformImpl sm_Identity;

        // 流支持
        int GetStreamingSize () const;
        
    private:
        // 完整的4x4齐次矩阵H = {{M,T},{0,1}}和
        // 它的逆矩阵为H^{-1} = {M^{-1},-M^{-1}*T},{0,1}}。
        // 逆矩阵只在需要时计算。
        TransformMatrix m_TransformMatrix;

        Matrix m_RotationOrGeneralMatrix; // M (普通) or R (旋转)
        APoint m_Translate; // T
        APoint m_Scale; // S
        
        mutable Matrix m_InverseMatrix;
        mutable bool m_InverseNeedsUpdate;
    };
    
    const TransformImpl operator* (const TransformImpl& lhs,const TransformImpl& rhs);
}

#endif // RENDERING_DATA_TYPES_TRANSFORM_IMPL_H

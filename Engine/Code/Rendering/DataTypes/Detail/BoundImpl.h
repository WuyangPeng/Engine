// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/17 13:59)

#ifndef RENDERING_DATA_TYPES_BOUND_IMPL_H
#define RENDERING_DATA_TYPES_BOUND_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/Plane.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Rendering/DataTypes/Transform.h"

namespace Rendering
{    
    class RENDERING_HIDDEN_DECLARE BoundImpl
    {
    public:
        using ClassType = BoundImpl;
        using APoint = Mathematics::APoint<float>;
        using Plane = Mathematics::Plane<float>;
        using AVector = Mathematics::AVector<float>;
        using NumericalValueSymbol = Mathematics::NumericalValueSymbol;
		using Math = Mathematics::Math<float>;
		using Vector3D = Mathematics::Vector3D<float>;

    public:
        // 边界指定为一个指定中心和半径的球体。
        BoundImpl (const APoint& center,float radius);
        
		CLASS_INVARIANT_DECLARE;
       
        // 任何边界必须定义一个中心和一个半径。
        void SetCenter (const APoint& center);
        void SetRadius (float radius);
        const APoint& GetCenter () const;
        float GetRadius () const;

		int GetStreamingSize () const;

        // 边界上的操作。
        NumericalValueSymbol WhichSide (const Plane& plane) const;
        void GrowToContain (const BoundImpl& bound);
        const BoundImpl TransformBy (const Transform& transform) const;
        void ComputeFromData (int numElements, int stride,const char* data);
		void ComputeFromData (const std::vector<APoint>& data);
		void ComputeFromData(const std::vector<Vector3D>& data);

        // 测试线性组件和边界是否相交（点相交不被计算）。
        // 线组件被参数化为P + t * D，
        // 这里P是一个组件上的点（原点），和D是一个单位向量。
        // 间隔[tmin,tmax]是
        //   line:     tmin = -Mathf::sm_MaxReal, tmax = Mathf::sm_MaxReal
        //   ray:      tmin = 0.0f, tmax = Mathf::sm_MaxReal
        //   segment:  tmin >= 0.0f, tmax > tmin
        bool TestIntersection (const APoint& origin,const AVector& direction,float tmin, float tmax) const;      
        
    private:
        APoint m_Center;
        float m_Radius;
    };    
}

#endif // RENDERING_DATA_TYPES_BOUND_IMPL_H

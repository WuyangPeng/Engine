// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/17 13:59)

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
        // �߽�ָ��Ϊһ��ָ�����ĺͰ뾶�����塣
        BoundImpl (const APoint& center,float radius);
        
		CLASS_INVARIANT_DECLARE;
       
        // �κα߽���붨��һ�����ĺ�һ���뾶��
        void SetCenter (const APoint& center);
        void SetRadius (float radius);
        const APoint& GetCenter () const;
        float GetRadius () const;

		int GetStreamingSize () const;

        // �߽��ϵĲ�����
        NumericalValueSymbol WhichSide (const Plane& plane) const;
        void GrowToContain (const BoundImpl& bound);
        const BoundImpl TransformBy (const Transform& transform) const;
        void ComputeFromData (int numElements, int stride,const char* data);
		void ComputeFromData (const std::vector<APoint>& data);
		void ComputeFromData(const std::vector<Vector3D>& data);

        // ������������ͱ߽��Ƿ��ཻ�����ཻ�������㣩��
        // �������������ΪP + t * D��
        // ����P��һ������ϵĵ㣨ԭ�㣩����D��һ����λ������
        // ���[tmin,tmax]��
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

// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/17 14:03)

#ifndef RENDERING_DATA_TYPES_BOUND_H
#define RENDERING_DATA_TYPES_BOUND_H

#include "Rendering/RenderingDll.h"

#include "Transform.h"
#include "Mathematics/Algebra/Plane.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"

RENDERING_EXPORT_SHARED_PTR(BoundImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Bound
    {
    public:
        DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(Bound);
        using APoint = Mathematics::APoint<float>;
        using Plane = Mathematics::Plane<float>;
        using AVector = Mathematics::AVector<float>;
		using Vector3D = Mathematics::Vector3D<float>;
        using NumericalValueSymbol = Mathematics::NumericalValueSymbol;
        
    public:
        Bound (const APoint& center,float radius);
		Bound();

		CLASS_INVARIANT_DECLARE;
 
        void SetCenter (const APoint& center);
        void SetRadius (float radius);
        const APoint& GetCenter () const;
        float GetRadius () const;

		int GetStreamingSize () const;
 
        NumericalValueSymbol WhichSide (const Plane& plane) const;
        void GrowToContain (const Bound& bound);
        const Bound TransformBy (const Transform& transform) const;
        void ComputeFromData (int numElements, int stride,const char* data);
		void ComputeFromData (const std::vector<APoint>& data);
		void ComputeFromData(const std::vector<Vector3D>& data);

        bool TestIntersection (const APoint& origin,const AVector& direction,float tmin, float tmax) const;  
        
    private:
  ;
		IMPL_TYPE_DECLARE(Bound);
    };

    // 测试两个固定的边界是否相交。
    RENDERING_DEFAULT_DECLARE bool TestIntersection (const Bound& lhsBound,const Bound& rhsBound);    

    // 测试两个运动的边界是否相交。
    RENDERING_DEFAULT_DECLARE bool TestIntersection (const Bound& lhsBound,const Bound::AVector& lhsVelocity,const Bound& rhsBound,
													 const Bound::AVector& rhsVelocity, float tmax);

    RENDERING_DEFAULT_DECLARE bool Approximate(const Bound& lhs, const Bound& rhs,  const float epsilon = 1e-8f);
}

#endif // RENDERING_DATA_TYPES_BOUND_H

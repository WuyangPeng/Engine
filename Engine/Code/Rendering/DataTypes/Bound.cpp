// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/18 15:07)

#include "Rendering/RenderingExport.h"

#include "Bound.h"
#include "Detail/BoundImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"

using std::vector;
using std::make_shared;

Rendering::Bound
    ::Bound(const APoint& center,float radius)
	:m_Impl{ make_shared<ImplType>(center,radius) }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Bound
	::Bound()
	:m_Impl{ make_shared<ImplType>(APoint::sm_Origin,0.0f) } 
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Rendering,Bound)

DELAY_COPY_CONSTRUCTION_DEFINE(Rendering,Bound)

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Rendering,Bound,SetCenter,APoint,void);
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Rendering,Bound,SetRadius,float,void);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Bound,GetCenter,const Rendering::Bound::APoint&);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Bound,GetRadius,float);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Bound,GetStreamingSize,int);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering,Bound,WhichSide,Plane, Mathematics::NumericalValueSymbol);

void Rendering::Bound
	::GrowToContain( const Bound& bound )
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT; 

	return m_Impl->GrowToContain(*bound.m_Impl);
}

const Rendering::Bound Rendering::Bound
    ::TransformBy (const Transform& transform) const
{    
    RENDERING_CLASS_IS_VALID_CONST_1;

	Bound bound{ APoint(),0.0f };
    
    *bound.m_Impl = m_Impl->TransformBy(transform);

    return bound;
}

void Rendering::Bound
    ::ComputeFromData (int numElements, int stride,const char* data)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;
    
    return m_Impl->ComputeFromData(numElements,stride,data);
}

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Rendering,Bound,ComputeFromData,vector<APoint>,void); 

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Rendering,Bound,ComputeFromData,vector<Vector3D>,void);

bool Rendering::Bound
    ::TestIntersection (const APoint& origin,const AVector& direction,float tmin, float tmax) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_Impl->TestIntersection(origin,direction,tmin,tmax);
}

bool Rendering
    ::TestIntersection (const Bound& lhsBound,const Bound& rhsBound)
{
    if (lhsBound.GetRadius() <= 0.0f || rhsBound.GetRadius() <= 0.0f)
    {
        // 其中一个边界是无效的，不相交。
        return false;
    }

    // 测试静态球和静态球的相交。
    auto difference = lhsBound.GetCenter() - rhsBound.GetCenter();
	auto radiusSum = lhsBound.GetRadius() + rhsBound.GetRadius();

    return difference.SquaredLength() <= radiusSum * radiusSum;
}

bool Rendering
    ::TestIntersection (const Bound& lhsBound, const Bound::AVector& lhsVelocity, const Bound& rhsBound,
				        const Bound::AVector& rhsVelocity,  float tmax)
{
    if (lhsBound.GetRadius() <= 0.0f || rhsBound.GetRadius() <= 0.0f)
    {
        // 其中一个边界是无效的，不相交。
        return false;
    }

    // 测试动态球和动态球的相交。
	auto realVelocity = rhsVelocity - lhsVelocity;
	auto centerDifference = rhsBound.GetCenter() - lhsBound.GetCenter();;
	auto realVelocitySquaredLength = realVelocity.SquaredLength();
	auto centerDifferenceSquaredLength = centerDifference.SquaredLength();
	auto radiusSum = lhsBound.GetRadius() + rhsBound.GetRadius();
	auto radiusSumSquared = radiusSum * radiusSum;

    if (0.0f < realVelocitySquaredLength)
    {
		auto dot = Dot(centerDifference,realVelocity);
        if (dot <= 0.0f)
        {
            if (-tmax * realVelocitySquaredLength <= dot)
            {
                return realVelocitySquaredLength * centerDifferenceSquaredLength - dot * dot <= 
                       realVelocitySquaredLength * radiusSumSquared;
            }
            else
            {
                return tmax * (tmax * realVelocitySquaredLength + 2.0f * dot) + 
                       centerDifferenceSquaredLength <= radiusSumSquared;
            }
        }
    }

    return centerDifferenceSquaredLength <= radiusSumSquared;
}

bool Rendering
    ::Approximate(const Bound& lhs, const Bound& rhs, const float epsilon)
{
    if (Approximate(lhs.GetCenter (),rhs.GetCenter (),epsilon) && Mathematics::Mathf::Approximate(lhs.GetRadius(),rhs.GetRadius(),epsilon))
         return true;
    else
         return false;
}
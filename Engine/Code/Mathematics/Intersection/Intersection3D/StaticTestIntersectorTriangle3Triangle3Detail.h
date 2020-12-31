// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/17 14:19)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_TRIANGLE3_DETAIL_H

#include "StaticTestIntersectorTriangle3Triangle3.h"
#include "Detail/TriangleProjectOntoAxisDetail.h"
#include "Mathematics/Objects3D/Line3Detail.h"
#include "Mathematics/Objects3D/Plane3Detail.h"
#include "Mathematics/Objects3D/Triangle3Detail.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Intersection/IntersectorDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersectorTriangle3Triangle3<Real>
	::StaticTestIntersectorTriangle3Triangle3(const Triangle3& lhsTriangle,const Triangle3& rhsTriangle, const Real epsilon)
	:ParentType{ epsilon }, m_LhsTriangle{ lhsTriangle }, m_RhsTriangle{ rhsTriangle }
{
	Test();

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

// private
template <typename Real>
void Mathematics::StaticTestIntersectorTriangle3Triangle3<Real>
	::Test()
{
	// 获取m_LhsTriangle的边向量
	auto lhsEdge = m_LhsTriangle.GetEdgeVectors(); 

	// 获取m_LhsTriangle的法线
	auto lhsNormal = m_LhsTriangle.GetNormal();

  	// 将三角形m_RhsTriangle投影到三角形m_LhsTriangle的法线上，进行分割测试。
	auto lhsNormalDotVertex0 = Vector3DTools::DotProduct(lhsNormal, m_LhsTriangle.GetVertex(0));

	TriangleProjectOntoAxis<Real> rhsTriangleProjectOntoAxis{ m_RhsTriangle, lhsNormal };
     
	if (lhsNormalDotVertex0 < rhsTriangleProjectOntoAxis.GetMin() || rhsTriangleProjectOntoAxis.GetMax() < lhsNormalDotVertex0)
    {
        return;
    }

	// 获取m_RhsTriangle的边向量
	auto rhsEdge = m_RhsTriangle.GetEdgeVectors();

	// 获取m_RhsTriangle的法线
	auto rhsNormal = m_RhsTriangle.GetNormal();

	auto lhsNormalCrossRhsNormal = Vector3DTools::UnitCrossProduct(lhsNormal, rhsNormal);

	if (this->GetEpsilon() <= Vector3DTools::DotProduct(lhsNormalCrossRhsNormal, lhsNormalCrossRhsNormal))
    {
        // 三角形不平行。

		// 将三角形m_LhsTriangle投影到三角形m_RhsTriangle的法线上，进行分割测试。
		auto rhsNormalDotVertex0 = Vector3DTools::DotProduct(rhsNormal, m_RhsTriangle.GetVertex(0));

		TriangleProjectOntoAxis<Real> lhsTriangleProjectOntoAxis{ m_LhsTriangle, rhsNormal };

		if (rhsNormalDotVertex0 < lhsTriangleProjectOntoAxis.GetMin() || lhsTriangleProjectOntoAxis.GetMax() < rhsNormalDotVertex0)
		{
			return;
		}      

        // 方向 lhsEdge[lhsIndex] X rhsEdge[rhsIndex]
        for (auto rhsIndex = 0; rhsIndex < 3; ++rhsIndex)
        {
            for (auto lhsIndex = 0; lhsIndex < 3; ++lhsIndex)
            {
				auto dir = Vector3DTools::UnitCrossProduct(lhsEdge[lhsIndex],rhsEdge[rhsIndex]);
                
				TriangleProjectOntoAxis<Real> lhsTriangleProjectOntoDir{ m_LhsTriangle, dir };
				TriangleProjectOntoAxis<Real> rhsTriangleProjectOntoDir{ m_RhsTriangle, dir };
				
				if (lhsTriangleProjectOntoDir.GetMax() < rhsTriangleProjectOntoDir.GetMin() || rhsTriangleProjectOntoDir.GetMax() < lhsTriangleProjectOntoDir.GetMin())
                {
                    return;
                }
            }
        }

 		// 测试查询不知道交集。
		this->SetIntersectionType(IntersectionType::Other);
    }
    else  // 三角形是平行的（并且事实上是共面的）。
    {
      	// 方向 m_LhsTriangle X lhsEdge[index]
        for (auto index = 0; index < 3; ++index)
        {
			auto dir = Vector3DTools::UnitCrossProduct(lhsNormal, lhsEdge[index]);
			
			TriangleProjectOntoAxis<Real> lhsTriangleProjectOntoDir{ m_LhsTriangle, dir };
			TriangleProjectOntoAxis<Real> rhsTriangleProjectOntoDir{ m_RhsTriangle, dir };

			if (lhsTriangleProjectOntoDir.GetMax() < rhsTriangleProjectOntoDir.GetMin() || rhsTriangleProjectOntoDir.GetMax() < lhsTriangleProjectOntoDir.GetMin())
			{
				return;
			}            
        }

   		// 方向 m_RhsTriangle X rhsEdge[index]
		for (auto index = 0; index < 3; ++index)
        {
			auto dir = Vector3DTools::UnitCrossProduct(rhsNormal, rhsEdge[index]);

			TriangleProjectOntoAxis<Real> lhsTriangleProjectOntoDir{ m_LhsTriangle, dir };
			TriangleProjectOntoAxis<Real> rhsTriangleProjectOntoDir{ m_RhsTriangle, dir };

			if (lhsTriangleProjectOntoDir.GetMax() < rhsTriangleProjectOntoDir.GetMin() || rhsTriangleProjectOntoDir.GetMax() < lhsTriangleProjectOntoDir.GetMin())
			{
				return;
			}
        }

		// 测试查询不知道交集。
		this->SetIntersectionType(IntersectionType::Plane);
    }
}

template <typename Real>
Mathematics::StaticTestIntersectorTriangle3Triangle3<Real>
	::~StaticTestIntersectorTriangle3Triangle3()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}


#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticTestIntersectorTriangle3Triangle3<Real>
	::IsValid() const noexcept
{
	if(ParentType::IsValid())
		return true;
	else
		return false;
}

#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::StaticTestIntersectorTriangle3Triangle3<Real>::Triangle3 Mathematics::StaticTestIntersectorTriangle3Triangle3<Real>
	::GetLhsTriangle() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_LhsTriangle;
}


template <typename Real>
typename const Mathematics::StaticTestIntersectorTriangle3Triangle3<Real>::Triangle3 Mathematics::StaticTestIntersectorTriangle3Triangle3<Real>
	::GetRhsTriangle() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_RhsTriangle;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_TRIANGLE3_DETAIL_H
 
    
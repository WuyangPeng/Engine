// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/17 14:19)

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
	// ��ȡm_LhsTriangle�ı�����
	auto lhsEdge = m_LhsTriangle.GetEdgeVectors(); 

	// ��ȡm_LhsTriangle�ķ���
	auto lhsNormal = m_LhsTriangle.GetNormal();

  	// ��������m_RhsTriangleͶӰ��������m_LhsTriangle�ķ����ϣ����зָ���ԡ�
	auto lhsNormalDotVertex0 = Vector3DTools::DotProduct(lhsNormal, m_LhsTriangle.GetVertex(0));

	TriangleProjectOntoAxis<Real> rhsTriangleProjectOntoAxis{ m_RhsTriangle, lhsNormal };
     
	if (lhsNormalDotVertex0 < rhsTriangleProjectOntoAxis.GetMin() || rhsTriangleProjectOntoAxis.GetMax() < lhsNormalDotVertex0)
    {
        return;
    }

	// ��ȡm_RhsTriangle�ı�����
	auto rhsEdge = m_RhsTriangle.GetEdgeVectors();

	// ��ȡm_RhsTriangle�ķ���
	auto rhsNormal = m_RhsTriangle.GetNormal();

	auto lhsNormalCrossRhsNormal = Vector3DTools::UnitCrossProduct(lhsNormal, rhsNormal);

	if (this->GetEpsilon() <= Vector3DTools::DotProduct(lhsNormalCrossRhsNormal, lhsNormalCrossRhsNormal))
    {
        // �����β�ƽ�С�

		// ��������m_LhsTriangleͶӰ��������m_RhsTriangle�ķ����ϣ����зָ���ԡ�
		auto rhsNormalDotVertex0 = Vector3DTools::DotProduct(rhsNormal, m_RhsTriangle.GetVertex(0));

		TriangleProjectOntoAxis<Real> lhsTriangleProjectOntoAxis{ m_LhsTriangle, rhsNormal };

		if (rhsNormalDotVertex0 < lhsTriangleProjectOntoAxis.GetMin() || lhsTriangleProjectOntoAxis.GetMax() < rhsNormalDotVertex0)
		{
			return;
		}      

        // ���� lhsEdge[lhsIndex] X rhsEdge[rhsIndex]
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

 		// ���Բ�ѯ��֪��������
		this->SetIntersectionType(IntersectionType::Other);
    }
    else  // ��������ƽ�еģ�������ʵ���ǹ���ģ���
    {
      	// ���� m_LhsTriangle X lhsEdge[index]
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

   		// ���� m_RhsTriangle X rhsEdge[index]
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

		// ���Բ�ѯ��֪��������
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
 
    
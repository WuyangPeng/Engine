// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/19 19:22)

#ifndef RENDERING_SCENE_GRAPH_PICKER_IMPL_H
#define RENDERING_SCENE_GRAPH_PICKER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/SceneGraph/Spatial.h"
#include "Rendering/SceneGraph/PickRecordContainer.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE PickerImpl
	{
	public:
		using ClassType = PickerImpl;
		using APoint = Mathematics::APoint<float>;
		using AVector = Mathematics::AVector<float>;

	public:
		// ���Բ������ĳɷ���P + t * D��
		// P��һ����ĳɷ�(P��ԭ��),D��һ����λ���ȷ���,
		// t��һ��������[tmin,tmax]�ı��������� tmin < tmax��
		// P��Dֵ�������������ꡣtmin��tmax��ѡ������
		// ֱ��:  tmin = -Mathf::sm_MaxReal, tmax = Mathf::sm_MaxReal
		// ����:  tmin = 0, tmax = Mathematics::Mathf::sm_MaxReal
		// �߶�:  tmin = 0, tmax > 0;
		PickerImpl(const ConstSpatialSharedPtr& scene, const APoint& origin,const AVector& direction, float tMin, float tMax);

		CLASS_INVARIANT_DECLARE;

		bool IsRecordsExist() const noexcept;
		
		// ��������������������Լ���ļ�¼��
		// ����Ӧ����0 < m_Records.GetSize()ʱ���á�

		// ��λ��¼����С����ֵ��Tֵ��
		const PickRecord GetClosestToZero () const;
		
		// ��λ��¼��ӽ������Ǹ�ֵ��Tֵ��
		const PickRecord GetClosestNonnegative () const;
		
		// ��λ��¼��ӽ���������ֵ��Tֵ��
		const PickRecord GetClosestNonpositive () const;    
		
	private:
		// ѡ�����ݹ���������볡����
		void ExecuteRecursive(const ConstSpatialSharedPtr& object);
		
		APoint m_Origin;
		AVector m_Direction;
		float m_TMin;
		float m_TMax;
		
		// �������еļ�¼��ѡ�������
		PickRecordContainer m_Records;
	};
}

#endif // RENDERING_SCENE_GRAPH_PICKER_IMPL_H

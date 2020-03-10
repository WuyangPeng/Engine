// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/19 19:23)

#ifndef RENDERING_SCENE_GRAPH_PICK_RECORD_IMPL_H
#define RENDERING_SCENE_GRAPH_PICK_RECORD_IMPL_H

#include "Rendering/SceneGraph/Spatial.h"

#include <boost/operators.hpp>

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE PickRecordImpl : private boost::totally_ordered<PickRecordImpl>
	{
	public:
		using ClassType = PickRecordImpl;
		
	public:	
		// ������֧��const static PickRecord��Picker���졣
		PickRecordImpl();
		PickRecordImpl(const PickRecordImpl& rhs);
		PickRecordImpl& operator = (const PickRecordImpl& rhs);

		CLASS_INVARIANT_DECLARE;

		ConstSpatialSmartPointer GetIntersected() const;
		float GetParameter() const;
		int GetTriangle() const;
		float GetBary(int index) const;

		void SetIntersected(const ConstSpatialSmartPointer& intersected);
		void SetParameter(float parameter);		
		void SetTriangle(int triangle);		
		void SetBary(float firstBary, float secondBary);
 
	private:		
		// �ָ�Ķ���
		ConstSpatialSmartPointer m_Intersected;
		
		// �����������P + t * D����������Աm_Parameter�ǲ���t�ڽ����ֵ��
		float m_Parameter;
		
		// �����ཻ�������ε�������
		int m_Triangle;		

		static const int sm_BarySize = 3;
 
		// ������������ꡣ���е���������[0,1]��b0 + b1 + b2 = 1��
		float m_Bary[sm_BarySize];
	};

	bool operator== (const PickRecordImpl& lhs, const PickRecordImpl& rhs);
	bool operator<  (const PickRecordImpl& lhs, const PickRecordImpl& rhs);
}

#endif // RENDERING_SCENE_GRAPH_PICK_RECORD_IMPL_H

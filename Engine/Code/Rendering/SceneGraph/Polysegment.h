// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/22 11:40)

#ifndef RENDERING_SCENE_GRAPH_POLYSEGMENT_H
#define RENDERING_SCENE_GRAPH_POLYSEGMENT_H

#include "Rendering/RenderingDll.h"

#include "Visual.h" 

namespace Rendering
{	
	class RENDERING_DEFAULT_DECLARE Polysegment : public Visual	
	{
	public:
		using ClassType = Polysegment;
		using ParentType = Visual;
		using ClassShareType = CoreTools::CopyUnsharedClasses;
		using PolysegmentSmartPointer = CoreTools::SeventhSubclassSmartPointer<ClassType>;
		using ConstPolysegmentSmartPointer = CoreTools::ConstSeventhSubclassSmartPointer<ClassType>;

	public:
		// ���'contiguous'��'true'����ö����γ�������������polysegment��ÿ�������Ķ��������߶����ӡ�
		// ���磬{ V0, V1, V2, V3 } ��ʽ�߶�<V0, V1>, <V1, V2>, and <V2, V3>��
		// ���������һ����յ�polysegment�����붥�㻺���������һ��Ԫ�ر����ǵ�һ��Ԫ�صĸ�����
		// ���磬{V0, V1, V2, V3 = V0}�γɾ����߶ε�������<V0, V1>, <V1, V2>, and <V2, V0>��
		// ���'contiguous'��'false'�������γ�һ��Ͽ����߶Ρ�
		// ���磬{V0, V1, V2, V3}��ʽ�߶�<V0, V1>�� <V2, V3>��
		// ����������£����붥�㻺�����������ż����Ŀ��Ԫ�ء�
		Polysegment(const VertexFormatSmartPointer& vertexformat,const VertexBufferSmartPointer& vertexbuffer,bool contiguous);
		virtual ~Polysegment();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Polysegment); 
		
		// ����Ӧ�ó���ָ��������С��polysegment���߶��������ڻ��ơ�
		// ����һ��������polysegment��0 <= numSegments <= numVertices - 1��
		// ���ڲ��ཻ���߶Σ�0 <= numSegments <= numVertices / 2�� 
		int GetMaxNumSegments () const;
		void SetNumSegments (int numSegments);
		int GetNumSegments () const;

	    // ��'contiguous'��'true'������polysegment�������߶ε����С�
		// ����һ�鲻�ཻ��ʱ��'contiguous'��'false'��
		bool GetContiguous () const;

		virtual ControllerInterfaceSmartPointer Clone() const override;
		
	private:
		// ��ǰ��߶ε�����
		int m_NumSegments;		
 
		// �������������ཻ���߶�
		bool m_Contiguous;
	};

	CORE_TOOLS_STREAM_REGISTER(Polysegment);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Seventh, Polysegment); 
}

#endif // RENDERING_SCENE_GRAPH_POLYSEGMENT_H

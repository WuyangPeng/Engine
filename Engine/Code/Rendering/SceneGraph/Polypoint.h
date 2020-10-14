// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/22 11:37)

#ifndef RENDERING_SCENE_GRAPH_POLYPOINT_H
#define RENDERING_SCENE_GRAPH_POLYPOINT_H

#include "Rendering/RenderingDll.h"

#include "Visual.h"

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE Polypoint : public Visual
	{
	public:
		using ClassType = Polypoint;
		using ParentType = Visual;
		using ClassShareType = CoreTools::CopyUnsharedClasses;
		using PolypointSharedPtr = std::shared_ptr<ClassType>;
		using ConstPolypointSharedPtr = std::shared_ptr<ClassType>;

	public:
		Polypoint(const VertexFormatSharedPtr& vertexformat,const VertexBufferSharedPtr& vertexbuffer);
	 
                
		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Polypoint);	
 
		// ����Ӧ�ó���ָ��������С�����ֵ���ڻ��ơ�
                int GetMaxNumPoints() const ;
		void SetNumPoints (int numPoints);
                int GetNumPoints() const noexcept;

		  ControllerInterfaceSharedPtr Clone() const override;
                ObjectInterfaceSharedPtr CloneObject() const override;
	private:	
		// ��ǰ����������
		int m_NumPoints;
	};
	
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(Polypoint);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( Polypoint); 
}

#endif // RENDERING_SCENE_GRAPH_POLYPOINT_H

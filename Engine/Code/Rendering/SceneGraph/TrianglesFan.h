// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 15:05)

#ifndef RENDERING_SCENE_GRAPH_TRIANGLES_FAN_H
#define RENDERING_SCENE_GRAPH_TRIANGLES_FAN_H

#include "Rendering/RenderingDll.h"

#include "Triangles.h"  

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE TrianglesFan : public Triangles
	{
	public:
		using ClassType = TrianglesFan;
		using ParentType = Triangles;
		using ClassShareType = CoreTools::CopyUnsharedClasses;

	public:
		TrianglesFan(const VertexFormatSharedPtr& vertexformat,const VertexBufferSharedPtr& vertexbuffer,int indexSize);
		TrianglesFan(const VertexFormatSharedPtr& vertexformat,const VertexBufferSharedPtr& vertexbuffer,const IndexBufferSharedPtr& indexbuffer);
		 

		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(TrianglesFan);
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE;  
		
	public:
		// 索引缓冲区数据的解释。
		  int GetNumTriangles() const override;
		  const TriangleIndex GetTriangle(int index) const override;
                  ObjectInterfaceSharedPtr CloneObject() const override;
		  ControllerInterfaceSharedPtr Clone() const override;
	};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(TrianglesFan);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( TrianglesFan); 
}

#endif // RENDERING_SCENE_GRAPH_TRIANGLES_FAN_H

 
// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 15:06)

#ifndef RENDERING_SCENE_GRAPH_TRIANGLES_STRIP_H
#define RENDERING_SCENE_GRAPH_TRIANGLES_STRIP_H

#include "Rendering/RenderingDll.h"

#include "Triangles.h"  

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE TrianglesStrip : public Triangles
	{
	public:
		using ClassType = TrianglesStrip;
		using ParentType = Triangles;
		using ClassShareType = CoreTools::CopyUnsharedClasses;

	public:
		TrianglesStrip(const VertexFormatSmartPointer& vertexformat,const VertexBufferSmartPointer& vertexbuffer,int indexSize);
		TrianglesStrip(const VertexFormatSmartPointer& vertexformat,const VertexBufferSmartPointer& vertexbuffer,const IndexBufferSmartPointer& indexbuffer);
 

		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(TrianglesStrip);
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE;  
		
	public:
		// 索引缓冲区数据的解释。
		  int GetNumTriangles() const override;
		  const TriangleIndex GetTriangle(int index) const override;

		  ControllerInterfaceSmartPointer Clone() const override;
	};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(TrianglesStrip);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Eighth, TrianglesStrip); 
}

#endif // RENDERING_SCENE_GRAPH_TRIANGLES_STRIP_H


 
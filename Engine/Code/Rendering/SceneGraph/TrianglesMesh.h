// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 15:06)

#ifndef RENDERING_SCENE_GRAPH_TRIANGLES_MESH_H
#define RENDERING_SCENE_GRAPH_TRIANGLES_MESH_H

#include "Rendering/RenderingDll.h"

#include "Triangles.h"  

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE TrianglesMesh : public Triangles	
	{
	public:
		using ClassType = TrianglesMesh;
		using ParentType = Triangles;
		using ClassShareType = CoreTools::CopyUnsharedClasses;

	public:
		TrianglesMesh(const VertexFormatSmartPointer& vertexformat,const VertexBufferSmartPointer& vertexbuffer,const IndexBufferSmartPointer& indexbuffer);
		virtual ~TrianglesMesh();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(TrianglesMesh);
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE;   
		
	public:
		// 索引缓冲区数据的解释。
		virtual int GetNumTriangles() const override;
		virtual const TriangleIndex GetTriangle(int index) const override;

		virtual ControllerInterfaceSmartPointer Clone() const override;
	};

	CORE_TOOLS_STREAM_REGISTER(TrianglesMesh);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Eighth, TrianglesMesh); 
}

#endif // RENDERING_SCENE_GRAPH_TRIANGLES_MESH_H

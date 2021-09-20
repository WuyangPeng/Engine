// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/26 15:07)

#ifndef RENDERING_RENDERERS_VERTEX_FORMAT_MANAGEMENT_IMPL_H
#define RENDERING_RENDERERS_VERTEX_FORMAT_MANAGEMENT_IMPL_H

#include "Rendering/RenderingDll.h"

#include <map>
#include <memory>
#include "../../Resources/VertexFormat.h"

namespace Rendering
{
	class VertexFormat;
	class PlatformVertexFormat;
	class Renderer;

	class RENDERING_HIDDEN_DECLARE VertexFormatManagementImpl 
	{
	public:
		using  ClassType = VertexFormatManagementImpl;
	 using FactoryType = ClassType;
		using PlatformVertexFormatSharedPtr = std::shared_ptr<PlatformVertexFormat>;
	    using RendererPtr = std::shared_ptr<Renderer>;

	public:
		explicit VertexFormatManagementImpl(RendererPtr ptr);

		CLASS_INVARIANT_DECLARE;
		 
       // 顶点格式管理。顶点格式对象必须是已经分配，
       // 它的属性和跨距由应用程序代码进行设置。
       void Bind (ConstVertexFormatSharedPtr vertexFormat); 
       void Unbind (ConstVertexFormatSharedPtr vertexFormat);
 
       void Enable (ConstVertexFormatSharedPtr vertexFormat);
       void Disable (ConstVertexFormatSharedPtr vertexFormat);

       PlatformVertexFormatSharedPtr GetResource (ConstVertexFormatSharedPtr vertexFormat);

	private:
       using VertexFormatMap = std::map<ConstVertexFormatSharedPtr, PlatformVertexFormatSharedPtr>;

	private:
		std::weak_ptr<Renderer> m_Renderer;
	   VertexFormatMap m_VertexFormats;	 
	};
}

#endif // RENDERING_RENDERERS_VERTEX_FORMAT_MANAGEMENT_IMPL_H



	
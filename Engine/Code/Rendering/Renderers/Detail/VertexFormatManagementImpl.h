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

namespace Rendering
{
	class VertexFormat;
	class PlatformVertexFormat;
	class Renderer;

	class RENDERING_HIDDEN_DECLARE VertexFormatManagementImpl 
	{
	public:
		using  ClassType = VertexFormatManagementImpl;
		using VertexFormatConstPtr = const VertexFormat*;
		using PlatformVertexFormatSharedPtr = std::shared_ptr<PlatformVertexFormat>;
	    using RendererPtr = Renderer*;

	public:
		explicit VertexFormatManagementImpl(RendererPtr ptr);

		CLASS_INVARIANT_DECLARE;
	
       // 顶点格式管理。顶点格式对象必须是已经分配，
       // 它的属性和跨距由应用程序代码进行设置。
       void Bind (VertexFormatConstPtr vertexFormat); 
       void Unbind (VertexFormatConstPtr vertexFormat);
 
       void Enable (VertexFormatConstPtr vertexFormat);
       void Disable (VertexFormatConstPtr vertexFormat);

       PlatformVertexFormatSharedPtr GetResource (VertexFormatConstPtr vertexFormat);

	private:
       using VertexFormatMap = std::map<VertexFormatConstPtr, PlatformVertexFormatSharedPtr>;

	private:
	   RendererPtr m_Renderer;
	   VertexFormatMap m_VertexFormats;	 
	};
}

#endif // RENDERING_RENDERERS_VERTEX_FORMAT_MANAGEMENT_IMPL_H



	
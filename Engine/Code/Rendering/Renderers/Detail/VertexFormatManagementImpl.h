// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/26 15:07)

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
	
       // �����ʽ���������ʽ����������Ѿ����䣬
       // �������ԺͿ����Ӧ�ó������������á�
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



	
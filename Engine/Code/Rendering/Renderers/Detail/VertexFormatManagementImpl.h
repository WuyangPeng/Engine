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
	 
		using PlatformVertexFormatSharedPtr = std::shared_ptr<PlatformVertexFormat>;
	    using RendererPtr = std::shared_ptr<Renderer>;

	public:
		explicit VertexFormatManagementImpl(RendererPtr ptr);

		CLASS_INVARIANT_DECLARE;
		 
       // �����ʽ���������ʽ����������Ѿ����䣬
       // �������ԺͿ����Ӧ�ó������������á�
       void Bind (ConstVertexFormatSmartPointer vertexFormat); 
       void Unbind (ConstVertexFormatSmartPointer vertexFormat);
 
       void Enable (ConstVertexFormatSmartPointer vertexFormat);
       void Disable (ConstVertexFormatSmartPointer vertexFormat);

       PlatformVertexFormatSharedPtr GetResource (ConstVertexFormatSmartPointer vertexFormat);

	private:
       using VertexFormatMap = std::map<ConstVertexFormatSmartPointer, PlatformVertexFormatSharedPtr>;

	private:
		std::weak_ptr<Renderer> m_Renderer;
	   VertexFormatMap m_VertexFormats;	 
	};
}

#endif // RENDERING_RENDERERS_VERTEX_FORMAT_MANAGEMENT_IMPL_H



	
// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/26 16:07)

#ifndef RENDERING_RENDERERS_VERTEX_FORMAT_MANAGEMENT_H
#define RENDERING_RENDERERS_VERTEX_FORMAT_MANAGEMENT_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include "../Resources/VertexFormat.h"

RENDERING_EXPORT_SHARED_PTR(VertexFormatManagementImpl);
EXPORT_NONCOPYABLE_CLASS(RENDERING);

namespace Rendering
{
	class VertexFormat;
	class PlatformVertexFormat;	
	class Renderer;

	class RENDERING_DEFAULT_DECLARE VertexFormatManagement : boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(VertexFormatManagement);
		using PlatformVertexFormatPtr = std::shared_ptr<PlatformVertexFormat>;
	    using RendererPtr = std::shared_ptr<Renderer>;

	public:
		explicit VertexFormatManagement(RendererPtr ptr);
		 
		CLASS_INVARIANT_DECLARE;
	
       // �����ʽ���������ʽ����������Ѿ����䣬
       // �������ԺͿ����Ӧ�ó������������á�
       void Bind (ConstVertexFormatSharedPtr vertexFormat); 
       void Unbind (ConstVertexFormatSharedPtr vertexFormat);
 
       void Enable (ConstVertexFormatSharedPtr vertexFormat);
       void Disable (ConstVertexFormatSharedPtr vertexFormat);

       PlatformVertexFormatPtr GetResource (ConstVertexFormatSharedPtr vertexFormat);

	private:
		IMPL_TYPE_DECLARE(VertexFormatManagement);
	};
}

#endif // RENDERING_RENDERERS_VERTEX_FORMAT_MANAGEMENT_H



	
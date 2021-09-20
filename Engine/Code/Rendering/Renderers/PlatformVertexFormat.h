// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/26 15:33)

#ifndef RENDERING_RENDERERS_PLATFORM_VERTEX_FORMAT_H
#define RENDERING_RENDERERS_PLATFORM_VERTEX_FORMAT_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include <boost/noncopyable.hpp>

RENDERING_NON_COPY_EXPORT_IMPL(PlatformVertexFormatImpl); 

namespace Rendering
{
    class Renderer;
    class VertexFormat;

	class RENDERING_DEFAULT_DECLARE PlatformVertexFormat  
    {
	public:
        NON_COPY_TYPE_DECLARE(PlatformVertexFormat);

    public:
        PlatformVertexFormat (Renderer* renderer, const VertexFormat* vertexFormat);
        ~PlatformVertexFormat ();
		PlatformVertexFormat(const PlatformVertexFormat&) = delete;
		PlatformVertexFormat& operator=(const PlatformVertexFormat&) = delete;
		PlatformVertexFormat( PlatformVertexFormat&&) = delete;
		PlatformVertexFormat& operator=( PlatformVertexFormat&&) = delete;
		
		CLASS_INVARIANT_DECLARE;

        // �����ʽ������
        void Enable (Renderer* renderer);
        void Disable (Renderer* renderer);

	private:
        PackageType impl;
    };
}

#endif // RENDERING_RENDERERS_PLATFORM_VERTEX_FORMAT_H

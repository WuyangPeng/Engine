// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/26 15:33)

#ifndef RENDERING_RENDERERS_PLATFORM_VERTEX_FORMAT_H
#define RENDERING_RENDERERS_PLATFORM_VERTEX_FORMAT_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>

RENDERING_EXPORT_SHARED_PTR(PlatformVertexFormatImpl);
EXPORT_NONCOPYABLE_CLASS(RENDERING);

namespace Rendering
{
    class Renderer;
    class VertexFormat;

	class RENDERING_DEFAULT_DECLARE PlatformVertexFormat : boost::noncopyable
    {
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(PlatformVertexFormat);

    public:
        PlatformVertexFormat (Renderer* renderer, const VertexFormat* vertexFormat);
        ~PlatformVertexFormat ();

		CLASS_INVARIANT_DECLARE;

        // 顶点格式操作。
        void Enable (Renderer* renderer);
        void Disable (Renderer* renderer);

	private:
		IMPL_TYPE_DECLARE(PlatformVertexFormat);
    };
}

#endif // RENDERING_RENDERERS_PLATFORM_VERTEX_FORMAT_H

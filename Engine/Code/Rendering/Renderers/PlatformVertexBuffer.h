// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/26 15:33)

#ifndef RENDERING_RENDERERS_PLATFORM_VERTEX_BUFFER_H
#define RENDERING_RENDERERS_PLATFORM_VERTEX_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Resources/Flags/BufferFlags.h"

#include <boost/noncopyable.hpp>

RENDERING_EXPORT_SHARED_PTR(PlatformVertexBufferImpl);
EXPORT_NONCOPYABLE_CLASS(RENDERING);

namespace Rendering
{
	class Renderer;
	class VertexBuffer;
	
	class RENDERING_DEFAULT_DECLARE PlatformVertexBuffer  : boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(PlatformVertexBuffer); 
		using BufferType = VertexBuffer;

	public:
		PlatformVertexBuffer (Renderer* renderer, const VertexBuffer* vertexBuffer);
		~PlatformVertexBuffer ();

		CLASS_INVARIANT_DECLARE;
		
		// ¶¥µã»º³åÇø²Ù×÷¡£
		void Enable (Renderer* renderer, unsigned int vertexSize,unsigned int streamIndex, unsigned int offset);
		void Disable (Renderer* renderer, unsigned int streamIndex);
		void* Lock (BufferLocking mode);
		void Unlock ();	

	private:
		IMPL_TYPE_DECLARE(PlatformVertexBuffer);		 
	};
}

#endif // RENDERING_RENDERERS_PLATFORM_VERTEX_BUFFER_H

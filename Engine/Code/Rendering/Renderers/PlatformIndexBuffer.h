// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/26 15:30)

#ifndef RENDERING_RENDERERS_PLATFORM_INDEX_BUFFER_H
#define RENDERING_RENDERERS_PLATFORM_INDEX_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "Rendering/Resources/Flags/BufferFlags.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include <boost/noncopyable.hpp>

RENDERING_NON_COPY_EXPORT_IMPL(PlatformIndexBufferImpl); 

namespace Rendering
{
	class Renderer;
	class IndexBuffer;
	
	class RENDERING_DEFAULT_DECLARE PlatformIndexBuffer  
	{
	public:
            NON_COPY_TYPE_DECLARE(PlatformIndexBuffer); 
		using BufferType = IndexBuffer;

	public:
		PlatformIndexBuffer(Renderer* renderer, const IndexBuffer* indexBuffer);
		~PlatformIndexBuffer ();
		PlatformIndexBuffer(const PlatformIndexBuffer&) = delete;
		PlatformIndexBuffer& operator=(const PlatformIndexBuffer&) = delete;
		PlatformIndexBuffer( PlatformIndexBuffer&&) = delete;
		PlatformIndexBuffer& operator=( PlatformIndexBuffer&&) = delete;

		CLASS_INVARIANT_DECLARE;
		
		// ����������
		void Enable (Renderer* renderer);
		void Disable (Renderer* renderer);
		void* Lock (BufferLocking mode);
		void Unlock ();		

	private:
                PackageType impl;
	};
}

#endif // RENDERING_RENDERERS_PLATFORM_INDEX_BUFFER_H

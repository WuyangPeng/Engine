// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 15:27)

#ifndef RENDERING_RENDERERS_BUFFER_LOCK_MANAGE_H
#define RENDERING_RENDERERS_BUFFER_LOCK_MANAGE_H

#include "Rendering/RenderingDll.h"

#include <boost/noncopyable.hpp>

namespace Rendering
{
    template <typename PlatformBufferType>
	class BufferLockManager : boost::noncopyable
	{
	public:
		using ClassType = BufferLockManager<PlatformBufferType>;

	public:
		explicit BufferLockManager(PlatformBufferType& manager);
		~BufferLockManager();

		CLASS_INVARIANT_DECLARE;

		void* Lock(BufferLocking mode);
	
	private:
		PlatformBufferType& m_Manager;
		bool m_Lock;
	};
}

#endif // RENDERING_RENDERERS_BUFFER_LOCK_MANAGE_H



	
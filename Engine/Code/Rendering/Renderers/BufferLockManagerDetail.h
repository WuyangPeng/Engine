// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 16:32)

#ifndef RENDERING_RENDERERS_BUFFER_LOCK_MANAGE_DETAIL_H
#define RENDERING_RENDERERS_BUFFER_LOCK_MANAGE_DETAIL_H

#include "Rendering/RenderingExport.h"

#include "BufferLockManager.h" 
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h" 

template <typename PlatformBufferType>
Rendering::BufferLockManager<PlatformBufferType>
	::BufferLockManager(PlatformBufferType& manager)
	:m_Manager{ manager }, m_Lock{ false }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

template <typename PlatformBufferType>
Rendering::BufferLockManager<PlatformBufferType>
	::~BufferLockManager()
{
	if (m_Lock)
	{
		m_Manager.Unlock();
	}

	RENDERING_SELF_CLASS_IS_VALID_9;
}
 
#ifdef OPEN_CLASS_INVARIANT
template <typename PlatformBufferType>
bool Rendering::BufferLockManager< PlatformBufferType>
	::IsValid() const noexcept
{
    return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename PlatformBufferType>
void* Rendering::BufferLockManager<PlatformBufferType>
	::Lock(BufferLocking mode) 
{
	RENDERING_CLASS_IS_VALID_9;

	auto videoMemory = m_Manager.Lock(mode);
	m_Lock = true;

	return videoMemory;
}
 
#endif // RENDERING_RENDERERS_BUFFER_LOCK_MANAGE_DETAIL_H
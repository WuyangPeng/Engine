// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/26 16:41)

#ifndef RENDERING_RENDERERS_BUFFER_MANAGEMENT_LOCK_ENCAPSULATION_DETAIL_H
#define RENDERING_RENDERERS_BUFFER_MANAGEMENT_LOCK_ENCAPSULATION_DETAIL_H

#include "Rendering/RenderingExport.h"

#include "BufferManagementLockEncapsulation.h" 
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h" 

template <typename BufferManagementType>
Rendering::BufferManagementLockEncapsulation<BufferManagementType>
	::BufferManagementLockEncapsulation(BufferManagementType& manager)
	:m_Manager{ manager }, m_Buffer{ nullptr }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

template <typename BufferManagementType>
Rendering::BufferManagementLockEncapsulation<BufferManagementType>
	::~BufferManagementLockEncapsulation()
{
	if (m_Buffer != nullptr)
	{
		m_Manager.Unlock(m_Buffer);
	}

	RENDERING_SELF_CLASS_IS_VALID_9;
}
 
#ifdef OPEN_CLASS_INVARIANT
template <typename BufferManagementType>
bool Rendering::BufferManagementLockEncapsulation< BufferManagementType>
	::IsValid() const noexcept
{
    return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename BufferManagementType>
void* Rendering::BufferManagementLockEncapsulation<BufferManagementType>
	::Lock(BufferConstPtr buffer,BufferLocking mode) 
{
	RENDERING_CLASS_IS_VALID_9;

	auto videoMemory = m_Manager.Lock(buffer,mode);
	m_Buffer = buffer;

	return videoMemory;
}
 
#endif // RENDERING_RENDERERS_BUFFER_MANAGEMENT_LOCK_ENCAPSULATION_DETAIL_H
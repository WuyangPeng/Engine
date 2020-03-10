// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/26 16:33)

#ifndef RENDERING_RENDERERS_BUFFER_MANAGEMENT_DETAIL_H
#define RENDERING_RENDERERS_BUFFER_MANAGEMENT_DETAIL_H

#include "Rendering/RenderingExport.h"

#include "BufferManagement.h"
#include "PlatformIndexBuffer.h"
#include "PlatformVertexBuffer.h"
#include "BufferManagementLockEncapsulationDetail.h"
#include "Rendering/Resources/IndexBuffer.h"
#include "Rendering/Resources/VertexBuffer.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include <type_traits>

template <typename PlatformBufferType>
Rendering::BufferManagement<PlatformBufferType>
	::BufferManagement(RendererPtr ptr)
	: m_Renderer{ ptr }, m_Buffers{}
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename PlatformBufferType>
bool Rendering::BufferManagement< PlatformBufferType>
	::IsValid() const noexcept
{
	if(m_Renderer != nullptr)
        return true;
    else
        return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename PlatformBufferType>
void Rendering::BufferManagement< PlatformBufferType>
	::Bind (BufferConstPtr buffer)
{
	RENDERING_CLASS_IS_VALID_1;

    if (m_Buffers.find(buffer) == m_Buffers.end())
    {
		PlatformBufferTypeSharedPtr platformBuffer{ std::make_shared<PlatformBufferType>(m_Renderer, buffer) };
		m_Buffers.insert({ buffer, platformBuffer });
    }
}

template <typename PlatformBufferType>
void Rendering::BufferManagement< PlatformBufferType>
	::Unbind (BufferConstPtr buffer)
{
	RENDERING_CLASS_IS_VALID_1;

	m_Buffers.erase(buffer);
}
 
template <typename PlatformBufferType>
void Rendering::BufferManagement<PlatformBufferType>
	::EnableIndexBuffer (BufferConstPtr buffer)
{
	static_assert(std::is_same_v<PlatformBufferType, PlatformIndexBuffer>,"PlatformBufferType must be PlatformIndexBuffer!");

	RENDERING_CLASS_IS_VALID_1;

    auto iter = m_Buffers.find(buffer);
    PlatformBufferTypeSharedPtr platformBuffer;
    if (iter != m_Buffers.end())
    {
        platformBuffer = iter->second;
    }
    else
    {
        // 延迟构造。
		platformBuffer = std::make_shared<PlatformIndexBuffer>(m_Renderer, buffer);
		m_Buffers.insert({ buffer,  platformBuffer });
    }

     platformBuffer->Enable(m_Renderer);
}

template <typename PlatformBufferType>
void Rendering::BufferManagement<PlatformBufferType>
	::DisableIndexBuffer (BufferConstPtr buffer)
{
	static_assert(std::is_same_v<PlatformBufferType, PlatformIndexBuffer>, "PlatformBufferType must be PlatformIndexBuffer!");

	RENDERING_CLASS_IS_VALID_1;

	auto iter = m_Buffers.find(buffer);
 
    if (iter != m_Buffers.end())
    {
        auto platformBuffer = iter->second;

        platformBuffer->Disable(m_Renderer);
    }
}

template <typename PlatformBufferType>
void Rendering::BufferManagement<PlatformBufferType>
	::EnableVertexBuffer (BufferConstPtr buffer,unsigned int streamIndex, unsigned int offset)
{
	static_assert(std::is_same_v<PlatformBufferType, PlatformVertexBuffer>, "PlatformBufferType must be PlatformVertexBuffer!"); 

	RENDERING_CLASS_IS_VALID_1;

	auto iter = m_Buffers.find(buffer);
    PlatformBufferTypeSharedPtr platformBuffer;
    if (iter != m_Buffers.end())
    {
        platformBuffer = iter->second;
    }
    else
    {
        // 延迟构造。
		platformBuffer = std::make_shared<PlatformBufferType>(m_Renderer, buffer);
		m_Buffers.insert({ buffer,  platformBuffer });
    }

     platformBuffer->Enable(m_Renderer, buffer->GetElementSize(),streamIndex, offset);
}

template <typename PlatformBufferType>
void Rendering::BufferManagement<PlatformBufferType>
	::DisableVertexBuffer (BufferConstPtr buffer,unsigned int streamIndex)
{
	static_assert(std::is_same_v<PlatformBufferType, PlatformVertexBuffer>, "PlatformBufferType must be PlatformVertexBuffer!");

	RENDERING_CLASS_IS_VALID_1;

	auto iter = m_Buffers.find(buffer);
 
    if (iter != m_Buffers.end())
    {
        auto platformBuffer = iter->second;

        platformBuffer->Disable(m_Renderer, streamIndex);
    }
}

template <typename PlatformBufferType>
void* Rendering::BufferManagement< PlatformBufferType>
	::Lock (BufferConstPtr buffer,BufferLocking mode)
{
	RENDERING_CLASS_IS_VALID_1;

	auto iter = m_Buffers.find(buffer);
    PlatformBufferTypeSharedPtr platformBuffer;
    if (iter != m_Buffers.end())
    {
        platformBuffer = iter->second;
    }
    else
    {
        // 延迟构造。
        platformBuffer = std::make_shared<PlatformBufferType>(m_Renderer, buffer);
		m_Buffers.insert({ buffer,  platformBuffer });
    }

    return platformBuffer->Lock(mode);
}

template <typename PlatformBufferType>
void Rendering::BufferManagement<PlatformBufferType>
	::Unlock (BufferConstPtr buffer)
{
	RENDERING_CLASS_IS_VALID_1;

	auto iter = m_Buffers.find(buffer);
 
    if (iter != m_Buffers.end())
    {
		auto platformBuffer = iter->second;

        platformBuffer->Unlock();
    }
}

template <typename PlatformBufferType>
void Rendering::BufferManagement<PlatformBufferType>
	::Update (BufferConstPtr buffer)
{
	RENDERING_CLASS_IS_VALID_1;

	auto numBytes = buffer->GetNumBytes();
	auto srcData = buffer->GetReadOnlyData();

	BufferManagementLockEncapsulation<ClassType> manager{ *this };
	void* trgData = manager.Lock(buffer, BufferLocking::WriteOnly);

    memcpy(trgData, srcData, numBytes); 
}

template <typename PlatformBufferType>
typename Rendering::BufferManagement<PlatformBufferType>::PlatformBufferTypeSharedPtr Rendering::BufferManagement<PlatformBufferType>
	::GetResource (BufferConstPtr buffer)
{
	RENDERING_CLASS_IS_VALID_1;

	auto iter = m_Buffers.find(buffer);
    if (iter != m_Buffers.end())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("找不到指定的缓冲区资源！"));
    }
}

#endif // RENDERING_RENDERERS_BUFFER_MANAGEMENT_DETAIL_H
///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:33)

#ifndef RENDERING_RENDERERS_BUFFER_MANAGEMENT_DETAIL_H
#define RENDERING_RENDERERS_BUFFER_MANAGEMENT_DETAIL_H

#include "BufferManagement.h"
#include "BufferManagementLockEncapsulationDetail.h"
#include "PlatformIndexBuffer.h"
#include "PlatformVertexBuffer.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Rendering/Resources/Buffers/IndexBuffer.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"

#include <type_traits>

template <typename PlatformBufferType>
Rendering::BufferManagement<PlatformBufferType>::BufferManagement(const RendererSharedPtr& renderer)
    : renderer{ renderer }, buffers{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename PlatformBufferType>
bool Rendering::BufferManagement<PlatformBufferType>::IsValid() const noexcept
{
    if (renderer.lock())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename PlatformBufferType>
void Rendering::BufferManagement<PlatformBufferType>::Bind(const ConstBufferSharedPtr& buffer)
{
    RENDERING_CLASS_IS_VALID_1;

    auto ptr = renderer.lock();
    if (!ptr)
    {
        return;
    }

    if (buffers.find(buffer) == buffers.end())
    {
        auto platformBuffer = std::make_shared<PlatformBufferType>(ptr.get(), buffer.get());
        buffers.emplace(buffer, platformBuffer);
    }
}

template <typename PlatformBufferType>
void Rendering::BufferManagement<PlatformBufferType>::Unbind(const ConstBufferSharedPtr& buffer)
{
    RENDERING_CLASS_IS_VALID_1;

    buffers.erase(buffer);
}

template <typename PlatformBufferType>
void Rendering::BufferManagement<PlatformBufferType>::EnableIndexBuffer(const ConstBufferSharedPtr& buffer)
{
    static_assert(std::is_same_v<PlatformBufferType, PlatformIndexBuffer>, "PlatformBufferType must be PlatformIndexBuffer!");

    RENDERING_CLASS_IS_VALID_1;

    auto ptr = renderer.lock();
    if (!ptr)
    {
        return;
    }

    const auto iter = buffers.find(buffer);
    PlatformBufferTypeSharedPtr platformBuffer{};
    if (iter != buffers.end())
    {
        platformBuffer = iter->second;
    }
    else
    {
        // 延迟构造。
        platformBuffer = std::make_shared<PlatformIndexBuffer>(ptr.get(), buffer.get());
        buffers.emplace(buffer, platformBuffer);
    }

    platformBuffer->Enable(ptr.get());
}

template <typename PlatformBufferType>
void Rendering::BufferManagement<PlatformBufferType>::DisableIndexBuffer(const ConstBufferSharedPtr& buffer)
{
    static_assert(std::is_same_v<PlatformBufferType, PlatformIndexBuffer>, "PlatformBufferType must be PlatformIndexBuffer!");

    RENDERING_CLASS_IS_VALID_1;

    auto ptr = renderer.lock();
    if (!ptr)
    {
        return;
    }

    const auto iter = buffers.find(buffer);

    if (iter != buffers.end())
    {
        auto platformBuffer = iter->second;

        platformBuffer->Disable(ptr.get());
    }
}

template <typename PlatformBufferType>
void Rendering::BufferManagement<PlatformBufferType>::EnableVertexBuffer(const ConstBufferSharedPtr& buffer, int streamIndex, int offset)
{
    static_assert(std::is_same_v<PlatformBufferType, PlatformVertexBuffer>, "PlatformBufferType must be PlatformVertexBuffer!");

    RENDERING_CLASS_IS_VALID_1;

    auto ptr = renderer.lock();
    if (!ptr)
    {
        return;
    }

    const auto iter = buffers.find(buffer);
    PlatformBufferTypeSharedPtr platformBuffer{};
    if (iter != buffers.end())
    {
        platformBuffer = iter->second;
    }
    else
    {
        // 延迟构造。
        platformBuffer = std::make_shared<PlatformBufferType>(ptr.get(), buffer.get());
        buffers.emplace(buffer, platformBuffer);
    }

    platformBuffer->Enable(ptr.get(), buffer->GetElementSize(), streamIndex, offset);
}

template <typename PlatformBufferType>
void Rendering::BufferManagement<PlatformBufferType>::DisableVertexBuffer(const ConstBufferSharedPtr& buffer, int streamIndex)
{
    static_assert(std::is_same_v<PlatformBufferType, PlatformVertexBuffer>, "PlatformBufferType must be PlatformVertexBuffer!");

    RENDERING_CLASS_IS_VALID_1;

    auto ptr = renderer.lock();
    if (!ptr)
    {
        return;
    }

    const auto iter = buffers.find(buffer);

    if (iter != buffers.end())
    {
        auto platformBuffer = iter->second;

        platformBuffer->Disable(ptr.get(), streamIndex);
    }
}

template <typename PlatformBufferType>
void* Rendering::BufferManagement<PlatformBufferType>::Lock(const ConstBufferSharedPtr& buffer, BufferLocking mode)
{
    RENDERING_CLASS_IS_VALID_1;

    auto ptr = renderer.lock();
    if (!ptr)
    {
        return nullptr;
    }

    const auto iter = buffers.find(buffer);
    PlatformBufferTypeSharedPtr platformBuffer{};
    if (iter != buffers.end())
    {
        platformBuffer = iter->second;
    }
    else
    {
        // 延迟构造。
        platformBuffer = std::make_shared<PlatformBufferType>(ptr.get(), buffer.get());
        buffers.emplace(buffer, platformBuffer);
    }

    return platformBuffer->Lock(mode);
}

template <typename PlatformBufferType>
void Rendering::BufferManagement<PlatformBufferType>::Unlock(const ConstBufferSharedPtr& buffer)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto iter = buffers.find(buffer);

    if (iter != buffers.end())
    {
        auto platformBuffer = iter->second;

        platformBuffer->Unlock();
    }
}

template <typename PlatformBufferType>
void Rendering::BufferManagement<PlatformBufferType>::Update(const ConstBufferSharedPtr& buffer)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto numBytes = buffer->GetNumBytes();
    const auto srcData = buffer->GetData();

    BufferManagementLockEncapsulation<ClassType> manager{ *this };
    void* trgData = manager.Lock(buffer, BufferLocking::WriteOnly);

    System::MemoryCopy(trgData, &*srcData, numBytes);
}

template <typename PlatformBufferType>
typename Rendering::BufferManagement<PlatformBufferType>::PlatformBufferTypeSharedPtr Rendering::BufferManagement<PlatformBufferType>::GetResource(ConstBufferSharedPtr buffer)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto iter = buffers.find(buffer);
    if (iter != buffers.end())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("找不到指定的缓冲区资源！"s));
    }
}

#endif  // RENDERING_RENDERERS_BUFFER_MANAGEMENT_DETAIL_H
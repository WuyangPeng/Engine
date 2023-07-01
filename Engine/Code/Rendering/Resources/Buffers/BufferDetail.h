///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/30 09:29)

#ifndef RENDERING_RESOURCES_BUFFER_DETAIL_H
#define RENDERING_RESOURCES_BUFFER_DETAIL_H

#include "Buffer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Resources/Buffers/MemberLayout.h"

template <typename T>
void Rendering::Buffer::CheckMember(const T& layout) const
{
    if (layout.GetNumElements() != 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("成员是一个数组，使用SetMember(name,index,value)。"s))
    }

    if (GetNumBytes() < layout.GetOffset() + sizeof(T))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("将访问缓冲区外的内存。"s))
    }
}

template <typename T>
void Rendering::Buffer::CheckMember(int index, const T& layout) const
{
    if (layout.GetNumElements() == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("成员不是一个数组，使用SetMember(name,value)。"s))
    }

    if (GetNumBytes() < layout.GetOffset() + (index + 1) * sizeof(T))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("将访问缓冲区外的内存。"s))
    }
}

#endif  // RENDERING_RESOURCES_BUFFER_DETAIL_H

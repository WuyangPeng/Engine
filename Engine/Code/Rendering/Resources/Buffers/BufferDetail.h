/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/12 19:22)

#ifndef RENDERING_RESOURCES_BUFFER_DETAIL_H
#define RENDERING_RESOURCES_BUFFER_DETAIL_H

#include "Buffer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

template <typename T>
void Rendering::Buffer::CheckMember(const T& layout) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (layout.GetNumElements() != 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("成员是一个数组，使用SetMember(name,index,value)。"s))
    }

    if (GetNumBytes() < layout.GetOffset() + layout.GetStreamingSize())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("将访问缓冲区外的内存。"s))
    }
}

template <typename T>
void Rendering::Buffer::CheckMember(int index, const T& layout) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (layout.GetNumElements() == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("成员不是一个数组，使用SetMember(name,value)。"s))
    }

    if (GetNumBytes() < layout.GetOffset() + (index + 1) * layout.GetStreamingSize())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("将访问缓冲区外的内存。"s))
    }
}

#endif  // RENDERING_RESOURCES_BUFFER_DETAIL_H

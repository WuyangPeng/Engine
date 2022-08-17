///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/09 15:04)

#ifndef RENDERING_RENDERERS_TEXTURE_BUFFER_DETAIL_H
#define RENDERING_RENDERERS_TEXTURE_BUFFER_DETAIL_H

#include "TextureBuffer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Resources/Buffers/MemberLayout.h"

template <typename T>
void Rendering::TextureBuffer::SetMember(const std::string& name, const T& value)
{
    RENDERING_CLASS_IS_VALID_9;

    auto layout = GetMember(name);

    if (layout.GetNumElements != 0)
    {
        THROW_EXCEPTION("成员是一个数组，使用SetMember(name,index,value)。"s);
    }

    if (GetNumBytes() < layout.GetOffset() + sizeof(T))
    {
        THROW_EXCEPTION("写入将访问缓冲区外的内存。"s);
    }

    auto target = GetData(layout.GetOffset());

    target.Increase<T>(value);
}

template <typename T>
T Rendering::TextureBuffer::GetMember(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto layout = GetMember(name);

    if (layout.GetNumElements != 0)
    {
        THROW_EXCEPTION("成员是一个数组，使用SetMember(name,index,value)。"s);
    }

    if (GetNumBytes() < layout.GetOffset() + sizeof(T))
    {
        THROW_EXCEPTION("写入将访问缓冲区外的内存。"s);
    }

    auto target = GetData(layout.GetOffset());

    return target.Increase<T>();
}

template <typename T>
void Rendering::TextureBuffer::SetMember(const std::string& name, int index, const T& value)
{
    RENDERING_CLASS_IS_VALID_9;

    auto layout = GetMember(name);

    if (layout.GetNumElements == 0)
    {
        THROW_EXCEPTION("成员不是一个数组，使用SetMember(name,value)。"s);
    }

    if (GetNumBytes() < layout.GetOffset() + (index + 1) * sizeof(T))
    {
        THROW_EXCEPTION("写入将访问缓冲区外的内存。"s);
    }

    auto target = GetData(layout.GetOffset() + index * sizeof(T));

    target.Increase<T>(value);
}

template <typename T>
T Rendering::TextureBuffer::GetMember(const std::string& name, int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto layout = GetMember(name);

    if (layout.GetNumElements == 0)
    {
        THROW_EXCEPTION("成员不是一个数组，使用SetMember(name,value)。"s);
    }

    if (GetNumBytes() < layout.GetOffset() + (index + 1) * sizeof(T))
    {
        THROW_EXCEPTION("写入将访问缓冲区外的内存。"s);
    }

    auto target = GetData(layout.GetOffset() + index * sizeof(T));

    return target.Increase<T>();
}

#endif  // RENDERING_RENDERERS_TEXTURE_BUFFER_DETAIL_H

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:20)

#ifndef RENDERING_RENDERERS_CONSTANT_BUFFER_DETAIL_H
#define RENDERING_RENDERERS_CONSTANT_BUFFER_DETAIL_H

#include "ConstantBuffer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Resources/Buffers/MemberLayout.h"

template <typename T>
void Rendering::ConstantBuffer::SetMember(const std::string& name, const T& value)
{
    RENDERING_CLASS_IS_VALID_9;

    auto layout = GetMember(name);

    if (layout.GetNumElements != 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��Ա��һ�����飬ʹ��SetMember(name,index,value)��"s));
    }

    if (GetNumBytes() < layout.GetOffset() + sizeof(T))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("д�뽫���ʻ���������ڴ档"s));
    }

    auto target = GetData(layout.GetOffset());

    target.Increase<T>(value);
}

template <typename T>
T Rendering::ConstantBuffer::GetMember(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto layout = GetMember(name);

    if (layout.GetNumElements != 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��Ա��һ�����飬ʹ��SetMember(name,index,value)��"s));
    }

    if (GetNumBytes() < layout.GetOffset() + sizeof(T))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("д�뽫���ʻ���������ڴ档"s));
    }

    auto target = GetData(layout.GetOffset());

    return target.Increase<T>();
}

template <typename T>
void Rendering::ConstantBuffer::SetMember(const std::string& name, int index, const T& value)
{
    RENDERING_CLASS_IS_VALID_9;

    auto layout = GetMember(name);

    if (layout.GetNumElements == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��Ա����һ�����飬ʹ��SetMember(name,value)��"s));
    }

    if (GetNumBytes() < layout.GetOffset() + (index + 1) * sizeof(T))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("д�뽫���ʻ���������ڴ档"s));
    }

    auto target = GetData(layout.GetOffset() + index * sizeof(T));

    target.Increase<T>(value);
}

template <typename T>
T Rendering::ConstantBuffer::GetMember(const std::string& name, int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto layout = GetMember(name);

    if (layout.GetNumElements == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��Ա����һ�����飬ʹ��SetMember(name,value)��"s));
    }

    if (GetNumBytes() < layout.GetOffset() + (index + 1) * sizeof(T))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("д�뽫���ʻ���������ڴ档"s));
    }

    auto target = GetData(layout.GetOffset() + index * sizeof(T));

    return target.Increase<T>();
}

#endif  // RENDERING_RENDERERS_CONSTANT_BUFFER_DETAIL_H

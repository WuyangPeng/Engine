/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/12 19:22)

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
        THROW_EXCEPTION(SYSTEM_TEXT("��Ա��һ�����飬ʹ��SetMember(name,index,value)��"s))
    }

    if (GetNumBytes() < layout.GetOffset() + layout.GetStreamingSize())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�����ʻ���������ڴ档"s))
    }
}

template <typename T>
void Rendering::Buffer::CheckMember(int index, const T& layout) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (layout.GetNumElements() == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��Ա����һ�����飬ʹ��SetMember(name,value)��"s))
    }

    if (GetNumBytes() < layout.GetOffset() + (index + 1) * layout.GetStreamingSize())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�����ʻ���������ڴ档"s))
    }
}

#endif  // RENDERING_RESOURCES_BUFFER_DETAIL_H

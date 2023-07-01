///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/30 09:29)

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
        THROW_EXCEPTION(SYSTEM_TEXT("��Ա��һ�����飬ʹ��SetMember(name,index,value)��"s))
    }

    if (GetNumBytes() < layout.GetOffset() + sizeof(T))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�����ʻ���������ڴ档"s))
    }
}

template <typename T>
void Rendering::Buffer::CheckMember(int index, const T& layout) const
{
    if (layout.GetNumElements() == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��Ա����һ�����飬ʹ��SetMember(name,value)��"s))
    }

    if (GetNumBytes() < layout.GetOffset() + (index + 1) * sizeof(T))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�����ʻ���������ڴ档"s))
    }
}

#endif  // RENDERING_RESOURCES_BUFFER_DETAIL_H

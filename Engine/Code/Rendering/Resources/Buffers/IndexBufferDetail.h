///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/29 15:17)

#ifndef RENDERING_RESOURCES_INDEX_BUFFER_DETAIL_H
#define RENDERING_RESOURCES_INDEX_BUFFER_DETAIL_H

#include "IndexBuffer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

template <typename T>
void Rendering::IndexBuffer::IncreaseData(int index, T vertex)
{
    RENDERING_CLASS_IS_VALID_1;

    auto data = GetData(index * CoreTools::GetStreamSize<T>());

    data.template Increase<T>(vertex);
}

template <typename T>
T Rendering::IndexBuffer::GetIncreaseData(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto data = GetData(index * CoreTools::GetStreamSize<T>());

    return data.template Increase<T>();
}

template <typename T>
void Rendering::IndexBuffer::IncreaseData(int index, T vertex0, T vertex1, int multiple)
{
    RENDERING_CLASS_IS_VALID_1;

    auto data = GetData(multiple * index * CoreTools::GetStreamSize<T>());

    data.template Increase<T>(vertex0);
    data.template Increase<T>(vertex1);
}

template <typename T>
Rendering::IndexBuffer::SegmentType Rendering::IndexBuffer::GetIncreaseData(int index, int multiple) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto data = GetData(multiple * index * CoreTools::GetStreamSize<T>());

    const auto vertex0 = data.template Increase<T>();
    const auto vertex1 = data.template Increase<T>();

    return { vertex0, vertex1 };
}

template <typename T>
void Rendering::IndexBuffer::IncreaseData(int index, T vertex0, T vertex1, T vertex2, int multiple)
{
    RENDERING_CLASS_IS_VALID_1;

    auto data = GetData(multiple * index * CoreTools::GetStreamSize<T>());

    data.template Increase<T>(vertex0);
    data.template Increase<T>(vertex1);
    data.template Increase<T>(vertex2);
}

template <typename T>
Rendering::IndexBuffer::TriangleType Rendering::IndexBuffer::GetIncreaseData(int index, int multiple, bool changePosition) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto data = GetData(multiple * index * CoreTools::GetStreamSize<T>());

    const auto vertex0 = data.template Increase<T>();
    const auto vertex1 = data.template Increase<T>();
    const auto vertex2 = data.template Increase<T>();

    if (changePosition)
    {
        return { vertex0, vertex2, vertex1 };
    }
    else
    {
        return { vertex0, vertex1, vertex2 };
    }
}

#endif  // RENDERING_RESOURCES_INDEX_BUFFER_DETAIL_H

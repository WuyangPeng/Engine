///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/30 09:29)

#ifndef RENDERING_RESOURCES_CONSTANT_BUFFER_DETAIL_H
#define RENDERING_RESOURCES_CONSTANT_BUFFER_DETAIL_H

#include "BufferDetail.h"
#include "ConstantBuffer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Resources/Buffers/MemberLayout.h"

template <typename T>
void Rendering::ConstantBuffer::SetMember(const std::string& name, const T& value)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto layout = GetMember(name);

    CheckMember(layout);

    auto target = GetStorage(layout.GetOffset());

    target.Increase<T>(value);
}

template <typename T>
T Rendering::ConstantBuffer::GetMember(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto layout = GetMember(name);

    CheckMember(layout);

    auto target = GetStorage(layout.GetOffset());

    return target.Increase<T>();
}

template <typename T>
void Rendering::ConstantBuffer::SetMember(const std::string& name, int index, const T& value)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto layout = GetMember(name);

    CheckMember(index, layout);

    auto target = GetStorage(layout.GetOffset() + index * sizeof(T));

    target.Increase<T>(value);
}

template <typename T>
T Rendering::ConstantBuffer::GetMember(const std::string& name, int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto layout = GetMember(name);

    CheckMember(index, layout);

    auto target = GetStorage(layout.GetOffset() + index * sizeof(T));

    return target.Increase<T>();
}

#endif  // RENDERING_RESOURCES_CONSTANT_BUFFER_DETAIL_H

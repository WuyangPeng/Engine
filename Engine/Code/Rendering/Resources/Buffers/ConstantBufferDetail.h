/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 11:34)

#ifndef RENDERING_RESOURCES_CONSTANT_BUFFER_DETAIL_H
#define RENDERING_RESOURCES_CONSTANT_BUFFER_DETAIL_H

#include "BufferDetail.h"
#include "ConstantBuffer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/MatrixDetail.h"
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
void Rendering::ConstantBuffer::SetMember(const std::string& name, const Mathematics::Matrix<T>& value)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto layout = GetMember(name);

    CheckMember(layout);

    auto target = GetStorage(layout.GetOffset());

    for (const auto element : value.GetData())
    {
        target.Increase<T>(element);
    }
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
Mathematics::Matrix<T> Rendering::ConstantBuffer::GetMatrixMember(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto layout = GetMember(name);

    CheckMember(layout);

    auto target = GetStorage(layout.GetOffset());

    Mathematics::Matrix<T> matrix{};

    typename Mathematics::Matrix<T>::EntryType entry{};

    for (auto& element : entry)
    {
        element = target.Increase<T>();
    }

    matrix.Set(entry);

    return matrix;
}

template <typename T>
void Rendering::ConstantBuffer::SetMember(const std::string& name, int index, const T& value)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto layout = GetMember(name);

    CheckMember(index, layout);

    auto target = GetStorage(layout.GetOffset() + index * CoreTools::GetStreamSize<T>());

    target.template Increase<T>(value);
}

template <typename T>
T Rendering::ConstantBuffer::GetMember(const std::string& name, int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto layout = GetMember(name);

    CheckMember(index, layout);

    auto target = GetStorage(layout.GetOffset() + index * CoreTools::GetStreamSize<T>());

    return target.template Increase<T>();
}

#endif  // RENDERING_RESOURCES_CONSTANT_BUFFER_DETAIL_H

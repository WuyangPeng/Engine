/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 15:02)

#ifndef RENDERING_SHADERS_SHADER_DETAIL_H
#define RENDERING_SHADERS_SHADER_DETAIL_H

#include "Shader.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

template <typename T>
int Rendering::Shader::Set(const std::string& name, const std::shared_ptr<T>& object)
{
    RENDERING_CLASS_IS_VALID_9;

    constexpr auto index = T::GetShaderDataLookup();

    auto handle = 0;

    const auto end = GetShaderDataEnd(index);
    for (auto iter = GetShaderDataBegin(index); iter != end; ++iter)
    {
        if (name == iter->GetName())
        {
            if (IsValid(*iter, object.get()))
            {
                iter->SetGraphicsObject(object);

                return handle;
            }

            return -1;
        }

        ++handle;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("无法找到对象"s))
}

template <typename T>
std::shared_ptr<const T> Rendering::Shader::Get(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    constexpr auto index = T::GetShaderDataLookup();

    const auto end = GetShaderDataEnd(index);
    for (auto iter = GetShaderDataBegin(index); iter != end; ++iter)
    {
        if (name == iter->GetName())
        {
            return boost::polymorphic_pointer_cast<const T>(iter->GetGraphicsObject());
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("无法找到对象"s))
}

template <typename T>
std::shared_ptr<T> Rendering::Shader::Get(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    constexpr auto index = T::GetShaderDataLookup();

    const auto end = GetShaderDataEnd(index);
    for (auto iter = GetShaderDataBegin(index); iter != end; ++iter)
    {
        if (name == iter->GetName())
        {
            return boost::polymorphic_pointer_cast<T>(iter->GetGraphicsObject());
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("无法找到对象"s))
}

template <typename T>
void Rendering::Shader::Set(int handle, const std::shared_ptr<T>& object)
{
    RENDERING_CLASS_IS_VALID_9;

    constexpr auto index = T::GetShaderDataLookup();

    const auto begin = GetShaderDataBegin(index);
    const auto end = GetShaderDataEnd(index);
    if (0 <= handle && handle < end - begin)
    {
        if (auto iter = begin + handle;
            IsValid(*iter, object.get()))
        {
            iter->SetGraphicsObject(object);
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无法找到对象"s))
    }
}

template <typename T>
std::shared_ptr<const T> Rendering::Shader::Get(int handle) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    constexpr auto index = T::GetShaderDataLookup();

    return boost::polymorphic_pointer_cast<const T>(GetGraphicsObject(index, handle));
}

#endif  // RENDERING_SHADERS_SHADER_DETAIL_H
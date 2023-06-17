///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:28)

#ifndef RENDERING_SHADERS_SHADER_IMPL_DETAIL_H
#define RENDERING_SHADERS_SHADER_IMPL_DETAIL_H

#include "ShaderImpl.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"


template <typename T>
int Rendering::ShaderImpl::Set(const std::string& name, const std::shared_ptr<T>& object)
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
                iter->SetObject(object);

                return handle;
            }
            return -1;
        }
        ++handle;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("无法找到对象"s));
}

#endif  // RENDERING_SHADERS_SHADER_IMPL_DETAIL_H
///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.1 (2023/07/01 16:14)

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
                iter->SetGraphicsObject(object);

                return handle;
            }

            return -1;
        }
        ++handle;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("�޷��ҵ�����"s))
}

#endif  // RENDERING_SHADERS_SHADER_IMPL_DETAIL_H
/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 15:02)

#ifndef RENDERING_SHADERS_PROGRAM_DEFINES_DETAIL_H
#define RENDERING_SHADERS_PROGRAM_DEFINES_DETAIL_H

#include "ProgramDefines.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

template <typename T>
void Rendering::ProgramDefines::Set(const std::string& name, T value)
{
    RENDERING_CLASS_IS_VALID_9;

    if constexpr (std::is_same_v<T, std::string> || std::is_same_v<T, const char*>)
    {
        Update(name, value);
    }
    else
    {
        Update(name, std::to_string(value));
    }
}

#endif  // RENDERING_SHADERS_PROGRAM_DEFINES_DETAIL_H

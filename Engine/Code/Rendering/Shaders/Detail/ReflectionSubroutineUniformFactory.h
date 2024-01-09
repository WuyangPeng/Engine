/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 15:00)

#ifndef RENDERING_SHADERS_REFLECTION_SUBROUTINE_UNIFORM_FACTORY_H
#define RENDERING_SHADERS_REFLECTION_SUBROUTINE_UNIFORM_FACTORY_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Shaders/ShadersInternalFwd.h"

#include <memory>
#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ReflectionSubroutineUniformFactory
    {
    public:
        using ClassType = ReflectionSubroutineUniformFactory;
        using ReflectionSubroutineUniformSharedPtr = std::shared_ptr<ReflectionSubroutineUniformImpl>;

    public:
        NODISCARD static ReflectionSubroutineUniformSharedPtr Create(const std::string& name);
        NODISCARD static ReflectionSubroutineUniformSharedPtr Create();

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // RENDERING_SHADERS_REFLECTION_SUBROUTINE_UNIFORM_FACTORY_H

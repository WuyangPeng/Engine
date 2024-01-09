/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 15:00)

#ifndef RENDERING_SHADERS_REFLECTION_SUBROUTINE_UNIFORM_IMPL_H
#define RENDERING_SHADERS_REFLECTION_SUBROUTINE_UNIFORM_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Shaders/ShadersInternalFwd.h"

#include <memory>
#include <string>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ReflectionSubroutineUniformImpl
    {
    public:
        using ClassType = ReflectionSubroutineUniformImpl;
        using FactoryType = ReflectionSubroutineUniformFactory;

        using OpenGLInt = System::OpenGLInt;
        using CompatibleSubroutines = std::vector<OpenGLInt>;
        using ReflectionSubroutineUniformSharedPtr = std::shared_ptr<ReflectionSubroutineUniformImpl>;

    public:
        ReflectionSubroutineUniformImpl() noexcept;
        virtual ~ReflectionSubroutineUniformImpl() noexcept = default;
        ReflectionSubroutineUniformImpl(const ReflectionSubroutineUniformImpl& rhs) noexcept = default;
        ReflectionSubroutineUniformImpl& operator=(const ReflectionSubroutineUniformImpl& rhs) noexcept = default;
        ReflectionSubroutineUniformImpl(ReflectionSubroutineUniformImpl&& rhs) noexcept = default;
        ReflectionSubroutineUniformImpl& operator=(ReflectionSubroutineUniformImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual ReflectionSubroutineUniformSharedPtr Clone() const = 0;

        NODISCARD virtual std::string GetName() const = 0;
        virtual void SetName(const std::string& aName) = 0;

        NODISCARD virtual OpenGLInt GetLocation() const noexcept = 0;
        virtual void SetLocation(OpenGLInt aLocation) noexcept = 0;

        NODISCARD virtual OpenGLInt GetArraySize() const noexcept = 0;
        virtual void SetArraySize(OpenGLInt aArraySize) noexcept = 0;

        NODISCARD virtual OpenGLInt GetCompatibleSubroutines(int index) const = 0;
        virtual void SetCompatibleSubroutines(int index, OpenGLInt aCompatibleSubroutines) = 0;
        virtual void SetCompatibleSubroutines(const CompatibleSubroutines& aCompatibleSubroutines) = 0;
    };
}

#endif  // RENDERING_SHADERS_REFLECTION_SUBROUTINE_UNIFORM_IMPL_H
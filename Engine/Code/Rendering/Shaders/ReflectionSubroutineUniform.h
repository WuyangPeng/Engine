/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/26 15:04)

#ifndef RENDERING_SHADERS_REFLECTION_SUBROUTINE_UNIFORM_H
#define RENDERING_SHADERS_REFLECTION_SUBROUTINE_UNIFORM_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

#include <string>
#include <vector>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(ReflectionSubroutineUniform, ReflectionSubroutineUniformImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ReflectionSubroutineUniform
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ReflectionSubroutineUniform);

        using OpenGLInt = System::OpenGLInt;
        using CompatibleSubroutines = std::vector<OpenGLInt>;

    public:
        explicit ReflectionSubroutineUniform(const std::string& name);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetName() const;
        void SetName(const std::string& name);

        NODISCARD OpenGLInt GetLocation() const noexcept;
        void SetLocation(OpenGLInt location) noexcept;

        NODISCARD OpenGLInt GetArraySize() const noexcept;
        void SetArraySize(OpenGLInt arraySize) noexcept;

        NODISCARD OpenGLInt GetCompatibleSubroutines(int index) const;
        void SetCompatibleSubroutines(int index, OpenGLInt compatibleSubroutines);
        void SetCompatibleSubroutines(const CompatibleSubroutines& compatibleSubroutines);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SHADERS_REFLECTION_SUBROUTINE_UNIFORM_H
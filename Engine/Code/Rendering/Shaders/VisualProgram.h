///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/24 18:27)

#ifndef RENDERING_SHADERS_VISUAL_PROGRAM_H
#define RENDERING_SHADERS_VISUAL_PROGRAM_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/NameMacro.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/Shaders/ShadersFwd.h"

#include <string>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(VisualProgram, VisualProgramImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE VisualProgram
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(VisualProgram);
        using ShaderSharedPtr = std::shared_ptr<Shader>;
        using ConstShaderSharedPtr = std::shared_ptr<const Shader>;
        using ObjectLink = CoreTools::ObjectLink;
        using BufferTarget = CoreTools::BufferTarget;
        using BufferSource = CoreTools::BufferSource;
        using ObjectRegister = CoreTools::ObjectRegister;

    public:
        explicit VisualProgram(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);
        virtual ~VisualProgram() noexcept = default;
        VisualProgram(const VisualProgram& rhs) = default;
        VisualProgram& operator=(const VisualProgram& rhs) = default;
        VisualProgram(VisualProgram&& rhs) noexcept = default;
        VisualProgram& operator=(VisualProgram&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD ConstShaderSharedPtr GetVertexShader() const noexcept;
        NODISCARD ConstShaderSharedPtr GetPixelShader() const noexcept;
        NODISCARD ConstShaderSharedPtr GetGeometryShader() const noexcept;

        void SetVertexShader(const ShaderSharedPtr& shader);
        void SetPixelShader(const ShaderSharedPtr& shader);
        void SetGeometryShader(const ShaderSharedPtr& shader);

        CORE_TOOLS_NAMES_IMPL_DECLARE;

        NODISCARD int GetStreamingSize() const noexcept;
        void Save(BufferTarget& target) const;
        void Load(BufferSource& source);
        void Link(ObjectLink& source);
        void Register(ObjectRegister& target) const;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SHADERS_VISUAL_PROGRAM_H

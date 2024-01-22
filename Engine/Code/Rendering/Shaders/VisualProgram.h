/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 15:05)

#ifndef RENDERING_SHADERS_VISUAL_PROGRAM_H
#define RENDERING_SHADERS_VISUAL_PROGRAM_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/NameMacro.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/OpenGLRenderer/GLSL/GLSLProgramHandle.h"
#include "Rendering/OpenGLRenderer/GLSL/GLSLShaderHandle.h"
#include "Rendering/Shaders/ShadersFwd.h"

#include <string>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(VisualProgram, VisualProgramImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE VisualProgram final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(VisualProgram);

        using OpenGLUInt = System::OpenGLUInt;
        using ObjectLink = CoreTools::ObjectLink;
        using BufferTarget = CoreTools::BufferTarget;
        using BufferSource = CoreTools::BufferSource;
        using ObjectRegister = CoreTools::ObjectRegister;
        using ShaderSharedPtr = std::shared_ptr<Shader>;
        using ConstShaderSharedPtr = std::shared_ptr<const Shader>;
        using VisualProgramSharedPtr = std::shared_ptr<VisualProgram>;

    public:
        NODISCARD static VisualProgram Create();
        NODISCARD static VisualProgramSharedPtr Create(const std::string& vertexShaderSource, const std::string& pixelShaderSource, const std::string& geometryShaderSource, const std::string& version, const ProgramDefines& defines);
        VisualProgram(const GLSLProgramHandle& programHandle, const GLSLShaderHandle& vertexShaderHandle, const GLSLShaderHandle& pixelShaderHandle, const GLSLShaderHandle& geometryShaderHandle);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstShaderSharedPtr GetVertexShader() const noexcept;
        NODISCARD ConstShaderSharedPtr GetPixelShader() const noexcept;
        NODISCARD ConstShaderSharedPtr GetGeometryShader() const noexcept;

        NODISCARD ShaderSharedPtr GetVertexShader() noexcept;
        NODISCARD ShaderSharedPtr GetPixelShader() noexcept;
        NODISCARD ShaderSharedPtr GetGeometryShader() noexcept;

        void SetVertexShader(const ShaderSharedPtr& shader);
        void SetPixelShader(const ShaderSharedPtr& shader);
        void SetGeometryShader(const ShaderSharedPtr& shader);

        CORE_TOOLS_NAMES_IMPL_DECLARE;

        NODISCARD int GetStreamingSize() const noexcept;
        void Save(BufferTarget& target) const;
        void Load(BufferSource& source);
        void Link(ObjectLink& source);
        void Register(ObjectRegister& target) const;

        NODISCARD Reflection GetReflector() const;
        NODISCARD OpenGLUInt GetProgramHandle() const;

        void CreateShader(bool createGeometryShader);
        void CreateVertexShader();
        void CreatePixelShader();
        void CreateGeometryShader();

    private:
        explicit VisualProgram(CoreTools::DisableNotThrow disableNotThrow);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SHADERS_VISUAL_PROGRAM_H

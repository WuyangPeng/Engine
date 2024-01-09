/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 15:02)

#ifndef RENDERING_SHADERS_VISUAL_PROGRAM_IMPL_H
#define RENDERING_SHADERS_VISUAL_PROGRAM_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/Helper/NameMacro.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/Shaders/Shader.h"

#include <memory>
#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE VisualProgramImpl
    {
    public:
        using ClassType = VisualProgramImpl;
        using FactoryType = VisualProgramImpl;

        using OpenGLUInt = System::OpenGLUInt;
        using ObjectLink = CoreTools::ObjectLink;
        using BufferTarget = CoreTools::BufferTarget;
        using BufferSource = CoreTools::BufferSource;
        using ObjectRegister = CoreTools::ObjectRegister;
        using ShaderSharedPtr = std::shared_ptr<Shader>;
        using ConstShaderSharedPtr = std::shared_ptr<const Shader>;
        using ShaderObjectAssociated = CoreTools::ObjectAssociated<Shader>;
        using VisualProgramSharedPtr = std::shared_ptr<VisualProgramImpl>;

    public:
        NODISCARD static VisualProgramSharedPtr Create(OpenGLUInt programHandle, OpenGLUInt vertexShaderHandle, OpenGLUInt pixelShaderHandle, OpenGLUInt geometryShaderHandle);

        VisualProgramImpl() noexcept;
        virtual ~VisualProgramImpl() noexcept = default;
        VisualProgramImpl(const VisualProgramImpl& rhs) = default;
        VisualProgramImpl& operator=(const VisualProgramImpl& rhs) = default;
        VisualProgramImpl(VisualProgramImpl&& rhs) noexcept = default;
        VisualProgramImpl& operator=(VisualProgramImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

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

        NODISCARD virtual Reflection GetReflector() const;
        NODISCARD virtual VisualProgramSharedPtr Clone() const;
        NODISCARD virtual OpenGLUInt GetProgramHandle() const;

    private:
        ShaderObjectAssociated vertexShader;
        ShaderObjectAssociated pixelShader;
        ShaderObjectAssociated geometryShader;
    };
}

#endif  // RENDERING_SHADERS_VISUAL_PROGRAM_IMPL_H

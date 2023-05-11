///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.1 (2022/08/24 18:12)

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
        using ShaderSharedPtr = std::shared_ptr<Shader>;
        using ConstShaderSharedPtr = std::shared_ptr<const Shader>;
        using ObjectLink = CoreTools::ObjectLink;
        using BufferTarget = CoreTools::BufferTarget;
        using BufferSource = CoreTools::BufferSource;
        using ObjectRegister = CoreTools::ObjectRegister;
        using ShaderObjectAssociated = CoreTools::ObjectAssociated<Shader>;
        using VisualProgramSharedPtr = std::shared_ptr<VisualProgramImpl>;
        using OpenGLUInt = System::OpenGLUInt;

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

        NODISCARD virtual GLSLReflection GetReflector() const;
        NODISCARD virtual VisualProgramSharedPtr Clone() const;

    private:
        ShaderObjectAssociated vertexShader;
        ShaderObjectAssociated pixelShader;
        ShaderObjectAssociated geometryShader;
    };
}

#endif  // RENDERING_SHADERS_VISUAL_PROGRAM_IMPL_H
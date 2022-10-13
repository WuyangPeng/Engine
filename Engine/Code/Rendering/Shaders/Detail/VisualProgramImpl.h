///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/24 18:12)

#ifndef RENDERING_SHADERS_VISUAL_PROGRAM_IMPL_H
#define RENDERING_SHADERS_VISUAL_PROGRAM_IMPL_H

#include "Rendering/RenderingDll.h"

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
        using ShaderSharedPtr = std::shared_ptr<Shader>;
        using ConstShaderSharedPtr = std::shared_ptr<const Shader>;
        using ObjectLink = CoreTools::ObjectLink;
        using BufferTarget = CoreTools::BufferTarget;
        using BufferSource = CoreTools::BufferSource;
        using ObjectRegister = CoreTools::ObjectRegister;
        using ShaderObjectAssociated = CoreTools::ObjectAssociated<Shader>;

    public:
        VisualProgramImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

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
        ShaderObjectAssociated vertexShader;
        ShaderObjectAssociated pixelShader;
        ShaderObjectAssociated geometryShader;
    };
}

#endif  // RENDERING_SHADERS_VISUAL_PROGRAM_IMPL_H

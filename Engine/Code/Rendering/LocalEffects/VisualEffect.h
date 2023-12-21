///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/06 09:14)

#ifndef RENDERING_LOCAL_EFFECTS_VISUAL_EFFECT_H
#define RENDERING_LOCAL_EFFECTS_VISUAL_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "Mathematics/Algebra/Matrix4.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/Shaders/ShadersFwd.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(VisualEffect, VisualEffectImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE VisualEffect : public CoreTools::Object
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(VisualEffect);
        using ParentType = Object;

        using Matrix4 = Mathematics::Matrix4F;
        using ShaderSharedPtr = std::shared_ptr<Shader>;
        using ConstShaderSharedPtr = std::shared_ptr<const Shader>;
        using VisualProgramSharedPtr = std::shared_ptr<VisualProgram>;
        using ConstVisualProgramSharedPtr = std::shared_ptr<const VisualProgram>;
        using ConstantBufferSharedPtr = std::shared_ptr<ConstantBuffer>;
        using ConstConstantBufferSharedPtr = std::shared_ptr<const ConstantBuffer>;
        using BaseRendererSharedPtr = std::shared_ptr<BaseRenderer>;
        using VisualEffectSharedPtr = std::shared_ptr<ClassType>;

    public:
        explicit VisualEffect(CoreTools::DisableNotThrow disableNotThrow);
        explicit VisualEffect(const VisualProgramSharedPtr& visualProgram);
        explicit VisualEffect(const BaseRendererSharedPtr& baseRenderer);
        VisualEffect(const BaseRendererSharedPtr& baseRenderer, const VisualProgramSharedPtr& visualProgram);
        VisualEffect(ProgramFactory& factory,
                     const BaseRendererSharedPtr& baseRenderer,
                     const std::string& vertexShaderFile,
                     const std::string& pixelShaderFile);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(VisualEffect);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        void SetBaseRenderer(const BaseRendererSharedPtr& baseRenderer) noexcept;
        NODISCARD BaseRendererSharedPtr GetBaseRenderer();

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;
        NODISCARD VisualEffectSharedPtr Clone() const;

        NODISCARD ConstVisualProgramSharedPtr GetProgram() const noexcept;
        NODISCARD VisualProgramSharedPtr GetProgram() noexcept;

        NODISCARD ConstShaderSharedPtr GetVertexShader() const noexcept;
        NODISCARD ConstShaderSharedPtr GetPixelShader() const noexcept;
        NODISCARD ConstShaderSharedPtr GetGeometryShader() const noexcept;

        NODISCARD ShaderSharedPtr GetVertexShader() noexcept;
        NODISCARD ShaderSharedPtr GetPixelShader() noexcept;
        NODISCARD ShaderSharedPtr GetGeometryShader() noexcept;

        virtual void SetProjectionViewWorldMatrixConstant(const ConstantBufferSharedPtr& buffer);

        NODISCARD ConstConstantBufferSharedPtr GetProjectionViewWorldMatrixConstant() const noexcept;
        NODISCARD ConstantBufferSharedPtr GetProjectionViewWorldMatrixConstant() noexcept;

        void SetProjectionViewWorldMatrix(const Matrix4& projectionViewWorldMatrix);
        NODISCARD Matrix4 GetProjectionViewWorldMatrix() const;

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(VisualEffect);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(VisualEffect);
}

#endif  // RENDERING_LOCAL_EFFECTS_VISUAL_EFFECT_H

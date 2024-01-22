/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 09:23)

#ifndef RENDERING_LOCAL_EFFECTS_VISUAL_EFFECT_IMPL_H
#define RENDERING_LOCAL_EFFECTS_VISUAL_EFFECT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/NameMacro.h"
#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/Matrix4.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"
#include "Rendering/Resources/Buffers/ConstantBuffer.h"
#include "Rendering/Shaders/ShadersFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE VisualEffectImpl
    {
    public:
        using ClassType = VisualEffectImpl;

        using Object = CoreTools::Object;
        using ObjectLink = CoreTools::ObjectLink;
        using BufferTarget = CoreTools::BufferTarget;
        using BufferSource = CoreTools::BufferSource;
        using ObjectRegister = CoreTools::ObjectRegister;
        using ShaderSharedPtr = std::shared_ptr<Shader>;
        using ConstShaderSharedPtr = std::shared_ptr<const Shader>;
        using VisualProgramSharedPtr = std::shared_ptr<VisualProgram>;
        using ConstVisualProgramSharedPtr = std::shared_ptr<const VisualProgram>;
        using ConstantBufferSharedPtr = std::shared_ptr<ConstantBuffer>;
        using ConstConstantBufferSharedPtr = std::shared_ptr<const ConstantBuffer>;
        using ConstantBufferObjectAssociated = CoreTools::ObjectAssociated<ConstantBuffer>;
        using Matrix4 = Mathematics::Matrix4F;
        using BaseRendererSharedPtr = std::shared_ptr<BaseRenderer>;
        using BaseRendererWeakPtr = std::weak_ptr<BaseRenderer>;

    public:
        explicit VisualEffectImpl(CoreTools::DisableNotThrow disableNotThrow);
        explicit VisualEffectImpl(VisualProgramSharedPtr visualProgram);
        explicit VisualEffectImpl(const BaseRendererSharedPtr& baseRenderer);
        VisualEffectImpl(const BaseRendererSharedPtr& baseRenderer, VisualProgramSharedPtr visualProgram);
        VisualEffectImpl(ProgramFactory& factory,
                         const BaseRendererSharedPtr& baseRenderer,
                         const std::string& vertexShaderFile,
                         const std::string& pixelShaderFile);

        CLASS_INVARIANT_DECLARE;

        CORE_TOOLS_NAMES_IMPL_DECLARE;

        void SetBaseRenderer(const BaseRendererSharedPtr& aBaseRenderer) noexcept;
        NODISCARD BaseRendererSharedPtr GetBaseRenderer();

        NODISCARD int GetStreamingSize() const noexcept;
        void Save(BufferTarget& target) const;
        void Load(BufferSource& source);
        void Link(ObjectLink& source);
        void Register(ObjectRegister& target) const;

        NODISCARD ConstVisualProgramSharedPtr GetProgram() const noexcept;
        NODISCARD VisualProgramSharedPtr GetProgram() noexcept;

        NODISCARD ConstShaderSharedPtr GetVertexShader() const noexcept;
        NODISCARD ConstShaderSharedPtr GetPixelShader() const noexcept;
        NODISCARD ConstShaderSharedPtr GetGeometryShader() const noexcept;

        NODISCARD ShaderSharedPtr GetVertexShader() noexcept;
        NODISCARD ShaderSharedPtr GetPixelShader() noexcept;
        NODISCARD ShaderSharedPtr GetGeometryShader() noexcept;

        void SetProjectionViewWorldMatrixConstant(const ConstantBufferSharedPtr& buffer);

        NODISCARD ConstConstantBufferSharedPtr GetProjectionViewWorldMatrixConstant() const noexcept;
        NODISCARD ConstantBufferSharedPtr GetProjectionViewWorldMatrixConstant() noexcept;

        void SetProjectionViewWorldMatrix(const Matrix4& projectionViewWorldMatrix);
        NODISCARD Matrix4 GetProjectionViewWorldMatrix() const;

    private:
        VisualProgramSharedPtr program;
        BaseRendererWeakPtr baseRenderer;

        // 用于存储附加此效果的Visual对象的4x4投影视图世界变换的常量缓冲区。
        ConstantBufferObjectAssociated projectionViewWorldMatrixConstant;
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_VISUAL_EFFECT_IMPL_H

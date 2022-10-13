///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/24 15:40)

#ifndef RENDERING_SHADERS_VISUAL_EFFECT_IMPL_H
#define RENDERING_SHADERS_VISUAL_EFFECT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/NameMacro.h"
#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/Matrix4.h"
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
        using Matrix4F = Mathematics::Matrix4F;

    public:
        explicit VisualEffectImpl(CoreTools::DisableNotThrow disableNotThrow);
        explicit VisualEffectImpl(const VisualProgramSharedPtr& visualProgram);

        CLASS_INVARIANT_DECLARE;

        CORE_TOOLS_NAMES_IMPL_DECLARE;

        NODISCARD int GetStreamingSize() const noexcept;
        void Save(BufferTarget& target) const;
        void Load(BufferSource& source);
        void Link(ObjectLink& source);
        void Register(ObjectRegister& target) const;

        NODISCARD ConstVisualProgramSharedPtr GetProgram() const noexcept;

        NODISCARD ConstShaderSharedPtr GetVertexShader() const noexcept;
        NODISCARD ConstShaderSharedPtr GetPixelShader() const noexcept;
        NODISCARD ConstShaderSharedPtr GetGeometryShader() const noexcept;

        void SetPVWMatrixConstant(const ConstantBufferSharedPtr& buffer);

        NODISCARD ConstConstantBufferSharedPtr GetPVWMatrixConstant() const noexcept;

        void SetPVWMatrix(const Matrix4F& pvwMatrix);
        NODISCARD Matrix4F GetPVWMatrix() const;

    private:
        VisualProgramSharedPtr program;
        ConstantBufferObjectAssociated pvwMatrixConstant;
    };
}

#endif  // RENDERING_SHADERS_VISUAL_EFFECT_IMPL_H

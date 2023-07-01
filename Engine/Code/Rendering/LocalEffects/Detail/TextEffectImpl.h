///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:42)

#ifndef RENDERING_LOCAL_EFFECTS_IMPL_H
#define RENDERING_LOCAL_EFFECTS_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/DataTypes/Colour.h"
#include "Rendering/Resources/Buffers/ConstantBuffer.h"
#include "Rendering/Shaders/ProgramFactory.h"
#include "Rendering/State/SamplerState.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE TextEffectImpl
    {
    public:
        using ClassType = TextEffectImpl;
        using ConstantBufferSharedPtr = std::shared_ptr<ConstantBuffer>;
        using SamplerStateSharedPtr = std::shared_ptr<SamplerState>;
        using ConstConstantBufferSharedPtr = std::shared_ptr<const ConstantBuffer>;
        using ConstSamplerStateSharedPtr = std::shared_ptr<const SamplerState>;
        using Texture2DSharedPtr = std::shared_ptr<Texture2D>;
        using ProgramFactorySharedPtr = std::shared_ptr<ProgramFactory>;
        using VisualProgramSharedPtr = std::shared_ptr<VisualProgram>;
        using Colour = Colour<float>;
        using Object = CoreTools::Object;
        using ObjectLink = CoreTools::ObjectLink;
        using BufferTarget = CoreTools::BufferTarget;
        using BufferSource = CoreTools::BufferSource;
        using ObjectRegister = CoreTools::ObjectRegister;

    public:
        TextEffectImpl(const Texture2DSharedPtr& texture, VisualProgram& visualProgram);
        explicit TextEffectImpl(CoreTools::DisableNotThrow disableNotThrow) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstConstantBufferSharedPtr GetTranslate() const noexcept;
        NODISCARD ConstConstantBufferSharedPtr GetColor() const noexcept;

        void SetTranslate(float x, float y);
        void SetNormalizedZ(float z);
        void SetColor(const Colour& aColor);

    private:
        ConstantBufferSharedPtr translate;
        ConstantBufferSharedPtr color;
        SamplerStateSharedPtr samplerState;
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_IMPL_H

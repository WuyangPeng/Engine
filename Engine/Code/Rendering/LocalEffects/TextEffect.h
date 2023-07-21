///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/20 19:35)

#ifndef RENDERING_RENDERERS_TEXT_EFFECT_H
#define RENDERING_RENDERERS_TEXT_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "VisualEffect.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/DataTypes/Colour.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/Shaders/ShadersFwd.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(TextEffect, TextEffectImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE TextEffect : public VisualEffect
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(TextEffect);
        using ParentType = VisualEffect;
        using ProgramFactorySharedPtr = std::shared_ptr<ProgramFactory>;
        using Texture2DSharedPtr = std::shared_ptr<Texture2D>;
        using Colour = Colour<float>;

    public:
        TextEffect(ProgramFactory& factory, const Texture2DSharedPtr& texture);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(TextEffect);

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        NODISCARD ConstConstantBufferSharedPtr GetTranslate() const noexcept;
        NODISCARD ConstConstantBufferSharedPtr GetColor() const noexcept;

        NODISCARD ConstantBufferSharedPtr GetTranslate() noexcept;
        NODISCARD ConstantBufferSharedPtr GetColor() noexcept;

        void SetTranslate(float x, float y);
        void SetNormalizedZ(float z);
        void SetColor(const Colour& aColor);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RENDERERS_TEXT_EFFECT_H

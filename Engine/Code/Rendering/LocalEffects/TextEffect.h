///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.0 (2022/08/05 10:58)

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
        TextEffect(const ProgramFactorySharedPtr& factory, const Texture2DSharedPtr& texture);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(TextEffect);

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        NODISCARD ConstConstantBufferSharedPtr GetTranslate() const noexcept;
        NODISCARD ConstConstantBufferSharedPtr GetColor() const noexcept;

        void SetTranslate(float x, float y);
        void SetNormalizedZ(float z);
        void SetColor(const Colour& aColor);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RENDERERS_TEXT_EFFECT_H
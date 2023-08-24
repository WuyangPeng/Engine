///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/25 13:46)

#ifndef RENDERING_RENDERER_ENGINE_GLOBAL_FONT_H
#define RENDERING_RENDERER_ENGINE_GLOBAL_FONT_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "Rendering/DataTypes/Colour.h"
#include "Rendering/LocalEffects/LocalEffectsFwd.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"
#include "Rendering/Shaders/ShadersFwd.h"

RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(GlobalFont, GlobalFontImpl);

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE GlobalFont
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(GlobalFont);

        using FontSharedPtr = std::shared_ptr<Font>;
        using ProgramFactorySharedPtr = std::shared_ptr<ProgramFactory>;

    public:
        explicit GlobalFont(FontType fontType);
        GlobalFont(FontType fontType, ProgramFactory& factory, const std::string& shaderExtendName, int maxMessageLength);

        CLASS_INVARIANT_DECLARE;

        void SetFont(const FontSharedPtr& font);
        NODISCARD FontSharedPtr GetFont() const noexcept;
        void SetDefaultFont();
        NODISCARD FontSharedPtr GetDefaultFont() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RENDERER_ENGINE_GLOBAL_FONT_H
///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/25 13:56)

#include "Rendering/RenderingExport.h"

#include "GlobalFontImpl.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/LocalEffects/Font.h"

Rendering::GlobalFontImpl::GlobalFontImpl(FontType fontType, ProgramFactory& factory, int maxMessageLength)
    : defaultFont{ std::make_shared<Font>(fontType, factory, maxMessageLength) },
      activeFont{ defaultFont }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::GlobalFontImpl::IsValid() const noexcept
{
    if (defaultFont != nullptr &&
        activeFont != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::GlobalFontImpl::SetFont(const FontSharedPtr& font)
{
    RENDERING_CLASS_IS_VALID_1;

    activeFont = font;

    CoreTools::DisableNoexcept();
}

Rendering::GlobalFontImpl::FontSharedPtr Rendering::GlobalFontImpl::GetFont() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return activeFont;
}

void Rendering::GlobalFontImpl::SetDefaultFont()
{
    RENDERING_CLASS_IS_VALID_1;

    SetFont(defaultFont);
}

Rendering::GlobalFontImpl::FontSharedPtr Rendering::GlobalFontImpl::GetDefaultFont() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return defaultFont;
}
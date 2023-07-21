///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/25 13:56)

#include "Rendering/RenderingExport.h"

#include "GlobalFont.h"
#include "Detail/GlobalFontImpl.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/LocalEffects/Font.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, GlobalFont)

Rendering::GlobalFont::GlobalFont(FontType fontType, ProgramFactory& factory, int maxMessageLength)
    : impl{ fontType, factory, maxMessageLength }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::GlobalFont::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::GlobalFont::SetFont(const FontSharedPtr& font)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetFont(font);
}

Rendering::GlobalFont::FontSharedPtr Rendering::GlobalFont::GetFont() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetFont();
}

void Rendering::GlobalFont::SetDefaultFont()
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetDefaultFont();
}

Rendering::GlobalFont::FontSharedPtr Rendering::GlobalFont::GetDefaultFont() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetDefaultFont();
}
///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/13 11:25)

#ifndef RENDERING_LOCAL_EFFECTS_FONT_ARIAL_W400_H18_H
#define RENDERING_LOCAL_EFFECTS_FONT_ARIAL_W400_H18_H

#include "Rendering/RenderingDll.h"

#include "FontImpl.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE FontArialW400H18 : public FontImpl
    {
    public:
        using ClassType = FontArialW400H18;
        using ParentType = FontImpl;

    public:
        FontArialW400H18(ProgramFactory& factory, int maxMessageLength);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD FontSharedPtr Clone() const override;

    private:
        using TexelsArrayType = std::array<uint8_t, 47718>;

    private:
        NODISCARD static const TexelsType& GetTexels();
        NODISCARD static const CharacterDataType& GetCharacterDataType() noexcept;

    private:
        static constexpr auto width = 2651;
        static constexpr auto height = 18;
        static const TexelsArrayType texels;
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_FONT_ARIAL_W400_H18_H

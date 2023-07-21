///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/12 15:45)

#ifndef RENDERING_LOCAL_EFFECTS_FONT_FACTORY_H
#define RENDERING_LOCAL_EFFECTS_FONT_FACTORY_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/DataTypes/Colour.h"
#include "Rendering/LocalEffects/LocalEffectsInternalFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/Shaders/ProgramFactory.h"

#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE FontFactory
    {
    public:
        using ClassType = FontFactory;

        using FontSharedPtr = std::shared_ptr<FontImpl>;
        using ProgramFactorySharedPtr = std::shared_ptr<ProgramFactory>;

        using TexelsType = std::vector<char>;
        using CharacterDataType = std::array<float, 257>;

    public:
        NODISCARD static FontSharedPtr Create(FontType fontType,
                                              ProgramFactory& factory,
                                              int maxMessageLength);
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_FONT_FACTORY_H

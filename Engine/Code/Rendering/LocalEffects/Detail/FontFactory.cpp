///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/12 15:46)

#include "Rendering/RenderingExport.h"

#include "FontArialW400H12.h"
#include "FontArialW400H14.h"
#include "FontArialW400H16.h"
#include "FontArialW400H18.h"
#include "FontArialW700H12.h"
#include "FontArialW700H14.h"
#include "FontArialW700H16.h"
#include "FontArialW700H18.h"
#include "FontFactory.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Rendering/LocalEffects/Flags/FontFlags.h"

Rendering::FontFactory::FontSharedPtr Rendering::FontFactory::Create(FontType fontType, ProgramFactory& factory, const std::string& shaderExtendName, int maxMessageLength)
{
    switch (fontType)
    {
        case FontType::ArialW400H12:
            return std::make_shared<FontArialW400H12>(factory, shaderExtendName, maxMessageLength);
        case FontType::ArialW400H14:
            return std::make_shared<FontArialW400H14>(factory, shaderExtendName, maxMessageLength);
        case FontType::ArialW400H16:
            return std::make_shared<FontArialW400H16>(factory, shaderExtendName, maxMessageLength);
        case FontType::ArialW400H18:
            return std::make_shared<FontArialW400H18>(factory, shaderExtendName, maxMessageLength);
        case FontType::ArialW700H12:
            return std::make_shared<FontArialW700H12>(factory, shaderExtendName, maxMessageLength);
        case FontType::ArialW700H14:
            return std::make_shared<FontArialW700H14>(factory, shaderExtendName, maxMessageLength);
        case FontType::ArialW700H16:
            return std::make_shared<FontArialW700H16>(factory, shaderExtendName, maxMessageLength);
        case FontType::ArialW700H18:
            return std::make_shared<FontArialW700H18>(factory, shaderExtendName, maxMessageLength);
        default:
        {
            THROW_EXCEPTION(SYSTEM_TEXT("未找到指定的字体类型。"))
        }
    }
}

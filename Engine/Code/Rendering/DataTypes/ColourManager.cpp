///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/29 11:07)

#include "Rendering/RenderingExport.h"

#include "ColourDetail.h"
#include "ColourManager.h"

#include <gsl/util>

Rendering::ByteColour Rendering::ColourManager::ExtractR8G8B8(uint32_t color) noexcept
{
    auto colour = ExtractR8G8B8A8(color);
    colour.SetAlpha(ColourDefaultTraits<uint8_t>::maxValue);

    return colour;
}

Rendering::ByteColour Rendering::ColourManager::ExtractR8G8B8A8(uint32_t color) noexcept
{
#ifdef SYSTEM_BIG_ENDIAN

    return ByteColour{ gsl::narrow_cast<uint8_t>((color & 0xFF000000) >> 24),
                       gsl::narrow_cast<uint8_t>((color & 0x00FF0000) >> 16),
                       gsl::narrow_cast<uint8_t>((color & 0x0000FF00) >> 8),
                       gsl::narrow_cast<uint8_t>((color & 0x000000FF)) };


#else  // !SYSTEM_BIG_ENDIAN

    return ByteColour{ gsl::narrow_cast<uint8_t>((color & 0x000000FF)),
                       gsl::narrow_cast<uint8_t>((color & 0x0000FF00) >> 8),
                       gsl::narrow_cast<uint8_t>((color & 0x00FF0000) >> 16),
                       gsl::narrow_cast<uint8_t>((color & 0xFF000000) >> 24) };

#endif  // SYSTEM_BIG_ENDIAN
}

// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/18 15:29)

#include "Rendering/RenderingExport.h"

#include "ColourDetail.h"
#include "ColourManager.h"

#include <gsl/util>

Rendering::ByteColour Rendering::ColourManager::ExtractR8G8B8(uint32_t color) noexcept
{
    auto colour = ExtractR8G8B8A8(color);
    colour.SetAlpha(ColourDefaultTraits<uint8_t>::sm_MaxValue);

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

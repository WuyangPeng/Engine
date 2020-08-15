// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/18 15:53)

#include "Rendering/RenderingExport.h"

#include "Utility.h"

#include <algorithm>

using std::swap;
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
void Rendering::Utility
    ::ReflectX (int xSize, int ySize,int numBytesPerPixel,char* pixels) noexcept
{
    const auto xMax = xSize / 2;
    const auto xSizeMinus1 = xSize - 1;
    for (auto x = 0; x < xMax; ++x)
    {
		const auto reflectX = xSizeMinus1 - x;
        for (auto y = 0; y < ySize; ++y)
        {
			auto source = numBytesPerPixel * (x + xSize * y);
			auto target = numBytesPerPixel * (reflectX + xSize * y);
            for (auto i = 0; i < numBytesPerPixel; ++i)
            {
                swap(pixels[source + i],pixels[target + i]);
            }
        }
    }
}

void Rendering::Utility
    ::ReflectY (int xSize, int ySize, int numBytesPerPixel,  char* pixels) noexcept
{
    const auto yMax = ySize/2;
    const auto ySizeMinus1 = ySize - 1;
    for (auto y = 0; y < yMax; ++y)
    {
		const auto reflectY = ySizeMinus1 - y;
        for (auto x = 0; x < xSize; ++x)
        {
			auto source = numBytesPerPixel * (x + xSize * y);
			auto target = numBytesPerPixel * (x + xSize * reflectY);
            for (auto i = 0; i < numBytesPerPixel; ++i)
            {
                swap(pixels[source + i],pixels[target + i]);;
            }
        }
    }
}
#include STSTEM_WARNING_POP
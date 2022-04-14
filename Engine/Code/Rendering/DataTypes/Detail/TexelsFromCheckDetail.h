///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/29 13:19)

#ifndef RENDERING_DATA_TYPES_TEXELS_FROM_CHECK_DETAIL_H
#define RENDERING_DATA_TYPES_TEXELS_FROM_CHECK_DETAIL_H

#include "Rendering/RenderingExport.h"

#include "ColourTextureFormatTraits.h"
#include "TexelsFromCheck.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

template <Rendering::TextureFormat Format>
Rendering::TexelsFromCheck<Format>::TexelsFromCheck(size_t inTexelsSize) noexcept
    : inTexelsSize{ inTexelsSize }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <Rendering::TextureFormat Format>
bool Rendering::TexelsFromCheck<Format>::IsValid() const noexcept
{
    if (0 < inTexelsSize)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <Rendering::TextureFormat Format>
size_t Rendering::TexelsFromCheck<Format>::GetOutTexelsLength() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return inTexelsSize / step;
}

template <Rendering::TextureFormat Format>
void Rendering::TexelsFromCheck<Format>::CheckInTexels() noexcept(g_Assert < 1 || g_RenderingAssert < 1)
{
    RENDERING_CLASS_IS_VALID_1;

    RENDERING_ASSERTION_1(inTexelsSize % step == 0, "输入数组大小%d不是%d的倍数。", inTexelsSize, step);
}

template <Rendering::TextureFormat Format>
void Rendering::TexelsFromCheck<Format>::CheckOutTexels(MAYBE_UNUSED size_t outTexelsSize) noexcept(g_Assert < 2 || g_RenderingAssert < 2)
{
    RENDERING_CLASS_IS_VALID_1;

    RENDERING_ASSERTION_2(outTexelsSize == GetOutTexelsLength(), "输出数组大小%d错误。", outTexelsSize);
}

#endif  // RENDERING_DATA_TYPES_TEXELS_FROM_CHECK_DETAIL_H
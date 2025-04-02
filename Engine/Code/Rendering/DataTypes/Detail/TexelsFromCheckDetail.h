///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:54)

#ifndef RENDERING_DATA_TYPES_TEXELS_FROM_CHECK_DETAIL_H
#define RENDERING_DATA_TYPES_TEXELS_FROM_CHECK_DETAIL_H

#include "Rendering/RenderingExport.h"

#include "TexelsFromCheck.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/DataTypes/ColourTextureFormatTraits.h"

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
void Rendering::TexelsFromCheck<Format>::CheckInTexels() noexcept(gAssert < 1 || gRenderingAssert < 1)
{
    RENDERING_CLASS_IS_VALID_1;

    RENDERING_ASSERTION_1(inTexelsSize % step == 0, "���������С%d����%d�ı�����", inTexelsSize, step);
}

template <Rendering::TextureFormat Format>
void Rendering::TexelsFromCheck<Format>::CheckOutTexels(MAYBE_UNUSED size_t outTexelsSize) noexcept(gAssert < 2 || gRenderingAssert < 2)
{
    RENDERING_CLASS_IS_VALID_1;

    RENDERING_ASSERTION_2(outTexelsSize == GetOutTexelsLength(), "��������С%d����", outTexelsSize);
}

#endif  // RENDERING_DATA_TYPES_TEXELS_FROM_CHECK_DETAIL_H
//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.0.0 (2020/08/22 2:02)

#ifndef RENDERING_DATA_TYPES_TEXELS_TO_CHECK_DETAIL_H
#define RENDERING_DATA_TYPES_TEXELS_TO_CHECK_DETAIL_H

#include "Rendering/RenderingExport.h"

#include "TexelsToCheck.h"
#include "ColourTextureFormatTraits.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

template <Rendering::TextureFormat Format>
Rendering::TexelsToCheck<Format>::TexelsToCheck(size_t inTexelsSize) noexcept
    : m_InTexelsSize{ inTexelsSize }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <Rendering::TextureFormat Format>
bool Rendering::TexelsToCheck<Format>::IsValid() const noexcept
{
    if (0 < m_InTexelsSize)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <Rendering::TextureFormat Format>
size_t Rendering::TexelsToCheck<Format>::GetOutTexelsLength() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_InTexelsSize * sm_Step;
} 

template <Rendering::TextureFormat Format>
void Rendering::TexelsToCheck<Format>::CheckOutTexels([[maybe_unused]] size_t outTexelsSize) noexcept(g_Assert < 2 || g_RenderingAssert < 2)
{
    RENDERING_CLASS_IS_VALID_1;

    RENDERING_ASSERTION_2(outTexelsSize == GetOutTexelsLength(), "��������С%d����", outTexelsSize);
}

#endif  // RENDERING_DATA_TYPES_TEXELS_TO_CHECK_DETAIL_H
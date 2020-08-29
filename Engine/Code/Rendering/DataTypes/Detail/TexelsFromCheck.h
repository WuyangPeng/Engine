//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.0.0 (2020/08/21 15:11)

#ifndef RENDERING_DATA_TYPES_TEXELS_FROM_CHECK_H
#define RENDERING_DATA_TYPES_TEXELS_FROM_CHECK_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "Rendering/DataTypes/DataTypesFwd.h"

namespace Rendering
{
    template <TextureFormat Format>
    class TexelsFromCheck
    {
    public:
        using ClassType = TexelsFromCheck;

    public:
        explicit TexelsFromCheck(size_t inTexelsSize) noexcept;

        CLASS_INVARIANT_DECLARE;

        size_t GetOutTexelsLength() const noexcept;

        void CheckInTexels() noexcept(g_Assert < 1 || g_RenderingAssert < 1);
        void CheckOutTexels(size_t outTexelsSize) noexcept(g_Assert < 2 || g_RenderingAssert < 2);

    private:
        static constexpr auto sm_Step = ColourTextureFormatTraits<Format>::sm_Step;

    private:
        size_t m_InTexelsSize;
    };
}

#endif  // RENDERING_DATA_TYPES_TEXELS_FROM_CHECK_H
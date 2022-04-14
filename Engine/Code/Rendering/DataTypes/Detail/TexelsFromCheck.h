///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/03/29 13:19)

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

        NODISCARD size_t GetOutTexelsLength() const noexcept;

        void CheckInTexels() noexcept(g_Assert < 1 || g_RenderingAssert < 1);
        void CheckOutTexels(MAYBE_UNUSED size_t outTexelsSize) noexcept(g_Assert < 2 || g_RenderingAssert < 2);

    private:
        static constexpr auto step = ColourTextureFormatTraits<Format>::step;

    private:
        size_t inTexelsSize;
    };
}

#endif  // RENDERING_DATA_TYPES_TEXELS_FROM_CHECK_H
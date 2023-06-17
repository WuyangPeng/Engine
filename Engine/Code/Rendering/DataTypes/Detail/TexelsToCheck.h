///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:55)

#ifndef RENDERING_DATA_TYPES_TEXELS_TO_CHECK_H
#define RENDERING_DATA_TYPES_TEXELS_TO_CHECK_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "Rendering/DataTypes/DataTypesFwd.h"

namespace Rendering
{
    template <TextureFormat Format>
    class TexelsToCheck
    {
    public:
        using ClassType = TexelsToCheck;

    public:
        explicit TexelsToCheck(size_t inTexelsSize) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD size_t GetOutTexelsLength() const noexcept;

        void CheckOutTexels(MAYBE_UNUSED size_t outTexelsSize) noexcept(gAssert < 2 || gRenderingAssert < 2);

    private:
        static constexpr auto step = ColourTextureFormatTraits<Format>::step;

    private:
        size_t inTexelsSize;
    };
}

#endif  // RENDERING_DATA_TYPES_TEXELS_TO_CHECK_H
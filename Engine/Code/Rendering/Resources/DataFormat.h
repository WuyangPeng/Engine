///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/08 13:48)

#ifndef RENDERING_RESOURCES_DATA_FORMAT_H
#define RENDERING_RESOURCES_DATA_FORMAT_H

#include "Rendering/RenderingDll.h"

#include "ResourcesFwd.h"
#include "Flags/DataFormatType.h"
#include "System/Helper/EnumCast.h"

#include <array>
#include <string>

namespace Rendering
{
    class DataFormat
    {
    public:
        using ClassType = DataFormat;

    public:
        NODISCARD static const std::string& GetName(DataFormatType type);

        NODISCARD static int GetNumBytesPerStruct(DataFormatType type);

        NODISCARD static int GetNumChannels(DataFormatType type);

        NODISCARD static ChannelType GetChannelType(DataFormatType type);

        NODISCARD static bool ConvertChannel(DataFormatType type);

        NODISCARD static bool IsSupported(DataFormatType type);

        NODISCARD constexpr static bool IsDepth(DataFormatType type) noexcept
        {
            return type == DataFormatType::D32FloatS8X24UInt ||
                   type == DataFormatType::D32Float ||
                   type == DataFormatType::D24UNormS8UInt ||
                   type == DataFormatType::D16UNorm;
        }

    private:
        static constexpr auto numFormats = System::EnumCastUnderlying(DataFormatType::NumFormats);
    };
}

#endif  // RENDERING_RESOURCES_DATA_FORMAT_H
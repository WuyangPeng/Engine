///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:23)

#ifndef RENDERING_RESOURCES_CHANNEL_TYPE_H
#define RENDERING_RESOURCES_CHANNEL_TYPE_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
    enum class ChannelType
    {
        UnSupported,
        Byte,
        UByte,
        Short,
        UShort,
        Int,
        UInt,
        HalfFloat,
        Float,
        Double,
        Int_10_10_2,
        UInt_10_10_2,
        Float_11_11_10,
        UInt_24_8,
        NumChannelTypes
    };
}

#endif  // RENDERING_RESOURCES_CHANNEL_TYPE_H

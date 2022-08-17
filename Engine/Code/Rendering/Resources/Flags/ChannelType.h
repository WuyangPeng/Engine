///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.0 (2022/08/08 13:18)

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

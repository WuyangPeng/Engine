///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.1 (2022/08/19 0:35)

#ifndef RENDERING_STATE_SAMPLER_STATE_MODE_H
#define RENDERING_STATE_SAMPLER_STATE_MODE_H

#include "System/Helper/EnumMacro.h"

#include <iostream>

namespace Rendering
{
    enum class SamplerStateMode
    {
        Wrap,
        Mirror,
        Clamp,
        Border,
        MirrorOnce
    };
}

#endif  // RENDERING_STATE_SAMPLER_STATE_MODE_H

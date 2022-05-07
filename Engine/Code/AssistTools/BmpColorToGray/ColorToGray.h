///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/28 16:23)

#ifndef ASSIST_TOOLS_BMP_COLOR_TO_GRAY_COLOR_TO_GRAY_H
#define ASSIST_TOOLS_BMP_COLOR_TO_GRAY_COLOR_TO_GRAY_H

#include "AssistTools/AssistToolsDll.h"

#include <vector>

namespace AssistTools
{
    class ASSIST_TOOLS_DEFAULT_DECLARE ColorToGray
    {
    public:
        ColorToGray(int width, int height, std::vector<uint8_t>& color);
    };
}

#endif  // ASSIST_TOOLS_BMP_COLOR_TO_GRAY_COLOR_TO_GRAY_H

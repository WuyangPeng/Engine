///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/04/28 16:23)

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

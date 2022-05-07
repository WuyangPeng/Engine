///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/28 16:23)

#include "AssistTools/AssistToolsExport.h"

#include "ColorToGray.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/PragmaWarning/NumericCast.h"

AssistTools::ColorToGray::ColorToGray(int width, int height, std::vector<uint8_t>& color)
{
    auto index = 0;
    for (auto i = 0; i < width * height; ++i, index += 3)
    {
        const auto b = static_cast<float>(color.at(index));
        const auto index1 = index + 1;
        const auto g = static_cast<float>(color.at(index1));
        const auto index2 = index + 2;
        const auto r = static_cast<float>(color.at(index2));
        const auto gray = boost::numeric_cast<uint8_t>(boost::numeric_cast<int>(0.30f * r + 0.59f * g + 0.11f * b));
        color.at(index) = gray;
        color.at(index1) = gray;
        color.at(index2) = gray;
    }
}

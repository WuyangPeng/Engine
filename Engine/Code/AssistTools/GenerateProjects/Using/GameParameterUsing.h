/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 19:53)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GAME_PARAMETER_USING_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GAME_PARAMETER_USING_H

#include "AssistTools/AssistToolsDll.h"

#include <string_view>

namespace AssistTools
{
    constexpr std::string_view moduleKey{ "Module" };
    constexpr std::string_view middleLayerKey{ "MiddleLayer" };

    constexpr std::string_view chineseNameKey{ "ChineseName" };
    constexpr std::string_view projectServiceTypeKey{ "ProjectServiceType" };
    constexpr std::string_view uppercaseKey{ "Uppercase" };
    constexpr std::string_view isManagerKey{ "IsManager" };
    constexpr std::string_view guidKey{ "Guid" };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GAME_PARAMETER_USING_H
///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/10 09:40)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GAME_PARAMETER_TYPE_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GAME_PARAMETER_TYPE_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace AssistTools
{
    enum class GameParameterType
    {
        Begin,

        CoreName = Begin,
        CoreCapital,
        ProjectChineseName,
        ProjectDescribeName,
        ProjectName,
        ProjectCapital,
        ProjectAbbreviation,
        EndYear,
        Version,
        VersionNum,
        TestingName,

        Count,
    };

    NODISCARD ASSIST_TOOLS_DEFAULT_DECLARE System::StringView ToString(GameParameterType gameParameterType);
    NODISCARD ASSIST_TOOLS_DEFAULT_DECLARE std::string ToMultiByteString(GameParameterType gameParameterType);
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GAME_PARAMETER_TYPE_H
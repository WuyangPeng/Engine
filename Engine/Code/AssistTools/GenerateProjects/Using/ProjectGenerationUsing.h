///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/10 09:28)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_PROJECT_GENERATION_USING_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_PROJECT_GENERATION_USING_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace AssistTools
{
    constexpr System::StringView dollar{ SYSTEM_TEXT("$") };

    constexpr System::StringView dataKey{ SYSTEM_TEXT("Data") };
    constexpr System::StringView hourKey{ SYSTEM_TEXT("Hour") };
    constexpr System::StringView minuteKey{ SYSTEM_TEXT("Minute") };

    constexpr System::StringView moduleCountKey{ SYSTEM_TEXT("ModuleCount") };
    constexpr System::StringView moduleDescribeKey{ SYSTEM_TEXT("ModuleDescribe") };
    constexpr System::StringView serialKey{ SYSTEM_TEXT("Serial") };
    constexpr System::StringView moduleNameKey{ SYSTEM_TEXT("ModuleName") };
    constexpr System::StringView moduleChineseNameKey{ SYSTEM_TEXT("ModuleChineseName") };
    constexpr System::StringView moduleJsonKey{ SYSTEM_TEXT("ModuleJson") };
    constexpr System::StringView moduleNameIsEndKey{ SYSTEM_TEXT("ModuleNameIsEnd") };
    constexpr System::StringView moduleTestingJsonKey{ SYSTEM_TEXT("ModuleTestingJson") };
    constexpr System::StringView callRunBatKey{ SYSTEM_TEXT("CallRunBat") };
    constexpr System::StringView callRunTestingBatKey{ SYSTEM_TEXT("CallRunTestingBat") };
    constexpr System::StringView copyrightKey{ SYSTEM_TEXT("Copyright") };
    constexpr System::StringView codeAnalysisKey{ SYSTEM_TEXT("CodeAnalysis") };
    constexpr System::StringView testingCodeAnalysisKey{ SYSTEM_TEXT("TestingCodeAnalysis") };
    constexpr System::StringView middleLayerIncludeKey{ SYSTEM_TEXT("MiddleLayerInclude") };
    constexpr System::StringView middleLayerFwdIncludeKey{ SYSTEM_TEXT("MiddleLayerFwdInclude") };
    constexpr System::StringView middleLayerNameKey{ SYSTEM_TEXT("MiddleLayerName") };
    constexpr System::StringView toolDirectoryKey{ SYSTEM_TEXT("ToolDirectory") };
    constexpr System::StringView toolProjectKey{ SYSTEM_TEXT("ToolProject") };
    constexpr System::StringView toolsProjectConfigurationPlatformsKey{ SYSTEM_TEXT("ToolProjectConfigurationPlatforms") };
    constexpr System::StringView toolsNestedProjectsKey{ SYSTEM_TEXT("ToolNestedProjects") };
    constexpr System::StringView guidIndexKey{ SYSTEM_TEXT("Guid") };
    constexpr System::StringView staticDescribeKey{ SYSTEM_TEXT("StaticDescribe") };
    constexpr System::StringView configurationKey{ SYSTEM_TEXT("Configuration") };
    constexpr System::StringView testingToolProjectKey{ SYSTEM_TEXT("TestingToolProject") };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_PROJECT_GENERATION_USING_H
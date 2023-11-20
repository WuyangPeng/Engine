///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/10 09:28)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_ENGINE_USING_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_ENGINE_USING_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace AssistTools
{
    constexpr System::StringView slash{ SYSTEM_TEXT("/") };
    constexpr System::StringView extension{ SYSTEM_TEXT(".txt") };
    constexpr System::StringView jsonExtension{ SYSTEM_TEXT(".json") };
    constexpr System::StringView batExtension{ SYSTEM_TEXT(".bat") };
    constexpr System::StringView generateDescribe{ SYSTEM_TEXT("Generate") };
    constexpr System::StringView configurationDescribe{ SYSTEM_TEXT("Configuration") };
    constexpr System::StringView windowsDescribe{ SYSTEM_TEXT("Windows") };
    constexpr System::StringView runDescribe{ SYSTEM_TEXT("Run") };
    constexpr System::StringView runTestingDescribe{ SYSTEM_TEXT("RunTesting") };
    constexpr System::StringView doxygenDescribe{ SYSTEM_TEXT("Doxygen") };
    constexpr System::StringView docDescribe{ SYSTEM_TEXT("Doc") };
    constexpr System::StringView moduleNameDescribe{ SYSTEM_TEXT("ModuleName") };
    constexpr System::StringView moduleUppercaseDescribe{ SYSTEM_TEXT("ModuleUppercase") };
    constexpr System::StringView batDescribe{ SYSTEM_TEXT("Bat") };
    constexpr System::StringView codeDescribe{ SYSTEM_TEXT("Code") };
    constexpr System::StringView projectDescribe{ SYSTEM_TEXT("Project") };
    constexpr System::StringView helperDescribe{ SYSTEM_TEXT("Helper") };
    constexpr System::StringView coreDescribe{ SYSTEM_TEXT("Core") };
    constexpr System::StringView moduleDescribe{ SYSTEM_TEXT("Module") };
    constexpr System::StringView engineDescribe{ SYSTEM_TEXT("Engine") };
    constexpr System::StringView middleLayerDescribe{ SYSTEM_TEXT("MiddleLayer") };
    constexpr System::StringView inputDescribe{ SYSTEM_TEXT("Input") };
    constexpr System::StringView projectNameWindowsDescribe{ SYSTEM_TEXT("ProjectNameWindows") };
    constexpr System::StringView resourceDescribe{ SYSTEM_TEXT("Resource") };
    constexpr System::StringView todoDescribe{ SYSTEM_TEXT("Todo") };
    constexpr System::StringView middleLayerUppercaseDescribe{ SYSTEM_TEXT("MiddleLayerUppercase") };
    constexpr System::StringView managerDescribe{ SYSTEM_TEXT("Manager") };
    constexpr System::StringView isManagerDescribe{ SYSTEM_TEXT("IsManager") };
    constexpr System::StringView middleLayerNameDescribe{ SYSTEM_TEXT("MiddleLayerName") };
    constexpr System::StringView levelDescribe{ SYSTEM_TEXT("Level") };
    constexpr System::StringView moduleChineseNameDescribe{ SYSTEM_TEXT("ModuleChineseName") };
    constexpr System::StringView versionSuiteDescribe{ SYSTEM_TEXT("VersionSuite") };
    constexpr System::StringView engineSuiteDescribe{ SYSTEM_TEXT("EngineSuite") };
    constexpr System::StringView moduleCoreDescribe{ SYSTEM_TEXT("ModuleCore") };
    constexpr System::StringView moduleMiddleLayerDescribe{ SYSTEM_TEXT("ModuleMiddleLayer") };
    constexpr System::StringView testingDescribe{ SYSTEM_TEXT("Testing") };
    constexpr System::StringView coreTestingDescribe{ SYSTEM_TEXT("CoreTesting") };
    constexpr System::StringView middleLayerTestingDescribe{ SYSTEM_TEXT("MiddleLayerTesting") };

    constexpr System::StringView readMeMd{ SYSTEM_TEXT("ReadMeMd") };
    constexpr System::StringView readMeMdOriginal{ SYSTEM_TEXT("ReadMe.md") };

    constexpr System::StringView gitIgnore{ SYSTEM_TEXT("GitIgnore") };
    constexpr System::StringView gitIgnoreOriginal{ SYSTEM_TEXT(".gitignore") };

    constexpr System::StringView clangFormat{ SYSTEM_TEXT("ClangFormat") };
    constexpr System::StringView clangFormatOriginal{ SYSTEM_TEXT(".clang-format") };

    constexpr System::StringView environmentVariable{ SYSTEM_TEXT("EnvironmentVariableJson") };
    constexpr System::StringView environmentVariableOriginal{ SYSTEM_TEXT("EnvironmentVariable.json") };

    constexpr System::StringView logJson{ SYSTEM_TEXT("LogJson") };
    constexpr System::StringView logJsonOriginal{ SYSTEM_TEXT("Log.json") };

    constexpr System::StringView projectJson{ SYSTEM_TEXT("ProjectJson") };
    constexpr System::StringView projectJsonOriginal{ SYSTEM_TEXT("Project.json") };

    constexpr System::StringView projectTestingJson{ SYSTEM_TEXT("ProjectTestingJson") };
    constexpr System::StringView projectTestingJsonOriginal{ SYSTEM_TEXT("ProjectTesting.json") };

    constexpr System::StringView projectNameJson{ SYSTEM_TEXT("ProjectNameJson") };

    constexpr System::StringView rendererJson{ SYSTEM_TEXT("RendererJson") };
    constexpr System::StringView rendererJsonOriginal{ SYSTEM_TEXT("Renderer.json") };

    constexpr System::StringView runAllBat{ SYSTEM_TEXT("RunAllBat") };
    constexpr System::StringView runAllTestingBat{ SYSTEM_TEXT("RunAllTestingBat") };
    constexpr System::StringView runProjectTestingBat{ SYSTEM_TEXT("RunProjectTestingBat") };

    constexpr System::StringView runAllClientBat{ SYSTEM_TEXT("RunAllClientBat") };
    constexpr System::StringView runAllClientBatOriginal{ SYSTEM_TEXT("RunAllClient.bat") };

    constexpr System::StringView runAllServerBat{ SYSTEM_TEXT("RunAllServerBat") };
    constexpr System::StringView runAllServerBatOriginal{ SYSTEM_TEXT("RunAllServer.bat") };

    constexpr System::StringView runBat{ SYSTEM_TEXT("RunBat") };

    constexpr System::StringView doxygenFile{ SYSTEM_TEXT("Doxyfile") };
    constexpr System::StringView doxygenFileOriginal{ SYSTEM_TEXT("Doxyfile") };

    constexpr System::StringView overviewMd{ SYSTEM_TEXT("OverviewMd") };
    constexpr System::StringView overviewMdOriginal{ SYSTEM_TEXT("Overview.md") };

    constexpr System::StringView delDoxygenFileBat{ SYSTEM_TEXT("DelDoxygenFileBat") };
    constexpr System::StringView delDoxygenFileBatOriginal{ SYSTEM_TEXT("DelDoxygenFile.bat") };

    constexpr System::StringView scheduleMd{ SYSTEM_TEXT("ScheduleMd") };
    constexpr System::StringView scheduleMdOriginal{ SYSTEM_TEXT("Schedule.md") };

    constexpr auto maxLevel = 10;
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_ENGINE_USING_H
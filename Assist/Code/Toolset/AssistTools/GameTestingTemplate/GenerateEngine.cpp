///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/13 10:35)

#include "GenerateEngine.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/CopyrightData.h"
#include "AssistTools/GenerateProjects/GenerateTestingTemplateCodeDirectory.h"
#include "AssistTools/GenerateProjects/GenerateTestingTemplateEngineDirectory.h"

GameTestingTemplate::GenerateEngine::GenerateEngine(const std::string& configurationFileName, const std::string& parameterFileName)
    : configurationFileName{ configurationFileName }, parameter{ parameterFileName }
{
    Generate();

    System::SystemPause();

    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(GameTestingTemplate, GenerateEngine)

void GameTestingTemplate::GenerateEngine ::Generate()
{
    const auto newCoreName = parameter.GetReplacing(SYSTEM_TEXT("CoreName"));
    const auto newIncludeName = parameter.GetReplacing(SYSTEM_TEXT("GameTemplateInclude"));
    const auto projectName = parameter.GetReplacing(SYSTEM_TEXT("ProjectName"));
    auto endYear = boost::lexical_cast<int>(parameter.GetReplacing(SYSTEM_TEXT("EndYear")));
    const auto versions = parameter.GetReplacing(SYSTEM_TEXT("Versions"));
    const auto projectChineseName = parameter.GetReplacing(SYSTEM_TEXT("ProjectChineseName"));
    const auto resourceDirectory = parameter.GetReplacing(SYSTEM_TEXT("ResourceDirectory"));
    const auto exportDirectory = parameter.GetReplacing(SYSTEM_TEXT("ExportDirectory"));
    const auto solutionName = parameter.GetReplacing(SYSTEM_TEXT("SolutionName"));
    const auto projectCapitalName = parameter.GetReplacing(SYSTEM_TEXT("ProjectCapital"));
    const auto coreCapital = parameter.GetReplacing(SYSTEM_TEXT("CoreCapital"));
    const auto newTestingIncludeName = parameter.GetReplacing(SYSTEM_TEXT("GameTestingTemplateInclude"));
    const auto newDebugLibName = parameter.GetReplacing(SYSTEM_TEXT("DebugLibName"));
    const auto newReleaseLibName = parameter.GetReplacing(SYSTEM_TEXT("ReleaseLibName"));

    AssistTools::CopyrightData copyrightData{ endYear, versions, projectChineseName };

    AssistTools::GenerateTestingTemplateEngineDirectory generateTemplateEngineDirectory{ resourceDirectory, configurationFileName };

    generateTemplateEngineDirectory.GenerateTo(exportDirectory, solutionName, newCoreName, newIncludeName, newTestingIncludeName, newDebugLibName, newReleaseLibName);

    AssistTools::GenerateTestingTemplateCodeDirectory generateTemplateCodeDirectory{ resourceDirectory, configurationFileName };

    generateTemplateCodeDirectory.GenerateTo(exportDirectory, solutionName, copyrightData, projectCapitalName, newCoreName, coreCapital);
}

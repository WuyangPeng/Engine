///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/06/30 16:02)

#include "GenerateEngine.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/CopyrightData.h"
#include "AssistTools/GenerateProjects/GenerateTemplateCodeDirectory.h"
#include "AssistTools/GenerateProjects/GenerateTemplateEngineDirectory.h"

using std::string;

GameTemplate::GenerateEngine ::GenerateEngine(const string& configurationFileName, const string& parameterFileName)
    : configurationFileName{ configurationFileName }, parameter{ parameterFileName }
{
    Generate();

    System::SystemPause();

    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(GameTemplate, GenerateEngine)

void GameTemplate::GenerateEngine ::Generate()
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

    AssistTools::CopyrightData copyrightData{ endYear, versions, projectChineseName };

    AssistTools::GenerateTemplateEngineDirectory generateTemplateEngineDirectory{ resourceDirectory, configurationFileName };

    generateTemplateEngineDirectory.GenerateTo(exportDirectory, solutionName, newCoreName, newIncludeName);

    AssistTools::GenerateTemplateCodeDirectory generateTemplateCodeDirectory{ resourceDirectory, configurationFileName };

    generateTemplateCodeDirectory.GenerateTo(exportDirectory, solutionName, copyrightData, projectCapitalName, projectName, newCoreName, coreCapital);
}

// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/11 1:14)

#include "GenerateEngine.h" 
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/CopyrightData.h"
#include "AssistTools/GenerateProjects/GenerateTemplateCodeDirectory.h"
#include "AssistTools/GenerateProjects/GenerateTemplateEngineDirectory.h"

#include "System/Helper/PragmaWarning/LexicalCast.h"

using std::string;

GameTemplate::GenerateEngine
	::GenerateEngine(const string& configurationFileName, const string& parameterFileName)
	:m_ConfigurationFileName{ configurationFileName }, m_Parameter{ parameterFileName }
{
	Generate();

	System::SystemPause();

	ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(GameTemplate, GenerateEngine)

void GameTemplate::GenerateEngine
	::Generate()
{
	const auto newCoreName = m_Parameter.GetReplacing(SYSTEM_TEXT("CoreName"));
	const auto newIncludeName = m_Parameter.GetReplacing(SYSTEM_TEXT("GameTemplateInclude"));
	const auto projectName = m_Parameter.GetReplacing(SYSTEM_TEXT("ProjectName"));
	auto endYear = boost::lexical_cast<int>(m_Parameter.GetReplacing(SYSTEM_TEXT("EndYear")));
	const auto versions = m_Parameter.GetReplacing(SYSTEM_TEXT("Versions"));
	const auto projectChineseName = m_Parameter.GetReplacing(SYSTEM_TEXT("ProjectChineseName"));
	const auto resourceDirectory = m_Parameter.GetReplacing(SYSTEM_TEXT("ResourceDirectory"));
	const auto exportDirectory = m_Parameter.GetReplacing(SYSTEM_TEXT("ExportDirectory"));
	const auto solutionName = m_Parameter.GetReplacing(SYSTEM_TEXT("SolutionName"));
	const auto projectCapitalName = m_Parameter.GetReplacing(SYSTEM_TEXT("ProjectCapital"));
	const auto coreCapital = m_Parameter.GetReplacing(SYSTEM_TEXT("CoreCapital"));

	AssistTools::CopyrightData copyrightData{ endYear, versions, projectChineseName };

	AssistTools::GenerateTemplateEngineDirectory generateTemplateEngineDirectory{ resourceDirectory, m_ConfigurationFileName };

	generateTemplateEngineDirectory.GenerateTo(exportDirectory, solutionName, newCoreName, newIncludeName);

	AssistTools::GenerateTemplateCodeDirectory generateTemplateCodeDirectory{ resourceDirectory, m_ConfigurationFileName };

	generateTemplateCodeDirectory.GenerateTo(exportDirectory, solutionName, copyrightData, projectCapitalName, projectName,newCoreName,coreCapital);
}

// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:37)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateSolutionImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
const System::String AssistTools::GenerateTemplateSolutionImpl
	::sm_Extension(SYSTEM_TEXT(".sln"));
 #include STSTEM_WARNING_POP
AssistTools::GenerateTemplateSolutionImpl
	::GenerateTemplateSolutionImpl(const System::String& templateFileName, const System::String& solutionName, const System::String& coreName)
	:ParentType(templateFileName, sm_Extension), m_SolutionName(solutionName), m_CoreName(coreName)
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

 
 
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools,GenerateTemplateSolutionImpl) 

void AssistTools::GenerateTemplateSolutionImpl
	::GenerateTo(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newCoreName) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

	VariableType newVariable;
	newVariable.insert(make_pair(m_SolutionName, newSolutionName));
	newVariable.insert(make_pair(m_CoreName, newCoreName)); 

	return ParentType::Generate (resourceDirectory, newSolutionName, newVariable);
}

/*
 æ¿˝ƒ£∞Â£∫

Microsoft Visual Studio Solution File, Format Version 11.00
# Visual Studio 2010
Project("{8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942}") = "%ProjectName%", "%ProjectName%\%ProjectName%.vcxproj", "{53AA2778-5CF8-4BEC-BB96-75BD12D8E678}"
	ProjectSection(ProjectDependencies) = postProject
		{B0397A08-C329-4EAB-8326-14B76AB1BC82} = {B0397A08-C329-4EAB-8326-14B76AB1BC82}
	EndProjectSection
EndProject
Project("{8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942}") = "%ProjectName%MiddleLayer", "%ProjectName%MiddleLayer\%ProjectName%MiddleLayer.vcxproj", "{B0397A08-C329-4EAB-8326-14B76AB1BC82}"
	ProjectSection(ProjectDependencies) = postProject
		{E4E3B6D7-D870-4FF1-977C-A1062AB3F55E} = {E4E3B6D7-D870-4FF1-977C-A1062AB3F55E}
	EndProjectSection
EndProject
Project("{8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942}") = "%ProjectName%%ToolsName%", "%ProjectName%%ToolsName%\%ProjectName%%ToolsName%.vcxproj", "{E4E3B6D7-D870-4FF1-977C-A1062AB3F55E}"
EndProject
Global
	GlobalSection(SolutionConfigurationPlatforms) = preSolution
		Debug|Win32 = Debug|Win32
		Release|Win32 = Release|Win32
	EndGlobalSection
	GlobalSection(ProjectConfigurationPlatforms) = postSolution
		{53AA2778-5CF8-4BEC-BB96-75BD12D8E678}.Debug|Win32.ActiveCfg = Debug|Win32
		{53AA2778-5CF8-4BEC-BB96-75BD12D8E678}.Debug|Win32.Build.0 = Debug|Win32
		{53AA2778-5CF8-4BEC-BB96-75BD12D8E678}.Release|Win32.ActiveCfg = Release|Win32
		{53AA2778-5CF8-4BEC-BB96-75BD12D8E678}.Release|Win32.Build.0 = Release|Win32
		{B0397A08-C329-4EAB-8326-14B76AB1BC82}.Debug|Win32.ActiveCfg = Debug|Win32
		{B0397A08-C329-4EAB-8326-14B76AB1BC82}.Debug|Win32.Build.0 = Debug|Win32
		{B0397A08-C329-4EAB-8326-14B76AB1BC82}.Release|Win32.ActiveCfg = Release|Win32
		{B0397A08-C329-4EAB-8326-14B76AB1BC82}.Release|Win32.Build.0 = Release|Win32
		{E4E3B6D7-D870-4FF1-977C-A1062AB3F55E}.Debug|Win32.ActiveCfg = Debug|Win32
		{E4E3B6D7-D870-4FF1-977C-A1062AB3F55E}.Debug|Win32.Build.0 = Debug|Win32
		{E4E3B6D7-D870-4FF1-977C-A1062AB3F55E}.Release|Win32.ActiveCfg = Release|Win32
		{E4E3B6D7-D870-4FF1-977C-A1062AB3F55E}.Release|Win32.Build.0 = Release|Win32
	EndGlobalSection
	GlobalSection(SolutionProperties) = preSolution
		HideSolutionNode = FALSE
	EndGlobalSection
EndGlobal

*/
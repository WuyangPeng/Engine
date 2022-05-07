///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/29 13:40)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTestingTemplateSolutionImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

using namespace std::literals;

const System::String AssistTools::GenerateTestingTemplateSolutionImpl::extension{ SYSTEM_TEXT(".sln"s) };

AssistTools::GenerateTestingTemplateSolutionImpl::GenerateTestingTemplateSolutionImpl(const System::String& templateFileName, const System::String& solutionName, const System::String& coreName)
    : ParentType{ templateFileName, extension }, solutionName{ solutionName }, coreName{ coreName }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTestingTemplateSolutionImpl)

void AssistTools::GenerateTestingTemplateSolutionImpl::GenerateTo(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newCoreName) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

    VariableType newVariable{ { solutionName, newSolutionName }, { coreName, newCoreName } };

    return ParentType::Generate(resourceDirectory, newSolutionName + GetTesting(), newVariable);
}

/*
示例模板：
Microsoft Visual Studio Solution File, Format Version 11.00
# Visual Studio 2010
Project("{8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942}") = "%ProjectName%Testing", "%ProjectName%Testing\%ProjectName%Testing.vcxproj", "{53AA2778-5CF8-4BEC-BB96-75BD12D8E678}"
EndProject
Project("{8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942}") = "%ProjectName%MiddleLayerTesting", "%ProjectName%MiddleLayerTesting\%ProjectName%MiddleLayerTesting.vcxproj", "{00FE0B10-07FB-4AE8-A458-F33F60FD191D}"
EndProject
Project("{8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942}") = "%ProjectName%%ToolsName%Testing", "%ProjectName%%ToolsName%Testing\%ProjectName%%ToolsName%Testing.vcxproj", "{E4E3B6D7-D870-4FF1-977C-A1062AB3F55E}"
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
		{00FE0B10-07FB-4AE8-A458-F33F60FD191D}.Debug|Win32.ActiveCfg = Debug|Win32
		{00FE0B10-07FB-4AE8-A458-F33F60FD191D}.Debug|Win32.Build.0 = Debug|Win32
		{00FE0B10-07FB-4AE8-A458-F33F60FD191D}.Release|Win32.ActiveCfg = Release|Win32
		{00FE0B10-07FB-4AE8-A458-F33F60FD191D}.Release|Win32.Build.0 = Release|Win32		
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
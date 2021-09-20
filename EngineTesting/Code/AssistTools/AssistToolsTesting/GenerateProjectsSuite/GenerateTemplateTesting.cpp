// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 11:00)

#include "GenerateTemplateTesting.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "System/FileManager/FileTools.h"

#include <boost/algorithm/string/find.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/assign/std/map.hpp>
#include <boost/assign/list_inserter.hpp> 

using std::string;
 
AssistTools::GenerateTemplateTesting
	::GenerateTemplateTesting(const CoreTools::OStreamShared& osPtr)
		:ParentType(osPtr),m_GenerateTemplateTesting("Configuration/StringReplacing.json")
{ 
	SELF_CLASS_IS_VALID_0; 
}            

 
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateTesting)
 
int AssistTools::GenerateTemplateTesting
	::GetContentFindCount(const System::String& templateFileName, const System::String& findContent)
{
	CoreTools::IFStreamManager manager(templateFileName);

	System::String content = manager.GetFileContent();  

	boost::iterator_range<System::String::const_iterator> iter = boost::find_first(content, findContent);
	int count = 0;

	while (iter.begin() != content.end())
	{
		++count;

		content = content.substr(iter.end() - content.begin());

		iter = boost::find_first(content, findContent);
	}
	
	return count;
} 

void AssistTools::GenerateTemplateTesting
	::ContentCountTest(const System::String& templateFileName, const System::String& findContent,int testCount, const std::string& functionName, int index)
{
	CoreTools::IFStreamManager manager(templateFileName);

	System::String content = manager.GetFileContent();

	boost::iterator_range<System::String::const_iterator> iter = boost::find_first(content, findContent);
	int count = 0;

	while (iter.begin() != content.end())
	{
		++count;

		content = content.substr(iter.end() - content.begin());

		iter = boost::find_first(content, findContent);
	}

	string message = "∫Ø ˝√˚Œ™£∫" + functionName + "£¨–Ú∫≈£∫" + boost::lexical_cast<string>(index);

	ASSERT_EQUAL_USE_MESSAGE(count, testCount, message);
}

const System::String AssistTools::GenerateTemplateTesting
	::GetResourceDirectory()
{
	return SYSTEM_TEXT("Resource/GenerateProjectsSuite");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetSolutionName()
{
	return SYSTEM_TEXT("Example");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetForwardSlash()
{
	return SYSTEM_TEXT("/");
}

const AssistTools::GenerateTemplateTesting::Replace AssistTools::GenerateTemplateTesting
	::GetSpecialReplace()
{
	Replace replace;
	boost::assign::insert(replace)
		(GenerateTemplateReplace::EndYear, GetSpecialEndYear())
		(GenerateTemplateReplace::ProjectChineseName, GetSpecialProjectChineseName())
		(GenerateTemplateReplace::Versions, GetSpecialVersions())
		(GenerateTemplateReplace::Date, GetSpecialDate())
		(GenerateTemplateReplace::Hour, GetSpecialHour())
		(GenerateTemplateReplace::Minute, GetSpecialMinute())
		(GenerateTemplateReplace::ProjectCapital, GetSpecialProjectCapital())
		(GenerateTemplateReplace::SolutionName, GetSpecialSolutionName())
		(GenerateTemplateReplace::ProjectName, GetSpecialProjectName())
		(GenerateTemplateReplace::ManagerCapital, GetSpecialManagerCapital())
		(GenerateTemplateReplace::ManagerName, GetSpecialManagerName())
		(GenerateTemplateReplace::ManagerChineseName, GetSpecialManagerChineseName())
		(GenerateTemplateReplace::InterfaceName, GetSpecialInterfaceName());

	return replace;
}

const System::String AssistTools::GenerateTemplateTesting
	::GetSpecialEndYear()
{
	return SYSTEM_TEXT("EndYearSpecial");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetSpecialProjectChineseName()
{
	return SYSTEM_TEXT("ProjectChineseNameSpecial");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetSpecialVersions()
{
	return SYSTEM_TEXT("VersionsSpecial");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetSpecialDate()
{
	return SYSTEM_TEXT("DateSpecial");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetSpecialHour()
{
	return SYSTEM_TEXT("HourSpecial");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetSpecialMinute()
{
	return SYSTEM_TEXT("MinuteSpecial");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetSpecialProjectCapital()
{
	return SYSTEM_TEXT("ProjectCapitalSpecial");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetSpecialSolutionName()
{
	return SYSTEM_TEXT("SolutionNameSpecial");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetSpecialProjectName()
{
	return SYSTEM_TEXT("ProjectNameSpecial");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetSpecialManagerCapital()
{
	return SYSTEM_TEXT("ManagerCapitalSpecial");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetSpecialManagerName()
{
	return SYSTEM_TEXT("ManagerNameSpecial");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetPercent()
{
	return SYSTEM_TEXT("%");
}

const AssistTools::CopyrightData AssistTools::GenerateTemplateTesting
	::GetCopyrightData() const
{
	return CopyrightData(GetEndYear(), GetVersions(), GetProjectChineseName());
}

const System::String AssistTools::GenerateTemplateTesting
	::GetVersions()
{
	return SYSTEM_TEXT("1.0.0.2");
}

int AssistTools::GenerateTemplateTesting
	::GetEndYear()
{
	return 2018;
}

const System::String AssistTools::GenerateTemplateTesting
	::GetProjectChineseName() const
{
	return m_GenerateTemplateTesting.GetReplacing(SYSTEM_TEXT("ProjectChineseName"));
}

const System::String AssistTools::GenerateTemplateTesting
	::GetProjectCapital()
{
	return SYSTEM_TEXT("EXAMPLE");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetDefaultEndYear()
{
	return SYSTEM_TEXT("EndYear");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetDefaultProjectChineseName()
{
	return SYSTEM_TEXT("ProjectChineseName");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetDefaultVersions()
{
	return SYSTEM_TEXT("Versions");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetDefaultDate()
{
	return SYSTEM_TEXT("Date");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetDefaultHour()
{
	return SYSTEM_TEXT("Hour");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetDefaultMinute()
{
	return SYSTEM_TEXT("Minute");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetDefaultProjectCapital()
{
	return SYSTEM_TEXT("ProjectCapital");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetDefaultSolutionName()
{
	return SYSTEM_TEXT("SolutionName");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetDefaultProjectName()
{
	return SYSTEM_TEXT("ProjectName");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetManagerChineseName() const
{
	return m_GenerateTemplateTesting.GetReplacing(SYSTEM_TEXT("ManagerChineseName"));
}

const System::String AssistTools::GenerateTemplateTesting
	::GetSpecialManagerChineseName()
{
	return SYSTEM_TEXT("ManagerChineseNameSpecial");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetDefaultManagerChineseName()
{
	return SYSTEM_TEXT("ManagerChineseName");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetSpecialInterfaceName()
{
	return SYSTEM_TEXT("InterfaceNameSpecial");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetSpecialCodeEngineDirectory()
{
	return SYSTEM_TEXT("SpecialCode");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetInputManagerName()
{
	return SYSTEM_TEXT("InputManager");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetCodeEngineDirectory()
{
	return SYSTEM_TEXT("Code");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetDefaultManagerName()
{
	return SYSTEM_TEXT("ManagerName");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetEngineDirectory()
{
	return SYSTEM_TEXT("Engine");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetEventManagerName()
{
	return SYSTEM_TEXT("EventManager");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetEventManagerCapitalName()
{
	return SYSTEM_TEXT("EVENT_MANAGER");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetEventManagerInterface()
{
	return SYSTEM_TEXT("EventManagerInterface");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetDefaultManagerCapital()
{
	return SYSTEM_TEXT("ManagerCapital");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetDefaultInterfaceName()
{
	return SYSTEM_TEXT("InterfaceName");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetInputManagerCapitalName()
{
	return SYSTEM_TEXT("INPUT_MANAGER");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetInputManagerInterface()
{
	return SYSTEM_TEXT("InputManagerInterface");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetUpdateName()
{
	return SYSTEM_TEXT("Update.txt");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetExportDirectory()
{
	return SYSTEM_TEXT("Export");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetTesting()
{
	return SYSTEM_TEXT("Testing");
}

const System::String AssistTools::GenerateTemplateTesting
	::GetMiddleLayerName()
{
	return SYSTEM_TEXT("MiddleLayer");
}

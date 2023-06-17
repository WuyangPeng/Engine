///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 10:54)

#include "GenerateTemplateTesting.h"
#include "System/FileManager/FileTools.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

AssistTools::GenerateTemplateTesting::GenerateTemplateTesting(const CoreTools::OStreamShared& stream)
    : ParentType(stream), generateTemplateTesting("Configuration/StringReplacing.json")
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateTesting)

int AssistTools::GenerateTemplateTesting::GetContentFindCount(const System::String& templateFileName, const System::String& findContent)
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

void AssistTools::GenerateTemplateTesting::ContentCountTest(const System::String& templateFileName, const System::String& findContent, int testCount, const std::string& functionName, int index)
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

    std::string message = "函数名为：" + functionName + "，序号：" + boost::lexical_cast<std::string>(index);

    ASSERT_EQUAL_USE_MESSAGE(count, testCount, message);
}

System::String AssistTools::GenerateTemplateTesting::GetResourceDirectory()
{
    return SYSTEM_TEXT("Resource/GenerateProjectsSuite");
}

System::String AssistTools::GenerateTemplateTesting::GetSolutionName()
{
    return SYSTEM_TEXT("Example");
}

System::String AssistTools::GenerateTemplateTesting::GetForwardSlash()
{
    return SYSTEM_TEXT("/");
}

AssistTools::GenerateTemplateTesting::Replace AssistTools::GenerateTemplateTesting::GetSpecialReplace()
{
    Replace replace{ { GenerateTemplateReplace::EndYear, GetSpecialEndYear() },
                     { GenerateTemplateReplace::ProjectChineseName, GetSpecialProjectChineseName() },
                     { GenerateTemplateReplace::Versions, GetSpecialVersions() },
                     { GenerateTemplateReplace::Date, GetSpecialDate() },
                     { GenerateTemplateReplace::Hour, GetSpecialHour() },
                     { GenerateTemplateReplace::Minute, GetSpecialMinute() },
                     { GenerateTemplateReplace::ProjectCapital, GetSpecialProjectCapital() },
                     { GenerateTemplateReplace::SolutionName, GetSpecialSolutionName() },
                     { GenerateTemplateReplace::ProjectName, GetSpecialProjectName() },
                     { GenerateTemplateReplace::ManagerCapital, GetSpecialManagerCapital() },
                     { GenerateTemplateReplace::ManagerName, GetSpecialManagerName() },
                     { GenerateTemplateReplace::ManagerChineseName, GetSpecialManagerChineseName() },
                     { GenerateTemplateReplace::InterfaceName, GetSpecialInterfaceName() } };

    return replace;
}

System::String AssistTools::GenerateTemplateTesting::GetSpecialEndYear()
{
    return SYSTEM_TEXT("EndYearSpecial");
}

System::String AssistTools::GenerateTemplateTesting::GetSpecialProjectChineseName()
{
    return SYSTEM_TEXT("ProjectChineseNameSpecial");
}

System::String AssistTools::GenerateTemplateTesting::GetSpecialVersions()
{
    return SYSTEM_TEXT("VersionsSpecial");
}

System::String AssistTools::GenerateTemplateTesting::GetSpecialDate()
{
    return SYSTEM_TEXT("DateSpecial");
}

System::String AssistTools::GenerateTemplateTesting::GetSpecialHour()
{
    return SYSTEM_TEXT("HourSpecial");
}

System::String AssistTools::GenerateTemplateTesting::GetSpecialMinute()
{
    return SYSTEM_TEXT("MinuteSpecial");
}

System::String AssistTools::GenerateTemplateTesting::GetSpecialProjectCapital()
{
    return SYSTEM_TEXT("ProjectCapitalSpecial");
}

System::String AssistTools::GenerateTemplateTesting::GetSpecialSolutionName()
{
    return SYSTEM_TEXT("SolutionNameSpecial");
}

System::String AssistTools::GenerateTemplateTesting::GetSpecialProjectName()
{
    return SYSTEM_TEXT("ProjectNameSpecial");
}

System::String AssistTools::GenerateTemplateTesting::GetSpecialManagerCapital()
{
    return SYSTEM_TEXT("ManagerCapitalSpecial");
}

System::String AssistTools::GenerateTemplateTesting::GetSpecialManagerName()
{
    return SYSTEM_TEXT("ManagerNameSpecial");
}

System::String AssistTools::GenerateTemplateTesting::GetPercent()
{
    return SYSTEM_TEXT("%");
}

AssistTools::CopyrightData AssistTools::GenerateTemplateTesting::GetCopyrightData() const
{
    return CopyrightData(GetEndYear(), GetVersions(), GetProjectChineseName());
}

System::String AssistTools::GenerateTemplateTesting::GetVersions()
{
    return SYSTEM_TEXT("1.0.0.2");
}

int AssistTools::GenerateTemplateTesting::GetEndYear() noexcept
{
    return 2018;
}

System::String AssistTools::GenerateTemplateTesting::GetProjectChineseName() const
{
    return generateTemplateTesting.GetReplacing(SYSTEM_TEXT("ProjectChineseName"));
}

System::String AssistTools::GenerateTemplateTesting::GetProjectCapital()
{
    return SYSTEM_TEXT("EXAMPLE");
}

System::String AssistTools::GenerateTemplateTesting::GetDefaultEndYear()
{
    return SYSTEM_TEXT("EndYear");
}

System::String AssistTools::GenerateTemplateTesting::GetDefaultProjectChineseName()
{
    return SYSTEM_TEXT("ProjectChineseName");
}

System::String AssistTools::GenerateTemplateTesting::GetDefaultVersions()
{
    return SYSTEM_TEXT("Versions");
}

System::String AssistTools::GenerateTemplateTesting::GetDefaultDate()
{
    return SYSTEM_TEXT("Date");
}

System::String AssistTools::GenerateTemplateTesting::GetDefaultHour()
{
    return SYSTEM_TEXT("Hour");
}

System::String AssistTools::GenerateTemplateTesting::GetDefaultMinute()
{
    return SYSTEM_TEXT("Minute");
}

System::String AssistTools::GenerateTemplateTesting::GetDefaultProjectCapital()
{
    return SYSTEM_TEXT("ProjectCapital");
}

System::String AssistTools::GenerateTemplateTesting::GetDefaultSolutionName()
{
    return SYSTEM_TEXT("SolutionName");
}

System::String AssistTools::GenerateTemplateTesting::GetDefaultProjectName()
{
    return SYSTEM_TEXT("ProjectName");
}

System::String AssistTools::GenerateTemplateTesting::GetManagerChineseName() const
{
    return generateTemplateTesting.GetReplacing(SYSTEM_TEXT("ManagerChineseName"));
}

System::String AssistTools::GenerateTemplateTesting::GetSpecialManagerChineseName()
{
    return SYSTEM_TEXT("ManagerChineseNameSpecial");
}

System::String AssistTools::GenerateTemplateTesting::GetDefaultManagerChineseName()
{
    return SYSTEM_TEXT("ManagerChineseName");
}

System::String AssistTools::GenerateTemplateTesting::GetSpecialInterfaceName()
{
    return SYSTEM_TEXT("InterfaceNameSpecial");
}

System::String AssistTools::GenerateTemplateTesting::GetSpecialCodeEngineDirectory()
{
    return SYSTEM_TEXT("SpecialCode");
}

System::String AssistTools::GenerateTemplateTesting::GetInputManagerName()
{
    return SYSTEM_TEXT("InputManager");
}

System::String AssistTools::GenerateTemplateTesting::GetCodeEngineDirectory()
{
    return SYSTEM_TEXT("Code");
}

System::String AssistTools::GenerateTemplateTesting::GetDefaultManagerName()
{
    return SYSTEM_TEXT("ManagerName");
}

System::String AssistTools::GenerateTemplateTesting::GetEngineDirectory()
{
    return SYSTEM_TEXT("Engine");
}

System::String AssistTools::GenerateTemplateTesting::GetEventManagerName()
{
    return SYSTEM_TEXT("EventManager");
}

System::String AssistTools::GenerateTemplateTesting::GetEventManagerCapitalName()
{
    return SYSTEM_TEXT("EVENT_MANAGER");
}

System::String AssistTools::GenerateTemplateTesting::GetEventManagerInterface()
{
    return SYSTEM_TEXT("EventManagerInterface");
}

System::String AssistTools::GenerateTemplateTesting::GetDefaultManagerCapital()
{
    return SYSTEM_TEXT("ManagerCapital");
}

System::String AssistTools::GenerateTemplateTesting::GetDefaultInterfaceName()
{
    return SYSTEM_TEXT("InterfaceName");
}

System::String AssistTools::GenerateTemplateTesting::GetInputManagerCapitalName()
{
    return SYSTEM_TEXT("INPUT_MANAGER");
}

System::String AssistTools::GenerateTemplateTesting::GetInputManagerInterface()
{
    return SYSTEM_TEXT("InputManagerInterface");
}

System::String AssistTools::GenerateTemplateTesting::GetUpdateName()
{
    return SYSTEM_TEXT("Update.txt");
}

System::String AssistTools::GenerateTemplateTesting::GetExportDirectory()
{
    return SYSTEM_TEXT("Export");
}

System::String AssistTools::GenerateTemplateTesting::GetTesting()
{
    return SYSTEM_TEXT("Testing");
}

System::String AssistTools::GenerateTemplateTesting::GetMiddleLayerName()
{
    return SYSTEM_TEXT("MiddleLayer");
}

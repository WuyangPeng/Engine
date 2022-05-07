///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/28 18:51)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateBaseImpl.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "System/Helper/PragmaWarning/PosixTime.h"
#include "System/Helper/PragmaWarning/Timer.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Time/CustomTime.h"
#include "AssistTools/GenerateProjects/CopyrightData.h"

using namespace std::literals;

const System::String AssistTools::GenerateTemplateBaseImpl::defaultEndYear{ SYSTEM_TEXT("EndYear"s) };
const System::String AssistTools::GenerateTemplateBaseImpl::defaultProjectChineseName{ SYSTEM_TEXT("ProjectChineseName"s) };
const System::String AssistTools::GenerateTemplateBaseImpl::defaultVersions{ SYSTEM_TEXT("Versions"s) };
const System::String AssistTools::GenerateTemplateBaseImpl::defaultDate{ SYSTEM_TEXT("Date"s) };
const System::String AssistTools::GenerateTemplateBaseImpl::defaultHour{ SYSTEM_TEXT("Hour"s) };
const System::String AssistTools::GenerateTemplateBaseImpl::defaultMinute{ SYSTEM_TEXT("Minute"s) };
const System::String AssistTools::GenerateTemplateBaseImpl::defaultProjectCapital{ SYSTEM_TEXT("ProjectCapital"s) };
const System::String AssistTools::GenerateTemplateBaseImpl::defaultSolutionName{ SYSTEM_TEXT("SolutionName"s) };
const System::String AssistTools::GenerateTemplateBaseImpl::defaultProjectName{ SYSTEM_TEXT("ProjectName"s) };
const System::String AssistTools::GenerateTemplateBaseImpl::defaultManagerCapital{ SYSTEM_TEXT("ManagerCapital"s) };
const System::String AssistTools::GenerateTemplateBaseImpl::defaultManagerName{ SYSTEM_TEXT("ManagerName"s) };
const System::String AssistTools::GenerateTemplateBaseImpl::defaultManagerChineseName{ SYSTEM_TEXT("ManagerChineseName"s) };
const System::String AssistTools::GenerateTemplateBaseImpl::defaultInterfaceName{ SYSTEM_TEXT("InterfaceName"s) };

AssistTools::GenerateTemplateBaseImpl::GenerateTemplateBaseImpl(const System::String& templateFileName, const System::String& extension, const Replace& replace)
    : ParentType{ templateFileName, extension }, replace{ replace }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateBaseImpl)

AssistTools::GenerateTemplateBaseImpl::VariableType AssistTools::GenerateTemplateBaseImpl::GetCopyrightVariable(const CopyrightData& copyrightData) const
{
    VariableType newVariable{};

    newVariable.emplace(GetOriginal(GenerateTemplateReplace::EndYear), boost::lexical_cast<System::String>(copyrightData.GetEndYear()));
    newVariable.emplace(GetOriginal(GenerateTemplateReplace::Versions), copyrightData.GetVersions());
    newVariable.emplace(GetOriginal(GenerateTemplateReplace::ProjectChineseName), copyrightData.GetProjectChineseName());

    System::String dateFormat{ SYSTEM_TEXT("%1%/%2%/%3%"s) };
    newVariable.emplace(GetOriginal(GenerateTemplateReplace::Date), CoreTools::CustomTime::GetSystemTimeDescribe(dateFormat));

    const auto nowTime = boost::posix_time::second_clock::local_time();
    const auto timeOfDay = nowTime.time_of_day();
    newVariable.emplace(GetOriginal(GenerateTemplateReplace::Hour), boost::lexical_cast<System::String>(timeOfDay.hours()));
    newVariable.emplace(GetOriginal(GenerateTemplateReplace::Minute), boost::lexical_cast<System::String>(timeOfDay.minutes()));

    return newVariable;
}

System::String AssistTools::GenerateTemplateBaseImpl::GetOriginal(GenerateTemplateReplace flag) const
{
    const auto iter = replace.find(flag);

    if (iter != replace.end())
    {
        return iter->second;
    }
    else
    {
        switch (flag)
        {
            case AssistTools::GenerateTemplateReplace::EndYear:
                return defaultEndYear;
            case AssistTools::GenerateTemplateReplace::ProjectChineseName:
                return defaultProjectChineseName;
            case AssistTools::GenerateTemplateReplace::Versions:
                return defaultVersions;
            case AssistTools::GenerateTemplateReplace::Date:
                return defaultDate;
            case AssistTools::GenerateTemplateReplace::Hour:
                return defaultHour;
            case AssistTools::GenerateTemplateReplace::Minute:
                return defaultMinute;
            case AssistTools::GenerateTemplateReplace::ProjectCapital:
                return defaultProjectCapital;
            case AssistTools::GenerateTemplateReplace::SolutionName:
                return defaultSolutionName;
            case AssistTools::GenerateTemplateReplace::ProjectName:
                return defaultProjectName;
            case AssistTools::GenerateTemplateReplace::ManagerCapital:
                return defaultManagerCapital;
            case AssistTools::GenerateTemplateReplace::ManagerName:
                return defaultManagerName;
            case AssistTools::GenerateTemplateReplace::ManagerChineseName:
                return defaultManagerChineseName;
            case AssistTools::GenerateTemplateReplace::InterfaceName:
                return defaultInterfaceName;
            default:
                THROW_EXCEPTION(SYSTEM_TEXT("错误的版权信息标识。"s));
        }
    }
}

/*
示例模板：
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%版本：%Versions% (%Date% %Hour%:%Minute%)
*/

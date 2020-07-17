// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:32)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateBaseImpl.h"
#include "AssistTools/GenerateProjects/CopyrightData.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Time/CustomTime.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

#include <boost/lexical_cast.hpp>
#include <boost/timer/timer.hpp>
#include "System/Helper/PragmaWarning/PosixTime.h" 

const System::String AssistTools::GenerateTemplateBaseImpl
	::sm_DefaultEndYear(SYSTEM_TEXT("EndYear"));	
const System::String AssistTools::GenerateTemplateBaseImpl
 	::sm_DefaultProjectChineseName(SYSTEM_TEXT("ProjectChineseName"));
const System::String AssistTools::GenerateTemplateBaseImpl
	::sm_DefaultVersions(SYSTEM_TEXT("Versions"));
const System::String AssistTools::GenerateTemplateBaseImpl
	::sm_DefaultDate(SYSTEM_TEXT("Date"));
const System::String AssistTools::GenerateTemplateBaseImpl
	::sm_DefaultHour(SYSTEM_TEXT("Hour"));	
const System::String AssistTools::GenerateTemplateBaseImpl
	::sm_DefaultMinute(SYSTEM_TEXT("Minute"));	
const System::String AssistTools::GenerateTemplateBaseImpl
	::sm_DefaultProjectCapital(SYSTEM_TEXT("ProjectCapital"));	
const System::String AssistTools::GenerateTemplateBaseImpl
	::sm_DefaultSolutionName(SYSTEM_TEXT("SolutionName"));	
const System::String AssistTools::GenerateTemplateBaseImpl
	::sm_DefaultProjectName(SYSTEM_TEXT("ProjectName"));	
const System::String AssistTools::GenerateTemplateBaseImpl
	::sm_DefaultManagerCapital(SYSTEM_TEXT("ManagerCapital"));	
const System::String AssistTools::GenerateTemplateBaseImpl
	::sm_DefaultManagerName(SYSTEM_TEXT("ManagerName"));
const System::String AssistTools::GenerateTemplateBaseImpl
	::sm_DefaultManagerChineseName(SYSTEM_TEXT("ManagerChineseName"));
const System::String AssistTools::GenerateTemplateBaseImpl
	::sm_DefaultInterfaceName(SYSTEM_TEXT("InterfaceName"));

AssistTools::GenerateTemplateBaseImpl
	::GenerateTemplateBaseImpl(const System::String& templateFileName, const System::String& extension, const Replace& replace)
	:ParentType(templateFileName, extension), m_Replace(replace)
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

AssistTools::GenerateTemplateBaseImpl
	::~GenerateTemplateBaseImpl()
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateBaseImpl)

const AssistTools::GenerateTemplateBaseImpl::VariableType AssistTools::GenerateTemplateBaseImpl
	::GetCopyrightVariable(const CopyrightData& copyrightData) const
{
	VariableType newVariable;

	newVariable.insert(make_pair(GetOriginal(GenerateTemplateReplace::EndYear), boost::lexical_cast<System::String>(copyrightData.GetEndYear())));
	newVariable.insert(make_pair(GetOriginal(GenerateTemplateReplace::Versions), copyrightData.GetVersions()));
	newVariable.insert(make_pair(GetOriginal(GenerateTemplateReplace::ProjectChineseName), copyrightData.GetProjectChineseName()));

	System::String dateFormat(SYSTEM_TEXT("%1%/%2%/%3%"));
	newVariable.insert(make_pair(GetOriginal(GenerateTemplateReplace::Date), CoreTools::CustomTime::GetSystemTimeDescribe(dateFormat)));

	boost::posix_time::ptime nowTime = boost::posix_time::second_clock::local_time();
	boost::posix_time::ptime::time_duration_type timeOfDay = nowTime.time_of_day();
	newVariable.insert(make_pair(GetOriginal(GenerateTemplateReplace::Hour), boost::lexical_cast<System::String>(timeOfDay.hours())));
	newVariable.insert(make_pair(GetOriginal(GenerateTemplateReplace::Minute), boost::lexical_cast<System::String>(timeOfDay.minutes())));

	return newVariable;
}

const System::String AssistTools::GenerateTemplateBaseImpl
	::GetOriginal(GenerateTemplateReplace flag) const
{
	ReplaceConstIter iter = m_Replace.find(flag);

	if (iter != m_Replace.end())
	{
		return iter->second;
	}		
	else
	{
		switch (flag)
		{
		case AssistTools::GenerateTemplateReplace::EndYear:
			return sm_DefaultEndYear;
		case AssistTools::GenerateTemplateReplace::ProjectChineseName:
			return sm_DefaultProjectChineseName;
		case AssistTools::GenerateTemplateReplace::Versions:
			return sm_DefaultVersions;
		case AssistTools::GenerateTemplateReplace::Date:
			return sm_DefaultDate;
		case AssistTools::GenerateTemplateReplace::Hour:
			return sm_DefaultHour;
		case AssistTools::GenerateTemplateReplace::Minute:
			return sm_DefaultMinute;
		case AssistTools::GenerateTemplateReplace::ProjectCapital:
			return sm_DefaultProjectCapital;
		case AssistTools::GenerateTemplateReplace::SolutionName:
			return sm_DefaultSolutionName;
		case AssistTools::GenerateTemplateReplace::ProjectName:
			return sm_DefaultProjectName;
		case AssistTools::GenerateTemplateReplace::ManagerCapital:
			return sm_DefaultManagerCapital;
		case AssistTools::GenerateTemplateReplace::ManagerName:
			return sm_DefaultManagerName;
		case AssistTools::GenerateTemplateReplace::ManagerChineseName:
			return sm_DefaultManagerChineseName;
		case AssistTools::GenerateTemplateReplace::InterfaceName:
			return sm_DefaultInterfaceName;
		default:
			THROW_EXCEPTION(SYSTEM_TEXT("¥ÌŒÛµƒ∞Ê»®–≈œ¢±Í ∂°£"));
		}
	}
}

/*
 æ¿˝ƒ£∞Â£∫
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)
*/


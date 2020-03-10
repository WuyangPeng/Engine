// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.2 (2020/01/22 11:54)

#include "CoreTools/CoreToolsExport.h"

#include "TestingInformation.h" 
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <utility>

using std::string;

CoreTools::TestingInformation
	::TestingInformation()
	:m_SuiteContainer{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, TestingInformation)

void CoreTools::TestingInformation
	::Insert(const string& suiteName, const string& testingName, int testLoopCount)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_SuiteContainer[suiteName].insert({ testingName, testLoopCount });
}

int CoreTools::TestingInformation
	::GetLoopCount(const string& suiteName, const string& testingName) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	auto iter = m_SuiteContainer.find(suiteName);

	if (iter != m_SuiteContainer.cend())
	{
		auto testingIter = iter->second.find(testingName);

		if (testingIter != iter->second.cend())
		{
			return testingIter->second;
		}
		else
		{
			THROW_EXCEPTION(SYSTEM_TEXT("²âÊÔÎ´ÅäÖÃ"));
		}
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("²âÊÔÌ×¼şÎ´ÅäÖÃ"));
	}
}


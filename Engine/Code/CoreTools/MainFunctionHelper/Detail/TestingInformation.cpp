//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/26 9:55)

#include "CoreTools/CoreToolsExport.h"

#include "TestingInformation.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <utility>

using std::string;

CoreTools::TestingInformation::TestingInformation() noexcept
    : m_SuiteContainer{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, TestingInformation)

void CoreTools::TestingInformation::Insert(const string& suiteName, const string& testingName, int testLoopCount)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_SuiteContainer[suiteName].insert({ testingName, testLoopCount });
}

int CoreTools::TestingInformation::GetLoopCount(const string& suiteName, const string& testingName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto iter = m_SuiteContainer.find(suiteName);

    if (iter != m_SuiteContainer.cend())
    {
        const auto testingIter = iter->second.find(testingName);

        if (testingIter != iter->second.cend())
        {
            return testingIter->second;
        }
        else
        {
            THROW_EXCEPTION(SYSTEM_TEXT("测试未配置"s));
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("测试套件未配置"s));
    }
}

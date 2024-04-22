/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 14:47)

#include "CoreTools/CoreToolsExport.h"

#include "TestingInformation.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::TestingInformation::TestingInformation() noexcept
    : suiteContainer{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, TestingInformation)

void CoreTools::TestingInformation::Insert(const std::string& suiteName, const std::string& testingName, int testLoopCount)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    suiteContainer[suiteName].emplace(testingName, testLoopCount);
}

int CoreTools::TestingInformation::GetLoopCount(const std::string& suiteName, const std::string& testingName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (const auto iter = suiteContainer.find(suiteName);
        iter != suiteContainer.cend())
    {
        if (const auto testingIter = iter->second.find(testingName);
            testingIter != iter->second.cend())
        {
            return testingIter->second;
        }
        else
        {
            THROW_EXCEPTION(SYSTEM_TEXT("测试未配置"s))
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("测试套件未配置"s))
    }
}

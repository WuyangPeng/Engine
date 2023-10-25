///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/21 09:39)

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

    suiteContainer[suiteName].insert({ testingName, testLoopCount });
}

int CoreTools::TestingInformation::GetLoopCount(const std::string& suiteName, const std::string& testingName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (const auto iter = suiteContainer.find(suiteName); iter != suiteContainer.cend())
    {
        if (const auto testingIter = iter->second.find(testingName); testingIter != iter->second.cend())
        {
            return testingIter->second;
        }
        else
        {
            THROW_EXCEPTION(SYSTEM_TEXT("����δ����"s))
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�����׼�δ����"s))
    }
}

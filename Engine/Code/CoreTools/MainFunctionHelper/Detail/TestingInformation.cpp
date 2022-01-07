///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/29 22:26)

#include "CoreTools/CoreToolsExport.h"

#include "TestingInformation.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::string;

CoreTools::TestingInformation::TestingInformation() noexcept
    : suiteContainer{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, TestingInformation)

void CoreTools::TestingInformation::Insert(const string& suiteName, const string& testingName, int testLoopCount)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    suiteContainer[suiteName].insert({ testingName, testLoopCount });
}

int CoreTools::TestingInformation::GetLoopCount(const string& suiteName, const string& testingName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto iter = suiteContainer.find(suiteName);

    if (iter != suiteContainer.cend())
    {
        const auto testingIter = iter->second.find(testingName);

        if (testingIter != iter->second.cend())
        {
            return testingIter->second;
        }
        else
        {
            THROW_EXCEPTION(SYSTEM_TEXT("����δ����"s));
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�����׼�δ����"s));
    }
}

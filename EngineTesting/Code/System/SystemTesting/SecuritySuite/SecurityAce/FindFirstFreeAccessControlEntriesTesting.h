///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/11/01 21:44)

#ifndef SYSTEM_SECURITY_SUITE_FIND_FIRST_FREE_ACCESS_CONTROL_ENTRIES_TESTING_H
#define SYSTEM_SECURITY_SUITE_FIND_FIRST_FREE_ACCESS_CONTROL_ENTRIES_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class FindFirstFreeAccessControlEntriesTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = FindFirstFreeAccessControlEntriesTesting;
        using ParentType = UnitTest;

    public:
        explicit FindFirstFreeAccessControlEntriesTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void FindFirstFreeAccessControlEntriesTest();
    };
}

#endif  // SYSTEM_SECURITY_SUITE_FIND_FIRST_FREE_ACCESS_CONTROL_ENTRIES_TESTING_H
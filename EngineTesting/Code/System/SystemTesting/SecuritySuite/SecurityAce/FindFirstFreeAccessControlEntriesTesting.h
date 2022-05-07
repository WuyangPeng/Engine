///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.4 (2021/06/02 15:19)

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
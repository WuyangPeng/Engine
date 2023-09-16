///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 13:46)

#ifndef SYSTEM_SECURITY_SUITE_FIND_FIRST_FREE_ACCESS_CONTROL_ENTRIES_TESTING_H
#define SYSTEM_SECURITY_SUITE_FIND_FIRST_FREE_ACCESS_CONTROL_ENTRIES_TESTING_H

#include "SecurityAceTestingBase.h"

namespace System
{
    class FindFirstFreeAccessControlEntriesTesting final : public SecurityAceTestingBase
    {
    public:
        using ClassType = FindFirstFreeAccessControlEntriesTesting;
        using ParentType = SecurityAceTestingBase;

    public:
        explicit FindFirstFreeAccessControlEntriesTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void FindFirstFreeAccessControlEntriesTest();
    };
}

#endif  // SYSTEM_SECURITY_SUITE_FIND_FIRST_FREE_ACCESS_CONTROL_ENTRIES_TESTING_H
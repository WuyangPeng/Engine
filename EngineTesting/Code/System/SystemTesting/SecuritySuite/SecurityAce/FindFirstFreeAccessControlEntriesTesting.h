/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 13:23)

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
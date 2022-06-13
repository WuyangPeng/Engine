///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/12 19:08)

#ifndef SYSTEM_SECURITY_SUITE_ADD_ACCESS_ALLOWED_ACE_TESTING_H
#define SYSTEM_SECURITY_SUITE_ADD_ACCESS_ALLOWED_ACE_TESTING_H

#include "System/Security/Fwd/SecurityFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class AddAccessAllowedAceTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AddAccessAllowedAceTesting;
        using ParentType = UnitTest;

    public:
        explicit AddAccessAllowedAceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void AddAccessAllowedAccessControlEntriesTest();

    private:
        using SpecificAccessFlagsCollection = std::vector<SpecificAccess>;

    private:
        SpecificAccessFlagsCollection specificAccessFlags;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ADD_ACCESS_ALLOWED_ACE_TESTING_H
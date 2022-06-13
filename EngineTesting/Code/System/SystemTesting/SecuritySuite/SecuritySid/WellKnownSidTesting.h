///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/12 19:12)

#ifndef SYSTEM_SECURITY_SUITE_WELL_KNOWN_SID_TESTING_H
#define SYSTEM_SECURITY_SUITE_WELL_KNOWN_SID_TESTING_H

#include "System/Security/Using/SecuritySidUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class WellKnownSidTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WellKnownSidTesting;
        using ParentType = UnitTest;

    public:
        explicit WellKnownSidTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CreateWellKnownSecurityIdentifierTest();

    private:
        using SecurityWellKnownSidTypeCollection = std::vector<SecurityWellKnownSidType>;

    private:
        SecurityWellKnownSidTypeCollection securityWellKnownSidType;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_WELL_KNOWN_SID_TESTING_H
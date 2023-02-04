///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/01/29 21:32)

#ifndef SYSTEM_SECURITY_SUITE_WELL_KNOWN_SID_TESTING_H
#define SYSTEM_SECURITY_SUITE_WELL_KNOWN_SID_TESTING_H

#include "System/Security/Using/SecuritySidUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <array>
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

        void DoCreateWellKnownSecurityIdentifierTest(SecurityWellKnownSidType securityWellKnownSidType);

    private:
        using SecurityWellKnownSidTypeContainer = std::vector<SecurityWellKnownSidType>;
        using BufferType = std::array<WindowsDWord, securityMaxSidSize>;

    private:
        SecurityWellKnownSidTypeContainer securityWellKnownSidTypes;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_WELL_KNOWN_SID_TESTING_H
/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:27)

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
        void DoRunUnitTest() override;
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
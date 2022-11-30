///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/11/01 21:42)

#ifndef SYSTEM_SECURITY_SUITE_RESTRICTED_TOKEN_TESTING_H
#define SYSTEM_SECURITY_SUITE_RESTRICTED_TOKEN_TESTING_H

#include "System/Security/Fwd/SecurityFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class RestrictedTokenTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = RestrictedTokenTesting;
        using ParentType = UnitTest;

    public:
        explicit RestrictedTokenTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CreateRestrictedTokenTest();

    private:
        using SpecifiesAdditionalPrivilegeOptionsFlagsContainer = std::vector<SpecifiesAdditionalPrivilegeOptions>;

    private:
        SpecifiesAdditionalPrivilegeOptionsFlagsContainer specifiesAdditionalPrivilegeOptionsFlags;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_RESTRICTED_TOKEN_TESTING_H
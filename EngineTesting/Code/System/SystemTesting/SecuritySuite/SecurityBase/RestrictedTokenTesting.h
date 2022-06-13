///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/12 19:11)

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
        using SpecifiesAdditionalPrivilegeOptionsFlagsCollection = std::vector<SpecifiesAdditionalPrivilegeOptions>;

    private:
        SpecifiesAdditionalPrivilegeOptionsFlagsCollection specifiesAdditionalPrivilegeOptionsFlags;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_RESTRICTED_TOKEN_TESTING_H
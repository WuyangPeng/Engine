///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.4 (2021/06/03 16:03)

#ifndef SYSTEM_SECURITY_SUITE_TOKEN_INFORMATION_TESTING_H
#define SYSTEM_SECURITY_SUITE_TOKEN_INFORMATION_TESTING_H

#include "System/Security/Using/SecurityBaseUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class TokenInformationTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = TokenInformationTesting;
        using ParentType = UnitTest;

    public:
        explicit TokenInformationTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void TokenInformationTest();

        template <TokenInformationClass TokenInformation, typename SecurityToken>
        void DoTokenInformationTest();

        void TokenImpersonationLevelTest();
    };
}

#endif  // SYSTEM_SECURITY_SUITE_TOKEN_INFORMATION_TESTING_H
///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/28 16:58)

#ifndef SYSTEM_SECURITY_SUITE_TOKEN_INFORMATION_TESTING_H
#define SYSTEM_SECURITY_SUITE_TOKEN_INFORMATION_TESTING_H

#include "SecurityBaseTestingBase.h"
#include "System/Security/Using/SecurityBaseUsing.h"

namespace System
{
    class TokenInformationTesting final : public SecurityBaseTestingBase
    {
    public:
        using ClassType = TokenInformationTesting;
        using ParentType = SecurityBaseTestingBase;

    public:
        explicit TokenInformationTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void TokenInformationTest();

        template <TokenInformationClass TokenInformation, typename SecurityToken>
        void DoTokenInformationTest();

        template <TokenInformationClass TokenInformation, typename SecurityToken>
        void GetTokenInformationTest(WindowsHandle tokenHandle);

        void TokenImpersonationLevelTest();
        void DoTokenImpersonationLevelTest(WindowsHandle tokenHandle);
        void GetTokenImpersonationLevelTest(WindowsHandle impersonatedToken);
        void LengthTest(WindowsDWord bufferLength, WindowsHandle impersonatedToken, TokenInformationClass tokenInformation);
    };
}

#endif  // SYSTEM_SECURITY_SUITE_TOKEN_INFORMATION_TESTING_H
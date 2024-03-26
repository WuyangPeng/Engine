/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 13:26)

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
        void DoRunUnitTest() override;
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
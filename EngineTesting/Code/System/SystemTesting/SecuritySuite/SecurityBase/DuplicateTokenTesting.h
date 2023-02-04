///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/01/29 11:34)

#ifndef SYSTEM_SECURITY_SUITE_DUPLICATE_TOKEN_TESTING_H
#define SYSTEM_SECURITY_SUITE_DUPLICATE_TOKEN_TESTING_H

#include "SecurityBaseTestingBase.h"
#include "System/Security/Using/SecurityBaseUsing.h"
#include "System/Threading/Fwd/ThreadingFlagsFwd.h"

#include <random>

namespace System
{
    class DuplicateTokenTesting final : public SecurityBaseTestingBase
    {
    public:
        using ClassType = DuplicateTokenTesting;
        using ParentType = SecurityBaseTestingBase;

    public:
        explicit DuplicateTokenTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void DuplicateTokenTest();

        void DoDuplicateTokenTest(WindowsHandle tokenHandle);
        void DuplicateTest(WindowsHandle tokenHandle, SecurityImpersonationLevel securityImpersonation);
        void WindowSecurityAttributesDuplicateTest(size_t index, WindowsHandle tokenHandle, SecurityImpersonationLevel securityImpersonation);

    private:
        using SecurityImpersonationLevelContainer = std::vector<SecurityImpersonationLevel>;
        using SecurityTokenTypeContainer = std::vector<SecurityTokenType>;
        using TokenStandardAccessContainer = std::vector<TokenStandardAccess>;
        using TokenSpecificAccessContainer = std::vector<TokenSpecificAccess>;

    private:
        SecurityImpersonationLevelContainer securityImpersonationLevels;
        SecurityTokenTypeContainer securityTokenTypes;
        TokenStandardAccessContainer tokenStandardAccesses;
        TokenSpecificAccessContainer tokenSpecificAccesses;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_DUPLICATE_TOKEN_TESTING_H
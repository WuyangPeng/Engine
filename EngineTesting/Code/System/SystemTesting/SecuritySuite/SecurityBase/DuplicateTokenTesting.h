/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 13:25)

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
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void DuplicateTokenTest();

        void DoDuplicateTokenTestLoop(WindowsHandle tokenHandle);
        void DoDuplicateTokenTest(WindowsHandle tokenHandle, size_t index);
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
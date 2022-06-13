///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/12 19:10)

#ifndef SYSTEM_SECURITY_SUITE_DUPLICATE_TOKEN_TESTING_H
#define SYSTEM_SECURITY_SUITE_DUPLICATE_TOKEN_TESTING_H

#include "System/Security/Using/SecurityBaseUsing.h"
#include "System/Threading/Fwd/ThreadingFlagsFwd.h"
#include "System/Threading/Using/ThreadToolsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class DuplicateTokenTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = DuplicateTokenTesting;
        using ParentType = UnitTest;

    public:
        explicit DuplicateTokenTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void DuplicateTokenTest();

    private:
        using SecurityImpersonationLevelCollection = std::vector<SecurityImpersonationLevel>;
        using SecurityTokenTypeCollection = std::vector<SecurityTokenType>;
        using TokenStandardAccessFlagsCollection = std::vector<TokenStandardAccess>;
        using TokenSpecificAccessFlagsCollection = std::vector<TokenSpecificAccess>;

    private:
        SecurityImpersonationLevelCollection securityImpersonationLevel;
        SecurityTokenTypeCollection securityTokenType;
        TokenStandardAccessFlagsCollection tokenStandardAccessFlags;
        TokenSpecificAccessFlagsCollection tokenSpecificAccessFlags;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_DUPLICATE_TOKEN_TESTING_H
///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/11/01 21:41)

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
        using SecurityImpersonationLevelContainer = std::vector<SecurityImpersonationLevel>;
        using SecurityTokenTypeContainer = std::vector<SecurityTokenType>;
        using TokenStandardAccessFlagsContainer = std::vector<TokenStandardAccess>;
        using TokenSpecificAccessFlagsContainer = std::vector<TokenSpecificAccess>;

    private:
        SecurityImpersonationLevelContainer securityImpersonationLevel;
        SecurityTokenTypeContainer securityTokenType;
        TokenStandardAccessFlagsContainer tokenStandardAccessFlags;
        TokenSpecificAccessFlagsContainer tokenSpecificAccessFlags;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_DUPLICATE_TOKEN_TESTING_H
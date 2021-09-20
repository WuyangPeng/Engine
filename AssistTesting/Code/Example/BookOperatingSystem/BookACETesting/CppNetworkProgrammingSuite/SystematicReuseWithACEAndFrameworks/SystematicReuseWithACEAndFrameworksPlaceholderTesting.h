///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.4 (2021/06/12 13:08)

#ifndef BOOK_ACE_SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_PLACEHOLDERTESTING_H
#define BOOK_ACE_SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_PLACEHOLDERTESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookACE
{
    namespace CppNetworkProgramming
    {
        class SystematicReuseWithACEAndFrameworksPlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = SystematicReuseWithACEAndFrameworksPlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit SystematicReuseWithACEAndFrameworksPlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_ACE_SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_PLACEHOLDERTESTING_H
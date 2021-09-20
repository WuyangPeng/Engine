///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/17 22:21)

#ifndef SYSTEM_CONSOLE_SUITE_CONSOLE_CODE_PAGE_TESTING_H
#define SYSTEM_CONSOLE_SUITE_CONSOLE_CODE_PAGE_TESTING_H

#include "System/CharacterString/Fwd/CharacterStringFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class ConsoleCodePageTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ConsoleCodePageTesting;
        using ParentType = UnitTest;

    public:
        explicit ConsoleCodePageTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CodePageTest();
        void OutputCodePageTest();

    private:
        using CodePageFlagsCollection = std::vector<CodePage>;

    private:
        CodePageFlagsCollection m_CodePageFlags;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CONSOLE_CODE_PAGE_TESTING_H
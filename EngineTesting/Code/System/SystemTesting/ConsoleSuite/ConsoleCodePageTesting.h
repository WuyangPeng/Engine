///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/03 11:07)

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
        void PrintTipsMessage() override;

    private:
        using CodePageContainer = std::vector<CodePage>;

    private:
        void ConsoleCodePageTest(CodePage codePage);
        void ConsoleOutputCodePageTest(CodePage codePage);

    private:
        CodePageContainer codePages;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CONSOLE_CODE_PAGE_TESTING_H
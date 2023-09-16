///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 15:46)

#ifndef SYSTEM_TESTING_CHARACTER_STRING_SUITE_CODE_PAGE_TESTING_H
#define SYSTEM_TESTING_CHARACTER_STRING_SUITE_CODE_PAGE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class CodePageTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CodePageTesting;
        using ParentType = UnitTest;

    public:
        explicit CodePageTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void AnsiCodePageTest();
        void OemCodePageTest();
    };
}

#endif  // SYSTEM_TESTING_CHARACTER_STRING_SUITE_CODE_PAGE_TESTING_H
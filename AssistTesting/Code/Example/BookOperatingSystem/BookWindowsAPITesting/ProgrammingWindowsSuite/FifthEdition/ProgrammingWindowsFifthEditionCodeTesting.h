///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.3 (2021/05/23 23:05)

#ifndef BOOK_WINDOWS_API_PROGRAMMING_WINDOWS_FIFTH_EDITION_CODE_TESTING_H
#define BOOK_WINDOWS_API_PROGRAMMING_WINDOWS_FIFTH_EDITION_CODE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookWindowsAPI
{
    class ProgrammingWindowsFifthEditionCodeTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ProgrammingWindowsFifthEditionCodeTesting;
        using ParentType = UnitTest;

    public:
        explicit ProgrammingWindowsFifthEditionCodeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();
    };
}

#endif  // BOOK_WINDOWS_API_PROGRAMMING_WINDOWS_FIFTH_EDITION_CODE_TESTING_H

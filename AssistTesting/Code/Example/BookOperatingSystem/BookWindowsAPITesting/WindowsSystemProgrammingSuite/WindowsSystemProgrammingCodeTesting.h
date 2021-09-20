///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.3 (2021/05/23 23:10)

#ifndef BOOK_WINDOWS_API_WINDOWS_SYSTEM_PROGRAMMING_CODE_TESTING_H
#define BOOK_WINDOWS_API_WINDOWS_SYSTEM_PROGRAMMING_CODE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookWindowsAPI
{
    class WindowsSystemProgrammingCodeTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowsSystemProgrammingCodeTesting;
        using ParentType = UnitTest;

    public:
        explicit WindowsSystemProgrammingCodeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();
    };
}

#endif  // BOOK_WINDOWS_API_WINDOWS_SYSTEM_PROGRAMMING_CODE_TESTING_H

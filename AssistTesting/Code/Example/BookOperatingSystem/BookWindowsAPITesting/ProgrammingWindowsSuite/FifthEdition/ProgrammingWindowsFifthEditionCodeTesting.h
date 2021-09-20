///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.3 (2021/05/23 23:05)

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

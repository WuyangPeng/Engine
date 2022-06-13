///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/15 0:53)

#ifndef SYSTEM_TESTING_HELPER_SUITE_UNICODE_MACRO_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_UNICODE_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class UnicodeUsingTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = UnicodeUsingTesting;
        using ParentType = UnitTest;

    public:
        explicit UnicodeUsingTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void StringStreamMacroTest();
        void FileStreamMacroTest();
        void ToStringTest();
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_UNICODE_MACRO_TESTING_H

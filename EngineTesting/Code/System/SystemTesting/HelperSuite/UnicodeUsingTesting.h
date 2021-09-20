///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.1 (2021/03/08 20:08)

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

///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.2 (2022/09/17 22:34)

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
        void NullCharTest();
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_UNICODE_MACRO_TESTING_H

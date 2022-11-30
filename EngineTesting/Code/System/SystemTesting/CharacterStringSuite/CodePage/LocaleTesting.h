///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/26 18:24)

#ifndef SYSTEM_TESTING_CHARACTER_STRING_SUITE_LOCALE_TESTING_H
#define SYSTEM_TESTING_CHARACTER_STRING_SUITE_LOCALE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <array>

namespace System
{
    class LocaleTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = LocaleTesting;
        using ParentType = UnitTest;

    public:
        explicit LocaleTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void LocaleTest();
    };
}

#endif  // SYSTEM_TESTING_CHARACTER_STRING_SUITE_LOCALE_TESTING_H
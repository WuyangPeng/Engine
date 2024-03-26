/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:02)

#ifndef SYSTEM_TESTING_CHARACTER_STRING_SUITE_LOCALE_TESTING_H
#define SYSTEM_TESTING_CHARACTER_STRING_SUITE_LOCALE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

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
        void DoRunUnitTest() override;
        void MainTest();

        void LocaleTest();
        void SetLocaleTest();
    };
}

#endif  // SYSTEM_TESTING_CHARACTER_STRING_SUITE_LOCALE_TESTING_H
/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 17:08)

#ifndef SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_LOOPER_TESTING_H
#define SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_LOOPER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class AndroidLooperTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AndroidLooperTesting;
        using ParentType = UnitTest;

    public:
        explicit AndroidLooperTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void AndroidLooperForThreadTest();
        void AndroidLooperPrepareTest();
        void AndroidLooperTest() const noexcept;
        void AndroidLooperPollTest();
        void AndroidLooperWakeTest() const noexcept;
        void AndroidLooperFileDescriptorTest();
    };
}

#endif  // SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_LOOPER_TESTING_H
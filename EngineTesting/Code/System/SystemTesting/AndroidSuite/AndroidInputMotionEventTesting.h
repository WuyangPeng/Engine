///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.6 (2021/07/11 20:34)

#ifndef SYSTEM_ANDROID_SUITE_ANDROID_INPUT_MOTION_EVENT_TESTING_H
#define SYSTEM_ANDROID_SUITE_ANDROID_INPUT_MOTION_EVENT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class AndroidInputMotionEventTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AndroidInputMotionEventTesting;
        using ParentType = UnitTest;

    public:
        explicit AndroidInputMotionEventTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest() noexcept;
    };
}

#endif  // SYSTEM_ANDROID_SUITE_ANDROID_INPUT_MOTION_EVENT_TESTING_H
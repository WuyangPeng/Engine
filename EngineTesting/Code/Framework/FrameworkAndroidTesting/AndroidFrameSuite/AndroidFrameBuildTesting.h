///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2022/06/24 14:03)

#ifndef FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_FRAME_BUILD_TESTING_H
#define FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_FRAME_BUILD_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class AndroidFrameBuildTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = AndroidFrameBuildTesting;
        using ParentType = UnitTest;

    public:
        explicit AndroidFrameBuildTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest() noexcept;

        void DoRunUnitTest() final;
    };
}

#endif  // FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_FRAME_BUILD_TESTING_H
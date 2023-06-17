///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2022/06/24 14:03)

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
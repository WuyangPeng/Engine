///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/24 14:02)

#ifndef FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_MESSAGE_LOOP_TESTING_H
#define FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_MESSAGE_LOOP_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
    class AndroidMessageLoopTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(AndroidMessageLoopTesting);

    private:
        void MainTest() noexcept;

        void DoRunUnitTest() final;
    };
}

#endif  // FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_MESSAGE_LOOP_TESTING_H

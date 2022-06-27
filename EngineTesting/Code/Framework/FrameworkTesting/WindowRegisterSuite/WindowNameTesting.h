///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/24 16:30)

#ifndef FRAMEWORK_WINDOW_REGISTER_SUITE_WINDOW_NAME_TESTING_H
#define FRAMEWORK_WINDOW_REGISTER_SUITE_WINDOW_NAME_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
    class WindowNameTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowNameTesting;
        using ParentType = UnitTest;

    public:
        explicit WindowNameTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void NameTest();
    };
}

#endif  // FRAMEWORK_WINDOW_REGISTER_SUITE_WINDOW_NAME_TESTING_H
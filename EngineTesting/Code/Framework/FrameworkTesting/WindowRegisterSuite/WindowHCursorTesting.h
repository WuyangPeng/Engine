///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 19:46)

#ifndef FRAMEWORK_WINDOW_REGISTER_SUITE_WINDOW_HCURSOR_TESTING_H
#define FRAMEWORK_WINDOW_REGISTER_SUITE_WINDOW_HCURSOR_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class WindowHCursorTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowHCursorTesting;
        using ParentType = UnitTest;

    public:
        explicit WindowHCursorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest() noexcept;
    };
}

#endif  //  FRAMEWORK_WINDOW_REGISTER_SUITE_WINDOW_HCURSOR_TESTING_H
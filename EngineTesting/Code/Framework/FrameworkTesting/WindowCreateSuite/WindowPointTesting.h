///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/24 17:01)

#ifndef FRAMEWORK_WINDOW_CREATE_SUITE_WINDOW_POINT_TESTING_H
#define FRAMEWORK_WINDOW_CREATE_SUITE_WINDOW_POINT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
    class WindowPointTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowPointTesting;
        using ParentType = UnitTest;

    public:
        explicit WindowPointTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void DefaultTest() noexcept;
        void RandomTest();
        void WindowPointUseTest() noexcept;
        void LParamTest();
        void EqualTest();
        void OstreamTest();
        void ConstexprTest() noexcept;
    };
}

#endif  // FRAMEWORK_WINDOW_CREATE_SUITE_WINDOW_POINT_TESTING_H
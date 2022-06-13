///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 18:49)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SUITE_TINY_TESTING_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SUITE_TINY_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class TinyTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(TinyTesting);

    private:
        void MainTest();
        void InitTest() noexcept;
        void PushBackTest() noexcept;
        void ClearTest() noexcept;
        void PushFrontTest() noexcept;
        void EmptyTest() noexcept;
        void InteratorTest() noexcept;
        void EraseTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_SUITE_TINY_TESTING_H

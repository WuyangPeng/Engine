/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 11:08)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SUITE_TINY_TESTING_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SUITE_TINY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class TinyTesting final : public UnitTest
    {
    public:
        using ClassType = TinyTesting;
        using ParentType = UnitTest;

    public:
        explicit TinyTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void InitTest();
        void PushBackTest() noexcept;
        void ClearTest() noexcept;
        void PushFrontTest() noexcept;
        void EmptyTest() noexcept;
        void IteratorTest();
        void EraseTest();

        void InitSizeTest() noexcept;
        void InitEmptyTest() noexcept;
        void InitFrontBackTest() noexcept;

        void Iterator0Test() noexcept;
        void Iterator1Test() noexcept;
        void Iterator2Test() noexcept;
        void Iterator3Test() noexcept;
        void Iterator4Test() noexcept;

        void Empty0Test() noexcept;
        void Empty1Test() noexcept;
        void Empty2Test() noexcept;
        void Empty3Test() noexcept;
        void Empty4Test() noexcept;
        void Empty5Test() noexcept;
        void Empty6Test() noexcept;
        void Empty7Test() noexcept;
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_SUITE_TINY_TESTING_H

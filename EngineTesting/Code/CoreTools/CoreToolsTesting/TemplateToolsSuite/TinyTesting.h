///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:33)

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
        void MainTest();
        void InitTest() noexcept;
        void PushBackTest() noexcept;
        void ClearTest() noexcept;
        void PushFrontTest() noexcept;
        void EmptyTest() noexcept;
        void IteratorTest() noexcept;
        void EraseTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_SUITE_TINY_TESTING_H

///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 18:49)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SUITE_TINY_TESTING_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SUITE_TINY_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class TinyTesting : public UnitTest
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
        void InteratorTest() noexcept;
        void EraseTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_SUITE_TINY_TESTING_H

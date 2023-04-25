///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/25 11:31)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SUITE_LITERAL_CAST_TESTING_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SUITE_LITERAL_CAST_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class LiteralCastTesting final : public UnitTest
    {
    public:
        using ClassType = LiteralCastTesting;
        using ParentType = UnitTest;

    public:
        explicit LiteralCastTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void CastTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_SUITE_LITERAL_CAST_TESTING_H

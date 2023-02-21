///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 18:47)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SUITE_LITERAL_CAST_TESTING_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SUITE_LITERAL_CAST_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class LiteralCastTesting : public UnitTest
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

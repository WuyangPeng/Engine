/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 11:08)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SUITE_VALUE_SCOPE_TESTING_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SUITE_VALUE_SCOPE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ValueScopeTesting final : public UnitTest
    {
    public:
        using ClassType = ValueScopeTesting;
        using ParentType = UnitTest;

    public:
        explicit ValueScopeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CastTest();
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_SUITE_VALUE_SCOPE_TESTING_H

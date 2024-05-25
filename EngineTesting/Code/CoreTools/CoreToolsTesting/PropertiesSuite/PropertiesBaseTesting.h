/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 12:54)

#ifndef CORE_TOOLS_PROPERTIES_SUITE_PROPERTIES_BASE_TESTING_H
#define CORE_TOOLS_PROPERTIES_SUITE_PROPERTIES_BASE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class PropertiesBaseTesting final : public UnitTest
    {
    public:
        using ClassType = PropertiesBaseTesting;
        using ParentType = UnitTest;

    public:
        explicit PropertiesBaseTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void GetSetTest();
    };
}

#endif  // CORE_TOOLS_PROPERTIES_SUITE_PROPERTIES_BASE_TESTING_H

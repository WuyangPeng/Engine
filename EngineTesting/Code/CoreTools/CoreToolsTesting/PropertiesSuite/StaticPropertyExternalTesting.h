/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 12:54)

#ifndef CORE_TOOLS_PROPERTIES_SUITE_STATIC_PROPERTY_EXTERNAL_TESTING_H
#define CORE_TOOLS_PROPERTIES_SUITE_STATIC_PROPERTY_EXTERNAL_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class StaticPropertyExternalTesting final : public UnitTest
    {
    public:
        using ClassType = StaticPropertyExternalTesting;
        using ParentType = UnitTest;

    public:
        explicit StaticPropertyExternalTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void GetSet0Test();
        void GetSet1Test();
        void GetSet2Test();
        void GetSet3Test();

    private:
        std::string setValue;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_SUITE_STATIC_PROPERTY_EXTERNAL_TESTING_H

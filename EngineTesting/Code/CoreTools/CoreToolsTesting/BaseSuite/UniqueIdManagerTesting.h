/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/15 14:34)

#ifndef CORE_TOOLS_BASE_SUITE_UNIQUE_ID_MANAGER_TESTING_H
#define CORE_TOOLS_BASE_SUITE_UNIQUE_ID_MANAGER_TESTING_H

#include "CoreTools/Base/Flags/UniqueIdSelect.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class UniqueIdManagerTesting final : public UnitTest
    {
    public:
        using ClassType = UniqueIdManagerTesting;
        using ParentType = UnitTest;

    public:
        explicit UniqueIdManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        static constexpr auto step = 100;
        static constexpr auto nextStep = 200;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void DefaultUniqueIdManagerTest();
        void UniqueIdManagerTest();
        void EnumUniqueIdManagerTest();
        void SetUniqueIdTest();
        void EnumSetUniqueIdTest();

        void DoUniqueIdManagerTest(int index);
        void DoEnumUniqueIdManagerTest(UniqueIdSelect index);
        void DoSetUniqueIdTest(int index);
        void DoEnumSetUniqueIdTest(UniqueIdSelect index);
    };
}

#endif  // CORE_TOOLS_BASE_SUITE_UNIQUE_ID_MANAGER_TESTING_H
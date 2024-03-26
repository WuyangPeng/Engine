/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/08 09:55)

#ifndef SYSTEM_TESTING_HELPER_SUITE_MAKE_INT_RESOURCE_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_MAKE_INT_RESOURCE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    /// @brief MakeIntResource�����Ĳ����׼���
    class MakeIntResourceTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MakeIntResourceTesting;
        using ParentType = UnitTest;

    public:
        explicit MakeIntResourceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void MakeIntResourceTest();
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_MAKE_INT_RESOURCE_TESTING_H

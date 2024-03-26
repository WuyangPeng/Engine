/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 17:18)

#ifndef SYSTEM_WINDOWS_SUITE_GET_LAST_SLASH_POSITION_TESTING_H
#define SYSTEM_WINDOWS_SUITE_GET_LAST_SLASH_POSITION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class GetLastSlashPositionTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GetLastSlashPositionTesting;
        using ParentType = UnitTest;

    public:
        explicit GetLastSlashPositionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void GetLastSlashPositionTest();
    };
}

#endif  // SYSTEM_WINDOWS_SUITE_GET_LAST_SLASH_POSITION_TESTING_H
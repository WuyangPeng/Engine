///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/11/01 21:56)

#ifndef SYSTEM_SECURITY_SUITE_ACCESS_CHECK_TESTING_H
#define SYSTEM_SECURITY_SUITE_ACCESS_CHECK_TESTING_H

#include "System/FileManager/Fwd/FileFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class AccessCheckTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AccessCheckTesting;
        using ParentType = UnitTest;

    public:
        explicit AccessCheckTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void AccessCheckTest();
        void AccessCheckByTypeTest();
        void AccessCheckByTypeResultListTest();

    private:
        using FileHandleDesiredAccessContainer = std::vector<FileHandleDesiredAccess>;

    private:
        FileHandleDesiredAccessContainer fileHandleDesiredAccess;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ACCESS_CHECK_TESTING_H
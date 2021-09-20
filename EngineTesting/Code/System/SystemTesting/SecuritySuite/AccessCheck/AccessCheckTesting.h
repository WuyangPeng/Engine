///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.4 (2021/06/04 14:27)

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
        using FileHandleDesiredAccessCollection = std::vector<FileHandleDesiredAccess>;

    private:
        FileHandleDesiredAccessCollection fileHandleDesiredAccess;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ACCESS_CHECK_TESTING_H
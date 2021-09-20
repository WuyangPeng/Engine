///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/05/24 14:30)

#ifndef SYSTEM_FILE_MANAGE_SUITE_CREATE_DIRECTORY_TESTING_H
#define SYSTEM_FILE_MANAGE_SUITE_CREATE_DIRECTORY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class CreateDirectoryTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CreateDirectoryTesting;
        using ParentType = UnitTest;

    public:
        explicit CreateDirectoryTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CreateDirectoryTest();
    };
}

#endif  // SYSTEM_FILE_MANAGE_SUITE_CREATE_DIRECTORY_TESTING_H
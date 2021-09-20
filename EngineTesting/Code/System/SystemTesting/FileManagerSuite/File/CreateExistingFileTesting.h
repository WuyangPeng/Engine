///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/05/20 16:43)

#ifndef SYSTEM_FILE_MANAGE_SUITE_CREATE_EXISTING_FILE_TESTING_H
#define SYSTEM_FILE_MANAGE_SUITE_CREATE_EXISTING_FILE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class CreateExistingFileTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CreateExistingFileTesting;
        using ParentType = UnitTest;

    public:
        explicit CreateExistingFileTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CreateExistingFileTest();
    };
}

#endif  // SYSTEM_FILE_MANAGE_SUITE_CREATE_EXISTING_FILE_TESTING_H
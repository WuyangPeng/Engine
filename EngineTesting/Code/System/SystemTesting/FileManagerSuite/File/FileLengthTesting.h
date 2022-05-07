///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/05/24 10:47)

#ifndef SYSTEM_FILE_MANAGE_SUITE_FILE_LENGTH_TESTING_H
#define SYSTEM_FILE_MANAGE_SUITE_FILE_LENGTH_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class FileLengthTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = FileLengthTesting;
        using ParentType = UnitTest;

    public:
        explicit FileLengthTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void FileLengthTest();
    };
}

#endif  // SYSTEM_FILE_MANAGE_SUITE_FILE_LENGTH_TESTING_H
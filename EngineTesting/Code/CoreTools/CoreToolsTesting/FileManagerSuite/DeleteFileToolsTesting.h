///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/24 19:13)

#ifndef CORE_TOOLS_TESTING_DELETE_FILE_TOOLS_TESTING_H
#define CORE_TOOLS_TESTING_DELETE_FILE_TOOLS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class DeleteFileToolsTesting final : public UnitTest
    {
    public:
        using ClassType = DeleteFileToolsTesting;
        using ParentType = UnitTest;

    public:
        explicit DeleteFileToolsTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void DeleteFileSucceedTest();
    };
}

#endif  // CORE_TOOLS_TESTING_DELETE_FILE_TOOLS_TESTING_H
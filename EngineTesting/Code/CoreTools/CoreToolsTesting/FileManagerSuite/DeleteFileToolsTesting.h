///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.3 (2021/09/06 16:40)

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
        void DoRunUnitTest() final;
        void MainTest();

        void DeleteFileSucceedTest();
    };
}

#endif  // CORE_TOOLS_TESTING_DELETE_FILE_TOOLS_TESTING_H
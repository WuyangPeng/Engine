///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.3 (2021/09/07 11:09)

#ifndef CORE_TOOLS_TESTING_FILE_HANDLE_MANAGER_TESTING_H
#define CORE_TOOLS_TESTING_FILE_HANDLE_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class FileHandleTesting final : public UnitTest
    {
    public:
        using ClassType = FileHandleTesting;
        using ParentType = UnitTest;
        using String = System::String;

    public:
        explicit FileHandleTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void InexistenceFileTest();
        void CannotOpenWriteFileHandleTest();
        void CannotOpenReadAndWriteFileHandleTest();

        NODISCARD static String GetFileHandleFileName();
    };
}

#endif  // CORE_TOOLS_TESTING_FILE_HANDLE_MANAGER_TESTING_H

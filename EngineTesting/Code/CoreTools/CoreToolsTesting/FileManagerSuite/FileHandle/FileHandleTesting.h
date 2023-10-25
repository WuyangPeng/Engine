///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/24 20:27)

#ifndef CORE_TOOLS_TESTING_FILE_HANDLE_MANAGER_TESTING_H
#define CORE_TOOLS_TESTING_FILE_HANDLE_MANAGER_TESTING_H

#include "System/Helper/UnicodeUsing.h"
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
        void DoRunUnitTest() override;
        void MainTest();

        void InExistenceFileTest();
        void CannotOpenWriteFileHandleTest();
        void CannotOpenReadAndWriteFileHandleTest();

        NODISCARD static String GetFileHandleFileName();
    };
}

#endif  // CORE_TOOLS_TESTING_FILE_HANDLE_MANAGER_TESTING_H

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/11 19:43)

#ifndef CORE_TOOLS_TESTING_WRITE_FILE_HANDLE_MANAGER_TESTING_H
#define CORE_TOOLS_TESTING_WRITE_FILE_HANDLE_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class WriteFileHandleTesting final : public UnitTest
    {
    public:
        using ClassType = WriteFileHandleTesting;
        using ParentType = UnitTest;
        using String = System::String;

    public:
        explicit WriteFileHandleTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void WriteFileHandleTest();
        void WriteResultTest();
        void GetFileByteSizeTest();

        NODISCARD static String GetFileHandleName();
        NODISCARD static std::string GetFileHandleContent();
    };
}

#endif  // CORE_TOOLS_TESTING_WRITE_FILE_HANDLE_MANAGER_TESTING_H

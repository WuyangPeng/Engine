///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.3 (2023/03/03 09:37)

#ifndef CORE_TOOLS_TESTING_WRITE_FILE_MANAGER_TESTING_H
#define CORE_TOOLS_TESTING_WRITE_FILE_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class WriteFileManagerTesting final : public UnitTest
    {
    public:
        using ClassType = WriteFileManagerTesting;
        using ParentType = UnitTest;
        using String = System::String;

    public:
        explicit WriteFileManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void WriteFileHandleTest();
        void WriteResultTest();
        void GetFileByteSizeTest();

        NODISCARD static String GetFileName();
        NODISCARD static std::string GetFileContent();
    };
}

#endif  // CORE_TOOLS_TESTING_WRITE_FILE_MANAGER_TESTING_H
///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.3 (2021/09/06 17:55)

#ifndef CORE_TOOLS_TESTING_READ_FILE_HANDLE_MANAGER_TESTING_H
#define CORE_TOOLS_TESTING_READ_FILE_HANDLE_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ReadFileHandleTesting final : public UnitTest
    {
    public:
        using ClassType = ReadFileHandleTesting;
        using ParentType = UnitTest;
        using String = System::String;

    public:
        explicit ReadFileHandleTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void WriteFileHandleTest();
        void ReadFileHandleTest();
        void GetFileByteSizeTest();

        NODISCARD static String GetFileHandleName();
        NODISCARD static std::string GetFileHandleContent();
    };
}

#endif  // CORE_TOOLS_TESTING_READ_FILE_HANDLE_MANAGER_TESTING_H
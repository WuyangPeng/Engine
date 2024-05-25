/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/16 16:51)

#ifndef CORE_TOOLS_TESTING_READ_FILE_HANDLE_MANAGER_TESTING_H
#define CORE_TOOLS_TESTING_READ_FILE_HANDLE_MANAGER_TESTING_H

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
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
        using BufferType = std::vector<char>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void WriteFileHandleTest();
        void ReadFileHandleTest();
        void GetFileByteSizeTest();

        NODISCARD static String GetFileHandleName();
        NODISCARD static std::string GetFileHandleContent();

        NODISCARD size_t GetSize(const std::string& content, ReadFileHandle& manager);
        void ReadResultTest(const std::string& content, ReadFileHandle& manager, size_t size);
    };
}

#endif  // CORE_TOOLS_TESTING_READ_FILE_HANDLE_MANAGER_TESTING_H

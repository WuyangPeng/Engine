/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 16:51)

#ifndef CORE_TOOLS_TESTING_READ_AND_WRITE_FILE_HANDLE_TESTING_H
#define CORE_TOOLS_TESTING_READ_AND_WRITE_FILE_HANDLE_TESTING_H

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ReadAndWriteFileHandleTesting final : public UnitTest
    {
    public:
        using ClassType = ReadAndWriteFileHandleTesting;
        using ParentType = UnitTest;

        using String = System::String;

    public:
        explicit ReadAndWriteFileHandleTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using BufferType = std::vector<char>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ClearFile();
        void WriteFileHandleTest();

        void ReadFileHandleTest();
        void GetFileByteSizeTest();

        NODISCARD static String GetFileHandleName();
        NODISCARD static std::string GetFileHandleContent();

        NODISCARD size_t GetSize(const std::string& content, ReadAndWriteFileHandle& manager);
        void ReadResultTest(const std::string& content, ReadAndWriteFileHandle& manager, size_t size);
    };
}

#endif  // CORE_TOOLS_TESTING_READ_AND_WRITE_FILE_HANDLE_TESTING_H

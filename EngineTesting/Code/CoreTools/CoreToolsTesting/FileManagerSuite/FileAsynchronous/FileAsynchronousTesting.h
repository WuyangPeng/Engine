/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 16:47)

#ifndef CORE_TOOLS_TESTING_FILE_ASYNCHRONOUS_TESTING_H
#define CORE_TOOLS_TESTING_FILE_ASYNCHRONOUS_TESTING_H

#include "CoreTools/FileManager/FileEventInterface.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <mutex>

namespace CoreTools
{
    class FileAsynchronousTesting final : public UnitTest, public FileEventInterface
    {
    public:
        using ClassType = FileAsynchronousTesting;
        using ParentType = UnitTest;

        using String = System::String;

    public:
        explicit FileAsynchronousTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using BufferType = std::vector<char>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ClearFile();

        void RegisteredWriteFileTest();
        void RegisteredWriteFileByEventTest();
        void RegisteredReadFileTest();

        NODISCARD static String GetFileName();
        NODISCARD static std::string GetContent();
        NODISCARD static size_t GetContentSize();
        NODISCARD static int GetBufferSize();

        void EventFunction(const FileAsynchronousParameter& fileAsynchronousParameter, const FileBuffer& fileBuffer) override;

        void ReadEventFunction(const FileAsynchronousParameter& fileAsynchronousParameter, const FileBuffer& fileBuffer);
        void WriteEventFunction(const FileAsynchronousParameter& fileAsynchronousParameter);

        NODISCARD static WriteBufferIO GetWriteBuffer(const std::string& content, size_t size, int bufferSize);
        NODISCARD static ConstFileBufferSharedPtr GetFileBuffer();

        NODISCARD size_t SizeTest(ReadBufferIO& readBuffer);
        void ReadBufferSize(ReadBufferIO& readBuffer, size_t size);
        void ResultTest(ReadBufferIO& readBuffer);

        NODISCARD size_t FileSizeTest(ReadFileManager& readFileManager);
        void ReadFileManagerSize(ReadFileManager& readFileManager, size_t size);
        void ReadFileResultTest(ReadFileManager& readFileManager);

    private:
        int callBackCount;
    };
}

#endif  // CORE_TOOLS_TESTING_FILE_ASYNCHRONOUS_TESTING_H
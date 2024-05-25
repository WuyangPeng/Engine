/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/28 21:52)

#ifndef CORE_TOOLS_TESTING_READ_BUFFER_IO_TESTING_H
#define CORE_TOOLS_TESTING_READ_BUFFER_IO_TESTING_H

#include "BufferIOTesting.h"
#include "CoreTools/FileManager/FileManagerFwd.h"

namespace CoreTools
{
    class ReadBufferIOTesting final : public BufferIOTesting
    {
    public:
        using ClassType = ReadBufferIOTesting;
        using ParentType = BufferIOTesting;

    public:
        explicit ReadBufferIOTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ReadBufferIOBasisTest();
        void ReadBufferIOReadTest();
        void GetTextTest();

        NODISCARD static WriteBufferIO GetWriteBufferIO(int bufferSize, size_t size, const std::string& content);
        NODISCARD static ReadBufferIO GetReadBufferIO(int bufferSize, size_t size, const std::string& content);
        void BytesTest(int bytesTotal, int bytesProcessed, const ReadBufferIO& readBuffer);
        void SizeTest(size_t size, ReadBufferIO& readBuffer);
        void ResultTest(const std::string& content, size_t size, ReadBufferIO& readBuffer);
        void DoGetTextTest(const std::string& content, size_t size, const ReadBufferIO& readBuffer);
    };
}

#endif  // CORE_TOOLS_TESTING_READ_BUFFER_IO_TESTING_H
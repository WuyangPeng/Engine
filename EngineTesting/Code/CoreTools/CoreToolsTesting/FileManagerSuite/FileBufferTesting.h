/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 16:03)

#ifndef CORE_TOOLS_TESTING_FILE_BUFFER_TESTING_H
#define CORE_TOOLS_TESTING_FILE_BUFFER_TESTING_H

#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class FileBufferTesting final : public UnitTest
    {
    public:
        using ClassType = FileBufferTesting;
        using ParentType = UnitTest;

    public:
        explicit FileBufferTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        static constexpr auto bufferSize = 10;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ValueTest();
        void DelayCopyTest();
        void BufferTest();
        void ForEachTest();
        void CopyBufferTest();

        void Init(FileBuffer& fileBuffer, int step) const;
        void GetBufferEqualTest(const FileBuffer& lhs, const FileBuffer& rhs);
        void InitByForEach(FileBuffer& fileBuffer);
        void CopyByForEachTest(const FileBuffer& fileBuffer);
        void DoCopyTest(const FileBuffer& fileBuffer);

        NODISCARD const char* ShallowCopyTest(const FileBuffer& lhs, const char* lhsPtr, const FileBuffer& rhs);
        void DeepCopyTest(const char* ptr0, const char* ptr1, FileBuffer& fileBuffer);
        void NoChangeTest(const FileBuffer& lhs, const FileBuffer& rhs);
    };
}

#endif  // CORE_TOOLS_TESTING_FILE_BUFFER_TESTING_H
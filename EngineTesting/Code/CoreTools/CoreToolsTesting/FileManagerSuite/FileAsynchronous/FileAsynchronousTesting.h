///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:56)

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
        void DoRunUnitTest() final;
        void MainTest();

        void ClearFile();
        void RegisteredWriteFileTest();
        void RegisteredWriteFileByEventTest();
        void RegisteredReadFileTest();

        NODISCARD String GetFileName();
        NODISCARD static std::string GetContent();

        void EventFunction(const FileAsynchronousParameter& fileAsynchronousParameter, const FileBuffer& fileBuffer) final;

        void ReadEventFunction(const FileAsynchronousParameter& fileAsynchronousParameter, const FileBuffer& fileBuffer);
        void WriteEventFunction(const FileAsynchronousParameter& fileAsynchronousParameter);

    private:
        int callBackCount;
    };
}

#endif  // CORE_TOOLS_TESTING_FILE_ASYNCHRONOUS_TESTING_H
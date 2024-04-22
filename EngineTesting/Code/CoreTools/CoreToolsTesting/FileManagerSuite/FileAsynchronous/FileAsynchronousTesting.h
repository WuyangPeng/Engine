/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/16 16:47)

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
        void DoRunUnitTest() override;
        void MainTest();

        void ClearFile();
        void RegisteredWriteFileTest();
        void RegisteredWriteFileByEventTest();
        void RegisteredReadFileTest();

        NODISCARD String GetFileName();
        NODISCARD static std::string GetContent();

        void EventFunction(const FileAsynchronousParameter& fileAsynchronousParameter, const FileBuffer& fileBuffer) override;

        void ReadEventFunction(const FileAsynchronousParameter& fileAsynchronousParameter, const FileBuffer& fileBuffer);
        void WriteEventFunction(const FileAsynchronousParameter& fileAsynchronousParameter);

    private:
        int callBackCount;
    };
}

#endif  // CORE_TOOLS_TESTING_FILE_ASYNCHRONOUS_TESTING_H
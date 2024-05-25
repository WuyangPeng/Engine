/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/22 16:51)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_FILE_IN_STREAM_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_FILE_IN_STREAM_TESTING_H

#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class FileInStreamTesting final : public UnitTest
    {
    public:
        using ClassType = FileInStreamTesting;
        using ParentType = UnitTest;

    public:
        explicit FileInStreamTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SaveFileOutStream() const;
        void FileStreamTest();
        void DeleteFileTest() const;

        void FileStreamResultTest(const InTopLevel& inTopLevel);
        void DoFileStreamResultTest(int index, const ObjectInterface& element);
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_FILE_IN_STREAM_TESTING_H
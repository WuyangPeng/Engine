/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/16 17:03)

#ifndef CORE_TOOLS_TESTING_READ_FILE_MANAGER_TESTING_H
#define CORE_TOOLS_TESTING_READ_FILE_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ReadFileManagerTesting final : public UnitTest
    {
    public:
        using ClassType = ReadFileManagerTesting;
        using ParentType = UnitTest;

        using String = System::String;

    public:
        explicit ReadFileManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void WriteFileManagerTest();
        void ReadFileManagerTest();
        void GetFileByteSizeTest();

        NODISCARD static String GetFileName();
        NODISCARD static std::string GetFileContent();
    };
}

#endif  // CORE_TOOLS_TESTING_READ_FILE_MANAGER_TESTING_H
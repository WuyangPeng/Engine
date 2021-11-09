///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.3 (2021/09/07 13:44)

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
        void DoRunUnitTest() final;
        void MainTest();

        void WriteFileManagerTest();
        void ReadFileManagerTest();
        void GetFileByteSizeTest();

        NODISCARD static String GetFileName();
        NODISCARD static std::string GetFileContent();
    };
}

#endif  // CORE_TOOLS_TESTING_READ_FILE_MANAGER_TESTING_H
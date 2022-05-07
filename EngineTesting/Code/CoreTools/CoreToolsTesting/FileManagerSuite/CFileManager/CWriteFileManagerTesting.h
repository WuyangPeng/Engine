///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.3 (2021/09/06 10:40)

#ifndef CORE_TOOLS_TESTING_C_WRITE_FILE_MANAGER_TESTING_H
#define CORE_TOOLS_TESTING_C_WRITE_FILE_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CWriteFileManagerTesting final : public UnitTest
    {
    public:
        using ClassType = CWriteFileManagerTesting;
        using ParentType = UnitTest;
        using String = System::String;

    public:
        explicit CWriteFileManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CWriteFileManagerTest();
        void WriteResultTest();
        void GetFileByteSizeTest();
        void PutTest();
        void PutWriteResultTest();
        void PositionTest();

        NODISCARD static String GetFileName();
        NODISCARD static std::string GetFileManagerContent();
    };
}

#endif  // CORE_TOOLS_TESTING_C_WRITE_FILE_MANAGER_TESTING_H
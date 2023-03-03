///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.3 (2023/03/03 09:07)

#ifndef CORE_TOOLS_TESTING_C_READ_FILE_MANAGER_TESTING_H
#define CORE_TOOLS_TESTING_C_READ_FILE_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CReadFileManagerTesting final : public UnitTest
    {
    public:
        using ClassType = CReadFileManagerTesting;
        using ParentType = UnitTest;
        using String = System::String;

    public:
        explicit CReadFileManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void WriteFileTest();
        void CReadFileManagerTest();
        void GetFileByteSizeTest();
        void GetCharacterTest();
        void PositionTest();

        NODISCARD static String GetFileName();
        NODISCARD static std::string GetFileManagerContent();
    };
}

#endif  // CORE_TOOLS_TESTING_C_READ_FILE_MANAGER_TESTING_H
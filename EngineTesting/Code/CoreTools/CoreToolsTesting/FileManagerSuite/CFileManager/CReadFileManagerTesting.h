/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 16:31)

#ifndef CORE_TOOLS_TESTING_C_READ_FILE_MANAGER_TESTING_H
#define CORE_TOOLS_TESTING_C_READ_FILE_MANAGER_TESTING_H

#include "CoreTools/FileManager/FileManagerFwd.h"
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

        NODISCARD size_t ReadSizeTest(CReadFileManager& manager);
        void ReadBufferTest(CReadFileManager& manager, size_t size);
        void DoGetCharacterTest(CReadFileManager& manager, size_t size);
        void DoPositionTest(CReadFileManager& manager);
        void MiscellaneousTest(CReadFileManager& manager);

    private:
        std::string fileManagerContent;
    };
}

#endif  // CORE_TOOLS_TESTING_C_READ_FILE_MANAGER_TESTING_H
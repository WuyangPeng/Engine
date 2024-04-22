/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 16:31)

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
        void DoRunUnitTest() override;
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
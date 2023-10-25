///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 20:27)

#ifndef CORE_TOOLS_TESTING_READ_AND_WRITE_FILE_HANDLE_TESTING_H
#define CORE_TOOLS_TESTING_READ_AND_WRITE_FILE_HANDLE_TESTING_H

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ReadAndWriteFileHandleTesting final : public UnitTest
    {
    public:
        using ClassType = ReadAndWriteFileHandleTesting;
        using ParentType = UnitTest;

        using String = System::String;

    public:
        explicit ReadAndWriteFileHandleTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ClearFile();
        void WriteFileHandleTest();
        void ReadFileHandleTest();
        void GetFileByteSizeTest();

        NODISCARD static String GetFileHandleName();
        NODISCARD static std::string GetFileHandleContent();
    };
}

#endif  // CORE_TOOLS_TESTING_READ_AND_WRITE_FILE_HANDLE_TESTING_H

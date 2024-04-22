/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 16:51)

#ifndef CORE_TOOLS_TESTING_WRITE_FILE_HANDLE_MANAGER_TESTING_H
#define CORE_TOOLS_TESTING_WRITE_FILE_HANDLE_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class WriteFileHandleTesting final : public UnitTest
    {
    public:
        using ClassType = WriteFileHandleTesting;
        using ParentType = UnitTest;

        using String = System::String;

    public:
        explicit WriteFileHandleTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void WriteFileHandleTest();
        void WriteResultTest();
        void GetFileByteSizeTest();

        NODISCARD static String GetFileHandleName();
        NODISCARD static std::string GetFileHandleContent();
    };
}

#endif  // CORE_TOOLS_TESTING_WRITE_FILE_HANDLE_MANAGER_TESTING_H

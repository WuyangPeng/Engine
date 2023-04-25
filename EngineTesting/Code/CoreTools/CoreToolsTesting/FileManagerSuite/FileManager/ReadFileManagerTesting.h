///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 19:43)

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
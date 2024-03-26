/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 11:17)

#ifndef SYSTEM_FILE_MANAGER_SUITE_FILE_LENGTH_TESTING_H
#define SYSTEM_FILE_MANAGER_SUITE_FILE_LENGTH_TESTING_H

#include "System/SystemTesting/FileManagerSuite/FileTestingBase.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    class FileLengthTesting final : public FileTestingBase
    {
    public:
        using ClassType = FileLengthTesting;
        using ParentType = FileTestingBase;

    public:
        explicit FileLengthTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CreateFileTest();
        void FileLengthTest();

        void WriteFileTest(WindowsHandle handle);
        void DoFileLengthTest(WindowsHandle handle);

    private:
        String fileName;
        std::string fileContent;
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_FILE_LENGTH_TESTING_H
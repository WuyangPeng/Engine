/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 17:03)

#ifndef CORE_TOOLS_TESTING_FILE_MANAGER_HELPER_TESTING_H
#define CORE_TOOLS_TESTING_FILE_MANAGER_HELPER_TESTING_H

#include "CoreTools/FileManager/Environment.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class FileManagerHelperTesting final : public UnitTest
    {
    public:
        using ClassType = FileManagerHelperTesting;
        using ParentType = UnitTest;

        using String = System::String;

    public:
        explicit FileManagerHelperTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void LoadFromFileTest(bool binaryFile);
        void LoadFromFileUseEnvironmentTest(bool binaryFile);
        void AppendToFileTest(bool binaryFile);
        void SaveIntoFileTest(bool binaryFile);
        void IsFileExistsTest();

        NODISCARD static String GetDirectory();
        NODISCARD static String GetFileName();
        NODISCARD static String GetFileManagerHelperName();
        NODISCARD static std::string GetFileManagerHelperContent();

        void ContentTest(const FileBuffer& buffer, const std::string& content);

    private:
        Environment environment;
    };
}

#endif  // CORE_TOOLS_TESTING_FILE_MANAGER_HELPER_TESTING_H
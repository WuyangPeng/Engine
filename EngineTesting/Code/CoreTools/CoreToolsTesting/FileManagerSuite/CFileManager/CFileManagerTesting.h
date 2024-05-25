/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/16 16:31)

#ifndef CORE_TOOLS_TESTING_C_FILE_MANAGER_TESTING_H
#define CORE_TOOLS_TESTING_C_FILE_MANAGER_TESTING_H

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/FileManager/Environment.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CFileManagerTesting final : public UnitTest
    {
    public:
        using ClassType = CFileManagerTesting;
        using ParentType = UnitTest;

        using String = System::String;

    public:
        explicit CFileManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CFileManagerHelperTest();

        void LoadFromFileTest(bool binaryFile);
        void LoadFromFileUseEnvironmentTest(bool binaryFile);
        void AppendToFileTest(bool binaryFile);
        void SaveIntoFileTest(bool binaryFile);

        NODISCARD static String GetDirectory();
        NODISCARD static String GetFileName();
        NODISCARD static String GetFileManagerHelperFileName();
        NODISCARD static std::string GetFileManagerContent();

        void ResultTest(const std::string& content, const FileBuffer& buffer);

    private:
        Environment environment;
    };
}

#endif  // CORE_TOOLS_TESTING_C_FILE_MANAGER_TESTING_H
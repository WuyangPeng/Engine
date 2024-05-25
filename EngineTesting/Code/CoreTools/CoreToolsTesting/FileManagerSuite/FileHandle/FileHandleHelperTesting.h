/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/16 16:51)

#ifndef CORE_TOOLS_TESTING_FILE_HANDLE_HELPER_MANAGER_TESTING_H
#define CORE_TOOLS_TESTING_FILE_HANDLE_HELPER_MANAGER_TESTING_H

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/FileManager/Environment.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class FileHandleHelperTesting final : public UnitTest
    {
    public:
        using ClassType = FileHandleHelperTesting;
        using ParentType = UnitTest;

        using String = System::String;

    public:
        explicit FileHandleHelperTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void LoadFromFileTest();
        void AppendToFileTest();
        void SaveIntoFileTest();
        void LoadFromFileUseEnvironmentTest();

        NODISCARD static String GetDirectory();
        NODISCARD static String GetFileName();
        NODISCARD static String GetFileHandleHelperName();
        NODISCARD static std::string GetFileHandleHelperContent();

        void ContentTest(const FileBuffer& buffer, const std::string& content);

    private:
        Environment environment;
    };
}

#endif  // CORE_TOOLS_TESTING_FILE_HANDLE_HELPER_MANAGER_TESTING_H

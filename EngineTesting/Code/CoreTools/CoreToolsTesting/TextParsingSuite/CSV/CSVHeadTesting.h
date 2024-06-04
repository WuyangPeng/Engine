/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 17:50)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_CSV_HEAD_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_CSV_HEAD_TESTING_H

#include "CoreTools/FileManager/IFileStreamManager.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace CoreTools
{
    class CSVHeadTesting final : public UnitTest
    {
    public:
        using ClassType = CSVHeadTesting;
        using ParentType = UnitTest;

    public:
        explicit CSVHeadTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using String = System::String;
        using FileContent = std::vector<String>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CreateCSV();

        NODISCARD FileContent ReadFile();
        NODISCARD FileContent ReadFile(const FileContent& content);

        void CSVHeadTest();
        void CSVHeadElementTest(const CSVHead& csvHead, int index);

        void CSVHeadBaseTest(const CSVHead& csvHead);
        void CSVHeadKeyTest(const CSVHead& csvHead);
        void CSVHeadArrayDataTypeTest(const CSVHead& csvHead);
        void HasBaseTest(const CSVHead& csvHead);

        void CSVHeadElementMappingTest(const CSVHead& csvHead, int index);
        void CSVHeadElementScopeTest(const CSVHead& csvHead, int index);
        void CSVHeadElementDefaultValueTest(const CSVHead& csvHead, int index);
        void CSVHeadElementAnnotationTest(const CSVHead& csvHead, int index);
        void CSVHeadElementActualTypeTest(const CSVHead& csvHead, int index);
        void CSVHeadElementVariableNameTest(const CSVHead& csvHead, int index);
        void CSVHeadElementGetFunctionNameTest(const CSVHead& csvHead, int index);
        void CSVHeadElementDataTest(const CSVHead& csvHead, int index);
        void CSVHeadElementAbbreviationTest(const CSVHead& csvHead, int index);

    private:
        String directory;
        String nameSpace;
        String csvClassName;
        String fileName;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_CSV_HEAD_TESTING_H

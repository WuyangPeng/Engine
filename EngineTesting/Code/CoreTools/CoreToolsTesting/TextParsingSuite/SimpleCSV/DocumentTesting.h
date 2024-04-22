/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/17 16:49)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_DOCUMENT_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_DOCUMENT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class DocumentTesting final : public UnitTest
    {
    public:
        using ClassType = DocumentTesting;
        using ParentType = UnitTest;

    public:
        explicit DocumentTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void WorkbookTest();
        void CreateTest();
        void RemoveFile();
        void PropertyTest();
        void ExecuteCommandTest();
        void ExecuteQueryTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_DOCUMENT_TESTING_H
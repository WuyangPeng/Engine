/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/17 17:05)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_SHEET_BASE_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_SHEET_BASE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    /// ������Բ�ֱ�Ӳ���SheetBase��
    /// ����ͨ��Document���ӵ���SheetBase����غ�����
    /// ֻ���Ի���SheetBase�ĺ�����
    class SheetBaseTesting final : public UnitTest
    {
    public:
        using ClassType = SheetBaseTesting;
        using ParentType = UnitTest;

    public:
        explicit SheetBaseTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SheetBaseTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_SHEET_BASE_TESTING_H
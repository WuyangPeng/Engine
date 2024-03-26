/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/11 18:23)

#ifndef SYSTEM_CONSOLE_SUITE_WRITE_ATTRIBUTE_TESTING_H
#define SYSTEM_CONSOLE_SUITE_WRITE_ATTRIBUTE_TESTING_H

#include "ConsoleAttributeTesting.h"

namespace System
{
    class WriteAttributeTesting final : public ConsoleAttributeTesting
    {
    public:
        using ClassType = WriteAttributeTesting;
        using ParentType = ConsoleAttributeTesting;

    public:
        explicit WriteAttributeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void WriteAttributeTest();
        void DoWriteAttributeTest(StandardHandle standardHandle);
        void ReadAttributeTest(const AttributeType& readAttribute, const AttributeType& writeAttribute);
        void DoReadAttributeTest(WindowsWord readAttribute, WindowsWord writeAttribute);
        NODISCARD AttributeType GetWriteAttribute() const;

        void PrintTipsMessage() override;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_WRITE_ATTRIBUTE_TESTING_H
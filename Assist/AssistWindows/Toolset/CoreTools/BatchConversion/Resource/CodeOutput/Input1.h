/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef CSV_OUTPUT_INPUT1_H
#define CSV_OUTPUT_INPUT1_H

#include "CoreTools/CoreToolsDll.h"

#include "CsvOutputFwd.h"
#include "Input1Base.h"
#include "System/Helper/UnicodeUsing.h"

namespace CsvOutput
{
    class Input1 final : public Input1Base
    {
    public:
        using ClassType = Input1;
        using ParentType = Input1Base;

    public:
        explicit Input1(const CoreTools::CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD bool IsTest0() const noexcept override;

        NODISCARD System::TChar GetTest1() const noexcept override;

        NODISCARD double GetTest2() const noexcept override;

        NODISCARD int GetTest4() const noexcept override;

        NODISCARD System::String GetTest5() const override;

        NODISCARD std::vector<System::String> GetTest6() const override;
        NODISCARD int GetTest6Count() const override;
        NODISCARD System::String GetTest6(int index) const override;
        NODISCARD std::vector<System::String>::const_iterator GetTest6Begin() const noexcept override;
        NODISCARD std::vector<System::String>::const_iterator GetTest6End() const noexcept override;

    private:
        int id;  // id
        bool test0;  // ����0
        System::TChar test1;  // ����1
        double test2;  // ����2
        int test4;  // ����4
        System::String test5;  // ����5
        std::vector<System::String> test6;  // ����6
    };
}

#endif  // CSV_OUTPUT_INPUT1_H

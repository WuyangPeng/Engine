/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef CSV_OUTPUT_INPUT3_H
#define CSV_OUTPUT_INPUT3_H

#include "CoreTools/CoreToolsDll.h"

#include "CsvOutputFwd.h"
#include "Input3Base.h"
#include "System/Helper/UnicodeUsing.h"

namespace CsvOutput
{
    class Input3 final : public Input3Base
    {
    public:
        using ClassType = Input3;
        using ParentType = Input3Base;

        using CSVRow = CoreTools::CSVRow; 

    public:
        explicit Input3(const CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD bool IsTest0() const noexcept override;

        NODISCARD Char GetTest1() const noexcept override;

        NODISCARD double GetTest2() const noexcept override;

        NODISCARD int GetTest4() const noexcept override;

        NODISCARD String GetTest5() const override;

    private:
        int id;  // id
        bool test0;  // ����0
        Char test1;  // ����1
        double test2;  // ����2
        int test4;  // ����4
        String test5;  // ����5
    };
}

#endif  // CSV_OUTPUT_INPUT3_H
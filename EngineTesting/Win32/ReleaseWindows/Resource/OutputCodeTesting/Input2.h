/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef OUTPUT_C_S_V_TESTING_INPUT2_H
#define OUTPUT_C_S_V_TESTING_INPUT2_H

#include "CoreTools/CoreToolsDll.h"

#include "OutputCSVTestingFwd.h"
#include "Input2Base.h"
#include "System/Helper/UnicodeUsing.h"

namespace OutputCSVTesting
{
    class Input2 final : public Input2Base
    {
    public:
        using ClassType = Input2;
        using ParentType = Input2Base;

        using CSVRow = CoreTools::CSVRow;

    public:
        explicit Input2(const CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD bool IsTest0() const noexcept override;

        NODISCARD System::TChar GetTest1() const noexcept override;

        NODISCARD double GetTest2() const noexcept override;

        NODISCARD int GetTest4() const noexcept override;

        NODISCARD String GetTest5() const override;

    private:
        int id;  // id
        bool test0;  // ����0
        System::TChar test1;  // ����1
        double test2;  // ����2
        int test4;  // ����4
        String test5;  // ����5
    };
}

#endif  // OUTPUT_C_S_V_TESTING_INPUT2_H

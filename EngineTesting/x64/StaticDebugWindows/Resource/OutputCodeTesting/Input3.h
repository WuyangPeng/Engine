/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef OUTPUT_C_S_V_TESTING_INPUT3_H
#define OUTPUT_C_S_V_TESTING_INPUT3_H

#include "CoreTools/CoreToolsDll.h"

#include "OutputCSVTestingFwd.h"
#include "Input3Base.h"
#include "System/Helper/UnicodeUsing.h"

namespace OutputCSVTesting
{
    class Input3 final : public Input3Base
    {
    public:
        using ClassType = Input3;
        using ParentType = Input3Base;

    public:
        explicit Input3(const CoreTools::CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD bool IsTest0() const noexcept override;

        NODISCARD System::TChar GetTest1() const noexcept override;

        NODISCARD double GetTest2() const noexcept override;

        NODISCARD int GetTest4() const noexcept override;

        NODISCARD System::String GetTest5() const override;

    private:
        int id;  // id
        bool test0;  // 测试0
        System::TChar test1;  // 测试1
        double test2;  // 测试2
        int test4;  // 测试4
        System::String test5;  // 测试5
    };
}

#endif  // OUTPUT_C_S_V_TESTING_INPUT3_H

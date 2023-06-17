/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef OUTPUT_C_S_V_TESTING_INPUT1_CONTAINER_H
#define OUTPUT_C_S_V_TESTING_INPUT1_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "OutputCSVTestingFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace OutputCSVTesting
{
    class Input1Container final
    {
    public:
        using ClassType = Input1Container;
        using ConstInput1BaseSharedPtr = std::shared_ptr<const Input1Base>;
        using Container = std::vector<ConstInput1BaseSharedPtr>;

    public:
        explicit Input1Container(const CoreTools::CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstInput1BaseSharedPtr GetFirstInput1() const;
        NODISCARD ConstInput1BaseSharedPtr GetInput1(int key) const;
        NODISCARD Container GetContainer() const;

        template <typename Function>
        NODISCARD ConstInput1BaseSharedPtr GetFirstInput1(Function function) const;

        template <typename Function>
        NODISCARD Container GetInput1(Function function) const;

    private:
        void Parsing(const CoreTools::CSVContent& csvContent);

    private:
        Container input1;
    };
}

#endif  // OUTPUT_C_S_V_TESTING_INPUT1_CONTAINER_H

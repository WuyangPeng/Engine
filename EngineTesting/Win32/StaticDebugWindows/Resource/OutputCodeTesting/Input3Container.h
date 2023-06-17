/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef OUTPUT_C_S_V_TESTING_INPUT3_CONTAINER_H
#define OUTPUT_C_S_V_TESTING_INPUT3_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "OutputCSVTestingFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace OutputCSVTesting
{
    class Input3Container final
    {
    public:
        using ClassType = Input3Container;
        using ConstInput3BaseSharedPtr = std::shared_ptr<const Input3Base>;
        using Container = std::vector<ConstInput3BaseSharedPtr>;

    public:
        explicit Input3Container(const CoreTools::CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstInput3BaseSharedPtr GetFirstInput3() const;
        NODISCARD ConstInput3BaseSharedPtr GetInput3(int key) const;
        NODISCARD Container GetContainer() const;

        template <typename Function>
        NODISCARD ConstInput3BaseSharedPtr GetFirstInput3(Function function) const;

        template <typename Function>
        NODISCARD Container GetInput3(Function function) const;

    private:
        void Parsing(const CoreTools::CSVContent& csvContent);

    private:
        Container input3;
    };
}

#endif  // OUTPUT_C_S_V_TESTING_INPUT3_CONTAINER_H

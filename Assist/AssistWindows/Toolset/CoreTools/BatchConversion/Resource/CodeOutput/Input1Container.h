/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef CSV_OUTPUT_INPUT1_CONTAINER_H
#define CSV_OUTPUT_INPUT1_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "CsvOutputFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace CsvOutput
{
    class Input1Container final
    {
    public:
        using ClassType = Input1Container;

        using ConstInput1SharedPtr = std::shared_ptr<const Input1MappingType>;
        using Container = std::vector<ConstInput1SharedPtr>;
        using CSVContent = CoreTools::CSVContent;

    public:
        explicit Input1Container(const CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstInput1SharedPtr GetFirstInput1() const;
        NODISCARD ConstInput1SharedPtr GetInput1(int key) const;
        NODISCARD Container GetContainer() const;

        NODISCARD int GetContainerSize() const;

        template <typename Function>
        NODISCARD ConstInput1SharedPtr GetFirstInput1(Function function) const;

        template <typename Function>
        NODISCARD Container GetInput1(Function function) const;

    private:
        void Parsing(const CSVContent& csvContent);
        void Load(const CSVContent& csvContent);
        void Unique();

    private:
        Container input1;
    };
}

#endif  // CSV_OUTPUT_INPUT1_CONTAINER_H
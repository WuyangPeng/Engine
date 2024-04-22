/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef CSV_OUTPUT_INPUT2_CONTAINER_H
#define CSV_OUTPUT_INPUT2_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "CsvOutputFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace CsvOutput
{
    class Input2Container final
    {
    public:
        using ClassType = Input2Container;

        using ConstInput2SharedPtr = std::shared_ptr<const Input2MappingType>;
        using Container = std::vector<ConstInput2SharedPtr>;
        using CSVContent = CoreTools::CSVContent;

    public:
        explicit Input2Container(const CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstInput2SharedPtr GetFirstInput2() const;
        NODISCARD ConstInput2SharedPtr GetInput2(int key) const;
        NODISCARD Container GetContainer() const;

        NODISCARD int GetContainerSize() const;

        template <typename Function>
        NODISCARD ConstInput2SharedPtr GetFirstInput2(Function function) const;

        template <typename Function>
        NODISCARD Container GetInput2(Function function) const;

    private:
        void Parsing(const CSVContent& csvContent);
        void Load(const CSVContent& csvContent);
        void Unique();

    private:
        Container input2;
    };
}

#endif  // CSV_OUTPUT_INPUT2_CONTAINER_H
/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef CSV_OUTPUT_INPUT3_CONTAINER_H
#define CSV_OUTPUT_INPUT3_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "CsvOutputFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace CsvOutput
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

#endif  // CSV_OUTPUT_INPUT3_CONTAINER_H

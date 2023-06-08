/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_SEXAGENARY_CYCLE_CONTAINER_H
#define ANCIENT_BOOKS_SEXAGENARY_CYCLE_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace AncientBooks
{
    class SexagenaryCycleContainer final
    {
    public:
        using ClassType = SexagenaryCycleContainer;
        using ConstSexagenaryCycleBaseSharedPtr = std::shared_ptr<const SexagenaryCycleBase>;
        using Container = std::vector<ConstSexagenaryCycleBaseSharedPtr>;

    public:
        explicit SexagenaryCycleContainer(const CoreTools::CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstSexagenaryCycleBaseSharedPtr GetFirstSexagenaryCycle() const;
        NODISCARD ConstSexagenaryCycleBaseSharedPtr GetSexagenaryCycle(int key) const;
        NODISCARD Container GetContainer() const;

        template <typename Function>
        NODISCARD ConstSexagenaryCycleBaseSharedPtr GetFirstSexagenaryCycle(Function function) const;

        template <typename Function>
        NODISCARD Container GetSexagenaryCycle(Function function) const;

    private:
        void Parsing(const CoreTools::CSVContent& csvContent);

    private:
        Container sexagenaryCycle;
    };
}

#endif  // ANCIENT_BOOKS_SEXAGENARY_CYCLE_CONTAINER_H

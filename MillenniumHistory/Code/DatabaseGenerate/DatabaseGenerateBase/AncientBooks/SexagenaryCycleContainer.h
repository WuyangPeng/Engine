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

        using ConstSexagenaryCycleSharedPtr = std::shared_ptr<const SexagenaryCycleMappingType>;
        using Container = std::vector<ConstSexagenaryCycleSharedPtr>;
        using CSVContent = CoreTools::CSVContent;

    public:
        explicit SexagenaryCycleContainer(const CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstSexagenaryCycleSharedPtr GetFirstSexagenaryCycle() const;
        NODISCARD ConstSexagenaryCycleSharedPtr GetSexagenaryCycle(int key) const;
        NODISCARD Container GetContainer() const;

        NODISCARD int GetContainerSize() const;

        template <typename Function>
        NODISCARD ConstSexagenaryCycleSharedPtr GetFirstSexagenaryCycle(Function function) const;

        template <typename Function>
        NODISCARD Container GetSexagenaryCycle(Function function) const;

    private:
        void Parsing(const CSVContent& csvContent);
        void Load(const CSVContent& csvContent);
        void Unique();

    private:
        Container sexagenaryCycle;
    };
}

#endif  // ANCIENT_BOOKS_SEXAGENARY_CYCLE_CONTAINER_H

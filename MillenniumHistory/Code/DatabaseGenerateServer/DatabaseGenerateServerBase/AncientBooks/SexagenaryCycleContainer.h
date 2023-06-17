/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

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

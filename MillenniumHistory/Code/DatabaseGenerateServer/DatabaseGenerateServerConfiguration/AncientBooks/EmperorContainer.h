/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_EMPEROR_CONTAINER_H
#define ANCIENT_BOOKS_EMPEROR_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace AncientBooks
{
    class EmperorContainer final
    {
    public:
        using ClassType = EmperorContainer;
        using ConstEmperorBaseSharedPtr = std::shared_ptr<const EmperorBase>;
        using Container = std::vector<ConstEmperorBaseSharedPtr>;

    public:
        explicit EmperorContainer(const CoreTools::CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstEmperorBaseSharedPtr GetFirstEmperor() const;
        NODISCARD ConstEmperorBaseSharedPtr GetEmperor(int key) const;
        NODISCARD Container GetContainer() const;

        template <typename Function>
        NODISCARD ConstEmperorBaseSharedPtr GetFirstEmperor(Function function) const;

        template <typename Function>
        NODISCARD Container GetEmperor(Function function) const;

    private:
        void Parsing(const CoreTools::CSVContent& csvContent);

    private:
        Container emperor;
    };
}

#endif  // ANCIENT_BOOKS_EMPEROR_CONTAINER_H

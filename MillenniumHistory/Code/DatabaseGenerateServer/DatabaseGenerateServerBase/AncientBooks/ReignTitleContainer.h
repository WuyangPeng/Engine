/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_REIGN_TITLE_CONTAINER_H
#define ANCIENT_BOOKS_REIGN_TITLE_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace AncientBooks
{
    class ReignTitleContainer final
    {
    public:
        using ClassType = ReignTitleContainer;
        using ConstReignTitleBaseSharedPtr = std::shared_ptr<const ReignTitleBase>;
        using Container = std::vector<ConstReignTitleBaseSharedPtr>;

    public:
        explicit ReignTitleContainer(const CoreTools::CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstReignTitleBaseSharedPtr GetFirstReignTitle() const;
        NODISCARD ConstReignTitleBaseSharedPtr GetReignTitle(int64_t key) const;
        NODISCARD Container GetContainer() const;

        template <typename Function>
        NODISCARD ConstReignTitleBaseSharedPtr GetFirstReignTitle(Function function) const;

        template <typename Function>
        NODISCARD Container GetReignTitle(Function function) const;

    private:
        void Parsing(const CoreTools::CSVContent& csvContent);

    private:
        Container reignTitle;
    };
}

#endif  // ANCIENT_BOOKS_REIGN_TITLE_CONTAINER_H

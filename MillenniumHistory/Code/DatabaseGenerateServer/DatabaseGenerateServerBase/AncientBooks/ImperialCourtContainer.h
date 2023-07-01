/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_IMPERIAL_COURT_CONTAINER_H
#define ANCIENT_BOOKS_IMPERIAL_COURT_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace AncientBooks
{
    class ImperialCourtContainer final
    {
    public:
        using ClassType = ImperialCourtContainer;

        using ConstImperialCourtBaseSharedPtr = std::shared_ptr<const ImperialCourtBase>;
        using Container = std::vector<ConstImperialCourtBaseSharedPtr>;
        using CSVContent = CoreTools::CSVContent;

    public:
        explicit ImperialCourtContainer(const CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstImperialCourtBaseSharedPtr GetFirstImperialCourt() const;
        NODISCARD ConstImperialCourtBaseSharedPtr GetImperialCourt(int key) const;
        NODISCARD Container GetContainer() const;

        template <typename Function>
        NODISCARD ConstImperialCourtBaseSharedPtr GetFirstImperialCourt(Function function) const;

        template <typename Function>
        NODISCARD Container GetImperialCourt(Function function) const;

    private:
        void Parsing(const CSVContent& csvContent);
        void Load(const CSVContent& csvContent);
        void Unique();

    private:
        Container imperialCourt;
    };
}

#endif  // ANCIENT_BOOKS_IMPERIAL_COURT_CONTAINER_H

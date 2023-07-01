/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_GEOGRAPHIC_CONTAINER_H
#define ANCIENT_BOOKS_GEOGRAPHIC_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace AncientBooks
{
    class GeographicContainer final
    {
    public:
        using ClassType = GeographicContainer;

        using ConstGeographicBaseSharedPtr = std::shared_ptr<const GeographicBase>;
        using Container = std::vector<ConstGeographicBaseSharedPtr>;
        using CSVContent = CoreTools::CSVContent;

    public:
        explicit GeographicContainer(const CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstGeographicBaseSharedPtr GetFirstGeographic() const;
        NODISCARD ConstGeographicBaseSharedPtr GetGeographic(int key) const;
        NODISCARD Container GetContainer() const;

        template <typename Function>
        NODISCARD ConstGeographicBaseSharedPtr GetFirstGeographic(Function function) const;

        template <typename Function>
        NODISCARD Container GetGeographic(Function function) const;

    private:
        void Parsing(const CSVContent& csvContent);
        void Load(const CSVContent& csvContent);
        void Unique();

    private:
        Container geographic;
    };
}

#endif  // ANCIENT_BOOKS_GEOGRAPHIC_CONTAINER_H

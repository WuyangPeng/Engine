/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_SOURCE_CONTAINER_H
#define ANCIENT_BOOKS_SOURCE_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace AncientBooks
{
    class SourceContainer final
    {
    public:
        using ClassType = SourceContainer;

        using ConstSourceBaseSharedPtr = std::shared_ptr<const SourceBase>;
        using Container = std::vector<ConstSourceBaseSharedPtr>;
        using CSVContent = CoreTools::CSVContent;

    public:
        explicit SourceContainer(const CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstSourceBaseSharedPtr GetFirstSource() const;
        NODISCARD ConstSourceBaseSharedPtr GetSource(int key) const;
        NODISCARD Container GetContainer() const;

        template <typename Function>
        NODISCARD ConstSourceBaseSharedPtr GetFirstSource(Function function) const;

        template <typename Function>
        NODISCARD Container GetSource(Function function) const;

    private:
        void Parsing(const CSVContent& csvContent);
        void Load(const CSVContent& csvContent);
        void Unique();

    private:
        Container source;
    };
}

#endif  // ANCIENT_BOOKS_SOURCE_CONTAINER_H

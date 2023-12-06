/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_VERSION_CONTAINER_H
#define ANCIENT_BOOKS_VERSION_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace AncientBooks
{
    class VersionContainer final
    {
    public:
        using ClassType = VersionContainer;

        using ConstVersionSharedPtr = std::shared_ptr<const VersionMappingType>;
        using Container = std::vector<ConstVersionSharedPtr>;
        using CSVContent = CoreTools::CSVContent;

    public:
        explicit VersionContainer(const CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstVersionSharedPtr GetFirstVersion() const;
        NODISCARD ConstVersionSharedPtr GetVersion(int key) const;
        NODISCARD Container GetContainer() const;

        NODISCARD int GetContainerSize() const;

        template <typename Function>
        NODISCARD ConstVersionSharedPtr GetFirstVersion(Function function) const;

        template <typename Function>
        NODISCARD Container GetVersion(Function function) const;

    private:
        void Parsing(const CSVContent& csvContent);
        void Load(const CSVContent& csvContent);
        void Unique();

    private:
        Container version;
    };
}

#endif  // ANCIENT_BOOKS_VERSION_CONTAINER_H

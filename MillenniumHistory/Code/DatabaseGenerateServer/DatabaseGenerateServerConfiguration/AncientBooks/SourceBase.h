/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_SOURCE_BASE_H
#define ANCIENT_BOOKS_SOURCE_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

namespace AncientBooks
{
    class SourceBase
    {
    public:
        using ClassType = SourceBase;

    public:
        SourceBase() noexcept = default;
        explicit SourceBase(int key) noexcept;

        virtual ~SourceBase() noexcept = default;
        SourceBase(const SourceBase& rhs) noexcept = default;
        SourceBase& operator=(const SourceBase& rhs) noexcept = default;
        SourceBase(SourceBase&& rhs) noexcept = default;
        SourceBase& operator=(SourceBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int GetKey() const noexcept;

        NODISCARD virtual int GetId() const noexcept;

        NODISCARD virtual System::String GetName() const;

        NODISCARD virtual int GetSort() const noexcept;

    private:
        int key{};
    };
}

#endif  // ANCIENT_BOOKS_SOURCE_BASE_H

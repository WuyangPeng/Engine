/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_GATHER_BASE_H
#define ANCIENT_BOOKS_GATHER_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"


namespace AncientBooks
{
    class GatherBase
    {
    public:
        using ClassType = GatherBase;

        using String = System::String;

    public:
        GatherBase() noexcept = default;
        explicit GatherBase(int key) noexcept;

        virtual ~GatherBase() noexcept = default;
        GatherBase(const GatherBase& rhs) noexcept = default;
        GatherBase& operator=(const GatherBase& rhs) noexcept = default;
        GatherBase(GatherBase&& rhs) noexcept = default;
        GatherBase& operator=(GatherBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int GetKey() const noexcept;

        NODISCARD virtual int GetId() const noexcept;

        NODISCARD virtual String GetGather() const;

    private:
        int key{};
    };
}

#endif  // ANCIENT_BOOKS_GATHER_BASE_H

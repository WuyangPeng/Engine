/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_IDENTITY_BASE_H
#define ANCIENT_BOOKS_IDENTITY_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"


namespace AncientBooks
{
    class IdentityBase
    {
    public:
        using ClassType = IdentityBase;

        using String = System::String;

    public:
        IdentityBase() noexcept = default;
        explicit IdentityBase(int key) noexcept;

        virtual ~IdentityBase() noexcept = default;
        IdentityBase(const IdentityBase& rhs) noexcept = default;
        IdentityBase& operator=(const IdentityBase& rhs) noexcept = default;
        IdentityBase(IdentityBase&& rhs) noexcept = default;
        IdentityBase& operator=(IdentityBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int GetKey() const noexcept;

        NODISCARD virtual int GetId() const noexcept;

        NODISCARD virtual String GetIdentity() const;

    private:
        int key{};
    };
}

#endif  // ANCIENT_BOOKS_IDENTITY_BASE_H

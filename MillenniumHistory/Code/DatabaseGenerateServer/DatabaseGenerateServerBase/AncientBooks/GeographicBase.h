/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_GEOGRAPHIC_BASE_H
#define ANCIENT_BOOKS_GEOGRAPHIC_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"


namespace AncientBooks
{
    class GeographicBase
    {
    public:
        using ClassType = GeographicBase;

        using String = System::String;

    public:
        GeographicBase() noexcept = default;
        explicit GeographicBase(int key) noexcept;

        virtual ~GeographicBase() noexcept = default;
        GeographicBase(const GeographicBase& rhs) noexcept = default;
        GeographicBase& operator=(const GeographicBase& rhs) noexcept = default;
        GeographicBase(GeographicBase&& rhs) noexcept = default;
        GeographicBase& operator=(GeographicBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int GetKey() const noexcept;

        NODISCARD virtual int GetId() const noexcept;

        NODISCARD virtual String GetName() const;

    private:
        int key{};
    };
}

#endif  // ANCIENT_BOOKS_GEOGRAPHIC_BASE_H

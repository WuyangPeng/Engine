/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_IMPERIAL_COURT_BASE_H
#define ANCIENT_BOOKS_IMPERIAL_COURT_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
namespace AncientBooks
{
    class ImperialCourtBase
    {
    public:
        using ClassType = ImperialCourtBase;

    public:
        ImperialCourtBase() noexcept = default;
        explicit ImperialCourtBase(int key) noexcept;

        virtual ~ImperialCourtBase() noexcept = default;
        ImperialCourtBase(const ImperialCourtBase& rhs) noexcept = default;
        ImperialCourtBase& operator=(const ImperialCourtBase& rhs) noexcept = default;
        ImperialCourtBase(ImperialCourtBase&& rhs) noexcept = default;
        ImperialCourtBase& operator=(ImperialCourtBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int GetKey() const noexcept;

        NODISCARD virtual int GetId() const noexcept;

        NODISCARD virtual System::String GetCategory() const;

        NODISCARD virtual System::String GetBook() const;

        NODISCARD virtual int GetBegin() const noexcept;
        NODISCARD virtual std::shared_ptr<const YearMappingType> GetBegin(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetEnd() const noexcept;
        NODISCARD virtual std::shared_ptr<const YearMappingType> GetEnd(const AncientBooksContainer& csvContainer) const;

    private:
        int key{};
    };
}

#endif  // ANCIENT_BOOKS_IMPERIAL_COURT_BASE_H

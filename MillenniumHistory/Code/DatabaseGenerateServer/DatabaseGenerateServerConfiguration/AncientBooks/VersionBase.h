/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_VERSION_BASE_H
#define ANCIENT_BOOKS_VERSION_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace AncientBooks
{
    class VersionBase
    {
    public:
        using ClassType = VersionBase;

    public:
        VersionBase() noexcept = default;
        explicit VersionBase(int key) noexcept;

        virtual ~VersionBase() noexcept = default;
        VersionBase(const VersionBase& rhs) noexcept = default;
        VersionBase& operator=(const VersionBase& rhs) noexcept = default;
        VersionBase(VersionBase&& rhs) noexcept = default;
        VersionBase& operator=(VersionBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int GetKey() const noexcept;

        NODISCARD virtual int GetId() const noexcept;

        NODISCARD virtual int GetBook() const noexcept;
        NODISCARD virtual std::shared_ptr<const BookMappingType> GetBook(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetSource() const noexcept;

        NODISCARD virtual System::String GetSourceName() const;

        NODISCARD virtual int GetCountry() const noexcept;
        NODISCARD virtual std::shared_ptr<const CountryMappingType> GetCountry(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int64_t GetReignTitle() const noexcept;
        NODISCARD virtual std::shared_ptr<const ReignTitleMappingType> GetReignTitle(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetYear() const noexcept;
        NODISCARD virtual std::shared_ptr<const YearMappingType> GetYear(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual System::String GetVersion() const;

        NODISCARD virtual std::vector<int> GetOtherAuthor() const;
        NODISCARD virtual int GetOtherAuthorCount() const;
        NODISCARD virtual int GetOtherAuthor(MAYBE_UNUSED int index) const;
        NODISCARD virtual std::vector<int>::const_iterator GetOtherAuthorBegin() const;
        NODISCARD virtual std::vector<int>::const_iterator GetOtherAuthorEnd() const;

        NODISCARD virtual std::vector<System::String> GetAuthorDescribe() const;
        NODISCARD virtual int GetAuthorDescribeCount() const;
        NODISCARD virtual System::String GetAuthorDescribe(MAYBE_UNUSED int index) const;
        NODISCARD virtual std::vector<System::String>::const_iterator GetAuthorDescribeBegin() const;
        NODISCARD virtual std::vector<System::String>::const_iterator GetAuthorDescribeEnd() const;

    private:
        int key{};
    };
}

#endif  // ANCIENT_BOOKS_VERSION_BASE_H

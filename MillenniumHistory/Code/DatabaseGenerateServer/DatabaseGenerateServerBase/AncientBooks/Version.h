/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_VERSION_H
#define ANCIENT_BOOKS_VERSION_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "VersionBase.h"
#include "System/Helper/UnicodeUsing.h"

namespace AncientBooks
{
    class Version final : public VersionBase
    {
    public:
        using ClassType = Version;
        using ParentType = VersionBase;

        using CSVRow = CoreTools::CSVRow; 

    public:
        explicit Version(const CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD int GetBook() const noexcept override;
        NODISCARD ConstBookSharedPtr GetBook(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetSource() const noexcept override;

        NODISCARD String GetSourceName() const override;

        NODISCARD int GetCountry() const noexcept override;
        NODISCARD ConstCountrySharedPtr GetCountry(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int64_t GetReignTitle() const noexcept override;
        NODISCARD ConstReignTitleSharedPtr GetReignTitle(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetYear() const noexcept override;
        NODISCARD ConstYearSharedPtr GetYear(const AncientBooksContainer& csvContainer) const override;

        NODISCARD String GetVersion() const override;

        NODISCARD IntContainer GetOtherAuthor() const override;
        NODISCARD int GetOtherAuthorCount() const override;
        NODISCARD int GetOtherAuthor(int index) const override;
        NODISCARD IntContainerConstIter GetOtherAuthorBegin() const noexcept override;
        NODISCARD IntContainerConstIter GetOtherAuthorEnd() const noexcept override;
        NODISCARD CharacterContainer GetOtherAuthor(const AncientBooksContainer& csvContainer) const override;

        NODISCARD StringContainer GetAuthorNotes() const override;
        NODISCARD int GetAuthorNotesCount() const override;
        NODISCARD String GetAuthorNotes(int index) const override;
        NODISCARD StringContainerConstIter GetAuthorNotesBegin() const noexcept override;
        NODISCARD StringContainerConstIter GetAuthorNotesEnd() const noexcept override;


    private:
        int id;  // Id
        int book;  // 書
        int source;  // 出處
        String sourceName;  // 出處名字
        int country;  // 時代
        int64_t reignTitle;  // 年號
        int year;  // 年
        String version;  // 版本
        IntContainer otherAuthor;  // 其他作者
        StringContainer authorNotes;  // 作者描述
    };
}

#endif  // ANCIENT_BOOKS_VERSION_H

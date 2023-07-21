/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_ARTICLE_BASE_H
#define ANCIENT_BOOKS_ARTICLE_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace AncientBooks
{
    class ArticleBase
    {
    public:
        using ClassType = ArticleBase;

        using String = System::String;
        using StringContainer = std::vector<String>;
        using StringContainerConstIter = StringContainer::const_iterator;
        using IntContainer = std::vector<int>;
        using IntContainerConstIter = IntContainer::const_iterator;
        using ConstVersionSharedPtr = std::shared_ptr<const VersionMappingType>;
        using ConstCharacterSharedPtr = std::shared_ptr<const CharacterMappingType>;
        using CharacterContainer = std::vector<ConstCharacterSharedPtr>;

    public:
        ArticleBase() noexcept = default;
        explicit ArticleBase(int64_t key) noexcept;

        virtual ~ArticleBase() noexcept = default;
        ArticleBase(const ArticleBase& rhs) noexcept = default;
        ArticleBase& operator=(const ArticleBase& rhs) noexcept = default;
        ArticleBase(ArticleBase&& rhs) noexcept = default;
        ArticleBase& operator=(ArticleBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int64_t GetKey() const noexcept;

        NODISCARD virtual int64_t GetId() const noexcept;

        NODISCARD virtual int GetVersion() const noexcept;
        NODISCARD virtual ConstVersionSharedPtr GetVersion(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetChapter() const noexcept;

        NODISCARD virtual String GetChapterName() const;

        NODISCARD virtual int GetVolume() const noexcept;

        NODISCARD virtual int GetChapterVolume() const noexcept;

        NODISCARD virtual IntContainer GetOtherAuthor() const;
        NODISCARD virtual int GetOtherAuthorCount() const;
        NODISCARD virtual int GetOtherAuthor(int index) const;
        NODISCARD virtual IntContainerConstIter GetOtherAuthorBegin() const;
        NODISCARD virtual IntContainerConstIter GetOtherAuthorEnd() const;
        NODISCARD virtual CharacterContainer GetOtherAuthor(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual StringContainer GetAuthorNotes() const;
        NODISCARD virtual int GetAuthorNotesCount() const;
        NODISCARD virtual String GetAuthorNotes(int index) const;
        NODISCARD virtual StringContainerConstIter GetAuthorNotesBegin() const;
        NODISCARD virtual StringContainerConstIter GetAuthorNotesEnd() const;

        NODISCARD virtual String GetTitle() const;

        NODISCARD virtual String GetAbbreviation() const;

        NODISCARD virtual String GetDirectory() const;

    private:
        int64_t key{};
    };
}

#endif  // ANCIENT_BOOKS_ARTICLE_BASE_H

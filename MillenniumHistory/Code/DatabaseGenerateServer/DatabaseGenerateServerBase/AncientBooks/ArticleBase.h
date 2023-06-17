/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

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
        NODISCARD virtual std::shared_ptr<const VersionMappingType> GetVersion(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetChapter() const noexcept;
        NODISCARD virtual std::shared_ptr<const ChapterMappingType> GetChapter(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual System::String GetChapterName() const;

        NODISCARD virtual int GetVolume() const noexcept;

        NODISCARD virtual std::vector<int> GetOtherAuthor() const;
        NODISCARD virtual int GetOtherAuthorCount() const;
        NODISCARD virtual int GetOtherAuthor(int index) const;
        NODISCARD virtual std::vector<int>::const_iterator GetOtherAuthorBegin() const;
        NODISCARD virtual std::vector<int>::const_iterator GetOtherAuthorEnd() const;

        NODISCARD virtual std::vector<System::String> GetAuthorDescribe() const;
        NODISCARD virtual int GetAuthorDescribeCount() const;
        NODISCARD virtual System::String GetAuthorDescribe(int index) const;
        NODISCARD virtual std::vector<System::String>::const_iterator GetAuthorDescribeBegin() const;
        NODISCARD virtual std::vector<System::String>::const_iterator GetAuthorDescribeEnd() const;

        NODISCARD virtual System::String GetTitle() const;

        NODISCARD virtual System::String GetAbbreviation() const;

        NODISCARD virtual System::String GetDirectory() const;

    private:
        int64_t key{};
    };
}

#endif  // ANCIENT_BOOKS_ARTICLE_BASE_H

/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_ARTICLE_H
#define ANCIENT_BOOKS_ARTICLE_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "ArticleBase.h"
#include "System/Helper/UnicodeUsing.h"

namespace AncientBooks
{
    class Article final : public ArticleBase
    {
    public:
        using ClassType = Article;
        using ParentType = ArticleBase;

    public:
        explicit Article(const CoreTools::CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int64_t GetKey() const noexcept override;

        NODISCARD int64_t GetId() const noexcept override;

        NODISCARD int GetVersion() const noexcept override;
        NODISCARD std::shared_ptr<const VersionMappingType> GetVersion(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetChapter() const noexcept override;
        NODISCARD std::shared_ptr<const ChapterMappingType> GetChapter(const AncientBooksContainer& csvContainer) const override;

        NODISCARD System::String GetChapterName() const override;

        NODISCARD int GetVolume() const noexcept override;

        NODISCARD std::vector<int> GetOtherAuthor() const override;
        NODISCARD int GetOtherAuthorCount() const override;
        NODISCARD int GetOtherAuthor(int index) const override;
        NODISCARD std::vector<int>::const_iterator GetOtherAuthorBegin() const noexcept override;
        NODISCARD std::vector<int>::const_iterator GetOtherAuthorEnd() const noexcept override;

        NODISCARD std::vector<System::String> GetAuthorDescribe() const override;
        NODISCARD int GetAuthorDescribeCount() const override;
        NODISCARD System::String GetAuthorDescribe(int index) const override;
        NODISCARD std::vector<System::String>::const_iterator GetAuthorDescribeBegin() const noexcept override;
        NODISCARD std::vector<System::String>::const_iterator GetAuthorDescribeEnd() const noexcept override;

        NODISCARD System::String GetTitle() const override;

        NODISCARD System::String GetAbbreviation() const override;

        NODISCARD System::String GetDirectory() const override;

    private:
        int64_t id;  // Id
        int version;  // �汾
        int chapter;  // ��
        System::String chapterName;  // �¹�����
        int volume;  // ��
        std::vector<int> otherAuthor;  // ��������
        std::vector<System::String> authorDescribe;  // ��������
        System::String title;  // ���}
        System::String abbreviation;  // ���}
        System::String directory;  // Ŀ�
    };
}

#endif  // ANCIENT_BOOKS_ARTICLE_H

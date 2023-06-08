/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

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

    public:
        explicit Version(const CoreTools::CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD int GetBook() const noexcept override;
        NODISCARD std::shared_ptr<const BookMappingType> GetBook(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetSource() const noexcept override;

        NODISCARD System::String GetSourceName() const override;

        NODISCARD int GetCountry() const noexcept override;
        NODISCARD std::shared_ptr<const CountryMappingType> GetCountry(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int64_t GetReignTitle() const noexcept override;
        NODISCARD std::shared_ptr<const ReignTitleMappingType> GetReignTitle(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetYear() const noexcept override;
        NODISCARD std::shared_ptr<const YearMappingType> GetYear(const AncientBooksContainer& csvContainer) const override;

        NODISCARD System::String GetVersion() const override;

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

    private:
        int id;  // Id
        int book;  // ��
        int source;  // ��̎
        System::String sourceName;  // ��̎����
        int country;  // �r��
        int64_t reignTitle;  // ��̖
        int year;  // ��
        System::String version;  // �汾
        std::vector<int> otherAuthor;  // ��������
        std::vector<System::String> authorDescribe;  // ��������
    };
}

#endif  // ANCIENT_BOOKS_VERSION_H

/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_CALENDAR_H
#define ANCIENT_BOOKS_CALENDAR_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "CalendarBase.h"
#include "System/Helper/UnicodeUsing.h"

namespace AncientBooks
{
    class Calendar final : public CalendarBase
    {
    public:
        using ClassType = Calendar;
        using ParentType = CalendarBase;

    public:
        explicit Calendar(const CoreTools::CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD System::String GetName() const override;

        NODISCARD std::vector<System::String> GetAlias() const override;
        NODISCARD int GetAliasCount() const override;
        NODISCARD System::String GetAlias(int index) const override;
        NODISCARD std::vector<System::String>::const_iterator GetAliasBegin() const noexcept override;
        NODISCARD std::vector<System::String>::const_iterator GetAliasEnd() const noexcept override;

        NODISCARD std::vector<int> GetSource() const override;
        NODISCARD int GetSourceCount() const override;
        NODISCARD int GetSource(int index) const override;
        NODISCARD std::vector<int>::const_iterator GetSourceBegin() const noexcept override;
        NODISCARD std::vector<int>::const_iterator GetSourceEnd() const noexcept override;

        NODISCARD System::String GetPublication() const override;

        NODISCARD std::vector<int> GetCreator() const override;
        NODISCARD int GetCreatorCount() const override;
        NODISCARD int GetCreator(int index) const override;
        NODISCARD std::vector<int>::const_iterator GetCreatorBegin() const noexcept override;
        NODISCARD std::vector<int>::const_iterator GetCreatorEnd() const noexcept override;

        NODISCARD int GetFormulate() const noexcept override;
        NODISCARD std::shared_ptr<const YearMappingType> GetFormulate(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetCountry() const noexcept override;
        NODISCARD std::shared_ptr<const CountryMappingType> GetCountry(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetBegin() const noexcept override;
        NODISCARD std::shared_ptr<const YearMappingType> GetBegin(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetEnd() const noexcept override;
        NODISCARD std::shared_ptr<const YearMappingType> GetEnd(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetAgainBegin() const noexcept override;
        NODISCARD std::shared_ptr<const YearMappingType> GetAgainBegin(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetAgainEnd() const noexcept override;
        NODISCARD std::shared_ptr<const YearMappingType> GetAgainEnd(const AncientBooksContainer& csvContainer) const override;

    private:
        int id;  // Id
        System::String name;  // ����
        std::vector<System::String> alias;  // �e��
        std::vector<int> source;  // ��̎
        System::String publication;  // ���d
        std::vector<int> creator;  // ������
        int formulate;  // �ƶ���
        int country;  // ����
        int begin;  // �_ʼ
        int end;  // �Y��
        int againBegin;  // �ٴ��_ʼ
        int againEnd;  // �ٴνY��
    };
}

#endif  // ANCIENT_BOOKS_CALENDAR_H

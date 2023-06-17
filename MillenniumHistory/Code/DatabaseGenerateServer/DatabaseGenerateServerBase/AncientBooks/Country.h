/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_COUNTRY_H
#define ANCIENT_BOOKS_COUNTRY_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "CountryBase.h"
#include "System/Helper/UnicodeUsing.h"

namespace AncientBooks
{
    class Country final : public CountryBase
    {
    public:
        using ClassType = Country;
        using ParentType = CountryBase;

    public:
        explicit Country(const CoreTools::CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD int GetImperialCourt() const noexcept override;
        NODISCARD std::shared_ptr<const ImperialCourtMappingType> GetImperialCourt(const AncientBooksContainer& csvContainer) const override;

        NODISCARD System::String GetCategory() const override;

        NODISCARD int GetBeginYear() const noexcept override;
        NODISCARD std::shared_ptr<const YearMappingType> GetBeginYear(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetBeginMonth() const noexcept override;
        NODISCARD std::shared_ptr<const MonthMappingType> GetBeginMonth(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetBeginSexagenaryCycle() const noexcept override;
        NODISCARD std::shared_ptr<const SexagenaryCycleMappingType> GetBeginSexagenaryCycle(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetBeginDay() const noexcept override;
        NODISCARD std::shared_ptr<const DayMappingType> GetBeginDay(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetEndYear() const noexcept override;
        NODISCARD std::shared_ptr<const YearMappingType> GetEndYear(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetEndMonth() const noexcept override;
        NODISCARD std::shared_ptr<const MonthMappingType> GetEndMonth(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetEndSexagenaryCycle() const noexcept override;
        NODISCARD std::shared_ptr<const SexagenaryCycleMappingType> GetEndSexagenaryCycle(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetEndDay() const noexcept override;
        NODISCARD std::shared_ptr<const DayMappingType> GetEndDay(const AncientBooksContainer& csvContainer) const override;

        NODISCARD std::vector<System::String> GetUnansweredQuestion() const override;
        NODISCARD int GetUnansweredQuestionCount() const override;
        NODISCARD System::String GetUnansweredQuestion(int index) const override;
        NODISCARD std::vector<System::String>::const_iterator GetUnansweredQuestionBegin() const noexcept override;
        NODISCARD std::vector<System::String>::const_iterator GetUnansweredQuestionEnd() const noexcept override;

    private:
        int id;  // Id
        int imperialCourt;  // ����
        System::String category;  // ����
        int beginYear;  // ��ʼ��
        int beginMonth;  // ��ʼ��
        int beginSexagenaryCycle;  // ��ʼ��֧��
        int beginDay;  // ��ʼ��
        int endYear;  // ������
        int endMonth;  // ������
        int endSexagenaryCycle;  // ������֧��
        int endDay;  // ������
        std::vector<System::String> unansweredQuestion;  // ����
    };
}

#endif  // ANCIENT_BOOKS_COUNTRY_H

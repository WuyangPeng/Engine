/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_EMPEROR_H
#define ANCIENT_BOOKS_EMPEROR_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "EmperorBase.h"
#include "System/Helper/UnicodeUsing.h"

namespace AncientBooks
{
    class Emperor final : public EmperorBase
    {
    public:
        using ClassType = Emperor;
        using ParentType = EmperorBase;

    public:
        explicit Emperor(const CoreTools::CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD int GetCharacter() const noexcept override;
        NODISCARD std::shared_ptr<const CharacterMappingType> GetCharacter(const AncientBooksContainer& csvContainer) const override;

        NODISCARD System::String GetName() const override;

        NODISCARD System::String GetDynasticTitle() const override;

        NODISCARD std::vector<System::String> GetDynasticTitleAlias() const override;
        NODISCARD int GetDynasticTitleAliasCount() const override;
        NODISCARD System::String GetDynasticTitleAlias(int index) const override;
        NODISCARD std::vector<System::String>::const_iterator GetDynasticTitleAliasBegin() const noexcept override;
        NODISCARD std::vector<System::String>::const_iterator GetDynasticTitleAliasEnd() const noexcept override;

        NODISCARD System::String GetPosthumousTitle() const override;

        NODISCARD std::vector<System::String> GetPosthumousTitleAlias() const override;
        NODISCARD int GetPosthumousTitleAliasCount() const override;
        NODISCARD System::String GetPosthumousTitleAlias(int index) const override;
        NODISCARD std::vector<System::String>::const_iterator GetPosthumousTitleAliasBegin() const noexcept override;
        NODISCARD std::vector<System::String>::const_iterator GetPosthumousTitleAliasEnd() const noexcept override;

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

        NODISCARD int GetAgainBeginYear() const noexcept override;
        NODISCARD std::shared_ptr<const YearMappingType> GetAgainBeginYear(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetAgainBeginMonth() const noexcept override;
        NODISCARD std::shared_ptr<const MonthMappingType> GetAgainBeginMonth(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetAgainBeginSexagenaryCycle() const noexcept override;
        NODISCARD std::shared_ptr<const SexagenaryCycleMappingType> GetAgainBeginSexagenaryCycle(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetAgainBeginDay() const noexcept override;
        NODISCARD std::shared_ptr<const DayMappingType> GetAgainBeginDay(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetAgainEndYear() const noexcept override;
        NODISCARD std::shared_ptr<const YearMappingType> GetAgainEndYear(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetAgainEndMonth() const noexcept override;
        NODISCARD std::shared_ptr<const MonthMappingType> GetAgainEndMonth(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetAgainEndSexagenaryCycle() const noexcept override;
        NODISCARD std::shared_ptr<const SexagenaryCycleMappingType> GetAgainEndSexagenaryCycle(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetAgainEndDay() const noexcept override;
        NODISCARD std::shared_ptr<const DayMappingType> GetAgainEndDay(const AncientBooksContainer& csvContainer) const override;

        NODISCARD std::vector<System::String> GetUnansweredQuestion() const override;
        NODISCARD int GetUnansweredQuestionCount() const override;
        NODISCARD System::String GetUnansweredQuestion(int index) const override;
        NODISCARD std::vector<System::String>::const_iterator GetUnansweredQuestionBegin() const noexcept override;
        NODISCARD std::vector<System::String>::const_iterator GetUnansweredQuestionEnd() const noexcept override;

    private:
        int id;  // Id
        int character;  // ����
        System::String name;  // ����
        System::String dynasticTitle;  // ���
        std::vector<System::String> dynasticTitleAlias;  // ��ű���
        System::String posthumousTitle;  // �ֺ�
        std::vector<System::String> posthumousTitleAlias;  // �ֺű���
        int beginYear;  // ��λ��
        int beginMonth;  // ��λ��
        int beginSexagenaryCycle;  // ��λ��֧��
        int beginDay;  // ��λ��
        int endYear;  // ��λ��
        int endMonth;  // ��λ��
        int endSexagenaryCycle;  // ��λ��֧��
        int endDay;  // ��λ��
        int againBeginYear;  // �ٴμ�λ��
        int againBeginMonth;  // �ٴμ�λ��
        int againBeginSexagenaryCycle;  // �ٴμ�λ��֧��
        int againBeginDay;  // �ٴμ�λ��
        int againEndYear;  // �ٴ���λ��
        int againEndMonth;  // �ٴ���λ��
        int againEndSexagenaryCycle;  // �ٴ���λ��֧��
        int againEndDay;  // �ٴ���λ��
        std::vector<System::String> unansweredQuestion;  // ����
    };
}

#endif  // ANCIENT_BOOKS_EMPEROR_H

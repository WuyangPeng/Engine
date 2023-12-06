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

        using CSVRow = CoreTools::CSVRow; 

    public:
        explicit Emperor(const CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD int GetCharacter() const noexcept override;
        NODISCARD ConstCharacterSharedPtr GetCharacter(const AncientBooksContainer& csvContainer) const override;

        NODISCARD String GetName() const override;

        NODISCARD String GetDynasticTitle() const override;

        NODISCARD StringContainer GetDynasticTitleAlias() const override;
        NODISCARD int GetDynasticTitleAliasCount() const override;
        NODISCARD String GetDynasticTitleAlias(int index) const override;
        NODISCARD StringContainerConstIter GetDynasticTitleAliasBegin() const noexcept override;
        NODISCARD StringContainerConstIter GetDynasticTitleAliasEnd() const noexcept override;

        NODISCARD String GetPosthumousTitle() const override;

        NODISCARD StringContainer GetPosthumousTitleAlias() const override;
        NODISCARD int GetPosthumousTitleAliasCount() const override;
        NODISCARD String GetPosthumousTitleAlias(int index) const override;
        NODISCARD StringContainerConstIter GetPosthumousTitleAliasBegin() const noexcept override;
        NODISCARD StringContainerConstIter GetPosthumousTitleAliasEnd() const noexcept override;

        NODISCARD int GetBeginYear() const noexcept override;
        NODISCARD ConstYearSharedPtr GetBeginYear(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetBeginMonth() const noexcept override;
        NODISCARD ConstMonthSharedPtr GetBeginMonth(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetBeginSexagenaryCycle() const noexcept override;
        NODISCARD ConstSexagenaryCycleSharedPtr GetBeginSexagenaryCycle(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetBeginDay() const noexcept override;
        NODISCARD ConstDaySharedPtr GetBeginDay(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetEndYear() const noexcept override;
        NODISCARD ConstYearSharedPtr GetEndYear(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetEndMonth() const noexcept override;
        NODISCARD ConstMonthSharedPtr GetEndMonth(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetEndSexagenaryCycle() const noexcept override;
        NODISCARD ConstSexagenaryCycleSharedPtr GetEndSexagenaryCycle(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetEndDay() const noexcept override;
        NODISCARD ConstDaySharedPtr GetEndDay(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetAgainBeginYear() const noexcept override;
        NODISCARD ConstYearSharedPtr GetAgainBeginYear(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetAgainBeginMonth() const noexcept override;
        NODISCARD ConstMonthSharedPtr GetAgainBeginMonth(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetAgainBeginSexagenaryCycle() const noexcept override;
        NODISCARD ConstSexagenaryCycleSharedPtr GetAgainBeginSexagenaryCycle(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetAgainBeginDay() const noexcept override;
        NODISCARD ConstDaySharedPtr GetAgainBeginDay(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetAgainEndYear() const noexcept override;
        NODISCARD ConstYearSharedPtr GetAgainEndYear(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetAgainEndMonth() const noexcept override;
        NODISCARD ConstMonthSharedPtr GetAgainEndMonth(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetAgainEndSexagenaryCycle() const noexcept override;
        NODISCARD ConstSexagenaryCycleSharedPtr GetAgainEndSexagenaryCycle(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetAgainEndDay() const noexcept override;
        NODISCARD ConstDaySharedPtr GetAgainEndDay(const AncientBooksContainer& csvContainer) const override;

        NODISCARD StringContainer GetUnansweredQuestion() const override;
        NODISCARD int GetUnansweredQuestionCount() const override;
        NODISCARD String GetUnansweredQuestion(int index) const override;
        NODISCARD StringContainerConstIter GetUnansweredQuestionBegin() const noexcept override;
        NODISCARD StringContainerConstIter GetUnansweredQuestionEnd() const noexcept override;

    private:
        int id;  // Id
        int character;  // ����
        String name;  // ����
        String dynasticTitle;  // ���
        StringContainer dynasticTitleAlias;  // ��ű���
        String posthumousTitle;  // �ֺ�
        StringContainer posthumousTitleAlias;  // �ֺű���
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
        StringContainer unansweredQuestion;  // ����
    };
}

#endif  // ANCIENT_BOOKS_EMPEROR_H

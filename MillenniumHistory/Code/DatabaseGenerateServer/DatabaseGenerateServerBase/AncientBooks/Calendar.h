/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

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

        using CSVRow = CoreTools::CSVRow;

    public:
        explicit Calendar(const CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD String GetName() const override;

        NODISCARD StringContainer GetAlias() const override;
        NODISCARD int GetAliasCount() const override;
        NODISCARD String GetAlias(int index) const override;
        NODISCARD StringContainerConstIter GetAliasBegin() const noexcept override;
        NODISCARD StringContainerConstIter GetAliasEnd() const noexcept override;

        NODISCARD IntContainer GetSource() const override;
        NODISCARD int GetSourceCount() const override;
        NODISCARD int GetSource(int index) const override;
        NODISCARD IntContainerConstIter GetSourceBegin() const noexcept override;
        NODISCARD IntContainerConstIter GetSourceEnd() const noexcept override;
        NODISCARD BookContainer GetSource(const AncientBooksContainer& csvContainer) const override;

        NODISCARD String GetPublication() const override;

        NODISCARD IntContainer GetCreator() const override;
        NODISCARD int GetCreatorCount() const override;
        NODISCARD int GetCreator(int index) const override;
        NODISCARD IntContainerConstIter GetCreatorBegin() const noexcept override;
        NODISCARD IntContainerConstIter GetCreatorEnd() const noexcept override;
        NODISCARD CharacterContainer GetCreator(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetFormulate() const noexcept override;
        NODISCARD ConstYearSharedPtr GetFormulate(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetCountry() const noexcept override;
        NODISCARD ConstCountrySharedPtr GetCountry(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetBegin() const noexcept override;
        NODISCARD ConstYearSharedPtr GetBegin(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetEnd() const noexcept override;
        NODISCARD ConstYearSharedPtr GetEnd(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetAgainBegin() const noexcept override;
        NODISCARD ConstYearSharedPtr GetAgainBegin(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetAgainEnd() const noexcept override;
        NODISCARD ConstYearSharedPtr GetAgainEnd(const AncientBooksContainer& csvContainer) const override;

    private:
        int id;  // Id
        String name;  // 名字
        StringContainer alias;  // 別名
        IntContainer source;  // 出處
        String publication;  // 刊載
        IntContainer creator;  // 創制人
        int formulate;  // 制定年
        int country;  // 國家
        int begin;  // 開始
        int end;  // 結束
        int againBegin;  // 再次開始
        int againEnd;  // 再次結束
    };
}

#endif  // ANCIENT_BOOKS_CALENDAR_H

/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_IMPERIAL_COURT_H
#define ANCIENT_BOOKS_IMPERIAL_COURT_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "ImperialCourtBase.h"
#include "System/Helper/UnicodeUsing.h"

namespace AncientBooks
{
    class ImperialCourt final : public ImperialCourtBase
    {
    public:
        using ClassType = ImperialCourt;
        using ParentType = ImperialCourtBase;

    public:
        explicit ImperialCourt(const CoreTools::CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD System::String GetCategory() const override;

        NODISCARD System::String GetBook() const override;

        NODISCARD int GetBegin() const noexcept override;
        NODISCARD std::shared_ptr<const YearMappingType> GetBegin(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetEnd() const noexcept override;
        NODISCARD std::shared_ptr<const YearMappingType> GetEnd(const AncientBooksContainer& csvContainer) const override;

    private:
        int id;  // Id
        System::String category;  // 名称
        System::String book;  // 书名
        int begin;  // 启始
        int end;  // 结束
    };
}

#endif  // ANCIENT_BOOKS_IMPERIAL_COURT_H

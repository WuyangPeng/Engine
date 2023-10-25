/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_DAY_H
#define ANCIENT_BOOKS_DAY_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "DayBase.h"
#include "System/Helper/UnicodeUsing.h"

namespace AncientBooks
{
    class Day final : public DayBase
    {
    public:
        using ClassType = Day;
        using ParentType = DayBase;

        using CSVRow = CoreTools::CSVRow; 

    public:
        explicit Day(const CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD String GetName() const override;


    private:
        int id;  // Id
        String name;  // 名字
    };
}

#endif  // ANCIENT_BOOKS_DAY_H

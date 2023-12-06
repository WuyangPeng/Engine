/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_GATHER_H
#define ANCIENT_BOOKS_GATHER_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "GatherBase.h"
#include "System/Helper/UnicodeUsing.h"

namespace AncientBooks
{
    class Gather final : public GatherBase
    {
    public:
        using ClassType = Gather;
        using ParentType = GatherBase;

        using CSVRow = CoreTools::CSVRow; 

    public:
        explicit Gather(const CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD String GetGather() const override;

    private:
        int id;  // Id
        String gather;  // 名称
    };
}

#endif  // ANCIENT_BOOKS_GATHER_H

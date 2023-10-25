/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_GENUS_H
#define ANCIENT_BOOKS_GENUS_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "GenusBase.h"
#include "System/Helper/UnicodeUsing.h"

namespace AncientBooks
{
    class Genus final : public GenusBase
    {
    public:
        using ClassType = Genus;
        using ParentType = GenusBase;

        using CSVRow = CoreTools::CSVRow; 

    public:
        explicit Genus(const CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD int GetCategory() const noexcept override;
        NODISCARD ConstCategorySharedPtr GetCategory(const AncientBooksContainer& csvContainer) const override;

        NODISCARD String GetName() const override;

        NODISCARD int GetFather() const noexcept override;
        NODISCARD ConstGenusSharedPtr GetFather(const AncientBooksContainer& csvContainer) const override;

        NODISCARD String GetBegin() const override;

        NODISCARD String GetEnd() const override;


    private:
        int id;  // Id
        int category;  // 類
        String name;  // 名称
        int father;  // 父類
        String begin;  // 启始
        String end;  // 结束
    };
}

#endif  // ANCIENT_BOOKS_GENUS_H

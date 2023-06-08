/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_CHAPTER_H
#define ANCIENT_BOOKS_CHAPTER_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "ChapterBase.h"
#include "System/Helper/UnicodeUsing.h"

namespace AncientBooks
{
    class Chapter final : public ChapterBase
    {
    public:
        using ClassType = Chapter;
        using ParentType = ChapterBase;

    public:
        explicit Chapter(const CoreTools::CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD System::String GetName() const override;

    private:
        int id;  // Id
        System::String name;  // 名稱
    };
}

#endif  // ANCIENT_BOOKS_CHAPTER_H

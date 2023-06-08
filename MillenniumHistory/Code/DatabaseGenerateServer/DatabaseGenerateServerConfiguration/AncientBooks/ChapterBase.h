/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_CHAPTER_BASE_H
#define ANCIENT_BOOKS_CHAPTER_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

namespace AncientBooks
{
    class ChapterBase
    {
    public:
        using ClassType = ChapterBase;

    public:
        ChapterBase() noexcept = default;
        explicit ChapterBase(int key) noexcept;

        virtual ~ChapterBase() noexcept = default;
        ChapterBase(const ChapterBase& rhs) noexcept = default;
        ChapterBase& operator=(const ChapterBase& rhs) noexcept = default;
        ChapterBase(ChapterBase&& rhs) noexcept = default;
        ChapterBase& operator=(ChapterBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int GetKey() const noexcept;

        NODISCARD virtual int GetId() const noexcept;

        NODISCARD virtual System::String GetName() const;

    private:
        int key{};
    };
}

#endif  // ANCIENT_BOOKS_CHAPTER_BASE_H

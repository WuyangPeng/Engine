/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++17
/// 自动生成

#ifndef C_S_V_CONFIGURE_CHAPTER_CONTAINER_H
#define C_S_V_CONFIGURE_CHAPTER_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVConfigureFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace CSVConfigure
{
    class ChapterContainer final
    {
    public:
        using ClassType = ChapterContainer;
        using ConstChapterBaseSharedPtr = std::shared_ptr<const ChapterBase>;
        using Container = std::vector<ConstChapterBaseSharedPtr>;

    public:
        explicit ChapterContainer(const CoreTools::CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstChapterBaseSharedPtr GetFirstChapter() const;
        NODISCARD ConstChapterBaseSharedPtr GetChapter(int key) const;
        NODISCARD Container GetContainer() const;

        template <typename Function>
        NODISCARD ConstChapterBaseSharedPtr GetFirstChapter(Function function) const;

        template <typename Function>
        NODISCARD Container GetChapter(Function function) const;

    private:
        void Parsing(const CoreTools::CSVContent& csvContent);

    private:
        Container chapter;
    };
}

#endif  // C_S_V_CONFIGURE_CHAPTER_CONTAINER_H

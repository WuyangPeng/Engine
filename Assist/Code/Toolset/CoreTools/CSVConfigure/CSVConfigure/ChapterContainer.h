/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

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

        using ConstChapterSharedPtr = std::shared_ptr<const ChapterMappingType>;
        using Container = std::vector<ConstChapterSharedPtr>;
        using CSVContent = CoreTools::CSVContent;

    public:
        explicit ChapterContainer(const CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstChapterSharedPtr GetFirstChapter() const;
        NODISCARD ConstChapterSharedPtr GetChapter(int key) const;
        NODISCARD Container GetContainer() const;

        NODISCARD int GetContainerSize() const;

        template <typename Function>
        NODISCARD ConstChapterSharedPtr GetFirstChapter(Function function) const;

        template <typename Function>
        NODISCARD Container GetChapter(Function function) const;

    private:
        void Parsing(const CSVContent& csvContent);
        void Load(const CSVContent& csvContent);
        void Unique();

    private:
        Container chapter;
    };
}

#endif  // C_S_V_CONFIGURE_CHAPTER_CONTAINER_H
/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef C_S_V_CONFIGURE_CHAPTER_BASE_H
#define C_S_V_CONFIGURE_CHAPTER_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVConfigureFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/Data/IntVector4.h"
#include "CoreTools/TextParsing/Data/Vector2.h"

namespace CSVConfigure
{
    class ChapterBase
    {
    public:
        using ClassType = ChapterBase;

        using String = System::String;

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

        NODISCARD virtual int GetNextId() const noexcept;

        NODISCARD virtual int GetReward() const noexcept;

        NODISCARD virtual String GetChapterName() const;

        NODISCARD virtual bool IsMain() const noexcept;

        NODISCARD virtual CoreTools::Vector2 GetPosition() const noexcept;

        NODISCARD virtual CoreTools::IntVector4 GetPoint() const noexcept;

    private:
        int key{};
    };
}

#endif  // C_S_V_CONFIGURE_CHAPTER_BASE_H

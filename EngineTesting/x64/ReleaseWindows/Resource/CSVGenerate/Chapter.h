/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++17
/// 自动生成

#ifndef C_S_V_CONFIGURE_CHAPTER_H
#define C_S_V_CONFIGURE_CHAPTER_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVConfigureFwd.h"
#include "ChapterBase.h"
#include "System/Helper/UnicodeUsing.h"

namespace CSVConfigure
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

        NODISCARD int GetID() const noexcept override;

        NODISCARD int GetNextID() const noexcept override;

        NODISCARD int GetReward() const noexcept override;

        NODISCARD System::String GetChapterName() const override;

        NODISCARD bool IsMain() const noexcept override;

        NODISCARD CoreTools::Vector2 GetPosition() const noexcept override;

        NODISCARD CoreTools::IntVector4 GetPoint() const noexcept override;

    private:
        void Checking();

    private:
        int id;  // ID
        int nextID;  // 下一关ID
        int reward;  // 过关奖励
        System::String chapterName;  // 关卡名称
        bool isMain;  // 是否主线
        CoreTools::Vector2 position;  // 位置
        CoreTools::IntVector4 point;  // 点
    };
}

#endif  // C_S_V_CONFIGURE_CHAPTER_H

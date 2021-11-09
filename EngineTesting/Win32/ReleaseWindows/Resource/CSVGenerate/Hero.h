/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++17
/// 自动生成

#ifndef C_S_V_CONFIGURE_HERO_H
#define C_S_V_CONFIGURE_HERO_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVConfigureFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/Data/Vector4.h"

#include <vector>

namespace CSVConfigure
{
    class Hero final
    {
    public:
        using ClassType = Hero;

    public:
        explicit Hero(const CoreTools::CSVRow& csvRow);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetKey() const noexcept;

        NODISCARD int GetID() const noexcept;

        NODISCARD int GetNextID() const noexcept;

        NODISCARD int GetReward() const noexcept;

        NODISCARD System::String GetHeroName() const;

        NODISCARD int64_t GetUniqueIdentifier() const noexcept;

        NODISCARD CoreTools::Vector4 GetPosition() const noexcept;

        NODISCARD std::vector<System::TChar> GetDescribe() const;
        NODISCARD int GetDescribeCount() const;
        NODISCARD bool GetDescribe(int index) const;
        NODISCARD std::vector<System::TChar>::const_iterator GetDescribeBegin() const noexcept;
        NODISCARD std::vector<System::TChar>::const_iterator GetDescribeEnd() const noexcept;

    private:
        int id;  // ID
        int nextID;  // 下一关ID
        int reward;  // 过关奖励
        System::String heroName;  // 英雄名称
        int64_t uniqueIdentifier;  // 唯一标识符
        CoreTools::Vector4 position;  // 位置
        std::vector<System::TChar> describe;  // 描述
    };
}

#endif  // C_S_V_CONFIGURE_HERO_H

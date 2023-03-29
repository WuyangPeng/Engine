/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef C_S_V_CONFIGURE_SYSTEM_CONSTANT_H
#define C_S_V_CONFIGURE_SYSTEM_CONSTANT_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVConfigureFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/Data/IntVector3.h"

namespace CSVConfigure
{
    class SystemConstant final
    {
    public:
        using ClassType = SystemConstant;

    public:
        explicit SystemConstant(const CoreTools::CSVRow& csvRow);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetKey() const noexcept;

        NODISCARD int GetId() const noexcept;

        NODISCARD int GetNextId() const noexcept;

        NODISCARD int GetReward() const noexcept;

        NODISCARD System::String GetSkillName() const;

        NODISCARD VectorType GetVectorType() const noexcept;

        NODISCARD CoreTools::IntVector3 GetPosition() const noexcept;

    private:
        int id;  // Id
        int nextId;  // 下一级Id
        int reward;  // 过关奖励
        System::String skillName;  // 技能名称
        VectorType vectorType;  // 向量类型
        CoreTools::IntVector3 position;  // 位置
    };
}

#endif  // C_S_V_CONFIGURE_SYSTEM_CONSTANT_H

/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef C_S_V_CONFIGURE_SKILL_H
#define C_S_V_CONFIGURE_SKILL_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVConfigureFwd.h"
#include "SkillBase.h"
#include "System/Helper/UnicodeUsing.h"

namespace CSVConfigure
{
    class Skill final : public SkillBase
    {
    public:
        using ClassType = Skill;
        using ParentType = SkillBase;

        using CSVRow = CoreTools::CSVRow; 

    public:
        explicit Skill(const CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD int GetNextId() const noexcept override;

        NODISCARD int GetReward() const noexcept override;

        NODISCARD String GetSkillName() const override;

        NODISCARD VectorType GetVectorType() const noexcept override;

        NODISCARD CoreTools::IntVector3 GetPosition() const noexcept override;

        NODISCARD constexpr static int GenerateKey(int id, int reward) noexcept
        {
            return  id * 100 + reward;
        }
    private:
        int id;  // Id
        int nextId;  // 下一级Id
        int reward;  // 过关奖励
        String skillName;  // 技能名称
        VectorType vectorType;  // 向量类型
        CoreTools::IntVector3 position;  // 位置
    };
}

#endif  // C_S_V_CONFIGURE_SKILL_H

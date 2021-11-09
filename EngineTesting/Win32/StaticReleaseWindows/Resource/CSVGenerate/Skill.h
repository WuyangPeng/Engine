/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++17
/// �Զ�����

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

    public:
        explicit Skill(const CoreTools::CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetID() const noexcept override;

        NODISCARD int GetNextID() const noexcept override;

        NODISCARD int GetReward() const noexcept override;

        NODISCARD System::String GetSkillName() const override;

        NODISCARD VectorType GetVectorType() const noexcept override;

        NODISCARD CoreTools::IntVector3 GetPosition() const noexcept override;

        NODISCARD constexpr static int GenerateKey(int id, int reward) noexcept
        {
            return  id * 100 + reward;
        }

    private:
        int id;  // ID
        int nextID;  // ��һ��ID
        int reward;  // ���ؽ���
        System::String skillName;  // ��������
        VectorType vectorType;  // ��������
        CoreTools::IntVector3 position;  // λ��
    };
}

#endif  // C_S_V_CONFIGURE_SKILL_H

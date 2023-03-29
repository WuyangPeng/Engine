/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef C_S_V_CONFIGURE_SKILL_BASE_H
#define C_S_V_CONFIGURE_SKILL_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVConfigureFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/Data/IntVector3.h"

namespace CSVConfigure
{
    class SkillBase
    {
    public:
        using ClassType = SkillBase;

    public:
        SkillBase() noexcept = default;
        explicit SkillBase(int key) noexcept;

        virtual ~SkillBase() noexcept = default;
        SkillBase(const SkillBase& rhs) noexcept = default;
        SkillBase& operator=(const SkillBase& rhs) noexcept = default;
        SkillBase(SkillBase&& rhs) noexcept = default;
        SkillBase& operator=(SkillBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int GetKey() const noexcept;

        NODISCARD virtual int GetId() const noexcept;

        NODISCARD virtual int GetNextId() const noexcept;

        NODISCARD virtual int GetReward() const noexcept;

        NODISCARD virtual System::String GetSkillName() const;

        NODISCARD virtual VectorType GetVectorType() const noexcept;

        NODISCARD virtual CoreTools::IntVector3 GetPosition() const noexcept;

    private:
        int key{};
    };
}

#endif  // C_S_V_CONFIGURE_SKILL_BASE_H

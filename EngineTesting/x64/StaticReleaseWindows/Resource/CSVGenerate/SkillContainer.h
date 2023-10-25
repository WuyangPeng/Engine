/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef C_S_V_CONFIGURE_SKILL_CONTAINER_H
#define C_S_V_CONFIGURE_SKILL_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVConfigureFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace CSVConfigure
{
    class SkillContainer final
    {
    public:
        using ClassType = SkillContainer;

        using ConstSkillSharedPtr = std::shared_ptr<const SkillMappingType>;
        using Container = std::vector<ConstSkillSharedPtr>;
        using CSVContent = CoreTools::CSVContent;

    public:
        explicit SkillContainer(const CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstSkillSharedPtr GetFirstSkill() const;
        NODISCARD ConstSkillSharedPtr GetSkill(int key) const;
        NODISCARD Container GetContainer() const;

        NODISCARD int GetContainerSize() const;

        template <typename Function>
        NODISCARD ConstSkillSharedPtr GetFirstSkill(Function function) const;

        template <typename Function>
        NODISCARD Container GetSkill(Function function) const;

    private:
        void Parsing(const CSVContent& csvContent);
        void Load(const CSVContent& csvContent);
        void Unique();

    private:
        Container skill;
    };
}

#endif  // C_S_V_CONFIGURE_SKILL_CONTAINER_H

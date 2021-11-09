/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++17
/// 自动生成

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
        using ConstSkillBaseSharedPtr = std::shared_ptr<const SkillBase>;
        using Container = std::vector<ConstSkillBaseSharedPtr>;

    public:
        explicit SkillContainer(const CoreTools::CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstSkillBaseSharedPtr GetFirstSkill() const;
        NODISCARD ConstSkillBaseSharedPtr GetSkill(int id, int reward) const;
        NODISCARD ConstSkillBaseSharedPtr GetSkill(int key) const;
        NODISCARD Container GetContainer() const;

        template <typename Function>
        NODISCARD ConstSkillBaseSharedPtr GetFirstSkill(Function function) const;

        template <typename Function>
        NODISCARD Container GetSkill(Function function) const;

    private:
        void Parsing(const CoreTools::CSVContent& csvContent);

    private:
        Container skill;
    };
}

#endif  // C_S_V_CONFIGURE_SKILL_CONTAINER_H

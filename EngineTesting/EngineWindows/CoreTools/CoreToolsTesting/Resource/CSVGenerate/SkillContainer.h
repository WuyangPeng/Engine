/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
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

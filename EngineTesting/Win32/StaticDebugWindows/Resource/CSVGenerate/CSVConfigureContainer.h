/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++17
/// 自动生成

#ifndef C_S_V_CONFIGURE_C_S_V_CONFIGURE_CONTAINER_H
#define C_S_V_CONFIGURE_C_S_V_CONFIGURE_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVConfigureFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>

namespace CSVConfigure
{
    class CSVConfigureContainer final
    {
    public:
        using ClassType = CSVConfigureContainer;

    public:
        explicit CSVConfigureContainer(const System::String& directory);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::shared_ptr<const ChapterContainer> GetChapterContainer() const noexcept;
        NODISCARD std::shared_ptr<const EquipContainer> GetEquipContainer() const noexcept;
        NODISCARD std::shared_ptr<const HeroContainer> GetHeroContainer() const noexcept;
        NODISCARD std::shared_ptr<const SceneContainer> GetSceneContainer() const noexcept;
        NODISCARD std::shared_ptr<const SkillContainer> GetSkillContainer() const noexcept;
        NODISCARD std::shared_ptr<const SystemConstantContainer> GetSystemConstantContainer() const noexcept;

    private:
        void Parsing(const System::String& directory);
        void Verify();

    private:
        std::shared_ptr<const ChapterContainer> chapterContainer;
        std::shared_ptr<const EquipContainer> equipContainer;
        std::shared_ptr<const HeroContainer> heroContainer;
        std::shared_ptr<const SceneContainer> sceneContainer;
        std::shared_ptr<const SkillContainer> skillContainer;
        std::shared_ptr<const SystemConstantContainer> systemConstantContainer;
    };
}

#endif  // C_S_V_CONFIGURE_CONTAINER_H

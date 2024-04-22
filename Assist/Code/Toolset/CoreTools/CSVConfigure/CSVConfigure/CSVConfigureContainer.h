/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef C_S_V_CONFIGURE_C_S_V_CONFIGURE_CONTAINER_H
#define C_S_V_CONFIGURE_C_S_V_CONFIGURE_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVConfigureFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <filesystem>
#include <memory>

namespace CSVConfigure
{
    class CSVConfigureContainer final
    {
    public:
        using ClassType = CSVConfigureContainer;

        using String = System::String;
        using ConstChapterContainerSharedPtr = std::shared_ptr<const ChapterContainer>;
        using ConstEquipContainerSharedPtr = std::shared_ptr<const EquipContainer>;
        using ConstHeroContainerSharedPtr = std::shared_ptr<const HeroContainer>;
        using ConstSceneContainerSharedPtr = std::shared_ptr<const SceneContainer>;
        using ConstSkillContainerSharedPtr = std::shared_ptr<const SkillContainer>;
        using ConstSystemConstantContainerSharedPtr = std::shared_ptr<const SystemConstantContainer>;

    public:
        explicit CSVConfigureContainer(const String& directory);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstChapterContainerSharedPtr GetChapterContainer() const noexcept;
        NODISCARD ConstEquipContainerSharedPtr GetEquipContainer() const noexcept;
        NODISCARD ConstHeroContainerSharedPtr GetHeroContainer() const noexcept;
        NODISCARD ConstSceneContainerSharedPtr GetSceneContainer() const noexcept;
        NODISCARD ConstSkillContainerSharedPtr GetSkillContainer() const noexcept;
        NODISCARD ConstSystemConstantContainerSharedPtr GetSystemConstantContainer() const noexcept;

    private:
        void Parsing(const String& directory);
        void Parsing(const std::filesystem::directory_entry& inputPath);
        void Verify() const;

    private:
        ConstChapterContainerSharedPtr chapterContainer;
        ConstEquipContainerSharedPtr equipContainer;
        ConstHeroContainerSharedPtr heroContainer;
        ConstSceneContainerSharedPtr sceneContainer;
        ConstSkillContainerSharedPtr skillContainer;
        ConstSystemConstantContainerSharedPtr systemConstantContainer;
    };
}

#endif  // C_S_V_CONFIGURE_C_S_V_CONFIGURE_CONTAINER_H
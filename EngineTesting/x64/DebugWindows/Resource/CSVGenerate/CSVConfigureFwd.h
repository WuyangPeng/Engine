/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef C_S_V_CONFIGURE_FWD_H
#define C_S_V_CONFIGURE_FWD_H

#include "CoreTools/TextParsing/TextParsingFwd.h"

namespace CSVConfigure
{
    enum class LineType;
    enum class VectorType;

    class Chapter;
    class ChapterBase;
    class ChapterContainer;
    using ChapterMappingType = ChapterBase;

    class Equip;
    class EquipBase;
    class EquipContainer;
    using EquipMappingType = EquipBase;

    class Hero;
    class HeroContainer;
    using HeroMappingType = Hero;

    class Scene;
    class SceneContainer;
    using SceneMappingType = Scene;

    class Skill;
    class SkillBase;
    class SkillContainer;
    using SkillMappingType = SkillBase;

    class SystemConstant;
    class SystemConstantContainer;
    using SystemConstantMappingType = SystemConstant;

    class CSVConfigureContainer;
}

#endif  // C_S_V_CONFIGURE_FWD_H

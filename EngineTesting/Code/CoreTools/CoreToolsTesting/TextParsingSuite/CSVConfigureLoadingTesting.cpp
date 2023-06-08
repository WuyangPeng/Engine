///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.11 (2023/06/07 22:11)

#include "CSVConfigureLoadingTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/BatchConversionCSV.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/CSVConfigureContainer.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/Chapter.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/ChapterContainerDetail.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/Equip.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/EquipContainerDetail.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/Hero.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/HeroContainerDetail.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/Scene.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/SceneContainerDetail.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/Skill.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/SkillContainerDetail.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/SystemConstant.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/SystemConstantContainer.h"

using namespace std::literals;

CoreTools::CSVConfigureLoadingTesting::CSVConfigureLoadingTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVConfigureLoadingTesting)

void CoreTools::CSVConfigureLoadingTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CSVConfigureLoadingTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CSVConfigureContainerTest);
}

void CoreTools::CSVConfigureLoadingTesting::CSVConfigureContainerTest()
{
    const CSVConfigure::CSVConfigureContainer csvConfigureContainer{ SYSTEM_TEXT("Resource/CSVConfigure"s) };
}

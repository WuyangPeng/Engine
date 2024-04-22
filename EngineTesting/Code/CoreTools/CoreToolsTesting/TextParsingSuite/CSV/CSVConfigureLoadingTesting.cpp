/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 17:27)

#include "CSVConfigureLoadingTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/BatchConversionCSV.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/CSVConfigureContainer.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/ChapterContainerDetail.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/Equip.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/EquipContainerDetail.h"

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
    const CSVConfigure::CSVConfigureContainer csvConfigureContainer{ SYSTEM_TEXT("Resource/CSVConfigure") };
}

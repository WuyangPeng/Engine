///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.3 (2021/04/26 22:11)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "Example/BookOperatingSystem/BookOperatingSystem/Helper/BookOperatingSystemClassInvariantMacro.h"

BookOperatingSystem::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "书籍 操作系统" }
{
    InitSuite();

    BOOK_OPERATING_SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookOperatingSystem, TestingHelper)

void BookOperatingSystem::TestingHelper::InitSuite() noexcept
{
}

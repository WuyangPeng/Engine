///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助测试版本：0.8.0.10 (2022/07/12 18:20)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/ResourceManagerClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

using namespace std::literals;

ResourceManagerExample::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "资源管理例子"s }
{
    InitSuite();

    RESOURCE_MANAGER_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ResourceManagerExample, TestingHelper)

void ResourceManagerExample::TestingHelper::InitSuite() noexcept
{
}

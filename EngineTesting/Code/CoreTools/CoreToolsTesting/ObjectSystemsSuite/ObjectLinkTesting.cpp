///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 15:42)

#include "ObjectLinkTesting.h"
#include "Detail/NullObject.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"

#include <vector>

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, ObjectLinkTesting)

void CoreTools::ObjectLinkTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InsertObjectPtrTest);
}

void CoreTools::ObjectLinkTesting::InsertObjectPtrTest() noexcept
{
}

///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/10 14:42)

#include "EnumResourceToolsWindowsTesting.h"
#include "System/DynamicLink/EnumResourceTools.h"
#include "System/DynamicLink/LoadResourceTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::EnumResourceToolsWindowsTesting::EnumResourceToolsWindowsTesting(const OStreamShared& stream, WindowsHInstance instance)
    : ParentType{ stream }, instance{ instance }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, EnumResourceToolsWindowsTesting)

void System::EnumResourceToolsWindowsTesting::EnumResourceTest()
{
    ASSERT_TRUE(EnumResourceTypesInLibrary(instance, TypeProcess, reinterpret_cast<WindowsLongPtrSizeType>(this)));

    ASSERT_LESS(0u, GetEnumResourceDataSize());

    for (const auto& data : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(EnumResourceExistTest, data);
    }
}

void System::EnumResourceToolsWindowsTesting::EnumResourceExistTest(const EnumResourceData& data)
{
    const auto resource = FindResourceInLibrary(instance, data.GetType(), data.GetName(), data.GetLanguage());

    ASSERT_UNEQUAL_NULL_PTR(resource);
}

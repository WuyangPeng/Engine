///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.3 (2023/03/03 09:12)

#include "FileEvent.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::FileEvent::FileEvent() noexcept
    : ParentType{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, FileEvent)

void CoreTools::FileEvent::EventFunction(const FileAsynchronousParameter& fileAsynchronousParameter, const FileBuffer& fileBuffer) noexcept
{
    System::UnusedFunction(fileAsynchronousParameter, fileBuffer);
}

CoreTools::FileEvent::FileEventInterfaceUniquePtr CoreTools::FileEvent::Create()
{
    return std::make_unique<ClassType>();
}

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/16 16:40)

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
    CORE_TOOLS_CLASS_IS_VALID_1;

    System::UnusedFunction(fileAsynchronousParameter, fileBuffer);
}

CoreTools::FileEvent::FileEventInterfaceUniquePtr CoreTools::FileEvent::Create()
{
    return std::make_unique<ClassType>();
}

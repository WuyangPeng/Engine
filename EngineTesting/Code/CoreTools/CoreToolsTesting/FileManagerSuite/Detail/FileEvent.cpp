///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.3 (2021/09/08 14:21)

#include "FileEvent.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <string>

using std::string;
using namespace std::literals;

CoreTools::FileEvent::FileEvent() noexcept
    : ParentType{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, FileEvent)

void CoreTools::FileEvent::EventFunction(MAYBE_UNUSED const FileAsynchronousParameter& fileAsynchronousParameter, MAYBE_UNUSED const FileBuffer& fileBuffer) noexcept
{
}

CoreTools::FileEvent::FileEventInterfaceUniquePtr CoreTools::FileEvent::Create()
{
    return std::make_unique<ClassType>();
}

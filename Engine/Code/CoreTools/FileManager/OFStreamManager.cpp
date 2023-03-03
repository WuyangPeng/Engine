///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/03/02 11:05)

#include "CoreTools/CoreToolsExport.h"

#include "OFStreamManager.h"
#include "Detail/OFStreamManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::OFStreamManager::OFStreamManager(const String& fileName, bool addition)
    : impl{ fileName, addition }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, OFStreamManager)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, OFStreamManager, GetStreamSize, CoreTools::OFStreamManager::PosType)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, OFStreamManager, SetSimplifiedChinese, void)

CoreTools::OFStreamManager& CoreTools::OFStreamManager::operator<<(const String& message)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    *impl << message;

    return *this;
}

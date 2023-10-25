///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/22 14:13)

#include "CoreTools/CoreToolsExport.h"

#include "OFStreamManager.h"
#include "Detail/OFStreamManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::OFStreamManager::OFStreamManager(const String& fileName, bool addition)
    : impl{ fileName, addition }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, OFStreamManager)

CoreTools::OFStreamManager::PosType CoreTools::OFStreamManager::GetStreamSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetStreamSize();
}

void CoreTools::OFStreamManager::SetSimplifiedChinese()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetSimplifiedChinese();
}

CoreTools::OFStreamManager& CoreTools::OFStreamManager::operator<<(const String& message)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    *impl << message;

    return *this;
}

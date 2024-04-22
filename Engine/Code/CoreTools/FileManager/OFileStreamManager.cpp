/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/01 10:51)

#include "CoreTools/CoreToolsExport.h"

#include "OFileStreamManager.h"
#include "Detail/OFileStreamManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::OFileStreamManager::OFileStreamManager(const String& fileName, bool addition)
    : impl{ fileName, addition }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, OFileStreamManager)

CoreTools::OFileStreamManager::PosType CoreTools::OFileStreamManager::GetStreamSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetStreamSize();
}

void CoreTools::OFileStreamManager::SetSimplifiedChinese()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetSimplifiedChinese();
}

CoreTools::OFileStreamManager& CoreTools::OFileStreamManager::operator<<(const String& message)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    *impl << message;

    return *this;
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/03/02 11:05)

#include "CoreTools/CoreToolsExport.h"

#include "IFStreamManager.h"
#include "Detail/IFStreamManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::IFStreamManager::IFStreamManager(const String& fileName)
    : impl{ fileName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, IFStreamManager)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, IFStreamManager, GetFileContent, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, IFStreamManager, BackupFile, System::String)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, IFStreamManager, SetSimplifiedChinese, void)

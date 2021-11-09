///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.3 (2021/09/03 14:59)

#include "CoreTools/CoreToolsExport.h"

#include "IFStreamManager.h"
#include "Detail/IFStreamManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

CoreTools::IFStreamManager::IFStreamManager(const String& fileName)
    : impl{ fileName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, IFStreamManager)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, IFStreamManager, GetFileContent, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, IFStreamManager, BackupFile, System::String)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, IFStreamManager, SetSimplifiedChinese, void)

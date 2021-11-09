///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.3 (2021/09/03 14:59)

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

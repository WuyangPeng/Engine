//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/14 14:39)

#include "CoreTools/CoreToolsExport.h"

#include "IFStreamManager.h"
#include "Detail/IFStreamManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

CoreTools::IFStreamManager::IFStreamManager(const String& fileName)
    : m_Impl{ make_shared<ImplType>(fileName) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, IFStreamManager)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, IFStreamManager, GetFileContent, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, IFStreamManager, BackupFile, System::String)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, IFStreamManager, SetSimplifiedChinese, void)

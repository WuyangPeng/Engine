///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/17 19:50)

#include "CoreTools/CoreToolsExport.h"

#include "LoadingLibrary.h"
#include "Detail/LoadingLibraryImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::LoadingLibrary::LoadingLibrary(const String& fileName, LoadLibraryType flags)
    : impl{ fileName, flags }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LoadingLibrary)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, LoadingLibrary, GetLoadedModule, CoreTools::LoadingLibrary::DynamicLinkModule)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, LoadingLibrary, GetProcessAddress, std::string, CoreTools::LoadingLibrary::DynamicLinkProcess)

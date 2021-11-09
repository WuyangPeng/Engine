///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.2 (2021/08/26 20:50)

#include "CoreTools/CoreToolsExport.h"

#include "LoadingLibrary.h"
#include "Detail/LoadingLibraryImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::string;

CoreTools::LoadingLibrary::LoadingLibrary(const String& fileName, LoadLibraryType flags)
    : impl{ fileName, flags }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LoadingLibrary)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, LoadingLibrary, GetLoadedModule, CoreTools::LoadingLibrary::DynamicLinkModule)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, LoadingLibrary, GetProcessAddress, string, CoreTools::LoadingLibrary::DynamicLinkProcess)

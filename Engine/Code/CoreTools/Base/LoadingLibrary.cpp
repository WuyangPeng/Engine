//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 11:28)

#include "CoreTools/CoreToolsExport.h"

#include "LoadingLibrary.h"
#include "Detail/LoadingLibraryImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
using std::string;

CoreTools::LoadingLibrary::LoadingLibrary(const String& fileName, LoadLibraryType flags)
    : m_Impl{ make_shared<ImplType>(fileName, flags) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, LoadingLibrary)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, LoadingLibrary, GetLoadedModule, CoreTools::LoadingLibrary::DynamicLinkModule)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, LoadingLibrary, GetProcessAddress, string, CoreTools::LoadingLibrary::DynamicLinkProcess)

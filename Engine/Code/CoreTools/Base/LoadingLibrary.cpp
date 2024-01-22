/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 20:06)

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

CoreTools::LoadingLibrary::DynamicLinkModule CoreTools::LoadingLibrary::GetLoadedModule() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->GetLoadedModule();
}

CoreTools::LoadingLibrary::DynamicLinkProcess CoreTools::LoadingLibrary::GetProcessAddress(const std::string& procName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->GetProcessAddress(procName);
}

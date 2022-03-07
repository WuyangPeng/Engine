///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/07 22:52)

#include "CoreTools/CoreToolsExport.h"

#include "LogFileName.h"
#include "Detail/LogFileNameImpl.h"
#include "System/SystemOutput/OutputDebugString.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

CoreTools::LogFileName::LogFileName(const System::TChar* fileName) noexcept
    : impl{}
{
    try
    {
        impl = make_shared<ImplType>(fileName);
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogFileName抛出异常"));
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LogFileName)

CoreTools::LogFileName::String CoreTools::LogFileName::GetFileName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (impl != nullptr)
    {
        return impl->GetFileName();
    }
    else
    {
        return String{};
    }
}

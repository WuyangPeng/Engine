///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/28 16:11)

#include "CoreTools/CoreToolsExport.h"

#include "LogFileName.h"
#include "Detail/LogFileNameImpl.h"
#include "System/SystemOutput/OutputDebugString.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::LogFileName::LogFileName(const System::TChar* fileName) noexcept
    : impl{}
{
    try
    {
        impl = std::make_shared<ImplType>(fileName);
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

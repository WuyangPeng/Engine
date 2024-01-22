/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 00:43)

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
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogFileName�׳��쳣"));
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

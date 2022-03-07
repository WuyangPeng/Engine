///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/07 22:38)

#include "CoreTools/CoreToolsExport.h"

#include "LogFileNameImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::LogFileNameImpl::LogFileNameImpl(const String& fileName)
    : fileName{ fileName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LogFileNameImpl)

System::String CoreTools::LogFileNameImpl::GetFileName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return fileName;
}

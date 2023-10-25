///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:57)

#include "CoreTools/CoreToolsExport.h"

#include "PrintFileNameLogMessage.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/LogManager/Log.h"
#include "CoreTools/LogManager/LogMessage.h"

CoreTools::PrintFileNameLogMessage::PrintFileNameLogMessage(const LogFileName& fileName, LogLevel level, LogFilter filter, const FunctionDescribed& functionDescribed) noexcept
    : ParentType{ level, filter, functionDescribed }, fileName{ fileName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, PrintFileNameLogMessage)

CoreTools::LogMessageImpl::LogMessageImplSharedPtr CoreTools::PrintFileNameLogMessage::Clone() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

System::String CoreTools::PrintFileNameLogMessage::GetFileName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return fileName.GetFileName();
}
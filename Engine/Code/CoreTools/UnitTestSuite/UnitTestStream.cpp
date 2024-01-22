/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 11:24)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestStream.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::UnitTestStream::UnitTestStream(const OStreamShared& streamShared) noexcept
    : streamShared{ streamShared }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::UnitTestStream::UnitTestStream(UnitTestStream&& rhs) noexcept
    : streamShared{ std::move(rhs.streamShared) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::UnitTestStream& CoreTools::UnitTestStream::operator=(UnitTestStream&& rhs) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (this != &rhs)
    {
        streamShared = std::move(rhs.streamShared);
    }

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, UnitTestStream)

CoreTools::OStreamShared& CoreTools::UnitTestStream::GetStream() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return streamShared;
}

bool CoreTools::UnitTestStream::IsStreamSharedFile() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return streamShared.IsFile();
}

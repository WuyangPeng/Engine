/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 11:23)

#include "CoreTools/CoreToolsExport.h"

#include "OStreamImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <fstream>

CoreTools::OStreamImpl::OStreamImpl(bool isCout) noexcept
    : stream{}, isCout{ isCout }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::OStreamImpl::OStreamImpl(const std::string& fileName)
    : stream{ make_shared<std::ofstream>(fileName, std::ofstream::out | std::ofstream::app) }, isCout{ false }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::OStreamImpl::OStreamImpl(OStreamImpl&& rhs) noexcept
    : stream{ std::move(rhs.stream) }, isCout{ rhs.isCout }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::OStreamImpl& CoreTools::OStreamImpl::operator=(OStreamImpl&& rhs) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (this != &rhs)
    {
        stream = std::move(rhs.stream);
        isCout = rhs.isCout;
    }

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, OStreamImpl)

std::ostream& CoreTools::OStreamImpl::GetStream() noexcept
{
    if (stream)
        return *stream;
    else if (isCout)
        return std::cout;
    else
        return std::cerr;
}

bool CoreTools::OStreamImpl::IsCout() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return isCout;
}

bool CoreTools::OStreamImpl::IsCerr() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (stream)
        return false;
    else
        return !isCout;
}

bool CoreTools::OStreamImpl::IsFile() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (stream)
        return true;
    else
        return false;
}

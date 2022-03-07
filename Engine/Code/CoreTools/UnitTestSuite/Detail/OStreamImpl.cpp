///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/14 21:26)

#include "CoreTools/CoreToolsExport.h"

#include "OStreamImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <fstream>

using std::cerr;
using std::cout;
using std::make_shared;
using std::ofstream;
using std::ostream;
using std::string;

CoreTools::OStreamImpl::OStreamImpl(bool isCout) noexcept
    : stream{}, isCout{ isCout }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::OStreamImpl::OStreamImpl(const string& fileName)
    : stream{ make_shared<ofstream>(fileName, ofstream::out | ofstream::app) }, isCout{ false }
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

ostream& CoreTools::OStreamImpl::GetStream() noexcept
{
    if (stream)
        return *stream;
    else if (isCout)
        return cout;
    else
        return cerr;
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

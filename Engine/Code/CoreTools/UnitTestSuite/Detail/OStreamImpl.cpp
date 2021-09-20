//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/23 14:41)

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
    : m_OStream{}, m_IsCout{ isCout }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::OStreamImpl::OStreamImpl(const string& fileName)
    : m_OStream{ make_shared<ofstream>(fileName, ofstream::out | ofstream::app) }, m_IsCout{ false }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, OStreamImpl)

ostream& CoreTools::OStreamImpl::GetStream() noexcept
{
    if (m_OStream)
    {
        return *m_OStream;
    }
    else
    {
        if (m_IsCout)
            return cout;
        else
            return cerr;
    }
}

bool CoreTools::OStreamImpl::IsCout() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_IsCout;
}

bool CoreTools::OStreamImpl::IsCerr() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (m_OStream)
    {
        return false;
    }
    else
    {
        return !m_IsCout;
    }
}

bool CoreTools::OStreamImpl::IsFile() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (m_OStream)
    {
        return true;
    }
    else
    {
        return false;
    }
}

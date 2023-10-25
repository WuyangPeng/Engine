///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 14:14)

#include "CoreTools/CoreToolsExport.h"

#include "OStreamShared.h"
#include "Detail/OStreamImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::OStreamShared::OStreamShared(bool isCout)
    : impl{ isCout }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::OStreamShared::OStreamShared(const std::string& fileName)
    : impl{ fileName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, OStreamShared)

std::ostream& CoreTools::OStreamShared::GetStream() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->GetStream();
}

bool CoreTools::OStreamShared::IsCout() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->IsCout();
}

bool CoreTools::OStreamShared::IsCerr() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->IsCerr();
}

bool CoreTools::OStreamShared::IsFile() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->IsFile();
}

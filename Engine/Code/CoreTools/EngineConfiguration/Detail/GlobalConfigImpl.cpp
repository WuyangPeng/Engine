/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/09 16:41)

#include "CoreTools/CoreToolsExport.h"

#include "GlobalConfigImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::GlobalConfigImpl::GlobalConfigImpl() noexcept
    : describe{},
      suffix{},
      publicSuffix{},
      domainName{},
      gameSuffix{},
      portShifting{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, GlobalConfigImpl)

System::String CoreTools::GlobalConfigImpl::GetDescribe() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return describe;
}

System::String CoreTools::GlobalConfigImpl::GetSuffix() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return suffix;
}

System::String CoreTools::GlobalConfigImpl::GetPublicSuffix() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return publicSuffix;
}

System::String CoreTools::GlobalConfigImpl::GetDomainName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return domainName;
}

System::String CoreTools::GlobalConfigImpl::GetGameSuffix() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return gameSuffix;
}

int CoreTools::GlobalConfigImpl::GetPortShifting() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return portShifting;
}

void CoreTools::GlobalConfigImpl::SetDescribe(const String& aDescribe)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    describe = aDescribe;
}

void CoreTools::GlobalConfigImpl::SetSuffix(const String& aSuffix)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    suffix = aSuffix;
}

void CoreTools::GlobalConfigImpl::SetPublicSuffix(const String& aPublicSuffix)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    publicSuffix = aPublicSuffix;
}

void CoreTools::GlobalConfigImpl::SetDomainName(const String& aDomainName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    domainName = aDomainName;
}

void CoreTools::GlobalConfigImpl::SetGameSuffix(const String& aGameSuffix)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    gameSuffix = aGameSuffix;
}

void CoreTools::GlobalConfigImpl::SetPortShifting(int aPortShifting) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    portShifting = aPortShifting;
}
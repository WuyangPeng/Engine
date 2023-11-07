///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 15:33)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectManagerImpl.h"
#include "CoreTools/Base/Flags/UniqueIdSelect.h"
#include "CoreTools/Base/UniqueIdManager.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::ObjectManagerImpl::ObjectManagerImpl() noexcept
    : factories{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ObjectManagerImpl)

CoreTools::ObjectManagerImpl::FactoryFunction CoreTools::ObjectManagerImpl::Find(const std::string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (const auto iter = factories.find(name); iter != factories.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("找不到指定的工厂函数！"s))
    }
}

void CoreTools::ObjectManagerImpl::Insert(const std::string& name, FactoryFunction function)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    factories.emplace(name, function);
}

void CoreTools::ObjectManagerImpl::Remove(const std::string& name) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    factories.erase(name);
}

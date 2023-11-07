///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/20 15:33)

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
        THROW_EXCEPTION(SYSTEM_TEXT("�Ҳ���ָ���Ĺ���������"s))
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

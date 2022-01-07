///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/24 23:01)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectManagerImpl.h"
#include "CoreTools/Base/Flags/UniqueIDSelectFlags.h"
#include "CoreTools/Base/UniqueIDManager.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::string;

CoreTools::ObjectManagerImpl::ObjectManagerImpl() noexcept
    : factories{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ObjectManagerImpl)

CoreTools::ObjectManagerImpl::FactoryFunction CoreTools::ObjectManagerImpl::Find(const string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto iter = factories.find(name);
    if (iter != factories.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�Ҳ���ָ���Ĺ���������"s));
    }
}

void CoreTools::ObjectManagerImpl::Insert(const string& name, FactoryFunction function)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    factories.insert({ name, function });
}

void CoreTools::ObjectManagerImpl::Remove(const string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    factories.erase(name);
}

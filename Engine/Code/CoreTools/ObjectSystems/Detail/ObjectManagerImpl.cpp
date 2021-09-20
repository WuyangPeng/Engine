//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/22 14:56)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectManagerImpl.h"
#include "CoreTools/Base/Flags/UniqueIDSelectFlags.h"
#include "CoreTools/Base/UniqueIDManager.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::make_pair;
using std::string;

CoreTools::ObjectManagerImpl::ObjectManagerImpl(MAYBE_UNUSED int count) noexcept
    : m_Factories{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ObjectManagerImpl)

CoreTools::ObjectManagerImpl::FactoryFunction CoreTools::ObjectManagerImpl::Find(const string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto iter = m_Factories.find(name);
    if (iter != m_Factories.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("找不到指定的工厂函数！"s));
    }
}

void CoreTools::ObjectManagerImpl::Insert(const string& name, FactoryFunction function)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_Factories.insert({ name, function });
}

void CoreTools::ObjectManagerImpl::Remove(const string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_Factories.erase(name);
}

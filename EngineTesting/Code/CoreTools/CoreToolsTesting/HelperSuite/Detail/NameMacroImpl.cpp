///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/18 16:07)

#include "NameMacroImpl.h"
#include "TestingObject.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;
using std::string;

CoreTools::NameMacroImpl::NameMacroImpl(int count) noexcept
    : count{ count }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, NameMacroImpl)

const CoreTools::ObjectSharedPtr CoreTools::NameMacroImpl::GetObjectByName(const string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return make_shared<TestingObject>(name);
}

const CoreTools::NameMacroImpl::ObjectSharedPtrContainer CoreTools::NameMacroImpl::GetAllObjectsByName(const string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ObjectSharedPtrContainer result{};

    result.emplace_back(make_shared<TestingObject>(name));

    return result;
}

const CoreTools::ConstObjectSharedPtr CoreTools::NameMacroImpl::GetConstObjectByName(const string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return make_shared<TestingObject>(name);
}

const CoreTools::NameMacroImpl::ConstObjectSharedPtrContainer CoreTools::NameMacroImpl::GetAllConstObjectsByName(const string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    ConstObjectSharedPtrContainer result{};

    result.emplace_back(make_shared<TestingObject>(name));

    return result;
}

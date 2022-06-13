///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:23)

#include "NameMacroBase.h"
#include "TestingObject.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;
using std::string;

CoreTools::NameMacroBase::NameMacroBase() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, NameMacroBase)

CoreTools::ObjectSharedPtr CoreTools::NameMacroBase::GetObjectByName(const string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return make_shared<TestingObject>(name);
}

CoreTools::NameMacroBase::ObjectSharedPtrContainer CoreTools::NameMacroBase::GetAllObjectsByName(const string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ObjectSharedPtrContainer result{};

    result.emplace_back(make_shared<TestingObject>(name));

    return result;
}

CoreTools::ConstObjectSharedPtr CoreTools::NameMacroBase::GetConstObjectByName(const string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return make_shared<TestingObject>(name);
}

CoreTools::NameMacroBase::ConstObjectSharedPtrContainer CoreTools::NameMacroBase::GetAllConstObjectsByName(const string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    ConstObjectSharedPtrContainer result{};

    result.emplace_back(make_shared<TestingObject>(name));

    return result;
}
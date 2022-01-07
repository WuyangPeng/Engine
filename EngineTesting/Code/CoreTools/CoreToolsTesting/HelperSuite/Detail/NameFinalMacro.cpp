///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/18 17:01)

#include "NameFinalMacro.h"
#include "TestingObject.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;
using std::string;

CoreTools::NameFinalMacro::NameFinalMacro(const string& name)
    : ParentType{ name }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, NameFinalMacro)

CoreTools::ObjectInterfaceSharedPtr CoreTools::NameFinalMacro::CloneObject() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return make_shared<ClassType>(*this);
}

CoreTools::ObjectSharedPtr CoreTools::NameFinalMacro::GetObjectByName(const string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return make_shared<TestingObject>(name);
}

CoreTools::NameFinalMacro::ObjectSharedPtrContainer CoreTools::NameFinalMacro::GetAllObjectsByName(const string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ObjectSharedPtrContainer result{};

    result.emplace_back(make_shared<TestingObject>(name));

    return result;
}

CoreTools::ConstObjectSharedPtr CoreTools::NameFinalMacro::GetConstObjectByName(const string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return make_shared<TestingObject>(name);
}

CoreTools::NameFinalMacro::ConstObjectSharedPtrContainer CoreTools::NameFinalMacro::GetAllConstObjectsByName(const string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    ConstObjectSharedPtrContainer result{};

    result.emplace_back(make_shared<TestingObject>(name));

    return result;
}

CoreTools::NameMacro::NameMacroSharedPtr CoreTools::NameFinalMacro::Create(const string& name)
{
    return make_shared<ClassType>(name);
}
/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/13 21:16)

#include "NameFinalMacro.h"
#include "TestingObject.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::NameFinalMacro::NameFinalMacro(const std::string& name)
    : ParentType{ name }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, NameFinalMacro)

CoreTools::ObjectInterfaceSharedPtr CoreTools::NameFinalMacro::CloneObject() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

CoreTools::ObjectSharedPtr CoreTools::NameFinalMacro::GetObjectByName(const std::string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return std::make_shared<TestingObject>(name);
}

CoreTools::NameFinalMacro::ObjectSharedPtrContainer CoreTools::NameFinalMacro::GetAllObjectsByName(const std::string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    ObjectSharedPtrContainer result{ std::make_shared<TestingObject>(name) };

    return result;
}

CoreTools::ConstObjectSharedPtr CoreTools::NameFinalMacro::GetConstObjectByName(const std::string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return std::make_shared<TestingObject>(name);
}

CoreTools::NameFinalMacro::ConstObjectSharedPtrContainer CoreTools::NameFinalMacro::GetAllConstObjectsByName(const std::string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    ConstObjectSharedPtrContainer result{ std::make_shared<TestingObject>(name) };

    return result;
}

CoreTools::NameMacro::NameMacroSharedPtr CoreTools::NameFinalMacro::Create(const std::string& name)
{
    return std::make_shared<ClassType>(name);
}
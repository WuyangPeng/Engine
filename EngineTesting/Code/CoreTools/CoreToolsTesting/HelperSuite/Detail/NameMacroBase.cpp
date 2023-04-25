///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/11 21:03)

#include "NameMacroBase.h"
#include "TestingObject.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::NameMacroBase::NameMacroBase() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, NameMacroBase)

CoreTools::ObjectSharedPtr CoreTools::NameMacroBase::GetObjectByName(const std::string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return std::make_shared<TestingObject>(name);
}

CoreTools::NameMacroBase::ObjectSharedPtrContainer CoreTools::NameMacroBase::GetAllObjectsByName(const std::string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ObjectSharedPtrContainer result{ std::make_shared<TestingObject>(name) };

    return result;
}

CoreTools::ConstObjectSharedPtr CoreTools::NameMacroBase::GetConstObjectByName(const std::string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return std::make_shared<TestingObject>(name);
}

CoreTools::NameMacroBase::ConstObjectSharedPtrContainer CoreTools::NameMacroBase::GetAllConstObjectsByName(const std::string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    ConstObjectSharedPtrContainer result{ std::make_shared<TestingObject>(name) };

    return result;
}
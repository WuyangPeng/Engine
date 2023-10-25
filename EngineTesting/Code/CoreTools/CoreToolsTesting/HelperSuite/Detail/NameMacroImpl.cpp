///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 15:38)

#include "NameMacroImpl.h"
#include "TestingObject.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::NameMacroImpl::NameMacroImpl() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, NameMacroImpl)

CoreTools::ObjectSharedPtr CoreTools::NameMacroImpl::GetObjectByName(const std::string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return std::make_shared<TestingObject>(name);
}

CoreTools::NameMacroImpl::ObjectSharedPtrContainer CoreTools::NameMacroImpl::GetAllObjectsByName(const std::string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ObjectSharedPtrContainer result{ std::make_shared<TestingObject>(name) };

    return result;
}

CoreTools::ConstObjectSharedPtr CoreTools::NameMacroImpl::GetConstObjectByName(const std::string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return std::make_shared<TestingObject>(name);
}

CoreTools::NameMacroImpl::ConstObjectSharedPtrContainer CoreTools::NameMacroImpl::GetAllConstObjectsByName(const std::string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    ConstObjectSharedPtrContainer result{ std::make_shared<TestingObject>(name) };

    return result;
}

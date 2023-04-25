///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 21:03)

#include "NameMacro.h"
#include "NameMacroImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::NameMacro::NameMacro(const std::string& name)
    : ParentType{ name }, impl{ ImplCreateUseDefaultConstruction::Default }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, NameMacro)

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, NameMacro)

CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(CoreTools, NameMacro)

CoreTools::NameMacro::NameMacroSharedPtr CoreTools::NameMacro::Create(const std::string& name)
{
    return std::make_shared<ClassType>(name);
}

CoreTools::ObjectInterfaceSharedPtr CoreTools::NameMacro::CloneObject() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

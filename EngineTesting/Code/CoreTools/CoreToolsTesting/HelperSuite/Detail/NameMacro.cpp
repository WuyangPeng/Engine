///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:23)

#include "NameMacro.h"
#include "NameMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;
using std::string;

CoreTools::NameMacro::NameMacro(const string& name)
    : ParentType{ name }, impl{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, NameMacro)

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, NameMacro)

CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(CoreTools, NameMacro)

CoreTools::NameMacro::NameMacroSharedPtr CoreTools::NameMacro::Create(const string& name)
{
    return make_shared<ClassType>(name);
}

CoreTools::ObjectInterfaceSharedPtr CoreTools::NameMacro::CloneObject() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return make_shared<ClassType>(*this);
}

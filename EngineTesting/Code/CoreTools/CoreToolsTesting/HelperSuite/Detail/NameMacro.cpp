///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/18 17:01)

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
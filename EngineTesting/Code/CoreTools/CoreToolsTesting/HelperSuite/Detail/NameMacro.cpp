/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/13 21:15)

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
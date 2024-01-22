/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 10:00)

#include "CoreTools/CoreToolsExport.h"

#include "NullObject.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

CORE_TOOLS_RTTI_DEFINE(CoreTools, NullObject);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, NullObject);
CORE_TOOLS_FACTORY_DEFINE(CoreTools, NullObject);

CoreTools::NullObject::NullObject(DisableNotThrow disableNotThrow)
    : ParentType{ "NullObject" }
{
    System::UnusedFunction(disableNotThrow);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::NullObject::NullObject(LoadConstructor value)
    : ParentType{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, NullObject);

CoreTools::ObjectInterfaceSharedPtr CoreTools::NullObject::CloneObject() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

bool CoreTools::NullObject::IsNullObject() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return true;
}

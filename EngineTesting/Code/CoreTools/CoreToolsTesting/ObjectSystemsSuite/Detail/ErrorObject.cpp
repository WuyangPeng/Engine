/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/22 16:50)

#include "ErrorObject.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

CoreTools::ErrorObject::ErrorObject(DisableNotThrow disableNotThrow)
    : ParentType{ "ErrorObject" }
{
    System::UnusedFunction(disableNotThrow);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ErrorObject)

CORE_TOOLS_RTTI_DEFINE(CoreTools, ErrorObject);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, ErrorObject);
CORE_TOOLS_FACTORY_DEFINE(CoreTools, ErrorObject);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(CoreTools, ErrorObject);

CoreTools::ObjectInterfaceSharedPtr CoreTools::ErrorObject::CloneObject() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

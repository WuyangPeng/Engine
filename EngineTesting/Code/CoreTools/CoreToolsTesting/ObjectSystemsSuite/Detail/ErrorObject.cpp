///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 14:33)

#include "ErrorObject.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

CoreTools::ErrorObject::ErrorObject(MAYBE_UNUSED DisableNotThrow disableNotThrow)
    : ParentType{ "ErrorObject" }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ErrorObject)

CORE_TOOLS_RTTI_DEFINE(CoreTools, ErrorObject);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, ErrorObject);
CORE_TOOLS_FACTORY_DEFINE(CoreTools, ErrorObject);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(CoreTools, ErrorObject);

CoreTools::ObjectInterfaceSharedPtr CoreTools::ErrorObject::CloneObject() const
{
    return std::make_shared<ClassType>(*this);
}

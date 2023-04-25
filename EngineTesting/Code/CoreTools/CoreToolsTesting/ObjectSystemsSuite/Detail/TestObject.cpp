///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/18 16:03)

#include "TestObject.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLink.h"
#include "CoreTools/ObjectSystems/ObjectRegister.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

CoreTools::TestObject::TestObjectSharedPtr CoreTools::TestObject::Create()
{
    return std::make_shared<ClassType>(DisableNotThrow::Disable);
}

CoreTools::TestObject::TestObject(DisableNotThrow disableNotThrow)
    : ParentType{ "TestObject" }
{
    System::UnusedFunction(disableNotThrow);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, TestObject)

CORE_TOOLS_RTTI_DEFINE(CoreTools, TestObject);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, TestObject);
CORE_TOOLS_FACTORY_DEFINE(CoreTools, TestObject);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(CoreTools, TestObject);

CoreTools::ObjectInterfaceSharedPtr CoreTools::TestObject::CloneObject() const
{
    return std::make_shared<ClassType>(*this);
}

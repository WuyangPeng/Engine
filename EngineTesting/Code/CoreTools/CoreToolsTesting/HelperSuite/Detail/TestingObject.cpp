///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 21:04)

#include "TestingObject.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

CORE_TOOLS_RTTI_DEFINE(CoreTools, TestingObject);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, TestingObject);
CORE_TOOLS_FACTORY_DEFINE(CoreTools, TestingObject);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(CoreTools, TestingObject);

CoreTools::TestingObject::TestingObject(const std::string& name)
    : ParentType{ name }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, TestingObject);

CoreTools::ObjectInterfaceSharedPtr CoreTools::TestingObject::CloneObject() const
{
    return std::make_shared<ClassType>(*this);
}

CoreTools::TestingObject::ObjectSharedPtr CoreTools::TestingObject::Create(const std::string& name)
{
    return std::make_shared<ClassType>(name);
}

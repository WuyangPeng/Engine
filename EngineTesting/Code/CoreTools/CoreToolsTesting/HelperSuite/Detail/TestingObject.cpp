///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:24)

#include "TestingObject.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

using std::make_shared;
using std::string;

CORE_TOOLS_RTTI_DEFINE(CoreTools, TestingObject);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, TestingObject);
CORE_TOOLS_FACTORY_DEFINE(CoreTools, TestingObject);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(CoreTools, TestingObject);

CoreTools::TestingObject::TestingObject(const string& name)
    : ParentType{ name }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, TestingObject);

CoreTools::ObjectInterfaceSharedPtr CoreTools::TestingObject::CloneObject() const
{
    return make_shared<ClassType>(*this);
}

CoreTools::TestingObject::ObjectSharedPtr CoreTools::TestingObject::Create(const string& name)
{
    return make_shared<ClassType>(name);
}

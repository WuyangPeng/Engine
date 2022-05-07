///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/19 15:10)

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
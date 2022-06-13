///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:22)

#include "DefaultTestingObjectPtr.h"
#include "TestingNoObjectPtrImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

using std::make_shared;
using std::string;

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, DefaultTestingObjectPtr);

CORE_TOOLS_RTTI_DEFINE(CoreTools, DefaultTestingObjectPtr);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, DefaultTestingObjectPtr);
CORE_TOOLS_FACTORY_DEFINE(CoreTools, DefaultTestingObjectPtr);

CoreTools::DefaultTestingObjectPtr::DefaultTestingObjectPtr(const string& name)
    : ParentType{ name }, impl{ ImplCreateUseDefaultConstruction::Default }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::DefaultTestingObjectPtr::ObjectSharedPtr CoreTools::DefaultTestingObjectPtr::Create(const string& name)
{
    return make_shared<ClassType>(name);
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, DefaultTestingObjectPtr);

CORE_TOOLS_IMPL_OBJECT_PTR_DEFAULT_STREAM(CoreTools, DefaultTestingObjectPtr);

CoreTools::ObjectInterfaceSharedPtr CoreTools::DefaultTestingObjectPtr::CloneObject() const
{
    return make_shared<ClassType>(*this);
}

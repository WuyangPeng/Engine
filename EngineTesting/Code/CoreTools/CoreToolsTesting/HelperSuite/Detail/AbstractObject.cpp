///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/18 16:33)

#include "AbstractObject.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

using std::string;

CORE_TOOLS_RTTI_DEFINE(CoreTools, AbstractObject);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, AbstractObject);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(CoreTools, AbstractObject);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(CoreTools, AbstractObject);

CoreTools::AbstractObject::AbstractObject(const string& name)
    : ParentType{ name }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::AbstractObject::~AbstractObject()
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, AbstractObject);

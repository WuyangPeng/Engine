/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/14 11:36)

#include "AbstractObject.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

CORE_TOOLS_RTTI_DEFINE(CoreTools, AbstractObject);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, AbstractObject);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(CoreTools, AbstractObject);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(CoreTools, AbstractObject);

CoreTools::AbstractObject::AbstractObject(const std::string& name)
    : ParentType{ name }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::AbstractObject::~AbstractObject() = default;

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, AbstractObject);

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/06 19:23)

#ifndef CORE_TOOLS_HELPER_SUITE_ABSTRACT_OBJECT_H
#define CORE_TOOLS_HELPER_SUITE_ABSTRACT_OBJECT_H

#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/Object.h"

namespace CoreTools
{
    class AbstractObject : public Object
    {
    public:
        using ClassType = AbstractObject;
        using ParentType = Object;

    public:
        explicit AbstractObject(const std::string& name);
        virtual ~AbstractObject() noexcept = 0;

        AbstractObject(const AbstractObject& rhs) = default;
        AbstractObject& operator=(const AbstractObject& rhs) = default;
        AbstractObject(AbstractObject&& rhs) noexcept = default;
        AbstractObject& operator=(AbstractObject&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(AbstractObject);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(AbstractObject);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(AbstractObject);
    CORE_TOOLS_WEAK_PTR_DECLARE(AbstractObject);
}

#endif  // CORE_TOOLS_HELPER_SUITE_ABSTRACT_OBJECT_H
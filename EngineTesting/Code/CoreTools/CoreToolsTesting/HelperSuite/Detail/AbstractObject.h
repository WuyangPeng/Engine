///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:13)

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
        virtual ~AbstractObject() = 0;

        AbstractObject(const AbstractObject& rhs) = default;
        AbstractObject& operator=(const AbstractObject& rhs) = default;
        AbstractObject(AbstractObject&& rhs) noexcept = default;
        AbstractObject& operator=(AbstractObject&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(AbstractObject);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(AbstractObject);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(AbstractObject);
    CORE_TOOLS_WEAK_PTR_DECLARE(AbstractObject);
}

#endif  // CORE_TOOLS_HELPER_SUITE_ABSTRACT_OBJECT_H
/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/14 11:31)

#ifndef CORE_TOOLS_HELPER_SUITE_TESTING_OBJECT_H
#define CORE_TOOLS_HELPER_SUITE_TESTING_OBJECT_H

#include "AbstractObject.h"

namespace CoreTools
{
    class TestingObject final : public AbstractObject
    {
    public:
        using ClassType = TestingObject;
        using ParentType = AbstractObject;

        using ObjectSharedPtr = std::shared_ptr<ClassType>;

    public:
        explicit TestingObject(const std::string& name);

        NODISCARD static ObjectSharedPtr Create(const std::string& name);

        CLASS_INVARIANT_FINAL_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(TestingObject);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(TestingObject);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(TestingObject);
}

#endif  // CORE_TOOLS_HELPER_SUITE_TESTING_OBJECT_H
/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/14 11:31)

#ifndef CORE_TOOLS_HELPER_SUITE_TESTING_OBJECT_SIZE_H
#define CORE_TOOLS_HELPER_SUITE_TESTING_OBJECT_SIZE_H

#include "AbstractObject.h"

namespace CoreTools
{
    class TestingObjectSize final : public AbstractObject
    {
    public:
        using ClassType = TestingObjectSize;
        using ParentType = AbstractObject;

        using ObjectSharedPtr = std::shared_ptr<ClassType>;

    public:
        explicit TestingObjectSize(int value);

        NODISCARD static ObjectSharedPtr Create(int value);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(TestingObjectSize);

        NODISCARD int GetTestValue() const noexcept;

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        int testValue;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(TestingObjectSize);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(TestingObjectSize);
}

#endif  // CORE_TOOLS_HELPER_SUITE_TESTING_OBJECT_SIZE_H
///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/19 15:08)

#ifndef CORE_TOOLS_HELPER_SUITE_TESTING_OBJECT_SIZE_H
#define CORE_TOOLS_HELPER_SUITE_TESTING_OBJECT_SIZE_H

#include "AbstractObject.h"

namespace CoreTools
{
    class TestingObjectSize : public AbstractObject
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

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(TestingObjectSize);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(TestingObjectSize);
}

#endif  // CORE_TOOLS_HELPER_SUITE_TESTING_OBJECT_SIZE_H
///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/18 16:39)

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

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const final;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(TestingObject);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(TestingObject);
}

#endif  // CORE_TOOLS_HELPER_SUITE_TESTING_OBJECT_H
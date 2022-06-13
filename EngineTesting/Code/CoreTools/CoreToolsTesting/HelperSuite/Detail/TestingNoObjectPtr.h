///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:16)

#ifndef CORE_TOOLS_HELPER_SUITE_TESTING_NO_OBJECT_PTR_H
#define CORE_TOOLS_HELPER_SUITE_TESTING_NO_OBJECT_PTR_H

#include "AbstractObject.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

namespace CoreTools
{
    class TestingNoObjectPtrImpl;

    class TestingNoObjectPtr : public AbstractObject
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(TestingNoObjectPtr);
        using ParentType = AbstractObject;
        using ObjectSharedPtr = std::shared_ptr<ClassType>;

    public:
        explicit TestingNoObjectPtr(const std::string& name);

        NODISCARD static ObjectSharedPtr Create(const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(TestingNoObjectPtr);
        CORE_TOOLS_OBJECT_STREAM_OVERRIDE_DECLARE;
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(TestingNoObjectPtr);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(TestingNoObjectPtr);
}

#endif  // CORE_TOOLS_HELPER_SUITE_TESTING_NO_OBJECT_PTR_H
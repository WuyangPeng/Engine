///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/19 14:35)

#ifndef CORE_TOOLS_HELPER_SUITE_DEFAULT_TESTING_NO_OBJECT_PTR_H
#define CORE_TOOLS_HELPER_SUITE_DEFAULT_TESTING_NO_OBJECT_PTR_H

#include "AbstractObject.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

namespace CoreTools
{
    class TestingNoObjectPtrImpl;

    class DefaultTestingNoObjectPtr : public AbstractObject
    {
    public:
        using DefaultTestingNoObjectPtrImpl = TestingNoObjectPtrImpl;
        COPY_UNSHARED_TYPE_DECLARE(DefaultTestingNoObjectPtr);
        using ParentType = AbstractObject;
        using ObjectSharedPtr = std::shared_ptr<ClassType>;

    public:
        explicit DefaultTestingNoObjectPtr(const std::string& name);

        NODISCARD static ObjectSharedPtr Create(const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(DefaultTestingNoObjectPtr);

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(DefaultTestingNoObjectPtr);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(DefaultTestingNoObjectPtr);
}

#endif  // CORE_TOOLS_HELPER_SUITE_DEFAULT_TESTING_NO_OBJECT_PTR_H
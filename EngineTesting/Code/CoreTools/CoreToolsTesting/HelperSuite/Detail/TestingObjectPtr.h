///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/19 15:07)

#ifndef CORE_TOOLS_HELPER_SUITE_TESTING_OBJECT_PTR_H
#define CORE_TOOLS_HELPER_SUITE_TESTING_OBJECT_PTR_H

#include "AbstractObject.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

namespace CoreTools
{
    class TestingNoObjectPtrImpl;

    class TestingObjectPtr : public AbstractObject
    {
    public:
        using TestingObjectPtrImpl = TestingNoObjectPtrImpl;
        COPY_UNSHARED_TYPE_DECLARE(TestingObjectPtr);
        using ParentType = AbstractObject;
        using ObjectSharedPtr = std::shared_ptr<ClassType>;

    public:
        explicit TestingObjectPtr(const std::string& name);

        NODISCARD static ObjectSharedPtr Create(const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(TestingObjectPtr);

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(TestingObjectPtr);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(TestingObjectPtr);
}

#endif  // CORE_TOOLS_HELPER_SUITE_TESTING_OBJECT_PTR_H
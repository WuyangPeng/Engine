/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/14 11:30)

#ifndef CORE_TOOLS_HELPER_SUITE_DEFAULT_TESTING_OBJECT_PTR_H
#define CORE_TOOLS_HELPER_SUITE_DEFAULT_TESTING_OBJECT_PTR_H

#include "AbstractObject.h"
#include "CoreTools/CoreToolsTesting/HelperSuite/HelperSuiteFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

namespace CoreTools
{
    class DefaultTestingObjectPtr final : public AbstractObject
    {
    public:
        using DefaultTestingObjectPtrImpl = TestingNoObjectPtrImpl;
        using ParentType = AbstractObject;

        COPY_UNSHARED_TYPE_DECLARE(DefaultTestingObjectPtr);
        using ObjectSharedPtr = std::shared_ptr<ClassType>;

    public:
        explicit DefaultTestingObjectPtr(const std::string& name);

        NODISCARD static ObjectSharedPtr Create(const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(DefaultTestingObjectPtr);

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(DefaultTestingObjectPtr);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(DefaultTestingObjectPtr);
}

#endif  // CORE_TOOLS_HELPER_SUITE_DEFAULT_TESTING_OBJECT_PTR_H
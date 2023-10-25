///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 15:34)

#ifndef CORE_TOOLS_HELPER_SUITE_DEFAULT_TESTING_NO_OBJECT_PTR_H
#define CORE_TOOLS_HELPER_SUITE_DEFAULT_TESTING_NO_OBJECT_PTR_H

#include "AbstractObject.h"
#include "CoreTools/CoreToolsTesting/HelperSuite/HelperSuiteFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

namespace CoreTools
{
    class DefaultTestingNoObjectPtr final : public AbstractObject
    {
    public:
        using DefaultTestingNoObjectPtrImpl = TestingNoObjectPtrImpl;
        using ParentType = AbstractObject;

        COPY_UNSHARED_TYPE_DECLARE(DefaultTestingNoObjectPtr);
        using ObjectSharedPtr = std::shared_ptr<ClassType>;

    public:
        DefaultTestingNoObjectPtr(const std::string& name, LoadConstructor loadConstructor);

        NODISCARD static ObjectSharedPtr Create(const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(DefaultTestingNoObjectPtr);

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(DefaultTestingNoObjectPtr);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(DefaultTestingNoObjectPtr);
}

#endif  // CORE_TOOLS_HELPER_SUITE_DEFAULT_TESTING_NO_OBJECT_PTR_H
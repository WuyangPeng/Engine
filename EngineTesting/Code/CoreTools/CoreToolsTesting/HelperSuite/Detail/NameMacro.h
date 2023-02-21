///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/16 20:46)

#ifndef CORE_TOOLS_HELPER_SUITE_NAME_MACRO_H
#define CORE_TOOLS_HELPER_SUITE_NAME_MACRO_H

#include "CoreTools/CoreToolsTesting/HelperSuite/HelperSuiteFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/ObjectSystems/Object.h"

namespace CoreTools
{
    class NameMacro : public Object
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(NameMacro);
        using ParentType = Object;
        using NameMacroSharedPtr = std::shared_ptr<ClassType>;

    public:
        explicit NameMacro(const std::string& name);

        NODISCARD static NameMacroSharedPtr Create(const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_NAME_MACRO_H
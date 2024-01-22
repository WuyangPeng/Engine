/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 09:56)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_NAME_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_NAME_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Contract/ImplStaticAssertHelper.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

CORE_TOOLS_DELAY_COPY_UNSHARED_EXPORT_IMPL(ObjectName, ObjectNameImpl);

namespace CoreTools
{
    // Object类的名字
    class CORE_TOOLS_DEFAULT_DECLARE ObjectName final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(ObjectName);

    public:
        explicit ObjectName(const std::string& name);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetName() const;
        NODISCARD bool IsExactly(const ObjectName& name) const noexcept;

        void SetName(const std::string& name);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_NAME_H

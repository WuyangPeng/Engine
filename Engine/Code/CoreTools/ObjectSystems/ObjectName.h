//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.2 (2020/09/11 13:00)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_NAME_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_NAME_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(ObjectNameImpl);

namespace CoreTools
{
    // Object类的名字
    class CORE_TOOLS_DEFAULT_DECLARE ObjectName
    {
    public:
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(ObjectName);

    public:
        explicit ObjectName(const std::string& name);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] std::string GetName() const;
        [[nodiscard]] bool IsExactly(const ObjectName& name) const noexcept;

        void SetName(const std::string& name);

    private:
        IMPL_TYPE_DECLARE(ObjectName);
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_NAME_H

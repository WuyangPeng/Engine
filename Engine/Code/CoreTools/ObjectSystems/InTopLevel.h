///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 15:26)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_IN_TOP_LEVEL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_IN_TOP_LEVEL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "ObjectInterface.h"
#include "ObjectType.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"

CORE_TOOLS_DELAY_COPY_UNSHARED_EXPORT_IMPL(InTopLevel, InTopLevelImpl);

// 被加载的顶层对象。
namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE InTopLevel final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(InTopLevel);

    public:
        NODISCARD static InTopLevel Create();

    private:
        explicit InTopLevel(DisableNotThrow disableNotThrow);

    public:
        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsTopLevel(const ObjectInterfaceSharedPtr& object) const;
        NODISCARD int GetTopLevelSize() const;

        NODISCARD ObjectContainerConstIter begin() const noexcept;
        NODISCARD ObjectContainerConstIter end() const noexcept;

        NODISCARD ObjectContainerIter begin();
        NODISCARD ObjectContainerIter end();

        // 对顶层的对象进行保存。
        void Insert(const ObjectInterfaceSharedPtr& object);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_IN_TOP_LEVEL_H

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/24 21:46)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OUT_TOP_LEVEL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OUT_TOP_LEVEL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "ObjectInterface.h"
#include "ObjectType.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"

CORE_TOOLS_DELAY_COPY_UNSHARED_EXPORT_IMPL(OutTopLevel, OutTopLevelImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE OutTopLevel final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(OutTopLevel);

    public:
        NODISCARD static OutTopLevel Create();

    private:
        explicit OutTopLevel(MAYBE_UNUSED DisableNotThrow disableNotThrow);

    public:
        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsTopLevel(const ConstObjectInterfaceSharedPtr& object) const;
        NODISCARD int GetTopLevelSize() const;

        NODISCARD ConstObjectContainerConstIter begin() const noexcept;
        NODISCARD ConstObjectContainerConstIter end() const noexcept;

        // 对顶层的对象进行保存。
        void Insert(const ObjectInterfaceSharedPtr& object);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OUT_TOP_LEVEL_H

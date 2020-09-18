//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.2 (2020/09/15 10:34)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OUT_TOP_LEVEL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OUT_TOP_LEVEL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "ObjectInterface.h"
#include "ObjectType.h"

CORE_TOOLS_EXPORT_SHARED_PTR(OutTopLevelImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE OutTopLevel
    {
    public:
        DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(OutTopLevel);

    public:
        OutTopLevel();

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] bool IsTopLevel(const ConstObjectInterfaceSharedPtr& object) const;
        [[nodiscard]] int GetTopLevelSize() const;

        [[nodiscard]] ConstObjectContainerConstIter begin() const noexcept;
        [[nodiscard]] ConstObjectContainerConstIter end() const noexcept;

        // 对顶层的对象进行保存。
        void Insert(const ObjectInterfaceSharedPtr& object);

    private:
        IMPL_TYPE_DECLARE(OutTopLevel);
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OUT_TOP_LEVEL_H

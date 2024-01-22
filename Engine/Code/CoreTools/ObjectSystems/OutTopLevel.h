/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 09:56)

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
        explicit OutTopLevel(DisableNotThrow disableNotThrow);

    public:
        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsTopLevel(const ConstObjectInterfaceSharedPtr& object) const;
        NODISCARD int GetTopLevelSize() const;

        NODISCARD ConstObjectContainerConstIter begin() const noexcept;
        NODISCARD ConstObjectContainerConstIter end() const noexcept;

        // �Զ���Ķ�����б��档
        void Insert(const ObjectInterfaceSharedPtr& object);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OUT_TOP_LEVEL_H

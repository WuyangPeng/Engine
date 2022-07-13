///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 14:10)

#ifndef EXPORT_TEST_ANIMATION_TEST_EXPORT_COPY_MACRO_H
#define EXPORT_TEST_ANIMATION_TEST_EXPORT_COPY_MACRO_H

#include "Animation/AnimationDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

EXPORT_SHARED_PTR(Animation, AnimationTestExportCopyMacroImpl, ANIMATION_DEFAULT_DECLARE);
ANIMATION_COPY_EXPORT(AnimationTestExportCopyMacro, AnimationTestExportCopyMacroImpl, COPY_UNSHARED);

namespace Animation
{
    class ANIMATION_DEFAULT_DECLARE AnimationTestExportCopyMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(AnimationTestExportCopyMacro);

    public:
        explicit AnimationTestExportCopyMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_ANIMATION_TEST_EXPORT_COPY_MACRO_H
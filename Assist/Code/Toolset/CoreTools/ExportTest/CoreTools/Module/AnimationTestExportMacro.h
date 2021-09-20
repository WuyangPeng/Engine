///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 16:54)

#ifndef EXPORT_TEST_ANIMATION_TEST_EXPORT_MACRO_H
#define EXPORT_TEST_ANIMATION_TEST_EXPORT_MACRO_H

#include "Animation/AnimationDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

EXPORT_SHARED_PTR(Animation, AnimationTestExportMacroImpl, ANIMATION_DEFAULT_DECLARE);
ANIMATION_EXPORT(AnimationTestExportMacroImpl, NON_COPY);
ANIMATION_EXPORT_UNIQUE_PTR(AnimationTestExportMacro);

namespace Animation
{
    class ANIMATION_DEFAULT_DECLARE AnimationTestExportMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(AnimationTestExportMacro);

    public:
        explicit AnimationTestExportMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_ANIMATION_TEST_EXPORT_MACRO_H
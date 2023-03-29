///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/17 15:32)

#ifndef EXPORT_TEST_ANIMATION_COPY_UNSHARED_MACRO_H
#define EXPORT_TEST_ANIMATION_COPY_UNSHARED_MACRO_H

#include "Animation/AnimationDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

ANIMATION_COPY_UNSHARED_EXPORT_IMPL(AnimationCopyUnsharedMacro, AnimationCopyUnsharedMacroImpl);

namespace Animation
{
    class ANIMATION_DEFAULT_DECLARE AnimationCopyUnsharedMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(AnimationCopyUnsharedMacro);

    public:
        explicit AnimationCopyUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_ANIMATION_COPY_UNSHARED_MACRO_H
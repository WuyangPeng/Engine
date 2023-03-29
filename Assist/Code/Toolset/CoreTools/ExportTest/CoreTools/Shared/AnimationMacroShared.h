///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/17 14:19)

#ifndef EXPORT_TEST_ANIMATION_MACRO_SHARED_H
#define EXPORT_TEST_ANIMATION_MACRO_SHARED_H

#include "Animation/AnimationDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/SharedExportMacro.h"

ANIMATION_SHARED_EXPORT_IMPL(AnimationMacroSharedImpl);

namespace Animation
{
    class ANIMATION_DEFAULT_DECLARE AnimationMacroShared final
    {
    public:
        SHARED_TYPE_DECLARE(AnimationMacroShared);

    public:
        explicit AnimationMacroShared(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_ANIMATION_MACRO_SHARED_H
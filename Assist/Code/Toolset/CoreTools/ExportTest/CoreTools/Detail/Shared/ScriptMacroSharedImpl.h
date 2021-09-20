///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.1 (2021/08/12 16:51)

#ifndef EXPORT_TEST_SCRIPT_MACRO_SHARED_IMPL_H
#define EXPORT_TEST_SCRIPT_MACRO_SHARED_IMPL_H

#include "Script/ScriptDll.h"

namespace Script
{
    class SCRIPT_HIDDEN_DECLARE ScriptMacroSharedImpl final
    {
    public:
        using ClassType = ScriptMacroSharedImpl;

    public:
        explicit ScriptMacroSharedImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        int m_Count;
    };
}

#endif  // EXPORT_TEST_SCRIPT_MACRO_SHARED_IMPL_H
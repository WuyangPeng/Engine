///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.1 (2021/08/11 13:56)

#ifndef EXPORT_TEST_COPY_UNSHARED_USE_CLONE_MACRO_IMPL_H
#define EXPORT_TEST_COPY_UNSHARED_USE_CLONE_MACRO_IMPL_H

#include "Toolset/CoreTools/ExportTest/ExportTestDll.h"

#include "CoreTools/Helper/UserMacro.h"

#include <memory>

namespace ExportTest
{
    class EXPORT_TEST_HIDDEN_DECLARE CopyUnsharedUseCloneMacroImpl final
    {
    public:
        using ClassType = CopyUnsharedUseCloneMacroImpl;
        using SharedPtr = std::shared_ptr<ClassType>;

    public:
        explicit CopyUnsharedUseCloneMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

        NODISCARD SharedPtr Clone() const;

    private:
        int m_Count;
    };
}

#endif  // EXPORT_TEST_COPY_UNSHARED_USE_CLONE_MACRO_IMPL_H
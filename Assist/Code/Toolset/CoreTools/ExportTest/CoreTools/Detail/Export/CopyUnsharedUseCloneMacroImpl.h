///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 22:15)

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
        int mCount;
    };
}

#endif  // EXPORT_TEST_COPY_UNSHARED_USE_CLONE_MACRO_IMPL_H
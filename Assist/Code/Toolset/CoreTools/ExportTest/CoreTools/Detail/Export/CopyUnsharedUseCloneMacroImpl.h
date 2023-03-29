///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/17 15:12)

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
        void SetCount(int aCount) noexcept;

        NODISCARD SharedPtr Clone() const;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_COPY_UNSHARED_USE_CLONE_MACRO_IMPL_H
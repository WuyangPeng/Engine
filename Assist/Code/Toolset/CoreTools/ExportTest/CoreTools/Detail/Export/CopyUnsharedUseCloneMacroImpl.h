///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/11 13:56)

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
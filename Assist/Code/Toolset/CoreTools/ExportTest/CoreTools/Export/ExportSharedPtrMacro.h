///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 16:53)

#ifndef EXPORT_TEST_EXPORT_SHARED_PTR_MACRO_H
#define EXPORT_TEST_EXPORT_SHARED_PTR_MACRO_H

#include "Toolset/CoreTools/ExportTest/ExportTestDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/ExportMacro.h"

EXPORT_SHARED_PTR(ExportTest, ExportSharedPtrMacroImpl, EXPORT_TEST_DEFAULT_DECLARE);
EXPORT_CONST_SHARED_PTR(ExportTest, ExportSharedPtrMacroImpl, EXPORT_TEST_DEFAULT_DECLARE);

namespace ExportTest
{
    class EXPORT_TEST_DEFAULT_DECLARE ExportSharedPtrMacro final
    {
    public:
        TYPE_DECLARE(ExportSharedPtrMacro);

    public:
        explicit ExportSharedPtrMacro(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_DECLARE;

    private:
        using ImplTypePtr = std::shared_ptr<ImplType>;
        using ConstImplTypePtr = std::shared_ptr<const ImplType>;

    private:
        ImplTypePtr impl;
        ConstImplTypePtr constImpl;
    };
}

#endif  // EXPORT_TEST_TEST_EXPORT_MACRO_H
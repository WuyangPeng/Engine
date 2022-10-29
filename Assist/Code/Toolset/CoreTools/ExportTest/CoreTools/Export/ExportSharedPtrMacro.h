///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/17 23:58)

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
        using DisableNotThrow = CoreTools::DisableNotThrow;

    public:
        explicit ExportSharedPtrMacro(DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_DECLARE;

    private:
        using ImplTypeSharedPtr = std::shared_ptr<ImplType>;
        using ConstImplTypeSharedPtr = std::shared_ptr<const ImplType>;

    private:
        ImplTypeSharedPtr impl;
        ConstImplTypeSharedPtr constImpl;
    };
}

#endif  // EXPORT_TEST_TEST_EXPORT_MACRO_H
///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 17:08)

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
        NODISCARD static ExportSharedPtrMacro Create();

        CLASS_INVARIANT_DECLARE;

    private:
        using ImplTypeSharedPtr = std::shared_ptr<ImplType>;
        using ConstImplTypeSharedPtr = std::shared_ptr<const ImplType>;

    private:
        explicit ExportSharedPtrMacro(DisableNotThrow disableNotThrow);

    private:
        ImplTypeSharedPtr impl;
        ConstImplTypeSharedPtr constImpl;
    };
}

#endif  // EXPORT_TEST_TEST_EXPORT_MACRO_H
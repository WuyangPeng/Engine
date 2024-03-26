/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:48)

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
        NODISCARD static ExportSharedPtrMacro Create();

        CLASS_INVARIANT_DECLARE;

    private:
        using DisableNotThrow = CoreTools::DisableNotThrow;
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
///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/03/28 12:58)

#ifndef APPLIED_CRYPTOGRAPHY_PLACEHOLDER_PLACEHOLDER_H
#define APPLIED_CRYPTOGRAPHY_PLACEHOLDER_PLACEHOLDER_H

#include "Example/BookCpp/AppliedCryptography/AppliedCryptographyDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace AppliedCryptography
{
    class APPLIED_CRYPTOGRAPHY_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // APPLIED_CRYPTOGRAPHY_PLACEHOLDER_PLACEHOLDER_H

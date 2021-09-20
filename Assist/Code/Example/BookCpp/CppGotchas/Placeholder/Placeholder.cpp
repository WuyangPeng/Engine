///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.1 (2021/01/08 21:29)

#include "Example/BookCpp/CppGotchas/CppGotchasExport.h"

#include "Example/BookCpp/CppGotchas/Helper/CppGotchasClassInvariantMacro.h"
#include "Placeholder.h"

CppGotchas::Placeholder::Placeholder() noexcept
{
    CPP_GOTCHAS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CppGotchas, Placeholder)

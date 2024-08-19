/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/19 10:20)

#ifndef FRAMEWORK_SMTP_SMTP_TRANSPORT_IMPL_H
#define FRAMEWORK_SMTP_SMTP_TRANSPORT_IMPL_H

#include "Framework/FrameworkDll.h"

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE SmtpTransportImpl
    {
    public:
        using ClassType = SmtpTransportImpl;

    public:
        SmtpTransportImpl() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // FRAMEWORK_SMTP_SMTP_TRANSPORT_IMPL_H
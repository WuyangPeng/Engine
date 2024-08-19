/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/19 10:20)

#ifndef FRAMEWORK_SMTP_SMTP_TRANSPORT_H
#define FRAMEWORK_SMTP_SMTP_TRANSPORT_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

FRAMEWORK_NON_COPY_EXPORT_IMPL(SmtpTransportImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE SmtpTransport
    {
    public:
        NON_COPY_TYPE_DECLARE(SmtpTransport);

    public:
        explicit SmtpTransport(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_DECLARE;

    private:
        PackageType impl;
    };
}

#endif  // FRAMEWORK_SMTP_SMTP_TRANSPORT_H
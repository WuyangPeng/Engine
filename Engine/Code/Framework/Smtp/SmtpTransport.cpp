/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/19 10:20)

#include "Framework/FrameworkExport.h"

#include "SmtpTransport.h"
#include "Detail/SmtpTransportImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::SmtpTransport::SmtpTransport(const EnvironmentDirectory& environmentDirectory)
    : impl{ environmentDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, SmtpTransport)

void Framework::SmtpTransport::SendMailMessage(const std::string& title, const std::string& content)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SendMailMessage(title, content);
}
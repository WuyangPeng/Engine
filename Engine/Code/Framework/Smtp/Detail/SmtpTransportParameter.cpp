/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.1 (2024/09/19 20:01)

#include "Framework/FrameworkExport.h"

#include "SmtpTransportParameter.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::SmtpTransportParameter::SmtpTransportParameter(std::string title, std::string content) noexcept
    : title{ std::move(title) }, content{ std::move(content) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, SmtpTransportParameter)

std::string Framework::SmtpTransportParameter::GetTitle() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return title;
}

std::string Framework::SmtpTransportParameter::GetContent() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return content;
}
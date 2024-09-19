/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.1 (2024/09/19 20:00)

#ifndef FRAMEWORK_SMTP_SMTP_TRANSPORT_PARAMETER_H
#define FRAMEWORK_SMTP_SMTP_TRANSPORT_PARAMETER_H

#include "Framework/FrameworkDll.h"

#include <string>

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE SmtpTransportParameter
    {
    public:
        using ClassType = SmtpTransportParameter;

    public:
        SmtpTransportParameter(std::string title, std::string content) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetTitle() const;
        NODISCARD std::string GetContent() const;

    private:
        std::string title;
        std::string content;
    };
}

#endif  // FRAMEWORK_SMTP_SMTP_TRANSPORT_PARAMETER_H
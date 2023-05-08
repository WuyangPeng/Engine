///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.7 (2023/04/28 10:58)

#ifndef NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_PARAMETER_H
#define NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_PARAMETER_H

#include "Network/NetworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <set>
#include <string>

NETWORK_DELAY_COPY_UNSHARED_EXPORT_IMPL(ConfigurationParameter, ConfigurationParameterImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE ConfigurationParameter final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(ConfigurationParameter);
        using String = System::String;
        using Parameter = std::set<System::String>;

    public:
        NODISCARD static ConfigurationParameter Create();

    private:
        explicit ConfigurationParameter(CoreTools::DisableNotThrow disableNotThrow);

    public:
        CLASS_INVARIANT_DECLARE;

        void AddParameter(const String& key, const String& parameter);
        NODISCARD bool IsParameterExist(const String& key, const String& parameter) const;
        NODISCARD Parameter GetParameter(const String& key) const;

    private:
        PackageType impl;
    };
}

#endif  // NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_PARAMETER_H

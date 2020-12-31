//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 18:18)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_ASIO_CONNECT_H
#define SYSTEM_HELPER_PRAGMA_WARNING_ASIO_CONNECT_H

#include "System/Helper/PragmaWarning.h"

#include STSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(4996)
#include SYSTEM_WARNING_DISABLE(26051)
#include SYSTEM_WARNING_DISABLE(26432)
#include SYSTEM_WARNING_DISABLE(26439)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26460)
#include SYSTEM_WARNING_DISABLE(26465)
#include SYSTEM_WARNING_DISABLE(26487)
#include SYSTEM_WARNING_DISABLE(26819)

#include <boost/asio/connect.hpp>

#include STSTEM_WARNING_POP

#endif  // SYSTEM_HELPER_PRAGMA_WARNING_ASIO_CONNECT_H

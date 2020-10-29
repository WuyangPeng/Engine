//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 14:50)

#include "Network/NetworkExport.h"

#include "NetworkInternal.h"

using namespace std::literals;

const System::String Network::GetACELogName()
{
    static System::String aceNetwork{ SYSTEM_TEXT("ACENetwork"s) };

    return aceNetwork;
}

const System::String Network::GetBoostLogName()
{
    static System::String boostNetwork{ SYSTEM_TEXT("BoostNetwork"s) };

    return boostNetwork;

     
}

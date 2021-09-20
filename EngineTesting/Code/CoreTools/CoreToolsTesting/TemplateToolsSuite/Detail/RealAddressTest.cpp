// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ²âÊÔ°æ±¾£º0.0.2.3 (2020/03/06 15:55)

#include "RealAddressTest.h"

#include "CoreTools/Helper/ClassInvariantMacro.h"

CoreTools::RealAddressTestAddress* CoreTools::RealAddressTest ::operator&() noexcept
{
    return nullptr;
}

const CoreTools::RealAddressTestAddress* CoreTools::RealAddressTest ::operator&() const noexcept
{
    return nullptr;
}

volatile CoreTools::RealAddressTestAddress* CoreTools::RealAddressTest ::operator&() volatile noexcept
{
    return nullptr;
}
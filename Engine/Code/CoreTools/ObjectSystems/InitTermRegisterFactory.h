// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 15:38)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_REGISTER_FACTORY_H
#define CORE_TOOLS_OBJECT_SYSTEMS_REGISTER_FACTORY_H

#include "CoreTools/CoreToolsDll.h"

#include "InitTerm.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE InitTermRegisterFactory
    {
    public:
        using ClassType = InitTermRegisterFactory;
        using Factory = void (*)();

    public:
        InitTermRegisterFactory(Factory initializa, Factory terminate)
        {
            InitTerm::AddInitializer(initializa);
            InitTerm::AddTerminator(terminate);
        }
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_REGISTER_FACTORY_H

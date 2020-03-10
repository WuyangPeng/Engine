// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/18 10:52)

#ifndef CORE_TOOLS_HELPER_TEMPLATE_TOOLS_MACRO_H
#define CORE_TOOLS_HELPER_TEMPLATE_TOOLS_MACRO_H

#define TRIGONOMETRIC_VARIABLE_DEFINE(variableName,radian) \
	    extern double variableName;	double variableName { radian };  

#define SINE_SPECIALIZATION_DEFINE(variableName,radian) \
	    extern double variableName; double variableName { radian }; \
	    namespace CoreTools { template<>  struct SineSeries<variableName,0,0> \
        { static double Value() { return 1.0; } }; }		

#endif // CORE_TOOLS_HELPER_TEMPLATE_TOOLS_MACRO_H

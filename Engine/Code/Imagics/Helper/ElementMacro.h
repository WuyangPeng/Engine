// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 13:56)

#ifndef IMAGICS_IMAGICS_MACRO_ELEMENT_MACRO_H
#define IMAGICS_IMAGICS_MACRO_ELEMENT_MACRO_H

// Wrappers for native types.
#define IMAGICS_DECL_ELEMENT(T) \
        class IMAGICS_DEFAULT_DECLARE E##T { public: \
        E##T (T value = 0) noexcept { mValue = value; } \
        operator T () noexcept { return mValue; } \
        static int GetRTTI () noexcept { return msRTTI; } \
        protected: T mValue; static const int msRTTI; }

#define IMAGICS_IMPL_ELEMENT(T,rtti) \
	    const int Imagics::E##T::msRTTI = rtti
 
#endif // IMAGICS_IMAGICS_MACRO_ELEMENT_MACRO_H

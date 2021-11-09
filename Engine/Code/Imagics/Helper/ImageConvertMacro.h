
// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 13:56)

#ifndef IMAGICS_IMAGICS_MACRO_IMAGE_CONVERT_MACRO_H
#define IMAGICS_IMAGICS_MACRO_IMAGE_CONVERT_MACRO_H

#include <gsl/util>

#define IMAGICS_IMAGE_CONVERTER(SrcType, TrgType)                        \
    static void SrcType##To##TrgType(int quantity, void* src, void* trg) \
    {                                                                    \
        SrcType* tSrc = (SrcType*)src;                                   \
        TrgType* tTrg = (TrgType*)trg;                                   \
        for (int i = 0; i < quantity; ++i, ++tSrc, ++tTrg)               \
        {                                                                \
            *tTrg = gsl::narrow_cast<TrgType>(*tSrc);                    \
        }                                                                \
    }

#define IMAGICS_IMAGE_ENTRY(SrcType, TrgType) SrcType##To##TrgType

#endif  // IMAGICS_IMAGICS_MACRO_IMAGE_CONVERT_MACRO_H

// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/30 13:56)

#ifndef IMAGICS_IMAGICS_MACRO_IMAGE_CONVERT_MACRO_H
#define IMAGICS_IMAGICS_MACRO_IMAGE_CONVERT_MACRO_H 

#define IMAGICS_IMAGE_CONVERTER(SrcType,TrgType) \
		static void SrcType##To##TrgType (int quantity, void* src, void* trg) \
        { SrcType* tSrc = (SrcType*)src; TrgType* tTrg = (TrgType*)trg; \
        for (int i = 0; i < quantity; ++i, ++tSrc, ++tTrg) { *tTrg = (TrgType)(*tSrc); } }

#define IMAGICS_IMAGE_ENTRY(SrcType,TrgType) SrcType##To##TrgType

#endif // IMAGICS_IMAGICS_MACRO_IMAGE_CONVERT_MACRO_H

//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 17:49)

#ifndef SYSTEM_HELPER_GL_EXT_EXTENSIONS_MACRO_H
#define SYSTEM_HELPER_GL_EXT_EXTENSIONS_MACRO_H

#include "System/Helper/GLExtensionsMacro.h"

// (EXT 001) GL_EXT_abgr

#define GL_ABGR_EXT 0x8000

// (EXT 002) GL_EXT_blend_color

#define GL_CONSTANT_COLOR_EXT 0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR_EXT 0x8002
#define GL_CONSTANT_ALPHA_EXT 0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA_EXT 0x8004
#define GL_BLEND_COLOR_EXT 0x8005

#define glBlendColorEXT System::GlBlendColorEXT

// (EXT 003) GL_EXT_polygon_offset

#define GL_POLYGON_OFFSET_EXT 0x8037
#define GL_POLYGON_OFFSET_FACTOR_EXT 0x8038
#define GL_POLYGON_OFFSET_BIAS_EXT 0x8039

#define glPolygonOffsetEXT System::GlPolygonOffsetEXT

// (EXT 004) GL_EXT_texture

#define GL_ALPHA4_EXT 0x803B
#define GL_ALPHA8_EXT 0x803C
#define GL_ALPHA12_EXT 0x803D
#define GL_ALPHA16_EXT 0x803E
#define GL_LUMINANCE4_EXT 0x803F
#define GL_LUMINANCE8_EXT 0x8040
#define GL_LUMINANCE12_EXT 0x8041
#define GL_LUMINANCE16_EXT 0x8042
#define GL_LUMINANCE4_ALPHA4_EXT 0x8043
#define GL_LUMINANCE6_ALPHA2_EXT 0x8044
#define GL_LUMINANCE8_ALPHA8_EXT 0x8045
#define GL_LUMINANCE12_ALPHA4_EXT 0x8046
#define GL_LUMINANCE12_ALPHA12_EXT 0x8047
#define GL_LUMINANCE16_ALPHA16_EXT 0x8048
#define GL_INTENSITY_EXT 0x8049
#define GL_INTENSITY4_EXT 0x804A
#define GL_INTENSITY8_EXT 0x804B
#define GL_INTENSITY12_EXT 0x804C
#define GL_INTENSITY16_EXT 0x804D
#define GL_RGB2_EXT 0x804E
#define GL_RGB4_EXT 0x804F
#define GL_RGB5_EXT 0x8050
#define GL_RGB8_EXT 0x8051
#define GL_RGB10_EXT 0x8052
#define GL_RGB12_EXT 0x8053
#define GL_RGB16_EXT 0x8054
#define GL_RGBA2_EXT 0x8055
#define GL_RGBA4_EXT 0x8056
#define GL_RGB5_A1_EXT 0x8057
#define GL_RGBA8_EXT 0x8058
#define GL_RGB10_A2_EXT 0x8059
#define GL_RGBA12_EXT 0x805A
#define GL_RGBA16_EXT 0x805B
#define GL_TEXTURE_RED_SIZE_EXT 0x805C
#define GL_TEXTURE_GREEN_SIZE_EXT 0x805D
#define GL_TEXTURE_BLUE_SIZE_EXT 0x805E
#define GL_TEXTURE_ALPHA_SIZE_EXT 0x805F
#define GL_TEXTURE_LUMINANCE_SIZE_EXT 0x8060
#define GL_TEXTURE_INTENSITY_SIZE_EXT 0x8061
#define GL_REPLACE_EXT 0x8062
#define GL_PROXY_TEXTURE_1D_EXT 0x8063
#define GL_PROXY_TEXTURE_2D_EXT 0x8064
#define GL_TEXTURE_TOO_LARGE_EXT 0x8065

// (EXT 006) GL_EXT_texture3D

#define GL_PACK_SKIP_IMAGES_EXT 0x806B
#define GL_PACK_IMAGE_HEIGHT_EXT 0x806C
#define GL_UNPACK_SKIP_IMAGES_EXT 0x806D
#define GL_UNPACK_IMAGE_HEIGHT_EXT 0x806E
#define GL_TEXTURE_3D_EXT 0x806F
#define GL_PROXY_TEXTURE_3D_EXT 0x8070
#define GL_TEXTURE_DEPTH_EXT 0x8071
#define GL_TEXTURE_WRAP_R_EXT 0x8072
#define GL_MAX_3D_TEXTURE_SIZE_EXT 0x8073

#define glTexImage3DEXT System::GlTexImage3DEXT
#define glTexSubImage3DEXT System::GlTexSubImage3DEXT

// (EXT 009) GL_EXT_subtexture

#define glTexSubImage1DEXT System::GlTexSubImage1DEXT
#define glTexSubImage2DEXT System::GlTexSubImage2DEXT

// (EXT 010) GL_EXT_copy_texture

#define glCopyTexImage1DEXT System::GlCopyTexImage1DEXT
#define glCopyTexImage2DEXT System::GlCopyTexImage2DEXT
#define glCopyTexSubImage1DEXT System::GlCopyTexSubImage1DEXT
#define glCopyTexSubImage2DEXT System::GlCopyTexSubImage2DEXT
#define glCopyTexSubImage3DEXT System::GlCopyTexSubImage3DEXT

// (EXT 011) GL_EXT_histogram

#define GL_HISTOGRAM_EXT 0x8024
#define GL_PROXY_HISTOGRAM_EXT 0x8025
#define GL_HISTOGRAM_WIDTH_EXT 0x8026
#define GL_HISTOGRAM_FORMAT_EXT 0x8027
#define GL_HISTOGRAM_RED_SIZE_EXT 0x8028
#define GL_HISTOGRAM_GREEN_SIZE_EXT 0x8029
#define GL_HISTOGRAM_BLUE_SIZE_EXT 0x802A
#define GL_HISTOGRAM_ALPHA_SIZE_EXT 0x802B
#define GL_HISTOGRAM_LUMINANCE_SIZE_EXT 0x802C
#define GL_HISTOGRAM_SINK_EXT 0x802D
#define GL_MINMAX_EXT 0x802E
#define GL_MINMAX_FORMAT_EXT 0x802F
#define GL_MINMAX_SINK_EXT 0x8030
#define GL_TABLE_TOO_LARGE_EXT 0x8031

#define glGetHistogramEXT System::GlGetHistogramEXT
#define glGetHistogramParameterfvEXT System::GlGetHistogramParameterfvEXT
#define glGetHistogramParameterivEXT System::GlGetHistogramParameterivEXT
#define glGetMinmaxEXT System::GlGetMinmaxEXT
#define glGetMinmaxParameterfvEXT System::GlGetMinmaxParameterfvEXT
#define glGetMinmaxParameterivEXT System::GlGetMinmaxParameterivEXT
#define glHistogramEXT System::GlHistogramEXT
#define glMinmaxEXT System::GlMinmaxEXT
#define glResetHistogramEXT System::GlResetHistogramEXT
#define glResetMinmaxEXT System::GlResetMinmaxEXT

// (EXT 012) GL_EXT_convolution

#define GL_CONVOLUTION_1D_EXT 0x8010
#define GL_CONVOLUTION_2D_EXT 0x8011
#define GL_SEPARABLE_2D_EXT 0x8012
#define GL_CONVOLUTION_BORDER_MODE_EXT 0x8013
#define GL_CONVOLUTION_FILTER_SCALE_EXT 0x8014
#define GL_CONVOLUTION_FILTER_BIAS_EXT 0x8015
#define GL_REDUCE_EXT 0x8016
#define GL_CONVOLUTION_FORMAT_EXT 0x8017
#define GL_CONVOLUTION_WIDTH_EXT 0x8018
#define GL_CONVOLUTION_HEIGHT_EXT 0x8019
#define GL_MAX_CONVOLUTION_WIDTH_EXT 0x801A
#define GL_MAX_CONVOLUTION_HEIGHT_EXT 0x801B
#define GL_POST_CONVOLUTION_RED_SCALE_EXT 0x801C
#define GL_POST_CONVOLUTION_GREEN_SCALE_EXT 0x801D
#define GL_POST_CONVOLUTION_BLUE_SCALE_EXT 0x801E
#define GL_POST_CONVOLUTION_ALPHA_SCALE_EXT 0x801F
#define GL_POST_CONVOLUTION_RED_BIAS_EXT 0x8020
#define GL_POST_CONVOLUTION_GREEN_BIAS_EXT 0x8021
#define GL_POST_CONVOLUTION_BLUE_BIAS_EXT 0x8022
#define GL_POST_CONVOLUTION_ALPHA_BIAS_EXT 0x8023

#define glConvolutionFilter1DEXT System::GlConvolutionFilter1DEXT
#define glConvolutionFilter2DEXT System::GlConvolutionFilter2DEXT
#define glConvolutionParameterfEXT System::GlConvolutionParameterfEXT
#define glConvolutionParameterfvEXT System::GlConvolutionParameterfvEXT
#define glConvolutionParameteriEXT System::GlConvolutionParameteriEXT
#define glConvolutionParameterivEXT System::GlConvolutionParameterivEXT
#define glCopyConvolutionFilter1DEXT System::GlCopyConvolutionFilter1DEXT
#define glCopyConvolutionFilter2DEXT System::GlCopyConvolutionFilter2DEXT
#define glGetConvolutionFilterEXT System::GlGetConvolutionFilterEXT
#define glGetConvolutionParameterfvEXT System::GlGetConvolutionParameterfvEXT
#define glGetConvolutionParameterivEXT System::GlGetConvolutionParameterivEXT
#define glGetSeparableFilterEXT System::GlGetSeparableFilterEXT
#define glSeparableFilter2DEXT System::GlSeparableFilter2DEXT

// (EXT 018) GL_EXT_cmyka

#define GL_CMYK_EXT 0x800C
#define GL_CMYKA_EXT 0x800D
#define GL_PACK_CMYK_HINT_EXT 0x800E
#define GL_UNPACK_CMYK_HINT_EXT 0x800F

// (EXT 020) GL_EXT_texture_object

#define GL_TEXTURE_PRIORITY_EXT 0x8066
#define GL_TEXTURE_RESIDENT_EXT 0x8067
#define GL_TEXTURE_1D_BINDING_EXT 0x8068
#define GL_TEXTURE_2D_BINDING_EXT 0x8069
#define GL_TEXTURE_3D_BINDING_EXT 0x806A

#define glAreTexturesResidentEXT System::GlAreTexturesResidentEXT
#define glBindTextureEXT System::GlBindTextureEXT
#define glDeleteTexturesEXT System::GlDeleteTexturesEXT
#define glGenTexturesEXT System::GlGenTexturesEXT
#define glIsTextureEXT System::GlIsTextureEXT
#define glPrioritizeTexturesEXT System::GlPrioritizeTexturesEXT

// (EXT 023) GL_EXT_packed_pixels

#define GL_UNSIGNED_BYTE_3_3_2_EXT 0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4_EXT 0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1_EXT 0x8034
#define GL_UNSIGNED_INT_8_8_8_8_EXT 0x8035
#define GL_UNSIGNED_INT_10_10_10_2_EXT 0x8036

// (EXT 027) GL_EXT_rescale_normal

#define GL_RESCALE_NORMAL_EXT 0x803A

// (EXT 030) GL_EXT_vertex_array

#define GL_VERTEX_ARRAY_EXT 0x8074
#define GL_NORMAL_ARRAY_EXT 0x8075
#define GL_COLOR_ARRAY_EXT 0x8076
#define GL_INDEX_ARRAY_EXT 0x8077
#define GL_TEXTURE_COORD_ARRAY_EXT 0x8078
#define GL_EDGE_FLAG_ARRAY_EXT 0x8079
#define GL_VERTEX_ARRAY_SIZE_EXT 0x807A
#define GL_VERTEX_ARRAY_TYPE_EXT 0x807B
#define GL_VERTEX_ARRAY_STRIDE_EXT 0x807C
#define GL_VERTEX_ARRAY_COUNT_EXT 0x807D
#define GL_NORMAL_ARRAY_TYPE_EXT 0x807E
#define GL_NORMAL_ARRAY_STRIDE_EXT 0x807F
#define GL_NORMAL_ARRAY_COUNT_EXT 0x8080
#define GL_COLOR_ARRAY_SIZE_EXT 0x8081
#define GL_COLOR_ARRAY_TYPE_EXT 0x8082
#define GL_COLOR_ARRAY_STRIDE_EXT 0x8083
#define GL_COLOR_ARRAY_COUNT_EXT 0x8084
#define GL_INDEX_ARRAY_TYPE_EXT 0x8085
#define GL_INDEX_ARRAY_STRIDE_EXT 0x8086
#define GL_INDEX_ARRAY_COUNT_EXT 0x8087
#define GL_TEXTURE_COORD_ARRAY_SIZE_EXT 0x8088
#define GL_TEXTURE_COORD_ARRAY_TYPE_EXT 0x8089
#define GL_TEXTURE_COORD_ARRAY_STRIDE_EXT 0x808A
#define GL_TEXTURE_COORD_ARRAY_COUNT_EXT 0x808B
#define GL_EDGE_FLAG_ARRAY_STRIDE_EXT 0x808C
#define GL_EDGE_FLAG_ARRAY_COUNT_EXT 0x808D
#define GL_VERTEX_ARRAY_POINTER_EXT 0x808E
#define GL_NORMAL_ARRAY_POINTER_EXT 0x808F
#define GL_COLOR_ARRAY_POINTER_EXT 0x8090
#define GL_INDEX_ARRAY_POINTER_EXT 0x8091
#define GL_TEXTURE_COORD_ARRAY_POINTER_EXT 0x8092
#define GL_EDGE_FLAG_ARRAY_POINTER_EXT 0x8093

#define glArrayElementEXT System::GlArrayElementEXT
#define glColorPointerEXT System::GlColorPointerEXT
#define glDrawArraysEXT System::GlDrawArraysEXT
#define glEdgeFlagPointerEXT System::GlEdgeFlagPointerEXT
#define glGetPointervEXT System::GlGetPointervEXT
#define glIndexPointerEXT System::GlIndexPointerEXT
#define glNormalPointerEXT System::GlNormalPointerEXT
#define glTexCoordPointerEXT System::GlTexCoordPointerEXT
#define glVertexPointerEXT System::GlVertexPointerEXT

// (EXT 035) GL_EXT_texture_edge_clamp

#define GL_CLAMP_TO_EDGE_EXT 0x812F

// (EXT 037) GL_EXT_blend_minmax

#define GL_FUNC_ADD_EXT 0x8006
#define GL_MIN_EXT 0x8007
#define GL_MAX_EXT 0x8008
#define GL_BLEND_EQUATION_EXT 0x8009

#define glBlendEquationEXT System::GlBlendEquationEXT

// (EXT 038) GL_EXT_blend_subtract

#define GL_FUNC_SUBTRACT_EXT 0x800A
#define GL_FUNC_REVERSE_SUBTRACT_EXT 0x800B

// (EXT 054) GL_EXT_point_parameters

#define GL_POINT_SIZE_MIN_EXT 0x8126
#define GL_POINT_SIZE_MAX_EXT 0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_EXT 0x8128
#define GL_DISTANCE_ATTENUATION_EXT 0x8129

#define glPointParameterfEXT System::GlPointParameterfEXT
#define glPointParameterfvEXT System::GlPointParameterfvEXT

// (EXT 074) GL_EXT_color_subtable

#define glColorSubTableEXT System::GlColorSubTableEXT
#define glCopyColorSubTableEXT System::GlCopyColorSubTableEXT

// (EXT 078) GL_EXT_paletted_texture

#define GL_COLOR_INDEX1_EXT 0x80E2
#define GL_COLOR_INDEX2_EXT 0x80E3
#define GL_COLOR_INDEX4_EXT 0x80E4
#define GL_COLOR_INDEX8_EXT 0x80E5
#define GL_COLOR_INDEX12_EXT 0x80E6
#define GL_COLOR_INDEX16_EXT 0x80E7
#define GL_TEXTURE_INDEX_SIZE_EXT 0x80ED

#define glColorTableEXT System::GlColorTableEXT
#define glGetColorTableEXT System::GlGetColorTableEXT
#define glGetColorTableParameterfvEXT System::GlGetColorTableParameterfvEXT
#define glGetColorTableParameterivEXT System::GlGetColorTableParameterivEXT

// (EXT 079) GL_EXT_clip_volume_hint

#define GL_CLIP_VOLUME_CLIPPING_HINT_EXT 0x80F0

// (EXT 094) GL_EXT_index_material

#define GL_INDEX_MATERIAL_EXT 0x81B8
#define GL_INDEX_MATERIAL_PARAMETER_EXT 0x81B9
#define GL_INDEX_MATERIAL_FACE_EXT 0x81BA

#define glIndexMaterialEXT System::GlIndexMaterialEXT

// (EXT 095) GL_EXT_index_func

#define GL_INDEX_TEST_EXT 0x81B5
#define GL_INDEX_TEST_FUNC_EXT 0x81B6
#define GL_INDEX_TEST_REF_EXT 0x81B7

#define glIndexFuncEXT System::GlIndexFuncEXT

// (EXT 096) GL_EXT_index_array_formats

#define GL_IUI_V2F_EXT 0x81AD
#define GL_IUI_V3F_EXT 0x81AE
#define GL_IUI_N3F_V2F_EXT 0x81AF
#define GL_IUI_N3F_V3F_EXT 0x81B0
#define GL_T2F_IUI_V2F_EXT 0x81B1
#define GL_T2F_IUI_V3F_EXT 0x81B2
#define GL_T2F_IUI_N3F_V2F_EXT 0x81B3
#define GL_T2F_IUI_N3F_V3F_EXT 0x81B4

// (EXT 097) GL_EXT_compiled_vertex_array

#define GL_ARRAY_ELEMENT_LOCK_FIRST_EXT 0x81A8
#define GL_ARRAY_ELEMENT_LOCK_COUNT_EXT 0x81A9

#define glLockArraysEXT System::GlLockArraysEXT
#define glUnlockArraysEXT System::GlUnlockArraysEXT

// (EXT 098) GL_EXT_cull_vertex

#define GL_CULL_VERTEX_EXT 0x81AA
#define GL_CULL_VERTEX_EYE_POSITION_EXT 0x81AB
#define GL_CULL_VERTEX_OBJECT_POSITION_EXT 0x81AC

#define glCullParameterdvEXT System::GlCullParameterdvEXT
#define glCullParameterfvEXT System::GlCullParameterfvEXT

// (EXT 102) GL_EXT_fragment_lighting

#define GL_FRAGMENT_LIGHTING_EXT 0x8400
#define GL_FRAGMENT_COLOR_MATERIAL_EXT 0x8401
#define GL_FRAGMENT_COLOR_MATERIAL_FACE_EXT 0x8402
#define GL_FRAGMENT_COLOR_MATERIAL_PARAMETER_EXT 0x8403
#define GL_MAX_FRAGMENT_LIGHTS_EXT 0x8404
#define GL_MAX_ACTIVE_LIGHTS_EXT 0x8405
#define GL_CURRENT_RASTER_NORMAL_EXT 0x8406
#define GL_LIGHT_ENV_MODE_EXT 0x8407
#define GL_FRAGMENT_LIGHT_MODEL_LOCAL_VIEWER_EXT 0x8408
#define GL_FRAGMENT_LIGHT_MODEL_TWO_SIDE_EXT 0x8409
#define GL_FRAGMENT_LIGHT_MODEL_AMBIENT_EXT 0x840A
#define GL_FRAGMENT_LIGHT_MODEL_NORMAL_INTERPOLATION_EXT 0x840B
#define GL_FRAGMENT_LIGHT0_EXT 0x840C
#define GL_FRAGMENT_LIGHT7_EXT 0x8413

#define glFragmentColorMaterialEXT System::GlFragmentColorMaterialEXT
#define glFragmentLightModelfEXT System::GlFragmentLightModelfEXT
#define glFragmentLightModelfvEXT System::GlFragmentLightModelfvEXT
#define glFragmentLightModeliEXT System::GlFragmentLightModeliEXT
#define glFragmentLightModelivEXT System::GlFragmentLightModelivEXT
#define glFragmentLightfEXT System::GlFragmentLightfEXT
#define glFragmentLightfvEXT System::GlFragmentLightfvEXT
#define glFragmentLightiEXT System::GlFragmentLightiEXT
#define glFragmentLightivEXT System::GlFragmentLightivEXT
#define glFragmentMaterialfEXT System::GlFragmentMaterialfEXT
#define glFragmentMaterialfvEXT System::GlFragmentMaterialfvEXT
#define glFragmentMaterialiEXT System::GlFragmentMaterialiEXT
#define glFragmentMaterialivEXT System::GlFragmentMaterialivEXT
#define glGetFragmentLightfvEXT System::GlGetFragmentLightfvEXT
#define glGetFragmentLightivEXT System::GlGetFragmentLightivEXT
#define glGetFragmentMaterialfvEXT System::GlGetFragmentMaterialfvEXT
#define glGetFragmentMaterialivEXT System::GlGetFragmentMaterialivEXT
#define glLightEnviEXT System::GlLightEnviEXT

// (EXT 112) GL_EXT_draw_range_elements

#define GL_MAX_ELEMENTS_VERTICES_EXT 0x80E8
#define GL_MAX_ELEMENTS_INDICES_EXT 0x80E9

#define glDrawRangeElementsEXT System::GlDrawRangeElementsEXT

// (EXT 117) GL_EXT_light_texture

#define GL_FRAGMENT_MATERIAL_EXT 0x8349
#define GL_FRAGMENT_NORMAL_EXT 0x834A
#define GL_FRAGMENT_COLOR_EXT 0x834C
#define GL_ATTENUATION_EXT 0x834D
#define GL_SHADOW_ATTENUATION_EXT 0x834E
#define GL_TEXTURE_APPLICATION_MODE_EXT 0x834F
#define GL_TEXTURE_LIGHT_EXT 0x8350
#define GL_TEXTURE_MATERIAL_FACE_EXT 0x8351
#define GL_TEXTURE_MATERIAL_PARAMETER_EXT 0x8352

#define glApplyTextureEXT System::GlApplyTextureEXT
#define glTextureLightEXT System::GlTextureLightEXT
#define glTextureMaterialEXT System::GlTextureMaterialEXT

// (EXT 120) GL_EXT_scene_marker

#define glBeginSceneEXT System::GlBeginSceneEXT
#define glEndSceneEXT System::GlEndSceneEXT

// (EXT 129) GL_EXT_bgra

#define GL_BGR_EXT 0x80E0
#define GL_BGRA_EXT 0x80E1

// (EXT 138) GL_EXT_pixel_transform

#define GL_PIXEL_TRANSFORM_2D_EXT 0x8330
#define GL_PIXEL_MAG_FILTER_EXT 0x8331
#define GL_PIXEL_MIN_FILTER_EXT 0x8332
#define GL_PIXEL_CUBIC_WEIGHT_EXT 0x8333
#define GL_CUBIC_EXT 0x8334
#define GL_AVERAGE_EXT 0x8335
#define GL_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT 0x8336
#define GL_MAX_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT 0x8337
#define GL_PIXEL_TRANSFORM_2D_MATRIX_EXT 0x8338

#define glPixelTransformParameteriEXT System::GlPixelTransformParameteriEXT
#define glPixelTransformParameterfEXT System::GlPixelTransformParameterfEXT
#define glPixelTransformParameterivEXT System::GlPixelTransformParameterivEXT
#define glPixelTransformParameterfvEXT System::GlPixelTransformParameterfvEXT

// (EXT 141) GL_EXT_shared_texture_palette

#define GL_SHARED_TEXTURE_PALETTE_EXT 0x81FB

// (EXT 144) GL_EXT_separate_specular_color

#define GL_LIGHT_MODEL_COLOR_CONTROL_EXT 0x81F8
#define GL_SINGLE_COLOR_EXT 0x81F9
#define GL_SEPARATE_SPECULAR_COLOR_EXT 0x81FA

// (EXT 145) GL_EXT_secondary_color

#define GL_COLOR_SUM_EXT 0x8458
#define GL_CURRENT_SECONDARY_COLOR_EXT 0x8459
#define GL_SECONDARY_COLOR_ARRAY_SIZE_EXT 0x845A
#define GL_SECONDARY_COLOR_ARRAY_TYPE_EXT 0x845B
#define GL_SECONDARY_COLOR_ARRAY_STRIDE_EXT 0x845C
#define GL_SECONDARY_COLOR_ARRAY_POINTER_EXT 0x845D
#define GL_SECONDARY_COLOR_ARRAY_EXT 0x845E

#define glSecondaryColor3bEXT System::GlSecondaryColor3bEXT
#define glSecondaryColor3bvEXT System::GlSecondaryColor3bvEXT
#define glSecondaryColor3dEXT System::GlSecondaryColor3dEXT
#define glSecondaryColor3dvEXT System::GlSecondaryColor3dvEXT
#define glSecondaryColor3fEXT System::GlSecondaryColor3fEXT
#define glSecondaryColor3fvEXT System::GlSecondaryColor3fvEXT
#define glSecondaryColor3iEXT System::GlSecondaryColor3iEXT
#define glSecondaryColor3ivEXT System::GlSecondaryColor3ivEXT
#define glSecondaryColor3sEXT System::GlSecondaryColor3sEXT
#define glSecondaryColor3svEXT System::GlSecondaryColor3svEXT
#define glSecondaryColor3ubEXT System::GlSecondaryColor3ubEXT
#define glSecondaryColor3ubvEXT System::GlSecondaryColor3ubvEXT
#define glSecondaryColor3uiEXT System::GlSecondaryColor3uiEXT
#define glSecondaryColor3uivEXT System::GlSecondaryColor3uivEXT
#define glSecondaryColor3usEXT System::GlSecondaryColor3usEXT
#define glSecondaryColor3usvEXT System::GlSecondaryColor3usvEXT
#define glSecondaryColorPointerEXT System::GlSecondaryColorPointerEXT

// (EXT 147) GL_EXT_texture_perturb_normal

#define GL_PERTURB_EXT 0x85AE
#define GL_TEXTURE_NORMAL_EXT 0x85AF

#define glTextureNormalEXT System::GlTextureNormalEXT

// (EXT 148) GL_EXT_multi_draw_arrays

#define glMultiDrawArraysEXT System::GlMultiDrawArraysEXT
#define glMultiDrawElementsEXT System::GlMultiDrawElementsEXT

// (EXT 149) GL_EXT_fog_coord

#define GL_FOG_COORDINATE_SOURCE_EXT 0x8450
#define GL_FOG_COORDINATE_EXT 0x8451
#define GL_FRAGMENT_DEPTH_EXT 0x8452
#define GL_CURRENT_FOG_COORDINATE_EXT 0x8453
#define GL_FOG_COORDINATE_ARRAY_TYPE_EXT 0x8454
#define GL_FOG_COORDINATE_ARRAY_STRIDE_EXT 0x8455
#define GL_FOG_COORDINATE_ARRAY_POINTER_EXT 0x8456
#define GL_FOG_COORDINATE_ARRAY_EXT 0x8457

#define glFogCoorddEXT System::GlFogCoorddEXT
#define glFogCoorddvEXT System::GlFogCoorddvEXT
#define glFogCoordfEXT System::GlFogCoordfEXT
#define glFogCoordfvEXT System::GlFogCoordfvEXT
#define glFogCoordPointerEXT System::GlFogCoordPointerEXT

// (EXT 156) GL_EXT_coordinate_frame

#define GL_TANGENT_ARRAY_EXT 0x8439
#define GL_BINORMAL_ARRAY_EXT 0x843A
#define GL_CURRENT_TANGENT_EXT 0x843B
#define GL_CURRENT_BINORMAL_EXT 0x843C
#define GL_TANGENT_ARRAY_TYPE_EXT 0x843E
#define GL_TANGENT_ARRAY_STRIDE_EXT 0x843F
#define GL_BINORMAL_ARRAY_TYPE_EXT 0x8440
#define GL_BINORMAL_ARRAY_STRIDE_EXT 0x8441
#define GL_TANGENT_ARRAY_POINTER_EXT 0x8442
#define GL_BINORMAL_ARRAY_POINTER_EXT 0x8443
#define GL_MAP1_TANGENT_EXT 0x8444
#define GL_MAP2_TANGENT_EXT 0x8445
#define GL_MAP1_BINORMAL_EXT 0x8446
#define GL_MAP2_BINORMAL_EXT 0x8447

#define glTangent3bEXT System::GlTangent3bEXT
#define glTangent3bvEXT System::GlTangent3bvEXT
#define glTangent3dEXT System::GlTangent3dEXT
#define glTangent3dvEXT System::GlTangent3dvEXT
#define glTangent3fEXT System::GlTangent3fEXT
#define glTangent3fvEXT System::GlTangent3fvEXT
#define glTangent3iEXT System::GlTangent3iEXT
#define glTangent3ivEXT System::GlTangent3ivEXT
#define glTangent3sEXT System::GlTangent3sEXT
#define glTangent3svEXT System::GlTangent3svEXT
#define glBinormal3bEXT System::GlBinormal3bEXT
#define glBinormal3bvEXT System::GlBinormal3bvEXT
#define glBinormal3dEXT System::GlBinormal3dEXT
#define glBinormal3dvEXT System::GlBinormal3dvEXT
#define glBinormal3fEXT System::GlBinormal3fEXT
#define glBinormal3fvEXT System::GlBinormal3fvEXT
#define glBinormal3iEXT System::GlBinormal3iEXT
#define glBinormal3ivEXT System::GlBinormal3ivEXT
#define glBinormal3sEXT System::GlBinormal3sEXT
#define glBinormal3svEXT System::GlBinormal3svEXT
#define glTangentPointerEXT System::GlTangentPointerEXT
#define glBinormalPointerEXT System::GlBinormalPointerEXT

// (EXT 158) GL_EXT_texture_env_combine

#define GL_COMBINE_EXT 0x8570
#define GL_COMBINE_RGB_EXT 0x8571
#define GL_COMBINE_ALPHA_EXT 0x8572
#define GL_RGB_SCALE_EXT 0x8573
#define GL_ADD_SIGNED_EXT 0x8574
#define GL_INTERPOLATE_EXT 0x8575
#define GL_CONSTANT_EXT 0x8576
#define GL_PRIMARY_COLOR_EXT 0x8577
#define GL_PREVIOUS_EXT 0x8578
#define GL_SOURCE0_RGB_EXT 0x8580
#define GL_SOURCE1_RGB_EXT 0x8581
#define GL_SOURCE2_RGB_EXT 0x8582
#define GL_SOURCE0_ALPHA_EXT 0x8588
#define GL_SOURCE1_ALPHA_EXT 0x8589
#define GL_SOURCE2_ALPHA_EXT 0x858A
#define GL_OPERAND0_RGB_EXT 0x8590
#define GL_OPERAND1_RGB_EXT 0x8591
#define GL_OPERAND2_RGB_EXT 0x8592
#define GL_OPERAND0_ALPHA_EXT 0x8598
#define GL_OPERAND1_ALPHA_EXT 0x8599
#define GL_OPERAND2_ALPHA_EXT 0x859A

// (EXT 173) GL_EXT_blend_func_separate

#define GL_BLEND_DST_RGB_EXT 0x80C8
#define GL_BLEND_SRC_RGB_EXT 0x80C9
#define GL_BLEND_DST_ALPHA_EXT 0x80CA
#define GL_BLEND_SRC_ALPHA_EXT 0x80CB

#define glBlendFuncSeparateEXT System::GlBlendFuncSeparateEXT

// (EXT 176) GL_EXT_stencil_wrap

#define GL_INCR_WRAP_EXT 0x8507
#define GL_DECR_WRAP_EXT 0x8508

// (EXT 178) GL_EXT_422_pixels

#define GL_422_EXT 0x80CC
#define GL_422_REV_EXT 0x80CD
#define GL_422_AVERAGE_EXT 0x80CE
#define GL_422_REV_AVERAGE_EXT 0x80CF

// (EXT 179) GL_EXT_texture_cube_map

#define GL_NORMAL_MAP_EXT 0x8511
#define GL_REFLECTION_MAP_EXT 0x8512
#define GL_TEXTURE_CUBE_MAP_EXT 0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP_EXT 0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT 0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_EXT 0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_EXT 0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_EXT 0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_EXT 0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_EXT 0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP_EXT 0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_EXT 0x851C

// (EXT 186) GL_EXT_texture_lod_bias

#define GL_MAX_TEXTURE_LOD_BIAS_EXT 0x84FD
#define GL_TEXTURE_FILTER_CONTROL_EXT 0x8500
#define GL_TEXTURE_LOD_BIAS_EXT 0x8501

// (EXT 187) GL_EXT_texture_filter_anisotropic

#define GL_TEXTURE_MAX_ANISOTROPY_EXT 0x84FE
#define GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT 0x84FF

// (EXT 188) GL_EXT_vertex_weighting

#define GL_MODELVIEW0_STACK_DEPTH_EXT 0x0BA3
#define GL_MODELVIEW1_STACK_DEPTH_EXT 0x8502
#define GL_MODELVIEW0_MATRIX_EXT 0x0BA6
#define GL_MODELVIEW1_MATRIX_EXT 0x8506
#define GL_VERTEX_WEIGHTING_EXT 0x8509
#define GL_MODELVIEW0_EXT 0x1700
#define GL_MODELVIEW1_EXT 0x850A
#define GL_CURRENT_VERTEX_WEIGHT_EXT 0x850B
#define GL_VERTEX_WEIGHT_ARRAY_EXT 0x850C
#define GL_VERTEX_WEIGHT_ARRAY_SIZE_EXT 0x850D
#define GL_VERTEX_WEIGHT_ARRAY_TYPE_EXT 0x850E
#define GL_VERTEX_WEIGHT_ARRAY_STRIDE_EXT 0x850F
#define GL_VERTEX_WEIGHT_ARRAY_POINTER_EXT 0x8510

#define glVertexWeightfEXT System::GlVertexWeightfEXT
#define glVertexWeightfvEXT System::GlVertexWeightfvEXT
#define glVertexWeightPointerEXT System::GlVertexWeightPointerEXT

// (EXT 198) GL_EXT_texture_compression_s3tc

#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT 0x83F0
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT 0x83F1
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT 0x83F2
#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT 0x83F3

// (EXT 209) GL_EXT_multisample

#define GL_MULTISAMPLE_EXT 0x809D
#define GL_SAMPLE_ALPHA_TO_MASK_EXT 0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_EXT 0x809F
#define GL_SAMPLE_MASK_EXT 0x80A0
#define GL_1PASS_EXT 0x80A1
#define GL_2PASS_0_EXT 0x80A2
#define GL_2PASS_1_EXT 0x80A3
#define GL_4PASS_0_EXT 0x80A4
#define GL_4PASS_1_EXT 0x80A5
#define GL_4PASS_2_EXT 0x80A6
#define GL_4PASS_3_EXT 0x80A7
#define GL_SAMPLE_BUFFERS_EXT 0x80A8
#define GL_SAMPLES_EXT 0x80A9
#define GL_SAMPLE_MASK_VALUE_EXT 0x80AA
#define GL_SAMPLE_MASK_INVERT_EXT 0x80AB
#define GL_SAMPLE_PATTERN_EXT 0x80AC
#define GL_MULTISAMPLE_BIT_EXT 0x20000000

#define glSampleMaskEXT System::GlSampleMaskEXT
#define glSamplePatternEXT System::GlSamplePatternEXT

// (EXT 220) GL_EXT_texture_env_dot3

#define GL_DOT3_RGB_EXT 0x8740
#define GL_DOT3_RGBA_EXT 0x8741

// (EXT 229) GL_EXT_texture_rectangle

#define GL_TEXTURE_RECTANGLE_EXT 0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE_EXT 0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE_EXT 0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE_EXT 0x84F8

// (EXT 248) GL_EXT_vertex_shader

#define GL_VERTEX_SHADER_EXT 0x8780
#define GL_VERTEX_SHADER_BINDING_EXT 0x8781
#define GL_OP_INDEX_EXT 0x8782
#define GL_OP_NEGATE_EXT 0x8783
#define GL_OP_DOT3_EXT 0x8784
#define GL_OP_DOT4_EXT 0x8785
#define GL_OP_MUL_EXT 0x8786
#define GL_OP_ADD_EXT 0x8787
#define GL_OP_MADD_EXT 0x8788
#define GL_OP_FRAC_EXT 0x8789
#define GL_OP_MAX_EXT 0x878A
#define GL_OP_MIN_EXT 0x878B
#define GL_OP_SET_GE_EXT 0x878C
#define GL_OP_SET_LT_EXT 0x878D
#define GL_OP_CLAMP_EXT 0x878E
#define GL_OP_FLOOR_EXT 0x878F
#define GL_OP_ROUND_EXT 0x8790
#define GL_OP_EXP_BASE_2_EXT 0x8791
#define GL_OP_LOG_BASE_2_EXT 0x8792
#define GL_OP_POWER_EXT 0x8793
#define GL_OP_RECIP_EXT 0x8794
#define GL_OP_RECIP_SQRT_EXT 0x8795
#define GL_OP_SUB_EXT 0x8796
#define GL_OP_CROSS_PRODUCT_EXT 0x8797
#define GL_OP_MULTIPLY_MATRIX_EXT 0x8798
#define GL_OP_MOV_EXT 0x8799
#define GL_OUTPUT_VERTEX_EXT 0x879A
#define GL_OUTPUT_COLOR0_EXT 0x879B
#define GL_OUTPUT_COLOR1_EXT 0x879C
#define GL_OUTPUT_TEXTURE_COORD0_EXT 0x879D
#define GL_OUTPUT_TEXTURE_COORD1_EXT 0x879E
#define GL_OUTPUT_TEXTURE_COORD2_EXT 0x879F
#define GL_OUTPUT_TEXTURE_COORD3_EXT 0x87A0
#define GL_OUTPUT_TEXTURE_COORD4_EXT 0x87A1
#define GL_OUTPUT_TEXTURE_COORD5_EXT 0x87A2
#define GL_OUTPUT_TEXTURE_COORD6_EXT 0x87A3
#define GL_OUTPUT_TEXTURE_COORD7_EXT 0x87A4
#define GL_OUTPUT_TEXTURE_COORD8_EXT 0x87A5
#define GL_OUTPUT_TEXTURE_COORD9_EXT 0x87A6
#define GL_OUTPUT_TEXTURE_COORD10_EXT 0x87A7
#define GL_OUTPUT_TEXTURE_COORD11_EXT 0x87A8
#define GL_OUTPUT_TEXTURE_COORD12_EXT 0x87A9
#define GL_OUTPUT_TEXTURE_COORD13_EXT 0x87AA
#define GL_OUTPUT_TEXTURE_COORD14_EXT 0x87AB
#define GL_OUTPUT_TEXTURE_COORD15_EXT 0x87AC
#define GL_OUTPUT_TEXTURE_COORD16_EXT 0x87AD
#define GL_OUTPUT_TEXTURE_COORD17_EXT 0x87AE
#define GL_OUTPUT_TEXTURE_COORD18_EXT 0x87AF
#define GL_OUTPUT_TEXTURE_COORD19_EXT 0x87B0
#define GL_OUTPUT_TEXTURE_COORD20_EXT 0x87B1
#define GL_OUTPUT_TEXTURE_COORD21_EXT 0x87B2
#define GL_OUTPUT_TEXTURE_COORD22_EXT 0x87B3
#define GL_OUTPUT_TEXTURE_COORD23_EXT 0x87B4
#define GL_OUTPUT_TEXTURE_COORD24_EXT 0x87B5
#define GL_OUTPUT_TEXTURE_COORD25_EXT 0x87B6
#define GL_OUTPUT_TEXTURE_COORD26_EXT 0x87B7
#define GL_OUTPUT_TEXTURE_COORD27_EXT 0x87B8
#define GL_OUTPUT_TEXTURE_COORD28_EXT 0x87B9
#define GL_OUTPUT_TEXTURE_COORD29_EXT 0x87BA
#define GL_OUTPUT_TEXTURE_COORD30_EXT 0x87BB
#define GL_OUTPUT_TEXTURE_COORD31_EXT 0x87BC
#define GL_OUTPUT_FOG_EXT 0x87BD
#define GL_SCALAR_EXT 0x87BE
#define GL_VECTOR_EXT 0x87BF
#define GL_MATRIX_EXT 0x87C0
#define GL_VARIANT_EXT 0x87C1
#define GL_INVARIANT_EXT 0x87C2
#define GL_LOCAL_CONSTANT_EXT 0x87C3
#define GL_LOCAL_EXT 0x87C4
#define GL_MAX_VERTEX_SHADER_INSTRUCTIONS_EXT 0x87C5
#define GL_MAX_VERTEX_SHADER_VARIANTS_EXT 0x87C6
#define GL_MAX_VERTEX_SHADER_INVARIANTS_EXT 0x87C7
#define GL_MAX_VERTEX_SHADER_LOCAL_CONSTANTS_EXT 0x87C8
#define GL_MAX_VERTEX_SHADER_LOCALS_EXT 0x87C9
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_INSTRUCTIONS_EXT 0x87CA
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_VARIANTS_EXT 0x87CB
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_INVARIANTS_EXT 0x87CC
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCAL_CONSTANTS_EXT 0x87CD
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCALS_EXT 0x87CE
#define GL_VERTEX_SHADER_INSTRUCTIONS_EXT 0x87CF
#define GL_VERTEX_SHADER_VARIANTS_EXT 0x87D0
#define GL_VERTEX_SHADER_INVARIANTS_EXT 0x87D1
#define GL_VERTEX_SHADER_LOCAL_CONSTANTS_EXT 0x87D2
#define GL_VERTEX_SHADER_LOCALS_EXT 0x87D3
#define GL_VERTEX_SHADER_OPTIMIZED_EXT 0x87D4
#define GL_X_EXT 0x87D5
#define GL_Y_EXT 0x87D6
#define GL_Z_EXT 0x87D7
#define GL_W_EXT 0x87D8
#define GL_NEGATIVE_X_EXT 0x87D9
#define GL_NEGATIVE_Y_EXT 0x87DA
#define GL_NEGATIVE_Z_EXT 0x87DB
#define GL_NEGATIVE_W_EXT 0x87DC
#define GL_ZERO_EXT 0x87DD
#define GL_ONE_EXT 0x87DE
#define GL_NEGATIVE_ONE_EXT 0x87DF
#define GL_NORMALIZED_RANGE_EXT 0x87E0
#define GL_FULL_RANGE_EXT 0x87E1
#define GL_CURRENT_VERTEX_EXT 0x87E2
#define GL_MVP_MATRIX_EXT 0x87E3
#define GL_VARIANT_VALUE_EXT 0x87E4
#define GL_VARIANT_DATATYPE_EXT 0x87E5
#define GL_VARIANT_ARRAY_STRIDE_EXT 0x87E6
#define GL_VARIANT_ARRAY_TYPE_EXT 0x87E7
#define GL_VARIANT_ARRAY_EXT 0x87E8
#define GL_VARIANT_ARRAY_POINTER_EXT 0x87E9
#define GL_INVARIANT_VALUE_EXT 0x87EA
#define GL_INVARIANT_DATATYPE_EXT 0x87EB
#define GL_LOCAL_CONSTANT_VALUE_EXT 0x87EC
#define GL_LOCAL_CONSTANT_DATATYPE_EXT 0x87ED

#define glBeginVertexShaderEXT System::GlBeginVertexShaderEXT
#define glBindLightParameterEXT System::GlBindLightParameterEXT
#define glBindMaterialParameterEXT System::GlBindMaterialParameterEXT
#define glBindParameterEXT System::GlBindParameterEXT
#define glBindTexGenParameterEXT System::GlBindTexGenParameterEXT
#define glBindTextureUnitParameterEXT System::GlBindTextureUnitParameterEXT
#define glBindVertexShaderEXT System::GlBindVertexShaderEXT
#define glDeleteVertexShaderEXT System::GlDeleteVertexShaderEXT
#define glDisableVariantClientStateEXT System::GlDisableVariantClientStateEXT
#define glEnableVariantClientStateEXT System::GlEnableVariantClientStateEXT
#define glEndVertexShaderEXT System::GlEndVertexShaderEXT
#define glExtractComponentEXT System::GlExtractComponentEXT
#define glGenSymbolsEXT System::GlGenSymbolsEXT
#define glGenVertexShadersEXT System::GlGenVertexShadersEXT
#define glGetInvariantBooleanvEXT System::GlGetInvariantBooleanvEXT
#define glGetInvariantFloatvEXT System::GlGetInvariantFloatvEXT
#define glGetInvariantIntegervEXT System::GlGetInvariantIntegervEXT
#define glGetLocalConstantBooleanvEXT System::GlGetLocalConstantBooleanvEXT
#define glGetLocalConstantFloatvEXT System::GlGetLocalConstantFloatvEXT
#define glGetLocalConstantIntegervEXT System::GlGetLocalConstantIntegervEXT
#define glGetVariantBooleanvEXT System::GlGetVariantBooleanvEXT
#define glGetVariantFloatvEXT System::GlGetVariantFloatvEXT
#define glGetVariantIntegervEXT System::GlGetVariantIntegervEXT
#define glGetVariantPointervEXT System::GlGetVariantPointervEXT
#define glInsertComponentEXT System::GlInsertComponentEXT
#define glIsVariantEnabledEXT System::GlIsVariantEnabledEXT
#define glSetInvariantEXT System::GlSetInvariantEXT
#define glSetLocalConstantEXT System::GlSetLocalConstantEXT
#define glShaderOp1EXT System::GlShaderOp1EXT
#define glShaderOp2EXT System::GlShaderOp2EXT
#define glShaderOp3EXT System::GlShaderOp3EXT
#define glSwizzleEXT System::GlSwizzleEXT
#define glVariantPointerEXT System::GlVariantPointerEXT
#define glVariantbvEXT System::GlVariantbvEXT
#define glVariantdvEXT System::GlVariantdvEXT
#define glVariantfvEXT System::GlVariantfvEXT
#define glVariantivEXT System::GlVariantivEXT
#define glVariantsvEXT System::GlVariantsvEXT
#define glVariantubvEXT System::GlVariantubvEXT
#define glVariantuivEXT System::GlVariantuivEXT
#define glVariantusvEXT System::GlVariantusvEXT
#define glWriteMaskEXT System::GlWriteMaskEXT

// (EXT 268) GL_EXT_stencil_two_side

#define GL_STENCIL_TEST_TWO_SIDE_EXT 0x8910
#define GL_ACTIVE_STENCIL_FACE_EXT 0x8911

#define glActiveStencilFaceEXT System::GlActiveStencilFaceEXT

// (EXT 297) GL_EXT_depth_bounds_test

#define GL_DEPTH_BOUNDS_TEST_EXT 0x8890
#define GL_DEPTH_BOUNDS_EXT 0x8891

#define glDepthBoundsEXT System::GlDepthBoundsEXT

// (EXT 298) GL_EXT_texture_mirror_clamp

#define GL_MIRROR_CLAMP_EXT 0x8742
#define GL_MIRROR_CLAMP_TO_EDGE_EXT 0x8743
#define GL_MIRROR_CLAMP_TO_BORDER_EXT 0x8912

// (EXT 299) GL_EXT_blend_equation_separate

#define GL_BLEND_EQUATION_RGB_EXT 0x8009
#define GL_BLEND_EQUATION_ALPHA_EXT 0x883D

#define glBlendEquationSeparateEXT System::GlBlendEquationSeparateEXT

// (EXT 302) GL_EXT_pixel_buffer_object

#define GL_PIXEL_PACK_BUFFER_EXT 0x88EB
#define GL_PIXEL_UNPACK_BUFFER_EXT 0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING_EXT 0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING_EXT 0x88EF

// (EXT 310) GL_EXT_framebuffer_object

#define GL_INVALID_FRAMEBUFFER_OPERATION_EXT 0x0506
#define GL_MAX_RENDERBUFFER_SIZE_EXT 0x84E8
#define GL_FRAMEBUFFER_BINDING_EXT 0x8CA6
#define GL_RENDERBUFFER_BINDING_EXT 0x8CA7
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE_EXT 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_EXT 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL_EXT 0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE_EXT 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_3D_ZOFFSET_EXT 0x8CD4
#define GL_FRAMEBUFFER_COMPLETE_EXT 0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENTS_EXT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DUPLICATE_ATTACHMENT_EXT 0x8CD8
#define GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT 0x8CD9
#define GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT 0x8CDA
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT 0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT 0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED_EXT 0x8CDD
#define GL_FRAMEBUFFER_STATUS_ERROR_EXT 0x8CDE
#define GL_MAX_COLOR_ATTACHMENTS_EXT 0x8CDF
#define GL_COLOR_ATTACHMENT0_EXT 0x8CE0
#define GL_COLOR_ATTACHMENT1_EXT 0x8CE1
#define GL_COLOR_ATTACHMENT2_EXT 0x8CE2
#define GL_COLOR_ATTACHMENT3_EXT 0x8CE3
#define GL_COLOR_ATTACHMENT4_EXT 0x8CE4
#define GL_COLOR_ATTACHMENT5_EXT 0x8CE5
#define GL_COLOR_ATTACHMENT6_EXT 0x8CE6
#define GL_COLOR_ATTACHMENT7_EXT 0x8CE7
#define GL_COLOR_ATTACHMENT8_EXT 0x8CE8
#define GL_COLOR_ATTACHMENT9_EXT 0x8CE9
#define GL_COLOR_ATTACHMENT10_EXT 0x8CEA
#define GL_COLOR_ATTACHMENT11_EXT 0x8CEB
#define GL_COLOR_ATTACHMENT12_EXT 0x8CEC
#define GL_COLOR_ATTACHMENT13_EXT 0x8CED
#define GL_COLOR_ATTACHMENT14_EXT 0x8CEE
#define GL_COLOR_ATTACHMENT15_EXT 0x8CEF
#define GL_DEPTH_ATTACHMENT_EXT 0x8D00
#define GL_STENCIL_ATTACHMENT_EXT 0x8D20
#define GL_FRAMEBUFFER_EXT 0x8D40
#define GL_RENDERBUFFER_EXT 0x8D41
#define GL_RENDERBUFFER_WIDTH_EXT 0x8D42
#define GL_RENDERBUFFER_HEIGHT_EXT 0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT_EXT 0x8D44
#define GL_STENCIL_INDEX_EXT 0x8D45
#define GL_STENCIL_INDEX1_EXT 0x8D46
#define GL_STENCIL_INDEX4_EXT 0x8D47
#define GL_STENCIL_INDEX8_EXT 0x8D48
#define GL_STENCIL_INDEX16_EXT 0x8D49

#define glIsRenderbufferEXT System::GlIsRenderbufferEXT
#define glBindRenderbufferEXT System::GlBindRenderbufferEXT
#define glDeleteRenderbuffersEXT System::GlDeleteRenderbuffersEXT
#define glGenRenderbuffersEXT System::GlGenRenderbuffersEXT
#define glRenderbufferStorageEXT System::GlRenderbufferStorageEXT
#define glGetRenderbufferParameterivEXT System::GlGetRenderbufferParameterivEXT
#define glIsFramebufferEXT System::GlIsFramebufferEXT
#define glBindFramebufferEXT System::GlBindFramebufferEXT
#define glDeleteFramebuffersEXT System::GlDeleteFramebuffersEXT
#define glGenFramebuffersEXT System::GlGenFramebuffersEXT
#define glCheckFramebufferStatusEXT System::GlCheckFramebufferStatusEXT
#define glFramebufferTexture1DEXT System::GlFramebufferTexture1DEXT
#define glFramebufferTexture2DEXT System::GlFramebufferTexture2DEXT
#define glFramebufferTexture3DEXT System::GlFramebufferTexture3DEXT
#define glFramebufferRenderbufferEXT System::GlFramebufferRenderbufferEXT
#define glGetFramebufferAttachmentParameterivEXT System::GlGetFramebufferAttachmentParameterivEXT
#define glGenerateMipmapEXT System::GlGenerateMipmapEXT

// (EXT 312) GL_EXT_packed_depth_stencil

#define GL_DEPTH_STENCIL_EXT 0x84F9
#define GL_UNSIGNED_INT_24_8_EXT 0x84FA
#define GL_DEPTH24_STENCIL8_EXT 0x88F0
#define GL_TEXTURE_STENCIL_SIZE_EXT 0x88F1

// (EXT 314) GL_EXT_stencil_clear_tag

#define GL_STENCIL_TAG_BITS_EXT 0x88F2
#define GL_STENCIL_CLEAR_TAG_VALUE_EXT 0x88F3

#define glStencilClearTagEXT System::GlStencilClearTagEXT

// (EXT 315) GL_EXT_texture_sRGB

#define GL_SRGB_EXT 0x8C40
#define GL_SRGB8_EXT 0x8C41
#define GL_SRGB_ALPHA_EXT 0x8C42
#define GL_SRGB8_ALPHA8_EXT 0x8C43
#define GL_SLUMINANCE_ALPHA_EXT 0x8C44
#define GL_SLUMINANCE8_ALPHA8_EXT 0x8C45
#define GL_SLUMINANCE_EXT 0x8C46
#define GL_SLUMINANCE8_EXT 0x8C47
#define GL_COMPRESSED_SRGB_EXT 0x8C48
#define GL_COMPRESSED_SRGB_ALPHA_EXT 0x8C49
#define GL_COMPRESSED_SLUMINANCE_EXT 0x8C4A
#define GL_COMPRESSED_SLUMINANCE_ALPHA_EXT 0x8C4B
#define GL_COMPRESSED_SRGB_S3TC_DXT1_EXT 0x8C4C
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT 0x8C4D
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT 0x8C4E
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT 0x8C4F

// (EXT 316) GL_EXT_framebuffer_blit

#define GL_READ_FRAMEBUFFER_EXT 0x8CA8
#define GL_DRAW_FRAMEBUFFER_EXT 0x8CA9
#define GL_DRAW_FRAMEBUFFER_BINDING_EXT 0x8CA6
#define GL_READ_FRAMEBUFFER_BINDING_EXT 0x8CAA

#define glBlitFramebufferEXT System::GlBlitFramebufferEXT

// (EXT 317) GL_EXT_framebuffer_multisample

#define GL_RENDERBUFFER_SAMPLES_EXT 0x8CAB

#define glRenderbufferStorageMultisampleEXT System::GlRenderbufferStorageMultisampleEXT

// (EXT 319) GL_EXT_timer_query

#define GL_TIME_ELAPSED_EXT 0x88BF

#define glGetQueryObjecti64vEXT System::GlGetQueryObjecti64vEXT
#define glGetQueryObjectui64vEXT System::GlGetQueryObjectui64vEXT

// (EXT 320) GL_EXT_gpu_program_parameters

#define glProgramEnvParameters4fvEXT System::GlProgramEnvParameters4fvEXT
#define glProgramLocalParameters4fvEXT System::GlProgramLocalParameters4fvEXT

// (EXT 324) GL_EXT_geometry_shader4

#define GL_LINES_ADJACENCY_EXT 0xA
#define GL_LINE_STRIP_ADJACENCY_EXT 0xB
#define GL_TRIANGLES_ADJACENCY_EXT 0xC
#define GL_TRIANGLE_STRIP_ADJACENCY_EXT 0xD
#define GL_PROGRAM_POINT_SIZE_EXT 0x8642
#define GL_MAX_VARYING_COMPONENTS_EXT 0x8B4B
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT 0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT 0x8CD4
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_EXT 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_EXT 0x8DA8
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_EXT 0x8DA9
#define GL_GEOMETRY_SHADER_EXT 0x8DD9
#define GL_GEOMETRY_VERTICES_OUT_EXT 0x8DDA
#define GL_GEOMETRY_INPUT_TYPE_EXT 0x8DDB
#define GL_GEOMETRY_OUTPUT_TYPE_EXT 0x8DDC
#define GL_MAX_GEOMETRY_VARYING_COMPONENTS_EXT 0x8DDD
#define GL_MAX_VERTEX_VARYING_COMPONENTS_EXT 0x8DDE
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_EXT 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT 0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_EXT 0x8DE1

#define glFramebufferTextureEXT System::GlFramebufferTextureEXT
#define glFramebufferTextureFaceEXT System::GlFramebufferTextureFaceEXT
#define glProgramParameteriEXT System::GlProgramParameteriEXT

// (EXT 326) GL_EXT_gpu_shader4

#define GL_VERTEX_ATTRIB_ARRAY_INTEGER_EXT 0x88FD
#define GL_SAMPLER_1D_ARRAY_EXT 0x8DC0
#define GL_SAMPLER_2D_ARRAY_EXT 0x8DC1
#define GL_SAMPLER_BUFFER_EXT 0x8DC2
#define GL_SAMPLER_1D_ARRAY_SHADOW_EXT 0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW_EXT 0x8DC4
#define GL_SAMPLER_CUBE_SHADOW_EXT 0x8DC5
#define GL_UNSIGNED_INT_VEC2_EXT 0x8DC6
#define GL_UNSIGNED_INT_VEC3_EXT 0x8DC7
#define GL_UNSIGNED_INT_VEC4_EXT 0x8DC8
#define GL_INT_SAMPLER_1D_EXT 0x8DC9
#define GL_INT_SAMPLER_2D_EXT 0x8DCA
#define GL_INT_SAMPLER_3D_EXT 0x8DCB
#define GL_INT_SAMPLER_CUBE_EXT 0x8DCC
#define GL_INT_SAMPLER_2D_RECT_EXT 0x8DCD
#define GL_INT_SAMPLER_1D_ARRAY_EXT 0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY_EXT 0x8DCF
#define GL_INT_SAMPLER_BUFFER_EXT 0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_1D_EXT 0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D_EXT 0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D_EXT 0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE_EXT 0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT_EXT 0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY_EXT 0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY_EXT 0x8DD7
#define GL_UNSIGNED_INT_SAMPLER_BUFFER_EXT 0x8DD8

#define glBindFragDataLocationEXT System::GlBindFragDataLocationEXT
#define glGetFragDataLocationEXT System::GlGetFragDataLocationEXT
#define glGetUniformuivEXT System::GlGetUniformuivEXT
#define glGetVertexAttribIivEXT System::GlGetVertexAttribIivEXT
#define glGetVertexAttribIuivEXT System::GlGetVertexAttribIuivEXT
#define glUniform1uiEXT System::GlUniform1uiEXT
#define glUniform1uivEXT System::GlUniform1uivEXT
#define glUniform2uiEXT System::GlUniform2uiEXT
#define glUniform2uivEXT System::GlUniform2uivEXT
#define glUniform3uiEXT System::GlUniform3uiEXT
#define glUniform3uivEXT System::GlUniform3uivEXT
#define glUniform4uiEXT System::GlUniform4uiEXT
#define glUniform4uivEXT System::GlUniform4uivEXT
#define glVertexAttribI1iEXT System::GlVertexAttribI1iEXT
#define glVertexAttribI1ivEXT System::GlVertexAttribI1ivEXT
#define glVertexAttribI1uiEXT System::GlVertexAttribI1uiEXT
#define glVertexAttribI1uivEXT System::GlVertexAttribI1uivEXT
#define glVertexAttribI2iEXT System::GlVertexAttribI2iEXT
#define glVertexAttribI2ivEXT System::GlVertexAttribI2ivEXT
#define glVertexAttribI2uiEXT System::GlVertexAttribI2uiEXT
#define glVertexAttribI2uivEXT System::GlVertexAttribI2uivEXT
#define glVertexAttribI3iEXT System::GlVertexAttribI3iEXT
#define glVertexAttribI3ivEXT System::GlVertexAttribI3ivEXT
#define glVertexAttribI3uiEXT System::GlVertexAttribI3uiEXT
#define glVertexAttribI3uivEXT System::GlVertexAttribI3uivEXT
#define glVertexAttribI4bvEXT System::GlVertexAttribI4bvEXT
#define glVertexAttribI4iEXT System::GlVertexAttribI4iEXT
#define glVertexAttribI4ivEXT System::GlVertexAttribI4ivEXT
#define glVertexAttribI4svEXT System::GlVertexAttribI4svEXT
#define glVertexAttribI4ubvEXT System::GlVertexAttribI4ubvEXT
#define glVertexAttribI4uiEXT System::GlVertexAttribI4uiEXT
#define glVertexAttribI4uivEXT System::GlVertexAttribI4uivEXT
#define glVertexAttribI4usvEXT System::GlVertexAttribI4usvEXT
#define glVertexAttribIPointerEXT System::GlVertexAttribIPointerEXT

// (EXT 327) GL_EXT_draw_instanced

#define glDrawArraysInstancedEXT System::GlDrawArraysInstancedEXT
#define glDrawElementsInstancedEXT System::GlDrawElementsInstancedEXT

// (EXT 328) GL_EXT_packed_float

#define GL_R11F_G11F_B10F_EXT 0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV_EXT 0x8C3B
#define GL_RGBA_SIGNED_COMPONENTS_EXT 0x8C3C

// (EXT 329) GL_EXT_texture_array

#define GL_COMPARE_REF_DEPTH_TO_TEXTURE_EXT 0x884E
#define GL_MAX_ARRAY_TEXTURE_LAYERS_EXT 0x88FF
#define GL_TEXTURE_1D_ARRAY_EXT 0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY_EXT 0x8C19
#define GL_TEXTURE_2D_ARRAY_EXT 0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY_EXT 0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY_EXT 0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY_EXT 0x8C1D

#define glFramebufferTextureLayerEXT System::GlFramebufferTextureLayerEXT

// (EXT 330) GL_EXT_texture_buffer_object

#define GL_TEXTURE_BUFFER_EXT 0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE_EXT 0x8C2B
#define GL_TEXTURE_BINDING_BUFFER_EXT 0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING_EXT 0x8C2D
#define GL_TEXTURE_BUFFER_FORMAT_EXT 0x8C2E

#define glTexBufferEXT System::GlTexBufferEXT

// (EXT 331) GL_EXT_texture_compression_latc

#define GL_COMPRESSED_LUMINANCE_LATC1_EXT 0x8C70
#define GL_COMPRESSED_SIGNED_LUMINANCE_LATC1_EXT 0x8C71
#define GL_COMPRESSED_LUMINANCE_ALPHA_LATC2_EXT 0x8C72
#define GL_COMPRESSED_SIGNED_LUMINANCE_ALPHA_LATC2_EXT 0x8C73

// (EXT 332) GL_EXT_texture_compression_rgtc

#define GL_COMPRESSED_RED_RGTC1_EXT 0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1_EXT 0x8DBC
#define GL_COMPRESSED_RED_GREEN_RGTC2_EXT 0x8DBD
#define GL_COMPRESSED_SIGNED_RED_GREEN_RGTC2_EXT 0x8DBE

// (EXT 333) GL_EXT_texture_shared_exponent

#define GL_RGB9_E5_EXT 0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV_EXT 0x8C3E
#define GL_TEXTURE_SHARED_SIZE_EXT 0x8C3F

// (EXT 337) GL_EXT_framebuffer_sRGB

#define GL_FRAMEBUFFER_SRGB_EXT 0x8DB9
#define GL_FRAMEBUFFER_SRGB_CAPABLE_EXT 0x8DBA

// (EXT 340) GL_EXT_draw_buffers2

#define glColorMaskIndexedEXT System::GlColorMaskIndexedEXT
#define glDisableIndexedEXT System::GlDisableIndexedEXT
#define glEnableIndexedEXT System::GlEnableIndexedEXT
#define glGetBooleanIndexedvEXT System::GlGetBooleanIndexedvEXT
#define glGetIntegerIndexedvEXT System::GlGetIntegerIndexedvEXT
#define glIsEnabledIndexedEXT System::GlIsEnabledIndexedEXT

// (EXT 342) GL_EXT_bindable_uniform

#define GL_MAX_VERTEX_BINDABLE_UNIFORMS_EXT 0x8DE2
#define GL_MAX_FRAGMENT_BINDABLE_UNIFORMS_EXT 0x8DE3
#define GL_MAX_GEOMETRY_BINDABLE_UNIFORMS_EXT 0x8DE4
#define GL_MAX_BINDABLE_UNIFORM_SIZE_EXT 0x8DED
#define GL_UNIFORM_BUFFER_EXT 0x8DEE
#define GL_UNIFORM_BUFFER_BINDING_EXT 0x8DEF

#define glGetUniformBufferSizeEXT System::GlGetUniformBufferSizeEXT
#define glGetUniformOffsetEXT System::GlGetUniformOffsetEXT
#define glUniformBufferEXT System::GlUniformBufferEXT

// (EXT 343) GL_EXT_texture_integer

#define GL_RGBA32UI_EXT 0x8D70
#define GL_RGB32UI_EXT 0x8D71
#define GL_ALPHA32UI_EXT 0x8D72
#define GL_INTENSITY32UI_EXT 0x8D73
#define GL_LUMINANCE32UI_EXT 0x8D74
#define GL_LUMINANCE_ALPHA32UI_EXT 0x8D75
#define GL_RGBA16UI_EXT 0x8D76
#define GL_RGB16UI_EXT 0x8D77
#define GL_ALPHA16UI_EXT 0x8D78
#define GL_INTENSITY16UI_EXT 0x8D79
#define GL_LUMINANCE16UI_EXT 0x8D7A
#define GL_LUMINANCE_ALPHA16UI_EXT 0x8D7B
#define GL_RGBA8UI_EXT 0x8D7C
#define GL_RGB8UI_EXT 0x8D7D
#define GL_ALPHA8UI_EXT 0x8D7E
#define GL_INTENSITY8UI_EXT 0x8D7F
#define GL_LUMINANCE8UI_EXT 0x8D80
#define GL_LUMINANCE_ALPHA8UI_EXT 0x8D81
#define GL_RGBA32I_EXT 0x8D82
#define GL_RGB32I_EXT 0x8D83
#define GL_ALPHA32I_EXT 0x8D84
#define GL_INTENSITY32I_EXT 0x8D85
#define GL_LUMINANCE32I_EXT 0x8D86
#define GL_LUMINANCE_ALPHA32I_EXT 0x8D87
#define GL_RGBA16I_EXT 0x8D88
#define GL_RGB16I_EXT 0x8D89
#define GL_ALPHA16I_EXT 0x8D8A
#define GL_INTENSITY16I_EXT 0x8D8B
#define GL_LUMINANCE16I_EXT 0x8D8C
#define GL_LUMINANCE_ALPHA16I_EXT 0x8D8D
#define GL_RGBA8I_EXT 0x8D8E
#define GL_RGB8I_EXT 0x8D8F
#define GL_ALPHA8I_EXT 0x8D90
#define GL_INTENSITY8I_EXT 0x8D91
#define GL_LUMINANCE8I_EXT 0x8D92
#define GL_LUMINANCE_ALPHA8I_EXT 0x8D93
#define GL_RED_INTEGER_EXT 0x8D94
#define GL_GREEN_INTEGER_EXT 0x8D95
#define GL_BLUE_INTEGER_EXT 0x8D96
#define GL_ALPHA_INTEGER_EXT 0x8D97
#define GL_RGB_INTEGER_EXT 0x8D98
#define GL_RGBA_INTEGER_EXT 0x8D99
#define GL_BGR_INTEGER_EXT 0x8D9A
#define GL_BGRA_INTEGER_EXT 0x8D9B
#define GL_LUMINANCE_INTEGER_EXT 0x8D9C
#define GL_LUMINANCE_ALPHA_INTEGER_EXT 0x8D9D
#define GL_RGBA_INTEGER_MODE_EXT 0x8D9E

#define glClearColorIiEXT System::GlClearColorIiEXT
#define glClearColorIuiEXT System::GlClearColorIuiEXT
#define glGetTexParameterIivEXT System::GlGetTexParameterIivEXT
#define glGetTexParameterIuivEXT System::GlGetTexParameterIuivEXT
#define glTexParameterIivEXT System::GlTexParameterIivEXT
#define glTexParameterIuivEXT System::GlTexParameterIuivEXT

// (EXT 352) GL_EXT_transform_feedback

#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH_EXT 0x8C76
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE_EXT 0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_EXT 0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS_EXT 0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START_EXT 0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_EXT 0x8C85
#define GL_PRIMITIVES_GENERATED_EXT 0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_EXT 0x8C88
#define GL_RASTERIZER_DISCARD_EXT 0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_EXT 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_EXT 0x8C8B
#define GL_INTERLEAVED_ATTRIBS_EXT 0x8C8C
#define GL_SEPARATE_ATTRIBS_EXT 0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER_EXT 0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_EXT 0x8C8F

#define glBeginTransformFeedbackEXT System::GlBeginTransformFeedbackEXT
#define glBindBufferBaseEXT System::GlBindBufferBaseEXT
#define glBindBufferOffsetEXT System::GlBindBufferOffsetEXT
#define glBindBufferRangeEXT System::GlBindBufferRangeEXT
#define glEndTransformFeedbackEXT System::GlEndTransformFeedbackEXT
#define glGetTransformFeedbackVaryingEXT System::GlGetTransformFeedbackVaryingEXT
#define glTransformFeedbackVaryingsEXT System::GlTransformFeedbackVaryingsEXT

// (EXT 353) GL_EXT_direct_state_access

#define GL_PROGRAM_MATRIX_EXT 0x8E2D
#define GL_TRANSPOSE_PROGRAM_MATRIX_EXT 0x8E2E
#define GL_PROGRAM_MATRIX_STACK_DEPTH_EXT 0x8E2F

#define glBindMultiTextureEXT System::GlBindMultiTextureEXT
#define glCheckNamedFramebufferStatusEXT System::GlCheckNamedFramebufferStatusEXT
#define glClientAttribDefaultEXT System::GlClientAttribDefaultEXT
#define glCompressedMultiTexImage1DEXT System::GlCompressedMultiTexImage1DEXT
#define glCompressedMultiTexImage2DEXT System::GlCompressedMultiTexImage2DEXT
#define glCompressedMultiTexImage3DEXT System::GlCompressedMultiTexImage3DEXT
#define glCompressedMultiTexSubImage1DEXT System::GlCompressedMultiTexSubImage1DEXT
#define glCompressedMultiTexSubImage2DEXT System::GlCompressedMultiTexSubImage2DEXT
#define glCompressedMultiTexSubImage3DEXT System::GlCompressedMultiTexSubImage3DEXT
#define glCompressedTextureImage1DEXT System::GlCompressedTextureImage1DEXT
#define glCompressedTextureImage2DEXT System::GlCompressedTextureImage2DEXT
#define glCompressedTextureImage3DEXT System::GlCompressedTextureImage3DEXT
#define glCompressedTextureSubImage1DEXT System::GlCompressedTextureSubImage1DEXT
#define glCompressedTextureSubImage2DEXT System::GlCompressedTextureSubImage2DEXT
#define glCompressedTextureSubImage3DEXT System::GlCompressedTextureSubImage3DEXT
#define glCopyMultiTexImage1DEXT System::GlCopyMultiTexImage1DEXT
#define glCopyMultiTexImage2DEXT System::GlCopyMultiTexImage2DEXT
#define glCopyMultiTexSubImage1DEXT System::GlCopyMultiTexSubImage1DEXT
#define glCopyMultiTexSubImage2DEXT System::GlCopyMultiTexSubImage2DEXT
#define glCopyMultiTexSubImage3DEXT System::GlCopyMultiTexSubImage3DEXT
#define glCopyTextureImage1DEXT System::GlCopyTextureImage1DEXT
#define glCopyTextureImage2DEXT System::GlCopyTextureImage2DEXT
#define glCopyTextureSubImage1DEXT System::GlCopyTextureSubImage1DEXT
#define glCopyTextureSubImage2DEXT System::GlCopyTextureSubImage2DEXT
#define glCopyTextureSubImage3DEXT System::GlCopyTextureSubImage3DEXT
#define glDisableClientStateIndexedEXT System::GlDisableClientStateIndexedEXT
#define glDisableClientStateiEXT System::GlDisableClientStateiEXT
#define glDisableVertexArrayAttribEXT System::GlDisableVertexArrayAttribEXT
#define glDisableVertexArrayEXT System::GlDisableVertexArrayEXT
#define glEnableClientStateIndexedEXT System::GlEnableClientStateIndexedEXT
#define glEnableClientStateiEXT System::GlEnableClientStateiEXT
#define glEnableVertexArrayAttribEXT System::GlEnableVertexArrayAttribEXT
#define glEnableVertexArrayEXT System::GlEnableVertexArrayEXT
#define glFlushMappedNamedBufferRangeEXT System::GlFlushMappedNamedBufferRangeEXT
#define glFramebufferDrawBufferEXT System::GlFramebufferDrawBufferEXT
#define glFramebufferDrawBuffersEXT System::GlFramebufferDrawBuffersEXT
#define glFramebufferReadBufferEXT System::GlFramebufferReadBufferEXT
#define glGenerateMultiTexMipmapEXT System::GlGenerateMultiTexMipmapEXT
#define glGenerateTextureMipmapEXT System::GlGenerateTextureMipmapEXT
#define glGetCompressedMultiTexImageEXT System::GlGetCompressedMultiTexImageEXT
#define glGetCompressedTextureImageEXT System::GlGetCompressedTextureImageEXT
#define glGetDoubleIndexedvEXT System::GlGetDoubleIndexedvEXT
#define glGetDoublei_vEXT System::GlGetDoublei_vEXT
#define glGetFloatIndexedvEXT System::GlGetFloatIndexedvEXT
#define glGetFloati_vEXT System::GlGetFloati_vEXT
#define glGetFramebufferParameterivEXT System::GlGetFramebufferParameterivEXT
#define glGetMultiTexEnvfvEXT System::GlGetMultiTexEnvfvEXT
#define glGetMultiTexEnvivEXT System::GlGetMultiTexEnvivEXT
#define glGetMultiTexGendvEXT System::GlGetMultiTexGendvEXT
#define glGetMultiTexGenfvEXT System::GlGetMultiTexGenfvEXT
#define glGetMultiTexGenivEXT System::GlGetMultiTexGenivEXT
#define glGetMultiTexImageEXT System::GlGetMultiTexImageEXT
#define glGetMultiTexLevelParameterfvEXT System::GlGetMultiTexLevelParameterfvEXT
#define glGetMultiTexLevelParameterivEXT System::GlGetMultiTexLevelParameterivEXT
#define glGetMultiTexParameterIivEXT System::GlGetMultiTexParameterIivEXT
#define glGetMultiTexParameterIuivEXT System::GlGetMultiTexParameterIuivEXT
#define glGetMultiTexParameterfvEXT System::GlGetMultiTexParameterfvEXT
#define glGetMultiTexParameterivEXT System::GlGetMultiTexParameterivEXT
#define glGetNamedBufferParameterivEXT System::GlGetNamedBufferParameterivEXT
#define glGetNamedBufferPointervEXT System::GlGetNamedBufferPointervEXT
#define glGetNamedBufferSubDataEXT System::GlGetNamedBufferSubDataEXT
#define glGetNamedFramebufferAttachmentParameterivEXT System::GlGetNamedFramebufferAttachmentParameterivEXT
#define glGetNamedProgramLocalParameterIivEXT System::GlGetNamedProgramLocalParameterIivEXT
#define glGetNamedProgramLocalParameterIuivEXT System::GlGetNamedProgramLocalParameterIuivEXT
#define glGetNamedProgramLocalParameterdvEXT System::GlGetNamedProgramLocalParameterdvEXT
#define glGetNamedProgramLocalParameterfvEXT System::GlGetNamedProgramLocalParameterfvEXT
#define glGetNamedProgramStringEXT System::GlGetNamedProgramStringEXT
#define glGetNamedProgramivEXT System::GlGetNamedProgramivEXT
#define glGetNamedRenderbufferParameterivEXT System::GlGetNamedRenderbufferParameterivEXT
#define glGetPointerIndexedvEXT System::GlGetPointerIndexedvEXT
#define glGetPointeri_vEXT System::GlGetPointeri_vEXT
#define glGetTextureImageEXT System::GlGetTextureImageEXT
#define glGetTextureLevelParameterfvEXT System::GlGetTextureLevelParameterfvEXT
#define glGetTextureLevelParameterivEXT System::GlGetTextureLevelParameterivEXT
#define glGetTextureParameterIivEXT System::GlGetTextureParameterIivEXT
#define glGetTextureParameterIuivEXT System::GlGetTextureParameterIuivEXT
#define glGetTextureParameterfvEXT System::GlGetTextureParameterfvEXT
#define glGetTextureParameterivEXT System::GlGetTextureParameterivEXT
#define glGetVertexArrayIntegeri_vEXT System::GlGetVertexArrayIntegeri_vEXT
#define glGetVertexArrayIntegervEXT System::GlGetVertexArrayIntegervEXT
#define glGetVertexArrayPointeri_vEXT System::GlGetVertexArrayPointeri_vEXT
#define glGetVertexArrayPointervEXT System::GlGetVertexArrayPointervEXT
#define glMapNamedBufferEXT System::GlMapNamedBufferEXT
#define glMapNamedBufferRangeEXT System::GlMapNamedBufferRangeEXT
#define glMatrixFrustumEXT System::GlMatrixFrustumEXT
#define glMatrixLoadIdentityEXT System::GlMatrixLoadIdentityEXT
#define glMatrixLoadTransposedEXT System::GlMatrixLoadTransposedEXT
#define glMatrixLoadTransposefEXT System::GlMatrixLoadTransposefEXT
#define glMatrixLoaddEXT System::GlMatrixLoaddEXT
#define glMatrixLoadfEXT System::GlMatrixLoadfEXT
#define glMatrixMultTransposedEXT System::GlMatrixMultTransposedEXT
#define glMatrixMultTransposefEXT System::GlMatrixMultTransposefEXT
#define glMatrixMultdEXT System::GlMatrixMultdEXT
#define glMatrixMultfEXT System::GlMatrixMultfEXT
#define glMatrixOrthoEXT System::GlMatrixOrthoEXT
#define glMatrixPopEXT System::GlMatrixPopEXT
#define glMatrixPushEXT System::GlMatrixPushEXT
#define glMatrixRotatedEXT System::GlMatrixRotatedEXT
#define glMatrixRotatefEXT System::GlMatrixRotatefEXT
#define glMatrixScaledEXT System::GlMatrixScaledEXT
#define glMatrixScalefEXT System::GlMatrixScalefEXT
#define glMatrixTranslatedEXT System::GlMatrixTranslatedEXT
#define glMatrixTranslatefEXT System::GlMatrixTranslatefEXT
#define glMultiTexBufferEXT System::GlMultiTexBufferEXT
#define glMultiTexCoordPointerEXT System::GlMultiTexCoordPointerEXT
#define glMultiTexEnvfEXT System::GlMultiTexEnvfEXT
#define glMultiTexEnvfvEXT System::GlMultiTexEnvfvEXT
#define glMultiTexEnviEXT System::GlMultiTexEnviEXT
#define glMultiTexEnvivEXT System::GlMultiTexEnvivEXT
#define glMultiTexGendEXT System::GlMultiTexGendEXT
#define glMultiTexGendvEXT System::GlMultiTexGendvEXT
#define glMultiTexGenfEXT System::GlMultiTexGenfEXT
#define glMultiTexGenfvEXT System::GlMultiTexGenfvEXT
#define glMultiTexGeniEXT System::GlMultiTexGeniEXT
#define glMultiTexGenivEXT System::GlMultiTexGenivEXT
#define glMultiTexImage1DEXT System::GlMultiTexImage1DEXT
#define glMultiTexImage2DEXT System::GlMultiTexImage2DEXT
#define glMultiTexImage3DEXT System::GlMultiTexImage3DEXT
#define glMultiTexParameterIivEXT System::GlMultiTexParameterIivEXT
#define glMultiTexParameterIuivEXT System::GlMultiTexParameterIuivEXT
#define glMultiTexParameterfEXT System::GlMultiTexParameterfEXT
#define glMultiTexParameterfvEXT System::GlMultiTexParameterfvEXT
#define glMultiTexParameteriEXT System::GlMultiTexParameteriEXT
#define glMultiTexParameterivEXT System::GlMultiTexParameterivEXT
#define glMultiTexRenderbufferEXT System::GlMultiTexRenderbufferEXT
#define glMultiTexSubImage1DEXT System::GlMultiTexSubImage1DEXT
#define glMultiTexSubImage2DEXT System::GlMultiTexSubImage2DEXT
#define glMultiTexSubImage3DEXT System::GlMultiTexSubImage3DEXT
#define glNamedBufferDataEXT System::GlNamedBufferDataEXT
#define glNamedBufferSubDataEXT System::GlNamedBufferSubDataEXT
#define glNamedCopyBufferSubDataEXT System::GlNamedCopyBufferSubDataEXT
#define glNamedFramebufferRenderbufferEXT System::GlNamedFramebufferRenderbufferEXT
#define glNamedFramebufferTexture1DEXT System::GlNamedFramebufferTexture1DEXT
#define glNamedFramebufferTexture2DEXT System::GlNamedFramebufferTexture2DEXT
#define glNamedFramebufferTexture3DEXT System::GlNamedFramebufferTexture3DEXT
#define glNamedFramebufferTextureEXT System::GlNamedFramebufferTextureEXT
#define glNamedFramebufferTextureFaceEXT System::GlNamedFramebufferTextureFaceEXT
#define glNamedFramebufferTextureLayerEXT System::GlNamedFramebufferTextureLayerEXT
#define glNamedProgramLocalParameter4dEXT System::GlNamedProgramLocalParameter4dEXT
#define glNamedProgramLocalParameter4dvEXT System::GlNamedProgramLocalParameter4dvEXT
#define glNamedProgramLocalParameter4fEXT System::GlNamedProgramLocalParameter4fEXT
#define glNamedProgramLocalParameter4fvEXT System::GlNamedProgramLocalParameter4fvEXT
#define glNamedProgramLocalParameterI4iEXT System::GlNamedProgramLocalParameterI4iEXT
#define glNamedProgramLocalParameterI4ivEXT System::GlNamedProgramLocalParameterI4ivEXT
#define glNamedProgramLocalParameterI4uiEXT System::GlNamedProgramLocalParameterI4uiEXT
#define glNamedProgramLocalParameterI4uivEXT System::GlNamedProgramLocalParameterI4uivEXT
#define glNamedProgramLocalParameters4fvEXT System::GlNamedProgramLocalParameters4fvEXT
#define glNamedProgramLocalParametersI4ivEXT System::GlNamedProgramLocalParametersI4ivEXT
#define glNamedProgramLocalParametersI4uivEXT System::GlNamedProgramLocalParametersI4uivEXT
#define glNamedProgramStringEXT System::GlNamedProgramStringEXT
#define glNamedRenderbufferStorageEXT System::GlNamedRenderbufferStorageEXT
#define glNamedRenderbufferStorageMultisampleCoverageEXT System::GlNamedRenderbufferStorageMultisampleCoverageEXT
#define glNamedRenderbufferStorageMultisampleEXT System::GlNamedRenderbufferStorageMultisampleEXT
#define glProgramUniform1fEXT System::GlProgramUniform1fEXT
#define glProgramUniform1fvEXT System::GlProgramUniform1fvEXT
#define glProgramUniform1iEXT System::GlProgramUniform1iEXT
#define glProgramUniform1ivEXT System::GlProgramUniform1ivEXT
#define glProgramUniform1uiEXT System::GlProgramUniform1uiEXT
#define glProgramUniform1uivEXT System::GlProgramUniform1uivEXT
#define glProgramUniform2fEXT System::GlProgramUniform2fEXT
#define glProgramUniform2fvEXT System::GlProgramUniform2fvEXT
#define glProgramUniform2iEXT System::GlProgramUniform2iEXT
#define glProgramUniform2ivEXT System::GlProgramUniform2ivEXT
#define glProgramUniform2uiEXT System::GlProgramUniform2uiEXT
#define glProgramUniform2uivEXT System::GlProgramUniform2uivEXT
#define glProgramUniform3fEXT System::GlProgramUniform3fEXT
#define glProgramUniform3fvEXT System::GlProgramUniform3fvEXT
#define glProgramUniform3iEXT System::GlProgramUniform3iEXT
#define glProgramUniform3ivEXT System::GlProgramUniform3ivEXT
#define glProgramUniform3uiEXT System::GlProgramUniform3uiEXT
#define glProgramUniform3uivEXT System::GlProgramUniform3uivEXT
#define glProgramUniform4fEXT System::GlProgramUniform4fEXT
#define glProgramUniform4fvEXT System::GlProgramUniform4fvEXT
#define glProgramUniform4iEXT System::GlProgramUniform4iEXT
#define glProgramUniform4ivEXT System::GlProgramUniform4ivEXT
#define glProgramUniform4uiEXT System::GlProgramUniform4uiEXT
#define glProgramUniform4uivEXT System::GlProgramUniform4uivEXT
#define glProgramUniformMatrix2fvEXT System::GlProgramUniformMatrix2fvEXT
#define glProgramUniformMatrix2x3fvEXT System::GlProgramUniformMatrix2x3fvEXT
#define glProgramUniformMatrix2x4fvEXT System::GlProgramUniformMatrix2x4fvEXT
#define glProgramUniformMatrix3fvEXT System::GlProgramUniformMatrix3fvEXT
#define glProgramUniformMatrix3x2fvEXT System::GlProgramUniformMatrix3x2fvEXT
#define glProgramUniformMatrix3x4fvEXT System::GlProgramUniformMatrix3x4fvEXT
#define glProgramUniformMatrix4fvEXT System::GlProgramUniformMatrix4fvEXT
#define glProgramUniformMatrix4x2fvEXT System::GlProgramUniformMatrix4x2fvEXT
#define glProgramUniformMatrix4x3fvEXT System::GlProgramUniformMatrix4x3fvEXT
#define glPushClientAttribDefaultEXT System::GlPushClientAttribDefaultEXT
#define glTextureBufferEXT System::GlTextureBufferEXT
#define glTextureImage1DEXT System::GlTextureImage1DEXT
#define glTextureImage2DEXT System::GlTextureImage2DEXT
#define glTextureImage3DEXT System::GlTextureImage3DEXT
#define glTextureParameterIivEXT System::GlTextureParameterIivEXT
#define glTextureParameterIuivEXT System::GlTextureParameterIuivEXT
#define glTextureParameterfEXT System::GlTextureParameterfEXT
#define glTextureParameterfvEXT System::GlTextureParameterfvEXT
#define glTextureParameteriEXT System::GlTextureParameteriEXT
#define glTextureParameterivEXT System::GlTextureParameterivEXT
#define glTextureRenderbufferEXT System::GlTextureRenderbufferEXT
#define glTextureSubImage1DEXT System::GlTextureSubImage1DEXT
#define glTextureSubImage2DEXT System::GlTextureSubImage2DEXT
#define glTextureSubImage3DEXT System::GlTextureSubImage3DEXT
#define glUnmapNamedBufferEXT System::GlUnmapNamedBufferEXT
#define glVertexArrayColorOffsetEXT System::GlVertexArrayColorOffsetEXT
#define glVertexArrayEdgeFlagOffsetEXT System::GlVertexArrayEdgeFlagOffsetEXT
#define glVertexArrayFogCoordOffsetEXT System::GlVertexArrayFogCoordOffsetEXT
#define glVertexArrayIndexOffsetEXT System::GlVertexArrayIndexOffsetEXT
#define glVertexArrayMultiTexCoordOffsetEXT System::GlVertexArrayMultiTexCoordOffsetEXT
#define glVertexArrayNormalOffsetEXT System::GlVertexArrayNormalOffsetEXT
#define glVertexArraySecondaryColorOffsetEXT System::GlVertexArraySecondaryColorOffsetEXT
#define glVertexArrayTexCoordOffsetEXT System::GlVertexArrayTexCoordOffsetEXT
#define glVertexArrayVertexAttribDivisorEXT System::GlVertexArrayVertexAttribDivisorEXT
#define glVertexArrayVertexAttribIOffsetEXT System::GlVertexArrayVertexAttribIOffsetEXT
#define glVertexArrayVertexAttribOffsetEXT System::GlVertexArrayVertexAttribOffsetEXT
#define glVertexArrayVertexOffsetEXT System::GlVertexArrayVertexOffsetEXT

// (EXT 354) GL_EXT_vertex_array_bgra

#define GL_BGRA 0x80E1

// (EXT 356) GL_EXT_texture_swizzle

#define GL_TEXTURE_SWIZZLE_R_EXT 0x8E42
#define GL_TEXTURE_SWIZZLE_G_EXT 0x8E43
#define GL_TEXTURE_SWIZZLE_B_EXT 0x8E44
#define GL_TEXTURE_SWIZZLE_A_EXT 0x8E45
#define GL_TEXTURE_SWIZZLE_RGBA_EXT 0x8E46

// (EXT 364) GL_EXT_provoking_vertex

#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION_EXT 0x8E4C
#define GL_FIRST_VERTEX_CONVENTION_EXT 0x8E4D
#define GL_LAST_VERTEX_CONVENTION_EXT 0x8E4E
#define GL_PROVOKING_VERTEX_EXT 0x8E4F

#define glProvokingVertexEXT System::GlProvokingVertexEXT

// (EXT 365) GL_EXT_texture_snorm

#define GL_RED_SNORM 0x8F90
#define GL_RG_SNORM 0x8F91
#define GL_RGB_SNORM 0x8F92
#define GL_RGBA_SNORM 0x8F93
#define GL_R8_SNORM 0x8F94
#define GL_RG8_SNORM 0x8F95
#define GL_RGB8_SNORM 0x8F96
#define GL_RGBA8_SNORM 0x8F97
#define GL_R16_SNORM 0x8F98
#define GL_RG16_SNORM 0x8F99
#define GL_RGB16_SNORM 0x8F9A
#define GL_RGBA16_SNORM 0x8F9B
#define GL_SIGNED_NORMALIZED 0x8F9C
#define GL_ALPHA_SNORM 0x9010
#define GL_LUMINANCE_SNORM 0x9011
#define GL_LUMINANCE_ALPHA_SNORM 0x9012
#define GL_INTENSITY_SNORM 0x9013
#define GL_ALPHA8_SNORM 0x9014
#define GL_LUMINANCE8_SNORM 0x9015
#define GL_LUMINANCE8_ALPHA8_SNORM 0x9016
#define GL_INTENSITY8_SNORM 0x9017
#define GL_ALPHA16_SNORM 0x9018
#define GL_LUMINANCE16_SNORM 0x9019
#define GL_LUMINANCE16_ALPHA16_SNORM 0x901A
#define GL_INTENSITY16_SNORM 0x901B

// (EXT 377) GL_EXT_separate_shader_objects

#define GL_ACTIVE_PROGRAM_EXT 0x8B8D

#define glActiveProgramEXT System::GlActiveProgramEXT
#define glCreateShaderProgramEXT System::GlCreateShaderProgramEXT
#define glUseShaderProgramEXT System::GlUseShaderProgramEXT

// (EXT 386) GL_EXT_shader_image_load_store

#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT_EXT 0x00000001
#define GL_ELEMENT_ARRAY_BARRIER_BIT_EXT 0x00000002
#define GL_UNIFORM_BARRIER_BIT_EXT 0x00000004
#define GL_TEXTURE_FETCH_BARRIER_BIT_EXT 0x00000008
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT_EXT 0x00000020
#define GL_COMMAND_BARRIER_BIT_EXT 0x00000040
#define GL_PIXEL_BUFFER_BARRIER_BIT_EXT 0x00000080
#define GL_TEXTURE_UPDATE_BARRIER_BIT_EXT 0x00000100
#define GL_BUFFER_UPDATE_BARRIER_BIT_EXT 0x00000200
#define GL_FRAMEBUFFER_BARRIER_BIT_EXT 0x00000400
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT_EXT 0x00000800
#define GL_ATOMIC_COUNTER_BARRIER_BIT_EXT 0x00001000
#define GL_MAX_IMAGE_UNITS_EXT 0x8F38
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS_EXT 0x8F39
#define GL_IMAGE_BINDING_NAME_EXT 0x8F3A
#define GL_IMAGE_BINDING_LEVEL_EXT 0x8F3B
#define GL_IMAGE_BINDING_LAYERED_EXT 0x8F3C
#define GL_IMAGE_BINDING_LAYER_EXT 0x8F3D
#define GL_IMAGE_BINDING_ACCESS_EXT 0x8F3E
#define GL_IMAGE_1D_EXT 0x904C
#define GL_IMAGE_2D_EXT 0x904D
#define GL_IMAGE_3D_EXT 0x904E
#define GL_IMAGE_2D_RECT_EXT 0x904F
#define GL_IMAGE_CUBE_EXT 0x9050
#define GL_IMAGE_BUFFER_EXT 0x9051
#define GL_IMAGE_1D_ARRAY_EXT 0x9052
#define GL_IMAGE_2D_ARRAY_EXT 0x9053
#define GL_IMAGE_CUBE_MAP_ARRAY_EXT 0x9054
#define GL_IMAGE_2D_MULTISAMPLE_EXT 0x9055
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY_EXT 0x9056
#define GL_INT_IMAGE_1D_EXT 0x9057
#define GL_INT_IMAGE_2D_EXT 0x9058
#define GL_INT_IMAGE_3D_EXT 0x9059
#define GL_INT_IMAGE_2D_RECT_EXT 0x905A
#define GL_INT_IMAGE_CUBE_EXT 0x905B
#define GL_INT_IMAGE_BUFFER_EXT 0x905C
#define GL_INT_IMAGE_1D_ARRAY_EXT 0x905D
#define GL_INT_IMAGE_2D_ARRAY_EXT 0x905E
#define GL_INT_IMAGE_CUBE_MAP_ARRAY_EXT 0x905F
#define GL_INT_IMAGE_2D_MULTISAMPLE_EXT 0x9060
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT 0x9061
#define GL_UNSIGNED_INT_IMAGE_1D_EXT 0x9062
#define GL_UNSIGNED_INT_IMAGE_2D_EXT 0x9063
#define GL_UNSIGNED_INT_IMAGE_3D_EXT 0x9064
#define GL_UNSIGNED_INT_IMAGE_2D_RECT_EXT 0x9065
#define GL_UNSIGNED_INT_IMAGE_CUBE_EXT 0x9066
#define GL_UNSIGNED_INT_IMAGE_BUFFER_EXT 0x9067
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY_EXT 0x9068
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY_EXT 0x9069
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY_EXT 0x906A
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_EXT 0x906B
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT 0x906C
#define GL_MAX_IMAGE_SAMPLES_EXT 0x906D
#define GL_IMAGE_BINDING_FORMAT_EXT 0x906E
#define GL_ALL_BARRIER_BITS_EXT 0xFFFFFFFF

#define glBindImageTextureEXT System::GlBindImageTextureEXT
#define glMemoryBarrierEXT System::GlMemoryBarrierEXT

// (EXT 387) GL_EXT_vertex_attrib_64bit

#define GL_DOUBLE_MAT2_EXT 0x8F46
#define GL_DOUBLE_MAT3_EXT 0x8F47
#define GL_DOUBLE_MAT4_EXT 0x8F48
#define GL_DOUBLE_MAT2x3_EXT 0x8F49
#define GL_DOUBLE_MAT2x4_EXT 0x8F4A
#define GL_DOUBLE_MAT3x2_EXT 0x8F4B
#define GL_DOUBLE_MAT3x4_EXT 0x8F4C
#define GL_DOUBLE_MAT4x2_EXT 0x8F4D
#define GL_DOUBLE_MAT4x3_EXT 0x8F4E
#define GL_DOUBLE_VEC2_EXT 0x8FFC
#define GL_DOUBLE_VEC3_EXT 0x8FFD
#define GL_DOUBLE_VEC4_EXT 0x8FFE

#define glGetVertexAttribLdvEXT System::GlGetVertexAttribLdvEXT
#define glVertexArrayVertexAttribLOffsetEXT System::GlVertexArrayVertexAttribLOffsetEXT
#define glVertexAttribL1dEXT System::GlVertexAttribL1dEXT
#define glVertexAttribL1dvEXT System::GlVertexAttribL1dvEXT
#define glVertexAttribL2dEXT System::GlVertexAttribL2dEXT
#define glVertexAttribL2dvEXT System::GlVertexAttribL2dvEXT
#define glVertexAttribL3dEXT System::GlVertexAttribL3dEXT
#define glVertexAttribL3dvEXT System::GlVertexAttribL3dvEXT
#define glVertexAttribL4dEXT System::GlVertexAttribL4dEXT
#define glVertexAttribL4dvEXT System::GlVertexAttribL4dvEXT
#define glVertexAttribLPointerEXT System::GlVertexAttribLPointerEXT

// (EXT 402) GL_EXT_texture_sRGB_decode

#define GL_TEXTURE_SRGB_DECODE_EXT 0x8A48
#define GL_DECODE_EXT 0x8A49
#define GL_SKIP_DECODE_EXT 0x8A4A

// (EXT 406) GL_EXT_x11_sync_object

#define GL_SYNC_X11_FENCE_EXT 0x90E1

#define glImportSyncEXT System::GlImportSyncEXT

// (EXT 409) GL_EXT_framebuffer_multisample_blit_scaled

#define GL_SCALED_RESOLVE_FASTEST_EXT 0x90BA
#define GL_SCALED_RESOLVE_NICEST_EXT 0x90BB

// (EXT 439) GL_EXT_debug_label

#define GL_PROGRAM_PIPELINE_OBJECT_EXT 0x8A4F
#define GL_PROGRAM_OBJECT_EXT 0x8B40
#define GL_SHADER_OBJECT_EXT 0x8B48
#define GL_BUFFER_OBJECT_EXT 0x9151
#define GL_QUERY_OBJECT_EXT 0x9153
#define GL_VERTEX_ARRAY_OBJECT_EXT 0x9154

#define glGetObjectLabelEXT System::GlGetObjectLabelEXT
#define glLabelObjectEXT System::GlLabelObjectEXT

// (EXT 440) GL_EXT_debug_marker

#define glInsertEventMarkerEXT System::GlInsertEventMarkerEXT
#define glPopGroupMarkerEXT System::GlPopGroupMarkerEXT
#define glPushGroupMarkerEXT System::GlPushGroupMarkerEXT

// (EXT 460) GL_EXT_polygon_offset_clamp

#define GL_POLYGON_OFFSET_CLAMP_EXT 0x8E1B

#define glPolygonOffsetClampEXT System::GlPolygonOffsetClampEXT

// (EXT 462) GL_EXT_raster_multisample

#define GL_COLOR_SAMPLES_NV 0x8E20
#define GL_RASTER_MULTISAMPLE_EXT 0x9327
#define GL_RASTER_SAMPLES_EXT 0x9328
#define GL_MAX_RASTER_SAMPLES_EXT 0x9329
#define GL_RASTER_FIXED_SAMPLE_LOCATIONS_EXT 0x932A
#define GL_MULTISAMPLE_RASTERIZATION_ALLOWED_EXT 0x932B
#define GL_EFFECTIVE_RASTER_SAMPLES_EXT 0x932C
#define GL_DEPTH_SAMPLES_NV 0x932D
#define GL_STENCIL_SAMPLES_NV 0x932E
#define GL_MIXED_DEPTH_SAMPLES_SUPPORTED_NV 0x932F
#define GL_MIXED_STENCIL_SAMPLES_SUPPORTED_NV 0x9330
#define GL_COVERAGE_MODULATION_TABLE_NV 0x9331
#define GL_COVERAGE_MODULATION_NV 0x9332
#define GL_COVERAGE_MODULATION_TABLE_SIZE_NV 0x9333

#define glCoverageModulationNV System::GlCoverageModulationNV
#define glCoverageModulationTableNV System::GlCoverageModulationTableNV
#define glGetCoverageModulationTableNV System::GlGetCoverageModulationTableNV
#define glRasterSamplesEXT System::GlRasterSamplesEXT

// (EXT 464) GL_EXT_texture_filter_minmax

#define GL_TEXTURE_REDUCTION_MODE_EXT 0x9366
#define GL_WEIGHTED_AVERAGE_EXT 0x9367

// GL_EXT_Cg_shader

#define GL_CG_VERTEX_SHADER_EXT 0x890E
#define GL_CG_FRAGMENT_SHADER_EXT 0x890F

#endif  // SYSTEM_HELPER_GL_EXT_EXTENSIONS_MACRO_H

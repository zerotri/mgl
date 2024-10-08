/*
 * Copyright (C) Michael Larson on 1/6/2022
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * pixel_utils.h
 * MGL
 *
 */

#ifndef pixel_utils_h
#define pixel_utils_h

#include "glcorearb.h"

typedef enum MTLPixelFormat_t MTLPixelFormat;

GLuint numComponentsForFormat(GLenum format);

GLboolean validFormat(GLuint format);
GLboolean validFormatType(GLuint format, GLuint type);
GLboolean validInternalFormat(GLint internalformat);

GLuint sizeForType(GLenum type);
GLuint sizeForFormatType(GLenum format, GLenum type);
GLuint sizeForInternalFormat(GLenum internalformat, GLenum format, GLenum type);

GLuint bicountForFormatType(GLenum format, GLenum type, GLenum component);
GLuint bitcountForInternalFormat(GLenum internalformat, GLenum component);

GLenum internalFormatForGLFormatType(GLenum format, GLenum type);

MTLPixelFormat mtlFormatForGLInternalFormat(GLenum internal_format);
MTLPixelFormat mtlPixelFormatForGLFormatType(GLenum gl_format, GLenum gl_type);


#ifndef API_AVAILABLE
#define API_AVAILABLE(...) __API_AVAILABLE_GET_MACRO(__VA_ARGS__,__API_AVAILABLE7, __API_AVAILABLE6, __API_AVAILABLE5, __API_AVAILABLE4, __API_AVAILABLE3, __API_AVAILABLE2, __API_AVAILABLE1, 0)(__VA_ARGS__)
#endif

#ifndef API_UNAVAILABLE
#define API_UNAVAILABLE(...) __API_UNAVAILABLE_GET_MACRO(__VA_ARGS__,__API_UNAVAILABLE7,__API_UNAVAILABLE6, __API_UNAVAILABLE5, __API_UNAVAILABLE4,__API_UNAVAILABLE3,__API_UNAVAILABLE2,__API_UNAVAILABLE1, 0)(__VA_ARGS__)
#endif


typedef enum MTLPixelFormat_t {
    MTLPixelFormatInvalid = 0,

    /* Normal 8 bit formats */

    MTLPixelFormatA8Unorm      = 1,

    MTLPixelFormatR8Unorm                            = 10,
    MTLPixelFormatR8Unorm_sRGB  = 11,
    MTLPixelFormatR8Snorm      = 12,
    MTLPixelFormatR8Uint       = 13,
    MTLPixelFormatR8Sint       = 14,

    /* Normal 16 bit formats */

    MTLPixelFormatR16Unorm     = 20,
    MTLPixelFormatR16Snorm     = 22,
    MTLPixelFormatR16Uint      = 23,
    MTLPixelFormatR16Sint      = 24,
    MTLPixelFormatR16Float     = 25,

    MTLPixelFormatRG8Unorm                            = 30,
    MTLPixelFormatRG8Unorm_sRGB = 31,
    MTLPixelFormatRG8Snorm                            = 32,
    MTLPixelFormatRG8Uint                             = 33,
    MTLPixelFormatRG8Sint                             = 34,

    /* Packed 16 bit formats */

    MTLPixelFormatB5G6R5Unorm = 40,
    MTLPixelFormatA1BGR5Unorm = 41,
    MTLPixelFormatABGR4Unorm  = 42,
    MTLPixelFormatBGR5A1Unorm = 43,

    /* Normal 32 bit formats */

    MTLPixelFormatR32Uint  = 53,
    MTLPixelFormatR32Sint  = 54,
    MTLPixelFormatR32Float = 55,

    MTLPixelFormatRG16Unorm  = 60,
    MTLPixelFormatRG16Snorm  = 62,
    MTLPixelFormatRG16Uint   = 63,
    MTLPixelFormatRG16Sint   = 64,
    MTLPixelFormatRG16Float  = 65,

    MTLPixelFormatRGBA8Unorm      = 70,
    MTLPixelFormatRGBA8Unorm_sRGB = 71,
    MTLPixelFormatRGBA8Snorm      = 72,
    MTLPixelFormatRGBA8Uint       = 73,
    MTLPixelFormatRGBA8Sint       = 74,

    MTLPixelFormatBGRA8Unorm      = 80,
    MTLPixelFormatBGRA8Unorm_sRGB = 81,

    /* Packed 32 bit formats */

    MTLPixelFormatRGB10A2Unorm = 90,
    MTLPixelFormatRGB10A2Uint  = 91,

    MTLPixelFormatRG11B10Float = 92,
    MTLPixelFormatRGB9E5Float = 93,

    MTLPixelFormatBGR10A2Unorm  = 94,

    MTLPixelFormatBGR10_XR      = 554,
    MTLPixelFormatBGR10_XR_sRGB = 555,

    /* Normal 64 bit formats */

    MTLPixelFormatRG32Uint  = 103,
    MTLPixelFormatRG32Sint  = 104,
    MTLPixelFormatRG32Float = 105,

    MTLPixelFormatRGBA16Unorm  = 110,
    MTLPixelFormatRGBA16Snorm  = 112,
    MTLPixelFormatRGBA16Uint   = 113,
    MTLPixelFormatRGBA16Sint   = 114,
    MTLPixelFormatRGBA16Float  = 115,

    MTLPixelFormatBGRA10_XR      = 552,
    MTLPixelFormatBGRA10_XR_sRGB = 553,

    /* Normal 128 bit formats */

    MTLPixelFormatRGBA32Uint  = 123,
    MTLPixelFormatRGBA32Sint  = 124,
    MTLPixelFormatRGBA32Float = 125,

    /* Compressed formats. */

    /* S3TC/DXT */
    MTLPixelFormatBC1_RGBA              = 130,
    MTLPixelFormatBC1_RGBA_sRGB         = 131,
    MTLPixelFormatBC2_RGBA              = 132,
    MTLPixelFormatBC2_RGBA_sRGB         = 133,
    MTLPixelFormatBC3_RGBA              = 134,
    MTLPixelFormatBC3_RGBA_sRGB         = 135,

    /* RGTC */
    MTLPixelFormatBC4_RUnorm            = 140,
    MTLPixelFormatBC4_RSnorm            = 141,
    MTLPixelFormatBC5_RGUnorm           = 142,
    MTLPixelFormatBC5_RGSnorm           = 143,

    /* BPTC */
    MTLPixelFormatBC6H_RGBFloat         = 150,
    MTLPixelFormatBC6H_RGBUfloat        = 151,
    MTLPixelFormatBC7_RGBAUnorm         = 152,
    MTLPixelFormatBC7_RGBAUnorm_sRGB    = 153,

    /* PVRTC */
    MTLPixelFormatPVRTC_RGB_2BPP        = 160,
    MTLPixelFormatPVRTC_RGB_2BPP_sRGB   = 161,
    MTLPixelFormatPVRTC_RGB_4BPP        = 162,
    MTLPixelFormatPVRTC_RGB_4BPP_sRGB   = 163,
    MTLPixelFormatPVRTC_RGBA_2BPP       = 164,
    MTLPixelFormatPVRTC_RGBA_2BPP_sRGB  = 165,
    MTLPixelFormatPVRTC_RGBA_4BPP       = 166,
    MTLPixelFormatPVRTC_RGBA_4BPP_sRGB  = 167,

    /* ETC2 */
    MTLPixelFormatEAC_R11Unorm          = 170,
    MTLPixelFormatEAC_R11Snorm          = 172,
    MTLPixelFormatEAC_RG11Unorm         = 174,
    MTLPixelFormatEAC_RG11Snorm         = 176,
    MTLPixelFormatEAC_RGBA8             = 178,
    MTLPixelFormatEAC_RGBA8_sRGB        = 179,

    MTLPixelFormatETC2_RGB8             = 180,
    MTLPixelFormatETC2_RGB8_sRGB        = 181,
    MTLPixelFormatETC2_RGB8A1           = 182,
    MTLPixelFormatETC2_RGB8A1_sRGB      = 183,

    /* ASTC */
    MTLPixelFormatASTC_4x4_sRGB         = 186,
    MTLPixelFormatASTC_5x4_sRGB         = 187,
    MTLPixelFormatASTC_5x5_sRGB         = 188,
    MTLPixelFormatASTC_6x5_sRGB         = 189,
    MTLPixelFormatASTC_6x6_sRGB         = 190,
    MTLPixelFormatASTC_8x5_sRGB         = 192,
    MTLPixelFormatASTC_8x6_sRGB         = 193,
    MTLPixelFormatASTC_8x8_sRGB         = 194,
    MTLPixelFormatASTC_10x5_sRGB        = 195,
    MTLPixelFormatASTC_10x6_sRGB        = 196,
    MTLPixelFormatASTC_10x8_sRGB        = 197,
    MTLPixelFormatASTC_10x10_sRGB       = 198,
    MTLPixelFormatASTC_12x10_sRGB       = 199,
    MTLPixelFormatASTC_12x12_sRGB       = 200,

    MTLPixelFormatASTC_4x4_LDR          = 204,
    MTLPixelFormatASTC_5x4_LDR          = 205,
    MTLPixelFormatASTC_5x5_LDR          = 206,
    MTLPixelFormatASTC_6x5_LDR          = 207,
    MTLPixelFormatASTC_6x6_LDR          = 208,
    MTLPixelFormatASTC_8x5_LDR          = 210,
    MTLPixelFormatASTC_8x6_LDR          = 211,
    MTLPixelFormatASTC_8x8_LDR          = 212,
    MTLPixelFormatASTC_10x5_LDR         = 213,
    MTLPixelFormatASTC_10x6_LDR         = 214,
    MTLPixelFormatASTC_10x8_LDR         = 215,
    MTLPixelFormatASTC_10x10_LDR        = 216,
    MTLPixelFormatASTC_12x10_LDR        = 217,
    MTLPixelFormatASTC_12x12_LDR        = 218,


    // ASTC HDR (High Dynamic Range) Formats
    MTLPixelFormatASTC_4x4_HDR          = 222,
    MTLPixelFormatASTC_5x4_HDR          = 223,
    MTLPixelFormatASTC_5x5_HDR          = 224,
    MTLPixelFormatASTC_6x5_HDR          = 225,
    MTLPixelFormatASTC_6x6_HDR          = 226,
    MTLPixelFormatASTC_8x5_HDR          = 228,
    MTLPixelFormatASTC_8x6_HDR          = 229,
    MTLPixelFormatASTC_8x8_HDR          = 230,
    MTLPixelFormatASTC_10x5_HDR         = 231,
    MTLPixelFormatASTC_10x6_HDR         = 232,
    MTLPixelFormatASTC_10x8_HDR         = 233,
    MTLPixelFormatASTC_10x10_HDR        = 234,
    MTLPixelFormatASTC_12x10_HDR        = 235,
    MTLPixelFormatASTC_12x12_HDR        = 236,

    /*!
     @constant MTLPixelFormatGBGR422
     @abstract A pixel format where the red and green channels are subsampled horizontally.  Two pixels are stored in 32 bits, with shared red and blue values, and unique green values.
     @discussion This format is equivalent to YUY2, YUYV, yuvs, or GL_RGB_422_APPLE/GL_UNSIGNED_SHORT_8_8_REV_APPLE.   The component order, from lowest addressed byte to highest, is Y0, Cb, Y1, Cr.  There is no implicit colorspace conversion from YUV to RGB, the shader will receive (Cr, Y, Cb, 1).  422 textures must have a width that is a multiple of 2, and can only be used for 2D non-mipmap textures.  When sampling, ClampToEdge is the only usable wrap mode.
     */
    MTLPixelFormatGBGR422 = 240,

    /*!
     @constant MTLPixelFormatBGRG422
     @abstract A pixel format where the red and green channels are subsampled horizontally.  Two pixels are stored in 32 bits, with shared red and blue values, and unique green values.
     @discussion This format is equivalent to UYVY, 2vuy, or GL_RGB_422_APPLE/GL_UNSIGNED_SHORT_8_8_APPLE. The component order, from lowest addressed byte to highest, is Cb, Y0, Cr, Y1.  There is no implicit colorspace conversion from YUV to RGB, the shader will receive (Cr, Y, Cb, 1).  422 textures must have a width that is a multiple of 2, and can only be used for 2D non-mipmap textures.  When sampling, ClampToEdge is the only usable wrap mode.
     */
    MTLPixelFormatBGRG422 = 241,

    /* Depth */
    MTLPixelFormatDepth16Unorm          = 250,
    MTLPixelFormatDepth32Float  = 252,

    /* Stencil */
    MTLPixelFormatStencil8        = 253,

    /* Depth Stencil */
    MTLPixelFormatDepth24Unorm_Stencil8  = 255,
    MTLPixelFormatDepth32Float_Stencil8  = 260,

    MTLPixelFormatX32_Stencil8  = 261,
    MTLPixelFormatX24_Stencil8  = 262,

} MTLPixelFormat;
#endif /* pixel_utils_h */

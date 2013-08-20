/*
File: Extensions.cpp
Author:	Abramau Mikalaj
Description: Load OpenGL functions
*/

#include "../driver/module.h"
#include "../../../system/module.h"
#include "extensions.h"

namespace Gpu
{
    namespace OpenGL
    {
#ifdef _WIN32
        PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT;
        PFNWGLGETEXTENSIONSSTRINGARBPROC wglGetExtensionsStringARB;
#elif defined __gnu_linux__
        PFNGLXCREATECONTEXTATTRIBSARBPROC glXCreateContextAttribsARB;
//        PFNGLXCHOOSEFBCONFIGPROC glXChooseFBConfig;
//        PFNGLXGETVISUALFROMFBCONFIGPROC glXGetVisualFromFBConfig;
//        PFNGLXGETFBCONFIGATTRIBPROC glXGetFBConfigAttrib;
//        PFNGLXCREATENEWCONTEXTPROC glXCreateNewContext;
//        PFNGLXGETFBCONFIGSPROC glXGetFBConfigs;
#endif

        PFNGLGETBUFFERPARAMETERI64VPROC glGetBufferParameteri64v;
        PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameteriv;
        PFNGLGETBUFFERPARAMETERI64VPROC glGetBufferParameterui64v;
        PFNGLGETBUFFERPOINTERVPROC glGetBufferPointerv;
        PFNGLTEXPARAMETERIPROC glTexParameteri;
        PFNGLPIXELSTOREIPROC glPixelStorei;
        PFNGLPIXELSTOREFPROC glPixelStoref;
        PFNGLBLENDCOLORPROC glBlendColor;
        PFNGLBLENDEQUATIONPROC glBlendEquation;
        PFNGLBLENDEQUATIONIPROC glBlendEquationi;
        PFNGLBLENDEQUATIONSEPARATEPROC glBlendEquationSeparate;
        PFNGLBLENDEQUATIONSEPARATEIPROC glBlendEquationSeparatei;
        PFNGLENABLEIPROC glEnablei;
        PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate;
        PFNGLBLENDFUNCPROC glBlendFunc;
        PFNGLBLENDFUNCIPROC glBlendFunci;
        PFNGLACTIVETEXTUREPROC glActiveTexture;
        PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D;
        PFNGLBUFFERDATAPROC glBufferData;
        PFNGLBUFFERSUBDATAPROC glBufferSubData;
        PFNGLGETBUFFERSUBDATAPROC glGetBufferSubData;
        PFNGLGENBUFFERSPROC glGenBuffers;
        PFNGLBINDBUFFERPROC glBindBuffer;
        PFNGLDELETEBUFFERSPROC glDeleteBuffers;
        PFNGLMAPBUFFERPROC glMapBuffer;
        PFNGLUNMAPBUFFERPROC glUnmapBuffer;
        PFNGLISBUFFERPROC glIsBuffer;
        PFNGLISRENDERBUFFERPROC glIsRenderbuffer;
        PFNGLBINDRENDERBUFFERPROC glBindRenderbuffer;
        PFNGLDELETERENDERBUFFERSPROC glDeleteRenderbuffers;
        PFNGLGENRENDERBUFFERSPROC glGenRenderbuffers;
        PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorage;
        PFNGLGETRENDERBUFFERPARAMETERIVPROC glGetRenderbufferParameteriv;
        PFNGLISFRAMEBUFFERPROC glIsFramebuffer;
        PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer;
        PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers;
        PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers;
        PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus;
        PFNGLFRAMEBUFFERTEXTUREPROC glFramebufferTexture1D;
        PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer;
        PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetFramebufferAttachmentParameteriv;
        PFNGLGENERATEMIPMAPPROC glGenerateMipmap;
        PFNGLCREATESHADERPROC glCreateShader;
        PFNGLCREATEPROGRAMPROC glCreateProgram;
        PFNGLDELETESHADERPROC glDeleteShader;
        PFNGLDELETEPROGRAMPROC glDeleteProgram;
        PFNGLSHADERSOURCEPROC glShaderSource;
        PFNGLCOMPILESHADERPROC glCompileShader;
        PFNGLATTACHSHADERPROC glAttachShader;
        PFNGLDETACHSHADERPROC glDetachShader;
        PFNGLLINKPROGRAMPROC glLinkProgram;
        PFNGLUSEPROGRAMPROC glUseProgram;
        PFNGLVALIDATEPROGRAMPROC glValidateProgram;
        PFNGLUNIFORM1FPROC glUniform1f;
        PFNGLUNIFORM1FVPROC glUniform1fv;
        PFNGLUNIFORM1IPROC glUniform1i;
        PFNGLUNIFORM1IVPROC glUniform1iv;
        PFNGLUNIFORM2FPROC glUniform2f;
        PFNGLUNIFORM2FVPROC glUniform2fv;
        PFNGLUNIFORM2IVPROC glUniform2iv;
        PFNGLUNIFORM3FPROC glUniform3f;
        PFNGLUNIFORM3IVPROC glUniform3iv;
        PFNGLUNIFORM3FVPROC glUniform3fv;
        PFNGLUNIFORM3IPROC glUniform3i;
        PFNGLUNIFORM4FPROC glUniform4f;
        PFNGLUNIFORM4IVPROC glUniform4iv;
        PFNGLUNIFORM4FVPROC glUniform4fv;
        PFNGLUNIFORM4IPROC glUniform4i;
        PFNGLUNIFORMMATRIX2FVPROC glUniformMatrix2fv;
        PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv;
        PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
        PFNGLGETACTIVEUNIFORMPROC glGetActiveUniform;
        PFNGLGETATTACHEDSHADERSPROC glGetAttachedShaders;
        PFNGLGETSHADERSOURCEPROC glGetShaderSource;
        PFNGLGETUNIFORMFVPROC glGetUniformfv;
        PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
        PFNGLVERTEXATTRIB1DPROC glVertexAttrib1d;
        PFNGLVERTEXATTRIB1DVPROC glVertexAttrib1dv;
        PFNGLVERTEXATTRIB1FPROC glVertexAttrib1f;
        PFNGLVERTEXATTRIB1FVPROC glVertexAttrib1fv;
        PFNGLVERTEXATTRIB1SPROC glVertexAttrib1s;
        PFNGLVERTEXATTRIB1SVPROC glVertexAttrib1sv;
        PFNGLVERTEXATTRIB2DPROC glVertexAttrib2d;
        PFNGLVERTEXATTRIB2DVPROC glVertexAttrib2dv;
        PFNGLVERTEXATTRIB2FPROC glVertexAttrib2f;
        PFNGLVERTEXATTRIB2FVPROC glVertexAttrib2fv;
        PFNGLVERTEXATTRIB2SPROC glVertexAttrib2s;
        PFNGLVERTEXATTRIB2SVPROC glVertexAttrib2sv;
        PFNGLVERTEXATTRIB3DPROC glVertexAttrib3d;
        PFNGLVERTEXATTRIB3DVPROC glVertexAttrib3dv;
        PFNGLVERTEXATTRIB3FPROC glVertexAttrib3f;
        PFNGLVERTEXATTRIB3FVPROC glVertexAttrib3fv;
        PFNGLVERTEXATTRIB3SPROC glVertexAttrib3s;
        PFNGLVERTEXATTRIB3SVPROC glVertexAttrib3sv;
        PFNGLVERTEXATTRIB4DPROC glVertexAttrib4d;
        PFNGLVERTEXATTRIB4DVPROC glVertexAttrib4dv;
        PFNGLVERTEXATTRIB4FPROC glVertexAttrib4f;
        PFNGLVERTEXATTRIB4FVPROC glVertexAttrib4fv;
        PFNGLVERTEXATTRIB4SPROC glVertexAttrib4s;
        PFNGLVERTEXATTRIB4SVPROC glVertexAttrib4sv;
        PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
        PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation;
        PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
        PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;
        PFNGLGETVERTEXATTRIBDVPROC glGetVertexAttribdv;
        PFNGLGETVERTEXATTRIBFVPROC glGetVertexAttribfv;
        PFNGLGETVERTEXATTRIBIVPROC glGetVertexAttribiv;
        PFNGLGETVERTEXATTRIBPOINTERVPROC glGetVertexAttribPointerv;
        PFNGLGETACTIVEATTRIBPROC glGetActiveAttrib;
        PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation;
        PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements;
        PFNGLGETSTRINGIPROC glGetStringi;
        PFNGLGETERRORPROC glGetError;
        PFNGLGETINTEGERVPROC glGetIntegerv;
        PFNGLVIEWPORTPROC glViewport;
        PFNGLCLEARCOLORPROC glClearColor;
        PFNGLENABLEPROC glEnable;
        PFNGLDISABLEPROC glDisable;
        PFNGLREADPIXELSPROC glReadPixels;
        PFNGLGETSTRINGPROC glGetString;
        PFNGLGENTEXTURESPROC glGenTextures;
        PFNGLBINDTEXTUREPROC glBindTexture;
        PFNGLTEXPARAMETERFPROC glTexParameterf;
        PFNGLTEXPARAMETERFVPROC glTexParameterfv;
        PFNGLTEXIMAGE2DPROC glTexImage2D;
        PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D;
        PFNGLDELETETEXTURESPROC glDeleteTextures;
        PFNGLDRAWBUFFERPROC glDrawBuffer;
        PFNGLREADBUFFERPROC glReadBuffer;
        PFNGLGETSHADERIVPROC glGetShaderiv;
        PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
        PFNGLGETPROGRAMIVPROC glGetProgramiv;
        PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
        PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;
        PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
        PFNGLDRAWARRAYSPROC glDrawArrays;
        PFNGLDRAWARRAYSINDIRECTPROC glDrawArraysIndirect;
        PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced;
        PFNGLDRAWELEMENTSPROC glDrawElements;
        PFNGLDRAWELEMENTSINDIRECTPROC glDrawElementsIndirect;
        PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced;
        PFNGLCLEARPROC glClear;
        PFNGLTEXSUBIMAGE2DPROC glTexSubImage2D;
        PFNGLPOLYGONMODEPROC glPolygonMode;
        PFNGLFENCESYNCPROC glFenceSync;
        PFNGLWAITSYNCPROC glWaitSync;
        PFNGLDELETESYNCPROC glDeleteSync;
        PFNGLDRAWBUFFERSPROC glDrawBuffers;
        PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glRenderbufferStorageMultisample;
        PFNGLBLITFRAMEBUFFERPROC glBlitFramebuffer;
        PFNGLDEPTHFUNCPROC glDepthFunc;
        PFNGLDEPTHMASKPROC glDepthMask;
        PFNGLPOINTSIZEPROC glPointSize;
        PFNGLPOINTPARAMETERIVPROC glPointParameteriv;
        PFNGLPOINTPARAMETERIPROC glPointParameteri;
        PFNGLPOINTPARAMETERFVPROC glPointParameterfv;
        PFNGLPOINTPARAMETERFPROC glPointParameterf;
        PFNGLCULLFACEPROC glCullFace;
        PFNGLLINEWIDTHPROC glLineWidth;
        PFNGLCLEARDEPTHFPROC glClearDepthf;
        PFNGLCLEARDEPTHPROC glClearDepth;
        PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC glRenderbufferStorageMultisampleCoverageNV;
        PFNGLFRAMEBUFFERTEXTURELAYERPROC glFramebufferTextureLayer;
        PFNGLPOLYGONOFFSETPROC glPolygonOffset;
    }
}

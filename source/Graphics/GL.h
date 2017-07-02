// © 2017 Joseph Cameron - &all Rights Reserved
// Project: GDK
// Created on 17-07-02.
#ifndef GDK_GFX_GL_H
#define GDK_GFX_GL_H

//std inc
#include <string>

namespace GDK
{
	namespace GFX
	{
		/*!
		 GL call wrapper for GFX
    	 */
		namespace GL
		{
            /*static void glActiveTexture(const int &aTextureUnit);
            static void glBindTexture(const int &aTextureType, const int &aTextureHandle);
            
            static int  glGetUniformLocation(const int &aShaderHandle, const std::string &aUniformName);
            static void glUniform1i(const int &aUniformHandle, const int &aValue);
            static void glUniform1f(const int &aUniformHandle, const float &aValue);
            static void glUniform2f(const int &aUniformHandle, const float &aX, const float &aY);
            static void glUniform3f(const int &aUniformHandle, const float &aX, const float &aY, const float &aZ);
            static void glUniform4f(const int &aUniformHandle, const float &aX, const float &aY, const float &aZ, const float &aW);
            //static void glUniformMatrix4fv(const int &aUniformHandle, const int &aCount, const Boolean &aTranspose, FloatBuffer &aData  );
            
            static void glViewport(const int &aX, const int &aY, const int &aWidth, const int &aHeight);
            
            static void glScissor(const int &aX, const int &aY, const int &aWidth, const int &aHeight);
            
            static void glClearColor(const float &aRed, const float &aGreen, const float &aBlue, const float &aAlpha);
            //static void glClear(const int &aClearMask);
            
            static void glEnable(const int &aCapability);
            static void glDisable(const int &aCapability);
            
            static void glUseProgram(const int &aProgramHandle);
            
            static int  glCreateShader(const int &aShaderType);
            static int  glCreateProgram();
            static void glLinkProgram(const int &aProgramHandle);
            //static void glGetProgramiv(const int &aProgramHandle, const int &aPName,int[] params, const int &aOffset);
            //static void glGetProgramInfoLog(const int &aProgramHandle, const int &aMaxLength, const int[] &aLogLength, const int &aInt, const byte[] &aInfoBuffer, const int &aInt2 );
            static void glDeleteProgram(const int &aProgramHandle);
            
            //static void glShaderSource(const int &aShaderHandle, const int &aCount, const std::string[] &astd::strings, const IntBuffer &aLengths);
            static void glCompileShader(const int &aShaderHandle);
            static void glAttachShader(const int &aProgramHandle, const int &aShaderHandle);
            
            static void glDrawArrays(const int &aPrimitiveType, const int &aFirst, const int &aCount);
            
            static int  glGetAttribLocation(const int &aProgramHandle, const std::string &aAttributeName);
            static void glEnableVertexAttribArray(const int &aAttributeIndex);
            //static void glVertexAttribPointer(const int &aAttributeIndex, const int &aAttributeSize, const int &aType, const Boolean &aNormalized, const int &aStride, const int &aOffset );
            
            static void glBindBuffer(const int &aTarget, const int &aBufferHandle);
            //static void glGenBuffers(const int &aNumber, const IntBuffer &aBufferHandle);
            //static void glBufferData(const int &aTarget, const int &aSize, const FloatBuffer &aVertexData, const int &aUsageHint);
            //static void glDeleteBuffers(const int &aNumberOfBuffers, const IntBuffer &aBufferHandles);
            
            //static void glGenTextures(const int &aNumberOfTextures, const IntBuffer &aTextureHandles);
            //static void glTexImage2D(const int &aTarget, const int &aLevelOfDetail, const int &aInternalFormat, const int &aWidth, const int &aHeight, const int &aBorder, const int &aFormat, const int &aType, const IntBuffer &aData);
            static void glTexParameteri(const int &aTarget, const int &aPName, const int &aParam);
            //static void glDeleteTextures(const int &aNumberOfTextures, const IntBuffer &aTextureHandles);
            
            static void glLineWidth(const float &aWidth);*/
            
		}
        
	}

}

#endif /* GDK_GFX_GL_H  */

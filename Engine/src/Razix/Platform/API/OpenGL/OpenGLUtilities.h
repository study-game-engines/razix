#pragma once

#ifdef RAZIX_RENDER_API_OPENGL

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include "Razix/Core/Log.h"

#include "Razix/Graphics/API/Texture.h"

namespace Razix {
    namespace Graphics {
        namespace Utilities::OpenGL {

            /* Check the OpenGL functions for any errors and reports them */
#define GLCall(x)   ::Razix::Graphics::Utilities::OpenGL::GLClearError();\
                        (x);\
                        RAZIX_CORE_ASSERT(::Razix::Graphics::Utilities::OpenGL::GLLogCall(#x, __FILE__, __LINE__), "[OpenGL Assertion Error]")

            /* Checks for any OpenGL errors */
            static void GLClearError()
            {
                while (glGetError() != GL_NO_ERROR);
            }

            /** Logs any error reported by OpenGL Functions
             *
             * @param functionsName The name of the functions that caused the error
             * @param file The file in which the function is
             * @param line The line of the function
             */
            static bool GLLogCall(const char* functionName, const char* file, int line)
            {
                while (GLenum error = glGetError()) {
                    RAZIX_CORE_ERROR("[OpenGL] - ERROR - {0}, (Function : {1} at Line : {2}, in File : {3})", error, functionName, line, file);
                    return false;
                }
                return true;
            }

            //TODO: USe macros to generate this code automatically
            uint32_t TextureFormatToGL(const RZTexture::Format format, bool srgb)
            {
                switch (format) {
                    case RZTexture::Format::R8:
                        return GL_R8;
                        break;
                    case RZTexture::Format::R16:
                        return GL_R16;
                        break;
                    case RZTexture::Format::R32:
                        return GL_R32I;
                        break;
                    case RZTexture::Format::RG8:
                        return GL_RG8;
                        break;
                    case RZTexture::Format::RG16:
                        return GL_RG16;
                        break;
                    case RZTexture::Format::RG32:
                        return GL_RG32I;
                        break;
                    case RZTexture::Format::RGB8:
                        return GL_RGB8;
                        break;
                    case RZTexture::Format::RGB16:
                        return GL_RGB16;
                        break;
                    case RZTexture::Format::RGB32:
                        return GL_RGB;
                        break;
                    case RZTexture::Format::RGBA8:
                        return GL_RGBA8;
                        break;
                    case RZTexture::Format::RGBA16:
                        return GL_RGBA16;
                        break;
                    case RZTexture::Format::RGBA32:
                        return GL_RGBA;
                        break;
                    case RZTexture::Format::R16F:
                        return GL_R16F;
                        break;
                    case RZTexture::Format::R32F:
                        return GL_R32F;
                        break;
                    case RZTexture::Format::RG16F:
                        return GL_RG16F;
                        break;
                    case RZTexture::Format::RG32F:
                        return GL_RG32F;
                        break;
                    case RZTexture::Format::RGB16F:
                        return GL_RGB16F;
                        break;
                    case RZTexture::Format::RGB32F:
                        return GL_RGB32F;
                        break;
                    case RZTexture::Format::RGBA16F:
                        return GL_RGBA16F;
                        break;
                    case RZTexture::Format::RGBA32F:
                        return GL_RGBA32F;
                        break;

                    default:
                        RAZIX_CORE_WARN("Unsupported Texture format");
                        return 0;
                        break;
                }
            }

            uint32_t TextureWrapToGL(const RZTexture::Wrapping wrap)
            {
                switch (wrap) {
                    case RZTexture::Wrapping::NONE:
                        RAZIX_CORE_WARN("Unsupported Texture Wrappign mode");
                    case RZTexture::Wrapping::REPEAT:
                        return GL_REPEAT;
                        break;
                    case RZTexture::Wrapping::MIRRORED_REPEAT:
                        return GL_MIRRORED_REPEAT;
                        break;
                    case RZTexture::Wrapping::CLAMP_TO_EDGE:
                        return GL_CLAMP_TO_EDGE;
                        break;
                    case RZTexture::Wrapping::CLAMP_TO_BORDER:
                        return GL_CLAMP_TO_BORDER;
                        break;

                    default:
                        RAZIX_CORE_WARN("Unsupported Texture Wrappign mode");
                        return 0;
                        break;
                }
            }

            uint32_t TextureFormatToInternalFormat(uint32_t format)
            {
                switch (format) {
                    case GL_SRGB8:
                        return GL_RGB;
                    case GL_SRGB8_ALPHA8:
                        return GL_RGBA;
                    case GL_RGBA:
                        return GL_RGBA;
                    case GL_RGB:
                        return GL_RGB;
                    case GL_R8:
                        return GL_RED;
                    case GL_RG8:
                        return GL_RG;
                    case GL_RGB8:
                        return GL_RGB;
                    case GL_RGBA8:
                        return GL_RGBA;
                    case GL_RGB16:
                        return GL_RGB;
                    case GL_RGBA16:
                        return GL_RGBA;
                    case GL_RGBA16F:
                        return GL_RGBA;
                    case GL_RGB32F:
                        return GL_RGB;
                    case GL_RGBA32F:
                        return GL_RGBA;
                    case GL_SRGB:
                        return GL_RGB;
                    case GL_SRGB_ALPHA:
                        return GL_RGBA;

                    default:
                        RAZIX_CORE_WARN("[OpenGL] Unsupported Texture Format");
                        return 0;
                }
            }
        }
    }
}
#endif
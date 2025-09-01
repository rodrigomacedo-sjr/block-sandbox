#include "../headers/LTexture.h"

LTexture::LTexture() {
  // Initialize texture ID
  mTextureID = 0;

  // Initialize texture dimensions
  mTextureWidth = 0;
  mTextureHeight = 0;
}

LTexture::~LTexture() {
  // Free texture data if needed
  freeTexture();
}

bool LTexture::loadTextureFromPixels32(GLuint *pixels, GLuint width,
                                       GLuint height) {
  // Free texture if it exists
  freeTexture();

  // Get texture dimensions
  mTextureWidth = width;
  mTextureHeight = height;
}

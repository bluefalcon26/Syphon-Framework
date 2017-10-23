/*
 SyphonServerRenderer.h
 Syphon

 Copyright 2016 bangnoise (Tom Butterworth) & vade (Anton Marini).
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.

 * Redistributions in binary form must reproduce the above copyright
 notice, this list of conditions and the following disclaimer in the
 documentation and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 */

#import <Foundation/Foundation.h>

@class SyphonImage;

@interface SyphonServerRenderer : NSObject {
@private
    CGLContextObj _context;
    GLuint  _MSAASampleCount;
    GLenum  _depthBufferFormat;
    GLenum  _stencilBufferFormat;
    GLsizei _width;
    GLsizei _height;
}
- (instancetype)initWithContext:(CGLContextObj)context MSAASampleCount:(GLuint)msc depthBufferResolution:(GLuint)dbr stencilBufferResolution:(GLuint)sbr;
@property (readonly) CGLContextObj context;
@property (readonly) GLuint MSAASampleCount;
@property (readonly) GLenum depthBufferFormat;
@property (readonly) GLenum stencilBufferFormat;
@property (readonly) GLsizei width;
@property (readonly) GLsizei height;
- (void)beginInContext; // Called once before any number of the following are called
- (void)endInContext; // Called once after any number of the following have been called
- (BOOL)capabilitiesDidChange; // Called when the context's capabilities have changed, returns YES if the renderer changes its configuration
- (void)destroySizedResources;
- (SyphonImage *)newImageForSurface:(IOSurfaceRef)surface;
- (void)setupForBackingTexture:(GLuint)backing width:(GLsizei)width height:(GLsizei)height;
- (void)bind;
- (void)unbind;
- (void)flush;
- (void)drawFrameTexture:(GLuint)texID textureTarget:(GLenum)target imageRegion:(NSRect)region textureDimensions:(NSSize)size flipped:(BOOL)isFlipped;
@end

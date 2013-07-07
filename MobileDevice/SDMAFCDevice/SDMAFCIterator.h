/*
 *  SDMAFCIterator.h
 *  SDM_MD_Demo
 *
 *  Copyright (c) 2013, Sam Marshall
 *  All rights reserved.
 * 
 *  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *  1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 *  3. All advertising materials mentioning features or use of this software must display the following acknowledgement:
 *  	This product includes software developed by the Sam Marshall.
 *  4. Neither the name of the Sam Marshall nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
 * 
 *  THIS SOFTWARE IS PROVIDED BY Sam Marshall ''AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL Sam Marshall BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef _SDMAFCITERATOR_H_
#define _SDMAFCITERATOR_H_

#import <CoreFoundation/CoreFoundation.h>

#pragma mark -
#pragma mark TYPES
#pragma mark -

typedef struct AFCIteratorClassHeader {
	unsigned char header[16];		// CF Object header
} __attribute__ ((packed)) AFCIteratorClassHeader; // 0x10

typedef struct AFCIteratorClassBody {
	// 16
	CFArrayRef keys_values;			// 24
	int32_t count0;					// 32
	CFMutableDataRef key_buffer; 	// 40
	CFMutableDataRef value_buffer;	// 48
} __attribute__ ((packed)) AFCIteratorClassBody; // 0x28

typedef struct afc_iterator {
	struct AFCIteratorClassHeader head;
	struct AFCIteratorClassBody body;
} __attribute__ ((packed)) afc_iterator;

typedef struct afc_iterator SDM_AFCIteratorClass;

#define SDM_AFCIteratorRef SDM_AFCIteratorClass*

#pragma mark -
#pragma mark FUNCTIONS
#pragma mark -

#endif